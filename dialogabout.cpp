#include "dialogabout.h"

/*!
 * \brief DialogAbout::init_var
 */
void DialogAbout::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout(this);

    //Label
    label_title = new QLabel(this);
    label_version = new QLabel(this);
    label_date = new QLabel(this);
    label_author = new QLabel(this);

    label_Qt_img = new QLabel(this);
    label_QCustomPlot_img = new QLabel(this);
    label_Fftw3_img = new QLabel(this);
    label_CrystalClear_Icons_img = new QLabel(this);
    label_Doxygen_img = new QLabel(this);
    label_Programmers_img = new QLabel(this);

    //Text
    text_Qt = new QTextEdit(this);
    text_QCustomPlot = new QTextEdit(this);
    text_Fftw3 = new QTextEdit(this);
    text_CrystalClear_Icons = new QTextEdit(this);
    text_Doxygen = new QTextEdit(this);
    text_Programmers = new QTextEdit(this);

    //Button
    button_close = new QPushButton(this);
}

/*!
 * \brief DialogAbout::init_win
 */
void DialogAbout::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Button
    button_close->setText("Close");

    //Text
    text_Qt->setReadOnly(true);
    text_QCustomPlot->setReadOnly(true);
    text_Fftw3->setReadOnly(true);
    text_CrystalClear_Icons->setReadOnly(true);
    text_Doxygen->setReadOnly(true);
    text_Programmers->setReadOnly(true);

    int text_size = 100;
    text_Qt->setFixedHeight(text_size);
    text_QCustomPlot->setFixedHeight(text_size);
    text_Fftw3->setFixedHeight(text_size);
    text_CrystalClear_Icons->setFixedHeight(text_size);
    text_Doxygen->setFixedHeight(text_size);
    text_Programmers->setFixedHeight(text_size);

    text_Qt->setText("This software use Qt 4 for MacOSX, Qt 5 for Linux and Windows: http://www.qt.io/");
    text_QCustomPlot->setText("This software use the QCustomPlot library: http://qcustomplot.com/. Thank to Emanuel Eichhammer");
    text_Fftw3->setText("This software use FFTW3: http://www.fftw.org/");
    text_CrystalClear_Icons->setText("This software use Crytal Clear Icons set: http://www.everaldo.com/. Thank to Everaldo Coelho");
    text_Doxygen->setText("This software use Doxygen: http://www.doxygen.org");
    text_Programmers->setText("This software is developped in the University of Picardie Jules Verne (Amiens, France), at the BioFlowImage laboratory, by Simon Garnotel: http://www.tidam.fr/");

    //Label
    label_title->setText("About Flow eXplorer");
    label_version->setText("Version: 1.31");
    label_date->setText("Date: July 2015");
    label_author->setText("Author: Simon Garnotel");

    int img_size = 200;
    label_Qt_img->setPixmap(QPixmap(IMG_Qt).scaledToWidth(img_size, Qt::SmoothTransformation));
    label_QCustomPlot_img->setPixmap(QPixmap(IMG_QCustomPlot).scaledToWidth(img_size, Qt::SmoothTransformation));
    label_Fftw3_img->setPixmap(QPixmap(IMG_fftw3).scaledToWidth(img_size, Qt::SmoothTransformation));
    label_CrystalClear_Icons_img->setPixmap(QPixmap(IMG_Everlado).scaledToWidth(img_size, Qt::SmoothTransformation));
    label_Doxygen_img->setPixmap(QPixmap(IMG_Doxygen).scaledToWidth(img_size, Qt::SmoothTransformation));
    label_Programmers_img->setPixmap(QPixmap(IMG_ICON).scaledToWidth(img_size, Qt::SmoothTransformation));

    label_Qt_img->setToolTip("Qt");
    label_QCustomPlot_img->setToolTip("QCustomPlot");
    label_Fftw3_img->setToolTip("FFTW3");
    label_CrystalClear_Icons_img->setToolTip("Crystal Clear Icons");
    label_Doxygen_img->setToolTip("Doxygen");
    label_Programmers_img->setToolTip("BioFlowImage");

    //Grid
    setLayout(grid);
    grid->addWidget(label_title, 0, 0, 1, 10);
    grid->addWidget(label_version, 1, 0, 1, 10);
    grid->addWidget(label_date, 2, 0, 1, 10);
    grid->addWidget(label_author, 3, 0, 1, 10);

    grid->addWidget(text_Qt, 10, 0, 5, 5);
    grid->addWidget(text_QCustomPlot, 15, 0, 5, 5);
    grid->addWidget(text_Fftw3, 20, 0, 5, 5);
    grid->addWidget(text_CrystalClear_Icons, 25, 0, 5, 5);
    grid->addWidget(text_Doxygen, 30, 0, 5, 5);
    grid->addWidget(text_Programmers, 35, 0, 5, 5);

    grid->addWidget(label_Qt_img, 10, 5, 5, 5);
    grid->addWidget(label_QCustomPlot_img, 15, 5, 5, 5);
    grid->addWidget(label_Fftw3_img, 20, 5, 5, 5);
    grid->addWidget(label_CrystalClear_Icons_img, 25, 5, 5, 5);
    grid->addWidget(label_Doxygen_img, 30, 5, 5, 5);
    grid->addWidget(label_Programmers_img, 35, 5, 5, 5);

    grid->addWidget(button_close, 100, 0, 1, 10);
}

/*!
 * \brief DialogAbout::init_sig
 */
void DialogAbout::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_close, SIGNAL(clicked()), this, SLOT(do_close()));
}

/*!
 * \brief DialogAbout::init_css
 */
void DialogAbout::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_title->setStyleSheet(CSS_LABEL_TITLE);
}

/*!
 * \brief DialogAbout::DialogAbout
 * \param parent
 */
DialogAbout::DialogAbout(QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();
}

/*!
 * \brief DialogAbout::do_close
 */
void DialogAbout::do_close(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    accept();
}
