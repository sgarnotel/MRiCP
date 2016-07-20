#include "dialogsettings.h"

/*!
 * \brief DialogSettings::init_var
 *
 * Initialisation of DialogSettings variables
 */
void DialogSettings::init_var()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;
    grid_path = new QGridLayout;
    grid_unity = new QGridLayout;
    grid_npi = new QGridLayout;
    grid_coeff = new QGridLayout;

    //Buttons
    button_close = new QPushButton(this);
    button_apply = new QPushButton(this);

    //Labels
    label_title = new QLabel(this);
    label_title_img = new QLabel(this);

    label_flow_path = new QLabel(this);
    label_pcmri_length = new QLabel(this);
    label_data_path = new QLabel(this);
    label_results_path = new QLabel(this);

    label_choose_MRI_time_unity = new QLabel(this);
    label_choose_MRI_flow_unity = new QLabel(this);
    label_choose_MRI_volume_unity = new QLabel(this);
    label_choose_ICP_time_unity = new QLabel(this);
    label_choose_ICP_pressure_unity = new QLabel(this);

    label_choose_npi = new QLabel(this);

    label_coeff_systole_threshold = new QLabel(this);
    label_coeff_systole_delay = new QLabel(this);
    label_coeff_fourier_min = new QLabel(this);
    label_coeff_fourier_max = new QLabel(this);
    label_coeff_ifft_min = new QLabel(this);
    label_coeff_ifft_max = new QLabel(this);

    label_warning = new QLabel(this);

    //LineEdit
    line_flow_path = new QLineEdit(this);
    line_data_path = new QLineEdit(this);
    line_results_path = new QLineEdit(this);

    //Boxes
    box_pcmri_length = new QSpinBox(this);

    box_MRI_time_unity = new QComboBox(this);
    box_MRI_flow_unity = new QComboBox(this);
    box_MRI_volume_unity = new QComboBox(this);
    box_ICP_time_unity = new QComboBox(this);
    box_ICP_pressure_unity = new QComboBox(this);

    box_npi = new QSpinBox(this);

    box_coeff_systole_threshold = new QDoubleSpinBox(this);
    box_coeff_systole_delay = new QDoubleSpinBox(this);
    box_coeff_fourier_min = new QDoubleSpinBox(this);
    box_coeff_fourier_max = new QDoubleSpinBox(this);
    box_coeff_ifft_min = new QDoubleSpinBox(this);
    box_coeff_ifft_max = new QDoubleSpinBox(this);

}

/*!
 * \brief DialogSettings::init_win
 *
 * Initialisation of DialogSettings window
 */
void DialogSettings::init_win()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Window
    setWindowTitle(DIALOG_SETTINGS_TXT_TITLE1);

    //Grid
    setLayout(grid);

    //Buttons
    button_close->setText(DIALOG_SETTINGS_TXT_CLOSE);
    button_apply->setText(DIALOG_SETTINGS_TXT_APPLY);

    //Labels
    label_title->setText(DIALOG_SETTINGS_TXT_TITLE2);
    label_title_img->setPixmap(QPixmap(IMG_SETTINGS).scaled(DIALOG_SETTINGS_IMG_SIZE, DIALOG_SETTINGS_IMG_SIZE));

    label_flow_path->setText(DIALOG_SETTINGS_FLOW_DIR);
    label_pcmri_length->setText(DIALOG_SETTINGS_TXT_PCMRI);
    label_data_path->setText(DIALOG_SETTINGS_DATA_DIR);
    label_results_path->setText(DIALOG_SETTINGS_RESULTS_DIR);

    label_choose_MRI_time_unity->setText(DIALOG_SETTINGS_TXT_MRI_T);
    label_choose_MRI_flow_unity->setText(DIALOG_SETTINGS_TXT_MRI_F);
    label_choose_MRI_volume_unity->setText(DIALOG_SETTINGS_TXT_MRI_V);
    label_choose_ICP_time_unity->setText(DIALOG_SETTINGS_TXT_ICP_T);
    label_choose_ICP_pressure_unity->setText(DIALOG_SETTINGS_TXT_ICP_P);

    label_choose_npi->setText(DIALOG_SETTINGS_TXT_NPI);

    label_coeff_systole_threshold->setText(DIALOG_SETTINGS_TXT_STHRES);
    label_coeff_systole_delay->setText(DIALOG_SETTINGS_TXT_SDELAY);
    label_coeff_fourier_min->setText(DIALOG_SETTINGS_TXT_FMIN);
    label_coeff_fourier_max->setText(DIALOG_SETTINGS_TXT_FMAX);
    label_coeff_ifft_min->setText(DIALOG_SETTINGS_TXT_IMIN);
    label_coeff_ifft_max->setText(DIALOG_SETTINGS_TXT_IMAX);

    label_warning->setText(DIALOG_SETTINGS_TXT_WARNING);

    //LineEdit
    line_flow_path->setText(EMPTY_STRING);
    line_data_path->setText(EMPTY_STRING);
    line_results_path->setText(EMPTY_STRING);

    //Boxes
    box_pcmri_length->setRange(DIALOG_SETTINGS_NPI_MIN, DIALOG_SETTINGS_NPI_MAX);

    box_MRI_time_unity->addItem(UNITY_S);
    box_MRI_time_unity->addItem(UNITY_MIN);

    box_MRI_flow_unity->addItem(UNITY_MM3_S);
    box_MRI_flow_unity->addItem(UNITY_MM3_MIN);
    box_MRI_flow_unity->addItem(UNITY_ML_S);
    box_MRI_flow_unity->addItem(UNITY_ML_MIN);

    box_MRI_volume_unity->addItem(UNITY_MM3);
    box_MRI_volume_unity->addItem(UNITY_ML);

    box_ICP_time_unity->addItem(DIALOG_SETTINGS_MS);
    box_ICP_time_unity->addItem(DIALOG_SETTINGS_S);
    box_ICP_time_unity->addItem(DIALOG_SETTINGS_MIN);
    box_ICP_time_unity->setEnabled(false);

    box_ICP_pressure_unity->addItem(DIALOG_SETTINGS_MMHG);
    box_ICP_pressure_unity->addItem(DIALOG_SETTINGS_MPA);
    box_ICP_pressure_unity->setEnabled(false);

    box_npi->setRange(DIALOG_SETTINGS_NPI_MIN, DIALOG_SETTINGS_NPI_MAX);

    box_coeff_systole_threshold->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_systole_threshold->setDecimals(DIALOG_SETTINGS_DECIMALS);

    box_coeff_systole_delay->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_systole_delay->setDecimals(DIALOG_SETTINGS_DECIMALS);

    box_coeff_fourier_min->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_fourier_min->setDecimals(DIALOG_SETTINGS_DECIMALS);

    box_coeff_fourier_max->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_fourier_max->setDecimals(DIALOG_SETTINGS_DECIMALS);

    box_coeff_ifft_min->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_ifft_min->setDecimals(DIALOG_SETTINGS_DECIMALS);

    box_coeff_ifft_max->setRange(DIALOG_SETTINGS_COEFF_MIN, DIALOG_SETTINGS_COEFF_MAX);
    box_coeff_ifft_max->setDecimals(DIALOG_SETTINGS_DECIMALS);

    //Grid
    grid_path->addWidget(label_flow_path, 0, 0, 1, 1);
    grid_path->addWidget(line_flow_path, 0, 1, 1, 1);
    grid_path->addWidget(label_pcmri_length, 1, 0, 1, 1);
    grid_path->addWidget(box_pcmri_length, 1, 1, 1, 1);
    grid_path->addWidget(label_data_path, 2, 0, 1, 1);
    grid_path->addWidget(line_data_path, 2, 1, 1, 1);
    grid_path->addWidget(label_results_path, 3, 0, 1, 1);
    grid_path->addWidget(line_results_path, 3, 1, 1, 1);

    grid_unity->addWidget(label_choose_MRI_time_unity, 0, 0, 1, 1);
    grid_unity->addWidget(box_MRI_time_unity, 0, 1, 1, 1);
    grid_unity->addWidget(label_choose_MRI_flow_unity, 1, 0, 1, 1);
    grid_unity->addWidget(box_MRI_flow_unity, 1, 1, 1, 1);
    grid_unity->addWidget(label_choose_MRI_volume_unity, 2, 0, 1, 1);
    grid_unity->addWidget(box_MRI_volume_unity, 2, 1, 1, 1);
    grid_unity->addWidget(label_choose_ICP_time_unity, 3, 0, 1, 1);
    grid_unity->addWidget(box_ICP_time_unity, 3, 1, 1, 1);
    grid_unity->addWidget(label_choose_ICP_pressure_unity, 4, 0, 1, 1);
    grid_unity->addWidget(box_ICP_pressure_unity, 4, 1, 1, 1);

    grid_npi->addWidget(label_choose_npi, 0, 0, 1, 1);
    grid_npi->addWidget(box_npi, 0, 1, 1, 1);


    grid_coeff->addWidget(label_coeff_systole_threshold, 0, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_systole_threshold, 0, 1, 1, 1);
    grid_coeff->addWidget(label_coeff_systole_delay, 1, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_systole_delay, 1, 1, 1, 1);
    grid_coeff->addWidget(label_coeff_fourier_min, 2, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_fourier_min, 2, 1, 1, 1);
    grid_coeff->addWidget(label_coeff_fourier_max, 3, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_fourier_max, 3, 1, 1, 1);
    grid_coeff->addWidget(label_coeff_ifft_min, 4, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_ifft_min, 4, 1, 1, 1);
    grid_coeff->addWidget(label_coeff_ifft_max, 5, 0, 1, 1);
    grid_coeff->addWidget(box_coeff_ifft_max, 5, 1, 1, 1);


    grid->addWidget(label_title_img, 0, 0, 1, 1);
    grid->addWidget(label_title, 0, 1, 1, 1);
    grid->addLayout(grid_path, 1, 0, 1, 2);
    grid->addLayout(grid_unity, 2, 0, 1, 2);
    grid->addLayout(grid_npi, 3, 0, 1, 2);
    grid->addLayout(grid_coeff, 4, 0, 1, 2);
    grid->addWidget(label_warning, 11, 0, 1, 2);
    grid->addWidget(button_apply, 12, 0, 1, 1);
    grid->addWidget(button_close, 12, 1, 1, 1);
}

/*!
 * \brief DialogSettings::init_sig
 *
 * Initialisation of DialogSettings signals
 */
void DialogSettings::init_sig()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_close, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_apply, SIGNAL(clicked()), this, SLOT(apply()));
}

/*!
 * \brief DialogSettings::init_css
 *
 * Initialisation of DialogSettings style sheet
 */
void DialogSettings::init_css()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    setStyleSheet(CSS_DIALOG);

    button_close->setStyleSheet(CSS_BUTTON);
    button_apply->setStyleSheet(CSS_BUTTON);

    label_title->setStyleSheet(CSS_LABEL_TITLE);
    label_flow_path->setStyleSheet(CSS_LABEL_GLOBAL);
    label_pcmri_length->setStyleSheet(CSS_LABEL_GLOBAL);
    label_data_path->setStyleSheet(CSS_LABEL_GLOBAL);
    label_results_path->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_MRI_time_unity->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_MRI_flow_unity->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_MRI_volume_unity->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_ICP_time_unity->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_ICP_pressure_unity->setStyleSheet(CSS_LABEL_GLOBAL);
    label_choose_npi->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_systole_threshold->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_systole_delay->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_fourier_min->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_fourier_max->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_ifft_min->setStyleSheet(CSS_LABEL_GLOBAL);
    label_coeff_ifft_max->setStyleSheet(CSS_LABEL_GLOBAL);
    label_warning->setStyleSheet(CSS_LABEL_WARNING);

    box_pcmri_length->setStyleSheet(CSS_SPINBOX);
    box_MRI_time_unity->setStyleSheet(CSS_COMBOBOX);
    box_MRI_flow_unity->setStyleSheet(CSS_COMBOBOX);
    box_MRI_volume_unity->setStyleSheet(CSS_COMBOBOX);
    box_ICP_time_unity->setStyleSheet(CSS_COMBOBOX);
    box_ICP_pressure_unity->setStyleSheet(CSS_COMBOBOX);
    box_npi->setStyleSheet(CSS_SPINBOX);
    box_coeff_systole_threshold->setStyleSheet(CSS_DSPINBOX);
    box_coeff_systole_delay->setStyleSheet(CSS_DSPINBOX);
    box_coeff_fourier_min->setStyleSheet(CSS_DSPINBOX);
    box_coeff_fourier_max->setStyleSheet(CSS_DSPINBOX);
    box_coeff_ifft_min->setStyleSheet(CSS_DSPINBOX);
    box_coeff_ifft_max->setStyleSheet(CSS_DSPINBOX);
}

/*!
 * \brief DialogSettings::init_settings
 *
 * Initialisation of DialogSettings settings values
 */
void DialogSettings::init_settings()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res;

    //Directories
    QStringList *directories = new QStringList;
    res = get_directories(directories);
    if (res){
        line_flow_path->setText(directories->at(0));
        if (directories->at(1).isEmpty()){
            line_data_path->setText(DATA_DIR);
        }
        else{
            line_data_path->setText(directories->at(1));
        }
        if (directories->at(2).isEmpty()){
            line_results_path->setText(PROCESSED_DIR);
        }
        else{
            line_results_path->setText(directories->at(2));
        }
    }

    string *unities = new string[UNITY_LENGTH];
    res = get_unities(unities);
    if (res){
#ifdef QT5
        box_MRI_time_unity->setCurrentText(QString::fromStdString(unities[0]));
        box_MRI_flow_unity->setCurrentText(QString::fromStdString(unities[1]));
        box_MRI_volume_unity->setCurrentText(QString::fromStdString(unities[2]));
        box_ICP_time_unity->setCurrentText(QString::fromStdString(unities[3]));
        box_ICP_pressure_unity->setCurrentText(QString::fromStdString(unities[4]));
#endif
    }
    delete[] unities;

    int npi;
    res = get_npi(&npi);
    if (res){
        box_npi->setValue(npi);
    }

    double *coeffs = new double[COEFFS_LENGTH];
    res = get_coeffs(coeffs);
    if (res){
        box_pcmri_length->setValue((int)coeffs[0]);
        box_coeff_systole_threshold->setValue(coeffs[1]);
        box_coeff_systole_delay->setValue(coeffs[2]);
        box_coeff_fourier_min->setValue(coeffs[3]);
        box_coeff_fourier_max->setValue(coeffs[4]);
        box_coeff_ifft_min->setValue(coeffs[5]);
        box_coeff_ifft_max->setValue(coeffs[6]);
    }
    delete[] coeffs;
}

/*!
 * \brief DialogSettings::DialogSettings
 * \param parent
 *
 * DialogSettings
 */
DialogSettings::DialogSettings(QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();

    init_settings();
}

/*!
 * \brief DialogSettings::close
 *
 * Close DialogSettings
 */
void DialogSettings::close()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    reject();
}

void DialogSettings::closeEvent(QCloseEvent *)
{
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;
}

/*!
 * \brief DialogSettings::apply
 *
 * Apply modifications of settings
 */
void DialogSettings::apply()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Save directories
    QStringList *directories = new QStringList;
    directories->append(line_flow_path->text());
    directories->append(line_data_path->text());
    directories->append(line_results_path->text());
    bool res0 = set_directories(directories);

    //Save unity
    string *unities = new string[UNITY_LENGTH];
    unities[0] = box_MRI_time_unity->currentText().toStdString();
    unities[1] = box_MRI_flow_unity->currentText().toStdString();
    unities[2] = box_MRI_volume_unity->currentText().toStdString();
    unities[3] = box_ICP_time_unity->currentText().toStdString();
    unities[4] = box_ICP_pressure_unity->currentText().toStdString();
    bool res1 = set_unities(unities);
    delete[] unities;

    //Save npi
    bool res2 = set_npi(box_npi->value());

    //Save coeffs
    double *coeffs = new double[COEFFS_LENGTH];
    coeffs[0] = (double)box_pcmri_length->value();
    coeffs[1] = box_coeff_systole_threshold->value();
    coeffs[2] = box_coeff_systole_delay->value();
    coeffs[3] = box_coeff_fourier_min->value();
    coeffs[4] = box_coeff_fourier_max->value();
    coeffs[5] = box_coeff_ifft_min->value();
    coeffs[6] = box_coeff_ifft_max->value();
    bool res3 = set_coeffs(coeffs);
    delete[] coeffs;

    //Result
    if (res0 && res1 && res2 && res3){
        accept();
    }
}


