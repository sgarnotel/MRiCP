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

#include "dialogimportflowexplorer.h"

void DialogImportFloweXplorer::InitVar(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Grid
    Grid = new QGridLayout;

    //Label
    LabelFloweXplorerDir = new QLabel;

    //LineEdit
    LineEditFloweXplorerDir = new QLineEdit;

    //List
    ListPatients = new QListWidget;

    //PushButton
    PushButtonFloweXplorerDir = new QPushButton;
    PushButtonLoad = new QPushButton;
    PushButtonImport = new QPushButton;

    //String
    StringFloweXplorerDir = "";
}

void DialogImportFloweXplorer::InitWin(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    //Dialog
    this->setModal(true);
    this->setLayout(Grid);

    //Grid
    Grid->addWidget(LabelFloweXplorerDir, 0, 0, 1, 1);
    Grid->addWidget(LineEditFloweXplorerDir, 0, 1, 1, 1);
    Grid->addWidget(PushButtonFloweXplorerDir, 0, 2, 1, 1);
    Grid->addWidget(PushButtonLoad, 1, 0, 1, 3);
    Grid->addWidget(ListPatients, 2, 0, 10, 3);
    Grid->addWidget(PushButtonImport, 12, 0, 1, 3);

    //Label
    LabelFloweXplorerDir->setText("Flow eXplorer results directory");

    //LineEdit
    LineEditFloweXplorerDir->setReadOnly(true);

    //List
    ListPatients->setSelectionMode(QListWidget::MultiSelection);

    //PushButton
    PushButtonFloweXplorerDir->setIcon(QIcon("img/dir.png"));
    PushButtonLoad->setText("Load");
    PushButtonImport->setText("Import");
}

void DialogImportFloweXplorer::InitSig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //PushButton
    connect(PushButtonFloweXplorerDir, SIGNAL(clicked(bool)), this, SLOT(DoFloweXplorerDir()));
    connect(PushButtonLoad, SIGNAL(clicked(bool)), this, SLOT(DoLoad()));
    connect(PushButtonImport, SIGNAL(clicked(bool)), this, SLOT(DoImport()));
}

void DialogImportFloweXplorer::InitCss(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Dialog
    this->setWindowTitle("Import from Flow eXplorer");
}

DialogImportFloweXplorer::DialogImportFloweXplorer(QWidget *parent) : QDialog(parent)
{
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

bool DialogImportFloweXplorer::DoFloweXplorerDir(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    StringFloweXplorerDir = QFileDialog::getExistingDirectory(this, "Select the Flow eXplorer results directory", "/home/simon/Documents/These/SOFTWARE/FLOW_EXPLORER/Flow_eXplorer-Release/Flow_eXplorer-RESULTS2");

    if (!StringFloweXplorerDir.isEmpty()){
        LineEditFloweXplorerDir->setText(StringFloweXplorerDir);
        return true;
    }
    else{
        return false;
    }
}

bool DialogImportFloweXplorer::DoLoad(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (!StringFloweXplorerDir.isEmpty()){
        QDir FloweXplorerDir = QDir(StringFloweXplorerDir);

        if (FloweXplorerDir.exists()){
            QStringList Patients = FloweXplorerDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

            if (!Patients.isEmpty()){
                ListPatients->addItems(Patients);
                return true;
            }
            else{
                QMessageBox::warning(this, "Error", "There is no patients in the results directory");
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Results directory does not exist");
        }
    }
    else{
        QMessageBox::warning(this, "Error", "Select a results directory first");
    }
    return false;
}

bool DialogImportFloweXplorer::DoImport(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int NList = ListPatients->count();

    if (NList != 0){
        QStringList SelectedPatients;
        for (unsigned int i = 0; i < NList; i++){
            if (ListPatients->item(i)->isSelected()){
                SelectedPatients.append(ListPatients->item(i)->text());
            }
        }

        unsigned int NPatients = SelectedPatients.size();
        if (NPatients != 0){
            for (unsigned int i = 0; i < NPatients; i++){
                bool Res = CreatePatient(StringFloweXplorerDir, SelectedPatients.at(i));
                if (!Res){
                    QMessageBox::warning(this, "Error", "Patient " + SelectedPatients.at(i) + " not created");
                }
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Select at least one patient");
        }
    }
    else{
        QMessageBox::warning(this, "Error", "Patients list is empty");
    }
    return false;
}

bool DialogImportFloweXplorer::CreatePatient(QString Directory, QString Patient){
    QDir PatientDir = QDir(Directory + "/" + Patient);

    if (PatientDir.exists()){
        QStringList Files = PatientDir.entryList();

        unsigned int NFiles = Files.size();

        if (NFiles != 0){
            bool Res;

            QString MRIPath;
            QStringList MRIArterialSpinalFiles;
            QStringList MRIVenousSpinalFiles;
            QStringList MRICSFSpinalFiles;
            QStringList MRIArterialIntracranialFiles;
            QStringList MRIVenousIntracranialFiles;
            QStringList MRICSFIntracranialFiles;
            QString ICPPath;

            //Read Files.dat
            int Pos = Files.indexOf("Files.dat");
            if (Pos == -1){
                QMessageBox::warning(this, "Error", "Unbale to find files " + Patient);
                return false;
            }
            {
                QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                if (File.open(QIODevice::ReadOnly)){
                    QString TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    QStringList TMPList = TMP.split("\t");
                    MRIPath = TMPList.at(1);

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRIArterialSpinalFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRIVenousSpinalFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRICSFSpinalFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRIArterialIntracranialFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRIVenousIntracranialFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    TMP = TMPList.at(1);
                    MRICSFIntracranialFiles = TMP.split(" + ");

                    TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    TMPList = TMP.split("\t");
                    ICPPath = TMP.at(1);

                    File.close();
                }
                else{
                    QMessageBox::warning(this, "Error", "Unable to read file: " + Files.at(Pos));
                    return false;
                }
            }

            QString MRIExamNumber;
            //Read informations.dat
            Pos = Files.indexOf("informations.dat");
            if (Pos == -1){
                QMessageBox::warning(this, "Error", "Unable to find files " + Patient);
                return false;
            }
            {
                QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                if (File.open(QIODevice::ReadOnly)){
                    QString TMP = File.readLine();
                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                    QStringList TMPList = TMP.split("\t");
                    MRIExamNumber = TMPList.at(1);
                    File.close();
                }
                else{
                    QMessageBox::warning(this, "Error", "Unbale to read file: " + Files.at(Pos));
                }
            }

            //Create Patient Directory
            QString ResultsDirName = GetResultsDir(&Res);
            if (!Res){
                std::cerr << "Unable to find the MRiCP results directory" << std::endl;
                return false;
            }

            QDir ResultsDir = QDir(ResultsDirName);

            Res = ResultsDir.mkdir(Patient);
            if (!Res){
                std::cerr << "Mkdir failed " << Patient.toStdString() << std::endl;
            }

            {   //PATIENT
                QString PATIENTGlobalFileName = ResultsDirName + "/" + Patient + "/PATIENT__global_informations.dat";
                {
                    QFile File(PATIENTGlobalFileName);
                    if (File.open(QIODevice::WriteOnly)){
                        File.write(Patient.toStdString().c_str()); File.write("\n");
                        File.write("\n");
                        File.write("0"); File.write("\n");
                        File.write("\n");
                        File.write("None");
                        File.close();
                    }
                    else{
                        std::cerr << "Unbale to write " << PATIENTGlobalFileName.toStdString() << std::endl;
                    }
                }

                QString PATIENTMRIFileName = ResultsDirName + "/" + Patient + "/PATIENT__mri_informations.dat";
                {
                    QFile File(PATIENTMRIFileName);
                    if (File.open(QIODevice::WriteOnly)){
                        File.write("Patient: "); File.write(Patient.toStdString().c_str()); File.write("\n");
                        File.write("Exam number: "); File.write(MRIExamNumber.toStdString().c_str()); File.write("\n");
                        File.close();
                    }
                    else{
                        std::cerr << "Unbale to write " << PATIENTMRIFileName.toStdString() << std::endl;
                    }
                }

                QString PATIENTICPFileName = ResultsDirName + "/" + Patient + "/PATIENT__icp_informations.dat";
                {
                    QFile File(PATIENTICPFileName);
                    if (File.open(QIODevice::WriteOnly)){
                        File.write("Patient: "); File.write(Patient.toStdString().c_str()); File.write("\n");
                        File.close();
                    }
                    else{
                        std::cerr << "Unbale to write " << PATIENTICPFileName.toStdString() << std::endl;
                    }
                }

                QString PATIENTEPIFileName = ResultsDirName + "/" + Patient + "/PATIENT__epi_informations.dat";
                {
                    QFile File(PATIENTEPIFileName);
                    if (File.open(QIODevice::WriteOnly)){
                        File.close();
                    }
                    else{
                        std::cerr << "Unbale to write " << PATIENTEPIFileName.toStdString() << std::endl;
                    }
                }
            }

            {   //MRI
                Res = ResultsDir.mkdir(Patient + "/MRI");
                if (!Res){
                    std::cerr << "Mkdir failed " << Patient.toStdString() << "/MRI" << std::endl;
                }

                {   //all
                    Res = ResultsDir.mkdir(Patient + "/MRI/all");
                    if (!Res){
                        std::cerr << "Mkdir failed " << Patient.toStdString() << "/MRI/all" << std::endl;
                    }

                    //Copy MRI all
                    unsigned int NMRIArterialSpinalFiles = MRIArterialSpinalFiles.size();
                    for (unsigned int i = 0; i < NMRIArterialSpinalFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRIArterialSpinalFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRIArterialSpinalFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArterialSpinalFiles.at(i).toStdString() << std::endl;
                        }
                    }
                    unsigned int NMRIVenousSpinalFiles = MRIVenousSpinalFiles.size();
                    for (unsigned int i = 0; i < NMRIVenousSpinalFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRIVenousSpinalFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRIVenousSpinalFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRIVenousSpinalFiles.at(i).toStdString() << std::endl;
                        }
                    }
                    unsigned int NMRICSFSpinalFiles = MRICSFSpinalFiles.size();
                    for (unsigned int i = 0; i < NMRICSFSpinalFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRICSFSpinalFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRICSFSpinalFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRICSFSpinalFiles.at(i).toStdString() << std::endl;
                        }
                    }
                    unsigned int NMRIArterialIntracranialFiles = MRIArterialIntracranialFiles.size();
                    for (unsigned int i = 0; i < NMRIArterialIntracranialFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRIArterialIntracranialFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRIArterialIntracranialFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArterialIntracranialFiles.at(i).toStdString() << std::endl;
                        }
                    }
                    unsigned int NMRIVenousIntracranialFiles = MRIVenousIntracranialFiles.size();
                    for (unsigned int i = 0; i < NMRIVenousIntracranialFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRIVenousIntracranialFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRIVenousIntracranialFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRIVenousIntracranialFiles.at(i).toStdString() << std::endl;
                        }
                    }
                    unsigned int NMRICSFIntracranialFiles = MRICSFIntracranialFiles.size();
                    for (unsigned int i = 0; i < NMRICSFIntracranialFiles; i++){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + MRICSFIntracranialFiles.at(i), ResultsDirName + "/" + Patient + "/MRI/all/MRI__" + MRICSFIntracranialFiles.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << MRICSFIntracranialFiles.at(i).toStdString() << std::endl;
                        }
                    }

                    //Create MRI file name
                    QString MRIArterialFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__arteries_names.dat";
                    {
                        QFile File(MRIArterialFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRIArterialSpinalFiles; i++){
                                File.write(MRIArterialSpinalFiles.at(i).toStdString().c_str());
                                File.write("\n");
                            }
                            for (unsigned int i = 0; i < NMRIArterialIntracranialFiles; i++){
                                File.write(MRIArterialIntracranialFiles.at(i).toStdString().c_str());
                                if (i != NMRIArterialIntracranialFiles-1) File.write("\n");
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIArterialFileName.toStdString() << std::endl;
                        }
                    }
                    QString MRIVenousFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__veins_names.dat";
                    {
                        QFile File(MRIVenousFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRIVenousSpinalFiles; i++){
                                File.write(MRIVenousSpinalFiles.at(i).toStdString().c_str());
                                File.write("\n");
                            }
                            for (unsigned int i = 0; i < NMRIVenousIntracranialFiles; i++){
                                File.write(MRIVenousIntracranialFiles.at(i).toStdString().c_str());
                                if (i != NMRIVenousIntracranialFiles-1) File.write("\n");
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIVenousFileName.toStdString() << std::endl;
                        }
                    }
                    QString MRICSFFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__csfs_names.dat";
                    {
                        QFile File(MRICSFFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRICSFSpinalFiles; i++){
                                File.write(MRICSFSpinalFiles.at(i).toStdString().c_str());
                                File.write("\n");
                            }
                            for (unsigned int i = 0; i < NMRICSFIntracranialFiles; i++){
                                File.write(MRICSFIntracranialFiles.at(i).toStdString().c_str());
                                if (i != NMRICSFIntracranialFiles-1) File.write("\n");
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRICSFFileName.toStdString() << std::endl;
                        }
                    }
                    QString MRIUndefinedFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__undefines_names.dat";
                    {
                        QFile File(MRIUndefinedFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.close();   //This functionnality did not exists in Flow eXplorer
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIUndefinedFileName.toStdString() << std::endl;
                        }
                    }

                    //Check for MRI Images
                    QDir ImageDir = QDir(MRIPath + "/" + MRIExamNumber + "/images");

                    QStringList NameFilter;
                    NameFilter << "*.jpg";
                    QStringList Images = ImageDir.entryList(NameFilter);

                    //Copy MRI Images
                    unsigned int NImages = Images.size();
                    for (unsigned int i = 0; i < NImages; i++){
                        Res = QFile::copy(MRIPath + "/" + MRIExamNumber + "/images/" + Images.at(i), ResultsDirName + "/" + Patient + "/MRI/all/" + Images.at(i));
                        if (!Res){
                            std::cerr << "Copy failed " << Images.at(i).toStdString() << std::endl;
                        }
                    }

                    //Copy MRI IMages files
                    QString MRIArterialImagesFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__arteries_images.dat";
                    {
                        QFile File(MRIArterialImagesFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRIArterialSpinalFiles; i++){
                                QString TMPFileName = MRIArterialSpinalFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            for (unsigned int i = 0; i < NMRIArterialIntracranialFiles; i++){
                                QString TMPFileName = MRIArterialIntracranialFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIArterialImagesFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIVenousImagesFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__veins_images.dat";
                    {
                        QFile File(MRIVenousImagesFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRIVenousSpinalFiles; i++){
                                QString TMPFileName = MRIVenousSpinalFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            for (unsigned int i = 0; i < NMRIVenousIntracranialFiles; i++){
                                QString TMPFileName = MRIVenousIntracranialFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIVenousImagesFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRICSFImagesFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__csfs_images.dat";
                    {
                        QFile File(MRICSFImagesFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            for (unsigned int i = 0; i < NMRICSFSpinalFiles; i++){
                                QString TMPFileName = MRICSFSpinalFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            for (unsigned int i = 0; i < NMRICSFIntracranialFiles; i++){
                                QString TMPFileName = MRICSFIntracranialFiles.at(i);
                                TMPFileName = TMPFileName.remove(".txt");
                                TMPFileName = TMPFileName.append(".jpg");
                                for (unsigned j = 0; j < NImages; j++){
                                    QString TMPImageName = Images.at(j);
                                    TMPImageName = TMPImageName.toLower();

                                    if (TMPImageName.compare(TMPFileName) == 0){
                                        File.write(Images.at(j).toStdString().c_str());
                                        File.write("\n");
                                    }
                                }
                            }
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRICSFImagesFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIUndefinedImagesFileName = ResultsDirName + "/" + Patient + "/MRI/all/MRI__undefines_images.dat";
                    {
                        QFile File(MRIUndefinedImagesFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.close();
                        }
                        else{
                            std::cerr << "Unbale to write " << MRIUndefinedImagesFileName.toStdString() << std::endl;
                        }
                    }
                }

                {   //spinal
                    Res = ResultsDir.mkdir(Patient + "/MRI/spinal");
                    if (!Res){
                        std::cerr << "Mkdir failed " << Patient.toStdString() << "/MRI/spinal" << std::endl;
                    }

                    QString MRIArterialSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__arterial.dat";
                    Pos = Files.indexOf("MRI_arterial_cervical__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arterial spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArterialSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArterialSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArterialSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_arterial.dat";
                    QString MRIArterialSpinalMoveFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__move_arterial.dat";
                    QString MRIArterialSpinalSystoleFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__systole_threshold.dat";
                    Pos = Files.indexOf("MRI_arterial_cervical__data.dat");
                    if (Pos != -1){
                        QString Systole;
                        QString Move;
                        QString HeartRate, Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //SystoleT
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Systole = TMPList.at(1);

                            TMP = File.readLine();  //SystoleD

                            TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //HeartRate
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            HeartRate = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArterialSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(HeartRate.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }

                            QFile MoveFile(MRIArterialSpinalMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }

                            QFile SystoleFile(MRIArterialSpinalSystoleFileName);
                            if (SystoleFile.open(QIODevice::WriteOnly)){
                                SystoleFile.write(Systole.toStdString().c_str());
                                SystoleFile.close();
                            }
                        }
                    }

                    QString MRIArterialSpinalQualityFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__quality_arterial.dat";
                    {
                        QFile File(MRIArterialSpinalQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRIVenousSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__venous.dat";
                    Pos = Files.indexOf("MRI_venous_cervical__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find venous spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIVenousSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIVenousSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIVenousSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_venous.dat";
                    QString MRIVenousSpinalMoveFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__move_venous.dat";
                    Pos = Files.indexOf("MRI_venous_cervical__data.dat");
                    if (Pos != -1){
                        QString Move;
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QString MinCorr, MaxCorr, MeanCorr, AmplitudeCorr, StrokeVolumeCorr;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            Pos = Files.indexOf("MRI_venous_cervical__corrected__data.dat");
                            if (Pos != -1){
                                QFile CorrFile(Directory + "/" + Patient + "/" + Files.at(Pos));
                                if (CorrFile.open(QIODevice::ReadOnly)){
                                    QString TMP = CorrFile.readLine();  //Correction
                                    TMP = CorrFile.readLine();  //Move
                                    TMP = CorrFile.readLine();  //Min
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MinCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Max
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MaxCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Mean
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MeanCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Gradient
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    AmplitudeCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //SV
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    StrokeVolumeCorr = TMPList.at(1);

                                    CorrFile.close();
                                }
                            }

                            QFile ResultsFile(MRIVenousSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");

                                if (Pos != -1){
                                    ResultsFile.write(MinCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MaxCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MeanCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(AmplitudeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(StrokeVolumeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                }

                                ResultsFile.close();
                            }

                            QFile MoveFile(MRIVenousSpinalMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }
                        }
                    }

                    QString MRIVenousSpinalQualityFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__quality_venous.dat";
                    {
                        QFile File(MRIVenousSpinalQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRICSFSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__csf.dat";
                    Pos = Files.indexOf("MRI_csf_cervical__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find CSF spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRICSFSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRICSFSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRICSFSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_csf.dat";
                    QString MRICSFSpinalMoveFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__move_csf.dat";
                    Pos = Files.indexOf("MRI_csf_cervical__data.dat");
                    if (Pos != -1){
                        QString Move;
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QString MinCorr, MaxCorr, MeanCorr, AmplitudeCorr, StrokeVolumeCorr;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            Pos = Files.indexOf("MRI_csf_cervical__corrected__data.dat");
                            if (Pos != -1){
                                QFile CorrFile(Directory + "/" + Patient + "/" + Files.at(Pos));
                                if (CorrFile.open(QIODevice::ReadOnly)){
                                    QString TMP = CorrFile.readLine();  //Correction
                                    TMP = CorrFile.readLine();  //Move
                                    TMP = CorrFile.readLine();  //Min
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MinCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Max
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MaxCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Mean
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MeanCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Gradient
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    AmplitudeCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //SV
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    StrokeVolumeCorr = TMPList.at(1);

                                    CorrFile.close();
                                }
                            }

                            QFile ResultsFile(MRICSFSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");

                                if (Pos != -1){
                                    ResultsFile.write(MinCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MaxCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MeanCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(AmplitudeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(StrokeVolumeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                }

                                ResultsFile.close();
                            }

                            QFile MoveFile(MRICSFSpinalMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }
                        }
                    }

                    QString MRICSFSpinalQualityFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__quality_csf.dat";
                    {
                        QFile File(MRICSFSpinalQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRIArteriovenousFlowSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__av_flow.dat";
                    Pos = Files.indexOf("MRI_AV_flow_cervical.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenous flow spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousFlowSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousFlowSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousFlowSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_av_flow.dat";
                    Pos = Files.indexOf("MRI_AV_flow_cervical__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousFlowSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousVolumeSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__av_volume.dat";
                    Pos = Files.indexOf("MRI_AV_volume_cervical.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenous volume spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousVolumeSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousVolumeSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousVolumeSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_av_volume.dat";
                    Pos = Files.indexOf("MRI_AV_volume_cervical__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousVolumeSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousCSFFlowSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__avcsf_flow.dat";
                    Pos = Files.indexOf("MRI_ICVC_flow_cervical.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenousCSF flow spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousCSFFlowSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousCSFFlowSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousCSFFlowSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_avcsf_flow.dat";
                    Pos = Files.indexOf("MRI_ICVC_flow_cervical__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousCSFFlowSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousCSFVolumeSpinalFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__avcsf_volume.dat";
                    Pos = Files.indexOf("MRI_ICVC_volume_cervical.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenousCSF volume spinal file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousCSFVolumeSpinalFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousCSFVolumeSpinalFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousCSFVolumeSpinalResultsFileName = ResultsDirName + "/" + Patient + "/MRI/spinal/MRI__results_avcsf_volume.dat";
                    Pos = Files.indexOf("MRI_ICVC_volume_cervical__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousCSFVolumeSpinalResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }
                }

                {   //intracranial
                    Res = ResultsDir.mkdir(Patient + "/MRI/intracranial");
                    if (!Res){
                        std::cerr << "Mkdir failed " << Patient.toStdString() << "/MRI/intracranial" << std::endl;
                    }

                    QString MRIArterialIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__arterial.dat";
                    Pos = Files.indexOf("MRI_arterial_cerebral__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arterial intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArterialIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArterialIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArterialIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_arterial.dat";
                    QString MRIArterialIntracranialMoveFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__move_arterial.dat";
                    QString MRIArterialIntracranialSystoleFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__systole_threshold.dat";
                    Pos = Files.indexOf("MRI_arterial_cerebral__data.dat");
                    if (Pos != -1){
                        QString Systole;
                        QString Move;
                        QString HeartRate, Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //SystoleT
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Systole = TMPList.at(1);

                            TMP = File.readLine();  //SystoleD

                            TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //HeartRate
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            HeartRate = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArterialIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(HeartRate.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }

                            QFile MoveFile(MRIArterialIntracranialMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }

                            QFile SystoleFile(MRIArterialIntracranialSystoleFileName);
                            if (SystoleFile.open(QIODevice::WriteOnly)){
                                SystoleFile.write(Systole.toStdString().c_str());
                                SystoleFile.close();
                            }
                        }
                    }

                    QString MRIArterialIntracranialQualityFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__quality_arterial.dat";
                    {
                        QFile File(MRIArterialIntracranialQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRIVenousIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__venous.dat";
                    Pos = Files.indexOf("MRI_venous_cerebral__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find venous intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIVenousIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIVenousIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIVenousIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_venous.dat";
                    QString MRIVenousIntracranialMoveFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__move_venous.dat";
                    Pos = Files.indexOf("MRI_venous_cerebral__data.dat");
                    if (Pos != -1){
                        QString Move;
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QString MinCorr, MaxCorr, MeanCorr, AmplitudeCorr, StrokeVolumeCorr;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            Pos = Files.indexOf("MRI_venous_cerebral__corrected__data.dat");
                            if (Pos != -1){
                                QFile CorrFile(Directory + "/" + Patient + "/" + Files.at(Pos));
                                if (CorrFile.open(QIODevice::ReadOnly)){
                                    QString TMP = CorrFile.readLine();  //Correction
                                    TMP = CorrFile.readLine();  //Move
                                    TMP = CorrFile.readLine();  //Min
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MinCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Max
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MaxCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Mean
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MeanCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Gradient
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    AmplitudeCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //SV
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    StrokeVolumeCorr = TMPList.at(1);

                                    CorrFile.close();
                                }
                            }

                            QFile ResultsFile(MRIVenousIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");

                                if (Pos != -1){
                                    ResultsFile.write(MinCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MaxCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MeanCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(AmplitudeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(StrokeVolumeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                }

                                ResultsFile.close();
                            }

                            QFile MoveFile(MRIVenousIntracranialMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }
                        }
                    }

                    QString MRIVenousIntracranialQualityFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__quality_venous.dat";
                    {
                        QFile File(MRIVenousIntracranialQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRICSFIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__csf.dat";
                    Pos = Files.indexOf("MRI_csf_cerebral__processed.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find CSF intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRICSFIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRICSFIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRICSFIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_csf.dat";
                    QString MRICSFIntracranialMoveFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__move_csf.dat";
                    Pos = Files.indexOf("MRI_csf_cerebral__data.dat");
                    if (Pos != -1){
                        QString Move;
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QString MinCorr, MaxCorr, MeanCorr, AmplitudeCorr, StrokeVolumeCorr;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Move
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Move = TMPList.at(1);

                            TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            Pos = Files.indexOf("MRI_csf_cerebral__corrected__data.dat");
                            if (Pos != -1){
                                QFile CorrFile(Directory + "/" + Patient + "/" + Files.at(Pos));
                                if (CorrFile.open(QIODevice::ReadOnly)){
                                    QString TMP = CorrFile.readLine();  //Correction
                                    TMP = CorrFile.readLine();  //Move
                                    TMP = CorrFile.readLine();  //Min
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MinCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Max
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MaxCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Mean
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    MeanCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //Gradient
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    AmplitudeCorr = TMPList.at(1);

                                    TMP = CorrFile.readLine();  //SV
                                    TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                                    TMPList = TMP.split("\t");
                                    StrokeVolumeCorr = TMPList.at(1);

                                    CorrFile.close();
                                }
                            }

                            QFile ResultsFile(MRICSFIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");

                                if (Pos != -1){
                                    ResultsFile.write(MinCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MaxCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(MeanCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(AmplitudeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                    ResultsFile.write(StrokeVolumeCorr.toStdString().c_str()); ResultsFile.write("\n");
                                }

                                ResultsFile.close();
                            }

                            QFile MoveFile(MRICSFIntracranialMoveFileName);
                            if (MoveFile.open(QIODevice::WriteOnly)){
                                MoveFile.write(Move.toStdString().c_str());
                                MoveFile.write("\n");
                                MoveFile.close();
                            }
                        }
                    }

                    QString MRICSFIntracranialQualityFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__quality_csf.dat";
                    {
                        QFile File(MRICSFIntracranialQualityFileName);
                        if (File.open(QIODevice::WriteOnly)){
                            File.write("0\n");  //Quality to 0 to indicate that is imported data
                            File.close();
                        }
                    }

                    QString MRIArteriovenousFlowIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__av_flow.dat";
                    Pos = Files.indexOf("MRI_AV_flow_cerebral.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenous flow intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousFlowIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousFlowIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousFlowIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_av_flow.dat";
                    Pos = Files.indexOf("MRI_AV_flow_cerebral__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousFlowIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousVolumeIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__av_volume.dat";
                    Pos = Files.indexOf("MRI_AV_volume_cerebral.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenous volume intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousVolumeIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousVolumeIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousVolumeIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_av_volume.dat";
                    Pos = Files.indexOf("MRI_AV_volume_cerebral__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousVolumeIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousCSFFlowIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__avcsf_flow.dat";
                    Pos = Files.indexOf("MRI_ICVC_flow_cerebral.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenousCSF flow intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousCSFFlowIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousCSFFlowIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousCSFFlowIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_avcsf_flow.dat";
                    Pos = Files.indexOf("MRI_ICVC_flow_cerebral__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousCSFFlowIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }

                    QString MRIArteriovenousCSFVolumeIntracranialFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__avcsf_volume.dat";
                    Pos = Files.indexOf("MRI_ICVC_volume_cerebral.dat");
                    if (Pos == -1){
                        std::cerr << "Unable to find arteriovenousCSF volume intracranial file" << std::endl;
                    }

                    if (Pos != -1){
                        Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), MRIArteriovenousCSFVolumeIntracranialFileName);
                        if (!Res){
                            std::cerr << "Copy failed " << MRIArteriovenousCSFVolumeIntracranialFileName.toStdString() << std::endl;
                        }
                    }

                    QString MRIArteriovenousCSFVolumeIntracranialResultsFileName = ResultsDirName + "/" + Patient + "/MRI/intracranial/MRI__results_avcsf_volume.dat";
                    Pos = Files.indexOf("MRI_ICVC_volume_cerebral__data.dat");
                    if (Pos != -1){
                        QString Min, Max, Mean, Amplitude, StrokeVolume;
                        QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                        if (File.open(QIODevice::ReadOnly)){
                            QString TMP = File.readLine();  //Min
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            QStringList TMPList = TMP.split("\t");
                            Min = TMPList.at(1);

                            TMP = File.readLine();  //Max
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Max = TMPList.at(1);

                            TMP = File.readLine();  //Mean
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Mean = TMPList.at(1);

                            TMP = File.readLine();  //Gradient
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            Amplitude = TMPList.at(1);

                            TMP = File.readLine();  //SV
                            TMP = TMP.remove("\n"); TMP = TMP.remove("\r");
                            TMPList = TMP.split("\t");
                            StrokeVolume = TMPList.at(1);

                            File.close();

                            QFile ResultsFile(MRIArteriovenousCSFVolumeIntracranialResultsFileName);
                            if (ResultsFile.open(QIODevice::WriteOnly)){
                                ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Mean.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.write(StrokeVolume.toStdString().c_str()); ResultsFile.write("\n");
                                ResultsFile.close();
                            }
                        }
                    }
                }
            }

            {   //ICP
                Res = ResultsDir.mkdir(Patient + "/ICP");
                if (!Res){
                    std::cerr << "Mkdir failed " << Patient.toStdString() << "/ICP" << std::endl;
                }

                QString ICPSignalFileName = ResultsDirName + "/" + Patient + "/ICP/ICP__signal.dat";
                Pos = Files.indexOf("ICP_signal.dat");
                if (Pos == -1){
                    std::cerr << "Unable to find ICP signal file" << std::endl;
                }

                if (Pos != -1){
                    Res = QFile::copy(Directory + "/" + Patient + "/" + Files.at(Pos), ICPSignalFileName);
                    if (!Res){
                        std::cerr << "Copy failed " << ICPSignalFileName.toStdString() << std::endl;
                    }
                }

                QString ICPResultsFileName = ResultsDirName + "/" + Patient + "/ICP_ICP__results_basal.dat";
                Pos = Files.indexOf("ICP__data.dat");
                if (Pos == -1){
                    std::cerr << "Unable to find ICP results file" << std::endl;
                }

                if (Pos != -1){
                    QString HeartRate, Min, Max, Mean, Amplitude;

                    QFile File(Directory + "/" + Patient + "/" + Files.at(Pos));
                    if (File.open(QIODevice::ReadOnly)){
                        QString TMP = File.readLine();  //HeartRate
                        TMP = TMP.remove("\n"); TMP.remove("\r");
                        QStringList TMPList = TMP.split("\t");
                        HeartRate = TMPList.at(1);

                        TMP = File.readLine();  //Min
                        TMP = TMP.remove("\n"); TMP.remove("\r");
                        TMPList = TMP.split("\t");
                        Min = TMPList.at(1);

                        TMP = File.readLine();  //Max
                        TMP = TMP.remove("\n"); TMP.remove("\r");
                        TMPList = TMP.split("\t");
                        Max = TMPList.at(1);

                        TMP = File.readLine();  //Mean
                        TMP = TMP.remove("\n"); TMP.remove("\r");
                        TMPList = TMP.split("\t");
                        Mean = TMPList.at(1);

                        TMP = File.readLine();  //Amplitude
                        TMP = TMP.remove("\n"); TMP.remove("\r");
                        TMPList = TMP.split("\t");
                        Amplitude = TMPList.at(1);

                        File.close();

                        QFile ResultsFile(ICPResultsFileName);
                        if (ResultsFile.open(QIODevice::WriteOnly)){
                            QString CardiacCycle;

                            bool Res;
                            double DoubleCardiacCycle = HeartRate.toDouble(&Res);
                            if (Res) DoubleCardiacCycle = 60. / DoubleCardiacCycle;
                            CardiacCycle = QString::number(DoubleCardiacCycle);

                            ResultsFile.write(CardiacCycle.toStdString().c_str()); ResultsFile.write("\n");
                            ResultsFile.write(HeartRate.toStdString().c_str()); ResultsFile.write("\n");
                            ResultsFile.write(Min.toStdString().c_str()); ResultsFile.write("\n");
                            ResultsFile.write(Max.toStdString().c_str()); ResultsFile.write("\n");
                            ResultsFile.write(Amplitude.toStdString().c_str()); ResultsFile.write("\n");

                            ResultsFile.close();
                        }
                    }
                }
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Empty results directory: " + Patient);
        }

        return true;
    }
    else{
        QMessageBox::warning(this, "Error", "Results directory does not exists: " + Patient);
    }

    return false;
}


