#include "dialogflowepi.h"

bool DialogFlowEPI::load_flow_data(QString file, int *quality, Coord *data)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Number of time/flow points
    int nbp = -1;
    //Open file
    QFile fichier(file);
    if (fichier.open(QIODevice::ReadOnly)){
        //Read flow Analysis file
        QString tmp;
        QString quality_str;
        QString nbp_tmp;
        for (int i = 0; i < 3; i++){
            tmp = fichier.readLine();
        }
        quality_str = fichier.readLine();               //Quality
        quality_str.remove(DIALOG_FLOW_I_CONFIANCE).remove("\n").remove("\r");
        for (int i = 4; i < 35; i++){
            tmp = fichier.readLine();
        }
        nbp_tmp = fichier.readLine();
        nbp_tmp.remove("Num_Pts").remove("\n").remove("\r");
        nbp = nbp_tmp.toInt();
        //Set data size
        data->set_size(nbp);
        tmp = fichier.readLine();
        for (int i = 0; i < nbp; i++){
            tmp = fichier.readLine();
            tmp.remove(DIALOG_FLOW_BEFORE_NUMBER);
            data->set_coord(tmp.toDouble(), i, YCOORD);    //Flow
        }
        tmp = fichier.readLine();
        for (int i = 0; i < nbp; i++){
            tmp = fichier.readLine();
            tmp.remove(DIALOG_FLOW_BEFORE_NUMBER);
            data->set_coord(tmp.toDouble()*1.e-3, i, XCOORD);    //Time
        }
        fichier.close();
        (*quality) = quality_str.toInt();
        return true;
    }
    else{
        cout << "ERROR DialogFlowEPI::load_flow_data" << endl;
    #ifndef MAC_OS
        cout << file.toStdString() << endl;
    #endif
        return false;
    }
}

QStringList DialogFlowEPI::load_flow_informations(QString file_name, bool *res)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    QStringList list;

    //Read file
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly)){
        QString tmp;
        tmp = file.readLine();

        tmp = file.readLine();
        tmp.remove(DIALOG_FLOW_AGE);
        tmp.remove(" ");
        tmp.remove("\n").remove("\r");
        list.append(tmp);

        tmp = file.readLine();
        tmp.remove(DIALOG_FLOW_SEXE);
        tmp.remove(" ");
        tmp.remove("\n").remove("\r");
        list.append(tmp);

        tmp = file.readLine();
        tmp.remove(DIALOG_FLOW_DATE_EXAM);
        tmp.remove(" ");
        tmp.remove("\n").remove("\r");
        tmp.replace("/", "-");
        list.append(tmp);

        tmp = file.readLine();
        tmp.remove(DIALOG_FLOW_DATE_NAISSANCE);
        tmp.remove(" ");
        tmp.remove("\n").remove("\r");
        tmp.replace("/", "-");
        list.append(tmp);

        if (file.atEnd()){
            list.append(EMPTY_STRING);
        }
        else{
            tmp = file.readLine();
            tmp.remove(DIALOG_FLOW_CONSTRUCTEUR_IRM);
            tmp.remove(" ");
            tmp.remove("\n").remove("\r");
            list.append(tmp);
        }

        if (res != NULL) *res = true;
    }
    if (res != NULL) *res = false;
    return list;
}

void DialogFlowEPI::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    //HBox
    hbox_title = new QHBoxLayout;
    hbox_button = new QHBoxLayout;

    //Label
    label_title = new QLabel(this);
    label_title_img = new QLabel(this);

    label_arterial = new QLabel(this);
    label_venous = new QLabel(this);
    label_csf = new QLabel(this);
    label_constructor = new QLabel(this);

    labels_arterial = NULL;
    labels_venous = NULL;
    labels_csf = NULL;

    labels_arterial_quality = NULL;
    labels_venous_quality = NULL;
    labels_csf_quality = NULL;

    //Radio
    radio_constructor1 = new QRadioButton(this);
    radio_constructor2 = new QRadioButton(this);
    radio_constructor3 = new QRadioButton(this);
    radio_constructor4 = new QRadioButton(this);
    radio_constructor5 = new QRadioButton(this);

    //CheckBox
    checks_arterial = NULL;
    checks_venous = NULL;
    checks_csf = NULL;

    //Button
    button_cancel = new QPushButton(this);
    button_load = new QPushButton(this);
    button_valid = new QPushButton(this);

    //String
    dir = EMPTY_STRING;
    patient_name = EMPTY_STRING;
    exam_number = EMPTY_STRING;
    exam_date = EMPTY_STRING;
    patient_date = EMPTY_STRING;
    patient_age = EMPTY_STRING;
    patient_sexe = EMPTY_STRING;
    MRI_constructor = EMPTY_STRING;

    files_arterial = new QStringList;
    files_venous = new QStringList;
    files_csf = new QStringList;

    informations = NULL;
    list_arterial = NULL;
    list_venous = NULL;
    list_csf = NULL;

    //Coord
    coords_arterial = NULL;
    coords_venous = NULL;
    coords_csf = NULL;
}

void DialogFlowEPI::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Button
    button_cancel->setText(DIALOG_FLOW_CANCEL);
    button_load->setText(DIALOG_FLOW_LOAD);
    button_valid->setText(DIALOG_FLOW_VALID);
    button_valid->setEnabled(false);

    //Label
    label_title->setText(DIALOG_FLOW_TITLE);
    label_title_img->setPixmap(QPixmap(IMG_FLOW).scaled(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));

    label_arterial->setText(DIALOG_FLOW_ARTERIAL_FILES);
    label_venous->setText(DIALOG_FLOW_VENOUS_FILES);
    label_csf->setText(DIALOG_FLOW_CSF_FILES);
    label_constructor->setText(DIALOG_FLOW_MRI_CONSTRUCTOR);

    //Radio
    radio_constructor1->setText(DIALOG_FLOW_MRI_CONSTUCTOR_1);
    radio_constructor2->setText(DIALOG_FLOW_MRI_CONSTUCTOR_2);
    radio_constructor3->setText(DIALOG_FLOW_MRI_CONSTUCTOR_3);
    radio_constructor4->setText(DIALOG_FLOW_MRI_CONSTUCTOR_4);
    radio_constructor5->setText(DIALOG_FLOW_MRI_CONSTUCTOR_5);

    //HBox
    hbox_title->addWidget(label_title_img);
    hbox_title->addWidget(label_title);

    hbox_button->addWidget(button_cancel);
    hbox_button->addWidget(button_load);
    hbox_button->addWidget(button_valid);

    //Grid
    setLayout(grid);

    grid->addLayout(hbox_title, 0, 0, 1, 10);

    grid->addWidget(label_arterial, 1, 0, 1, 3);
    grid->addWidget(label_venous, 1, 3, 1, 3);
    grid->addWidget(label_csf, 1, 6, 1, 3);
    grid->addWidget(label_constructor, 1, 9, 1, 3);

    grid->addWidget(radio_constructor1, 2, 9, 1, 1);
    grid->addWidget(radio_constructor2, 3, 9, 1, 1);
    grid->addWidget(radio_constructor3, 4, 9, 1, 1);
    grid->addWidget(radio_constructor4, 5, 9, 1, 1);
    grid->addWidget(radio_constructor5, 6, 9, 1, 1);

    grid->addLayout(hbox_button, 100, 0, 1, 10);
}

void DialogFlowEPI::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(button_load, SIGNAL(clicked()), this, SLOT(load()));
    connect(button_valid, SIGNAL(clicked()), this, SLOT(valid()));
}

void DialogFlowEPI::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_title->setStyleSheet(CSS_LABEL_TITLE);

    label_arterial->setStyleSheet(CSS_LABEL_BIG);
    label_venous->setStyleSheet(CSS_LABEL_BIG);
    label_csf->setStyleSheet(CSS_LABEL_BIG);
    label_constructor->setStyleSheet(CSS_LABEL_BIG);
}

DialogFlowEPI::DialogFlowEPI(QString dir, QStringList *informations,
                       Coord **coords_arterial, QStringList *list_arterial,
                       Coord **coords_venous, QStringList *list_venous,
                       Coord **coords_csf, QStringList *list_csf,
                       QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();

    //Address copy
    this->dir = dir;
    this->informations = informations;
    this->list_arterial = list_arterial;
    this->list_venous = list_venous;
    this->list_csf = list_csf;

    this->coords_arterial = coords_arterial;
    this->coords_venous = coords_venous;
    this->coords_csf = coords_csf;

    //Patient name
    patient_name = QString(dir);
    {
#ifdef WIN_OS
        patient_name.replace(UNIX_DIR_SEPARATOR, WINDOWS_DIR_SEPARATOR);
#endif
        int pos = patient_name.indexOf(DIR_SEPARATOR);
        while (pos != -1){
            patient_name.remove(0, pos+1);
            pos = patient_name.indexOf(DIR_SEPARATOR);
        }
    }

    //list Files
#ifdef LINUX_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef MAC_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef WIN_OS
    dir.replace("/", "\\");
    QString command = "dir /B /A:D \"" + dir + "\" > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
    int res = system(command.toStdString().c_str());
    if (!res){
        //Read List
        QStringList exam_list;

        QFile file(QString(SYSTEM_DIR) + "ls1.txt");
        if (file.open(QIODevice::ReadOnly)){
            while(!file.atEnd()){
                QString tmp = file.readLine();
                tmp.remove("\n").remove("\r");
                exam_list.append(tmp);
            }

            if (exam_list.size() > 1){
                exam_number = QInputDialog::getItem(this, DIALOG_FLOW_EXAM_DIALOG_TITLE, DIALOG_FLOW_EXAM_DIALOG_TXT, exam_list, 0, false);
            }
            else{
                exam_number = exam_list.takeFirst();
            }

            QString location = dir + DIR_SEPARATOR + exam_number + DIR_SEPARATOR;

            //list Files

#ifdef LINUX_OS
            QString command = "ls \'" + dir + "/" + exam_number + "\' > " + QString(SYSTEM_DIR)  + "ls2.txt\n";
#endif
#ifdef MAC_OS
            QString command = "ls \'" + dir + "/" + exam_number + "\' > " + QString(SYSTEM_DIR)  + "ls2.txt\n";
#endif
#ifdef WIN_OS

            QString command = "dir /B \"" + dir + "\\" + exam_number + "\" > " + QString(SYSTEM_DIR)  + "ls2.txt\n";
#endif

            int res = system(command.toStdString().c_str());
            if (!res){
                //Read List
                QStringList files;

                QFile file(QString::fromStdString(SYSTEM_DIR) + "ls2.txt");
                if (file.open(QIODevice::ReadOnly)){
                    while (!file.atEnd()){
                        QString file_name = file.readLine();
                        file_name.remove("\n").remove("\r");
                        if (file_name.indexOf(".txt") != -1){
                            files.append(file_name);
                        }
                    }

                    //List Copy
                    for (int i = 0; i < files.size(); i++){
                        QString file_name = files.at(i);
                        if (file_name.contains("epi_")){
                            if (file_name.contains(DIALOG_FLOW_CID_CERVICAL)
                                    || file_name.contains(DIALOG_FLOW_CIG_CERVICAL)
                                    || file_name.contains(DIALOG_FLOW_VERTEBRALD)
                                    || file_name.contains(DIALOG_FLOW_VERTEBRALG)
                                    ){
                                files_arterial->append(file_name);
                            }
                            else if (file_name.contains(DIALOG_FLOW_CID_CEREBRAL)
                                     || file_name.contains(DIALOG_FLOW_CIG_CEREBRAL)
                                     || file_name.contains(DIALOG_FLOW_TB)
                                     ){
                                files_arterial->append(file_name);
                            }
                            else if (file_name.contains(DIALOG_FLOW_JUGULARD)
                                     || file_name.contains(DIALOG_FLOW_JUGULARG)
                                     || file_name.contains(DIALOG_FLOW_EPIDURALD)
                                     || file_name.contains(DIALOG_FLOW_EPIDURALG)
                                     || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORD)
                                     || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORG)
                                     ){
                                files_venous->append(file_name);
                            }
                            else if (file_name.contains(DIALOG_FLOW_SINUSS)
                                     || file_name.contains(DIALOG_FLOW_SINUSD)
                                     || file_name.contains(DIALOG_FLOW_CSINUSS)
                                     || file_name.contains(DIALOG_FLOW_CSINUSD)
                                     || file_name.contains(DIALOG_FLOW_CSINUSLD)
                                     || file_name.contains(DIALOG_FLOW_CSINUSLG)
                                     ){
                                files_venous->append(file_name);
                            }
                            else if (file_name.contains(DIALOG_FLOW_CSF_C2C3)
                                     || file_name.contains(DIALOG_FLOW_CSF_MC2C3)
                                     || file_name.contains(DIALOG_FLOW_CSF_SPINE)
                                     || file_name.contains(DIALOG_FLOW_CSF_C1)
                                     ){
                                files_csf->append(file_name);
                            }
                            else if (file_name.contains(DIALOG_FLOW_CSF_AQUEDUC)
                                     || file_name.contains(DIALOG_FLOW_CSF_V4)
                                     || file_name.contains(DIALOG_FLOW_CSF_MV4)
                                     || file_name.contains(DIALOG_FLOW_CSF_JBM)
                                     || file_name.contains(DIALOG_FLOW_CSF_CP)
                                     || file_name.contains(DIALOG_FLOW_CSF_MCP)
                                     || file_name.contains(DIALOG_FLOW_CSF_MONROD)
                                     || file_name.contains(DIALOG_FLOW_CSF_MONROG)
                                     || file_name.contains(DIALOG_FLOW_CSF_V3)
                                     || file_name.contains(DIALOG_FLOW_CSF_V3STOMIE)
                                     ){
                                files_csf->append(file_name);
                            }
                            else{
                                if (file_name.compare(DIALOG_FLOW_INFORMATIONS) != 0){
                                    files_arterial->append(file_name);
                                    files_venous->append(file_name);
                                    files_csf->append(file_name);
                                }
                            }
                        }
                    }

                    //Informations
                    QStringList list = load_flow_informations(location+DIALOG_FLOW_INFORMATIONS);
                    exam_date = list.at(2);
                    patient_date = list.at(3);
                    patient_age = list.at(0);
                    patient_sexe = list.at(1);
                    MRI_constructor = list.at(4);

                    if (MRI_constructor.compare(DIALOG_FLOW_MRI_CONSTUCTOR_1) == 0){
                        radio_constructor1->setChecked(true);
                    }
                    else if (MRI_constructor.compare(DIALOG_FLOW_MRI_CONSTUCTOR_2) == 0){
                        radio_constructor2->setChecked(true);
                    }
                    else if (MRI_constructor.compare(DIALOG_FLOW_MRI_CONSTUCTOR_3) == 0){
                        radio_constructor3->setChecked(true);
                    }
                    else if (MRI_constructor.compare(DIALOG_FLOW_MRI_CONSTUCTOR_4) == 0){
                        radio_constructor4->setChecked(true);
                    }
                    else{
                        radio_constructor5->setChecked(true);
                    }

                    //Labels and checks
                    int n_arterial = files_arterial->size();
                    int n_venous = files_venous->size();
                    int n_csf = files_csf->size();

                    labels_arterial = new QLabel[n_arterial];
                    labels_venous = new QLabel[n_venous];
                    labels_csf = new QLabel[n_csf];

                    labels_arterial_quality = new QLabel[n_arterial];
                    labels_venous_quality = new QLabel[n_venous];
                    labels_csf_quality = new QLabel[n_csf];

                    checks_arterial = new QCheckBox[n_arterial];
                    checks_venous = new QCheckBox[n_venous];
                    checks_csf = new QCheckBox[n_csf];

                    for (int i = 0; i < n_arterial; i++){
                        QString file_name = files_arterial->at(i);
                        if (file_name.contains(DIALOG_FLOW_CID_CERVICAL)
                                || file_name.contains(DIALOG_FLOW_CIG_CERVICAL)
                                || file_name.contains(DIALOG_FLOW_VERTEBRALD)
                                || file_name.contains(DIALOG_FLOW_VERTEBRALG)
                                || file_name.contains(DIALOG_FLOW_CID_CEREBRAL)
                                || file_name.contains(DIALOG_FLOW_CIG_CEREBRAL)
                                || file_name.contains(DIALOG_FLOW_TB)
                                ){
                            checks_arterial[i].setChecked(true);
                        }
                        labels_arterial[i].setText(files_arterial->at(i));

                        grid->addWidget(&checks_arterial[i], i+2, 0, 1, 1);
                        grid->addWidget(&labels_arterial[i], i+2, 1, 1, 1);
                        grid->addWidget(&labels_arterial_quality[i], i+2, 2, 1, 1);
                    }

                    for (int i = 0; i < n_venous; i++){
                        QString file_name = files_venous->at(i);
                        if (file_name.contains(DIALOG_FLOW_JUGULARD)
                                 || file_name.contains(DIALOG_FLOW_JUGULARG)
                                 || file_name.contains(DIALOG_FLOW_EPIDURALD)
                                 || file_name.contains(DIALOG_FLOW_EPIDURALG)
                                 || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORD)
                                 || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORG)
                                 || file_name.contains(DIALOG_FLOW_SINUSS)
                                 || file_name.contains(DIALOG_FLOW_SINUSD)
                                 || file_name.contains(DIALOG_FLOW_CSINUSS)
                                 || file_name.contains(DIALOG_FLOW_CSINUSD)
                                 || file_name.contains(DIALOG_FLOW_CSINUSLD)
                                 || file_name.contains(DIALOG_FLOW_CSINUSLG)
                                 ){
                            checks_venous[i].setChecked(true);
                        }
                        labels_venous[i].setText(files_venous->at(i));

                        grid->addWidget(&checks_venous[i], i+2, 3, 1, 1);
                        grid->addWidget(&labels_venous[i], i+2, 4, 1, 1);
                        grid->addWidget(&labels_venous_quality[i], i+2, 5, 1, 1);
                    }

                    for (int i = 0; i < n_csf; i++){
                        QString file_name = files_csf->at(i);
                        if (file_name.contains(DIALOG_FLOW_CSF_C2C3)
                                 || file_name.contains(DIALOG_FLOW_CSF_MC2C3)
                                 || file_name.contains(DIALOG_FLOW_CSF_SPINE)
                                 || file_name.contains(DIALOG_FLOW_CSF_C1)
                                 || file_name.contains(DIALOG_FLOW_CSF_AQUEDUC)
                                 || file_name.contains(DIALOG_FLOW_CSF_V4)
                                 || file_name.contains(DIALOG_FLOW_CSF_MV4)
                                 || file_name.contains(DIALOG_FLOW_CSF_JBM)
                                 || file_name.contains(DIALOG_FLOW_CSF_CP)
                                 || file_name.contains(DIALOG_FLOW_CSF_MCP)
                                 || file_name.contains(DIALOG_FLOW_CSF_MONROD)
                                 || file_name.contains(DIALOG_FLOW_CSF_MONROG)
                                 || file_name.contains(DIALOG_FLOW_CSF_V3)
                                 || file_name.contains(DIALOG_FLOW_CSF_V3STOMIE)
                                 ){
                            checks_csf[i].setChecked(true);
                        }
                        labels_csf[i].setText(files_csf->at(i));

                        grid->addWidget(&checks_csf[i], i+2, 6, 1, 1);
                        grid->addWidget(&labels_csf[i], i+2, 7, 1, 1);
                        grid->addWidget(&labels_csf_quality[i], i+2, 8, 1, 1);
                    }
                }
                else{
                    QMessageBox::critical(this, "ERROR", "BUG FLOW READ FILES");
                    cancel();
                }
            }
            else{
                QMessageBox::critical(this, "ERROR", "BUG FLOW SUBDIR");
                cancel();
            }
        }
        else{
            QMessageBox::critical(this, "ERROR", "BUG FLOW READ SUBDIR");
            cancel();
        }
    }
    else{
        QMessageBox::critical(this, "ERROR", "BUG FLOW DIR DialogFlowEPI::DialogFlowEPI");
        cancel();
    }
}

void DialogFlowEPI::load(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Clear
    informations->clear();
    list_arterial->clear();
    list_venous->clear();
    list_csf->clear();

    //Informations
    informations->append(patient_name);
    informations->append(exam_number);
    informations->append(exam_date);
    informations->append(patient_date);
    informations->append(patient_age);
    informations->append(patient_sexe);
    informations->append(MRI_constructor);

    //Data
    int n_arterial_tmp = files_arterial->size();
    int n_venous_tmp = files_venous->size();
    int n_csf_tmp = files_csf->size();

    //Count
    int n_arterial = 0;
    int n_venous = 0;
    int n_csf = 0;

    for (int i = 0; i < n_arterial_tmp; i++){
        if (checks_arterial[i].isChecked()){
            n_arterial++;
        }
    }
    for (int i = 0; i < n_venous_tmp; i++){
        if (checks_venous[i].isChecked()){
            n_venous++;
        }
    }
    for (int i = 0; i < n_csf_tmp; i++){
        if (checks_csf[i].isChecked()){
            n_csf++;
        }
    }

    int k = 0;
    for (int i = 0; i < n_arterial_tmp; i++){
        if (checks_arterial[i].isChecked()){
            coords_arterial[k] = new Coord;
            int quality;
            bool res = load_flow_data(dir + DIR_SEPARATOR + exam_number + DIR_SEPARATOR + files_arterial->at(i), &quality, coords_arterial[k]);
            if (res){
                list_arterial->append(files_arterial->at(i));
                list_arterial->append(QString::number(quality));
                set_label_qualitycolor(&labels_arterial_quality[i], quality);
                k++;
            }
        }
    }

    k = 0;
    for (int i = 0; i < n_venous_tmp; i++){
        if (checks_venous[i].isChecked()){
            coords_venous[k] = new Coord;
            int quality;
            bool res = load_flow_data(dir + DIR_SEPARATOR + exam_number + DIR_SEPARATOR + files_venous->at(i), &quality, coords_venous[k]);
            if (res){
                list_venous->append(files_venous->at(i));
                list_venous->append(QString::number(quality));
                set_label_qualitycolor(&labels_venous_quality[i], quality);
                k++;
            }
        }
    }

    k = 0;
    for (int i = 0; i < n_csf_tmp; i++){
        if (checks_csf[i].isChecked()){
            coords_csf[k] = new Coord;
            int quality;
            bool res = load_flow_data(dir + DIR_SEPARATOR + exam_number + DIR_SEPARATOR + files_csf->at(i), &quality, coords_csf[k]);
            if (res){
                list_csf->append(files_csf->at(i));
                list_csf->append(QString::number(quality));
                set_label_qualitycolor(&labels_csf_quality[i], quality);
                k++;
            }
        }
    }

    button_valid->setEnabled(true);

    /*if (radio_constructor1->isChecked() || radio_constructor2->isChecked() || radio_constructor5->isChecked()){   //Philips / Siemens / other
        //No inversion flow
    }
    else{   //GE
        for (int i = 0; i < n_arterial; i++){
            coords_arterial[i]->multiply('y', -1);
        }
        for (int i = 0; i < n_venous; i++){
            coords_venous[i]->multiply('y', -1);
        }
        for (int i = 0; i < n_csf; i++){
            coords_csf[i]->multiply('y', -1);
        }
    }*/
    //TODO Need inversion ???
}

void DialogFlowEPI::set_label_qualitycolor(QLabel *label, int quality)
{
    if (DEBUG > 100) cout << Q_FUNC_INFO << endl;

    if (quality == 0 || quality == 6){
        label->clear();
    }
    else if (quality == 1){
        label->setPixmap(QPixmap(DIALOG_FLOW_IMG1).scaled(20, 20));
    }
    else if (quality > 1 && quality < 5){
        label->setPixmap(QPixmap(DIALOG_FLOW_IMG2).scaled(20, 20));
    }
    else if (quality == 5){
        label->setPixmap(QPixmap(DIALOG_FLOW_IMG3).scaled(20, 20));
    }
    else{
        label->setPixmap(QPixmap(DIALOG_FLOW_IMG1).scaled(20, 20));
    }

    if (quality < 1 || quality > 5){
        label->setToolTip(EMPTY_STRING);
    }
    else{
        label->setToolTip(DIALOG_FLOW_QUALITY + QString::number(quality));
    }
}

void DialogFlowEPI::valid(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    delete_all();
    accept();
}

void DialogFlowEPI::cancel(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    delete_all();
    reject();
}

void DialogFlowEPI::delete_all(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (labels_arterial != NULL) delete[] labels_arterial; labels_arterial = NULL;
    if (labels_venous != NULL) delete[] labels_venous; labels_venous = NULL;
    if (labels_csf != NULL) delete[] labels_csf; labels_csf = NULL;

    if (labels_arterial_quality != NULL) delete[] labels_arterial_quality; labels_arterial_quality = NULL;
    if (labels_venous_quality != NULL) delete[] labels_venous_quality; labels_venous_quality = NULL;
    if (labels_csf_quality != NULL) delete[] labels_csf_quality; labels_csf_quality = NULL;

    if (checks_arterial != NULL) delete[] checks_arterial; checks_arterial = NULL;
    if (checks_venous != NULL) delete[] checks_venous; checks_venous = NULL;
    if (checks_csf != NULL) delete[] checks_csf; checks_csf = NULL;
}

void DialogFlowEPI::closeEvent(QCloseEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;

    delete_all();
}
