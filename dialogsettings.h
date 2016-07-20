#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H


#include "headers.hpp"
#include "TextDef__Settings.h"


/*!
 * \brief The DialogSettings class
 *
 * This class contains dialog box for modify settings.
 */
class DialogSettings : public QDialog
{
    Q_OBJECT
public:
    explicit DialogSettings(QWidget *parent = 0);

signals:

private slots:
    void closeEvent(QCloseEvent *);

    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void init_settings();

    void close();
    void apply();

private:
    //Grid
    QGridLayout *grid;
    QGridLayout *grid_path;
    QGridLayout *grid_unity;
    QGridLayout *grid_npi;
    QGridLayout *grid_coeff;

    //Buttons
    QPushButton *button_close;
    QPushButton *button_apply;

    //Labels
    QLabel *label_title;
    QLabel *label_title_img;

    QLabel *label_flow_path;
    QLabel *label_pcmri_length;
    QLabel *label_data_path;
    QLabel *label_results_path;

    QLabel *label_choose_MRI_time_unity;
    QLabel *label_choose_MRI_flow_unity;
    QLabel *label_choose_MRI_volume_unity;
    QLabel *label_choose_ICP_time_unity;
    QLabel *label_choose_ICP_pressure_unity;

    QLabel *label_choose_npi;

    QLabel *label_coeff_systole_threshold;
    QLabel *label_coeff_systole_delay;
    QLabel *label_coeff_fourier_min;
    QLabel *label_coeff_fourier_max;
    QLabel *label_coeff_ifft_min;
    QLabel *label_coeff_ifft_max;

    QLabel *label_warning;

    //Line
    QLineEdit *line_flow_path;
    QLineEdit *line_data_path;
    QLineEdit *line_results_path;

    //Boxes
    QSpinBox *box_pcmri_length;

    QComboBox *box_MRI_time_unity;
    QComboBox *box_MRI_flow_unity;
    QComboBox *box_MRI_volume_unity;
    QComboBox *box_ICP_time_unity;
    QComboBox *box_ICP_pressure_unity;

    QSpinBox *box_npi;

    QDoubleSpinBox *box_coeff_systole_threshold;
    QDoubleSpinBox *box_coeff_systole_delay;
    QDoubleSpinBox *box_coeff_fourier_min;
    QDoubleSpinBox *box_coeff_fourier_max;
    QDoubleSpinBox *box_coeff_ifft_min;
    QDoubleSpinBox *box_coeff_ifft_max;
};

#endif // DIALOGSETTINGS_H
