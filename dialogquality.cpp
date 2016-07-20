#include "dialogquality.h"


/*!
 * \brief DialogQuality::init_var
 */
void DialogQuality::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    //Label
    label_title = new QLabel(this);
    label_subtitle = new QLabel(this);

    label_arterial = new QLabel(this);
    label_venous = new QLabel(this);
    label_csf = new QLabel(this);
    label_ICP = new QLabel(this);

    //ComboBox
    box_arterial = new QComboBox(this);
    box_venous = new QComboBox(this);
    box_csf = new QComboBox(this);
    box_ICP = new QComboBox(this);

    //Button
    button_cancel = new QPushButton(this);
    button_valid = new QPushButton(this);

    //Int
    arterial_quality = 0;
    venous_quality = 0;
    csf_quality = 0;
    ICP_quality = 0;
}

/*!
 * \brief DialogQuality::init_win
 */
void DialogQuality::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Dialog
    setModal(true);

    //Int
    if (param.compare(DIALOG_QUALITY_PARAM1) == 0){
        arterial_quality = get_MRI_arterial_cervical_quality_source(current_dir).toInt();
        venous_quality = get_MRI_venous_cervical_quality_source(current_dir).toInt();
        csf_quality = get_MRI_csf_cervical_quality_source(current_dir).toInt();
    }
    else if (param.compare(DIALOG_QUALITY_PARAM2) == 0){
        arterial_quality = get_MRI_arterial_cerebral_quality_source(current_dir).toInt();
        venous_quality = get_MRI_venous_cerebral_quality_source(current_dir).toInt();
        csf_quality = get_MRI_csf_cerebral_quality_source(current_dir).toInt();
    }
    else if (param.compare(DIALOG_QUALITY_PARAM3) == 0){
        arterial_quality = get_MRI_arterial_other_quality_source(current_dir, current_index[0]).toInt();
        venous_quality = get_MRI_venous_other_quality_source(current_dir, current_index[1]).toInt();
        csf_quality = get_MRI_csf_other_quality_source(current_dir, current_index[2]).toInt();
    }
    else if (param.compare(DIALOG_QUALITY_PARAM4) == 0){
        ICP_quality = get_ICP_quality_source(current_dir).toInt();
    }
    //Correction
    if (arterial_quality == 0){
        arterial_quality = 6;
    }
    if (venous_quality == 0){
        venous_quality = 6;
    }
    if (csf_quality == 0){
        csf_quality = 6;
    }
    if (ICP_quality == 0){
        ICP_quality = 6;
    }

    //Button
    button_cancel->setText(DIALOG_QUALITY_CANCEL);
    button_valid->setText(DIALOG_QUALITY_VALID);

    //ComboBox
    box_arterial->addItem(DIALOG_QUALITY1);
    box_arterial->addItem(DIALOG_QUALITY2);
    box_arterial->addItem(DIALOG_QUALITY3);
    box_arterial->addItem(DIALOG_QUALITY4);
    box_arterial->addItem(DIALOG_QUALITY5);
    box_arterial->addItem(DIALOG_QUALITY6);
    box_arterial->setCurrentIndex(arterial_quality-1);

    box_venous->addItem(DIALOG_QUALITY1);
    box_venous->addItem(DIALOG_QUALITY2);
    box_venous->addItem(DIALOG_QUALITY3);
    box_venous->addItem(DIALOG_QUALITY4);
    box_venous->addItem(DIALOG_QUALITY5);
    box_venous->addItem(DIALOG_QUALITY6);
    box_venous->setCurrentIndex(venous_quality-1);

    box_csf->addItem(DIALOG_QUALITY1);
    box_csf->addItem(DIALOG_QUALITY2);
    box_csf->addItem(DIALOG_QUALITY3);
    box_csf->addItem(DIALOG_QUALITY4);
    box_csf->addItem(DIALOG_QUALITY5);
    box_csf->addItem(DIALOG_QUALITY6);
    box_csf->setCurrentIndex(csf_quality-1);

    box_ICP->addItem(DIALOG_QUALITY1);
    box_ICP->addItem(DIALOG_QUALITY2);
    box_ICP->addItem(DIALOG_QUALITY3);
    box_ICP->addItem(DIALOG_QUALITY4);
    box_ICP->addItem(DIALOG_QUALITY5);
    box_ICP->addItem(DIALOG_QUALITY6);
    box_ICP->setCurrentIndex(ICP_quality-1);

    //Label
    label_title->setText(DIALOG_QUALITY_TITLE);
    label_subtitle->setText(param);

    label_arterial->setText(DIALOG_QUALITY_ARTERIAL);
    label_venous->setText(DIALOG_QUALITY_VENOUS);
    label_csf->setText(DIALOG_QUALITY_CSF);
    label_ICP->setText(DIALOG_QUALITY_ICP);

    //Grid
    setLayout(grid);

    grid->addWidget(label_title, 0, 0, 1, 1);
    grid->addWidget(label_subtitle, 0, 1, 1, 1);

    if (param.compare(DIALOG_QUALITY_PARAM1) == 0 || param.compare(DIALOG_QUALITY_PARAM2) == 0 || param.compare(DIALOG_QUALITY_PARAM3) == 0){
        label_ICP->setHidden(true);
        box_ICP->setHidden(true);

        grid->addWidget(label_arterial, 10, 0, 1, 1);
        grid->addWidget(box_arterial, 10, 1, 1, 1);
        grid->addWidget(label_venous, 20, 0, 1, 1);
        grid->addWidget(box_venous, 20, 1, 1, 1);
        grid->addWidget(label_csf, 30, 0, 1, 1);
        grid->addWidget(box_csf, 30, 1, 1, 1);
    }
    else if (param.compare(DIALOG_QUALITY_PARAM4) == 0){
        label_arterial->setHidden(true);
        label_venous->setHidden(true);
        label_csf->setHidden(true);
        box_arterial->setHidden(true);
        box_venous->setHidden(true);
        box_csf->setHidden(true);

        grid->addWidget(label_ICP, 10, 0, 1, 1);
        grid->addWidget(box_ICP, 10, 1, 1, 1);
    }


    grid->addWidget(button_cancel, 40, 0, 1, 1);
    grid->addWidget(button_valid, 40, 1, 1, 1);
}

/*!
 * \brief DialogQuality::init_sig
 */
void DialogQuality::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(do_cancel()));
    connect(button_valid, SIGNAL(clicked()), this, SLOT(do_valid()));
}

/*!
 * \brief DialogQuality::init_css
 */
void DialogQuality::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Dialog
    setStyleSheet(CSS_DIALOG);

    //Label
    label_title->setStyleSheet(CSS_LABEL_TITLE);
    label_subtitle->setStyleSheet(CSS_LABEL_GLOBAL);

    label_arterial->setStyleSheet(CSS_LABEL_GLOBAL);
    label_venous->setStyleSheet(CSS_LABEL_GLOBAL);
    label_csf->setStyleSheet(CSS_LABEL_GLOBAL);

    //ComboBox
    box_arterial->setStyleSheet(CSS_COMBOBOX);
    box_venous->setStyleSheet(CSS_COMBOBOX);
    box_csf->setStyleSheet(CSS_COMBOBOX);

    //Button
    button_cancel->setStyleSheet(CSS_BUTTON);
    button_valid->setStyleSheet(CSS_BUTTON);
}

/*!
 * \brief DialogQuality::DialogQuality
 * \param param
 * \param parent
 */
DialogQuality::DialogQuality(QString current_dir, QString param, int *current_index, QStringList *current_names, QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    this->current_dir = current_dir;
    this->param = param;

    this->current_index = current_index;

    this->current_names = current_names;

    init_var();
    init_win();
    init_sig();
    init_css();
}

/*!
 * \brief DialogQuality::do_cancel
 */
void DialogQuality::do_cancel(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    reject();
}

/*!
 * \brief DialogQuality::do_valid
 */
void DialogQuality::do_valid(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Save qualities
    if (param.compare(DIALOG_QUALITY_PARAM1) == 0){
        arterial_quality = box_arterial->currentIndex() + 1;
        QString txt = QString::number(arterial_quality);
        set_MRI_arterial_cervical_quality_source(current_dir, txt);

        venous_quality = box_venous->currentIndex() + 1;
        txt = QString::number(venous_quality);
        set_MRI_venous_cervical_quality_source(current_dir, txt);

        csf_quality = box_csf->currentIndex() + 1;
        txt = QString::number(csf_quality);
        set_MRI_csf_cervical_quality_source(current_dir, txt);
    }
    else if (param.compare(DIALOG_QUALITY_PARAM2) == 0){
        arterial_quality = box_arterial->currentIndex() + 1;
        QString txt = QString::number(arterial_quality);
        set_MRI_arterial_cerebral_quality_source(current_dir, txt);

        venous_quality = box_venous->currentIndex() + 1;
        txt = QString::number(venous_quality);
        set_MRI_venous_cerebral_quality_source(current_dir, txt);

        csf_quality = box_csf->currentIndex() + 1;
        txt = QString::number(csf_quality);
        set_MRI_csf_cerebral_quality_source(current_dir, txt);
    }
    else if (param.compare(DIALOG_QUALITY_PARAM3) == 0){
        arterial_quality = box_arterial->currentIndex() + 1;
        QString txt = current_names->at(0) + "\t" + QString::number(arterial_quality) + "\r\n";
        set_MRI_arterial_other_quality_source(current_dir, current_index[0], txt);

        venous_quality = box_venous->currentIndex() + 1;
        txt = current_names->at(1) + "\t" + QString::number(venous_quality) + "\r\n";
        set_MRI_venous_other_quality_source(current_dir, current_index[1], txt);

        csf_quality = box_csf->currentIndex() + 1;
        txt = current_names->at(2) + "\t" + QString::number(csf_quality) + "\r\n";
        set_MRI_csf_other_quality_source(current_dir, current_index[2], txt);
    }
    else if (param.compare(DIALOG_QUALITY_PARAM4) == 0){
        ICP_quality = box_ICP->currentIndex() + 1;
        QString txt = QString::number(ICP_quality);
        set_ICP_quality_source(current_dir, txt);
    }

    accept();
}


