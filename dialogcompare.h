#ifndef DIALOGCOMPARE_H
#define DIALOGCOMPARE_H


#include "headers.hpp"
#include "TextDef__Compare.h"


/*!
 * \brief The DialogCompare class
 *
 * This class contains the dialog box for flow/pressure comparaison.
 */
class DialogCompare : public QDialog
{
    Q_OBJECT
public:
    explicit DialogCompare(QString current_dir, QString current_flow,
                           Coord *volume, Coord *pressure,
                           QWidget *parent = 0);

private slots:
    void closeEvent(QCloseEvent *);

    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void plot_volume_curve();
    void plot_pressure_curve();
    void plot_compliance_curve();
    void plot_compliance_cont_curve();

    void plot_first_bound(int pos);
    void plot_second_bound(int pos);

    void plot_first_font();
    void plot_second_font();
    void plot_third_font();

    void do_move_volume_right();
    void do_move_volume_left();
    void do_move_pressure_right();
    void do_move_pressure_left();

    void do_smooth_compliance();

    void do_compliance();
    void do_filter();

    void do_save_compliance();
    void do_save_compliance_cont();

    void do_quit();

private:
    //Grid
    QGridLayout *grid;

    //VBox
    QVBoxLayout *vbox_volume_move;
    QVBoxLayout *vbox_pressure_move;
    QVBoxLayout *vbox_compliance_labels;
    QVBoxLayout *vbox_compliance_cont_labels;

    //HBox
    QHBoxLayout *hbox_compliance_buttons;
    QHBoxLayout *hbox_compliance_cont_buttons;

    //Plot
    QCustomPlot *plot_volume;
    QCustomPlot *plot_pressure;
    QCustomPlot *plot_compliance;
    QCustomPlot *plot_compliance_cont;

    //Coord
    Coord *coord_volume;
    Coord *coord_pressure;
    Coord *coord_compliance;
    Coord *coord_compliance_cont;

    //Button
    QPushButton *button_move_volume_right;
    QPushButton *button_move_volume_left;
    QPushButton *button_move_pressure_right;
    QPushButton *button_move_pressure_left;

    QPushButton *button_smooth_compliance;
    QPushButton *button_save_compliance;

    QPushButton *button_filter_compliance_cont;
    QPushButton *button_save_compliance_cont;

    QPushButton *button_compliance;

    QPushButton *button_close;

    //Slider
    QSlider *slider_first_bound;
    QSlider *slider_second_bound;

    //SpinBox
    QSpinBox *box_compliance_delay;
    QSpinBox *box_compliance_filter;

    //Label
    QLabel *label_compliance_global;

    QLabel *label_compliance_delay;
    QLabel *label_compliance_filter;

    QLabel *label_compliance_min;
    QLabel *label_compliance_max;
    QLabel *label_compliance_mean;
    QLabel *label_compliance_gradient;

    QLabel *label_compliance_cont_min;
    QLabel *label_compliance_cont_max;
    QLabel *label_compliance_cont_mean;
    QLabel *label_compliance_cont_gradient;

    //Double
    double global_compliance;
    double first_bound;
    double second_bound;

    //String
    QString current_dir;
    QString current_flow;
};

#endif // DIALOGCOMPARE_H
