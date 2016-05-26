/****************************************************************************
**  This is a part of MRiCP                                                **
**  Copyright (C) 2016  Simon Garnotel                                     **
**                                                                         **
**  This program is free software: you can redistribute it and/or modify   **
**  it under the terms of the GNU General Public License as published by   **
**  the Free Software Foundation, either version 3 of the License, or      **
**  (at your option) any later version.                                    **
**                                                                         **
**  This program is distributed in the hope that it will be useful,        **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**  GNU General Public License for more details.                           **
**                                                                         **
**  You should have received a copy of the GNU General Public License      **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.  **
**                                                                         **
** **************************************************************************
**                                                                         **
** Author: Simon Garnotel                                                  **
** Contact: simon.garnotel@gmail.com                                       **
** Date: 05/2016                                                           **
** Version: 1.0                                                            **
****************************************************************************/

#include "headers.h"

bool AppendPathology(QString Pathology){
    bool Res;

    QFile File("system/pathologies.dat");
    if (File.open(QIODevice::Append)){
        File.write(Pathology.toStdString().c_str());
        File.write("\n");
        File.close();
        Res = true;
    }
    else{
        Res = false;
    }

    return Res;
}

QStringList GetPathologies(bool *Res){
    QStringList PathologiesList;

    QFile File("system/pathologies.dat");
    if (File.open(QIODevice::ReadOnly)){
        while(!File.atEnd()){
            QString Line = File.readLine();
            Line.remove("\n");
            PathologiesList.append(Line);
        }
        File.close();
        (*Res) = true;
    }
    else{
        (*Res) = false;
    }

    return PathologiesList;
}

bool load_FLOW_informations(const QString file_name, QStringList *informations){
    if (file_name.isEmpty()){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QString::isEmpty() - ERR1" << std::endl;
        return false;
    }

    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        while(!file.atEnd()){
            informations->append(file.readLine());
        }
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QFile::open() - ERR2" << std::endl;
        return false;
    }
    return true;
}

bool load_FLOW_file(const QString file_name, QVector<double> *xy){
    if (file_name.isEmpty()){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QString::isEmpty() - ERR1" << std::endl;
        return false;
    }

    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        QString line = file.readLine();
        while (!line.contains("DEBIT_mm3/sec")){
            line = file.readLine();
        }
        line = file.readLine();
        while(!line.contains("SURFACE_mm2")){
            QStringList words = line.split(" ");
            QString word = words.takeLast();
            bool res;
            double value = word.toDouble(&res);
            if (!res){
                std::cerr << Q_FUNC_INFO << std::endl;
                std::cerr << "QString::toDouble() - ERR3" << std::endl;
                return false;
            }
            xy->append(value);
            line = file.readLine();
        }
        while(!line.contains("Axe des Temps")){
            line = file.readLine();
        }
        while (!file.atEnd()){
            line = file.readLine();
            QStringList words = line.split(" ");
            QString word = words.takeLast();
            bool res;
            double value = word.toDouble(&res);
            if (!res){
                std::cerr << Q_FUNC_INFO << std::endl;
                std::cerr << "QString::toDouble() - ERR4" << std::endl;
                return false;
            }
            value = value * 1.e-3;
            xy->append(value);
        }
        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QFile::open() - ERR2" << std::endl;
        return false;
    }
}

QVector<double> **load_FLOW_files(QWidget *parent, QStringList *names, QVector<int> *sizes, QString *patient_name, QStringList *informations, QStringList *images, bool *res){
    QVector<double> **flows = NULL;

    QString global_dir_name = QFileDialog::getExistingDirectory(parent, "Choose a FLOW patient folder", GetFlowDir(res));
    if (patient_name != NULL){
        patient_name->clear();
        patient_name->append(global_dir_name);

        int pos = patient_name->indexOf("/");
        while (pos != -1){
            (*patient_name) = patient_name->remove(0, pos+1);
            pos = patient_name->indexOf("/");
        }
    }
    if (!global_dir_name.isEmpty()){
        QDir global_dir = QDir(global_dir_name);
        if (!global_dir.exists()){
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "QDir::exists() - ERR2" << std::endl;
            if (res != NULL) (*res) = false;
            return flows;
        }

        QStringList global_dir_list = global_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        QString exam_dir_name;
        unsigned int n_exam = global_dir_list.count();
        if (n_exam != 0){
                exam_dir_name = QInputDialog::getItem(parent, "Exam", "Choose an exam", global_dir_list, 0, false, res);
                if (!res){
                    std::cerr << Q_FUNC_INFO << std::endl;
                    std::cerr << "QInputDialog::getItem() - ERR4" << std::endl;
                    return flows;
                }
                else{
                    informations->append("Exam number: " + exam_dir_name);
                    exam_dir_name = global_dir_name + "/" + exam_dir_name;
                }
        }
        else{
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "unsigned int != 0 - ERR3" << std::endl;
            if (res != NULL) (*res) = false;
            return flows;
        }

        QDir exam_dir = QDir(exam_dir_name);
        if (!exam_dir.exists()){
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "QDir::exists() - ERR5" << std::endl;
            if (res != NULL) (*res) = false;
            return flows;
        }

        QStringList exam_dir_list = exam_dir.entryList(QDir::Files);
        unsigned int n_files = exam_dir_list.count();
        if (n_files != 0){
            flows = new QVector<double>*[n_files];
            for (unsigned int i = 0; i < n_files; i++){
                flows[i] = new QVector<double>;

                QString file_name = exam_dir_list.at(i);
                names->append(file_name);

                if (file_name.contains(".txt")){
                    if (file_name.contains("general-informations")){
                        (*res) = load_FLOW_informations(exam_dir_name + "/" + file_name, informations);
                        if (!res){
                            std::cerr << Q_FUNC_INFO << std::endl;
                            std::cerr << "bool true - ERR7" << std::endl;
                            return flows;
                        }
                        sizes->append(0);
                        images->append("");
                    }
                    else{
                        (*res) = load_FLOW_file(exam_dir_name + "/" + file_name, flows[i]);
                        if (!res){
                            std::cerr << Q_FUNC_INFO << std::endl;
                            std::cerr << "bool true - ERR8" << std::endl;
                            return flows;
                        }
                        sizes->append(flows[i]->count()/2);

                        {
                            QString image_name = file_name;
                            image_name = image_name.remove(".txt");
                            image_name.append(".jpg");

                            image_name = image_name.replace("aqueduc", "Aqueduc");
                            image_name = image_name.replace("c2_c3", "C2_C3");
                            image_name = image_name.replace("cid", "CID");
                            image_name = image_name.replace("cig", "CIG");
                            image_name = image_name.replace("jugul", "Jugul");
                            image_name = image_name.replace("-d", "-D");
                            image_name = image_name.replace("-g", "-G");
                            image_name = image_name.replace("sinus", "Sinus");
                            image_name = image_name.replace("-s", "-S");
                            image_name = image_name.replace("tb", "Tb");
                            image_name = image_name.replace("verteb", "Verteb");

                            images->append(exam_dir_name + "/images/" + image_name);
                        }
                    }
                }
                else{
                    sizes->append(0);
                    images->append("");
                    continue;
                }
            }

            if (res != NULL) (*res) = true;
            return flows;
        }
        else{
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "unsigned int != 0 - ERR6" << std::endl;
            if (res != NULL) (*res) = false;
            return flows;
        }
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QString::isEmpty() - ERR1" << std::endl;
        if (res != NULL) (*res) = false;
        return flows;
    }
}

bool load_ICMP_csv(QWidget *parent, QVector<double> *x, QVector<double> *y, QString *patient_name){
    x->clear();
    y->clear();

    bool res;
    QString file_name = QFileDialog::getOpenFileName(parent, "Choose an ICM+ CSV pressure file", GetProliphycDir(&res), "CSV (*.csv)");
    if (patient_name != NULL){
        patient_name->clear();
        patient_name->append(file_name);

        int pos = patient_name->indexOf("/");
        while (pos != -1){
            (*patient_name) = patient_name->remove(0, pos+1);
            pos = patient_name->indexOf("/");
        }

        (*patient_name) = patient_name->remove(".csv");
    }
    if (!file_name.isEmpty()){
        QFile file(file_name);
        if (file.open(QIODevice::ReadOnly)){
            QString line = file.readLine();
            QStringList words = line.split(";");

            int DateTime_position = 0;
            int icp_position = 0;
            for ( int i = 0; i < words.count(); i++){
                QString word = words.at(i);
                word.remove("\n"); word.remove("\r"); word.remove(" ");
                if (word.compare("DateTime") == 0){
                    DateTime_position = i;
                }
                if (word.compare("icp[]") == 0){
                    icp_position = i;
                }
            }

            unsigned int k = 0;
            double xmin = 0.;
            while (!file.atEnd()){
                line = file.readLine();
                words = line.split(";");

                QString DateTime_str = words.at(DateTime_position);
                QString icp_str = words.at(icp_position);

                DateTime_str.replace(",", ".");
                icp_str.replace(",", ".");

                bool res;
                double DateTime = DateTime_str.toDouble(&res);
                if (!res){
                    std::cerr << Q_FUNC_INFO << std::endl;
                    std::cerr << "QString::toDouble() ERR1" << std::endl;
                    return res;
                }
                double icp = icp_str.toDouble(&res);
                if (!res){
                    std::cerr << Q_FUNC_INFO << std::endl;
                    std::cerr << "QString::toDouble() ERR2" << std::endl;
                    return res;
                }

                if (k == 0){
                    xmin = DateTime;
                    k++;
                }

                x->append((DateTime - xmin)*1.e5);
                y->append(icp);
            }
            return true;
        }
        else{
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "QFile::open()  ERR3" << std::endl;
            return false;
        }
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "QFileDialog::getOpenFileName ERR4" << std::endl;
        return false;
    }
}





bool SaveDat(const QString FileName){
    QFile File(FileName);
    if (File.open(QIODevice::WriteOnly)){
        File.close();
        return true;
    }
    else{
        return false;
    }
}


bool SaveDat(const QString FileName, const QVector<QString> *v){
    unsigned int Nv = v->count();

    /*if (Nv != 0){*/
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            for (unsigned int i = 0; i < Nv; i++){
                File.write(v->at(i).toStdString().c_str());
                if (i != Nv-1) File.write("\n");
            }
            File.close();
            return true;
        }
        else{
            return false;
        }
    /*}
    else{
        return true;
    }*/
}

bool LoadDat(const QString FileName, QVector<QString> *v, const int full=0){
    QFile File(FileName);
    if (File.open(QIODevice::ReadOnly)){
        if (full == 0){
            while (!File.atEnd()){
                QString Line = File.readLine();
                Line.remove("\n");
                v->append(Line);
            }
        }
        else{
            QString Text = File.readAll();
            v->append(Text);
        }
        File.close();
        return true;
    }
    else{
        return false;
    }
}

bool SaveDat(const QString FileName, const QVector<double> *x, const QVector<double> *y=NULL){
    unsigned int Nx = x->count();
    unsigned int Ny;
    if (y != NULL){
        Ny = y->count();
    }
    else{
        Ny = Nx;
    }

    if ((Nx == Ny) && (Nx != 0)){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            for (unsigned int i = 0; i < Nx; i++){
                File.write(QString::number(x->at(i)).toStdString().c_str());
                if (y != NULL){
                    File.write("\t");
                    File.write(QString::number(y->at(i)).toStdString().c_str());
                }
                if (i != Nx-1) File.write("\n");
            }
            File.close();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool SaveDat(const QString FileName, const QVector<int> *v){
    unsigned int Nv = v->count();

    if (Nv != 0){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            for (unsigned int i = 0; i < Nv; i++){
                File.write(QString::number(v->at(i)).toStdString().c_str());
                if (i != Nv-1) File.write("\n");
            }
            File.close();
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool LoadDat(const QString FileName, QVector<double> *x, QVector<double> *y=NULL){
    QFile File(FileName);
    if (File.open(QIODevice::ReadOnly)){
        while (!File.atEnd()){
            bool Res;
            QString Line = File.readLine();

            if (Line.at(0) == '#') continue;

            Line.remove("\n");

            if (y != NULL){
                QStringList Words = Line.split("\t");
                x->append(Words.at(0).toDouble(&Res));
                if (!Res) return Res;
                y->append(Words.at(1).toDouble(&Res));
                if (!Res) return Res;
            }
            else{
                x->append(Line.toDouble(&Res));
                if (!Res) return Res;
            }
        }
        File.close();
        return true;
    }
    else{
        return false;
    }
}

bool LoadDat(const QString FileName, QVector<int> *x){
    QFile File(FileName);
    if (File.open(QIODevice::ReadOnly)){
        while (!File.atEnd()){
            bool Res;
            QString Line = File.readLine();
            Line.remove("\n");
            x->append(Line.toInt(&Res));
            if (!Res) return Res;
        }
        File.close();
        return true;
    }
    else{
        return false;
    }
}

bool SavePatient(const QString DirName,
                 const QVector<QString> Globalinformations,
                 const QVector<QString> MRIInformations,
                 const QVector<QString> ICPInformations,
                 const QVector<QString> EPIInformations
                 ){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return Res;
    }

    //GLOBALINFORMATIONS
    QString GlobalinformationsFileName = DirName + "/" + "PATIENT__global_informations.dat";
    Res = SaveDat(GlobalinformationsFileName, &Globalinformations);
    if (!Res) return Res;

    //MRIINFORMATIONS
    QString MRIInformationsFileName = DirName + "/" + "PATIENT__mri_informations.dat";
    Res = SaveDat(MRIInformationsFileName, &MRIInformations);
    if (!Res) return Res;

    //ICPINFORMATIONS
    QString ICPInformationsFileName = DirName + "/" + "PATIENT__icp_informations.dat";
    Res = SaveDat(ICPInformationsFileName, &ICPInformations);
    if (!Res) return Res;

    //EPIINFORMATIONS
    QString EPIInformationsFileName = DirName + "/" + "PATIENT__epi_informations.dat";
    Res = SaveDat(EPIInformationsFileName, &EPIInformations);
    if (!Res) return Res;

    return Res;
}

bool LoadPatient(const QString DirName,
                 QVector<QString> *Globalinformations,
                 QVector<QString> *MRIInformations,
                 QVector<QString> *ICPInformations,
                 QVector<QString> *EPIInformations
                 ){
    bool Res;

    Globalinformations->clear();
    MRIInformations->clear();
    ICPInformations->clear();
    EPIInformations->clear();

    //GLOBALINFORMATIONS
    QString GlobalinformationsFileName = DirName + "/" + "PATIENT__global_informations.dat";
    Res = LoadDat(GlobalinformationsFileName, Globalinformations);
    if (!Res) return Res;

    //MRIINFORMATIONS
    QString MRIInformationsFileName = DirName + "/" + "PATIENT__mri_informations.dat";
    Res = LoadDat(MRIInformationsFileName, MRIInformations, 1);
    if (!Res) return Res;

    //ICPINFORMATIONS
    QString ICPInformationsFileName = DirName + "/" + "PATIENT__icp_informations.dat";
    Res = LoadDat(ICPInformationsFileName, ICPInformations, 1);
    if (!Res) return Res;

    //EPIINFORMATIONS
    QString EPIInformationsFileName = DirName + "/" + "PATIENT__epi_informations.dat";
    Res = LoadDat(EPIInformationsFileName, EPIInformations, 1);
    if (!Res) return Res;

    return true;
}

bool SaveMRI(const QString DirName,
             const QVector<double> SystoleThreshold, const QVector<int> Quality, const QVector<int> Move,
             const QVector<double> *Arterial_x, const QVector<double> *Arterial_y, const QVector<double> ArterialResults,
             const QVector<double> *Venous_x,const  QVector<double> *Venous_y, const QVector<double> VenousResults,
             const QVector<double> *CSF_x, const QVector<double> *CSF_y, const QVector<double> CSFResults,
             const QVector<double> *AVFlow_x, const QVector<double> *AVFlow_y, const QVector<double> AVFlowResults,
             const QVector<double> *AVVolume_x, const QVector<double> *AVVolume_y, const QVector<double> AVVolumeResults,
             const QVector<double> *AVCSFFlow_x, const QVector<double> *AVCSFFlow_y, const QVector<double> AVCSFFlowResults,
             const QVector<double> *AVCSFVolume_x, const QVector<double> *AVCSFVolume_y, const QVector<double> AVCSFVolumeResults
             ){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return Res;
    }

    //SYSTOLE THRESHOLD
    if (SystoleThreshold.count() == 1){
        QString SystoleThresholdFileName = DirName + "/" + "MRI__systole_threshold.dat";
        Res = SaveDat(SystoleThresholdFileName, &SystoleThreshold);
        if (!Res) return Res;
    }

    //QUALITY
    if (Quality.count() == 3){
        {
            QString QualityFileName = DirName + "/" + "MRI__quality_arterial.dat";
            QVector<double> QualityArterial;
            QualityArterial.append(Quality.at(0));
            Res = SaveDat(QualityFileName, &QualityArterial);
            if (!Res) return Res;
        }
        {
            QString QualityFileName = DirName + "/" + "MRI__quality_venous.dat";
            QVector<double> QualityVenous;
            QualityVenous.append(Quality.at(1));
            Res = SaveDat(QualityFileName, &QualityVenous);
            if (!Res) return Res;
        }
        {
            QString QualityFileName = DirName + "/" + "MRI__quality_csf.dat";
            QVector<double> QualityCSF;
            QualityCSF.append(Quality.at(2));
            Res = SaveDat(QualityFileName, &QualityCSF);
            if (!Res) return Res;
        }
    }

    //Move
    if (Move.count() == 3){
        {
            QString MoveFileName = DirName + "/" + "MRI__move_arterial.dat";
            QVector<double> MoveArterial;
            MoveArterial.append(Move.at(0));
            Res = SaveDat(MoveFileName, &MoveArterial);
            if (!Res) return Res;
        }
        {
            QString MoveFileName = DirName + "/" + "MRI__move_venous.dat";
            QVector<double> MoveVenous;
            MoveVenous.append(Move.at(0));
            Res = SaveDat(MoveFileName, &MoveVenous);
            if (!Res) return Res;
        }
        {
            QString MoveFileName = DirName + "/" + "MRI__move_csf.dat";
            QVector<double> MoveCSF;
            MoveCSF.append(Move.at(0));
            Res = SaveDat(MoveFileName, &MoveCSF);
            if (!Res) return Res;
        }
    }

    //ARTERIAL
    QString ArterialFileName = DirName + "/" + "MRI__arterial.dat";
    Res = SaveDat(ArterialFileName, Arterial_x, Arterial_y);
    if (!Res) return Res;

    //ARTERIAL RESULTS
    QString ArterialResultsFileName = DirName + "/" + "MRI__results_arterial.dat";
    Res = SaveDat(ArterialResultsFileName, &ArterialResults);
    if (!Res) return Res;

    //VENOUS
    QString VenousFileName = DirName + "/" + "MRI__venous.dat";
    Res = SaveDat(VenousFileName, Venous_x, Venous_y);
    if (!Res) return Res;

    //VENOUS RESULTS
    QString VenousResultsFileName = DirName + "/" + "MRI__results_venous.dat";
    Res = SaveDat(VenousResultsFileName, &VenousResults);
    if (!Res) return Res;

    //CSF
    QString CSFFileName = DirName + "/" + "MRI__csf.dat";
    Res = SaveDat(CSFFileName, CSF_x, CSF_y);
    if (!Res) return Res;

    //CSF RESULTS
    QString CSFResultsFileName = DirName + "/" + "MRI__results_csf.dat";
    Res = SaveDat(CSFResultsFileName, &CSFResults);
    if (!Res) return Res;

    //AV FLOW
    QString AVFlowFileName = DirName + "/" + "MRI__av_flow.dat";
    Res = SaveDat(AVFlowFileName, AVFlow_x, AVFlow_y);
    if (!Res) return Res;

    //AV FLOW RESULTS
    QString AVFlowResultsFileName = DirName + "/" + "MRI__results_av_flow.dat";
    Res = SaveDat(AVFlowResultsFileName, &AVFlowResults);
    if (!Res) return Res;

    //AV VOLUME
    QString AVVolumeFileName = DirName + "/" + "MRI__av_volume.dat";
    Res = SaveDat(AVVolumeFileName, AVVolume_x, AVVolume_y);
    if (!Res) return Res;

    //AV VOLUME RESULTS
    QString AVVolumeResultsFileName = DirName + "/" + "MRI__results_av_volume.dat";
    Res = SaveDat(AVVolumeResultsFileName, &AVVolumeResults);
    if (!Res) return Res;

    //AVCSF FLOW
    QString AVCSFFlowFileName = DirName + "/" + "MRI__avcsf_flow.dat";
    Res = SaveDat(AVCSFFlowFileName, AVCSFFlow_x, AVCSFFlow_y);
    if (!Res) return Res;

    //AVCSF FLOW RESULTS
    QString AVCSFFlowResultsFileName = DirName + "/" + "MRI__results_avcsf_flow.dat";
    Res = SaveDat(AVCSFFlowResultsFileName, &AVCSFFlowResults);
    if (!Res) return Res;

    //AVCSF VOLUME
    QString AVCSFVolumeFileName = DirName + "/" + "MRI__avcsf_volume.dat";
    Res = SaveDat(AVCSFVolumeFileName, AVCSFVolume_x, AVCSFVolume_y);
    if (!Res) return Res;

    //AVCSF VOLUME RESULTS
    QString AVCSFVolumeResultsFileName = DirName + "/" + "MRI__results_avcsf_volume.dat";
    Res = SaveDat(AVCSFVolumeResultsFileName, &AVCSFVolumeResults);
    if (!Res) return Res;

    return Res;
}

bool SaveMRI2(const QString DirName,
              const QVector<QString> *ArteriesImages,
              QVector<double> **Arteries_x, QVector<double> **Arteries_y, const QVector<QString> ArteriesNames,
              const QVector<QString> *VeinsImages,
              QVector<double> **Veins_x, QVector<double> **Veins_y, const QVector<QString> VeinsNames,
              const QVector<QString> *CSFsImages,
              QVector<double> **CSFs_x, QVector<double> **CSFs_y, const QVector<QString> CSFsNames,
              const QVector<QString> *UndefinesImages,
              QVector<double> **Undefines_x, QVector<double> **Undefines_y, const QVector<QString> UndefinesNames
              ){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return Res;
    }

    //ARTERIES IMAGES
    QString ArteriesImagesFileName = DirName + "/" + "MRI__arteries_images.dat";
    if (ArteriesImages != NULL){
        {
            QVector<QString> NewArteriesImages;
            unsigned int NArteriesImages = ArteriesImages->count();
            for (unsigned int i = 0; i < NArteriesImages; i++){
                QString Image = ArteriesImages->at(i);
                int Pos = Image.lastIndexOf("/");
                Image = Image.remove(0, Pos+1);
                NewArteriesImages.append(Image);
            }

            for (unsigned int i = 0; i < NArteriesImages; i++){
                QFile::copy(ArteriesImages->at(i), DirName + "/" + NewArteriesImages.at(i));
            }

            Res = SaveDat(ArteriesImagesFileName, &NewArteriesImages);
            if (!Res) return Res;
        }
    }
    else{
        Res = SaveDat(ArteriesImagesFileName);
        if (!Res) return Res;
    }

    //ARTERIES
    QString ArteriesFileName = DirName + "/" + "MRI__arteries_names.dat";
    Res = SaveDat(ArteriesFileName, &ArteriesNames);
    if (!Res) return Res;

    unsigned int NArteries = ArteriesNames.count();
    for (unsigned int i = 0; i < NArteries; i++){
        QString ArteriesFileName = DirName + "/" + "MRI__" + ArteriesNames.at(i);
        Res = SaveDat(ArteriesFileName, Arteries_x[i], Arteries_y[i]);
        if (!Res) return Res;
    }

    //VEINS IMAGES
    QString VeinsImagesFileName = DirName + "/" + "MRI__veins_images.dat";
    if (VeinsImages != NULL){
        {
            QVector<QString> NewVeinsImages;
            unsigned int NVeinsImages = VeinsImages->count();
            for (unsigned int i = 0; i < NVeinsImages; i++){
                QString Image = VeinsImages->at(i);
                int Pos = Image.lastIndexOf("/");
                Image = Image.remove(0, Pos+1);
                NewVeinsImages.append(Image);
            }

            for (unsigned int i = 0; i < NVeinsImages; i++){
                QFile::copy(VeinsImages->at(i), DirName + "/" + NewVeinsImages.at(i));
            }

            Res = SaveDat(VeinsImagesFileName, &NewVeinsImages);
            if (!Res) return Res;
        }
    }
    else{
        Res = SaveDat(VeinsImagesFileName);
        if (!Res) return Res;
    }

    //VEINS
    QString VeinsFileName = DirName + "/" + "MRI__veins_names.dat";
    Res = SaveDat(VeinsFileName, &VeinsNames);
    if (!Res) return Res;

    unsigned int NVeins = VeinsNames.count();
    for (unsigned int i = 0; i < NVeins; i++){
        QString VeinsFileName = DirName + "/" + "MRI__" + VeinsNames.at(i);
        Res = SaveDat(VeinsFileName, Veins_x[i], Veins_y[i]);
        if (!Res) return Res;
    }

    //CSFS IMAGES
    QString CSFsImagesFileName = DirName + "/" + "MRI__csfs_images.dat";
    if (CSFsImages != NULL){
        {
            QVector<QString> NewCSFsImages;
            unsigned int NCSFsImages = CSFsImages->count();
            for (unsigned int i = 0; i < NCSFsImages; i++){
                QString Image = CSFsImages->at(i);
                int Pos = Image.lastIndexOf("/");
                Image = Image.remove(0, Pos+1);
                NewCSFsImages.append(Image);
            }

            for (unsigned int i = 0; i < NCSFsImages; i++){
                QFile::copy(CSFsImages->at(i), DirName + "/" + NewCSFsImages.at(i));
            }

            Res = SaveDat(CSFsImagesFileName, &NewCSFsImages);
            if (!Res) return Res;
        }
    }
    else{
        Res = SaveDat(CSFsImagesFileName);
        if (!Res) return Res;
    }

    //CSFS
    QString CSFsFileName = DirName + "/" + "MRI__csfs_names.dat";
    Res = SaveDat(CSFsFileName, &CSFsNames);
    if (!Res) return Res;

    unsigned int NCSFs = CSFsNames.count();
    for (unsigned int i = 0; i < NCSFs; i++){
        QString CSFsFileName = DirName + "/" + "MRI__" + CSFsNames.at(i);
        Res = SaveDat(CSFsFileName, CSFs_x[i], CSFs_y[i]);
        if (!Res) return Res;
    }

    //UNDEFINES IMAGES
    QString UndefinesImagesFileName = DirName + "/" + "MRI__undefines_images.dat";
    if (UndefinesImages != NULL){
        {
            QVector<QString> NewUndefinesImages;
            unsigned int NUndefinesImages = UndefinesImages->count();

            for (unsigned int i = 0; i < NUndefinesImages; i++){
                QString Image = UndefinesImages->at(i);
                int Pos = Image.lastIndexOf("/");
                Image = Image.remove(0, Pos+1);
                NewUndefinesImages.append(Image);
            }

            for (unsigned int i = 0; i < NUndefinesImages; i++){
                QFile::copy(UndefinesImages->at(i), DirName + "/" + NewUndefinesImages.at(i));
            }

            Res = SaveDat(UndefinesImagesFileName, &NewUndefinesImages);
            if (!Res) return Res;
        }
    }
    else{
        Res = SaveDat(UndefinesImagesFileName);
        if (!Res) return Res;
    }

    //UNDEFINES
    QString UndefinesFileName = DirName + "/" + "MRI__undefines_names.dat";
    Res = SaveDat(UndefinesFileName, &UndefinesNames);
    if (!Res) return Res;

    unsigned int NUndefines = UndefinesNames.count();
    for (unsigned int i = 0; i < NUndefines; i++){
        QString UndefinesFileName = DirName + "/" + "MRI__" + UndefinesNames.at(i);
        Res = SaveDat(UndefinesFileName, Undefines_x[i], Undefines_y[i]);
        if (!Res) return Res;
    }

    return Res;
}

bool LoadMRI(const QString DirName,
             QVector<double> *SystoleThreshold, QVector<int> *Quality, QVector<int> *Move,
             QVector<double> *Arterial_x, QVector<double> *Arterial_y, QVector<double> *ArterialResults,
             QVector<double> *Venous_x, QVector<double> *Venous_y, QVector<double> *VenousResults,
             QVector<double> *CSF_x, QVector<double> *CSF_y, QVector<double> *CSFResults,
             QVector<double> *AVFlow_x, QVector<double> *AVFlow_y, QVector<double> *AVFlowResults,
             QVector<double> *AVVolume_x, QVector<double> *AVVolume_y, QVector<double> *AVVolumeResults,
             QVector<double> *AVCSFFlow_x, QVector<double> *AVCSFFlow_y, QVector<double> *AVCSFFlowResults,
             QVector<double> *AVCSFVolume_x, QVector<double> *AVCSFVolume_y, QVector<double> *AVCSFVolumeResults
             ){
    bool Res;

    SystoleThreshold->clear();
    Quality->clear();
    Move->clear();
    Arterial_x->clear();
    Arterial_y->clear();
    ArterialResults->clear();
    Venous_x->clear();
    Venous_y->clear();
    VenousResults->clear();
    CSF_x->clear();
    CSF_y->clear();
    CSFResults->clear();
    AVFlow_x->clear();
    AVFlow_y->clear();
    AVFlowResults->clear();
    AVVolume_x->clear();
    AVVolume_y->clear();
    AVVolumeResults->clear();
    AVCSFFlow_x->clear();
    AVCSFFlow_y->clear();
    AVCSFFlowResults->clear();
    AVCSFVolume_x->clear();
    AVCSFVolume_y->clear();
    AVCSFVolumeResults->clear();

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //SYSTOLE THRESHOLD
    QString SystoleThresholdFileName = DirName + "/" + "MRI__systole_threshold.dat";
    Res = LoadDat(SystoleThresholdFileName, SystoleThreshold);
    if (!Res){
        std::cout << "1" << std::endl;
        return Res;
    }

    //QUALITY
    {
        QString QualityFileName = DirName + "/" + "MRI__quality_arterial.dat";
        Res = LoadDat(QualityFileName, Quality);
        if (!Res){
            std::cout << "2" << std::endl;
            return Res;
        }
    }
    {
        QString QualityFileName = DirName + "/" + "MRI__quality_venous.dat";
        Res = LoadDat(QualityFileName, Quality);
        if (!Res){
            std::cout << "3" << std::endl;
            return Res;
        }
    }
    {
        QString QualityFileName = DirName + "/" + "MRI__quality_csf.dat";
        Res = LoadDat(QualityFileName, Quality);
        if (!Res){
            std::cout << "4" << std::endl;
            return Res;
        }
    }

    //Move
    {
        QString MoveFileName = DirName + "/" + "MRI__move_arterial.dat";
        Res = LoadDat(MoveFileName, Move);
        if (!Res){
            std::cout << "5" << std::endl;
            return Res;
        }
    }
    {
        QString MoveFileName = DirName + "/" + "MRI__move_venous.dat";
        Res = LoadDat(MoveFileName, Move);
        if (!Res){
            std::cout << "6" << std::endl;
            return Res;
        }
    }
    {
        QString MoveFileName = DirName + "/" + "MRI__move_csf.dat";
        Res = LoadDat(MoveFileName, Move);
        if (!Res){
            std::cout << "7" << std::endl;
            return Res;
        }
    }

    //ARTERIAL
    QString ArterialFileName = DirName + "/" + "MRI__arterial.dat";
    Res = LoadDat(ArterialFileName, Arterial_x, Arterial_y);
    if (!Res){
        Arterial_x->clear();
        Arterial_y->clear();
    }

    std::cout << Arterial_x->size() << "\t" << Arterial_y->size() << std::endl;

    //ARTERIAL RESULTS
    QString ArterialResultsFileName = DirName + "/" + "MRI__results_arterial.dat";
    Res = LoadDat(ArterialResultsFileName, ArterialResults);
    if (!Res){
        ArterialResults->clear();
    }

    //VENOUS
    QString VenousFileName = DirName + "/" + "MRI__venous.dat";
    Res = LoadDat(VenousFileName, Venous_x, Venous_y);
    if (!Res){
        Venous_x->clear();
        Venous_y->clear();
    }

    //VENOUS RESULTS
    QString VenousResultsFileName = DirName + "/" + "MRI__results_venous.dat";
    Res = LoadDat(VenousResultsFileName, VenousResults);
    if (!Res){
        VenousResults->clear();
    }

    //CSF
    QString CSFFileName = DirName + "/" + "MRI__csf.dat";
    Res = LoadDat(CSFFileName, CSF_x, CSF_y);
    if (!Res){
        CSF_x->clear(); CSF_y->clear();
    }

    //CSF RESULTS
    QString CSFResultsFileName = DirName + "/" + "MRI__results_csf.dat";
    Res = LoadDat(CSFResultsFileName, CSFResults);
    if (!Res){
        CSFResults->clear();
    }

    //AV FLOW
    QString AVFlowFileName = DirName + "/" + "MRI__av_flow.dat";
    Res = LoadDat(AVFlowFileName, AVFlow_x, AVFlow_y);
    if (!Res){
        AVFlow_x->clear();
        AVFlow_y->clear();
    }

    //AV FLOW RESULTS
    QString AVFlowResultsFileName = DirName + "/" + "MRI__results_av_flow.dat";
    Res = LoadDat(AVFlowResultsFileName, AVFlowResults);
    if (!Res){
        AVFlowResults->clear();
    }

    //AV VOLUME
    QString AVVolumeFileName = DirName + "/" + "MRI__av_volume.dat";
    Res = LoadDat(AVVolumeFileName, AVVolume_x, AVVolume_y);
    if (!Res){
        AVVolume_x->clear();
        AVVolume_y->clear();
    }

    //AV VOLUME RESULTS
    QString AVVolumeResultsFileName = DirName + "/" + "MRI__results_av_volume.dat";
    Res = LoadDat(AVVolumeResultsFileName, AVVolumeResults);
    if (!Res){
        AVVolumeResults->clear();
    }

    //AVCSF FLOW
    QString AVCSFFlowFileName = DirName + "/" + "MRI__avcsf_flow.dat";
    Res = LoadDat(AVCSFFlowFileName, AVCSFFlow_x, AVCSFFlow_y);
    if (!Res){
        AVCSFFlow_x->clear();
        AVCSFFlow_y->clear();
    }

    //AVCSF FLOW RESULTS
    QString AVCSFFlowResultsFileName = DirName + "/" + "MRI__results_avcsf_flow.dat";
    Res = LoadDat(AVCSFFlowResultsFileName, AVCSFFlowResults);
    if (!Res){
        AVCSFFlowResults->clear();
    }

    //AVCSF VOLUME
    QString AVCSFVolumeFileName = DirName + "/" + "MRI__avcsf_volume.dat";
    Res = LoadDat(AVCSFVolumeFileName, AVCSFVolume_x, AVCSFVolume_y);
    if (!Res){
        AVCSFVolume_x->clear();
        AVCSFVolume_y->clear();
    }

    //AVCSF VOLUME RESULTS
    QString AVCSFVolumeResultsFileName = DirName + "/" + "MRI__results_avcsf_volume.dat";
    Res = LoadDat(AVCSFVolumeResultsFileName, AVCSFVolumeResults);
    if (!Res){
        AVCSFVolumeResults->clear();
    }

    return true;
}

bool LoadMRI2_1(const QString DirName,
              QVector<QString> *ArteriesImages,
              QVector<QString> *ArteriesNames,
              QVector<QString> *VeinsImages,
              QVector<QString> *VeinsNames,
              QVector<QString> *CSFsImages,
              QVector<QString> *CSFsNames,
              QVector<QString> *UndefinesImages,
              QVector<QString> *UndefinesNames
              ){
    bool Res;

    ArteriesImages->clear();
    ArteriesNames->clear();
    VeinsImages->clear();
    VeinsNames->clear();
    CSFsImages->clear();
    CSFsNames->clear();
    UndefinesImages->clear();
    UndefinesNames->clear();

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //ARTERIES IMAGES
    QString ArteriesImagesFileName = DirName + "/" + "MRI__arteries_images.dat";
    Res = LoadDat(ArteriesImagesFileName, ArteriesImages);
    if (!Res){
        ArteriesImages->clear();
    }

    //ARTERIES
    QString ArteriesFileName = DirName + "/" + "MRI__arteries_names.dat";
    Res = LoadDat(ArteriesFileName, ArteriesNames);
    if (!Res){
        ArteriesNames->clear();
    }

    //VEINS IMAGES
    QString VeinsImagesFileName = DirName + "/" + "MRI__veins_images.dat";
    Res = LoadDat(VeinsImagesFileName, VeinsImages);
    if (!Res){
        VeinsImages->clear();
    }

    //VEINS
    QString VeinsFileName = DirName + "/" + "MRI__veins_names.dat";
    Res = LoadDat(VeinsFileName, VeinsNames);
    if (!Res){
        VeinsNames->clear();
    }

    //CSFS IMAGES
    QString CSFsImagesFileName = DirName + "/" + "MRI__csfs_images.dat";
    Res = LoadDat(CSFsImagesFileName, CSFsImages);
    if (!Res){
        CSFsImages->clear();
    }

    //CSFS
    QString CSFsFileName = DirName + "/" + "MRI__csfs_names.dat";
    Res = LoadDat(CSFsFileName, CSFsNames);
    if (!Res){
        CSFsNames->clear();
    }

    //UNDEFINES IMAGES
    QString UndefinesImagesFileName = DirName + "/" + "MRI__undefines_images.dat";
    Res = LoadDat(UndefinesImagesFileName, UndefinesImages);
    if (!Res){
        UndefinesImages->clear();
    }

    //UNDEFINES
    QString UndefinesFileName = DirName + "/" + "MRI__undefines_names.dat";
    Res = LoadDat(UndefinesFileName, UndefinesNames);
    if (!Res){
        UndefinesNames->clear();
    }

    return true;
}

bool LoadMRI2_2(const QString DirName,
              QVector<double> **Arteries_x, QVector<double> **Arteries_y, const QVector<QString> ArteriesNames,
              QVector<double> **Veins_x, QVector<double> **Veins_y, const QVector<QString> VeinsNames,
              QVector<double> **CSFs_x, QVector<double> **CSFs_y, const QVector<QString> CSFsNames,
              QVector<double> **Undefines_x, QVector<double> **Undefines_y, const QVector<QString> UndefinesNames
              ){
    bool Res;

    unsigned int NArteries = ArteriesNames.count();
    for (unsigned int i = 0; i < NArteries; i++){
        Arteries_x[i]->clear();
        Arteries_y[i]->clear();
    }
    unsigned int NVeins = VeinsNames.count();
    for (unsigned int i = 0; i < NVeins; i++){
        Veins_x[i]->clear();
        Veins_y[i]->clear();
    }
    unsigned int NCSFs = CSFsNames.count();
    for (unsigned int i = 0; i < NCSFs; i++){
        CSFs_x[i]->clear();
        CSFs_y[i]->clear();
    }
    unsigned int NUndefines = UndefinesNames.count();
    for (unsigned int i = 0; i < NUndefines; i++){
        Undefines_x[i]->clear();
        Undefines_y[i]->clear();
    }

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //ARTERIES
    for (unsigned int i = 0; i < NArteries; i++){
        QString ArteriesFileName = DirName + "/" + "MRI__" + ArteriesNames.at(i);
        Res = LoadDat(ArteriesFileName, Arteries_x[i], Arteries_y[i]);
        if (!Res){
            for (unsigned int i = 0; i < NArteries; i++){
                Arteries_x[i]->clear();
                Arteries_y[i]->clear();
            }
        }
    }

    //VEINS
    for (unsigned int i = 0; i < NVeins; i++){
        QString VeinsFileName = DirName + "/" + "MRI__" + VeinsNames.at(i);
        Res = LoadDat(VeinsFileName, Veins_x[i], Veins_y[i]);
        if (!Res){
            for (unsigned int i = 0; i < NVeins; i++){
                Veins_x[i]->clear();
                Veins_y[i]->clear();
            }
        }
    }

    //CSFS
    for (unsigned int i = 0; i < NCSFs; i++){
        QString CSFsFileName = DirName + "/" + "MRI__" + CSFsNames.at(i);
        Res = LoadDat(CSFsFileName, CSFs_x[i], CSFs_y[i]);
        if (!Res){
            for (unsigned int i = 0; i < NCSFs; i++){
                CSFs_x[i]->clear();
                CSFs_y[i]->clear();
            }
        }
    }

    //Undefines
    for (unsigned int i = 0; i < NUndefines; i++){
        QString UndefinesFileName = DirName + "/" + "MRI__" + UndefinesNames.at(i);
        Res = LoadDat(UndefinesFileName, Undefines_x[i], Undefines_y[i]);
        if (!Res){
            for (unsigned int i = 0; i < NUndefines; i++){
                Undefines_x[i]->clear();
                Undefines_y[i]->clear();
            }
        }
    }

    return true;
}

bool SaveICP(const QString DirName,
             const QVector<double> *Signal_x, const QVector<double> *Signal_y, const QVector<double> Selection, const QVector<int> Quality,
             const QVector<double> *SelectionBasal_x, const QVector<double> *SelectionBasal_y, const QVector<double> *SelectionPlateau_x, const QVector<double> *SelectionPlateau_y, const QVector<double> FFTRange,
             const QVector<double> *FFTSpectrumBasal_x, const QVector<double> *FFTSpectrumBasal_y, const QVector<double> *FFTSpectrumPlateau_x, const QVector<double> *FFTSpectrumPlateau_y, const QVector<double> FFTROI,
             const QVector<double> *IFFTBasal_x, const QVector<double> *IFFTBasal_y, const QVector<double> *IFFTPlateau_x, const QVector<double> *IFFTPlateau_y, const QVector<double> Threshold, const QVector<double> *PeaksBasal_x, const QVector<double> *PeaksBasal_y, const QVector<double> *PeaksPlateau_x, const QVector<double> *PeaksPlateau_y,
             const QVector<double> *MeanBasal_x, const QVector<double> *MeanBasal_y, const QVector<double> *MeanPlateau_x, const QVector<double> *MeanPlateau_y, const QVector<int> IsAdjusted, const QVector<double> Results
             ){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return false;
    }

    //SIGNAL
    QString SignalFileName = DirName + "/" + "ICP__signal.dat";
    Res = SaveDat(SignalFileName, Signal_x, Signal_y);
    if (!Res)return false;

    //SELECTION
    if (Selection.count() == 4){
        {
            QString SelectionFileName = DirName + "/" + "ICP__signal_selection_basal.dat";
            QVector<double> SelectionBasal;
            SelectionBasal.append(Selection.at(0));
            SelectionBasal.append(Selection.at(1));
            Res = SaveDat(SelectionFileName, &SelectionBasal);
            if (!Res)return false;
        }
        {
            QString SelectionFileName = DirName + "/" + "ICP__signal_selection_plateau.dat";
            QVector<double> SelectionPlateau;
            SelectionPlateau.append(Selection.at(2));
            SelectionPlateau.append(Selection.at(3));
            Res = SaveDat(SelectionFileName, &SelectionPlateau);
            if (!Res)return false;
        }
    }

    //QUALITY
    if (Quality.count() == 2){
        {
            QString QualityFileName = DirName + "/" + "ICP__quality_basal.dat";
            QVector<double> QualityBasal;
            QualityBasal.append(Quality.at(0));
            Res = SaveDat(QualityFileName, &QualityBasal);
            if (!Res)return false;
        }
        {
            QString QualityFileName = DirName + "/" + "ICP__quality_plateau.dat";
            QVector<double> QualityPlateau;
            QualityPlateau.append(Quality.at(1));
            Res = SaveDat(QualityFileName, &QualityPlateau);
            if (!Res)return false;
        }
    }

    //FFT
    QString SelectionBasalFileName = DirName + "/" + "ICP__selection_basal.dat";
    Res = SaveDat(SelectionBasalFileName, SelectionBasal_x, SelectionBasal_y);
    if (!Res)return false;

    QString SelectionPlateauFileName = DirName + "/" + "ICP__selection_plateau.dat";
    Res = SaveDat(SelectionPlateauFileName, SelectionPlateau_x, SelectionPlateau_y);
    if (!Res)return false;

    //FFT RANGE
    if (FFTRange.count() == 4){
        {
            QString FFTRangeFileName = DirName + "/" + "ICP__fftrange_basal.dat";
            QVector<double> FFTRangeBasal;
            FFTRangeBasal.append(FFTRange.at(0));
            FFTRangeBasal.append(FFTRange.at(1));
            Res = SaveDat(FFTRangeFileName, &FFTRangeBasal);
            if (!Res)return false;
        }
        {
            QString FFTRangeFileName = DirName + "/" + "ICP__fftrange_plateau.dat";
            QVector<double> FFTRangePlateau;
            FFTRangePlateau.append(FFTRange.at(2));
            FFTRangePlateau.append(FFTRange.at(3));
            Res = SaveDat(FFTRangeFileName, &FFTRangePlateau);
            if (!Res)return false;
        }
    }

    //FFT SPECTRUM
    QString FFTSpectrumBasalFileName = DirName + "/" + "ICP__fftspectrum_basal.dat";
    Res = SaveDat(FFTSpectrumBasalFileName, FFTSpectrumBasal_x, FFTSpectrumBasal_y);
    if (!Res)return false;

    QString FFTSpectrumPlateauFileName = DirName + "/" + "ICP__fftspectrum_plateau.dat";
    Res = SaveDat(FFTSpectrumPlateauFileName, FFTSpectrumPlateau_x, FFTSpectrumPlateau_y);
    if (!Res)return false;

    //FFT ROI
    if (FFTROI.count() == 4){
        {
            QString FFTROIFileName = DirName + "/" + "ICP__fftroi_basal.dat";
            QVector<double> FFTROIBasal;
            FFTROIBasal.append(FFTROI.at(0));
            FFTROIBasal.append(FFTROI.at(1));
            Res = SaveDat(FFTROIFileName, &FFTROIBasal);
            if (!Res)return false;
        }
        {
            QString FFTROIFileName = DirName + "/" + "ICP__fftroi_plateau.dat";
            QVector<double> FFTROIPlateau;
            FFTROIPlateau.append(FFTROI.at(2));
            FFTROIPlateau.append(FFTROI.at(3));
            Res = SaveDat(FFTROIFileName, &FFTROIPlateau);
            if (!Res)return false;
        }
    }

    //IFFT
    QString IFFTBasalFileName = DirName + "/" + "ICP__ifft_basal.dat";
    Res = SaveDat(IFFTBasalFileName, IFFTBasal_x, IFFTBasal_y);
    if (!Res)return false;

    QString IFFTPlateauFileName = DirName + "/" + "ICP__ifft_plateau.dat";
    Res = SaveDat(IFFTPlateauFileName, IFFTPlateau_x, IFFTPlateau_y);
    if (!Res)return false;

    //THRESHOLD
    if (Threshold.count() == 2){
        {
            QString ThresholdFileName = DirName + "/" + "ICP__threshold_basal.dat";
            QVector<double> ThresholdBasal;
            ThresholdBasal.append(Threshold.at(0));
            Res = SaveDat(ThresholdFileName, &ThresholdBasal);
            if (!Res)return false;
        }
        {
            QString ThresholdFileName = DirName + "/" + "ICP__threshold_plateau.dat";
            QVector<double> ThresholdPlateau;
            ThresholdPlateau.append(Threshold.at(1));
            Res = SaveDat(ThresholdFileName, &ThresholdPlateau);
            if (!Res)return false;
        }
    }

    //PEAKS
    QString PeaksBasalFileName = DirName + "/" + "ICP__peaks_basal.dat";
    Res = SaveDat(PeaksBasalFileName, PeaksBasal_x, PeaksBasal_y);
    if (!Res)return false;

    QString PeaksPlateauFileName = DirName + "/" + "ICP__peaks_plateau.dat";
    Res = SaveDat(PeaksPlateauFileName, PeaksPlateau_x, PeaksPlateau_y);
    if (!Res)return false;

    //MEAN
    QString MeanBasalFileName = DirName + "/" + "ICP__mean_basal.dat";
    Res = SaveDat(MeanBasalFileName, MeanBasal_x, MeanBasal_y);
    if (!Res)return false;

    QString MeanPlateauFileName = DirName + "/" + "ICP__mean_plateau.dat";
    Res = SaveDat(MeanPlateauFileName, MeanPlateau_x, MeanPlateau_y);
    if (!Res)return false;

    //IS ADJUSTED
    if (IsAdjusted.count() == 2){
        {
            QString IsAdjustedFileName = DirName + "/" + "ICP__isadjusted_basal.dat";
            QVector<double> IsAdjustedBasal;
            IsAdjustedBasal.append(IsAdjusted.at(0));
            Res = SaveDat(IsAdjustedFileName, &IsAdjustedBasal);
            if (!Res)return false;
        }
        {
            QString IsAdjustedFileName = DirName + "/" + "ICP__isadjusted_plateau.dat";
            QVector<double> IsAdjustedPlateau;
            IsAdjustedPlateau.append(IsAdjusted.at(0));
            Res = SaveDat(IsAdjustedFileName, &IsAdjustedPlateau);
            if (!Res)return false;
        }
    }

    //RESULTS
    if (Results.count() == 12){
        {
            QString ResultsFileName = DirName + "/" + "ICP__results_basal.dat";
            QVector<double> ResultsBasal;
            for (int i = 0; i < 6; i++){
                ResultsBasal.append(Results.at(i));
            }
            Res = SaveDat(ResultsFileName, &ResultsBasal);
            if (!Res)return false;
        }
        {
            QString ResultsFileName = DirName + "/" + "ICP__results_plateau.dat";
            QVector<double> ResultsPlateau;
            for (int i = 3; i < 12; i++){
                ResultsPlateau.append(Results.at(i));
            }
            Res = SaveDat(ResultsFileName, &ResultsPlateau);
            if (!Res)return false;
        }
    }

    return true;
}

bool LoadICP(const QString DirName,
             QVector<double> *Signal_x, QVector<double> *Signal_y, QVector<double> *Selection, QVector<int> *Quality,
             QVector<double> *SelectionBasal_x, QVector<double> *SelectionBasal_y, QVector<double> *SelectionPlateau_x, QVector<double> *SelectionPlateau_y, QVector<double> *FFTRange,
             QVector<double> *FFTSpectrumBasal_x, QVector<double> *FFTSpectrumBasal_y, QVector<double> *FFTSpectrumPlateau_x, QVector<double> *FFTSpectrumPlateau_y, QVector<double> *FFTROI,
             QVector<double> *IFFTBasal_x, QVector<double> *IFFTBasal_y, QVector<double> *IFFTPlateau_x, QVector<double> *IFFTPlateau_y, QVector<double> *Threshold, QVector<double> *PeaksBasal_x, QVector<double> *PeaksBasal_y, QVector<double> *PeaksPlateau_x, QVector<double> *PeaksPlateau_y,
             QVector<double> *MeanBasal_x, QVector<double> *MeanBasal_y, QVector<double> *MeanPlateau_x, QVector<double> *MeanPlateau_y, QVector<int> *IsAdjusted, QVector<double> *Results
             ){
    bool Res;

    Signal_x->clear();
    Signal_y->clear();
    Selection->clear();
    Quality->clear();
    SelectionBasal_x->clear();
    SelectionBasal_y->clear();
    SelectionPlateau_x->clear();
    SelectionPlateau_y->clear();
    FFTRange->clear();
    FFTSpectrumBasal_x->clear();
    FFTSpectrumBasal_y->clear();
    FFTSpectrumPlateau_x->clear();
    FFTSpectrumPlateau_y->clear();
    FFTROI->clear();
    IFFTBasal_x->clear();
    IFFTBasal_y->clear();
    IFFTPlateau_x->clear();
    IFFTPlateau_y->clear();
    Threshold->clear();
    PeaksBasal_x->clear();
    PeaksBasal_y->clear();
    PeaksPlateau_x->clear();
    PeaksPlateau_y->clear();
    MeanBasal_x->clear();
    MeanBasal_y->clear();
    MeanPlateau_x->clear();
    MeanPlateau_y->clear();
    IsAdjusted->clear();
    Results->clear();

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //SIGNAL
    QString SignalFileName = DirName + "/" + "ICP__signal.dat";
    Res = LoadDat(SignalFileName, Signal_x, Signal_y);
    if (!Res) return Res;

    //SELECTION
    {
        QString SelectionFileName = DirName + "/" + "ICP__signal_selection_basal.dat";
        Res = LoadDat(SelectionFileName, Selection);
        if (!Res){
            Selection->clear();
        }
    }
    {
        QString SelectionFileName = DirName + "/" + "ICP__signal_selection_plateau.dat";
        Res = LoadDat(SelectionFileName, Selection);
        if (!Res){
            Selection->clear();
        }
    }

    //QUALITY
    {
        QString QualityFileName = DirName + "/" + "ICP__quality_basal.dat";
        Res = (LoadDat)(QualityFileName, Quality);
        if (!Res){
            Quality->clear();
        }
    }
    {
        QString QualityFileName = DirName + "/" + "ICP__quality_plateau.dat";
        Res = LoadDat(QualityFileName, Quality);
        if (!Res){
            Quality->clear();
        }
    }

    //FFT
    QString SelectionBasalFileName = DirName + "/" + "ICP__selection_basal.dat";
    Res = LoadDat(SelectionBasalFileName, SelectionBasal_x, SelectionBasal_y);
    if (!Res){
        SelectionBasal_x->clear();
        SelectionBasal_y->clear();
    }

    QString SelectionPlateauFileName = DirName + "/" + "ICP__selection_plateau.dat";
    Res = LoadDat(SelectionPlateauFileName, SelectionPlateau_x, SelectionPlateau_y);
    if (!Res){
        SelectionPlateau_x->clear();
        SelectionPlateau_y->clear();
    }

    //FFT RANGE
    {
        QString FFTRangeFileName = DirName + "/" + "ICP__fftrange_basal.dat";
        Res = LoadDat(FFTRangeFileName, FFTRange);
        if (!Res){
            FFTRange->clear();
        }
    }
    {
        QString FFTRangeFileName = DirName + "/" + "ICP__fftrange_plateau.dat";
        Res = LoadDat(FFTRangeFileName, FFTRange);
        if (!Res){
            FFTRange->clear();
        }
    }

    //FFT SPECTRUM
    QString FFTSpectrumBasalFileName = DirName + "/" + "ICP__fftspectrum_basal.dat";
    Res = LoadDat(FFTSpectrumBasalFileName, FFTSpectrumBasal_x, FFTSpectrumBasal_y);
    if (!Res){
        FFTSpectrumBasal_x->clear();
        FFTSpectrumBasal_y->clear();
    }

    QString FFTSpectrumPlateauFileName = DirName + "/" + "ICP__fftspectrum_plateau.dat";
    Res = LoadDat(FFTSpectrumPlateauFileName, FFTSpectrumPlateau_x, FFTSpectrumPlateau_y);
    if (!Res){
        FFTSpectrumPlateau_x->clear();
        FFTSpectrumPlateau_y->clear();
    }

    //FFT ROI
    {
        QString FFTROIFileName = DirName + "/" + "ICP__fftroi_basal.dat";
        Res = LoadDat(FFTROIFileName, FFTROI);
        if (!Res){
            FFTROI->clear();
        }
    }
    {
        QString FFTROIFileName = DirName + "/" + "ICP__fftroi_plateau.dat";
        Res = LoadDat(FFTROIFileName, FFTROI);
        if (!Res){
            FFTROI->clear();
        }
    }

    //IFFT
    QString IFFTBasalFileName = DirName + "/" + "ICP__ifft_basal.dat";
    Res = LoadDat(IFFTBasalFileName, IFFTBasal_x, IFFTBasal_y);
    if (!Res){
        IFFTBasal_x->clear();
        IFFTBasal_y->clear();
    }

    QString IFFTPlateauFileName = DirName + "/" + "ICP__ifft_plateau.dat";
    Res = LoadDat(IFFTPlateauFileName, IFFTPlateau_x, IFFTPlateau_y);
    if (!Res){
        IFFTPlateau_x->clear();
        IFFTPlateau_y->clear();
    }

    //THRESHOLD
    {
        QString ThresholdFileName = DirName + "/" + "ICP__threshold_basal.dat";
        Res = LoadDat(ThresholdFileName, Threshold);
        if (!Res){
            Threshold->clear();
        }
    }
    {
        QString ThresholdFileName = DirName + "/" + "ICP__threshold_plateau.dat";
        Res = LoadDat(ThresholdFileName, Threshold);
        if (!Res){
            Threshold->clear();
        }
    }

    //PEAKS
    QString PeaksBasalFileName = DirName + "/" + "ICP__peaks_basal.dat";
    Res = LoadDat(PeaksBasalFileName, PeaksBasal_x, PeaksBasal_y);
    if (!Res){
        PeaksBasal_x->clear();
        PeaksBasal_y->clear();
    }

    QString PeaksPlateauFileName = DirName + "/" + "ICP__peaks_plateau.dat";
    Res = LoadDat(PeaksPlateauFileName, PeaksPlateau_x, PeaksPlateau_y);
    if (!Res){
        PeaksPlateau_x->clear();
        PeaksPlateau_y->clear();
    }

    //MEAN
    QString MeanBasalFileName = DirName + "/" + "ICP__mean_basal.dat";
    Res = LoadDat(MeanBasalFileName, MeanBasal_x, MeanBasal_y);
    if (!Res){
        MeanBasal_x->clear();
        MeanBasal_y->clear();
    }

    QString MeanPlateauFileName = DirName + "/" + "ICP__mean_plateau.dat";
    Res = LoadDat(MeanPlateauFileName, MeanPlateau_x, MeanPlateau_y);
    if (!Res){
        MeanPlateau_x->clear();
        MeanPlateau_y->clear();
    }

    //IS ADJUSTED
    {
        QString IsAdjustedFileName = DirName + "/" + "ICP__isadjusted_basal.dat";
        Res = LoadDat(IsAdjustedFileName, IsAdjusted);
        if (!Res){
            IsAdjusted->clear();
        }
    }
    {
        QString IsAdjustedFileName = DirName + "/" + "ICP__isadjusted_plateau.dat";
        Res = LoadDat(IsAdjustedFileName, IsAdjusted);
        if (!Res){
            IsAdjusted->clear();
        }
    }

    //RESULTS
    {
        QString ResultsFileName = DirName + "/" + "ICP__results_basal.dat";
        Res = LoadDat(ResultsFileName, Results);
        if (!Res){
            Results->clear();
        }
    }
    {
        QString ResultsFileName = DirName + "/" + "ICP__results_plateau.dat";
        Res = LoadDat(ResultsFileName, Results);
        if (!Res){
            Results->clear();
        }
    }

    return true;
}

bool LoadICPResults(const QString DirName, QVector<double> *Results){
    bool Res;

    Results->clear();

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //RESULTS
    {
        QString ResultsFileName = DirName + "/" + "ICP__results_basal.dat";
        Res = LoadDat(ResultsFileName, Results);
        if (!Res) return Res;
    }
    {
        QString ResultsFileName = DirName + "/" + "ICP__results_plateau.dat";
        Res = LoadDat(ResultsFileName, Results);
        if (!Res) return Res;
    }

    return Res;
}

bool SaveCompliance(const QString DirName, const QVector<int> Selection, const QVector<double> ComplianceResults){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return false;
    }

    //SELECTION
    QString SelectionFileName = DirName + "/" + "COMPLIANCE__selection.dat";
    Res = SaveDat(SelectionFileName, &Selection);
    if (!Res)return false;

    //COMPLIANCE RESULTS
    QString ComplianceResultsFileName = DirName + "/" + "COMPLIANCE__results.dat";
    Res = SaveDat(ComplianceResultsFileName, &ComplianceResults);
    if (!Res)return false;

    return Res;
}

bool LoadCompliance(const QString DirName, QVector<int> *Selection, QVector<double> *ComplianceResults){
    bool Res;

    Selection->clear();
    ComplianceResults->clear();

    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        return true;
    }

    //SELECTION
    QString SelectionFileName = DirName + "/" + "COMPLIANCE__selection.dat";
    Res = LoadDat(SelectionFileName, Selection);
    if (!Res)return false;

    //COMPLIANCE RESULTS
    QString ComplianceResultsFileName = DirName + "/" + "COMPLIANCE__results.dat";
    Res = LoadDat(ComplianceResultsFileName, ComplianceResults);
    if (!Res)return false;

    return Res;
}

bool LoadComplianceResults(const QString DirName, QVector<double> *Results){
    bool Res;

    Results->clear();

    //RESULTS
    QString ComplianceResultsFileName = DirName + "/" + "COMPLIANCE__results.dat";
    Res = LoadDat(ComplianceResultsFileName, Results);
    if (!Res)return false;

    return Res;
}

bool SaveTransfertFunction(const QString DirName, const QVector<int> Selection){
    bool Res;

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return false;
    }

    //SELECTION
    QString SelectionFileName = DirName + "/" + "TRANSFERTFUNCTION__selection.dat";
    Res = SaveDat(SelectionFileName, &Selection);
    if (!Res)return false;

    return Res;
}

bool LoadTransfertFunction(const QString DirName, QVector<int> *Selection){
    bool Res;

    Selection->clear();

    //MkDir
    QDir ResultsDir = QDir(DirName);
    if (!ResultsDir.exists()){
        Res = ResultsDir.mkdir(DirName);
        if (!Res)return false;
    }

    //SELECTION
    QString SelectionFileName = DirName + "/" + "TRANSFERTFUNCTION__selection.dat";
    Res = LoadDat(SelectionFileName, Selection);
    if (!Res)return false;

    return Res;
}

bool SaveCSV(QString FileName, QVector<double> *X, QVector<double> *Y){
    unsigned int NX = X->count();
    unsigned int NY = Y->count();

    if ((NX == NY) && (NX != 0)){
        QFile File(FileName);
        if (File.open(QIODevice::WriteOnly)){
            for (unsigned int i = 0; i < NX; i++){
                File.write(QString::number(X->at(i)).toStdString().c_str());
                File.write("\t");
                File.write(QString::number(Y->at(i)).toStdString().c_str());
                if (i != (NX-1)) File.write("\n");
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


