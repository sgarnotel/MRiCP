#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H


#include "headers.hpp"
#include "TextDef__Delete.h"


class DialogDelete : public QDialog
{
    Q_OBJECT
public:
    explicit DialogDelete(QWidget *parent = 0);

private slots:
    virtual void closeEvent(QCloseEvent *);

    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void load_patients();
    void load_patients(QString dir_tmp);
    void delete_patient();
    void update();

    void quit();

private:
    //Grid
    QGridLayout *grid;

    //List
    QListWidget *patient_list;

    //Button
    QPushButton *button_load;
    QPushButton *button_delete;
    QPushButton *button_quit;

    //String
    QString dir;
};

#endif // DIALOGDELETE_H
