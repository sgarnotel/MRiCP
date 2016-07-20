#include "dialognew.h"

void DialogNew::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    //Line
    line_patient = new QLineEdit(this);
    line_MRI = new QLineEdit(this);
    line_ICP = new QLineEdit(this);
    line_EPI = new QLineEdit(this);

    //Label
    label_title = new QLabel(this);
    label_title_img = new QLabel(this);
    label_patient = new QLabel(this);
    label_MRI = new QLabel(this);
    label_ICP = new QLabel(this);
    label_EPI = new QLabel(this);

    //Button
    button_load_MRI = new QPushButton(this);
    button_load_ICP = new QPushButton(this);
    button_load_EPI = new QPushButton(this);

    button_cancel = new QPushButton(this);
    button_valid = new QPushButton(this);

    //Coord
    coords_MRI_arterial = NULL;
    coords_MRI_venous = NULL;
    coords_MRI_csf = NULL;

    coord_MRI_arterial_cervical = new Coord;
    coord_MRI_venous_cervical = new Coord;
    coord_MRI_csf_cervical = new Coord;
    coord_MRI_arterial_cerebral = new Coord;
    coord_MRI_venous_cerebral = new Coord;
    coord_MRI_csf_cerebral = new Coord;

    coord_ICP = new Coord;

    coords_EPI_arterial = NULL;
    coords_EPI_venous = NULL;
    coords_EPI_csf = NULL;

    coord_EPI_arterial_cervical = new Coord;
    coord_EPI_venous_cervical = new Coord;
    coord_EPI_csf_cervical = new Coord;
    coord_EPI_arterial_cerebral = new Coord;
    coord_EPI_venous_cerebral = new Coord;
    coord_EPI_csf_cerebral = new Coord;

    //String
    dir = EMPTY_STRING;

    list_MRI_informations = new QStringList;
    list_MRI_arterial = new QStringList;
    list_MRI_venous = new QStringList;
    list_MRI_csf = new QStringList;

    list_MRI_arterial_cervical = new QStringList;
    list_MRI_venous_cervical = new QStringList;
    list_MRI_csf_cervical = new QStringList;
    list_MRI_arterial_cerebral = new QStringList;
    list_MRI_venous_cerebral = new QStringList;
    list_MRI_csf_cerebral = new QStringList;

    list_EPI_informations = new QStringList;
    list_EPI_arterial = new QStringList;
    list_EPI_venous = new QStringList;
    list_EPI_csf = new QStringList;

    list_EPI_arterial_cervical = new QStringList;
    list_EPI_venous_cervical = new QStringList;
    list_EPI_csf_cervical = new QStringList;
    list_EPI_arterial_cerebral = new QStringList;
    list_EPI_venous_cerebral = new QStringList;
    list_EPI_csf_cerebral = new QStringList;
}

void DialogNew::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Button
    button_load_MRI->setText(DIALOG_NEW_LOAD_MRI);
    button_load_ICP->setText(DIALOG_NEW_LOAD_ICP);
    button_load_EPI->setText(DIALOG_NEW_LOAD_EPI);

    button_cancel->setText(DIALOG_NEW_CANCEL);
    button_valid->setText(DIALOG_NEW_LOAD);

    //Label
    label_title->setText(DIALOG_NEW_NEW);
    label_title_img->setPixmap(QPixmap(IMG_ADD).scaled(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));
    label_patient->setText(DIALOG_NEW_PATIENT);
    label_MRI->setText(DIALOG_NEW_FLOW);
    label_ICP->setText(DIALOG_NEW_PRESSURE);
    label_EPI->setText(DIALOG_NEW_EPI);

    //Grid
    setLayout(grid);

    grid->addWidget(label_title_img, 0, 0, 1, 1);
    grid->addWidget(label_title, 0, 1, 1, 1);

    grid->addWidget(label_patient, 1, 0, 1, 2);
    grid->addWidget(line_patient, 2, 0, 1, 2);

    grid->addWidget(label_MRI, 3, 0, 1, 1);
    grid->addWidget(button_load_MRI, 3, 1, 1, 1);
    grid->addWidget(line_MRI, 4, 0, 1, 2);

    grid->addWidget(label_ICP, 5, 0, 1, 1);
    grid->addWidget(button_load_ICP, 5, 1, 1, 1);
    grid->addWidget(line_ICP, 6, 0, 1, 2);

    grid->addWidget(label_EPI, 7, 0, 1, 1);
    grid->addWidget(button_load_EPI, 7, 1, 1, 1);
    grid->addWidget(line_EPI, 8, 0, 1, 2);

    grid->addWidget(button_cancel, 9, 0, 1, 1);
    grid->addWidget(button_valid, 9, 1, 1, 1);
}

void DialogNew::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_load_MRI, SIGNAL(clicked()), this, SLOT(load_MRI()));
    connect(button_load_ICP, SIGNAL(clicked()), this, SLOT(load_ICP()));
    connect(button_load_EPI, SIGNAL(clicked()), this, SLOT(load_EPI()));

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(button_valid, SIGNAL(clicked()), this, SLOT(valid()));
}

void DialogNew::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_title->setStyleSheet(CSS_LABEL_TITLE);

    label_patient->setStyleSheet(CSS_LABEL_BIG);
    label_MRI->setStyleSheet(CSS_LABEL_BIG);
    label_ICP->setStyleSheet(CSS_LABEL_BIG);
    label_EPI->setStyleSheet(CSS_LABEL_BIG);
}

DialogNew::DialogNew(QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();
}

void DialogNew::load_MRI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    dir = QFileDialog::getExistingDirectory(this, DIALOG_NEW_FLOW_DIALOG, get_Flow_directory());

    if (!dir.isEmpty()){
        if (IsFlowAnalysisPatientDir(dir)){
            int max_flows = GetFlowAnalysisNumFiles(dir);
            if (max_flows > 0){
                coords_MRI_arterial = new Coord*[max_flows];
                coords_MRI_venous = new Coord*[max_flows];
                coords_MRI_csf = new Coord*[max_flows];
                DialogFlow *dialog = new DialogFlow(dir, list_MRI_informations,
                                                    coords_MRI_arterial, list_MRI_arterial,
                                                    coords_MRI_venous, list_MRI_venous,
                                                    coords_MRI_csf, list_MRI_csf,
                                                    this);
                int res = dialog->exec();
                if (res == QDialog::Accepted){
                    DialogFlowConstructor *dialog2 = new DialogFlowConstructor(coords_MRI_arterial, coords_MRI_venous, coords_MRI_csf,
                                                                               list_MRI_arterial, list_MRI_venous, list_MRI_csf,
                                                                               coord_MRI_arterial_cervical, coord_MRI_venous_cervical, coord_MRI_csf_cervical,
                                                                               list_MRI_arterial_cervical, list_MRI_venous_cervical, list_MRI_csf_cervical,
                                                                               coord_MRI_arterial_cerebral, coord_MRI_venous_cerebral, coord_MRI_csf_cerebral,
                                                                               list_MRI_arterial_cerebral, list_MRI_venous_cerebral, list_MRI_csf_cerebral,
                                                                               this);

                    res = dialog2->exec();

                    if (res == QDialog::Accepted){
                        if (line_patient->text().isEmpty()){
                            line_patient->setText(list_MRI_informations->at(0) + UNDERSCORE + list_MRI_informations->at(1) + UNDERSCORE + list_MRI_informations->at(2));
                        }

                        line_MRI->clear();
                        line_MRI->setText(dir);
                    }
                    else{
                        list_MRI_arterial->clear();
                        list_MRI_venous->clear();
                        list_MRI_csf->clear();

                        list_MRI_arterial_cervical->clear();
                        list_MRI_venous_cervical->clear();
                        list_MRI_csf_cervical->clear();

                        list_MRI_arterial_cerebral->clear();
                        list_MRI_venous_cerebral->clear();
                        list_MRI_csf_cerebral->clear();
                    }
                }
                else{
                    list_MRI_arterial->clear();
                    list_MRI_venous->clear();
                    list_MRI_csf->clear();
                }
            }
        }
    }
}

void DialogNew::load_ICP(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    QString file_name = QFileDialog::getOpenFileName(this, DIALOG_NEW_ICP_DIALOG, get_Data_directory(), DATA_TYPE);
    #ifdef WIN_OS
        file_name.replace(UNIX_DIR_SEPARATOR, WINDOWS_DIR_SEPARATOR);
    #endif
        if (!file_name.isEmpty()){
            bool res = load_data_proliphyc(file_name, coord_ICP);

            if (res){
                if (!line_ICP->text().isEmpty()){
                    line_ICP->setText(line_ICP->text() + DIALOG_NEW_PLUS + file_name);
                }
                else{
                    line_ICP->setText(file_name);
                }

                int pos = file_name.indexOf(DIR_SEPARATOR);
                while (pos != -1){
                    file_name.remove(0, pos+1);
                    pos = file_name.indexOf(DIR_SEPARATOR);
                }

                if (line_patient->text().isEmpty()){
                    file_name.remove(DATA_EXTENSION);
                    file_name.replace(SPACE, UNDERSCORE);
                    line_patient->setText(file_name);
                }
            }
        }
}

void DialogNew::load_EPI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    dir = QFileDialog::getExistingDirectory(this, DIALOG_NEW_FLOW_DIALOG, get_Flow_directory());

    if (!dir.isEmpty()){
        if (IsFlowAnalysisPatientDir(dir)){
            int max_flows = GetFlowAnalysisNumFiles(dir);
            if (max_flows > 0){
                coords_EPI_arterial = new Coord*[max_flows];
                coords_EPI_venous = new Coord*[max_flows];
                coords_EPI_csf = new Coord*[max_flows];
                DialogFlowEPI *dialog = new DialogFlowEPI(dir, list_EPI_informations,
                                                    coords_EPI_arterial, list_EPI_arterial,
                                                    coords_EPI_venous, list_EPI_venous,
                                                    coords_EPI_csf, list_EPI_csf,
                                                    this);
                int res = dialog->exec();
                if (res == QDialog::Accepted){
                    /*DialogFlowConstructorEPI *dialog2 = new DialogFlowConstructorEPI(coords_EPI_arterial, coords_EPI_venous, coords_EPI_csf,
                                                                               list_EPI_arterial, list_EPI_venous, list_EPI_csf,
                                                                               coord_EPI_arterial_cervical, coord_EPI_venous_cervical, coord_EPI_csf_cervical,
                                                                               list_EPI_arterial_cervical, list_EPI_venous_cervical, list_EPI_csf_cervical,
                                                                               coord_EPI_arterial_cerebral, coord_EPI_venous_cerebral, coord_EPI_csf_cerebral,
                                                                               list_EPI_arterial_cerebral, list_EPI_venous_cerebral, list_EPI_csf_cerebral,
                                                                               this);

                    res = dialog2->exec();*/

                    if (res == QDialog::Accepted){
                        if (line_patient->text().isEmpty()){
                            line_patient->setText(list_EPI_informations->at(0) + UNDERSCORE + list_EPI_informations->at(1) + UNDERSCORE + list_EPI_informations->at(2));
                        }

                        line_EPI->clear();
                        line_EPI->setText(dir);
                    }
                    else{
                        list_EPI_arterial->clear();
                        list_EPI_venous->clear();
                        list_EPI_csf->clear();

                        list_EPI_arterial_cervical->clear();
                        list_EPI_venous_cervical->clear();
                        list_EPI_csf_cervical->clear();

                        list_EPI_arterial_cerebral->clear();
                        list_EPI_venous_cerebral->clear();
                        list_EPI_csf_cerebral->clear();
                    }
                }
                else{
                    list_EPI_arterial->clear();
                    list_EPI_venous->clear();
                    list_EPI_csf->clear();
                }
            }
        }
    }
}

void DialogNew::cancel(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    reject();
}

void DialogNew::valid(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!line_patient->text().isEmpty()){
        line_patient->setText(line_patient->text().replace(SPACE, UNDERSCORE));

        //LINUX create directory
#ifdef LINUX_OS
        QString command = "mkdir " + get_Results_directory() + line_patient->text();
#endif
#ifdef MAC_OS
        QString command = "mkdir " + get_Results_directory() + line_patient->text();
#endif
#ifdef WIN_OS
        QString command = "mkdir " + get_Results_directory() + line_patient->text();
#endif
        int res = system(command.toStdString().c_str());
        if (res != 0){
            QMessageBox::critical(this, NEW_ERROR_002_N, NEW_ERROR_002);
        }
        else{
            //Directory
            QString new_directory = get_Results_directory() + line_patient->text() + DIR_SEPARATOR;

            //All MRI files
            {
                int n_arterial = list_MRI_arterial->size() / 2;
                int n_venous = list_MRI_venous->size() / 2;
                int n_csf = list_MRI_csf->size() / 2;

                //DATA
                for (int i = 0; i < n_arterial; i++){
                    save_data(new_directory + list_MRI_arterial->at(2*i), coords_MRI_arterial[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_arterial];
                    string *list2 = new string[n_arterial];

                    for (int i = 0; i < n_arterial; i++){
                        list1[i] = list_MRI_arterial->at(2*i).toStdString();
                        list2[i] = list_MRI_arterial->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + MRI_ARTERIAL_QUALITY_FILE, list1, list2, n_arterial);

                    delete[] list1;
                    delete[] list2;
                }

                //DATA
                for (int i = 0; i < n_venous; i++){
                    save_data(new_directory + list_MRI_venous->at(2*i), coords_MRI_venous[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_venous];
                    string *list2 = new string[n_venous];

                    for (int i = 0; i < n_venous; i++){
                        list1[i] = list_MRI_venous->at(2*i).toStdString();
                        list2[i] = list_MRI_venous->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + MRI_VENOUS_QUALITY_FILE, list1, list2, n_venous);

                    delete[] list1;
                    delete[] list2;
                }

                //DATA
                for (int i = 0; i < n_csf; i++){
                    save_data(new_directory + list_MRI_csf->at(2*i), coords_MRI_csf[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_csf];
                    string *list2 = new string[n_csf];

                    for (int i = 0; i < n_csf; i++){
                        list1[i] = list_MRI_csf->at(2*i).toStdString();
                        list2[i] = list_MRI_csf->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + MRI_CSF_QUALITY_FILE, list1, list2, n_csf);

                    delete[] list1;
                    delete[] list2;
                }
            }

            //All EPI Files
            {
                int n_arterial = list_EPI_arterial->size() / 2;
                int n_venous = list_EPI_venous->size() / 2;
                int n_csf = list_EPI_csf->size() / 2;

                //DATA
                for (int i = 0; i < n_arterial; i++){
                    save_data(new_directory + list_EPI_arterial->at(2*i), coords_EPI_arterial[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_arterial];
                    string *list2 = new string[n_arterial];

                    for (int i = 0; i < n_arterial; i++){
                        list1[i] = list_EPI_arterial->at(2*i).toStdString();
                        list2[i] = list_EPI_arterial->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + EPI_ARTERIAL_QUALITY_FILE, list1, list2, n_arterial);

                    delete[] list1;
                    delete[] list2;
                }

                //DATA
                for (int i = 0; i < n_venous; i++){
                    save_data(new_directory + list_EPI_venous->at(2*i), coords_EPI_venous[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_venous];
                    string *list2 = new string[n_venous];

                    for (int i = 0; i < n_venous; i++){
                        list1[i] = list_EPI_venous->at(2*i).toStdString();
                        list2[i] = list_EPI_venous->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + EPI_VENOUS_QUALITY_FILE, list1, list2, n_venous);

                    delete[] list1;
                    delete[] list2;
                }

                //DATA
                for (int i = 0; i < n_csf; i++){
                    save_data(new_directory + list_EPI_csf->at(2*i), coords_EPI_csf[i]);
                }

                //QUALITY
                {
                    string *list1 = new string[n_csf];
                    string *list2 = new string[n_csf];

                    for (int i = 0; i < n_csf; i++){
                        list1[i] = list_EPI_csf->at(2*i).toStdString();
                        list2[i] = list_EPI_csf->at(2*i+1).toStdString();
                    }

                    save_sup_data(new_directory + EPI_CSF_QUALITY_FILE, list1, list2, n_csf);

                    delete[] list1;
                    delete[] list2;
                }
            }

            //Cervical and cerebral files
            {
                int n = FILE_NAMES_LENGTH;
                string *list1 = new string[n];
                string *list2 = new string[n];

                list1[0] = FILE_NAME_ITEM01;
                list2[0] = line_MRI->text().toStdString();

                list1[1] = FILE_NAME_ITEM02;
                if (list_MRI_arterial_cervical->size() > 0) list2[1] = list_MRI_arterial_cervical->at(0).toStdString();
                list1[2] = FILE_NAME_ITEM03;
                if (list_MRI_venous_cervical->size() > 0) list2[2] = list_MRI_venous_cervical->at(0).toStdString();
                list1[3] = FILE_NAME_ITEM04;
                if (list_MRI_csf_cervical->size() > 0) list2[3] = list_MRI_csf_cervical->at(0).toStdString();
                list1[4] = FILE_NAME_ITEM05;
                if (list_MRI_arterial_cerebral->size() > 0) list2[4] = list_MRI_arterial_cerebral->at(0).toStdString();
                list1[5] = FILE_NAME_ITEM06;
                if (list_MRI_venous_cerebral->size() > 0) list2[5] = list_MRI_venous_cerebral->at(0).toStdString();
                list1[6] = FILE_NAME_ITEM07;
                if (list_MRI_csf_cerebral->size() > 0) list2[6] = list_MRI_csf_cerebral->at(0).toStdString();

                list1[7] = FILE_NAME_ITEM08;
                list2[7] = line_ICP->text().toStdString();

                list1[8] = FILE_NAME_ITEM09;
                list2[8] = line_EPI->text().toStdString();
                list1[9] = FILE_NAME_ITEM10;
                if (list_EPI_arterial_cervical->size() > 0) list2[9] = list_EPI_arterial_cervical->at(0).toStdString();
                list1[10] = FILE_NAME_ITEM11;
                if (list_EPI_venous_cervical->size() > 0) list2[10] = list_EPI_venous_cervical->at(0).toStdString();
                list1[11] = FILE_NAME_ITEM12;
                if (list_EPI_csf_cervical->size() > 0) list2[11] = list_EPI_csf_cervical->at(0).toStdString();
                list1[12] = FILE_NAME_ITEM13;
                if (list_EPI_arterial_cerebral->size() > 0) list2[12] = list_EPI_arterial_cerebral->at(0).toStdString();
                list1[13] = FILE_NAME_ITEM14;
                if (list_EPI_venous_cerebral->size() > 0) list2[13] = list_EPI_venous_cerebral->at(0).toStdString();
                list1[14] = FILE_NAME_ITEM15;
                if (list_EPI_csf_cerebral->size() > 0) list2[14] = list_EPI_csf_cerebral->at(0).toStdString();

                save_sup_data(new_directory + FILE_NAMES_FILE, list1, list2, n);

                delete[] list1;
                delete[] list2;
            }

            //Save informations
            {
                int n = INFORMATIONS_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                list1[0] = INFORMATIONS_DATA_ITEM01;
                if (list_MRI_informations->size() > 1) list2[0] = list_MRI_informations->at(1).toStdString();
                list1[1] = INFORMATIONS_DATA_ITEM02;
                if (list_MRI_informations->size() > 2)list2[1] = list_MRI_informations->at(2).toStdString();
                list1[2] = INFORMATIONS_DATA_ITEM03;
                if (list_MRI_informations->size() > 3)list2[2] = list_MRI_informations->at(3).toStdString();
                list1[3] = INFORMATIONS_DATA_ITEM04;
                if (list_MRI_informations->size() > 4)list2[3] = list_MRI_informations->at(4).toStdString();
                list1[4] = INFORMATIONS_DATA_ITEM05;
                if (list_MRI_informations->size() > 5)list2[4] = list_MRI_informations->at(5).toStdString();
                list1[5] = INFORMATIONS_DATA_ITEM06;
                if (list_MRI_informations->size() > 6)list2[5] = list_MRI_informations->at(6).toStdString();

                save_sup_data(new_directory + INFORMATIONS_FILE, list1, list2, n);

                delete[] list1;
                delete[] list2;
            }

            //Save MRI quality
            {
                int n = MRI_QUALITY_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                list1[0] = MRI_QUALITY_ITEM01;
                list2[0] = EMPTY_STRING;
                list1[1] = MRI_QUALITY_ITEM02;
                if (list_MRI_arterial_cervical->size() > 1) list2[1] = list_MRI_arterial_cervical->at(1).toStdString();
                list1[2] = MRI_QUALITY_ITEM03;
                if (list_MRI_venous_cervical->size() > 1) list2[2] = list_MRI_venous_cervical->at(1).toStdString();
                list1[3] = MRI_QUALITY_ITEM04;
                if (list_MRI_csf_cervical->size() > 1) list2[3] = list_MRI_csf_cervical->at(1).toStdString();
                list1[4] = MRI_QUALITY_ITEM05;
                list2[4] = EMPTY_STRING;
                list1[5] = MRI_QUALITY_ITEM06;
                if (list_MRI_arterial_cerebral->size() > 1) list2[5] = list_MRI_arterial_cerebral->at(1).toStdString();
                list1[6] = MRI_QUALITY_ITEM07;
                if (list_MRI_venous_cerebral->size() > 1) list2[6] = list_MRI_venous_cerebral->at(1).toStdString();
                list1[7] = MRI_QUALITY_ITEM08;
                if (list_MRI_csf_cerebral->size() > 1) list2[7] = list_MRI_csf_cerebral->at(1).toStdString();


                save_sup_data(new_directory + MRI_QUALITY_FILE_CC, list1, list2, n);

                delete[] list1;
                delete[] list2;
            }

            //Save ICP quality
            {
                int n = ICP_QUALITY_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                list1[0] = ICP_QUALITY_ITEM01;  list2[0] = QString::number(QUALITY5).toStdString();

                save_sup_data(new_directory + ICP_QUALITY_FILE, list1, list2, n);

                delete[] list1;
                delete[] list2;
            }

            //Save EPI quality
            {
                int n = EPI_QUALITY_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                list1[0] = EPI_QUALITY_ITEM01;
                list2[0] = EMPTY_STRING;
                list1[1] = EPI_QUALITY_ITEM02;
                if (list_EPI_arterial_cervical->size() > 1) list2[1] = list_EPI_arterial_cervical->at(1).toStdString();
                list1[2] = EPI_QUALITY_ITEM03;
                if (list_EPI_venous_cervical->size() > 1) list2[2] = list_EPI_venous_cervical->at(1).toStdString();
                list1[3] = EPI_QUALITY_ITEM04;
                if (list_EPI_csf_cervical->size() > 1) list2[3] = list_EPI_csf_cervical->at(1).toStdString();
                list1[4] = EPI_QUALITY_ITEM05;
                list2[4] = EMPTY_STRING;
                list1[5] = EPI_QUALITY_ITEM06;
                if (list_EPI_arterial_cerebral->size() > 1) list2[5] = list_EPI_arterial_cervical->at(1).toStdString();
                list1[6] = EPI_QUALITY_ITEM07;
                if (list_EPI_venous_cerebral->size() > 1) list2[6] = list_EPI_venous_cervical->at(1).toStdString();
                list1[7] = EPI_QUALITY_ITEM08;
                if (list_EPI_csf_cerebral->size() > 1) list2[7] = list_EPI_csf_cervical->at(1).toStdString();

                save_sup_data(new_directory + EPI_QUALITY_FILE_CC, list1, list2, n);

                delete[] list1;
                delete[] list2;
            }

            //Save data file in the new directory
            if (coord_MRI_arterial_cervical->size() > 0){
                save_data(new_directory + MRI_ARTERIAL_CERVICAL_FILE, coord_MRI_arterial_cervical, NULL);
            }
            if (coord_MRI_venous_cervical->size() > 0){
                save_data(new_directory + MRI_VENOUS_CERVICAL_FILE, coord_MRI_venous_cervical, NULL);
            }
            if (coord_MRI_csf_cervical->size() > 0){
                save_data(new_directory + MRI_CSF_CERVICAL_FILE, coord_MRI_csf_cervical, NULL);
            }
            if (coord_MRI_arterial_cerebral->size() > 0){
                save_data(new_directory + MRI_ARTERIAL_CEREBRAL_FILE, coord_MRI_arterial_cerebral, NULL);
            }
            if (coord_MRI_venous_cerebral->size() > 0){
                save_data(new_directory + MRI_VENOUS_CEREBRAL_FILE, coord_MRI_venous_cerebral, NULL);
            }
            if (coord_MRI_csf_cerebral->size() > 0){
                save_data(new_directory + MRI_CSF_CEREBRAL_FILE, coord_MRI_csf_cerebral, NULL);
            }


           if (coord_ICP->size() > 0){
                save_data(new_directory + ICP_FILE, coord_ICP, NULL);
            }


            if (coord_EPI_arterial_cervical->size() > 0){
                save_data(new_directory + EPI_ARTERIAL_CERVICAL_FILE, coord_EPI_arterial_cervical, NULL);
            }
            if (coord_EPI_venous_cervical->size() > 0){
                save_data(new_directory + EPI_VENOUS_CERVICAL_FILE, coord_EPI_venous_cervical, NULL);
            }
            if (coord_EPI_csf_cervical->size() > 0){
                save_data(new_directory + EPI_CSF_CERVICAL_FILE, coord_EPI_csf_cervical, NULL);
            }
            if (coord_EPI_arterial_cerebral->size() > 0){
                save_data(new_directory + EPI_ARTERIAL_CEREBRAL_FILE, coord_EPI_arterial_cerebral, NULL);
            }
            if (coord_EPI_venous_cerebral->size() > 0){
                save_data(new_directory + EPI_VENOUS_CEREBRAL_FILE, coord_EPI_venous_cerebral, NULL);
            }
            if (coord_EPI_csf_cerebral->size() > 0){
                save_data(new_directory + EPI_CSF_CEREBRAL_FILE, coord_EPI_csf_cerebral, NULL);
            }

            delete_all();

            accept();
        }
    }
}

void DialogNew::delete_all(){
    if (coords_MRI_arterial != NULL) delete[] coords_MRI_arterial; coords_MRI_arterial = NULL;
    if (coords_MRI_venous != NULL) delete[] coords_MRI_venous; coords_MRI_venous = NULL;
    if (coords_MRI_csf != NULL) delete[] coords_MRI_csf; coords_MRI_csf = NULL;

    if (coords_EPI_arterial != NULL) delete[] coords_EPI_arterial; coords_EPI_arterial = NULL;
    if (coords_EPI_venous != NULL) delete[] coords_EPI_venous; coords_EPI_venous = NULL;
    if (coords_EPI_csf != NULL) delete[] coords_EPI_csf; coords_EPI_csf = NULL;
}

void DialogNew::closeEvent(QCloseEvent *){
    delete_all();
}

