#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//*************//
//***INCLUDE***//
//*************//
#include "headers.hpp"
#include "dialogsettings.h"
#include "dialogquality.h"
#include "dialognew.h"
#include "dialogmodify.h"
#include "dialogdelete.h"
#include "dialogcompare.h"
#include "dialogstats.h"
#include "dialogabout.h"
//*************//
//*************//


/*!
 * \brief The MainWindow class
 *
 * The main window of the software.
 *
 * It contains flows and pressure curves (EPI curve will be available as soon as possible), and all utils to analyse then.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

private slots:
    void resizeEvent(QResizeEvent *);
    void closeEvent(QCloseEvent *);

    //************//
    //***GLOBAL***//
    //************//
    //Init
    void init_var();
    void init_win();
    void init_sig();
    void init_css();
    void init_set();

    //Actions
    void quit_win();
    void settings();

    void load_patient();
    void load_patient(QString dir);
    void new_patient();
    void modify_patient();
    void delete_patient();
    void export_patient();

    void hide_ICP();
    void restore_ICP();
    void hide_MRI();
    void restore_MRI();
    void hide_EPI();
    void restore_EPI();

    //Buttons
    void update_tab(int pos);
    void clear_all();
    void save_all();

    //Status
    void status_error(QString txt);
    void status_info(QString txt);
    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
    void init_MRI_var();
    void init_MRI_win();
    void init_MRI_sig();
    void init_MRI_css();


    //Plots
    bool plot_MRI_cervical();
    bool plot_MRI_arterial_cervical();
    bool plot_MRI_systole_cervical();
    bool plot_MRI_venous_cervical();
    bool plot_MRI_venous_corr_cervical();
    bool plot_MRI_csf_cervical();
    bool plot_MRI_csf_corr_cervical();
    bool plot_MRI_AV_cervical();
    bool plot_MRI_ICVC_cervical();

    bool plot_MRI_cerebral();
    bool plot_MRI_arterial_cerebral();
    bool plot_MRI_systole_cerebral();
    bool plot_MRI_venous_cerebral();
    bool plot_MRI_venous_corr_cerebral();
    bool plot_MRI_csf_cerebral();
    bool plot_MRI_csf_corr_cerebral();
    bool plot_MRI_AV_cerebral();
    bool plot_MRI_ICVC_cerebral();

    bool plot_MRI_cervical_cerebral();
    bool plot_MRI_arterial_cervical_cerebral();
    bool plot_MRI_venous_cervical_cerebral();
    bool plot_MRI_csf_cervical_cerebral();
    bool plot_MRI_AV_flow_cervical_cerebral();
    bool plot_MRI_AV_volume_cervical_cerebral();
    bool plot_MRI_ICVC_flow_cervical_cerebral();
    bool plot_MRI_ICVC_volume_cervical_cerebral();

    bool plot_MRI_spectrum();
    bool plot_MRI_arterial_spectrum();
    bool plot_MRI_venous_spectrum();
    bool plot_MRI_csf_spectrum();
    bool plot_MRI_AV_flow_spectrum();
    bool plot_MRI_AV_volume_spectrum();
    bool plot_MRI_ICVC_flow_spectrum();
    bool plot_MRI_ICVC_volume_spectrum();

    bool plot_MRI_others();
    bool plot_MRI_arterial_others();
    bool plot_MRI_venous_others();
    bool plot_MRI_csf_others();


    //Print
    bool print_MRI_arterial_cervical();
    bool print_MRI_venous_cervical();
    bool print_MRI_csf_cervical();
    bool print_MRI_AV_cervical();
    bool print_MRI_ICVC_cervical();

    bool print_MRI_arterial_cerebral();
    bool print_MRI_venous_cerebral();
    bool print_MRI_csf_cerebral();
    bool print_MRI_AV_cerebral();
    bool print_MRI_ICVC_cerebral();

    bool print_MRI_arterial_others();
    bool print_MRI_venous_others();
    bool print_MRI_csf_others();


    //Buttons
    void do_MRI_quality_cervical();

    void do_MRI_plot_00_cervical();
    void do_MRI_choice_ncycles_cervical_1();
    void do_MRI_choice_ncycles_cervical_2();
    void do_MRI_choice_ncycles_cervical_3();

    void do_MRI_systole_detect_cervical();
    void do_MRI_systole_adjust_cervical();
    void do_MRI_systole_show_cervical();

    void do_MRI_move_arterial_right_cervical();
    void do_MRI_move_arterial_left_cervical();
    void do_MRI_move_venous_right_cervical();
    void do_MRI_move_venous_left_cervical();
    void do_MRI_move_csf_right_cervical();
    void do_MRI_move_csf_left_cervical();

    void do_MRI_arterial_restore_cervical();
    void do_MRI_arterial_smooth_cervical();
    void do_MRI_arterial_save_cervical();
    void do_MRI_legend_cervical();

    void do_MRI_venous_restore_cervical();
    void do_MRI_venous_smooth_cervical();
    void do_MRI_venous_save_cervical();
    void do_MRI_venous_corr_save_cervical();

    void do_MRI_csf_restore_cervical();
    void do_MRI_csf_smooth_cervical();
    void do_MRI_csf_save_cervical();
    void do_MRI_csf_corr_save_cervical();

    void do_MRI_venous_corr_cervical();
    void do_MRI_csf_corr_cervical();

    void do_MRI_AV_flow_volume_cervical(int pos);

    void do_MRI_AV_cervical();
    void do_MRI_AV_auto_cervical();
    void do_MRI_AV_adjust_cervical();
    void do_MRI_AV_normalize_cervical();
    void do_MRI_AV_smooth_cervical();
    void do_MRI_AV_save_cervical();

    void do_MRI_ICVC_flow_volume_cervical(int pos);

    void do_MRI_ICVC_cervical();
    void do_MRI_ICVC_auto_cervical();
    void do_MRI_ICVC_adjust_cervical();
    void do_MRI_ICVC_normalize_cervical();
    void do_MRI_ICVC_smooth_cervical();
    void do_MRI_ICVC_save_cervical();

    //

    void do_MRI_quality_cerebral();

    void do_MRI_plot_00_cerebral();
    void do_MRI_choice_ncycles_cerebral_1();
    void do_MRI_choice_ncycles_cerebral_2();
    void do_MRI_choice_ncycles_cerebral_3();

    void do_MRI_systole_detect_cerebral();
    void do_MRI_systole_adjust_cerebral();
    void do_MRI_systole_show_cerebral();

    void do_MRI_move_arterial_right_cerebral();
    void do_MRI_move_arterial_left_cerebral();
    void do_MRI_move_venous_right_cerebral();
    void do_MRI_move_venous_left_cerebral();
    void do_MRI_move_csf_right_cerebral();
    void do_MRI_move_csf_left_cerebral();

    void do_MRI_arterial_restore_cerebral();
    void do_MRI_arterial_smooth_cerebral();
    void do_MRI_arterial_save_cerebral();
    void do_MRI_legend_cerebral();

    void do_MRI_venous_restore_cerebral();
    void do_MRI_venous_smooth_cerebral();
    void do_MRI_venous_save_cerebral();
    void do_MRI_venous_corr_save_cerebral();

    void do_MRI_csf_restore_cerebral();
    void do_MRI_csf_smooth_cerebral();
    void do_MRI_csf_save_cerebral();
    void do_MRI_csf_corr_save_cerebral();

    void do_MRI_venous_corr_cerebral();
    void do_MRI_csf_corr_cerebral();

    void do_MRI_AV_flow_volume_cerebral(int pos);

    void do_MRI_AV_cerebral();
    void do_MRI_AV_auto_cerebral();
    void do_MRI_AV_adjust_cerebral();
    void do_MRI_AV_normalize_cerebral();
    void do_MRI_AV_smooth_cerebral();
    void do_MRI_AV_save_cerebral();

    void do_MRI_ICVC_flow_volume_cerebral(int pos);

    void do_MRI_ICVC_cerebral();
    void do_MRI_ICVC_auto_cerebral();
    void do_MRI_ICVC_adjust_cerebral();
    void do_MRI_ICVC_normalize_cerebral();
    void do_MRI_ICVC_smooth_cerebral();
    void do_MRI_ICVC_save_cerebral();

    //

    void do_MRI_dphi();
    void do_MRI_legend_cervical_cerebral();

    //

    void do_MRI_quality_others();

    void do_MRI_menu_arterial_others_visible();
    void do_MRI_menu_venous_others_visible();
    void do_MRI_menu_csf_others_visible();

    void do_MRI_move_arterial_right_others();
    void do_MRI_move_arterial_left_others();
    void do_MRI_move_venous_right_others();
    void do_MRI_move_venous_left_others();
    void do_MRI_move_csf_right_others();
    void do_MRI_move_csf_left_others();

    void do_MRI_arterial_restore_others();
    void do_MRI_arterial_smooth_others();
    void do_MRI_arterial_save_others();
    void do_MRI_legend_others();

    void do_MRI_venous_restore_others();
    void do_MRI_venous_smooth_others();
    void do_MRI_venous_save_others();

    void do_MRI_csf_restore_others();
    void do_MRI_csf_smooth_others();
    void do_MRI_csf_save_others();

    //Others
    void clear_MRI();
    void save_MRI();
    //*********//
    //*********//


    //*********//
    //***ICP***//
    //*********//
    void init_ICP_var();
    void init_ICP_win();
    void init_ICP_sig();
    void init_ICP_css();

    //Plot
    void plot_ICP_signal_curve();
    void plot_ICP_signal_min();
    void plot_ICP_signal_max();
    void plot_ICP_signal_font();
    void plot_ICP_select_curve();
    void plot_ICP_fourier_curve();
    void plot_ICP_ifft_min();
    void plot_ICP_ifft_max();
    void plot_ICP_fourier_font();
    void plot_ICP_ifft_curve();
    void plot_ICP_threshold();
    void plot_ICP_peaks();
    void plot_ICP_mean_curve();

    //Sliders
    void move_ICP_min_signal(int pos);
    void move_ICP_max_signal(int pos);
    void move_ICP_min_fourier(int pos);
    void move_ICP_max_fourier(int pos);
    void move_ICP_min_ifft(int pos);
    void move_ICP_max_ifft(int pos);
    void move_ICP_threshold(int pos);
    void update_ICP_ifft_range();

    //Boxes
    void choose_ICP_min_signal(double pos);
    void choose_ICP_max_signal(double pos);
    void choose_ICP_min_fourier(int pos);
    void choose_ICP_max_fourier(int pos);
    void choose_ICP_min_ifft(int pos);
    void choose_ICP_max_ifft(int pos);
    void choose_ICP_threshold(double pos);

    //Buttons
    void do_ICP_fourier();
    void do_ICP_ifft();
    void do_ICP_peaks();
    void do_ICP_mean();
    void do_ICP_adjust();
    void do_ICP_normalize();
    void do_ICP_save();

    //Others
    void clear_ICP();
    void save_ICP();
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    void init_EPI_var();
    void init_EPI_win();
    void init_EPI_sig();
    void init_EPI_css();

    //Plot
    void plot_EPI_signal_curve(int pos);
    void plot_EPI_signal_min();
    void plot_EPI_signal_max();
    void plot_EPI_signal_font();
    void plot_EPI_select_curve();
    void plot_EPI_fourier_curve();
    void plot_EPI_ifft_min();
    void plot_EPI_ifft_max();
    void plot_EPI_fourier_font();
    void plot_EPI_ifft_curve();
    void plot_EPI_threshold();
    void plot_EPI_peaks();
    void plot_EPI_mean_curve();

    //Sliders
    void move_EPI_min_signal(int pos);
    void move_EPI_max_signal(int pos);
    void move_EPI_min_fourier(int pos);
    void move_EPI_max_fourier(int pos);
    void move_EPI_min_ifft(int pos);
    void move_EPI_max_ifft(int pos);
    void move_EPI_threshold(int pos);
    void update_EPI_ifft_range();

    //Boxes
    void choose_EPI_min_signal(double pos);
    void choose_EPI_max_signal(double pos);
    void choose_EPI_min_fourier(int pos);
    void choose_EPI_max_fourier(int pos);
    void choose_EPI_min_ifft(int pos);
    void choose_EPI_max_ifft(int pos);
    void choose_EPI_threshold(double pos);

    //Buttons
    void do_ICP_quality();
    void do_EPI_fourier();
    void do_EPI_ifft();
    void do_EPI_peaks();
    void do_EPI_mean();
    void do_EPI_adjust();
    void do_EPI_normalize();
    void do_EPI_save();

    //Others
    void clear_EPI();
    void save_EPI();


    //*************//
    //***COMPARE***//
    //*************//
    void init_COMP_var();
    void init_COMP_win();
    void init_COMP_sig();
    void init_COMP_css();

    void compare();
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    void init_STAT_var();
    void init_STAT_win();
    void init_STAT_sig();
    void init_STAT_css();

    void stats();
    //***********//
    //***********//


    //**********//
    //***HELP***//
    //**********//
    void do_user_help();
    void do_programmer_help();
    void do_about();
    //**********//
    //**********//

private:
    //************//
    //***GLOBAL***//
    //************//
    //Central
    QWidget *central;

    //ScrollArea
    QScrollArea *scroll_area;

    //Widget
    QWidget *scroll_widget;

    //VBox
    QVBoxLayout *scroll_vbox;

    //Menu
    QMenu *menu_file;
    QMenu *menu_edit;
    QMenu *menu_view;
    QMenu *menu_help;

    //Actions
    QAction *action_quit;
    QAction *action_settings;

    QAction *action_load_patient;
    QAction *action_new_patient;
    QAction *action_modify_patient;
    QAction *action_delete_patient;
    QAction *action_export_patient;

    QAction *action_hide_MRI;
    QAction *action_restore_MRI;
    QAction *action_hide_ICP;
    QAction *action_restore_ICP;
    QAction *action_hide_EPI;
    QAction *action_restore_EPI;

    QAction *action_user_help;
    QAction *action_programmer_help;
    QAction *action_about;

    //ToolBar
    QToolBar *toolbar;

    //Grid
    QGridLayout *grid;
    QGridLayout *grid_all;

    //Labels
    QLabel *label_title;
    QLabel *label_patient;
    QLabel *label_patient_name;
    QLabel *label_space1;
    QLabel *label_space2;
    QLabel *label_statusbar_img;
    QLabel *label_statusbar_txt;

    //StatusBar
    QStatusBar *statusbar;

    //Buttons
    QPushButton *button_save_MRI;
    QPushButton *button_save_ICP;
    QPushButton *button_save_EPI;
    QPushButton *button_save_all;
    QPushButton *button_clear_MRI;
    QPushButton *button_clear_ICP;
    QPushButton *button_clear_EPI;
    QPushButton *button_clear_all;

    //Int
    int npi;
    int PCMRI_length;

    //String
    QString current_dir;
    QString exam_number;
    QString exam_date;
    QString patient_age;
    QString patient_sexe;
    QString patient_date;

    QString MRI_time_unity;
    QString MRI_flow_unity;
    QString MRI_volume_unity;
    QString ICP_time_unity;
    QString ICP_pressure_unity;

    //Double
    double MRI_EPI_coeff_systole_threshold;
    double MRI_EPI_coeff_systole_delay;
    double ICP_coeff_fourier_min;
    double ICP_coeff_fourier_max;
    double ICP_coeff_ifft_min;
    double ICP_coeff_ifft_max;
    double EPI_coeff_fourier_min;
    double EPI_coeff_fourier_max;
    double EPI_coeff_ifft_min;
    double EPI_coeff_ifft_max;

    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
    //Tab
    QTabWidget *MRI_tab;

    //Widget
    QWidget *MRI_tab_cervical;

    QWidget *MRI_tab_cerebral;

    QWidget *MRI_tab_cervical_cerebral;

    QWidget *MRI_tab_spectrum;

    QWidget *MRI_tab_others;

    //Grid
    QGridLayout *MRI_grid_cervical;

    QGridLayout *MRI_grid_cerebral;

    QGridLayout *MRI_grid_cervical_cerebral;

    QGridLayout *MRI_grid_spectrum;

    QGridLayout *MRI_grid_others;

    //Menu
    QMenu *MRI_menu_ncycles_cervical;
    QMenu *MRI_menu_ncycles_cerebral;

    QMenu *MRI_arterial_menu;
    QMenu *MRI_venous_menu;
    QMenu *MRI_csf_menu;

    //HBox
    QHBoxLayout *MRI_hbox_arterial_cervical;
    QHBoxLayout *MRI_hbox_venous_cervical;
    QHBoxLayout *MRI_hbox_csf_cervical;
    QHBoxLayout *MRI_hbox_AV_ICVC_cervical;
    QHBoxLayout *MRI_hbox_AV_cervical;
    QHBoxLayout *MRI_hbox_ICVC_cervical;

    QHBoxLayout *MRI_hbox_arterial_cerebral;
    QHBoxLayout *MRI_hbox_venous_cerebral;
    QHBoxLayout *MRI_hbox_csf_cerebral;
    QHBoxLayout *MRI_hbox_AV_ICVC_cerebral;
    QHBoxLayout *MRI_hbox_AV_cerebral;
    QHBoxLayout *MRI_hbox_ICVC_cerebral;

    QHBoxLayout *MRI_hbox_arterial_others;
    QHBoxLayout *MRI_hbox_venous_others;
    QHBoxLayout *MRI_hbox_csf_others;

    //VBox
    QVBoxLayout *MRI_vbox_arterial_move_cervical;
    QVBoxLayout *MRI_vbox_arterial_button_cervical;
    QVBoxLayout *MRI_vbox_arterial_label_cervical;
    QVBoxLayout *MRI_vbox_venous_move_cervical;
    QVBoxLayout *MRI_vbox_venous_button_cervical;
    QVBoxLayout *MRI_vbox_venous_label_cervical;
    QVBoxLayout *MRI_vbox_venous_corr_label_cervical;
    QVBoxLayout *MRI_vbox_csf_move_cervical;
    QVBoxLayout *MRI_vbox_csf_button_cervical;
    QVBoxLayout *MRI_vbox_csf_label_cervical;
    QVBoxLayout *MRI_vbox_csf_corr_label_cervical;
    QVBoxLayout *MRI_vbox_AV_label_cervical;
    QVBoxLayout *MRI_vbox_ICVC_label_cervical;

    QVBoxLayout *MRI_vbox_arterial_move_cerebral;
    QVBoxLayout *MRI_vbox_arterial_button_cerebral;
    QVBoxLayout *MRI_vbox_arterial_label_cerebral;
    QVBoxLayout *MRI_vbox_venous_move_cerebral;
    QVBoxLayout *MRI_vbox_venous_button_cerebral;
    QVBoxLayout *MRI_vbox_venous_label_cerebral;
    QVBoxLayout *MRI_vbox_venous_corr_label_cerebral;
    QVBoxLayout *MRI_vbox_csf_move_cerebral;
    QVBoxLayout *MRI_vbox_csf_button_cerebral;
    QVBoxLayout *MRI_vbox_csf_label_cerebral;
    QVBoxLayout *MRI_vbox_csf_corr_label_cerebral;
    QVBoxLayout *MRI_vbox_AV_label_cerebral;
    QVBoxLayout *MRI_vbox_ICVC_label_cerebral;

    QVBoxLayout *MRI_vbox_arterial_move_others;
    QVBoxLayout *MRI_vbox_arterial_button_others;
    QVBoxLayout *MRI_vbox_arterial_label_others;
    QVBoxLayout *MRI_vbox_venous_move_others;
    QVBoxLayout *MRI_vbox_venous_button_others;
    QVBoxLayout *MRI_vbox_venous_label_others;
    QVBoxLayout *MRI_vbox_csf_move_others;
    QVBoxLayout *MRI_vbox_csf_button_others;
    QVBoxLayout *MRI_vbox_csf_label_others;

    //Plot
    QCustomPlot *MRI_plot_arterial_cervical;
    QCustomPlot *MRI_plot_venous_cervical;
    QCustomPlot *MRI_plot_csf_cervical;
    QCustomPlot *MRI_plot_AV_cervical;
    QCustomPlot *MRI_plot_ICVC_cervical;

    QCustomPlot *MRI_plot_arterial_cerebral;
    QCustomPlot *MRI_plot_venous_cerebral;
    QCustomPlot *MRI_plot_csf_cerebral;
    QCustomPlot *MRI_plot_AV_cerebral;
    QCustomPlot *MRI_plot_ICVC_cerebral;

    QCustomPlot *MRI_plot_arterial_cervical_cerebral;
    QCustomPlot *MRI_plot_venous_cervical_cerebral;
    QCustomPlot *MRI_plot_csf_cervical_cerebral;
    QCustomPlot *MRI_plot_AV_flow_cervical_cerebral;
    QCustomPlot *MRI_plot_AV_volume_cervical_cerebral;
    QCustomPlot *MRI_plot_ICVC_flow_cervical_cerebral;
    QCustomPlot *MRI_plot_ICVC_volume_cervical_cerebral;

    QCustomPlot *MRI_plot_arterial_spectrum;
    QCustomPlot *MRI_plot_venous_spectrum;
    QCustomPlot *MRI_plot_csf_spectrum;
    QCustomPlot *MRI_plot_AV_flow_spectrum;
    QCustomPlot *MRI_plot_AV_volume_spectrum;
    QCustomPlot *MRI_plot_ICVC_flow_spectrum;
    QCustomPlot *MRI_plot_ICVC_volume_spectrum;

    QCustomPlot *MRI_plot_arterial_others;
    QCustomPlot *MRI_plot_venous_others;
    QCustomPlot *MRI_plot_csf_others;

    //Coord
    Coord *MRI_coord_arterial_cervical;
    Coord *MRI_coord_systole_cervical;
    Coord *MRI_coord_venous_cervical;
    Coord *MRI_coord_venous_corr_cervical;
    Coord *MRI_coord_csf_cervical;
    Coord *MRI_coord_csf_corr_cervical;
    Coord *MRI_coord_AV_flow_cervical;
    Coord *MRI_coord_AV_volume_cervical;
    Coord *MRI_coord_ICVC_flow_cervical;
    Coord *MRI_coord_ICVC_volume_cervical;

    Coord *MRI_coord_arterial_cerebral;
    Coord *MRI_coord_systole_cerebral;
    Coord *MRI_coord_venous_cerebral;
    Coord *MRI_coord_venous_corr_cerebral;
    Coord *MRI_coord_csf_cerebral;
    Coord *MRI_coord_csf_corr_cerebral;
    Coord *MRI_coord_AV_flow_cerebral;
    Coord *MRI_coord_AV_volume_cerebral;
    Coord *MRI_coord_ICVC_flow_cerebral;
    Coord *MRI_coord_ICVC_volume_cerebral;

    Coord **MRI_coords_arterial_other;
    Coord **MRI_coords_venous_other;
    Coord **MRI_coords_csf_other;

    //Box
    QDoubleSpinBox *MRI_box_systole_threshold_cervical;
    QSpinBox *MRI_box_systole_delay_cervical;
    QSpinBox *MRI_box_arterial_move_cervical;
    QSpinBox *MRI_box_venous_move_cervical;
    QSpinBox *MRI_box_csf_move_cervical;
    QComboBox *MRI_box_AV_flow_volume_cervical;
    QComboBox *MRI_box_AV_adjust_cervical;
    QComboBox *MRI_box_ICVC_flow_volume_cervical;
    QComboBox *MRI_box_ICVC_adjust_cervical;

    QDoubleSpinBox *MRI_box_systole_threshold_cerebral;
    QSpinBox *MRI_box_systole_delay_cerebral;
    QSpinBox *MRI_box_arterial_move_cerebral;
    QSpinBox *MRI_box_venous_move_cerebral;
    QSpinBox *MRI_box_csf_move_cerebral;
    QComboBox *MRI_box_AV_flow_volume_cerebral;
    QComboBox *MRI_box_AV_adjust_cerebral;
    QComboBox *MRI_box_ICVC_flow_volume_cerebral;
    QComboBox *MRI_box_ICVC_adjust_cerebral;

    //Check
    QCheckBox *MRI_check_move_cervical;
    QCheckBox *MRI_check_venous_cervical;
    QCheckBox *MRI_check_AV_csf_cervical;

    QCheckBox *MRI_check_move_cerebral;
    QCheckBox *MRI_check_venous_cerebral;
    QCheckBox *MRI_check_AV_csf_cerebral;

    QCheckBox *MRI_check_venous_cervical_cerebral;
    QCheckBox *MRI_check_csf_cervical_cerebral;

    QCheckBox *MRI_check_move_others;

    //Button
    QPushButton *MRI_button_quality_cervical;

    QPushButton *MRI_button_plot_00_cervical;
    QPushButton *MRI_button_choice_ncycles_cervical;

    QPushButton *MRI_button_detect_systole_cervical;
    QPushButton *MRI_button_adjust_systole_cervical;
    QPushButton *MRI_button_show_systole_cervical;

    QPushButton *MRI_button_venous_corr_cervical;
    QPushButton *MRI_button_csf_corr_cervical;
    QPushButton *MRI_button_AV_cervical;
    QPushButton *MRI_button_AV_auto_cervical;
    QPushButton *MRI_button_ICVC_cervical;
    QPushButton *MRI_button_ICVC_auto_cervical;

    QPushButton *MRI_button_arterial_move_right_cervical;
    QPushButton *MRI_button_arterial_move_left_cervical;
    QPushButton *MRI_button_venous_move_right_cervical;
    QPushButton *MRI_button_venous_move_left_cervical;
    QPushButton *MRI_button_csf_move_right_cervical;
    QPushButton *MRI_button_csf_move_left_cervical;

    QPushButton *MRI_button_arterial_restore_cervical;
    QPushButton *MRI_button_arterial_smooth_cervical;
    QPushButton *MRI_button_arterial_save_cervical;
    QPushButton *MRI_button_legend_cervical;
    QPushButton *MRI_button_venous_restore_cervical;
    QPushButton *MRI_button_venous_smooth_cervical;
    QPushButton *MRI_button_venous_save_cervical;
    QPushButton *MRI_button_venous_corr_save_cervical;
    QPushButton *MRI_button_csf_restore_cervical;
    QPushButton *MRI_button_csf_smooth_cervical;
    QPushButton *MRI_button_csf_save_cervical;
    QPushButton *MRI_button_csf_corr_save_cervical;
    QPushButton *MRI_button_AV_adjust_cervical;
    QPushButton *MRI_button_AV_normalize_cervical;
    QPushButton *MRI_button_AV_smooth_cervical;
    QPushButton *MRI_button_AV_save_cervical;
    QPushButton *MRI_button_ICVC_adjust_cervical;
    QPushButton *MRI_button_ICVC_normalize_cervical;
    QPushButton *MRI_button_ICVC_smooth_cervical;
    QPushButton *MRI_button_ICVC_save_cervical;


    QPushButton *MRI_button_quality_cerebral;

    QPushButton *MRI_button_plot_00_cerebral;
    QPushButton *MRI_button_choice_ncycles_cerebral;

    QPushButton *MRI_button_detect_systole_cerebral;
    QPushButton *MRI_button_adjust_systole_cerebral;
    QPushButton *MRI_button_show_systole_cerebral;

    QPushButton *MRI_button_venous_corr_cerebral;
    QPushButton *MRI_button_csf_corr_cerebral;
    QPushButton *MRI_button_AV_cerebral;
    QPushButton *MRI_button_AV_auto_cerebral;
    QPushButton *MRI_button_ICVC_cerebral;
    QPushButton *MRI_button_ICVC_auto_cerebral;

    QPushButton *MRI_button_arterial_move_right_cerebral;
    QPushButton *MRI_button_arterial_move_left_cerebral;
    QPushButton *MRI_button_venous_move_right_cerebral;
    QPushButton *MRI_button_venous_move_left_cerebral;
    QPushButton *MRI_button_csf_move_right_cerebral;
    QPushButton *MRI_button_csf_move_left_cerebral;

    QPushButton *MRI_button_arterial_restore_cerebral;
    QPushButton *MRI_button_arterial_smooth_cerebral;
    QPushButton *MRI_button_arterial_save_cerebral;
    QPushButton *MRI_button_legend_cerebral;
    QPushButton *MRI_button_venous_restore_cerebral;
    QPushButton *MRI_button_venous_smooth_cerebral;
    QPushButton *MRI_button_venous_save_cerebral;
    QPushButton *MRI_button_venous_corr_save_cerebral;
    QPushButton *MRI_button_csf_restore_cerebral;
    QPushButton *MRI_button_csf_smooth_cerebral;
    QPushButton *MRI_button_csf_save_cerebral;
    QPushButton *MRI_button_csf_corr_save_cerebral;
    QPushButton *MRI_button_AV_adjust_cerebral;
    QPushButton *MRI_button_AV_normalize_cerebral;
    QPushButton *MRI_button_AV_smooth_cerebral;
    QPushButton *MRI_button_AV_save_cerebral;
    QPushButton *MRI_button_ICVC_adjust_cerebral;
    QPushButton *MRI_button_ICVC_normalize_cerebral;
    QPushButton *MRI_button_ICVC_smooth_cerebral;
    QPushButton *MRI_button_ICVC_save_cerebral;


    QPushButton *MRI_button_arterial_choice;
    QPushButton *MRI_button_venous_choice;
    QPushButton *MRI_button_csf_choice;
    QPushButton *MRI_button_legend_cervical_cerebral;


    QPushButton *MRI_button_quality_others;

    QPushButton *MRI_button_arterial_move_right_others;
    QPushButton *MRI_button_arterial_move_left_others;
    QPushButton *MRI_button_venous_move_right_others;
    QPushButton *MRI_button_venous_move_left_others;
    QPushButton *MRI_button_csf_move_right_others;
    QPushButton *MRI_button_csf_move_left_others;

    QPushButton *MRI_button_arterial_restore_others;
    QPushButton *MRI_button_arterial_smooth_others;
    QPushButton *MRI_button_arterial_save_others;
    QPushButton *MRI_button_legend_others;
    QPushButton *MRI_button_venous_restore_others;
    QPushButton *MRI_button_venous_smooth_others;
    QPushButton *MRI_button_venous_save_others;
    QPushButton *MRI_button_csf_restore_others;
    QPushButton *MRI_button_csf_smooth_others;
    QPushButton *MRI_button_csf_save_others;

    //Label
    QLabel *MRI_label_heart_rate_cervical;
    QLabel *MRI_label_arterial_min_cervical;
    QLabel *MRI_label_arterial_max_cervical;
    QLabel *MRI_label_arterial_mean_cervical;
    QLabel *MRI_label_arterial_grad_cervical;
    QLabel *MRI_label_arterial_stroke_cervical;
    QLabel *MRI_label_venous_corr_cervical;
    QLabel *MRI_label_venous_min_cervical;
    QLabel *MRI_label_venous_max_cervical;
    QLabel *MRI_label_venous_mean_cervical;
    QLabel *MRI_label_venous_grad_cervical;
    QLabel *MRI_label_venous_stroke_cervical;
    QLabel *MRI_label_venous_corr_min_cervical;
    QLabel *MRI_label_venous_corr_max_cervical;
    QLabel *MRI_label_venous_corr_mean_cervical;
    QLabel *MRI_label_venous_corr_grad_cervical;
    QLabel *MRI_label_venous_corr_stroke_cervical;
    QLabel *MRI_label_csf_corr_cervical;
    QLabel *MRI_label_csf_heart_rate_cervical;
    QLabel *MRI_label_csf_min_cervical;
    QLabel *MRI_label_csf_max_cervical;
    QLabel *MRI_label_csf_mean_cervical;
    QLabel *MRI_label_csf_grad_cervical;
    QLabel *MRI_label_csf_stroke_cervical;
    QLabel *MRI_label_csf_corr_min_cervical;
    QLabel *MRI_label_csf_corr_max_cervical;
    QLabel *MRI_label_csf_corr_mean_cervical;
    QLabel *MRI_label_csf_corr_grad_cervical;
    QLabel *MRI_label_csf_corr_stroke_cervical;
    QLabel *MRI_label_AV_ICVC_ratio_cervical;
    QLabel *MRI_label_AV_flow_min_cervical;
    QLabel *MRI_label_AV_flow_max_cervical;
    QLabel *MRI_label_AV_flow_mean_cervical;
    QLabel *MRI_label_AV_flow_grad_cervical;
    QLabel *MRI_label_AV_flow_stroke_cervical;
    QLabel *MRI_label_AV_volume_min_cervical;
    QLabel *MRI_label_AV_volume_max_cervical;
    QLabel *MRI_label_AV_volume_mean_cervical;
    QLabel *MRI_label_AV_volume_grad_cervical;
    QLabel *MRI_label_ICVC_flow_min_cervical;
    QLabel *MRI_label_ICVC_flow_max_cervical;
    QLabel *MRI_label_ICVC_flow_mean_cervical;
    QLabel *MRI_label_ICVC_flow_grad_cervical;
    QLabel *MRI_label_ICVC_flow_stroke_cervical;
    QLabel *MRI_label_ICVC_volume_min_cervical;
    QLabel *MRI_label_ICVC_volume_max_cervical;
    QLabel *MRI_label_ICVC_volume_mean_cervical;
    QLabel *MRI_label_ICVC_volume_grad_cervical;

    QLabel *MRI_label_heart_rate_cerebral;
    QLabel *MRI_label_arterial_min_cerebral;
    QLabel *MRI_label_arterial_max_cerebral;
    QLabel *MRI_label_arterial_mean_cerebral;
    QLabel *MRI_label_arterial_grad_cerebral;
    QLabel *MRI_label_arterial_stroke_cerebral;
    QLabel *MRI_label_venous_corr_cerebral;
    QLabel *MRI_label_venous_min_cerebral;
    QLabel *MRI_label_venous_max_cerebral;
    QLabel *MRI_label_venous_mean_cerebral;
    QLabel *MRI_label_venous_grad_cerebral;
    QLabel *MRI_label_venous_stroke_cerebral;
    QLabel *MRI_label_venous_corr_min_cerebral;
    QLabel *MRI_label_venous_corr_max_cerebral;
    QLabel *MRI_label_venous_corr_mean_cerebral;
    QLabel *MRI_label_venous_corr_grad_cerebral;
    QLabel *MRI_label_venous_corr_stroke_cerebral;
    QLabel *MRI_label_csf_corr_cerebral;
    QLabel *MRI_label_csf_heart_rate_cerebral;
    QLabel *MRI_label_csf_min_cerebral;
    QLabel *MRI_label_csf_max_cerebral;
    QLabel *MRI_label_csf_mean_cerebral;
    QLabel *MRI_label_csf_grad_cerebral;
    QLabel *MRI_label_csf_stroke_cerebral;
    QLabel *MRI_label_csf_corr_min_cerebral;
    QLabel *MRI_label_csf_corr_max_cerebral;
    QLabel *MRI_label_csf_corr_mean_cerebral;
    QLabel *MRI_label_csf_corr_grad_cerebral;
    QLabel *MRI_label_csf_corr_stroke_cerebral;
    QLabel *MRI_label_AV_ICVC_ratio_cerebral;
    QLabel *MRI_label_AV_flow_min_cerebral;
    QLabel *MRI_label_AV_flow_max_cerebral;
    QLabel *MRI_label_AV_flow_mean_cerebral;
    QLabel *MRI_label_AV_flow_grad_cerebral;
    QLabel *MRI_label_AV_flow_stroke_cerebral;
    QLabel *MRI_label_AV_volume_min_cerebral;
    QLabel *MRI_label_AV_volume_max_cerebral;
    QLabel *MRI_label_AV_volume_mean_cerebral;
    QLabel *MRI_label_AV_volume_grad_cerebral;
    QLabel *MRI_label_ICVC_flow_min_cerebral;
    QLabel *MRI_label_ICVC_flow_max_cerebral;
    QLabel *MRI_label_ICVC_flow_mean_cerebral;
    QLabel *MRI_label_ICVC_flow_grad_cerebral;
    QLabel *MRI_label_ICVC_flow_stroke_cerebral;
    QLabel *MRI_label_ICVC_volume_min_cerebral;
    QLabel *MRI_label_ICVC_volume_max_cerebral;
    QLabel *MRI_label_ICVC_volume_mean_cerebral;
    QLabel *MRI_label_ICVC_volume_grad_cerebral;

    QLabel *MRI_label_arterial_dphi;
    QLabel *MRI_label_venous_dphi;
    QLabel *MRI_label_csf_dphi;
    QLabel *MRI_label_AV_flow_dphi;
    QLabel *MRI_label_AV_volume_dphi;
    QLabel *MRI_label_ICVC_flow_dphi;
    QLabel *MRI_label_ICVC_volume_dphi;

    QLabel *MRI_label_heart_rate_others;
    QLabel *MRI_label_arterial_min_others;
    QLabel *MRI_label_arterial_max_others;
    QLabel *MRI_label_arterial_mean_others;
    QLabel *MRI_label_arterial_grad_others;
    QLabel *MRI_label_arterial_stroke_others;
    QLabel *MRI_label_venous_min_others;
    QLabel *MRI_label_venous_max_others;
    QLabel *MRI_label_venous_mean_others;
    QLabel *MRI_label_venous_grad_others;
    QLabel *MRI_label_venous_stroke_others;
    QLabel *MRI_label_csf_heart_rate_others;
    QLabel *MRI_label_csf_min_others;
    QLabel *MRI_label_csf_max_others;
    QLabel *MRI_label_csf_mean_others;
    QLabel *MRI_label_csf_grad_others;
    QLabel *MRI_label_csf_stroke_others;


    //String
    QStringList *MRI_arterial_files_cervical;
    QStringList *MRI_venous_files_cervical;
    QStringList *MRI_CSF_files_cervical;

    QStringList *MRI_arterial_files_cerebral;
    QStringList *MRI_venous_files_cerebral;
    QStringList *MRI_CSF_files_cerebral;

    QStringList *MRI_arterial_files_other;
    QStringList *MRI_venous_files_other;
    QStringList *MRI_csf_files_other;


    //Int
    int MRI_number_arterial;
    int MRI_number_venous;
    int MRI_number_csf;

    int MRI_legend_cervical;
    int MRI_legend_cerebral;
    int MRI_legend_cervical_cerebral;
    int MRI_legend_others;

    int MRI_plot_00_cervical;
    int MRI_plot_00_cerebral;

    int MRI_ncycles_cervical;
    int MRI_ncycles_cerebral;

    int MRI_quality_arterial_cervical;
    int MRI_quality_venous_cervical;
    int MRI_quality_csf_cervical;
    int MRI_quality_arterial_cerebral;
    int MRI_quality_venous_cerebral;
    int MRI_quality_csf_cerebral;
    int *MRI_quality_arterial_other;
    int *MRI_quality_venous_other;
    int *MRI_quality_csf_other;

    int MRI_AV_flow_cervical_normalized;
    int MRI_AV_volume_cervical_normalized;
    int MRI_ICVC_flow_cervical_normalized;
    int MRI_ICVC_volume_cervical_normalized;

    int MRI_AV_flow_cerebral_normalized;
    int MRI_AV_volume_cerebral_normalized;
    int MRI_ICVC_flow_cerebral_normalized;
    int MRI_ICVC_volume_cerebral_normalized;

    //*********//
    //***ICP***//
    //*********//
    //Tab
    QTabWidget *ICP_tab;

    //Widget
    QWidget *ICP_tab_widget;

    //Grid
    QGridLayout *ICP_grid;
    QGridLayout *ICP_grid_header;
    QGridLayout *ICP_grid_signal;
    QGridLayout *ICP_grid_fourier;
    QGridLayout *ICP_grid_ifft;
    QGridLayout *ICP_grid_peaks;
    QGridLayout *ICP_grid_labels;
    QGridLayout *ICP_grid_buttons;

    //Plots
    QCustomPlot *ICP_plot_signal;
    QCustomPlot *ICP_plot_select;
    QCustomPlot *ICP_plot_fourier;
    QCustomPlot *ICP_plot_ifft;
    QCustomPlot *ICP_plot_mean;

    //Sliders
    QSlider *ICP_slider_min_signal;
    QSlider *ICP_slider_max_signal;
    QSlider *ICP_slider_min_fourier;
    QSlider *ICP_slider_max_fourier;
    QSlider *ICP_slider_min_ifft;
    QSlider *ICP_slider_max_ifft;
    QSlider *ICP_slider_threshold;

    //Boxes
    QDoubleSpinBox *ICP_box_min_signal;
    QDoubleSpinBox *ICP_box_max_signal;
    QSpinBox *ICP_box_min_fourier;
    QSpinBox *ICP_box_max_fourier;
    QSpinBox *ICP_box_min_ifft;
    QSpinBox *ICP_box_max_ifft;
    QDoubleSpinBox *ICP_box_threshold;
    QComboBox *ICP_box_adjust;

    //Buttons
    QPushButton *ICP_button_quality;
    QPushButton *ICP_button_fourier;
    QPushButton *ICP_button_ifft;
    QPushButton *ICP_button_peaks;
    QPushButton *ICP_button_mean;
    QPushButton *ICP_button_adjust;
    QPushButton *ICP_button_normalize;
    QPushButton *ICP_button_save;

    //Labels
    QLabel *ICP_label_cycle;
    QLabel *ICP_label_heartrate;
    QLabel *ICP_label_min;
    QLabel *ICP_label_max;
    QLabel *ICP_label_mean;
    QLabel *ICP_label_gradient;

    //Int
    int ICP_quality;
    int ICP_min_fourier;
    int ICP_max_fourier;
    int ICP_min_ifft;
    int ICP_max_ifft;

    //Double
    double ICP_min_signal;
    double ICP_max_signal;
    double ICP_threshold;

    //Coords
    Coord *ICP_coord_signal;
    Coord *ICP_coord_select;
    Coord *ICP_coord_fourier;
    Coord *ICP_coord_ifft;
    Coord *ICP_coord_peaks;
    Coord *ICP_coord_mean;
    Coord *ICP_coord_SD;
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    //Tab
    QTabWidget *EPI_tab;

    //Widget
    QWidget *EPI_tab_widget;

    //Grid
    QGridLayout *EPI_grid;
    QGridLayout *EPI_grid_header;
    QGridLayout *EPI_grid_signal;
    QGridLayout *EPI_grid_fourier;
    QGridLayout *EPI_grid_ifft;
    QGridLayout *EPI_grid_peaks;
    QGridLayout *EPI_grid_labels;
    QGridLayout *EPI_grid_buttons;

    //Menu
    QMenu *EPI_menu;

    //Plots
    QCustomPlot *EPI_plot_signal;
    QCustomPlot *EPI_plot_select;
    QCustomPlot *EPI_plot_fourier;
    QCustomPlot *EPI_plot_ifft;
    QCustomPlot *EPI_plot_mean;

    //Sliders
    QSlider *EPI_slider_min_signal;
    QSlider *EPI_slider_max_signal;
    QSlider *EPI_slider_min_fourier;
    QSlider *EPI_slider_max_fourier;
    QSlider *EPI_slider_min_ifft;
    QSlider *EPI_slider_max_ifft;
    QSlider *EPI_slider_threshold;

    //Boxes
    QComboBox *EPI_box_select_signal;
    QComboBox *EPI_box_quality;
    QDoubleSpinBox *EPI_box_min_signal;
    QDoubleSpinBox *EPI_box_max_signal;
    QSpinBox *EPI_box_min_fourier;
    QSpinBox *EPI_box_max_fourier;
    QSpinBox *EPI_box_min_ifft;
    QSpinBox *EPI_box_max_ifft;
    QDoubleSpinBox *EPI_box_threshold;
    QComboBox *EPI_box_adjust;

    //Buttons
    QPushButton *EPI_button_fourier;
    QPushButton *EPI_button_ifft;
    QPushButton *EPI_button_peaks;
    QPushButton *EPI_button_mean;
    QPushButton *EPI_button_adjust;
    QPushButton *EPI_button_normalize;
    QPushButton *EPI_button_save;

    //Labels
    QLabel *EPI_label_cycle;
    QLabel *EPI_label_heartrate;
    QLabel *EPI_label_min;
    QLabel *EPI_label_max;
    QLabel *EPI_label_mean;
    QLabel *EPI_label_gradient;

    //String
    QStringList *EPI_arterial_files_cervical;
    QStringList *EPI_venous_files_cervical;
    QStringList *EPI_CSF_files_cervical;

    QStringList *EPI_arterial_files_cerebral;
    QStringList *EPI_venous_files_cerebral;
    QStringList *EPI_CSF_files_cerebral;

    QStringList *EPI_arterial_files_other;
    QStringList *EPI_venous_files_other;
    QStringList *EPI_csf_files_other;

    //Int
    int EPI_current_pos;

    int EPI_min_fourier;
    int EPI_max_fourier;
    int EPI_min_ifft;
    int EPI_max_ifft;

    int EPI_number_arterial;
    int EPI_number_venous;
    int EPI_number_csf;

    int EPI_quality_arterial_cervical;
    int EPI_quality_venous_cervical;
    int EPI_quality_csf_cervical;
    int EPI_quality_arterial_cerebral;
    int EPI_quality_venous_cerebral;
    int EPI_quality_csf_cerebral;
    int *EPI_quality_arterial_other;
    int *EPI_quality_venous_other;
    int *EPI_quality_csf_other;

    int *EPI_quality;

    //Double
    double EPI_min_signal;
    double EPI_max_signal;
    double EPI_threshold;

    //Coords
    Coord **EPI_coords;

    /*Coord *EPI_coord_arterial_cervical;
    Coord *EPI_coord_venous_cervical;
    Coord *EPI_coord_csf_cervical;

    Coord *EPI_coord_arterial_cerebral;
    Coord *EPI_coord_venous_cerebral;
    Coord *EPI_coord_csf_cerebral;

    Coord **EPI_coords_arterial_other;
    Coord **EPI_coords_venous_other;
    Coord **EPI_coords_csf_other;*/

    Coord *EPI_coord_select;
    Coord *EPI_coord_fourier;
    Coord *EPI_coord_ifft;
    Coord *EPI_coord_peaks;
    Coord *EPI_coord_mean;
    Coord *EPI_coord_SD;
    //*********//
    //*********//


    //*************//
    //***COMPARE***//
    //*************//
    //Action
    QAction *action_compare;

    //ToolBar
    QToolBar *toolbar_compare;

    //Labels
    QLabel *label_compare;
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    //Action
    QAction *action_stats;

    //ToolBar
    QToolBar *toolbar_stats;

    //Labels
    QLabel *label_stats;
    //***********//
    //***********//
};

#endif // MAINWINDOW_H
