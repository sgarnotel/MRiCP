#ifndef DIALOGFLOWEPI_H
#define DIALOGFLOWEPI_H

#include "headers.hpp"

#include "TextDef__Flow.h"

#define MAX_QUALITY     (int)5

/*!
 * \brief The DialogFlowEPI class
 *
 * This class contains the dialog box for load files from Flow Analysis software
 */
class DialogFlowEPI : public QDialog
{
    Q_OBJECT
public:
    explicit DialogFlowEPI(QString dir, QStringList *informations,
                        Coord **coords_arterial, QStringList *list_arterial,
                        Coord **coords_venous, QStringList *list_venous,
                        Coord **coords_csf, QStringList *list_csf,
                        QWidget *parent = 0);

signals:

private slots:
    bool load_flow_data(QString file, int *quality, Coord *data);
    QStringList load_flow_informations(QString file_name, bool *res=NULL);

    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void cancel();
    void load();
    void set_label_qualitycolor(QLabel *label, int quality);
    void valid();

    void delete_all();
    void closeEvent(QCloseEvent *);

private:
    //Grid
    QGridLayout * grid;

    //HBox
    QHBoxLayout *hbox_title;
    QHBoxLayout *hbox_button;

    //Label
    QLabel *label_title;
    QLabel *label_title_img;

    QLabel *label_arterial;
    QLabel *label_venous;
    QLabel *label_csf;
    QLabel *label_constructor;

    QLabel *labels_arterial;
    QLabel *labels_venous;
    QLabel *labels_csf;

    QLabel *labels_arterial_quality;
    QLabel *labels_venous_quality;
    QLabel *labels_csf_quality;

    //Radio
    QRadioButton *radio_constructor1;
    QRadioButton *radio_constructor2;
    QRadioButton *radio_constructor3;
    QRadioButton *radio_constructor4;
    QRadioButton *radio_constructor5;

    //CheckBox
    QCheckBox *checks_arterial;
    QCheckBox *checks_venous;
    QCheckBox *checks_csf;

    //Button
    QPushButton *button_cancel;
    QPushButton *button_load;
    QPushButton *button_valid;

    //String
    QString dir;
    QString patient_name;
    QString exam_number;
    QString exam_date;
    QString patient_date;
    QString patient_age;
    QString patient_sexe;
    QString MRI_constructor;

    QStringList *files_arterial;
    QStringList *files_venous;
    QStringList *files_csf;

    QStringList *informations;
    QStringList *list_arterial;
    QStringList *list_venous;
    QStringList *list_csf;

    //Coord
    Coord **coords_arterial;
    Coord **coords_venous;
    Coord **coords_csf;
};

#endif // DIALOGFLOWEPI_H
