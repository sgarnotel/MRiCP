#include "dialogflowconstructor.h"

void DialogFlowConstructor::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //int
    n_arterial = list_arterial->size() / 2;
    n_venous = list_venous->size() / 2;
    n_csf = list_csf->size() / 2;

    //Grid
    grid = new QGridLayout;

    //HBox
    hbox_title = new QHBoxLayout;
    hbox_button = new QHBoxLayout;

    //Label
    label_title = new QLabel(this);
    label_title_img = new QLabel(this);

    label_arterial_cervical = new QLabel(this);
    label_venous_cervical = new QLabel(this);
    label_csf_cervical = new QLabel(this);
    label_arterial_cerebral = new QLabel(this);
    label_venous_cerebral = new QLabel(this);
    label_csf_cerebral = new QLabel(this);

    labels_arterial_cervical = new QLabel[n_arterial];
    labels_venous_cervical = new QLabel[n_venous];
    labels_csf_cervical = new QLabel[n_csf];
    labels_arterial_cerebral = new QLabel[n_arterial];
    labels_venous_cerebral = new QLabel[n_venous];
    labels_csf_cerebral = new QLabel[n_csf];

    //CheckBox
    checks_arterial_cervical = new QCheckBox[n_arterial];
    checks_venous_cervical = new QCheckBox[n_venous];
    checks_csf_cervical = new QCheckBox[n_csf];
    checks_arterial_cerebral = new QCheckBox[n_arterial];
    checks_venous_cerebral = new QCheckBox[n_venous];
    checks_csf_cerebral = new QCheckBox[n_csf];

    //Button
    button_cancel = new QPushButton(this);
    button_valid = new QPushButton(this);
}

void DialogFlowConstructor::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    setLayout(grid);

    grid->addLayout(hbox_title, 0, 0, 1, 12);

    grid->addWidget(label_arterial_cervical, 1, 0, 1, 2, Qt::AlignCenter);
    grid->addWidget(label_venous_cervical, 1, 2, 1, 2, Qt::AlignCenter);
    grid->addWidget(label_csf_cervical, 1, 4, 1, 2, Qt::AlignCenter);
    grid->addWidget(label_arterial_cerebral, 1, 6, 1, 2, Qt::AlignCenter);
    grid->addWidget(label_venous_cerebral, 1, 8, 1, 2, Qt::AlignCenter);
    grid->addWidget(label_csf_cerebral, 1, 10, 1, 2, Qt::AlignCenter);

    for (int i = 0; i < n_arterial; i++){
        grid->addWidget(&checks_arterial_cervical[i], i+2, 0, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_arterial_cervical[i], i+2, 1, 1, 1, Qt::AlignLeft);

        grid->addWidget(&checks_arterial_cerebral[i], i+2, 6, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_arterial_cerebral[i], i+2, 7, 1, 1, Qt::AlignLeft);
    }
    for (int i = 0; i < n_venous; i++){
        grid->addWidget(&checks_venous_cervical[i], i+2, 2, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_venous_cervical[i], i+2, 3, 1, 1, Qt::AlignLeft);

        grid->addWidget(&checks_venous_cerebral[i], i+2, 8, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_venous_cerebral[i], i+2, 9, 1, 1, Qt::AlignLeft);
    }
    for (int i = 0; i < n_csf; i++){
        grid->addWidget(&checks_csf_cervical[i], i+2, 4, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_csf_cervical[i], i+2, 5, 1, 1, Qt::AlignLeft);

        grid->addWidget(&checks_csf_cerebral[i], i+2, 10, 1, 1, Qt::AlignRight);
        grid->addWidget(&labels_csf_cerebral[i], i+2, 11, 1, 1, Qt::AlignLeft);
    }

    int row_max = max(n_arterial, n_venous);
    row_max = max(row_max, n_csf);

    grid->addLayout(hbox_button, row_max+2, 0, 1, 12);

    //HBox
    hbox_title->addWidget(label_title_img);
    hbox_title->addWidget(label_title);

    hbox_button->addWidget(button_cancel);
    hbox_button->addWidget(button_valid);

    //Label
    label_title->setText(DIALOG_FLOW_CONSTRUCTOR_TITLE);
    label_title_img->setPixmap(QPixmap(IMG_ADD).scaled(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));

    label_arterial_cervical->setText(DIALOG_FLOW_ARTERIAL_CERVICAL);
    label_venous_cervical->setText(DIALOG_FLOW_VENOUS_CERVICAL);
    label_csf_cervical->setText(DIALOG_FLOW_CSF_CERVICAL);
    label_arterial_cerebral->setText(DIALOG_FLOW_ARTERIAL_CEREBRAL);
    label_venous_cerebral->setText(DIALOG_FLOW_VENOUS_CEREBRAL);
    label_csf_cerebral->setText(DIALOG_FLOW_CSF_CEREBRAL);

    for (int i = 0; i < n_arterial; i++){
        labels_arterial_cervical[i].setText(list_arterial->at(2*i));
        labels_arterial_cerebral[i].setText(list_arterial->at(2*i));
    }
    for (int i = 0; i < n_venous; i++){
        labels_venous_cervical[i].setText(list_venous->at(2*i));
        labels_venous_cerebral[i].setText(list_venous->at(2*i));
    }
    for (int i = 0; i < n_csf; i++){
        labels_csf_cervical[i].setText(list_csf->at(2*i));
        labels_csf_cerebral[i].setText(list_csf->at(2*i));
    }

    //CheckBox
    for (int i = 0; i < n_arterial; i++){
        QString file_name = list_arterial->at(2*i);
        if (file_name.contains(DIALOG_FLOW_CID_CERVICAL)
                || file_name.contains(DIALOG_FLOW_CIG_CERVICAL)
                || file_name.contains(DIALOG_FLOW_VERTEBRALD)
                || file_name.contains(DIALOG_FLOW_VERTEBRALG)
                ){
            checks_arterial_cervical[i].setChecked(true);
        }
        if (file_name.contains(DIALOG_FLOW_CID_CEREBRAL) || file_name.contains(DIALOG_FLOW_CIG_CEREBRAL) || file_name.contains(DIALOG_FLOW_TB)){
            checks_arterial_cerebral[i].setChecked(true);
        }
    }
    for (int i = 0; i < n_venous; i++){
        QString file_name = list_venous->at(2*i);
        if (file_name.contains(DIALOG_FLOW_JUGULARD)
                || file_name.contains(DIALOG_FLOW_JUGULARG)
                || file_name.contains(DIALOG_FLOW_EPIDURALD)
                || file_name.contains(DIALOG_FLOW_EPIDURALG)
                || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORD)
                || file_name.contains(DIALOG_FLOW_PLEXUS_POSTERIORG)
                ){
            checks_venous_cervical[i].setChecked(true);
        }
        if (file_name.contains(DIALOG_FLOW_SINUSS)
                || file_name.contains(DIALOG_FLOW_SINUSD)
                ){
            checks_venous_cerebral[i].setChecked(true);
        }
    }
    for (int i = 0; i < n_csf; i++){
        QString file_name = list_csf->at(2*i);
        if (file_name.contains(DIALOG_FLOW_CSF_C2C3)){
            checks_csf_cervical[i].setChecked(true);
        }
        if (file_name.contains(DIALOG_FLOW_CSF_C2C3)){
            checks_csf_cerebral[i].setChecked(true);
        }
    }

    //Button
    button_cancel->setText(DIALOG_FLOW_CANCEL);
    button_valid->setText(DIALOG_FLOW_VALID);
}

void DialogFlowConstructor::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(button_valid, SIGNAL(clicked()), this, SLOT(valid()));
}

void DialogFlowConstructor::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_title->setStyleSheet(CSS_LABEL_TITLE);

    label_arterial_cervical->setStyleSheet(CSS_LABEL_BIG);
    label_venous_cervical->setStyleSheet(CSS_LABEL_BIG);
    label_csf_cervical->setStyleSheet(CSS_LABEL_BIG);

    label_arterial_cerebral->setStyleSheet(CSS_LABEL_BIG);
    label_venous_cerebral->setStyleSheet(CSS_LABEL_BIG);
    label_csf_cerebral->setStyleSheet(CSS_LABEL_BIG);
}

DialogFlowConstructor::DialogFlowConstructor(Coord **coords_arterial, Coord **coords_venous, Coord **coords_csf,
                                             QStringList *list_arterial, QStringList *list_venous, QStringList *list_csf,
                                             Coord *coord_arterial_cervical, Coord *coord_venous_cervical, Coord *coord_csf_cervical,
                                             QStringList *list_arterial_cervical, QStringList *list_venous_cervical, QStringList *list_csf_cervical,
                                             Coord *coord_arterial_cerebral, Coord *coord_venous_cerebral, Coord *coord_csf_cerebral,
                                             QStringList *list_arterial_cerebral, QStringList *list_venous_cerebral, QStringList *list_csf_cerebral,
                                             QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Address copy
    this->coords_arterial = coords_arterial;
    this->coords_venous = coords_venous;
    this->coords_csf = coords_csf;

    this->coord_arterial_cervical = coord_arterial_cervical;
    this->coord_venous_cervical = coord_venous_cervical;
    this->coord_csf_cervical = coord_csf_cervical;
    this->coord_arterial_cerebral = coord_arterial_cerebral;
    this->coord_venous_cerebral = coord_venous_cerebral;
    this->coord_csf_cerebral = coord_csf_cerebral;

    this->list_arterial = list_arterial;
    this->list_venous = list_venous;
    this->list_csf = list_csf;

    this->list_arterial_cervical = list_arterial_cervical;
    this->list_venous_cervical = list_venous_cervical;
    this->list_csf_cervical = list_csf_cervical;

    this->list_arterial_cerebral = list_arterial_cerebral;
    this->list_venous_cerebral = list_venous_cerebral;
    this->list_csf_cerebral = list_csf_cerebral;

    init_var();
    init_win();
    init_sig();
    init_css();
}

void DialogFlowConstructor::valid(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int nbp = coords_arterial[0]->size();

    coord_arterial_cervical->set_size(nbp);
    coord_venous_cervical->set_size(nbp);
    coord_csf_cervical->set_size(nbp);
    coord_arterial_cerebral->set_size(nbp);
    coord_venous_cerebral->set_size(nbp);
    coord_csf_cerebral->set_size(nbp);

    QString cervical_file_name = EMPTY_STRING;
    QString cerebral_file_name = EMPTY_STRING;
    QString cervical_quality = EMPTY_STRING;
    QString cerebral_quality = EMPTY_STRING;
    for (int i = 0; i < n_arterial; i++){
        if (checks_arterial_cervical[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_arterial_cervical->set_coord(coords_arterial[i]->coord(j, XCOORD), j, XCOORD);
                coord_arterial_cervical->set_coord(coord_arterial_cervical->coord(j, YCOORD) + coords_arterial[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cervical_file_name.isEmpty()){
                cervical_file_name = list_arterial->at(2*i);
            }
            else{
                cervical_file_name = cervical_file_name + DIALOG_FLOW_PLUS + list_arterial->at(2*i);
            }
            //Quality
            if (cervical_quality.isEmpty()){
                cervical_quality = list_arterial->at(2*i+1);
            }
            else{
                int previous_quality = cervical_quality.toInt();
                int current_quality = list_arterial->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cervical_quality = list_arterial->at(2*i+1);
                }
            }
        }
        if (checks_arterial_cerebral[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_arterial_cerebral->set_coord(coords_arterial[i]->coord(j, XCOORD), j, XCOORD);
                coord_arterial_cerebral->set_coord(coord_arterial_cerebral->coord(j, YCOORD) + coords_arterial[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cerebral_file_name.isEmpty()){
                cerebral_file_name = list_arterial->at(2*i);
            }
            else{
                cerebral_file_name = cerebral_file_name + DIALOG_FLOW_PLUS + list_arterial->at(2*i);
            }
            //Quality
            if (cerebral_quality.isEmpty()){
                cerebral_quality = list_arterial->at(2*i+1);
            }
            else{
                int previous_quality = cerebral_quality.toInt();
                int current_quality = list_arterial->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cerebral_quality = list_arterial->at(2*i+1);
                }
            }
        }
    }
    list_arterial_cervical->append(cervical_file_name);
    list_arterial_cervical->append(cervical_quality);
    list_arterial_cerebral->append(cerebral_file_name);
    list_arterial_cerebral->append(cerebral_quality);

    cervical_file_name = EMPTY_STRING;
    cerebral_file_name = EMPTY_STRING;
    cervical_quality = EMPTY_STRING;
    cerebral_quality = EMPTY_STRING;
    for (int i = 0; i < n_venous; i++){
        if (checks_venous_cervical[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_venous_cervical->set_coord(coords_venous[i]->coord(j, XCOORD), j, XCOORD);
                coord_venous_cervical->set_coord(coord_venous_cervical->coord(j, YCOORD) + coords_venous[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cervical_file_name.isEmpty()){
                cervical_file_name = list_venous->at(2*i);
            }
            else{
                cervical_file_name = cervical_file_name + DIALOG_FLOW_PLUS + list_venous->at(2*i);
            }
            //Quality
            if (cervical_quality.isEmpty()){
                cervical_quality = list_venous->at(2*i+1);
            }
            else{
                int previous_quality = cervical_quality.toInt();
                int current_quality = list_venous->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cervical_quality = list_venous->at(2*i+1);
                }
            }
        }
        if (checks_venous_cerebral[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_venous_cerebral->set_coord(coords_venous[i]->coord(j, XCOORD), j, XCOORD);
                coord_venous_cerebral->set_coord(coord_venous_cerebral->coord(j, YCOORD) + coords_venous[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cerebral_file_name.isEmpty()){
                cerebral_file_name = list_venous->at(2*i);
            }
            else{
                cerebral_file_name = cerebral_file_name + DIALOG_FLOW_PLUS + list_venous->at(2*i);
            }
            //Quality
            if (cerebral_quality.isEmpty()){
                cerebral_quality = list_venous->at(2*i+1);
            }
            else{
                int previous_quality = cerebral_quality.toInt();
                int current_quality = list_venous->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cerebral_quality = list_venous->at(2*i+1);
                }
            }
        }
    }
    list_venous_cervical->append(cervical_file_name);
    list_venous_cervical->append(cervical_quality);
    list_venous_cerebral->append(cerebral_file_name);
    list_venous_cerebral->append(cerebral_quality);

    cervical_file_name = EMPTY_STRING;
    cerebral_file_name = EMPTY_STRING;
    cervical_quality = EMPTY_STRING;
    cerebral_quality = EMPTY_STRING;
    for (int i = 0; i < n_csf; i++){
        if (checks_csf_cervical[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_csf_cervical->set_coord(coords_csf[i]->coord(j, XCOORD), j, XCOORD);
                coord_csf_cervical->set_coord(coord_csf_cervical->coord(j, YCOORD) + coords_csf[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cervical_file_name.isEmpty()){
                cervical_file_name = list_csf->at(2*i);
            }
            else{
                cervical_file_name = cervical_file_name + DIALOG_FLOW_PLUS + list_csf->at(2*i);
            }
            //Quality
            if (cervical_quality.isEmpty()){
                cervical_quality = list_csf->at(2*i+1);
            }
            else{
                int previous_quality = cervical_quality.toInt();
                int current_quality = list_csf->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cervical_quality = list_csf->at(2*i+1);
                }
            }
        }
        if (checks_csf_cerebral[i].isChecked()){
            //Coord
            for (int j = 0; j < nbp; j++){
                coord_csf_cerebral->set_coord(coords_csf[i]->coord(j, XCOORD), j, XCOORD);
                coord_csf_cerebral->set_coord(coord_csf_cerebral->coord(j, YCOORD) + coords_csf[i]->coord(j, YCOORD), j, YCOORD);
            }
            //File name
            if (cerebral_file_name.isEmpty()){
                cerebral_file_name = list_csf->at(2*i);
            }
            else{
                cerebral_file_name = cerebral_file_name + DIALOG_FLOW_PLUS + list_csf->at(2*i);
            }
            //Quality
            if (cerebral_quality.isEmpty()){
                cerebral_quality = list_csf->at(2*i+1);
            }
            else{
                int previous_quality = cerebral_quality.toInt();
                int current_quality = list_csf->at(2*i+1).toInt();
                if (current_quality < previous_quality){
                    cerebral_quality = list_csf->at(2*i+1);
                }
            }
        }
    }
    list_csf_cervical->append(cervical_file_name);
    list_csf_cervical->append(cervical_quality);
    list_csf_cerebral->append(cerebral_file_name);
    list_csf_cerebral->append(cerebral_quality);

    delete_all();
    accept();
}

void DialogFlowConstructor::cancel(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    delete_all();
    reject();
}

void DialogFlowConstructor::delete_all(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (labels_arterial_cervical != NULL) delete[] labels_arterial_cervical; labels_arterial_cervical = NULL;
    if (labels_venous_cervical != NULL) delete[] labels_venous_cervical; labels_venous_cervical = NULL;
    if (labels_csf_cervical != NULL) delete[] labels_csf_cervical; labels_csf_cervical = NULL;
    if (labels_arterial_cerebral != NULL) delete[] labels_arterial_cerebral; labels_arterial_cerebral = NULL;
    if (labels_venous_cerebral != NULL) delete[] labels_venous_cerebral; labels_venous_cerebral = NULL;
    if (labels_csf_cerebral != NULL) delete[] labels_csf_cerebral; labels_csf_cerebral = NULL;

    if (checks_arterial_cervical != NULL) delete[] checks_arterial_cervical; checks_arterial_cervical = NULL;
    if (checks_venous_cervical != NULL) delete[] checks_venous_cervical; checks_venous_cervical = NULL;
    if (checks_csf_cervical != NULL) delete[] checks_csf_cervical; checks_csf_cervical = NULL;
    if (checks_arterial_cerebral != NULL) delete[] checks_arterial_cerebral; checks_arterial_cerebral = NULL;
    if (checks_venous_cerebral != NULL) delete[] checks_venous_cerebral; checks_venous_cerebral = NULL;
    if (checks_csf_cerebral != NULL) delete[] checks_csf_cerebral; checks_csf_cerebral = NULL;
}

void DialogFlowConstructor::closeEvent(QCloseEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    delete_all();
}


