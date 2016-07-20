#ifndef DIALOGFLOWCONSTRUCTOR_H
#define DIALOGFLOWCONSTRUCTOR_H

#include "headers.hpp"

#include "TextDef__Flow.h"

class DialogFlowConstructor : public QDialog
{
    Q_OBJECT
public:
    explicit DialogFlowConstructor(Coord **coords_arterial, Coord **coords_venous, Coord **coords_csf,
                                   QStringList *list_arterial, QStringList *list_venous, QStringList *list_csf,
                                   Coord *coord_arterial_cervical, Coord *coord_venous_cervical, Coord *coord_csf_cervical,
                                   QStringList *list_arterial_cervical, QStringList *list_venous_cervical, QStringList *list_csf_cervical,
                                   Coord *coord_arterial_cerebral, Coord *coord_venous_cerebral, Coord *coord_csf_cerebral,
                                   QStringList *list_arterial_cerebral, QStringList *list_venous_cerebral, QStringList *list_csf_cerebral,
                                   QWidget *parent = 0);

signals:

public slots:

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void cancel();
    void valid();

    void delete_all();
    void closeEvent(QCloseEvent *);

private:
    //Grid
    QGridLayout *grid;

    //HBox
    QHBoxLayout *hbox_title;
    QHBoxLayout *hbox_button;

    //Label
    QLabel *label_title;
    QLabel *label_title_img;

    QLabel *label_arterial_cervical;
    QLabel *label_venous_cervical;
    QLabel *label_csf_cervical;
    QLabel *label_arterial_cerebral;
    QLabel *label_venous_cerebral;
    QLabel *label_csf_cerebral;

    QLabel *labels_arterial_cervical;
    QLabel *labels_venous_cervical;
    QLabel *labels_csf_cervical;
    QLabel *labels_arterial_cerebral;
    QLabel *labels_venous_cerebral;
    QLabel *labels_csf_cerebral;

    //CheckBox
    QCheckBox *checks_arterial_cervical;
    QCheckBox *checks_venous_cervical;
    QCheckBox *checks_csf_cervical;
    QCheckBox *checks_arterial_cerebral;
    QCheckBox *checks_venous_cerebral;
    QCheckBox *checks_csf_cerebral;

    //Button
    QPushButton *button_cancel;
    QPushButton *button_valid;

    //String
    QStringList *list_arterial;
    QStringList *list_venous;
    QStringList *list_csf;

    QStringList *list_arterial_cervical;
    QStringList *list_venous_cervical;
    QStringList *list_csf_cervical;

    QStringList *list_arterial_cerebral;
    QStringList *list_venous_cerebral;
    QStringList *list_csf_cerebral;

    //Coord
    Coord **coords_arterial;
    Coord **coords_venous;
    Coord **coords_csf;

    Coord *coord_arterial_cervical;
    Coord *coord_venous_cervical;
    Coord *coord_csf_cervical;
    Coord *coord_arterial_cerebral;
    Coord *coord_venous_cerebral;
    Coord *coord_csf_cerebral;

    //Int
    int n_arterial;
    int n_venous;
    int n_csf;
};

#endif // DIALOGFLOWCONSTRUCTOR_H
