#include "headers.hpp"

/*!
 * \brief load_data_proliphyc
 * \param file_name
 * \param coord
 * \return
 */
bool load_data_proliphyc(QString file_name, Coord *coord)
{
    //Open file
    bool res;
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        //Read number of points
        QString tmp = file.readLine();
        tmp.remove(0, 1);
        int n = tmp.toInt(&res);
        if (res){
            coord->set_size(n);
            double x0 = 0.;
            for (int i = 0; i < n; i++){
                tmp = file.readLine();
                QStringList list = tmp.split("\t");
                if (i == 0){                            //Special for PROLIPHYC
                    x0 = list.takeFirst().toDouble();
                    coord->set_coord(0., i, XCOORD);
                    coord->set_coord(list.takeFirst().toDouble(), i, YCOORD);
                }
                else{
                    coord->set_coord((list.takeFirst().toDouble()-x0)*1.e5, i, XCOORD);
                    coord->set_coord(list.takeFirst().toDouble(), i, YCOORD);
                }
            }
            //Close file and end
            file.close();
            return true;
        }
        else{
            file.close();
            return false;
        }
    }
    return false;
}

/*!
 * \brief load_data
 * \param file_name
 * \param coord
 * \return
 */
bool load_data(QString file_name, Coord *coord)
{
    bool res;
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        //Read number of points
        QString tmp = file.readLine();
        tmp.remove(0, 1);
        int n = tmp.toInt(&res);
        if (res){
            coord->set_size(n);
            for (int i = 0; i < n; i++){
                tmp = file.readLine();
                QStringList list = tmp.split("\t");
                coord->set_coord(list.takeFirst().toDouble(&res), i, XCOORD);
                if (!res) return res;
                coord->set_coord(list.takeFirst().toDouble(&res), i, YCOORD);
                if (!res) return res;
            }
            //Close file and end
            file.close();
            return true;
        }
        else{
            file.close();
            return false;
        }
    }
    return false;
}

/*!
 * \brief save_data
 * \param file_name
 * \param coord
 * \param coord_SD
 * \return
 */
bool save_data(QString file_name, Coord *coord, Coord *coord_SD)
{
    int n = coord->size();
    if (n > 0){
        //Open file
        QFile file(file_name);
        if (file.open(QIODevice::WriteOnly)){
            //Write number of points
            file.write("#");
            file.write(QString::number(n).toStdString().c_str());
            file.write("\r\n");
            //Write points
            for (int i = 0; i < n; i++){
                file.write(QString::number(coord->coord(i, XCOORD)).toStdString().c_str());
                file.write("\t");
                file.write(QString::number(coord->coord(i, YCOORD)).toStdString().c_str());
                if (coord_SD != NULL){
                    file.write("\t");
                    file.write(QString::number(coord_SD->coord(i, YCOORD)).toStdString().c_str());
                }
                file.write("\r\n");
            }
            //Close and end
            file.close();
            return true;
        }
    }
    return false;
}

/*!
 * \brief save_sup_data
 * \param file_name
 * \param string_list1
 * \param string_list2
 * \param n
 * \return
 */
bool save_sup_data(QString file_name, string *string_list1, string *string_list2, int n)
{
    //Open file
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly)){
        for (int i = 0; i < n; i++){
            file.write(string_list1[i].c_str());
            file.write("\t");
            file.write(string_list2[i].c_str());
            file.write("\r\n");
        }
        file.close();
        return true;
    }
    return false;
}

/*!
 * \brief load_sup_data
 * \param file_name
 * \param string_list1
 * \param string_list2
 * \param n
 * \return
 */
bool load_sup_data(QString file_name, string *string_list1, string *string_list2, int n)
{
    //Read file
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        for (int i = 0; i < n; i++){
            QString tmp = file.readLine();
            if (tmp.isEmpty()) return false;
            QStringList list = tmp.split("\t");
            string_list1[i] = list.takeFirst().remove("\n").remove("\r").toStdString();
            string_list2[i] = list.takeFirst().remove("\n").remove("\r").toStdString();
        }
        file.close();
        return true;
    }
    return false;
}

/*!
 * \brief save_csv
 * \param file_name
 * \param title1
 * \param title2
 * \param x
 * \param y
 * \param z
 * \return
 */
bool save_csv(QString file_name, QString title1, QString title2, QVector<string> name, QVector<double> x, QVector<double> y, QVector<double> reg, QVector<double> clust)
{
    QString separator = "; ";
    QString end = "\n";

    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly)){
        file.write("Name");
        file.write(separator.toStdString().c_str());
        file.write(title1.toStdString().c_str());
        file.write(separator.toStdString().c_str());
        file.write(title2.toStdString().c_str());
        file.write(separator.toStdString().c_str());
        if (reg.size() > 0){
            file.write("Regression");
        }
        file.write(separator.toStdString().c_str());
        if(clust.size() > 0){
            file.write("Clustering");
        }
        file.write(end.toStdString().c_str());
        for (int i = 0; i < x.size(); i++){
            file.write(name.at(i).c_str());
            file.write(separator.toStdString().c_str());
            QString coord_x = QString::number(x.at(i));
            coord_x.replace(".", ",");
            file.write(coord_x.toStdString().c_str());
            file.write(separator.toStdString().c_str());
            QString coord_y = QString::number(y.at(i));
            coord_y.replace(".", ",");
            file.write(coord_y.toStdString().c_str());
            file.write(separator.toStdString().c_str());
            if (reg.size() >= i && reg.size() > 0){
                QString coord_reg = QString::number(reg.at(i));
                coord_reg.replace(".", ",");
                file.write(coord_reg.toStdString().c_str());
            }
            file.write(separator.toStdString().c_str());
            if (clust.size() >= i && clust.size() > 0){
                QString coord_clust = QString::number(clust.at(i));
                file.write(coord_clust.toStdString().c_str());
            }
            file.write(end.toStdString().c_str());
        }
        file.close();
        return true;
    }
    return false;
}


bool save_rtf(QString file_name, QStringList patient_informations, QStringList data)
{
    QStringList img;
    QFile img_file("img/logo-CHU.hex");
    if (img_file.open(QIODevice::ReadOnly)){
        while(!img_file.atEnd()){
            img.append(img_file.readLine());
        }
    }
    QFile file(file_name);
    if (file.open(QIODevice::WriteOnly)){

        file.write("{\\rtf1\\ansi\\deff0\n");

        file.write("{\\fonttbl\n");
        file.write("    {\\f0\\fnil\\fcharset0\\fprq0\\fttruetype Helvetica;}\n");
        file.write("}\n");
        file.write("{\n");
        file.write("\\trowd\n");
        file.write("\\cellx5000\n");
        file.write("\\cellx8600\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs30 {\\qc {\\b Unit\\'e9 fonctionnelle de traitement de l'image en imagerie m\\'e9dicale}}}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs26 \\qc {Centre Hospitalier Universitaire CHU Sud - B\\'e2timent TEP - 80054 AMIENS Cedex}}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs24 \\qc {{\\b Olivier Bal\\'e9dent MCU-PH}}}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs24 T\\'e9l\\'e9phone : 03 22 45 60 24 -- 06 67 98 20 41}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs24 E-mail : olivier.baledent@chu-amiens.fr}\n");
        file.write("\\cell\n");
        file.write("\\intbl\n");
        file.write("{\\fo\\fs24 ");
        file.write("{\\pict\\pngblib\\picwgoal3000\\pichgoal2000 ");
        for (int i = 0; i < img.size(); i++){
            file.write(img.at(i).toStdString().c_str());
            file.write("\n");
        }
        file.write("}");
        file.write("}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs24 IRM de flux du ");
        if (patient_informations.size() > 1){
            if (!patient_informations.at(1).isEmpty()){
                file.write(patient_informations.at(1).toStdString().c_str());
            }
            else{
                file.write("NR");
            }
        }
        file.write(" de Monsieur ");
        if (patient_informations.size() > 0){
            if (!patient_informations.at(0).isEmpty()){
                file.write(patient_informations.at(0).toStdString().c_str());
            }
            else{
                file.write("NR");
            }
        }
        file.write(", n\\'e9 le ");
        if (patient_informations.size() > 2){
            if (!patient_informations.at(2).isEmpty()){
                file.write(patient_informations.at(2).toStdString().c_str());
            }
            else{
                file.write("NR");
            }
        }
        file.write(" (");
        if (patient_informations.size() > 3){
            if (!patient_informations.at(3).isEmpty()){
                file.write(patient_informations.at(3).toStdString().c_str());
            }
            else{
                file.write("NR");
            }
        }
        file.write(" ans)}\n");
        file.write("\\par\n");
        file.write("{\n");
        file.write("\\trowd\n");
        file.write("\\cellx2000\n");
        file.write("\\cellx4000\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs24 Indication clinique}\n");
        file.write("\\cell\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs24 NR}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("}\n");
        file.write("\\par\n");
        file.write("{\\f0\\fs24 {\\ul Tableau r\\'e9capitulatif des r\\'e9sultats}}\n");
        file.write("\\par\n");
        file.write("{\n");
        file.write("\\trowd\n");
        file.write("\\cellx2000\n");
        file.write("\\cellx4000\n");
        file.write("\\cellx6000\n");
        file.write("\\cellx8000\n");
        file.write("\\intbl\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 {\\b PATIENT}}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 {\\b TEMOINS \\'e2g\\'e9s}}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs24 Volume oscillatoire du LCS}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Mesur\\'e9 (\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Moyenne(\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 \\'c9cart-type(\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 Aqueduc}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(0).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 34}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 16}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 V3 stomie}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24");
        file.write(data.at(1).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 V4}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(2).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 28}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 18}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 C2-C3}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(3).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 457}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 147}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 Citerne pr\\'e9pontique}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24");
        file.write(data.at(4).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 239}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 187}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("}\n");
        file.write("\\par\n");
        file.write("{\n");
        file.write("\\trowd\n");
        file.write("\\cellx2000\n");
        file.write("\\cellx4000\n");
        file.write("\\cellx6000\n");
        file.write("\\cellx8000\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs24 D\\'e9bit sang}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Mesur\\'e9 (mL/min)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Moyenne (mL/min)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 \\'c9cart-type (mL/min)}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 C\\'e9r\\'e9bral}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(5).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 498}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 57}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 Cervical}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(6).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("}\n");
        file.write("\\par\n");
        file.write("{\n");
        file.write("\\trowd\n");
        file.write("\\cellx2000\n");
        file.write("\\cellx4000\n");
        file.write("\\cellx6000\n");
        file.write("\\cellx8000\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs24 Volume oscillatoire}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Mesur\\'e9 (\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 Moyenne (\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs20 \\'c9cart-type (\\'b5L)}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 AV c\\'e9r\\'e9bral}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(7).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 AV cervical}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(8).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 ICVC c\\'e9r\\'e9bral}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(9).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("\\intbl\n");
        file.write("{\\f0\\fs20 ICVC cervical}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ");
        file.write(data.at(10).toStdString().c_str());
        file.write("}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("{\\f0\\fs24 ?}\n");
        file.write("\\cell\n");
        file.write("\\row\n");
        file.write("}\n");
        file.write("}\n");

        file.close();

        return true;
    }
    return false;
}


//****************//
//***PARAMETERS***//
//****************//
/*GET*/

bool get_directories(QStringList *directories)
{
    directories->clear();

    QFile file(QString::fromStdString(SYSTEM_DIR) + "directories.dat");
    if (file.open(QIODevice::ReadOnly)){
        for (int i = 0; i < 3; i++){
            QString tmp = file.readLine();
            if (tmp.isEmpty()) return false;
            tmp.remove("\n").remove("\r");
            directories->append(tmp);
        }
        file.close();
        return true;
    }
    return false;
}

QString get_Flow_directory(){
    QStringList *directories = new QStringList;
    bool res = get_directories(directories);
    if (res){
        return directories->at(0);
    }
    else{
        return EMPTY_STRING;
    }
}

QString get_Data_directory(){
    QStringList *directories = new QStringList;
    bool res = get_directories(directories);
    if (res){
        return directories->at(1);
    }
    else{
        return EMPTY_STRING;
    }
}

QString get_Results_directory(){
    QStringList *directories = new QStringList;
    bool res = get_directories(directories);
    if (res){
        return directories->at(2);
    }
    else{
        return EMPTY_STRING;
    }
}

/*!
 * \brief get_unities
 * \param unities
 * \return
 */
bool get_unities(string *unities)
{
    //Read file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "unities.dat");
    if (file.open(QIODevice::ReadOnly)){
        for (int i = 0; i < UNITY_LENGTH; i++){
            QString tmp = file.readLine();
            if (tmp.isEmpty()) return false;
            unities[i] = (tmp.remove("\n").remove("\r")).toStdString();
        }
        file.close();
        return true;
    }
    return false;
}

//Number of interpolation points
//For MRI and mean ICP curves
/*!
 * \brief get_npi
 * \param npi
 * \return
 */
bool get_npi(int *npi)
{
    bool res;
    //Read file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "npi.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp = file.readLine();
        if (tmp.isEmpty()) return false;
        (*npi) = (tmp.remove("\n").remove("\r")).toInt(&res);
        return res;
    }
    return false;
}

//Fourier and IFFT coefficients
/*!
 * \brief get_coeffs
 * \param coeffs
 * \return
 */
bool get_coeffs(double *coeffs)
{
    bool res;
    //Read file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "coeffs.dat");
    if (file.open(QIODevice::ReadOnly)){
        for (int i = 0; i < COEFFS_LENGTH; i++){
            QString tmp = file.readLine();
            if (tmp.isEmpty()) return false;
            coeffs[i] = (tmp.remove("\n").remove("\r")).toDouble(&res);
            if (!res) return res;
        }
        file.close();
        return true;
    }
    return false;
}

/*SET*/
bool set_directories(QStringList *directories)
{
    //
    QFile file(QString::fromStdString(SYSTEM_DIR) + "directories.dat");
    if (file.open(QIODevice::WriteOnly)){
        for (int i = 0; i < 3; i++){
            file.write(directories->at(i).toStdString().c_str());
            if (i < 2){
                file.write("\r\n");
            }
        }
        file.close();
        return true;
    }
    return false;
}

/*!
 * \brief set_unities
 * \param unities
 * \return
 */
bool set_unities(string *unities)
{
    //Write file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "unities.dat");
    if (file.open(QIODevice::WriteOnly)){
        for (int i = 0; i < UNITY_LENGTH; i++){
            file.write(unities[i].c_str());
            if (i < UNITY_LENGTH){
                file.write("\r\n");
            }
        }
        file.close();
        return true;
    }
    return false;
}

/*!
 * \brief set_npi
 * \param npi
 * \return
 */
bool set_npi(int npi)
{
    //Write file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "npi.dat");
    if (file.open(QIODevice::WriteOnly)){
        file.write(QString::number(npi).toStdString().c_str());
        file.close();
        return true;
    }
    return false;
}

/*!
 * \brief set_coeffs
 * \param coeffs
 * \return
 */
bool set_coeffs(double *coeffs)
{
    //Write file
    QFile file(QString::fromStdString(SYSTEM_DIR) + "coeffs.dat");
    if (file.open(QIODevice::WriteOnly)){
        for (int i = 0; i < COEFFS_LENGTH; i++){
            file.write(QString::number(coeffs[i]).toStdString().c_str());
            if (i < COEFFS_LENGTH-1){
                file.write("\r\n");
            }
        }
        file.close();
        return true;
    }
    return false;
}


/*********************/
/*PATIENTS FILE NAMES*/
/*********************/
/*GLOBAL*/
/*!
 * \brief get_file_source_data
 * \param patient_dir
 * \param l
 * \param res
 * \return
 */
QString get_file_source_data(QString patient_dir, int l, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + FILE_NAMES_FILE);
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;

        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }

        file.close();

        if (l == 1){
            tmp.remove(FILE_NAME_ITEM01);
        }
        else if (l == 2){
            tmp.remove(FILE_NAME_ITEM02);
        }
        else if (l == 3){
            tmp.remove(FILE_NAME_ITEM03);
        }
        else if (l == 4){
            tmp.remove(FILE_NAME_ITEM04);
        }
        else if (l == 5){
            tmp.remove(FILE_NAME_ITEM05);
        }
        else if (l == 6){
            tmp.remove(FILE_NAME_ITEM06);
        }
        else if (l == 7){
            tmp.remove(FILE_NAME_ITEM07);
        }
        else if (l == 8){
            tmp.remove(FILE_NAME_ITEM08);
        }
        else if (l == 9){
            tmp.remove(FILE_NAME_ITEM09);
        }
        else if (l == 10){
            tmp.remove(FILE_NAME_ITEM10);
        }
        else if (l == 11){
            tmp.remove(FILE_NAME_ITEM11);
        }
        else if (l == 12){
            tmp.remove(FILE_NAME_ITEM12);
        }
        else if (l == 13){
            tmp.remove(FILE_NAME_ITEM13);
        }
        else if (l == 14){
            tmp.remove(FILE_NAME_ITEM14);
        }
        else if (l == 15){
            tmp.remove(FILE_NAME_ITEM15);
        }
        tmp.remove("\t");

        if (res != NULL) *res = true;
        return tmp;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

/*!
 * \brief set_file_source_data
 * \param patient_dir
 * \param l
 * \param txt
 * \param res
 */
void set_file_source_data(QString patient_dir, int l, QString txt, bool *res)
{
    l = l - 1;

    QStringList list;

    QFile file(get_Results_directory() + patient_dir + DIR_SEPARATOR + FILE_NAMES_FILE);
    if (file.open(QIODevice::ReadWrite)){
        for (int i = 0; i < FILE_NAMES_LENGTH; i++){
            list.append(file.readLine());
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < FILE_NAMES_LENGTH; i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

/*GET*/
/*!
 * \brief get_MRI_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 1, res);
}

/*!
 * \brief get_MRI_arterial_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_arterial_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 2, res);
}

/*!
 * \brief get_MRI_venous_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_venous_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 3, res);
}

/*!
 * \brief get_MRI_csf_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_csf_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 4, res);
}

/*!
 * \brief get_MRI_arterial_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_arterial_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 5, res);
}

/*!
 * \brief get_MRI_venous_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_venous_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 6, res);
}

/*!
 * \brief get_MRI_csf_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_MRI_csf_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 7, res);
}

/*!
 * \brief get_ICP_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_ICP_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 8, res);
}

/*!
 * \brief get_EPI_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 9, res);
}

/*!
 * \brief get_EPI_arterial_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_arterial_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 10, res);
}

/*!
 * \brief get_EPI_venous_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_venous_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 11, res);
}

/*!
 * \brief get_EPI_csf_cervical_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_csf_cervical_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 12, res);
}

/*!
 * \brief get_EPI_arterial_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_arterial_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 13, res);
}

/*!
 * \brief get_EPI_venous_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_venous_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 14, res);
}

/*!
 * \brief get_EPI_csf_cerebral_source
 * \param patient_dir
 * \param res
 * \return
 */
QString get_EPI_csf_cerebral_source(QString patient_dir, bool *res)
{
    return get_file_source_data(patient_dir, 15, res);
}

/*SET*/
/*!
 * \brief set_MRI_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM01) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 1, txt, res);
}

/*!
 * \brief set_MRI_arterial_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_arterial_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM02) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 2, txt, res);
}

/*!
 * \brief set_MRI_venous_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_venous_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM03) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 3, txt, res);
}

/*!
 * \brief set_MRI_csf_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_csf_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM04) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 4, txt, res);
}

/*!
 * \brief set_MRI_arterial_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_arterial_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM05) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 5, txt, res);
}

/*!
 * \brief set_MRI_venous_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_venous_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM06) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 6, txt, res);
}

/*!
 * \brief set_MRI_csf_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_MRI_csf_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM07) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 7, txt, res);
}

/*!
 * \brief set_ICP_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_ICP_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM08) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 8, txt, res);
}

/*!
 * \brief set_EPI_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM09) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 9, txt, res);
}

/*!
 * \brief set_EPI_arterial_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_arterial_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM10) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 10, txt, res);
}

/*!
 * \brief set_EPI_venous_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_venous_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM11) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 11, txt, res);
}

/*!
 * \brief set_EPI_csf_cervical_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_csf_cervical_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM12) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 12, txt, res);
}

/*!
 * \brief set_EPI_arterial_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_arterial_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM13) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 13, txt, res);
}

/*!
 * \brief set_EPI_venous_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_venous_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM14) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 14, txt, res);
}

/*!
 * \brief set_EPI_csf_cerebral_source
 * \param patient_dir
 * \param txt
 * \param res
 */
void set_EPI_csf_cerebral_source(QString patient_dir, QString txt, bool *res)
{
    txt = QString::fromStdString(FILE_NAME_ITEM15) + "\t" + txt + "\n";
    set_file_source_data(patient_dir, 15, txt, res);
}


/******************/
/*PATIENTS QUALITY*/
/******************/
/*GLOBAL*/
QString get_MRI_quality_source_data(QString patient_dir, int l, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + MRI_QUALITY_FILE_CC);
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;

        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }

        file.close();

        if (l == 1){
            tmp.remove(MRI_QUALITY_ITEM01);
        }
        else if (l == 2){
            tmp.remove(MRI_QUALITY_ITEM02);
        }
        else if (l == 3){
            tmp.remove(MRI_QUALITY_ITEM03);
        }
        else if (l == 4){
            tmp.remove(MRI_QUALITY_ITEM04);
        }
        else if (l == 5){
            tmp.remove(MRI_QUALITY_ITEM05);
        }
        else if (l == 6){
            tmp.remove(MRI_QUALITY_ITEM06);
        }
        else if (l == 7){
            tmp.remove(MRI_QUALITY_ITEM07);
        }
        else if (l == 8){
            tmp.remove(MRI_QUALITY_ITEM08);
        }
        tmp.remove("\t");

        if (res != NULL) *res = true;
        return tmp;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_ICP_quality_source(QString patient_dir, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + ICP_QUALITY_FILE);
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        tmp = file.readLine();

        file.close();

        tmp.remove(ICP_QUALITY_ITEM01);

        if (res != NULL) *res = true;
        return tmp;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_EPI_quality_source_data(QString patient_dir, int l, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + EPI_QUALITY_FILE_CC);
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;

        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }

        file.close();

        if (l == 1){
            tmp.remove(EPI_QUALITY_ITEM01);
        }
        else if (l == 2){
            tmp.remove(EPI_QUALITY_ITEM02);
        }
        else if (l == 3){
            tmp.remove(EPI_QUALITY_ITEM03);
        }
        else if (l == 4){
            tmp.remove(EPI_QUALITY_ITEM04);
        }
        else if (l == 5){
            tmp.remove(EPI_QUALITY_ITEM05);
        }
        else if (l == 6){
            tmp.remove(EPI_QUALITY_ITEM06);
        }
        else if (l == 7){
            tmp.remove(EPI_QUALITY_ITEM07);
        }
        else if (l == 8){
            tmp.remove(EPI_QUALITY_ITEM08);
        }
        tmp.remove("\t");

        if (res != NULL) *res = true;
        return tmp;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

void set_MRI_quality_source_data(QString patient_dir, int l, QString txt, bool *res)
{
    l = l - 1;

    QStringList list;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_QUALITY_FILE_CC);
    if (file.open(QIODevice::ReadWrite)){
        for (int i = 0; i < MRI_QUALITY_LENGTH; i++){
            list.append(file.readLine());
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < MRI_QUALITY_LENGTH; i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

void set_ICP_quality_source(QString patient_dir, QString txt, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + ICP_QUALITY_FILE);
    if (file.open(QIODevice::WriteOnly)){
        txt = QString::fromStdString(ICP_QUALITY_ITEM01) + "\t" + txt;

        file.write(txt.toStdString().c_str());
        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

void set_EPI_quality_source_data(QString patient_dir, int l, QString txt, bool *res)
{
    l = l - 1;

    QStringList list;

    QFile file(patient_dir + DIR_SEPARATOR + EPI_QUALITY_FILE_CC);
    if (file.open(QIODevice::ReadWrite)){
        for (int i = 0; i < EPI_QUALITY_LENGTH; i++){
            list.append(file.readLine());
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < EPI_QUALITY_LENGTH; i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}


/*GET*/
QString get_MRI_arterial_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 2, res);
}

QString get_MRI_venous_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 3, res);
}

QString get_MRI_csf_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 4, res);
}

QString get_MRI_arterial_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 6, res);
}

QString get_MRI_venous_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 7, res);
}

QString get_MRI_csf_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 8, res);
}

QString get_MRI_arterial_others_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 10, res);
}

QString get_MRI_venous_others_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 11, res);
}

QString get_MRI_csf_others_quality_source(QString patient_dir, bool *res)
{
    return get_MRI_quality_source_data(patient_dir, 12, res);
}

QString get_MRI_arterial_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_ARTERIAL_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_MRI_venous_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_VENOUS_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_MRI_csf_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_CSF_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}


QString get_EPI_arterial_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 2, res);
}

QString get_EPI_venous_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 3, res);
}

QString get_EPI_csf_cervical_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 4, res);
}

QString get_EPI_arterial_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 6, res);
}

QString get_EPI_venous_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 7, res);
}

QString get_EPI_csf_cerebral_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 8, res);
}

QString get_EPI_arterial_others_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 10, res);
}

QString get_EPI_venous_others_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 11, res);
}

QString get_EPI_csf_others_quality_source(QString patient_dir, bool *res)
{
    return get_EPI_quality_source_data(patient_dir, 12, res);
}

QString get_EPI_arterial_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + EPI_ARTERIAL_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_EPI_venous_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + EPI_VENOUS_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

QString get_EPI_csf_other_quality_source(QString patient_dir, int l, bool *res)
{
    l++;

    QFile file(patient_dir + DIR_SEPARATOR + EPI_CSF_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        QString tmp;
        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }
        tmp.remove("\n").remove("\r");
        QStringList tmp_list = tmp.split("\t");
        QString tmp2 = tmp_list.takeLast();
        if (res != NULL) *res = true;
        return tmp2;
    }
    else{
        if (res != NULL) *res = false;
        return EMPTY_STRING;
    }
}

/*SET*/
void set_MRI_arterial_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM02) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 2, txt, res);
}

void set_MRI_venous_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM03) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 3, txt, res);
}

void set_MRI_csf_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM04) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 4, txt, res);
}

void set_MRI_arterial_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM06) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 6, txt, res);
}

void set_MRI_venous_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM07) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 7, txt, res);
}

void set_MRI_csf_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(MRI_QUALITY_ITEM08) + "\t" + txt + "\r\n";
    set_MRI_quality_source_data(patient_dir, 8, txt, res);
}

void set_MRI_arterial_other_quality_source(QString patient_dir, int l, QString txt, bool *res)
{
    QStringList list;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_ARTERIAL_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        while(!file.atEnd()){
            QString tmp = file.readLine();
            list.append(tmp);
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < list.size(); i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

void set_MRI_venous_other_quality_source(QString patient_dir, int l, QString txt, bool *res)
{
    QStringList list;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_VENOUS_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        while(!file.atEnd()){
            QString tmp = file.readLine();
            list.append(tmp);
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < list.size(); i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

void set_MRI_csf_other_quality_source(QString patient_dir, int l, QString txt, bool *res)
{
    QStringList list;

    QFile file(patient_dir + DIR_SEPARATOR + MRI_CSF_QUALITY_FILE);
    if (file.open(QIODevice::ReadWrite)){
        while(!file.atEnd()){
            QString tmp = file.readLine();
            list.append(tmp);
        }

        list.replace(l, txt);

        file.seek(0);

        for (int i = 0; i < list.size(); i++){
            file.write(list.at(i).toStdString().c_str());
        }

        file.close();

        if (res != NULL) *res = true;
    }
    else{
        if (res != NULL) *res = false;
    }
}

void set_EPI_arterial_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM02) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 2, txt, res);
}

void set_EPI_venous_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM03) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 3, txt, res);
}

void set_EPI_csf_cervical_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM04) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 4, txt, res);
}

void set_EPI_arterial_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM06) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 6, txt, res);
}

void set_EPI_venous_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM07) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 7, txt, res);
}

void set_EPI_csf_cerebral_quality_source(QString patient_dir, QString txt, bool *res){
    txt = QString::fromStdString(EPI_QUALITY_ITEM08) + "\t" + txt + "\r\n";
    set_EPI_quality_source_data(patient_dir, 8, txt, res);
}

/******************/
/***INFORMATIONS***/
/******************/
QString get_informations_source(QString patient_dir, int l, bool *res)
{
    QFile file(patient_dir + DIR_SEPARATOR + "informations.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;

        for (int i = 0; i < l; i++){
            tmp = file.readLine();
        }

        if (l == 1){
            tmp.remove(INFORMATIONS_DATA_ITEM01);
        }
        else if (l == 2){
            tmp.remove(INFORMATIONS_DATA_ITEM02);
        }
        else if (l == 3){
            tmp.remove(INFORMATIONS_DATA_ITEM03);
        }
        else if (l == 4){
            tmp.remove(INFORMATIONS_DATA_ITEM04);
        }
        else if (l == 5){
            tmp.remove(INFORMATIONS_DATA_ITEM05);
        }

        tmp.remove("\t");
        tmp.remove("\n");
        tmp.remove("\r");

        if (res != NULL) *res = true;
        return tmp;
    }
    if (res != NULL) *res = false;
    return EMPTY_STRING;
}

QString get_exam_number(QString patient_dir, bool *res)
{
    return get_informations_source(patient_dir, 1, res);
}

QString get_exam_date(QString patient_dir, bool *res)
{
    return get_informations_source(patient_dir, 2, res);
}

QString get_patient_date(QString patient_dir, bool *res)
{
    return get_informations_source(patient_dir, 3, res);
}

QString get_patient_age(QString patient_dir, bool *res)
{
    return get_informations_source(patient_dir, 4, res);
}

QString get_patient_sexe(QString patient_dir, bool *res)
{
    return get_informations_source(patient_dir, 5, res);
}


//
QStringList *get_MRI_arterial_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "MRI_arterial_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}

QStringList *get_MRI_venous_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "MRI_venous_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}

QStringList *get_MRI_csf_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "MRI_csf_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}

QStringList *get_EPI_arterial_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "EPI_arterial_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}

QStringList *get_EPI_venous_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "EPI_venous_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}

QStringList *get_EPI_csf_files(QString patient_dir)
{
    QStringList *res = new QStringList;

    QFile file(patient_dir + DIR_SEPARATOR + "EPI_csf_quality.dat");
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        while(!file.atEnd()){
            tmp = file.readLine();
            QStringList tmp2 = tmp.split("\t");
            QString tmp3 = tmp2.at(0);
            tmp3.remove("\n").remove("\r");
            if (!tmp3.isEmpty()){
                res->append(tmp3);
            }
        }
        file.close();
    }
    return res;
}


