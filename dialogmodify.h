#ifndef DIALOGMODIFY_H
#define DIALOGMODIFY_H

#include "headers.hpp"
#include "dialognew.h"

#include "TextDef__Modify.h"

class DialogModify : public QDialog
{
    Q_OBJECT
public:
    explicit DialogModify(QString current_dir,
                          Coord *EXT__coord_arterial_cervical, Coord *EXT__coord_venous_cervical, Coord *EXT__coord_CSF_cervical,
                          Coord *EXT__coord_arterial_cerebral, Coord *EXT__coord_venous_cerebral, Coord *EXT__coord_CSF_cerebral,
                          Coord **EXT__coords_arterial, Coord **EXT__coords_venous, Coord **EXT__coords_CSF,
                          QWidget *parent = 0);

signals:

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void load_MRI_data();

    void do_plot_arterial_cervical();
    void do_plot_venous_cervical();
    void do_plot_CSF_cervical();

    void do_plot_arterial_cerebral();
    void do_plot_venous_cerebral();
    void do_plot_CSF_cerebral();

    void do_plot_arterial_other();
    void do_plot_venous_other();
    void do_plot_CSF_other();

    void get_point_arterial_cervical(QMouseEvent *m_event);
    void get_point_venous_cervical(QMouseEvent *m_event);
    void get_point_CSF_cervical(QMouseEvent *m_event);

    void get_point_arterial_cerebral(QMouseEvent *m_event);
    void get_point_venous_cerebral(QMouseEvent *m_event);
    void get_point_CSF_cerebral(QMouseEvent *m_event);

    void get_point_arterial_other(QMouseEvent *m_event);
    void get_point_venous_other(QMouseEvent *m_event);
    void get_point_CSF_other(QMouseEvent *m_event);

    void modify_arterial_cervical();
    void modify_venous_cervical();
    void modify_CSF_cervical();

    void modify_arterial_cerebral();
    void modify_venous_cerebral();
    void modify_CSF_cerebral();

    void modify_arterial_other();
    void modify_venous_other();
    void modify_CSF_other();

    void auto_modify_arterial_cervical();
    void auto_modify_venous_cervical(int pos=-1);
    void auto_modify_CSF_cervical(int pos=-1);

    void auto_modify_arterial_cerebral(int pos=-1);
    void auto_modify_venous_cerebral(int pos=-1);
    void auto_modify_CSF_cerebral(int pos=-1);

    void auto_modify_arterial_other(int curve=-1);
    void auto_modify_venous_other(int pos=-1, int curve=-1);
    void auto_modify_CSF_other(int pos=-1, int curve=-1);

    void auto_modify_all_arterial_other();
    void auto_modify_all_venous_other(int pos=-1);
    void auto_modify_all_CSF_other(int pos=-1);

    void modify();
    void cancel();

private:
    //Tab
    QTabWidget *tab;

    //Widget
    QWidget *tab_cervical_cerebral;
    QWidget *tab_other;

    //Grid
    QGridLayout *grid;
    QGridLayout *grid_cervical_cerebral;
    QGridLayout *grid_other;

    //QCustomPlot
    QCustomPlot *plot_arterial_cervical;
    QCustomPlot *plot_venous_cervical;
    QCustomPlot *plot_CSF_cervical;

    QCustomPlot *plot_arterial_cerebral;
    QCustomPlot *plot_venous_cerebral;
    QCustomPlot *plot_CSF_cerebral;

    QCustomPlot *plot_arterial_other;
    QCustomPlot *plot_venous_other;
    QCustomPlot *plot_CSF_other;

    //Label
    QLabel *label_cervical;
    QLabel *label_cerebral;

    QLabel *label_value_arterial_cervical;
    QLabel *label_value_venous_cervical;
    QLabel *label_value_CSF_cervical;

    QLabel *label_value_arterial_cerebral;
    QLabel *label_value_venous_cerebral;
    QLabel *label_value_CSF_cerebral;

    QLabel *label_value_arterial_other;
    QLabel *label_value_venous_other;
    QLabel *label_value_CSF_other;

    //SpinBox
    QDoubleSpinBox *box_value_arterial_cervical;
    QDoubleSpinBox *box_value_venous_cervical;
    QDoubleSpinBox *box_value_CSF_cervical;

    QDoubleSpinBox *box_value_arterial_cerebral;
    QDoubleSpinBox *box_value_venous_cerebral;
    QDoubleSpinBox *box_value_CSF_cerebral;

    QDoubleSpinBox *box_value_arterial_other;
    QDoubleSpinBox *box_value_venous_other;
    QDoubleSpinBox *box_value_CSF_other;

    //Button
    QPushButton *button_modify_arterial_cervical;
    QPushButton *button_modify_venous_cervical;
    QPushButton *button_modify_CSF_cervical;
    QPushButton *button_auto_modify_arterial_cervical;
    QPushButton *button_auto_modify_venous_cervical;
    QPushButton *button_auto_modify_CSF_cervical;

    QPushButton *button_modify_arterial_cerebral;
    QPushButton *button_modify_venous_cerebral;
    QPushButton *button_modify_CSF_cerebral;
    QPushButton *button_auto_modify_arterial_cerebral;
    QPushButton *button_auto_modify_venous_cerebral;
    QPushButton *button_auto_modify_CSF_cerebral;

    QPushButton *button_modify_arterial_other;
    QPushButton *button_modify_venous_other;
    QPushButton *button_modify_CSF_other;
    QPushButton *button_auto_modify_arterial_other;
    QPushButton *button_auto_modify_venous_other;
    QPushButton *button_auto_modify_CSF_other;
    QPushButton *button_auto_modify_all_arterial_other;
    QPushButton *button_auto_modify_all_venous_other;
    QPushButton *button_auto_modify_all_CSF_other;
    QPushButton *button_choice_arterial;
    QPushButton *button_choice_venous;
    QPushButton *button_choice_CSF;

    QPushButton *button_modify;
    QPushButton *button_cancel;

    //Menu
    QMenu *menu_choice_arterial;
    QMenu *menu_choice_venous;
    QMenu *menu_choice_CSF;

    //CheckBox
    QCheckBox *check_venous_cervical;
    QCheckBox *check_CSF_cervical;

    QCheckBox *check_arterial_cerebral;
    QCheckBox *check_venous_cerebral;
    QCheckBox *check_CSF_cerebral;

    QCheckBox *check_venous_other;
    QCheckBox *check_CSF_other;

    //Coord
    Coord *coord_arterial_cervical;
    Coord *coord_venous_cervical;
    Coord *coord_CSF_cervical;

    Coord *coord_arterial_cerebral;
    Coord *coord_venous_cerebral;
    Coord *coord_CSF_cerebral;

    Coord **coords_arterial;
    Coord **coords_venous;
    Coord **coords_CSF;

    Coord *EXT_coord_arterial_cervical;
    Coord *EXT_coord_venous_cervical;
    Coord *EXT_coord_CSF_cervical;

    Coord *EXT_coord_arterial_cerebral;
    Coord *EXT_coord_venous_cerebral;
    Coord *EXT_coord_CSF_cerebral;

    Coord **EXT_coords_arterial;
    Coord **EXT_coords_venous;
    Coord **EXT_coords_CSF;

    //String
    QString dir;

    //Int
    int point_arterial_cervical;
    int point_venous_cervical;
    int point_CSF_cervical;

    int point_arterial_cerebral;
    int point_venous_cerebral;
    int point_CSF_cerebral;

    int n_arterial;
    int n_venous;
    int n_CSF;

    int curve_arterial_other;
    int point_arterial_other;
    int curve_venous_other;
    int point_venous_other;
    int curve_CSF_other;
    int point_CSF_other;

    int arterial_cervical_modified;
    int venous_cervical_modified;
    int CSF_cervical_modified;

    int arterial_cerebral_modified;
    int venous_cerebral_modified;
    int CSF_cerebral_modified;

    int arterial_other_modified;
    int venous_other_modified;
    int CSF_other_modified;
};

#endif // DIALOGMODIFY_H
