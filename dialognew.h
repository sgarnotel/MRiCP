#ifndef DIALOGNEW_H
#define DIALOGNEW_H

#include "headers.hpp"
#include "dialogflow.h"
#include "dialogflowepi.h"
#include "dialogflowconstructor.h"
#include "dialogflowconstructorepi.h"

#include "TextDef__New.h"


/*!
 * \brief The DialogNew class
 *
 * This class contains dialog box for add a patient.
 */
class DialogNew : public QDialog
{
    Q_OBJECT
public:
    explicit DialogNew(QWidget *parent=0);

signals:

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void load_MRI();
    void load_ICP();
    void load_EPI();

    void cancel();
    void valid();

    void delete_all();
    void closeEvent(QCloseEvent *);

private:
    //Grid
    QGridLayout *grid;

    //Line
    QLineEdit *line_patient;
    QLineEdit *line_MRI;
    QLineEdit *line_ICP;
    QLineEdit *line_EPI;

    //Label
    QLabel *label_title;
    QLabel *label_title_img;
    QLabel *label_patient;
    QLabel *label_MRI;
    QLabel *label_ICP;
    QLabel *label_EPI;

    //Button
    QPushButton *button_load_MRI;
    QPushButton *button_load_ICP;
    QPushButton *button_load_EPI;

    QPushButton *button_cancel;
    QPushButton *button_valid;

    //Coord
    Coord **coords_MRI_arterial;
    Coord **coords_MRI_venous;
    Coord **coords_MRI_csf;
    Coord *coord_MRI_arterial_cervical;
    Coord *coord_MRI_venous_cervical;
    Coord *coord_MRI_csf_cervical;
    Coord *coord_MRI_arterial_cerebral;
    Coord *coord_MRI_venous_cerebral;
    Coord *coord_MRI_csf_cerebral;

    Coord *coord_ICP;

    Coord **coords_EPI_arterial;
    Coord **coords_EPI_venous;
    Coord **coords_EPI_csf;
    Coord *coord_EPI_arterial_cervical;
    Coord *coord_EPI_venous_cervical;
    Coord *coord_EPI_csf_cervical;
    Coord *coord_EPI_arterial_cerebral;
    Coord *coord_EPI_venous_cerebral;
    Coord *coord_EPI_csf_cerebral;

    //String
    QString dir;

    QStringList *list_MRI_informations;
    QStringList *list_MRI_arterial;
    QStringList *list_MRI_venous;
    QStringList *list_MRI_csf;

    QStringList *list_MRI_arterial_cervical;
    QStringList *list_MRI_venous_cervical;
    QStringList *list_MRI_csf_cervical;
    QStringList *list_MRI_arterial_cerebral;
    QStringList *list_MRI_venous_cerebral;
    QStringList *list_MRI_csf_cerebral;

    QStringList *list_EPI_informations;
    QStringList *list_EPI_arterial;
    QStringList *list_EPI_venous;
    QStringList *list_EPI_csf;

    QStringList *list_EPI_arterial_cervical;
    QStringList *list_EPI_venous_cervical;
    QStringList *list_EPI_csf_cervical;
    QStringList *list_EPI_arterial_cerebral;
    QStringList *list_EPI_venous_cerebral;
    QStringList *list_EPI_csf_cerebral;
};

#endif // DIALOGNEW_H
