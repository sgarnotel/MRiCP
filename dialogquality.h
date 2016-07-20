#ifndef DIALOGQUALITY_H
#define DIALOGQUALITY_H


#include "headers.hpp"
#include "TextDef__Quality.h"


class DialogQuality : public QDialog
{
    Q_OBJECT
public:
    explicit DialogQuality(QString current_dir, QString param, int *current_index, QStringList *current_names, QWidget *parent = 0);

signals:

public slots:

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void do_cancel();
    void do_valid();

private:
    //Grid
    QGridLayout *grid;

    //Label
    QLabel *label_title;
    QLabel *label_subtitle;

    QLabel *label_arterial;
    QLabel *label_venous;
    QLabel *label_csf;
    QLabel *label_ICP;

    //ComboBox
    QComboBox *box_arterial;
    QComboBox *box_venous;
    QComboBox *box_csf;
    QComboBox *box_ICP;

    //Button
    QPushButton *button_cancel;
    QPushButton *button_valid;

    //String
    QString current_dir;
    QString param;

    QStringList *current_names;

    //Int
    int *current_index;
    int arterial_quality;
    int venous_quality;
    int csf_quality;
    int ICP_quality;
};

#endif // DIALOGQUALITY_H
