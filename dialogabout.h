#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include "headers.hpp"

class DialogAbout : public QDialog
{
    Q_OBJECT
public:
    explicit DialogAbout(QWidget *parent = 0);

signals:

public slots:
    void do_close();

private slots:
    //Init
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

private:
    //Grid
    QGridLayout *grid;

    //Label
    QLabel *label_title;
    QLabel *label_version;
    QLabel *label_date;
    QLabel *label_author;

    QLabel *label_Qt_img;
    QLabel *label_QCustomPlot_img;
    QLabel *label_Fftw3_img;
    QLabel *label_CrystalClear_Icons_img;
    QLabel *label_Doxygen_img;
    QLabel *label_Programmers_img;

    //Text
    QTextEdit *text_Qt;
    QTextEdit *text_QCustomPlot;
    QTextEdit *text_Fftw3;
    QTextEdit *text_CrystalClear_Icons;
    QTextEdit *text_Doxygen;
    QTextEdit *text_Programmers;

    //Button
    QPushButton *button_close;
};

#endif // DIALOGABOUT_H
