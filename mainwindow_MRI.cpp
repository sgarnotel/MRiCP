#include "mainwindow.h"

//********************//
//***INITIALISATION***//
//********************//
/*!
 * \brief MainWindow::init_MRI_var
 *
 * Initialisation of MRI part variables
 */
void MainWindow::init_MRI_var()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    MRI_tab = new QTabWidget(this);

    //Widget
    MRI_tab_cervical = new QWidget(this);
    //
    MRI_tab_cerebral = new QWidget(this);
    //
    MRI_tab_cervical_cerebral = new QWidget(this);
    //
    MRI_tab_spectrum = new QWidget(this);
    //
    MRI_tab_others = new QWidget(this);

    //Grid
    MRI_grid_cervical = new QGridLayout;
    //
    MRI_grid_cerebral = new QGridLayout;
    //
    MRI_grid_cervical_cerebral = new QGridLayout;
    //
    MRI_grid_spectrum = new QGridLayout;
    //
    MRI_grid_others = new QGridLayout;

    //Menu
    MRI_menu_ncycles_cervical = new QMenu(this);
    MRI_menu_ncycles_cerebral = new QMenu(this);

    MRI_arterial_menu = new QMenu(this);
    MRI_venous_menu = new QMenu(this);
    MRI_csf_menu = new QMenu(this);

    //HBox
    MRI_hbox_arterial_cervical = new QHBoxLayout;
    MRI_hbox_venous_cervical = new QHBoxLayout;
    MRI_hbox_csf_cervical = new QHBoxLayout;
    MRI_hbox_AV_ICVC_cervical = new QHBoxLayout;
    MRI_hbox_AV_cervical = new QHBoxLayout;
    MRI_hbox_ICVC_cervical = new QHBoxLayout;
    //
    MRI_hbox_arterial_cerebral = new QHBoxLayout;
    MRI_hbox_venous_cerebral = new QHBoxLayout;
    MRI_hbox_csf_cerebral = new QHBoxLayout;
    MRI_hbox_AV_ICVC_cerebral = new QHBoxLayout;
    MRI_hbox_AV_cerebral = new QHBoxLayout;
    MRI_hbox_ICVC_cerebral = new QHBoxLayout;
    //
    MRI_hbox_arterial_others = new QHBoxLayout;
    MRI_hbox_venous_others = new QHBoxLayout;
    MRI_hbox_csf_others = new QHBoxLayout;

    //VBox
    MRI_vbox_arterial_move_cervical = new QVBoxLayout;
    MRI_vbox_arterial_button_cervical = new QVBoxLayout;
    MRI_vbox_arterial_label_cervical = new QVBoxLayout;
    MRI_vbox_venous_move_cervical = new QVBoxLayout;
    MRI_vbox_venous_button_cervical = new QVBoxLayout;
    MRI_vbox_venous_label_cervical = new QVBoxLayout;
    MRI_vbox_venous_corr_label_cervical = new QVBoxLayout;
    MRI_vbox_csf_move_cervical = new QVBoxLayout;
    MRI_vbox_csf_button_cervical = new QVBoxLayout;
    MRI_vbox_csf_label_cervical = new QVBoxLayout;
    MRI_vbox_csf_corr_label_cervical = new QVBoxLayout;
    MRI_vbox_AV_label_cervical = new QVBoxLayout;
    MRI_vbox_ICVC_label_cervical = new QVBoxLayout;
    //
    MRI_vbox_arterial_move_cerebral = new QVBoxLayout;
    MRI_vbox_arterial_button_cerebral = new QVBoxLayout;
    MRI_vbox_arterial_label_cerebral = new QVBoxLayout;
    MRI_vbox_venous_move_cerebral = new QVBoxLayout;
    MRI_vbox_venous_button_cerebral = new QVBoxLayout;
    MRI_vbox_venous_label_cerebral = new QVBoxLayout;
    MRI_vbox_venous_corr_label_cerebral = new QVBoxLayout;
    MRI_vbox_csf_move_cerebral = new QVBoxLayout;
    MRI_vbox_csf_button_cerebral = new QVBoxLayout;
    MRI_vbox_csf_label_cerebral = new QVBoxLayout;
    MRI_vbox_csf_corr_label_cerebral = new QVBoxLayout;
    MRI_vbox_AV_label_cerebral = new QVBoxLayout;
    MRI_vbox_ICVC_label_cerebral = new QVBoxLayout;
    //
    MRI_vbox_arterial_move_others = new QVBoxLayout;
    MRI_vbox_arterial_button_others = new QVBoxLayout;
    MRI_vbox_arterial_label_others = new QVBoxLayout;
    MRI_vbox_venous_move_others = new QVBoxLayout;
    MRI_vbox_venous_button_others = new QVBoxLayout;
    MRI_vbox_venous_label_others = new QVBoxLayout;
    MRI_vbox_csf_move_others = new QVBoxLayout;
    MRI_vbox_csf_button_others = new QVBoxLayout;
    MRI_vbox_csf_label_others = new QVBoxLayout;

    //Plot
    MRI_plot_arterial_cervical = new QCustomPlot(this);
    MRI_plot_venous_cervical = new QCustomPlot(this);
    MRI_plot_csf_cervical = new QCustomPlot(this);
    MRI_plot_AV_cervical = new QCustomPlot(this);
    MRI_plot_ICVC_cervical = new QCustomPlot(this);
    //
    MRI_plot_arterial_cerebral = new QCustomPlot(this);
    MRI_plot_venous_cerebral = new QCustomPlot(this);
    MRI_plot_csf_cerebral = new QCustomPlot(this);
    MRI_plot_AV_cerebral = new QCustomPlot(this);
    MRI_plot_ICVC_cerebral = new QCustomPlot(this);
    //
    MRI_plot_arterial_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_venous_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_csf_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_AV_flow_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_AV_volume_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_ICVC_flow_cervical_cerebral = new QCustomPlot(this);
    MRI_plot_ICVC_volume_cervical_cerebral = new QCustomPlot(this);
    //
    MRI_plot_arterial_spectrum = new QCustomPlot(this);
    MRI_plot_venous_spectrum = new QCustomPlot(this);
    MRI_plot_csf_spectrum = new QCustomPlot(this);
    MRI_plot_AV_flow_spectrum = new QCustomPlot(this);
    MRI_plot_AV_volume_spectrum = new QCustomPlot(this);
    MRI_plot_ICVC_flow_spectrum = new QCustomPlot(this);
    MRI_plot_ICVC_volume_spectrum = new QCustomPlot(this);
    //
    MRI_plot_arterial_others = new QCustomPlot(this);
    MRI_plot_venous_others = new QCustomPlot(this);
    MRI_plot_csf_others = new QCustomPlot(this);

    //Coord
    MRI_coord_arterial_cervical = new Coord;
    MRI_coord_systole_cervical = new Coord;
    MRI_coord_venous_cervical = new Coord;
    MRI_coord_venous_corr_cervical = new Coord;
    MRI_coord_csf_cervical = new Coord;
    MRI_coord_csf_corr_cervical = new Coord;
    MRI_coord_AV_flow_cervical = new Coord;
    MRI_coord_AV_volume_cervical = new Coord;
    MRI_coord_ICVC_flow_cervical = new Coord;
    MRI_coord_ICVC_volume_cervical = new Coord;
    //
    MRI_coord_arterial_cerebral = new Coord;
    MRI_coord_systole_cerebral = new Coord;
    MRI_coord_venous_cerebral = new Coord;
    MRI_coord_venous_corr_cerebral = new Coord;
    MRI_coord_csf_cerebral = new Coord;
    MRI_coord_csf_corr_cerebral = new Coord;
    MRI_coord_AV_flow_cerebral = new Coord;
    MRI_coord_AV_volume_cerebral = new Coord;
    MRI_coord_ICVC_flow_cerebral = new Coord;
    MRI_coord_ICVC_volume_cerebral = new Coord;
    //
    MRI_coords_arterial_other = NULL;
    MRI_coords_venous_other = NULL;
    MRI_coords_csf_other = NULL;

    //Box
    MRI_box_systole_threshold_cervical = new QDoubleSpinBox(this);
    MRI_box_systole_delay_cervical = new QSpinBox(this);
    MRI_box_arterial_move_cervical = new QSpinBox(this);
    MRI_box_venous_move_cervical = new QSpinBox(this);
    MRI_box_csf_move_cervical = new QSpinBox(this);
    MRI_box_AV_flow_volume_cervical = new QComboBox(this);
    MRI_box_AV_adjust_cervical = new QComboBox(this);
    MRI_box_ICVC_flow_volume_cervical = new QComboBox(this);
    MRI_box_ICVC_adjust_cervical = new QComboBox(this);
    //
    MRI_box_systole_threshold_cerebral = new QDoubleSpinBox(this);
    MRI_box_systole_delay_cerebral = new QSpinBox(this);
    MRI_box_arterial_move_cerebral = new QSpinBox(this);
    MRI_box_venous_move_cerebral = new QSpinBox(this);
    MRI_box_csf_move_cerebral = new QSpinBox(this);
    MRI_box_AV_flow_volume_cerebral = new QComboBox(this);
    MRI_box_AV_adjust_cerebral = new QComboBox(this);
    MRI_box_ICVC_flow_volume_cerebral = new QComboBox(this);
    MRI_box_ICVC_adjust_cerebral = new QComboBox(this);

    //Check
    MRI_check_move_cervical = new QCheckBox(this);
    MRI_check_venous_cervical = new QCheckBox(this);
    MRI_check_AV_csf_cervical = new QCheckBox(this);
    //
    MRI_check_move_cerebral = new QCheckBox(this);
    MRI_check_venous_cerebral = new QCheckBox(this);
    MRI_check_AV_csf_cerebral = new QCheckBox(this);
    //
    MRI_check_venous_cervical_cerebral = new QCheckBox(this);
    MRI_check_csf_cervical_cerebral = new QCheckBox(this);
    //
    MRI_check_move_others = new QCheckBox(this);

    //Button
    MRI_button_quality_cervical = new QPushButton(this);

    MRI_button_plot_00_cervical = new QPushButton(this);
    MRI_button_choice_ncycles_cervical = new QPushButton(this);

    MRI_button_detect_systole_cervical = new QPushButton(this);
    MRI_button_adjust_systole_cervical = new QPushButton(this);
    MRI_button_show_systole_cervical = new QPushButton(this);

    MRI_button_venous_corr_cervical = new QPushButton(this);
    MRI_button_csf_corr_cervical = new QPushButton(this);

    MRI_button_AV_cervical = new QPushButton(this);
    MRI_button_AV_auto_cervical = new QPushButton(this);
    MRI_button_ICVC_cervical = new QPushButton(this);
    MRI_button_ICVC_auto_cervical = new QPushButton(this);

    MRI_button_arterial_move_right_cervical = new QPushButton(this);
    MRI_button_arterial_move_left_cervical = new QPushButton(this);
    MRI_button_venous_move_right_cervical = new QPushButton(this);
    MRI_button_venous_move_left_cervical = new QPushButton(this);
    MRI_button_csf_move_right_cervical = new QPushButton(this);
    MRI_button_csf_move_left_cervical = new QPushButton(this);

    MRI_button_arterial_restore_cervical = new QPushButton(this);
    MRI_button_arterial_smooth_cervical = new QPushButton(this);
    MRI_button_arterial_save_cervical = new QPushButton(this);
    MRI_button_legend_cervical = new QPushButton(this);
    MRI_button_venous_restore_cervical = new QPushButton(this);
    MRI_button_venous_smooth_cervical = new QPushButton(this);
    MRI_button_venous_save_cervical = new QPushButton(this);
    MRI_button_venous_corr_save_cervical = new QPushButton(this);
    MRI_button_csf_restore_cervical = new QPushButton(this);
    MRI_button_csf_smooth_cervical = new QPushButton(this);
    MRI_button_csf_save_cervical = new QPushButton(this);
    MRI_button_csf_corr_save_cervical = new QPushButton(this);
    MRI_button_AV_adjust_cervical = new QPushButton(this);
    MRI_button_AV_normalize_cervical = new QPushButton(this);
    MRI_button_AV_smooth_cervical = new QPushButton(this);
    MRI_button_AV_save_cervical = new QPushButton(this);
    MRI_button_ICVC_adjust_cervical = new QPushButton(this);
    MRI_button_ICVC_normalize_cervical = new QPushButton(this);
    MRI_button_ICVC_smooth_cervical = new QPushButton(this);
    MRI_button_ICVC_save_cervical = new QPushButton(this);

    //

    MRI_button_quality_cerebral = new QPushButton(this);

    MRI_button_plot_00_cerebral = new QPushButton(this);
    MRI_button_choice_ncycles_cerebral = new QPushButton(this);

    MRI_button_detect_systole_cerebral = new QPushButton(this);
    MRI_button_adjust_systole_cerebral = new QPushButton(this);
    MRI_button_show_systole_cerebral = new QPushButton(this);

    MRI_button_venous_corr_cerebral = new QPushButton(this);
    MRI_button_csf_corr_cerebral = new QPushButton(this);

    MRI_button_AV_cerebral = new QPushButton(this);
    MRI_button_AV_auto_cerebral = new QPushButton(this);
    MRI_button_ICVC_cerebral = new QPushButton(this);
    MRI_button_ICVC_auto_cerebral = new QPushButton(this);

    MRI_button_arterial_move_right_cerebral = new QPushButton(this);
    MRI_button_arterial_move_left_cerebral = new QPushButton(this);
    MRI_button_venous_move_right_cerebral = new QPushButton(this);
    MRI_button_venous_move_left_cerebral = new QPushButton(this);
    MRI_button_csf_move_right_cerebral = new QPushButton(this);
    MRI_button_csf_move_left_cerebral = new QPushButton(this);

    MRI_button_arterial_restore_cerebral = new QPushButton(this);
    MRI_button_arterial_smooth_cerebral = new QPushButton(this);
    MRI_button_arterial_save_cerebral = new QPushButton(this);
    MRI_button_legend_cerebral = new QPushButton(this);
    MRI_button_venous_restore_cerebral = new QPushButton(this);
    MRI_button_venous_smooth_cerebral = new QPushButton(this);
    MRI_button_venous_save_cerebral = new QPushButton(this);
    MRI_button_venous_corr_save_cerebral = new QPushButton(this);
    MRI_button_csf_restore_cerebral = new QPushButton(this);
    MRI_button_csf_smooth_cerebral = new QPushButton(this);
    MRI_button_csf_save_cerebral = new QPushButton(this);
    MRI_button_csf_corr_save_cerebral = new QPushButton(this);
    MRI_button_AV_adjust_cerebral = new QPushButton(this);
    MRI_button_AV_normalize_cerebral = new QPushButton(this);
    MRI_button_AV_smooth_cerebral = new QPushButton(this);
    MRI_button_AV_save_cerebral = new QPushButton(this);
    MRI_button_ICVC_adjust_cerebral = new QPushButton(this);
    MRI_button_ICVC_normalize_cerebral = new QPushButton(this);
    MRI_button_ICVC_smooth_cerebral = new QPushButton(this);
    MRI_button_ICVC_save_cerebral = new QPushButton(this);

    //

    MRI_button_legend_cervical_cerebral = new QPushButton(this);

    //

    MRI_button_quality_others = new QPushButton(this);

    MRI_button_arterial_move_right_others = new QPushButton(this);
    MRI_button_arterial_move_left_others = new QPushButton(this);
    MRI_button_venous_move_right_others = new QPushButton(this);
    MRI_button_venous_move_left_others = new QPushButton(this);
    MRI_button_csf_move_right_others = new QPushButton(this);
    MRI_button_csf_move_left_others = new QPushButton(this);

    MRI_button_arterial_restore_others = new QPushButton(this);
    MRI_button_arterial_smooth_others = new QPushButton(this);
    MRI_button_arterial_save_others = new QPushButton(this);
    MRI_button_legend_others = new QPushButton(this);
    MRI_button_venous_restore_others = new QPushButton(this);
    MRI_button_venous_smooth_others = new QPushButton(this);
    MRI_button_venous_save_others = new QPushButton(this);
    MRI_button_csf_restore_others = new QPushButton(this);
    MRI_button_csf_smooth_others = new QPushButton(this);
    MRI_button_csf_save_others = new QPushButton(this);

    //

    MRI_button_arterial_choice = new QPushButton(this);
    MRI_button_venous_choice = new QPushButton(this);
    MRI_button_csf_choice = new QPushButton(this);


    //Label
    MRI_label_heart_rate_cervical = new QLabel(this);
    MRI_label_arterial_min_cervical = new QLabel(this);
    MRI_label_arterial_max_cervical = new QLabel(this);
    MRI_label_arterial_mean_cervical = new QLabel(this);
    MRI_label_arterial_grad_cervical = new QLabel(this);
    MRI_label_arterial_stroke_cervical = new QLabel(this);
    MRI_label_venous_corr_cervical = new QLabel(this);
    MRI_label_venous_min_cervical = new QLabel(this);
    MRI_label_venous_max_cervical = new QLabel(this);
    MRI_label_venous_mean_cervical = new QLabel(this);
    MRI_label_venous_grad_cervical = new QLabel(this);
    MRI_label_venous_stroke_cervical = new QLabel(this);
    MRI_label_venous_corr_min_cervical = new QLabel(this);
    MRI_label_venous_corr_max_cervical = new QLabel(this);
    MRI_label_venous_corr_mean_cervical = new QLabel(this);
    MRI_label_venous_corr_grad_cervical = new QLabel(this);
    MRI_label_venous_corr_stroke_cervical = new QLabel(this);
    MRI_label_csf_corr_cervical = new QLabel(this);
    MRI_label_csf_heart_rate_cervical = new QLabel(this);
    MRI_label_csf_min_cervical = new QLabel(this);
    MRI_label_csf_max_cervical = new QLabel(this);
    MRI_label_csf_mean_cervical = new QLabel(this);
    MRI_label_csf_grad_cervical = new QLabel(this);
    MRI_label_csf_stroke_cervical = new QLabel(this);
    MRI_label_csf_corr_min_cervical = new QLabel(this);
    MRI_label_csf_corr_max_cervical = new QLabel(this);
    MRI_label_csf_corr_mean_cervical = new QLabel(this);
    MRI_label_csf_corr_grad_cervical = new QLabel(this);
    MRI_label_csf_corr_stroke_cervical = new QLabel(this);
    MRI_label_AV_flow_min_cervical = new QLabel(this);
    MRI_label_AV_ICVC_ratio_cervical = new QLabel(this);
    MRI_label_AV_flow_max_cervical = new QLabel(this);
    MRI_label_AV_flow_mean_cervical = new QLabel(this);
    MRI_label_AV_flow_grad_cervical = new QLabel(this);
    MRI_label_AV_flow_stroke_cervical = new QLabel(this);
    MRI_label_AV_volume_min_cervical = new QLabel(this);
    MRI_label_AV_volume_max_cervical = new QLabel(this);
    MRI_label_AV_volume_mean_cervical = new QLabel(this);
    MRI_label_AV_volume_grad_cervical = new QLabel(this);
    MRI_label_ICVC_flow_min_cervical = new QLabel(this);
    MRI_label_ICVC_flow_max_cervical = new QLabel(this);
    MRI_label_ICVC_flow_mean_cervical = new QLabel(this);
    MRI_label_ICVC_flow_grad_cervical = new QLabel(this);
    MRI_label_ICVC_flow_stroke_cervical = new QLabel(this);
    MRI_label_ICVC_volume_min_cervical = new QLabel(this);
    MRI_label_ICVC_volume_max_cervical = new QLabel(this);
    MRI_label_ICVC_volume_mean_cervical = new QLabel(this);
    MRI_label_ICVC_volume_grad_cervical = new QLabel(this);
    //
    MRI_label_heart_rate_cerebral = new QLabel(this);
    MRI_label_arterial_min_cerebral = new QLabel(this);
    MRI_label_arterial_max_cerebral = new QLabel(this);
    MRI_label_arterial_mean_cerebral = new QLabel(this);
    MRI_label_arterial_grad_cerebral = new QLabel(this);
    MRI_label_arterial_stroke_cerebral = new QLabel(this);
    MRI_label_venous_corr_cerebral = new QLabel(this);
    MRI_label_venous_min_cerebral = new QLabel(this);
    MRI_label_venous_max_cerebral = new QLabel(this);
    MRI_label_venous_mean_cerebral = new QLabel(this);
    MRI_label_venous_grad_cerebral = new QLabel(this);
    MRI_label_venous_stroke_cerebral = new QLabel(this);
    MRI_label_venous_corr_min_cerebral = new QLabel(this);
    MRI_label_venous_corr_max_cerebral = new QLabel(this);
    MRI_label_venous_corr_mean_cerebral = new QLabel(this);
    MRI_label_venous_corr_grad_cerebral = new QLabel(this);
    MRI_label_venous_corr_stroke_cerebral = new QLabel(this);
    MRI_label_csf_corr_cerebral = new QLabel(this);
    MRI_label_csf_heart_rate_cerebral = new QLabel(this);
    MRI_label_csf_min_cerebral = new QLabel(this);
    MRI_label_csf_max_cerebral = new QLabel(this);
    MRI_label_csf_mean_cerebral = new QLabel(this);
    MRI_label_csf_grad_cerebral = new QLabel(this);
    MRI_label_csf_stroke_cerebral = new QLabel(this);
    MRI_label_csf_corr_min_cerebral = new QLabel(this);
    MRI_label_csf_corr_max_cerebral = new QLabel(this);
    MRI_label_csf_corr_mean_cerebral = new QLabel(this);
    MRI_label_csf_corr_grad_cerebral = new QLabel(this);
    MRI_label_csf_corr_stroke_cerebral = new QLabel(this);
    MRI_label_AV_ICVC_ratio_cerebral = new QLabel(this);
    MRI_label_AV_flow_min_cerebral = new QLabel(this);
    MRI_label_AV_flow_max_cerebral = new QLabel(this);
    MRI_label_AV_flow_mean_cerebral = new QLabel(this);
    MRI_label_AV_flow_grad_cerebral = new QLabel(this);
    MRI_label_AV_flow_stroke_cerebral = new QLabel(this);
    MRI_label_AV_volume_min_cerebral = new QLabel(this);
    MRI_label_AV_volume_max_cerebral = new QLabel(this);
    MRI_label_AV_volume_mean_cerebral = new QLabel(this);
    MRI_label_AV_volume_grad_cerebral = new QLabel(this);
    MRI_label_ICVC_flow_min_cerebral = new QLabel(this);
    MRI_label_ICVC_flow_max_cerebral = new QLabel(this);
    MRI_label_ICVC_flow_mean_cerebral = new QLabel(this);
    MRI_label_ICVC_flow_grad_cerebral = new QLabel(this);
    MRI_label_ICVC_flow_stroke_cerebral = new QLabel(this);
    MRI_label_ICVC_volume_min_cerebral = new QLabel(this);
    MRI_label_ICVC_volume_max_cerebral = new QLabel(this);
    MRI_label_ICVC_volume_mean_cerebral = new QLabel(this);
    MRI_label_ICVC_volume_grad_cerebral = new QLabel(this);
    //
    MRI_label_arterial_dphi = new QLabel(this);
    MRI_label_venous_dphi = new QLabel(this);
    MRI_label_csf_dphi = new QLabel(this);
    MRI_label_AV_flow_dphi = new QLabel(this);
    MRI_label_AV_volume_dphi = new QLabel(this);
    MRI_label_ICVC_flow_dphi = new QLabel(this);
    MRI_label_ICVC_volume_dphi = new QLabel(this);
    //
    MRI_label_heart_rate_others = new QLabel(this);
    MRI_label_arterial_min_others = new QLabel(this);
    MRI_label_arterial_max_others = new QLabel(this);
    MRI_label_arterial_mean_others = new QLabel(this);
    MRI_label_arterial_grad_others = new QLabel(this);
    MRI_label_arterial_stroke_others = new QLabel(this);
    MRI_label_venous_min_others = new QLabel(this);
    MRI_label_venous_max_others = new QLabel(this);
    MRI_label_venous_mean_others = new QLabel(this);
    MRI_label_venous_grad_others = new QLabel(this);
    MRI_label_venous_stroke_others = new QLabel(this);
    MRI_label_csf_heart_rate_others = new QLabel(this);
    MRI_label_csf_min_others = new QLabel(this);
    MRI_label_csf_max_others = new QLabel(this);
    MRI_label_csf_mean_others = new QLabel(this);
    MRI_label_csf_grad_others = new QLabel(this);
    MRI_label_csf_stroke_others = new QLabel(this);

    //String
    MRI_arterial_files_cervical = new QStringList;
    MRI_venous_files_cervical = new QStringList;
    MRI_CSF_files_cervical = new QStringList;
    MRI_arterial_files_cerebral = new QStringList;
    MRI_venous_files_cerebral = new QStringList;
    MRI_CSF_files_cerebral = new QStringList;
    MRI_arterial_files_other = new QStringList;
    MRI_venous_files_other = new QStringList;
    MRI_csf_files_other = new QStringList;

    //Int
    MRI_number_arterial = 0;
    MRI_number_venous = 0;
    MRI_number_csf = 0;

    MRI_legend_cervical = LEGEND_ON;
    MRI_legend_cerebral = LEGEND_ON;
    MRI_legend_cervical_cerebral = LEGEND_ON;
    MRI_legend_others = LEGEND_ON;

    MRI_plot_00_cervical = 0;
    MRI_plot_00_cerebral = 0;

    MRI_ncycles_cervical = 1;
    MRI_ncycles_cerebral = 1;

    MRI_quality_arterial_cervical = QUALITY5;
    MRI_quality_venous_cervical = QUALITY5;
    MRI_quality_csf_cervical = QUALITY5;
    MRI_quality_arterial_cerebral = QUALITY5;
    MRI_quality_venous_cerebral = QUALITY5;
    MRI_quality_csf_cerebral = QUALITY5;

    MRI_quality_arterial_other = NULL;
    MRI_quality_venous_other = NULL;
    MRI_quality_csf_other = NULL;

    MRI_AV_flow_cervical_normalized = 0;
    MRI_AV_volume_cervical_normalized = 0;
    MRI_ICVC_flow_cervical_normalized = 0;
    MRI_ICVC_volume_cervical_normalized = 0;

    MRI_AV_flow_cerebral_normalized = 0;
    MRI_AV_volume_cerebral_normalized = 0;
    MRI_ICVC_flow_cerebral_normalized = 0;
    MRI_ICVC_volume_cerebral_normalized = 0;
}

/*!
 * \brief MainWindow::init_MRI_win
 */
void MainWindow::init_MRI_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Button
    MRI_button_quality_cervical->setText(MAINWINDOW_MRI_QUALITY);

    MRI_button_plot_00_cervical->setText("Plot (0,0)");
    MRI_button_choice_ncycles_cervical->setText("Num Cycles");
    MRI_button_choice_ncycles_cervical->setMenu(MRI_menu_ncycles_cervical);
    {
        QAction *action_ncycles_1 = new QAction("1", this);
        QAction *action_ncycles_2 = new QAction("2", this);
        QAction *action_ncycles_3 = new QAction("3", this);
        action_ncycles_1->setCheckable(true);
        action_ncycles_1->setChecked(true);
        action_ncycles_2->setCheckable(true);
        action_ncycles_3->setCheckable(true);
        MRI_menu_ncycles_cervical->addAction(action_ncycles_1);
        MRI_menu_ncycles_cervical->addAction(action_ncycles_2);
        MRI_menu_ncycles_cervical->addAction(action_ncycles_3);
    }

    MRI_button_detect_systole_cervical->setText(MAINWINDOW_MRI_SYST_DETECT);
    MRI_button_adjust_systole_cervical->setText(MAINWINDOW_MRI_SYST_ADJ);
    MRI_button_show_systole_cervical->setText("Hide systole");

    MRI_button_venous_corr_cervical->setText(MAINWINDOW_MRI_AVCONS);
    MRI_button_csf_corr_cervical->setText(MAINWINDOW_MRI_CMEAN);
    MRI_button_AV_cervical->setText(MAINWINDOW_MRI_AV);
    MRI_button_AV_auto_cervical->setText(MAINWINDOW_MRI_AV_AUTO);
    MRI_button_ICVC_cervical->setText(MAINWINDOW_MRI_ICVC);
    MRI_button_ICVC_auto_cervical->setText(MAINWINDOW_MRI_ICVC_AUTO);

    MRI_button_arterial_move_right_cervical->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_arterial_move_right_cervical->setToolTip(MAINWINDOW_MRI_MOVE_A_RIGHT);
    MRI_button_arterial_move_left_cervical->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_arterial_move_left_cervical->setToolTip(MAINWINDOW_MRI_MOVE_A_LEFT);
    MRI_button_venous_move_right_cervical->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_venous_move_right_cervical->setToolTip(MAINWINDOW_MRI_MOVE_V_RIGHT);
    MRI_button_venous_move_left_cervical->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_venous_move_left_cervical->setToolTip(MAINWINDOW_MRI_MOVE_V_LEFT);
    MRI_button_csf_move_right_cervical->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_csf_move_right_cervical->setToolTip(MAINWINDOW_MRI_MOVE_C_RIGHT);
    MRI_button_csf_move_left_cervical->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_csf_move_left_cervical->setToolTip(MAINWINDOW_MRI_MOVE_C_LEFT);

    MRI_button_arterial_restore_cervical->setIcon(QIcon(IMG_RESTORE));
    MRI_button_arterial_restore_cervical->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_arterial_smooth_cervical->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_arterial_smooth_cervical->setToolTip(MAINWINDOW_MRI_SMOOTH_A);
    MRI_button_arterial_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_arterial_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_A);
    MRI_button_legend_cervical->setIcon(QIcon(IMG_LEGEND));
    MRI_button_legend_cervical->setToolTip(MAINWINDOW_MRI_LEGEND);
    MRI_button_venous_restore_cervical->setIcon(QIcon(IMG_RESTORE));
    MRI_button_venous_restore_cervical->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_venous_smooth_cervical->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_venous_smooth_cervical->setToolTip(MAINWINDOW_MRI_SMOOTH_V);
    MRI_button_venous_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_venous_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_V);
    MRI_button_venous_corr_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_venous_corr_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_V2);
    MRI_button_csf_restore_cervical->setIcon(QIcon(IMG_RESTORE));
    MRI_button_csf_restore_cervical->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_csf_smooth_cervical->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_csf_smooth_cervical->setToolTip(MAINWINDOW_MRI_SMOOTH_C);
    MRI_button_csf_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_csf_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_C);
    MRI_button_csf_corr_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_csf_corr_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_C2);
    MRI_button_AV_adjust_cervical->setIcon(QIcon(IMG_ADJUST));
    MRI_button_AV_adjust_cervical->setToolTip(MAINWINDOW_MRI_ADJ_AV);
    MRI_button_AV_normalize_cervical->setIcon(QIcon(IMG_NORMALIZE));
    MRI_button_AV_normalize_cervical->setToolTip(MAINWINDOW_MRI_NORM_AV);
    MRI_button_AV_smooth_cervical->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_AV_smooth_cervical->setToolTip(MAINWINDOW_MRI_SMOOTH_AV);
    MRI_button_AV_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_AV_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_AV);
    MRI_button_ICVC_adjust_cervical->setIcon(QIcon(IMG_ADJUST));
    MRI_button_ICVC_adjust_cervical->setToolTip(MAINWINDOW_MRI_ADJ_ICVC);
    MRI_button_ICVC_normalize_cervical->setIcon(QIcon(IMG_NORMALIZE));
    MRI_button_ICVC_normalize_cervical->setToolTip(MAINWINDOW_MRI_NORM_ICVC);
    MRI_button_ICVC_smooth_cervical->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_ICVC_smooth_cervical->setToolTip(MAINWINDOW_MRI_SMOOTH_ICVC);
    MRI_button_ICVC_save_cervical->setIcon(QIcon(IMG_SAVE));
    MRI_button_ICVC_save_cervical->setToolTip(MAINWINDOW_MRI_SAVE_ICVC);

    //

    MRI_button_quality_cerebral->setText(MAINWINDOW_MRI_QUALITY);

    MRI_button_plot_00_cerebral->setText("Plot (0,0)");
    MRI_button_choice_ncycles_cerebral->setText("Num Cycles");
    MRI_button_choice_ncycles_cerebral->setMenu(MRI_menu_ncycles_cerebral);
    {
        QAction *action_ncycles_1 = new QAction("1", this);
        QAction *action_ncycles_2 = new QAction("2", this);
        QAction *action_ncycles_3 = new QAction("3", this);
        action_ncycles_1->setCheckable(true);
        action_ncycles_1->setChecked(true);
        action_ncycles_2->setCheckable(true);
        action_ncycles_3->setCheckable(true);
        MRI_menu_ncycles_cerebral->addAction(action_ncycles_1);
        MRI_menu_ncycles_cerebral->addAction(action_ncycles_2);
        MRI_menu_ncycles_cerebral->addAction(action_ncycles_3);
    }

    MRI_button_detect_systole_cerebral->setText(MAINWINDOW_MRI_SYST_DETECT);
    MRI_button_adjust_systole_cerebral->setText(MAINWINDOW_MRI_SYST_ADJ);
    MRI_button_show_systole_cerebral->setText("Hide systole");

    MRI_button_venous_corr_cerebral->setText(MAINWINDOW_MRI_AVCONS);
    MRI_button_csf_corr_cerebral->setText(MAINWINDOW_MRI_CMEAN);
    MRI_button_AV_cerebral->setText(MAINWINDOW_MRI_AV);
    MRI_button_AV_auto_cerebral->setText(MAINWINDOW_MRI_AV_AUTO);
    MRI_button_ICVC_cerebral->setText(MAINWINDOW_MRI_ICVC_CERERBAL);
    MRI_button_ICVC_auto_cerebral->setText(MAINWINDOW_MRI_ICVC_AUTO);

    MRI_button_arterial_move_right_cerebral->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_arterial_move_right_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_A_RIGHT);
    MRI_button_arterial_move_left_cerebral->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_arterial_move_left_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_A_LEFT);
    MRI_button_venous_move_right_cerebral->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_venous_move_right_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_V_RIGHT);
    MRI_button_venous_move_left_cerebral->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_venous_move_left_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_V_LEFT);
    MRI_button_csf_move_right_cerebral->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_csf_move_right_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_C_RIGHT);
    MRI_button_csf_move_left_cerebral->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_csf_move_left_cerebral->setToolTip(MAINWINDOW_MRI_MOVE_C_LEFT);

    MRI_button_arterial_restore_cerebral->setIcon(QIcon(IMG_RESTORE));
    MRI_button_arterial_restore_cerebral->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_arterial_smooth_cerebral->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_arterial_smooth_cerebral->setToolTip(MAINWINDOW_MRI_SMOOTH_A);
    MRI_button_arterial_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_arterial_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_A);
    MRI_button_legend_cerebral->setIcon(QIcon(IMG_LEGEND));
    MRI_button_legend_cerebral->setToolTip(MAINWINDOW_MRI_LEGEND);
    MRI_button_venous_restore_cerebral->setIcon(QIcon(IMG_RESTORE));
    MRI_button_venous_restore_cerebral->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_venous_smooth_cerebral->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_venous_smooth_cerebral->setToolTip(MAINWINDOW_MRI_SMOOTH_V);
    MRI_button_venous_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_venous_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_V);
    MRI_button_venous_corr_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_venous_corr_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_V2);
    MRI_button_csf_restore_cerebral->setIcon(QIcon(IMG_RESTORE));
    MRI_button_csf_restore_cerebral->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_csf_smooth_cerebral->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_csf_smooth_cerebral->setToolTip(MAINWINDOW_MRI_SMOOTH_C);
    MRI_button_csf_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_csf_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_C);
    MRI_button_csf_corr_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_csf_corr_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_C2);
    MRI_button_AV_adjust_cerebral->setIcon(QIcon(IMG_ADJUST));
    MRI_button_AV_adjust_cerebral->setToolTip(MAINWINDOW_MRI_ADJ_AV);
    MRI_button_AV_normalize_cerebral->setIcon(QIcon(IMG_NORMALIZE));
    MRI_button_AV_normalize_cerebral->setToolTip(MAINWINDOW_MRI_NORM_AV);
    MRI_button_AV_smooth_cerebral->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_AV_smooth_cerebral->setToolTip(MAINWINDOW_MRI_SMOOTH_AV);
    MRI_button_AV_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_AV_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_AV);
    MRI_button_ICVC_adjust_cerebral->setIcon(QIcon(IMG_ADJUST));
    MRI_button_ICVC_adjust_cerebral->setToolTip(MAINWINDOW_MRI_ADJ_ICVC);
    MRI_button_ICVC_normalize_cerebral->setIcon(QIcon(IMG_NORMALIZE));
    MRI_button_ICVC_normalize_cerebral->setToolTip(MAINWINDOW_MRI_NORM_ICVC);
    MRI_button_ICVC_smooth_cerebral->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_ICVC_smooth_cerebral->setToolTip(MAINWINDOW_MRI_SMOOTH_ICVC);
    MRI_button_ICVC_save_cerebral->setIcon(QIcon(IMG_SAVE));
    MRI_button_ICVC_save_cerebral->setToolTip(MAINWINDOW_MRI_SAVE_ICVC);

    //

    MRI_button_arterial_choice->setText("Arterial");
    //MRI_button_arterial_choice->set
    MRI_button_arterial_choice->setMenu(MRI_arterial_menu);
    MRI_button_venous_choice->setText("Venous");
    MRI_button_venous_choice->setMenu(MRI_venous_menu);
    MRI_button_csf_choice->setText("CSF");
    MRI_button_csf_choice->setMenu(MRI_csf_menu);
    MRI_button_legend_cervical_cerebral->setIcon(QIcon(IMG_LEGEND));
    MRI_button_legend_cervical_cerebral->setToolTip(MAINWINDOW_MRI_LEGEND);

    //

    MRI_button_quality_others->setText(MAINWINDOW_MRI_QUALITY);

    MRI_button_arterial_move_right_others->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_arterial_move_right_others->setToolTip(MAINWINDOW_MRI_MOVE_A_RIGHT);
    MRI_button_arterial_move_left_others->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_arterial_move_left_others->setToolTip(MAINWINDOW_MRI_MOVE_A_LEFT);
    MRI_button_venous_move_right_others->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_venous_move_right_others->setToolTip(MAINWINDOW_MRI_MOVE_V_RIGHT);
    MRI_button_venous_move_left_others->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_venous_move_left_others->setToolTip(MAINWINDOW_MRI_MOVE_V_LEFT);
    MRI_button_csf_move_right_others->setIcon(QIcon(IMG_RIGHT_ARROW));
    MRI_button_csf_move_right_others->setToolTip(MAINWINDOW_MRI_MOVE_C_RIGHT);
    MRI_button_csf_move_left_others->setIcon(QIcon(IMG_LEFT_ARROW));
    MRI_button_csf_move_left_others->setToolTip(MAINWINDOW_MRI_MOVE_C_LEFT);

    MRI_button_arterial_restore_others->setIcon(QIcon(IMG_RESTORE));
    MRI_button_arterial_restore_others->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_arterial_smooth_others->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_arterial_smooth_others->setToolTip(MAINWINDOW_MRI_SMOOTH_A);
    MRI_button_arterial_save_others->setIcon(QIcon(IMG_SAVE));
    MRI_button_arterial_save_others->setToolTip(MAINWINDOW_MRI_SAVE_A);
    MRI_button_legend_others->setIcon(QIcon(IMG_LEGEND));
    MRI_button_legend_others->setToolTip(MAINWINDOW_MRI_LEGEND);
    MRI_button_venous_restore_others->setIcon(QIcon(IMG_RESTORE));
    MRI_button_venous_restore_others->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_venous_smooth_others->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_venous_smooth_others->setToolTip(MAINWINDOW_MRI_SMOOTH_V);
    MRI_button_venous_save_others->setIcon(QIcon(IMG_SAVE));
    MRI_button_venous_save_others->setToolTip(MAINWINDOW_MRI_SAVE_V);
    MRI_button_csf_restore_others->setIcon(QIcon(IMG_RESTORE));
    MRI_button_csf_restore_others->setToolTip(MAINWINDOW_MRI_RESTORE);
    MRI_button_csf_smooth_others->setIcon(QIcon(IMG_SMOOTH));
    MRI_button_csf_smooth_others->setToolTip(MAINWINDOW_MRI_SMOOTH_C);
    MRI_button_csf_save_others->setIcon(QIcon(IMG_SAVE));
    MRI_button_csf_save_others->setToolTip(MAINWINDOW_MRI_SAVE_C);


    //Check
    MRI_check_move_cervical->setIcon(QIcon(IMG_LOCK));
    MRI_check_move_cervical->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    MRI_check_move_cervical->setToolTip(MAINWINDOW_MRI_LOCK);
    MRI_check_venous_cervical->setIcon(QIcon(IMG_POSITIVE));
    MRI_check_venous_cervical->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    MRI_check_venous_cervical->setToolTip("Positive");
    MRI_check_AV_csf_cervical->setText("Show CSF");
    //
    MRI_check_move_cerebral->setIcon(QIcon(IMG_LOCK));
    MRI_check_move_cerebral->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    MRI_check_move_cerebral->setToolTip(MAINWINDOW_MRI_LOCK);
    MRI_check_venous_cerebral->setIcon(QIcon(IMG_POSITIVE));
    MRI_check_venous_cerebral->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    MRI_check_venous_cerebral->setToolTip("Positive");
    MRI_check_AV_csf_cerebral->setText("Show CSF");
    //
    MRI_check_venous_cervical_cerebral->setText("Plot all");
    MRI_check_csf_cervical_cerebral->setText("Plot all");
    //
    MRI_check_move_others->setIcon(QIcon(IMG_LOCK));
    MRI_check_move_others->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    MRI_check_move_others->setToolTip(MAINWINDOW_MRI_LOCK);

    //Box
    MRI_box_systole_threshold_cervical->setRange(0., 0.);
    MRI_box_systole_delay_cervical->setRange(0, 0);
    MRI_box_arterial_move_cervical->setRange(-npi, npi);
    MRI_box_arterial_move_cervical->setEnabled(false);
    MRI_box_venous_move_cervical->setRange(-npi, npi);
    MRI_box_venous_move_cervical->setEnabled(false);
    MRI_box_csf_move_cervical->setRange(-npi, npi);
    MRI_box_csf_move_cervical->setEnabled(false);
    MRI_box_AV_flow_volume_cervical->addItem(MAINWINDOW_MRI_FV_ITEM01);
    MRI_box_AV_flow_volume_cervical->addItem(MAINWINDOW_MRI_FV_ITEM02);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM1);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM2);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM3);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM4);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM5);
    MRI_box_AV_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM6);
    MRI_box_ICVC_flow_volume_cervical->addItem(MAINWINDOW_MRI_FV_ITEM01);
    MRI_box_ICVC_flow_volume_cervical->addItem(MAINWINDOW_MRI_FV_ITEM02);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM1);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM2);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM3);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM4);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM5);
    MRI_box_ICVC_adjust_cervical->addItem(MAINWINDOW_ADJUST_ITEM6);
    //
    MRI_box_systole_threshold_cerebral->setRange(0., 0.);
    MRI_box_systole_delay_cerebral->setRange(0, 0);
    MRI_box_arterial_move_cerebral->setRange(-npi, npi);
    MRI_box_arterial_move_cerebral->setEnabled(false);
    MRI_box_venous_move_cerebral->setRange(-npi, npi);
    MRI_box_venous_move_cerebral->setEnabled(false);
    MRI_box_csf_move_cerebral->setRange(-npi, npi);
    MRI_box_csf_move_cerebral->setEnabled(false);
    MRI_box_AV_flow_volume_cerebral->addItem(MAINWINDOW_MRI_FV_ITEM01);
    MRI_box_AV_flow_volume_cerebral->addItem(MAINWINDOW_MRI_FV_ITEM02);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM1);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM2);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM3);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM4);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM5);
    MRI_box_AV_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM6);
    MRI_box_ICVC_flow_volume_cerebral->addItem(MAINWINDOW_MRI_FV_ITEM01);
    MRI_box_ICVC_flow_volume_cerebral->addItem(MAINWINDOW_MRI_FV_ITEM02);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM1);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM2);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM3);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM4);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM5);
    MRI_box_ICVC_adjust_cerebral->addItem(MAINWINDOW_ADJUST_ITEM6);

    //Coord
    //...   Nothing to do

    //Plot
    MRI_plot_arterial_cervical->addGraph(); //arterial
    MRI_plot_arterial_cervical->addGraph(); //systole
    MRI_plot_venous_cervical->addGraph();   //venous
    MRI_plot_venous_cervical->addGraph();   //corrected venous
    MRI_plot_csf_cervical->addGraph();      //csf
    MRI_plot_csf_cervical->addGraph();      //corrected csf
    MRI_plot_AV_cervical->addGraph();       //AV
    MRI_plot_AV_cervical->addGraph();       //csf
    MRI_plot_ICVC_cervical->addGraph();     //ICVC
    //
    MRI_plot_arterial_cerebral->addGraph(); //arterial
    MRI_plot_arterial_cerebral->addGraph(); //systole
    MRI_plot_venous_cerebral->addGraph();   //venous
    MRI_plot_venous_cerebral->addGraph();   //corrected venous
    MRI_plot_csf_cerebral->addGraph();      //csf
    MRI_plot_csf_cerebral->addGraph();      //corrected csf
    MRI_plot_AV_cerebral->addGraph();       //AV
    MRI_plot_AV_cerebral->addGraph();       //csf
    MRI_plot_ICVC_cerebral->addGraph();     //ICVC
    //
    MRI_plot_arterial_cervical_cerebral->addGraph(); //arterial cervical
    MRI_plot_arterial_cervical_cerebral->addGraph(); //arterial cerebral
    MRI_plot_arterial_cervical_cerebral->addGraph(); //Max cervical
    MRI_plot_arterial_cervical_cerebral->addGraph(); //Max cerebral
    MRI_plot_venous_cervical_cerebral->addGraph();   //venous cervical
    MRI_plot_venous_cervical_cerebral->addGraph();   //venous cerebral
    MRI_plot_venous_cervical_cerebral->addGraph();   //corrected venous cervical
    MRI_plot_venous_cervical_cerebral->addGraph();   //corrected venous cerebral
    MRI_plot_venous_cervical_cerebral->addGraph();   //Max cervical
    MRI_plot_venous_cervical_cerebral->addGraph();   //Max cerebral
    MRI_plot_csf_cervical_cerebral->addGraph();      //csf cervical
    MRI_plot_csf_cervical_cerebral->addGraph();      //csf cerebral
    MRI_plot_csf_cervical_cerebral->addGraph();      //corrected csf cervical
    MRI_plot_csf_cervical_cerebral->addGraph();      //corrected csf cerebral
    MRI_plot_csf_cervical_cerebral->addGraph();      //Max cervical
    MRI_plot_csf_cervical_cerebral->addGraph();      //Max cerebral
    MRI_plot_AV_flow_cervical_cerebral->addGraph();     //AV flow cervical
    MRI_plot_AV_flow_cervical_cerebral->addGraph();     //AV flow cerebral
    MRI_plot_AV_flow_cervical_cerebral->addGraph();     //Max AV flow cervical
    MRI_plot_AV_flow_cervical_cerebral->addGraph();     //Max AV flow cerebral
    MRI_plot_AV_volume_cervical_cerebral->addGraph();   //AV volume cervical
    MRI_plot_AV_volume_cervical_cerebral->addGraph();   //AV volume cerebral
    MRI_plot_AV_volume_cervical_cerebral->addGraph();   //Max AV volume cervical
    MRI_plot_AV_volume_cervical_cerebral->addGraph();   //Max AV volume cerebral
    MRI_plot_ICVC_flow_cervical_cerebral->addGraph();   //ICVC flow cervical
    MRI_plot_ICVC_flow_cervical_cerebral->addGraph();   //ICVC flow cerebral
    MRI_plot_ICVC_flow_cervical_cerebral->addGraph();   //Max ICVC flow cervical
    MRI_plot_ICVC_flow_cervical_cerebral->addGraph();   //Max ICVC flow cerebral
    MRI_plot_ICVC_volume_cervical_cerebral->addGraph(); //ICVC volume cervical
    MRI_plot_ICVC_volume_cervical_cerebral->addGraph(); //ICVC volume cerebral
    MRI_plot_ICVC_volume_cervical_cerebral->addGraph(); //Max ICVC volume cervical
    MRI_plot_ICVC_volume_cervical_cerebral->addGraph(); //Max ICVC volume cerebral
    //
    MRI_plot_arterial_spectrum->addGraph();             //Arterial cervical
    MRI_plot_arterial_spectrum->addGraph();             //Arterial cerebral
    MRI_plot_venous_spectrum->addGraph();               //Venous cervical
    MRI_plot_venous_spectrum->addGraph();               //Venous cerebral
    MRI_plot_csf_spectrum->addGraph();                  //CSF cervical
    MRI_plot_csf_spectrum->addGraph();                  //CSF cerebral
    MRI_plot_AV_flow_spectrum->addGraph();              //AV flow cervical
    MRI_plot_AV_flow_spectrum->addGraph();              //AV flow cerebral
    MRI_plot_AV_volume_spectrum->addGraph();            //AV volume cervical
    MRI_plot_AV_volume_spectrum->addGraph();            //AV volume cerebral
    MRI_plot_ICVC_flow_spectrum->addGraph();            //ICVC flow cervical
    MRI_plot_ICVC_flow_spectrum->addGraph();            //ICVC flow cerebral
    MRI_plot_ICVC_volume_spectrum->addGraph();          //ICVC volume cervical
    MRI_plot_ICVC_volume_spectrum->addGraph();          //ICVC volume cerebral
    //
    MRI_plot_arterial_others->addGraph();   //arterial
    MRI_plot_venous_others->addGraph();     //venous
    MRI_plot_csf_others->addGraph();        //csf

    //VBox
    MRI_vbox_arterial_move_cervical->addWidget(MRI_button_arterial_move_right_cervical);
    MRI_vbox_arterial_move_cervical->addWidget(MRI_box_arterial_move_cervical);
    MRI_vbox_arterial_move_cervical->addWidget(MRI_button_arterial_move_left_cervical);
    MRI_vbox_arterial_move_cervical->addWidget(MRI_check_move_cervical);

    MRI_vbox_arterial_button_cervical->addWidget(MRI_button_arterial_restore_cervical);
    MRI_vbox_arterial_button_cervical->addWidget(MRI_button_arterial_smooth_cervical);
    MRI_vbox_arterial_button_cervical->addWidget(MRI_button_arterial_save_cervical);
    MRI_vbox_arterial_button_cervical->addWidget(MRI_button_legend_cervical);

    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_heart_rate_cervical);
    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_arterial_min_cervical);
    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_arterial_max_cervical);
    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_arterial_mean_cervical);
    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_arterial_grad_cervical);
    MRI_vbox_arterial_label_cervical->addWidget(MRI_label_arterial_stroke_cervical);

    MRI_vbox_venous_move_cervical->addWidget(MRI_button_venous_move_right_cervical);
    MRI_vbox_venous_move_cervical->addWidget(MRI_box_venous_move_cervical);
    MRI_vbox_venous_move_cervical->addWidget(MRI_button_venous_move_left_cervical);
    MRI_vbox_venous_move_cervical->addWidget(MRI_check_venous_cervical);

    MRI_vbox_venous_button_cervical->addWidget(MRI_button_venous_restore_cervical);
    MRI_vbox_venous_button_cervical->addWidget(MRI_button_venous_smooth_cervical);
    MRI_vbox_venous_button_cervical->addWidget(MRI_button_venous_save_cervical);
    MRI_vbox_venous_button_cervical->addWidget(MRI_button_venous_corr_save_cervical);

    MRI_vbox_venous_label_cervical->addWidget(MRI_label_venous_min_cervical);
    MRI_vbox_venous_label_cervical->addWidget(MRI_label_venous_max_cervical);
    MRI_vbox_venous_label_cervical->addWidget(MRI_label_venous_mean_cervical);
    MRI_vbox_venous_label_cervical->addWidget(MRI_label_venous_grad_cervical);
    MRI_vbox_venous_label_cervical->addWidget(MRI_label_venous_stroke_cervical);

    MRI_vbox_venous_corr_label_cervical->addWidget(MRI_label_venous_corr_min_cervical);
    MRI_vbox_venous_corr_label_cervical->addWidget(MRI_label_venous_corr_max_cervical);
    MRI_vbox_venous_corr_label_cervical->addWidget(MRI_label_venous_corr_mean_cervical);
    MRI_vbox_venous_corr_label_cervical->addWidget(MRI_label_venous_corr_grad_cervical);
    MRI_vbox_venous_corr_label_cervical->addWidget(MRI_label_venous_corr_stroke_cervical);

    MRI_vbox_csf_move_cervical->addWidget(MRI_button_csf_move_right_cervical);
    MRI_vbox_csf_move_cervical->addWidget(MRI_box_csf_move_cervical);
    MRI_vbox_csf_move_cervical->addWidget(MRI_button_csf_move_left_cervical);

    MRI_vbox_csf_button_cervical->addWidget(MRI_button_csf_restore_cervical);
    MRI_vbox_csf_button_cervical->addWidget(MRI_button_csf_smooth_cervical);
    MRI_vbox_csf_button_cervical->addWidget(MRI_button_csf_save_cervical);
    MRI_vbox_csf_button_cervical->addWidget(MRI_button_csf_corr_save_cervical);

    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_heart_rate_cervical);
    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_min_cervical);
    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_max_cervical);
    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_mean_cervical);
    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_grad_cervical);
    MRI_vbox_csf_label_cervical->addWidget(MRI_label_csf_stroke_cervical);

    MRI_vbox_csf_corr_label_cervical->addWidget(MRI_label_csf_corr_min_cervical);
    MRI_vbox_csf_corr_label_cervical->addWidget(MRI_label_csf_corr_max_cervical);
    MRI_vbox_csf_corr_label_cervical->addWidget(MRI_label_csf_corr_mean_cervical);
    MRI_vbox_csf_corr_label_cervical->addWidget(MRI_label_csf_corr_grad_cervical);
    MRI_vbox_csf_corr_label_cervical->addWidget(MRI_label_csf_corr_stroke_cervical);

    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_flow_min_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_flow_max_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_flow_mean_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_flow_grad_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_flow_stroke_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_volume_min_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_volume_max_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_volume_mean_cervical);
    MRI_vbox_AV_label_cervical->addWidget(MRI_label_AV_volume_grad_cervical);

    MRI_hbox_AV_cervical->addWidget(MRI_check_AV_csf_cervical);
    MRI_hbox_AV_cervical->addWidget(MRI_button_AV_adjust_cervical);
    MRI_hbox_AV_cervical->addWidget(MRI_box_AV_adjust_cervical);
    MRI_hbox_AV_cervical->addWidget(MRI_button_AV_normalize_cervical);
    MRI_hbox_AV_cervical->addWidget(MRI_button_AV_smooth_cervical);
    MRI_hbox_AV_cervical->addWidget(MRI_button_AV_save_cervical);

    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_flow_min_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_flow_max_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_flow_mean_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_flow_grad_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_flow_stroke_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_volume_min_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_volume_max_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_volume_mean_cervical);
    MRI_vbox_ICVC_label_cervical->addWidget(MRI_label_ICVC_volume_grad_cervical);

    MRI_hbox_ICVC_cervical->addWidget(MRI_button_ICVC_adjust_cervical);
    MRI_hbox_ICVC_cervical->addWidget(MRI_box_ICVC_adjust_cervical);
    MRI_hbox_ICVC_cervical->addWidget(MRI_button_ICVC_normalize_cervical);
    MRI_hbox_ICVC_cervical->addWidget(MRI_button_ICVC_smooth_cervical);
    MRI_hbox_ICVC_cervical->addWidget(MRI_button_ICVC_save_cervical);

    //

    MRI_vbox_arterial_move_cerebral->addWidget(MRI_button_arterial_move_right_cerebral);
    MRI_vbox_arterial_move_cerebral->addWidget(MRI_box_arterial_move_cerebral);
    MRI_vbox_arterial_move_cerebral->addWidget(MRI_button_arterial_move_left_cerebral);
    MRI_vbox_arterial_move_cerebral->addWidget(MRI_check_move_cerebral);

    MRI_vbox_arterial_button_cerebral->addWidget(MRI_button_arterial_restore_cerebral);
    MRI_vbox_arterial_button_cerebral->addWidget(MRI_button_arterial_smooth_cerebral);
    MRI_vbox_arterial_button_cerebral->addWidget(MRI_button_arterial_save_cerebral);
    MRI_vbox_arterial_button_cerebral->addWidget(MRI_button_legend_cerebral);

    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_heart_rate_cerebral);
    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_arterial_min_cerebral);
    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_arterial_max_cerebral);
    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_arterial_mean_cerebral);
    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_arterial_grad_cerebral);
    MRI_vbox_arterial_label_cerebral->addWidget(MRI_label_arterial_stroke_cerebral);

    MRI_vbox_venous_move_cerebral->addWidget(MRI_button_venous_move_right_cerebral);
    MRI_vbox_venous_move_cerebral->addWidget(MRI_box_venous_move_cerebral);
    MRI_vbox_venous_move_cerebral->addWidget(MRI_button_venous_move_left_cerebral);
    MRI_vbox_venous_move_cerebral->addWidget(MRI_check_venous_cerebral);

    MRI_vbox_venous_button_cerebral->addWidget(MRI_button_venous_restore_cerebral);
    MRI_vbox_venous_button_cerebral->addWidget(MRI_button_venous_smooth_cerebral);
    MRI_vbox_venous_button_cerebral->addWidget(MRI_button_venous_save_cerebral);
    MRI_vbox_venous_button_cerebral->addWidget(MRI_button_venous_corr_save_cerebral);

    MRI_vbox_venous_label_cerebral->addWidget(MRI_label_venous_min_cerebral);
    MRI_vbox_venous_label_cerebral->addWidget(MRI_label_venous_max_cerebral);
    MRI_vbox_venous_label_cerebral->addWidget(MRI_label_venous_mean_cerebral);
    MRI_vbox_venous_label_cerebral->addWidget(MRI_label_venous_grad_cerebral);
    MRI_vbox_venous_label_cerebral->addWidget(MRI_label_venous_stroke_cerebral);

    MRI_vbox_venous_corr_label_cerebral->addWidget(MRI_label_venous_corr_min_cerebral);
    MRI_vbox_venous_corr_label_cerebral->addWidget(MRI_label_venous_corr_max_cerebral);
    MRI_vbox_venous_corr_label_cerebral->addWidget(MRI_label_venous_corr_mean_cerebral);
    MRI_vbox_venous_corr_label_cerebral->addWidget(MRI_label_venous_corr_grad_cerebral);
    MRI_vbox_venous_corr_label_cerebral->addWidget(MRI_label_venous_corr_stroke_cerebral);

    MRI_vbox_csf_move_cerebral->addWidget(MRI_button_csf_move_right_cerebral);
    MRI_vbox_csf_move_cerebral->addWidget(MRI_box_csf_move_cerebral);
    MRI_vbox_csf_move_cerebral->addWidget(MRI_button_csf_move_left_cerebral);

    MRI_vbox_csf_button_cerebral->addWidget(MRI_button_csf_restore_cerebral);
    MRI_vbox_csf_button_cerebral->addWidget(MRI_button_csf_smooth_cerebral);
    MRI_vbox_csf_button_cerebral->addWidget(MRI_button_csf_save_cerebral);
    MRI_vbox_csf_button_cerebral->addWidget(MRI_button_csf_corr_save_cerebral);

    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_heart_rate_cerebral);
    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_min_cerebral);
    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_max_cerebral);
    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_mean_cerebral);
    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_grad_cerebral);
    MRI_vbox_csf_label_cerebral->addWidget(MRI_label_csf_stroke_cerebral);

    MRI_vbox_csf_corr_label_cerebral->addWidget(MRI_label_csf_corr_min_cerebral);
    MRI_vbox_csf_corr_label_cerebral->addWidget(MRI_label_csf_corr_max_cerebral);
    MRI_vbox_csf_corr_label_cerebral->addWidget(MRI_label_csf_corr_mean_cerebral);
    MRI_vbox_csf_corr_label_cerebral->addWidget(MRI_label_csf_corr_grad_cerebral);
    MRI_vbox_csf_corr_label_cerebral->addWidget(MRI_label_csf_corr_stroke_cerebral);

    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_flow_min_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_flow_max_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_flow_mean_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_flow_grad_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_flow_stroke_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_volume_min_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_volume_max_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_volume_mean_cerebral);
    MRI_vbox_AV_label_cerebral->addWidget(MRI_label_AV_volume_grad_cerebral);

    MRI_hbox_AV_cerebral->addWidget(MRI_check_AV_csf_cerebral);
    MRI_hbox_AV_cerebral->addWidget(MRI_button_AV_adjust_cerebral);
    MRI_hbox_AV_cerebral->addWidget(MRI_box_AV_adjust_cerebral);
    MRI_hbox_AV_cerebral->addWidget(MRI_button_AV_normalize_cerebral);
    MRI_hbox_AV_cerebral->addWidget(MRI_button_AV_smooth_cerebral);
    MRI_hbox_AV_cerebral->addWidget(MRI_button_AV_save_cerebral);

    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_flow_min_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_flow_max_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_flow_mean_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_flow_grad_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_flow_stroke_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_volume_min_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_volume_max_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_volume_mean_cerebral);
    MRI_vbox_ICVC_label_cerebral->addWidget(MRI_label_ICVC_volume_grad_cerebral);

    MRI_hbox_ICVC_cerebral->addWidget(MRI_button_ICVC_adjust_cerebral);
    MRI_hbox_ICVC_cerebral->addWidget(MRI_box_ICVC_adjust_cerebral);
    MRI_hbox_ICVC_cerebral->addWidget(MRI_button_ICVC_normalize_cerebral);
    MRI_hbox_ICVC_cerebral->addWidget(MRI_button_ICVC_smooth_cerebral);
    MRI_hbox_ICVC_cerebral->addWidget(MRI_button_ICVC_save_cerebral);

    //

    MRI_vbox_arterial_move_others->addWidget(MRI_button_arterial_move_right_others);
    MRI_vbox_arterial_move_others->addWidget(MRI_button_arterial_move_left_others);
    MRI_vbox_arterial_move_others->addWidget(MRI_check_move_others);

    MRI_vbox_arterial_button_others->addWidget(MRI_button_arterial_restore_others);
    MRI_vbox_arterial_button_others->addWidget(MRI_button_arterial_smooth_others);
    MRI_vbox_arterial_button_others->addWidget(MRI_button_arterial_save_others);
    MRI_vbox_arterial_button_others->addWidget(MRI_button_legend_others);

    MRI_vbox_arterial_label_others->addWidget(MRI_label_heart_rate_others);
    MRI_vbox_arterial_label_others->addWidget(MRI_label_arterial_min_others);
    MRI_vbox_arterial_label_others->addWidget(MRI_label_arterial_max_others);
    MRI_vbox_arterial_label_others->addWidget(MRI_label_arterial_mean_others);
    MRI_vbox_arterial_label_others->addWidget(MRI_label_arterial_grad_others);
    MRI_vbox_arterial_label_others->addWidget(MRI_label_arterial_stroke_others);

    MRI_vbox_venous_move_others->addWidget(MRI_button_venous_move_right_others);
    MRI_vbox_venous_move_others->addWidget(MRI_button_venous_move_left_others);

    MRI_vbox_venous_button_others->addWidget(MRI_button_venous_restore_others);
    MRI_vbox_venous_button_others->addWidget(MRI_button_venous_smooth_others);
    MRI_vbox_venous_button_others->addWidget(MRI_button_venous_save_others);

    MRI_vbox_venous_label_others->addWidget(MRI_label_venous_min_others);
    MRI_vbox_venous_label_others->addWidget(MRI_label_venous_max_others);
    MRI_vbox_venous_label_others->addWidget(MRI_label_venous_mean_others);
    MRI_vbox_venous_label_others->addWidget(MRI_label_venous_grad_others);
    MRI_vbox_venous_label_others->addWidget(MRI_label_venous_stroke_others);

    MRI_vbox_csf_move_others->addWidget(MRI_button_csf_move_right_others);
    MRI_vbox_csf_move_others->addWidget(MRI_button_csf_move_left_others);

    MRI_vbox_csf_button_others->addWidget(MRI_button_csf_restore_others);
    MRI_vbox_csf_button_others->addWidget(MRI_button_csf_smooth_others);
    MRI_vbox_csf_button_others->addWidget(MRI_button_csf_save_others);

    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_heart_rate_others);
    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_min_others);
    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_max_others);
    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_mean_others);
    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_grad_others);
    MRI_vbox_csf_label_others->addWidget(MRI_label_csf_stroke_others);

    //HBox
    MRI_hbox_arterial_cervical->addWidget(MRI_button_detect_systole_cervical, Qt::AlignLeft);
    MRI_hbox_arterial_cervical->addWidget(MRI_box_systole_threshold_cervical, Qt::AlignLeft);
    MRI_hbox_arterial_cervical->addWidget(MRI_box_systole_delay_cervical, Qt::AlignLeft);
    MRI_hbox_arterial_cervical->addWidget(MRI_button_adjust_systole_cervical, Qt::AlignLeft);
    MRI_hbox_arterial_cervical->addWidget(MRI_button_show_systole_cervical, Qt::AlignLeft);
    MRI_hbox_arterial_cervical->addWidget(MRI_button_plot_00_cervical, Qt::AlignRight);
    MRI_hbox_arterial_cervical->addWidget(MRI_button_choice_ncycles_cervical, Qt::AlignRight);
    MRI_hbox_arterial_cervical->addWidget(MRI_button_quality_cervical, Qt::AlignRight);

    MRI_hbox_venous_cervical->addWidget(MRI_button_venous_corr_cervical, Qt::AlignLeft);
    MRI_hbox_venous_cervical->addWidget(MRI_label_venous_corr_cervical, Qt::AlignRight);

    MRI_hbox_csf_cervical->addWidget(MRI_button_csf_corr_cervical, Qt::AlignLeft);
    MRI_hbox_csf_cervical->addWidget(MRI_label_csf_corr_cervical, Qt::AlignRight);

    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_box_AV_flow_volume_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_button_AV_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_button_AV_auto_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_label_AV_ICVC_ratio_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_box_ICVC_flow_volume_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_button_ICVC_cervical);
    MRI_hbox_AV_ICVC_cervical->addWidget(MRI_button_ICVC_auto_cervical);

    //

    MRI_hbox_arterial_cerebral->addWidget(MRI_button_detect_systole_cerebral, Qt::AlignLeft);
    MRI_hbox_arterial_cerebral->addWidget(MRI_box_systole_threshold_cerebral, Qt::AlignLeft);
    MRI_hbox_arterial_cerebral->addWidget(MRI_box_systole_delay_cerebral, Qt::AlignLeft);
    MRI_hbox_arterial_cerebral->addWidget(MRI_button_adjust_systole_cerebral, Qt::AlignLeft);
    MRI_hbox_arterial_cerebral->addWidget(MRI_button_show_systole_cerebral, Qt::AlignLeft);
    MRI_hbox_arterial_cerebral->addWidget(MRI_button_plot_00_cerebral, Qt::AlignRight);
    MRI_hbox_arterial_cerebral->addWidget(MRI_button_choice_ncycles_cerebral, Qt::AlignRight);
    MRI_hbox_arterial_cerebral->addWidget(MRI_button_quality_cerebral, Qt::AlignRight);

    MRI_hbox_venous_cerebral->addWidget(MRI_button_venous_corr_cerebral, Qt::AlignLeft);
    MRI_hbox_venous_cerebral->addWidget(MRI_label_venous_corr_cerebral, Qt::AlignRight);

    MRI_hbox_csf_cerebral->addWidget(MRI_button_csf_corr_cerebral, Qt::AlignLeft);
    MRI_hbox_csf_cerebral->addWidget(MRI_label_csf_corr_cerebral, Qt::AlignRight);

    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_box_AV_flow_volume_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_button_AV_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_button_AV_auto_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_label_AV_ICVC_ratio_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_box_ICVC_flow_volume_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_button_ICVC_cerebral);
    MRI_hbox_AV_ICVC_cerebral->addWidget(MRI_button_ICVC_auto_cerebral);

    //

    MRI_hbox_arterial_others->addWidget(MRI_button_arterial_choice);
    MRI_hbox_arterial_others->addWidget(MRI_button_quality_others, Qt::AlignRight);

    MRI_hbox_venous_others->addWidget(MRI_button_venous_choice);

    MRI_hbox_csf_others->addWidget(MRI_button_csf_choice);


    //Grid
    MRI_grid_cervical->addLayout(MRI_hbox_arterial_cervical, 0, 0, 1, 100);
    MRI_grid_cervical->addWidget(MRI_plot_arterial_cervical, 1, 0, 10, 70);
    MRI_grid_cervical->addLayout(MRI_vbox_arterial_move_cervical, 1, 70, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_arterial_button_cervical, 1, 75, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_arterial_label_cervical, 1, 80, 10, 20);
    MRI_grid_cervical->addLayout(MRI_hbox_venous_cervical, 11, 0, 1, 100);
    MRI_grid_cervical->addWidget(MRI_plot_venous_cervical, 12, 0, 10, 70);
    MRI_grid_cervical->addLayout(MRI_vbox_venous_move_cervical, 12, 70, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_venous_button_cervical, 12, 75, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_venous_label_cervical, 12, 80, 10, 15);
    MRI_grid_cervical->addLayout(MRI_vbox_venous_corr_label_cervical, 12, 95, 10, 5);
    MRI_grid_cervical->addLayout(MRI_hbox_csf_cervical, 22, 0, 1, 100);
    MRI_grid_cervical->addWidget(MRI_plot_csf_cervical, 23, 0, 10, 70);
    MRI_grid_cervical->addLayout(MRI_vbox_csf_move_cervical, 23, 70, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_csf_button_cervical, 23, 75, 10, 5);
    MRI_grid_cervical->addLayout(MRI_vbox_csf_label_cervical, 23, 80, 10, 15);
    MRI_grid_cervical->addLayout(MRI_vbox_csf_corr_label_cervical, 23, 95, 10, 5);
    MRI_grid_cervical->addLayout(MRI_hbox_AV_ICVC_cervical, 33, 0, 1, 100);
    MRI_grid_cervical->addWidget(MRI_plot_AV_cervical, 34, 0, 10, 35);
    MRI_grid_cervical->addLayout(MRI_vbox_AV_label_cervical, 34, 35, 10, 15);
    MRI_grid_cervical->addWidget(MRI_plot_ICVC_cervical, 34, 50, 10, 35);
    MRI_grid_cervical->addLayout(MRI_vbox_ICVC_label_cervical, 34, 85, 10, 15);
    MRI_grid_cervical->addLayout(MRI_hbox_AV_cervical, 44, 0, 1, 50);
    MRI_grid_cervical->addLayout(MRI_hbox_ICVC_cervical, 44, 50, 1, 50);
    //
    MRI_grid_cerebral->addLayout(MRI_hbox_arterial_cerebral, 0, 0, 1, 100);
    MRI_grid_cerebral->addWidget(MRI_plot_arterial_cerebral, 1, 0, 10, 70);
    MRI_grid_cerebral->addLayout(MRI_vbox_arterial_move_cerebral, 1, 70, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_arterial_button_cerebral, 1, 75, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_arterial_label_cerebral, 1, 80, 10, 20);
    MRI_grid_cerebral->addLayout(MRI_hbox_venous_cerebral, 11, 0, 1, 100);
    MRI_grid_cerebral->addWidget(MRI_plot_venous_cerebral, 12, 0, 10, 70);
    MRI_grid_cerebral->addLayout(MRI_vbox_venous_move_cerebral, 12, 70, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_venous_button_cerebral, 12, 75, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_venous_label_cerebral, 12, 80, 10, 15);
    MRI_grid_cerebral->addLayout(MRI_vbox_venous_corr_label_cerebral, 12, 95, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_hbox_csf_cerebral, 22, 0, 1, 100);
    MRI_grid_cerebral->addWidget(MRI_plot_csf_cerebral, 23, 0, 10, 70);
    MRI_grid_cerebral->addLayout(MRI_vbox_csf_move_cerebral, 23, 70, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_csf_button_cerebral, 23, 75, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_vbox_csf_label_cerebral, 23, 80, 10, 15);
    MRI_grid_cerebral->addLayout(MRI_vbox_csf_corr_label_cerebral, 23, 95, 10, 5);
    MRI_grid_cerebral->addLayout(MRI_hbox_AV_ICVC_cerebral, 33, 0, 1, 100);
    MRI_grid_cerebral->addWidget(MRI_plot_AV_cerebral, 34, 0, 10, 35);
    MRI_grid_cerebral->addLayout(MRI_vbox_AV_label_cerebral, 34, 35, 10, 15);
    MRI_grid_cerebral->addWidget(MRI_plot_ICVC_cerebral, 34, 50, 10, 35);
    MRI_grid_cerebral->addLayout(MRI_vbox_ICVC_label_cerebral, 34, 85, 10, 15);
    MRI_grid_cerebral->addLayout(MRI_hbox_AV_cerebral, 44, 0, 1, 50);
    MRI_grid_cerebral->addLayout(MRI_hbox_ICVC_cerebral, 44, 50, 1, 50);
    //
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_arterial_cervical_cerebral, 0, 0, 10, 90);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_arterial_dphi, 1, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_button_legend_cervical_cerebral, 2, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_venous_cervical_cerebral, 10, 0, 10, 90);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_venous_dphi, 10, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_check_venous_cervical_cerebral, 11, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_csf_cervical_cerebral, 20, 0, 10, 90);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_csf_dphi, 20, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_check_csf_cervical_cerebral, 21, 90, 1, 10);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_AV_flow_cervical_cerebral, 30, 0, 10, 45);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_ICVC_flow_cervical_cerebral, 30, 50, 10, 45);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_AV_flow_dphi, 30, 45, 1, 5);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_ICVC_flow_dphi, 31, 95, 1, 5);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_AV_volume_cervical_cerebral, 40, 0, 10, 45);
    MRI_grid_cervical_cerebral->addWidget(MRI_plot_ICVC_volume_cervical_cerebral, 40, 50, 10, 45);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_AV_volume_dphi, 40, 45, 1, 5);
    MRI_grid_cervical_cerebral->addWidget(MRI_label_ICVC_volume_dphi, 40, 95, 1, 5);
    //
    MRI_grid_spectrum->addWidget(MRI_plot_arterial_spectrum, 0, 0, 10, 100);
    MRI_grid_spectrum->addWidget(MRI_plot_venous_spectrum, 10, 0, 10, 100);
    MRI_grid_spectrum->addWidget(MRI_plot_csf_spectrum, 20, 0, 10, 100);
    MRI_grid_spectrum->addWidget(MRI_plot_AV_flow_spectrum, 30, 0, 10, 50);
    MRI_grid_spectrum->addWidget(MRI_plot_ICVC_flow_spectrum, 30, 50, 10, 50);
    MRI_grid_spectrum->addWidget(MRI_plot_AV_volume_spectrum, 40, 0, 10, 50);
    MRI_grid_spectrum->addWidget(MRI_plot_ICVC_volume_spectrum, 40, 50, 10, 50);
    //
    MRI_grid_others->addLayout(MRI_hbox_arterial_others, 0, 0, 1, 100);
    MRI_grid_others->addWidget(MRI_plot_arterial_others, 1, 0, 10, 70);
    MRI_grid_others->addLayout(MRI_vbox_arterial_move_others, 1, 70, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_arterial_button_others, 1, 75, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_arterial_label_others, 1, 80, 10, 20);
    MRI_grid_others->addLayout(MRI_hbox_venous_others, 11, 0, 1, 100);
    MRI_grid_others->addWidget(MRI_plot_venous_others, 12, 0, 10, 70);
    MRI_grid_others->addLayout(MRI_vbox_venous_move_others, 12, 70, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_venous_button_others, 12, 75, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_venous_label_others, 12, 80, 10, 15);
    MRI_grid_others->addLayout(MRI_hbox_csf_others, 22, 0, 1, 100);
    MRI_grid_others->addWidget(MRI_plot_csf_others, 23, 0, 10, 70);
    MRI_grid_others->addLayout(MRI_vbox_csf_move_others, 23, 70, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_csf_button_others, 23, 75, 10, 5);
    MRI_grid_others->addLayout(MRI_vbox_csf_label_others, 23, 80, 10, 15);


    //Widget
    MRI_tab_cervical->setLayout(MRI_grid_cervical);
    //
    MRI_tab_cerebral->setLayout(MRI_grid_cerebral);
    //
    MRI_tab_cervical_cerebral->setLayout(MRI_grid_cervical_cerebral);
    //
    MRI_tab_spectrum->setLayout(MRI_grid_spectrum);
    //
    MRI_tab_others->setLayout(MRI_grid_others);

    //Tab
    MRI_tab->addTab(MRI_tab_cervical, MAINWINDOW_MRI_CERVICAL);
    //
    MRI_tab->addTab(MRI_tab_cerebral, MAINWINDOW_MRI_CEREBRAL);
    //
    MRI_tab->addTab(MRI_tab_cervical_cerebral, MAINWINDOW_MRI_CERV_CERE);
    //
    MRI_tab->addTab(MRI_tab_spectrum, "Spectrum");
    //
    MRI_tab->addTab(MRI_tab_others, MAINWINDOW_MRI_OTHERS);
}

/*!
 * \brief MainWindow::init_MRI_sig
 */
void MainWindow::init_MRI_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(MRI_button_quality_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_quality_cervical()));

    connect(MRI_button_plot_00_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_plot_00_cervical()));
    connect(MRI_menu_ncycles_cervical->actions().at(0), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cervical_1()));
    connect(MRI_menu_ncycles_cervical->actions().at(1), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cervical_2()));
    connect(MRI_menu_ncycles_cervical->actions().at(2), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cervical_3()));

    connect(MRI_button_detect_systole_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_systole_detect_cervical()));
    connect(MRI_button_adjust_systole_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_systole_adjust_cervical()));
    connect(MRI_button_show_systole_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_systole_show_cervical()));

    connect(MRI_button_arterial_move_right_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_right_cervical()));
    connect(MRI_button_arterial_move_left_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_left_cervical()));
    connect(MRI_button_venous_move_right_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_right_cervical()));
    connect(MRI_button_venous_move_left_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_left_cervical()));
    connect(MRI_button_csf_move_right_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_right_cervical()));
    connect(MRI_button_csf_move_left_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_left_cervical()));

    connect(MRI_check_venous_cervical, SIGNAL(clicked()), this, SLOT(plot_MRI_venous_cervical()));
    connect(MRI_check_venous_cervical, SIGNAL(clicked()), this, SLOT(plot_MRI_venous_corr_cervical()));

    connect(MRI_button_arterial_restore_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_restore_cervical()));
    connect(MRI_button_arterial_smooth_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_smooth_cervical()));
    connect(MRI_button_arterial_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_save_cervical()));
    connect(MRI_button_legend_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_legend_cervical()));

    connect(MRI_button_venous_restore_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_venous_restore_cervical()));
    connect(MRI_button_venous_smooth_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_venous_smooth_cervical()));
    connect(MRI_button_venous_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_venous_save_cervical()));
    connect(MRI_button_venous_corr_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_venous_corr_save_cervical()));

    connect(MRI_button_csf_restore_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_csf_restore_cervical()));
    connect(MRI_button_csf_smooth_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_csf_smooth_cervical()));
    connect(MRI_button_csf_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_csf_save_cervical()));
    connect(MRI_button_csf_corr_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_csf_corr_save_cervical()));

    connect(MRI_button_venous_corr_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_venous_corr_cervical()));
    connect(MRI_button_csf_corr_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_csf_corr_cervical()));

    connect(MRI_box_AV_flow_volume_cervical, SIGNAL(currentIndexChanged(int)), this, SLOT(do_MRI_AV_flow_volume_cervical(int)));

    connect(MRI_check_AV_csf_cervical, SIGNAL(clicked()), this, SLOT(plot_MRI_AV_cervical()));

    connect(MRI_button_AV_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_cervical()));
    connect(MRI_button_AV_auto_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_auto_cervical()));
    connect(MRI_button_AV_adjust_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_adjust_cervical()));
    connect(MRI_button_AV_normalize_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_normalize_cervical()));
    connect(MRI_button_AV_smooth_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_smooth_cervical()));
    connect(MRI_button_AV_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_AV_save_cervical()));

    connect(MRI_box_ICVC_flow_volume_cervical, SIGNAL(currentIndexChanged(int)), this, SLOT(do_MRI_ICVC_flow_volume_cervical(int)));

    connect(MRI_button_ICVC_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_cervical()));
    connect(MRI_button_ICVC_auto_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_auto_cervical()));
    connect(MRI_button_ICVC_adjust_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_adjust_cervical()));
    connect(MRI_button_ICVC_normalize_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_normalize_cervical()));
    connect(MRI_button_ICVC_smooth_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_smooth_cervical()));
    connect(MRI_button_ICVC_save_cervical, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_save_cervical()));

    //

    connect(MRI_button_quality_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_quality_cerebral()));

    connect(MRI_button_plot_00_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_plot_00_cerebral()));
    connect(MRI_menu_ncycles_cerebral->actions().at(0), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cerebral_1()));
    connect(MRI_menu_ncycles_cerebral->actions().at(1), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cerebral_2()));
    connect(MRI_menu_ncycles_cerebral->actions().at(2), SIGNAL(triggered()), this, SLOT(do_MRI_choice_ncycles_cerebral_3()));

    connect(MRI_button_detect_systole_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_systole_detect_cerebral()));
    connect(MRI_button_adjust_systole_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_systole_adjust_cerebral()));
    connect(MRI_button_show_systole_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_systole_show_cerebral()));

    connect(MRI_button_arterial_move_right_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_right_cerebral()));
    connect(MRI_button_arterial_move_left_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_left_cerebral()));
    connect(MRI_button_venous_move_right_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_right_cerebral()));
    connect(MRI_button_venous_move_left_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_left_cerebral()));
    connect(MRI_button_csf_move_right_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_right_cerebral()));
    connect(MRI_button_csf_move_left_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_left_cerebral()));

    connect(MRI_check_venous_cerebral, SIGNAL(clicked()), this, SLOT(plot_MRI_venous_cerebral()));
    connect(MRI_check_venous_cerebral, SIGNAL(clicked()), this, SLOT(plot_MRI_venous_corr_cerebral()));

    connect(MRI_button_arterial_restore_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_restore_cerebral()));
    connect(MRI_button_arterial_smooth_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_smooth_cerebral()));
    connect(MRI_button_arterial_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_save_cerebral()));
    connect(MRI_button_legend_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_legend_cerebral()));

    connect(MRI_button_venous_restore_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_venous_restore_cerebral()));
    connect(MRI_button_venous_smooth_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_venous_smooth_cerebral()));
    connect(MRI_button_venous_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_venous_save_cerebral()));
    connect(MRI_button_venous_corr_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_venous_corr_save_cerebral()));

    connect(MRI_button_csf_restore_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_csf_restore_cerebral()));
    connect(MRI_button_csf_smooth_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_csf_smooth_cerebral()));
    connect(MRI_button_csf_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_csf_save_cerebral()));
    connect(MRI_button_csf_corr_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_csf_corr_save_cerebral()));

    connect(MRI_button_venous_corr_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_venous_corr_cerebral()));
    connect(MRI_button_csf_corr_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_csf_corr_cerebral()));

    connect(MRI_box_AV_flow_volume_cerebral, SIGNAL(currentIndexChanged(int)), this, SLOT(do_MRI_AV_flow_volume_cerebral(int)));

    connect(MRI_check_AV_csf_cerebral, SIGNAL(clicked()), this, SLOT(plot_MRI_AV_cerebral()));

    connect(MRI_button_AV_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_cerebral()));
    connect(MRI_button_AV_auto_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_auto_cerebral()));
    connect(MRI_button_AV_adjust_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_adjust_cerebral()));
    connect(MRI_button_AV_normalize_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_normalize_cerebral()));
    connect(MRI_button_AV_smooth_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_smooth_cerebral()));
    connect(MRI_button_AV_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_AV_save_cerebral()));

    connect(MRI_box_ICVC_flow_volume_cerebral, SIGNAL(currentIndexChanged(int)), this, SLOT(do_MRI_ICVC_flow_volume_cerebral(int)));

    connect(MRI_button_ICVC_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_cerebral()));
    connect(MRI_button_ICVC_auto_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_auto_cerebral()));
    connect(MRI_button_ICVC_adjust_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_adjust_cerebral()));
    connect(MRI_button_ICVC_normalize_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_normalize_cerebral()));
    connect(MRI_button_ICVC_smooth_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_smooth_cerebral()));
    connect(MRI_button_ICVC_save_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_ICVC_save_cerebral()));

    //

    connect(MRI_button_legend_cervical_cerebral, SIGNAL(clicked()), this, SLOT(do_MRI_legend_cervical_cerebral()));
    connect(MRI_check_venous_cervical_cerebral, SIGNAL(clicked()), this, SLOT(plot_MRI_venous_cervical_cerebral()));
    connect(MRI_check_csf_cervical_cerebral, SIGNAL(clicked()), this, SLOT(plot_MRI_csf_cervical_cerebral()));

    //

    connect(MRI_button_quality_others, SIGNAL(clicked()), this, SLOT(do_MRI_quality_others()));

    connect(MRI_button_arterial_move_right_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_right_others()));
    connect(MRI_button_arterial_move_left_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_arterial_left_others()));
    connect(MRI_button_venous_move_right_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_right_others()));
    connect(MRI_button_venous_move_left_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_venous_left_others()));
    connect(MRI_button_csf_move_right_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_right_others()));
    connect(MRI_button_csf_move_left_others, SIGNAL(clicked()), this, SLOT(do_MRI_move_csf_left_others()));

    connect(MRI_button_arterial_restore_others, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_restore_others()));
    connect(MRI_button_arterial_smooth_others, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_smooth_others()));
    connect(MRI_button_arterial_save_others, SIGNAL(clicked()), this, SLOT(do_MRI_arterial_save_others()));
    connect(MRI_button_legend_others, SIGNAL(clicked()), this, SLOT(do_MRI_legend_others()));

    connect(MRI_button_venous_restore_others, SIGNAL(clicked()), this, SLOT(do_MRI_venous_restore_others()));
    connect(MRI_button_venous_smooth_others, SIGNAL(clicked()), this, SLOT(do_MRI_venous_smooth_others()));
    connect(MRI_button_venous_save_others, SIGNAL(clicked()), this, SLOT(do_MRI_venous_save_others()));

    connect(MRI_button_csf_restore_others, SIGNAL(clicked()), this, SLOT(do_MRI_csf_restore_others()));
    connect(MRI_button_csf_smooth_others, SIGNAL(clicked()), this, SLOT(do_MRI_csf_smooth_others()));
    connect(MRI_button_csf_save_others, SIGNAL(clicked()), this, SLOT(do_MRI_csf_save_others()));
}

/*!
 * \brief MainWindow::init_MRI_css
 */
void MainWindow::init_MRI_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    MRI_tab->setStyleSheet(CSS_TAB);
#ifdef QT5
    MRI_tab->tabBar()->setStyleSheet(CSS_TABBAR);
    MRI_tab->tabBar()->setFocusPolicy(Qt::NoFocus);
#endif

    //Widget
    MRI_tab_cervical->setStyleSheet(CSS_WIDGET);
    MRI_tab_cerebral->setStyleSheet(CSS_WIDGET);
    MRI_tab_cervical_cerebral->setStyleSheet(CSS_WIDGET);
    MRI_tab_spectrum->setStyleSheet(CSS_WIDGET);
    MRI_tab_others->setStyleSheet(CSS_WIDGET);

    //Plot
    QPen bluedotpen;
    bluedotpen.setColor(Qt::blue);
    bluedotpen.setStyle(Qt::DashLine);
    QPen greendotpen;
    greendotpen.setColor(QColor(0, 128, 0));
    greendotpen.setStyle(Qt::DashLine);
    QPen systolepen;
    systolepen.setColor(QColor(200, 0, 0));
    systolepen.setWidth(2);

    MRI_plot_arterial_cervical->graph(0)->setPen(QPen(Qt::red));
    MRI_plot_arterial_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_ART0);
    MRI_plot_arterial_cervical->graph(1)->setPen(systolepen);
    MRI_plot_arterial_cervical->graph(1)->setLineStyle(QCPGraph::lsNone);
    MRI_plot_arterial_cervical->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    MRI_plot_arterial_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_ART1);
    MRI_plot_arterial_cervical->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_arterial_cervical->legend->setVisible(true);
    MRI_plot_arterial_cervical->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_venous_cervical->graph(0)->setPen(QPen(Qt::blue));
    MRI_plot_venous_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_VEN0);
    MRI_plot_venous_cervical->graph(1)->setPen(bluedotpen);
    MRI_plot_venous_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_VEN1);
    MRI_plot_venous_cervical->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_venous_cervical->legend->setVisible(true);
    MRI_plot_venous_cervical->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_csf_cervical->graph(0)->setPen(QPen(QColor(0, 128, 0)));
    MRI_plot_csf_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_CSF0);
    MRI_plot_csf_cervical->graph(1)->setPen(greendotpen);
    MRI_plot_csf_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_CSF1);
    MRI_plot_csf_cervical->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_csf_cervical->legend->setVisible(true);
    MRI_plot_csf_cervical->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_AV_cervical->graph(1)->setPen(QPen(QColor(0, 128, 0)));

    //

    MRI_plot_arterial_cerebral->graph(0)->setPen(QPen(Qt::red));
    MRI_plot_arterial_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_ART0);
    MRI_plot_arterial_cerebral->graph(1)->setPen(systolepen);
    MRI_plot_arterial_cerebral->graph(1)->setLineStyle(QCPGraph::lsNone);
    MRI_plot_arterial_cerebral->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    MRI_plot_arterial_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_ART1);
    MRI_plot_arterial_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_arterial_cerebral->legend->setVisible(true);
    MRI_plot_arterial_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_venous_cerebral->graph(0)->setPen(QPen(Qt::blue));
    MRI_plot_venous_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_VEN0);
    MRI_plot_venous_cerebral->graph(1)->setPen(bluedotpen);
    MRI_plot_venous_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_VEN1);
    MRI_plot_venous_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_venous_cerebral->legend->setVisible(true);
    MRI_plot_venous_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_csf_cerebral->graph(0)->setPen(QPen(QColor(0, 128, 0)));
    MRI_plot_csf_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_CSF0);
    MRI_plot_csf_cerebral->graph(1)->setPen(greendotpen);
    MRI_plot_csf_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_CSF1);
    MRI_plot_csf_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_csf_cerebral->legend->setVisible(true);
    MRI_plot_csf_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_AV_cerebral->graph(1)->setPen(QPen(QColor(0, 128, 0)));

    //

    QPen redpen1;
    redpen1.setColor(QColor(255, 0, 0));
    QPen redpen2;
    redpen2.setColor(QColor(255, 0, 0));
    redpen2.setWidth(2);
    QPen reddashpen1;
    reddashpen1.setColor(QColor(255, 0, 0));
    reddashpen1.setStyle(Qt::DashDotDotLine);
    QPen reddashpen2;
    reddashpen2.setColor(QColor(255, 0, 0));
    reddashpen2.setStyle(Qt::DashDotDotLine);
    reddashpen2.setWidth(2);
    QPen bluepen1;
    bluepen1.setColor(QColor(0, 0, 255));
    QPen bluepen2;
    bluepen2.setColor(QColor(0, 0, 255));
    bluepen2.setWidth(2);
    QPen bluedotpen1;
    bluedotpen1.setColor(QColor(0, 0, 255));
    bluedotpen1.setStyle(Qt::DashLine);
    QPen bluedotpen2;
    bluedotpen2.setColor(QColor(0, 0, 255));
    bluedotpen2.setWidth(2);
    bluedotpen2.setStyle(Qt::DashLine);
    QPen bluedashpen1;
    bluedashpen1.setColor(QColor(0, 0, 255));
    bluedashpen1.setStyle(Qt::DashDotDotLine);
    QPen bluedashpen2;
    bluedashpen2.setColor(QColor(0, 0, 255));
    bluedashpen2.setWidth(2);
    bluedashpen2.setStyle(Qt::DashDotDotLine);
    QPen greenpen1;
    greenpen1.setColor(QColor(0, 128, 0));
    QPen greenpen2;
    greenpen2.setColor(QColor(0, 128, 0));
    greenpen2.setWidth(2);
    QPen greendotpen1;
    greendotpen1.setColor(QColor(0, 128, 0));
    greendotpen1.setStyle(Qt::DashLine);
    QPen greendotpen2;
    greendotpen2.setColor(QColor(0, 128, 0));
    greendotpen2.setWidth(2);
    greendotpen2.setStyle(Qt::DashLine);
    QPen greendashpen1;
    greendashpen1.setColor(QColor(0, 128, 0));
    greendashpen1.setStyle(Qt::DashDotDotLine);
    QPen greendashpen2;
    greendashpen2.setColor(QColor(0, 128, 0));
    greendashpen2.setWidth(2);
    greendashpen2.setStyle(Qt::DashDotDotLine);
    QPen purplepen1;
    purplepen1.setColor(QColor(128, 0, 128));
    QPen purplepen2;
    purplepen2.setColor(QColor(128, 0, 128));
    purplepen2.setWidth(2);
    QPen purpledashpen1;
    purpledashpen1.setColor(QColor(128, 0, 128));
    purpledashpen1.setStyle(Qt::DashDotDotLine);
    QPen purpledashpen2;
    purpledashpen2.setColor(QColor(128, 0, 128));
    purpledashpen2.setWidth(2);
    purpledashpen2.setStyle(Qt::DashDotDotLine);
    QPen orangepen1;
    orangepen1.setColor(QColor(255, 165, 0));
    QPen orangepen2;
    orangepen2.setColor(QColor(255, 165, 0));
    orangepen2.setWidth(2);
    QPen orangedashpen1;
    orangedashpen1.setColor(QColor(255, 165, 0));
    orangedashpen1.setStyle(Qt::DashDotDotLine);
    QPen orangedashpen2;
    orangedashpen2.setColor(QColor(255, 165, 0));
    orangedashpen2.setWidth(2);
    orangedashpen2.setStyle(Qt::DashDotDotLine);

    MRI_plot_arterial_cervical_cerebral->graph(0)->setPen(redpen1);
    MRI_plot_arterial_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_arterial_cervical_cerebral->graph(1)->setPen(redpen2);
    MRI_plot_arterial_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_arterial_cervical_cerebral->graph(2)->setPen(reddashpen1);
    MRI_plot_arterial_cervical_cerebral->graph(2)->setName("Max cervical");
    MRI_plot_arterial_cervical_cerebral->graph(3)->setPen(reddashpen2);
    MRI_plot_arterial_cervical_cerebral->graph(3)->setName("Max cerebral");
    MRI_plot_arterial_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_arterial_cervical_cerebral->legend->setVisible(true);
    MRI_plot_arterial_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_arterial_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_arterial_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_arterial_cervical_cerebral, MAINWINDOW_MRI_GRAPH_ART0));

    MRI_plot_venous_cervical_cerebral->graph(0)->setPen(bluepen1);
    MRI_plot_venous_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_venous_cervical_cerebral->graph(1)->setPen(bluepen2);
    MRI_plot_venous_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_venous_cervical_cerebral->graph(2)->setPen(bluedotpen1);
    MRI_plot_venous_cervical_cerebral->graph(2)->setName(MAINWINDOW_MRI_CERVICAL_C);
    MRI_plot_venous_cervical_cerebral->graph(3)->setPen(bluedotpen2);
    MRI_plot_venous_cervical_cerebral->graph(3)->setName(MAINWINDOW_MRI_CERERBAL_C);
    MRI_plot_venous_cervical_cerebral->graph(4)->setPen(bluedashpen1);
    MRI_plot_venous_cervical_cerebral->graph(4)->setName("Min cervical");
    MRI_plot_venous_cervical_cerebral->graph(5)->setPen(bluedashpen2);
    MRI_plot_venous_cervical_cerebral->graph(5)->setName("Min cerebral");
    MRI_plot_venous_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_venous_cervical_cerebral->legend->setVisible(true);
    MRI_plot_venous_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_venous_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_venous_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_venous_cervical_cerebral, MAINWINDOW_MRI_GRAPH_VEN0));

    MRI_plot_csf_cervical_cerebral->graph(0)->setPen(greenpen1);
    MRI_plot_csf_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_csf_cervical_cerebral->graph(1)->setPen(greenpen2);
    MRI_plot_csf_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_csf_cervical_cerebral->graph(2)->setPen(greendotpen1);
    MRI_plot_csf_cervical_cerebral->graph(2)->setName(MAINWINDOW_MRI_CERVICAL_C);
    MRI_plot_csf_cervical_cerebral->graph(3)->setPen(greendotpen2);
    MRI_plot_csf_cervical_cerebral->graph(3)->setName(MAINWINDOW_MRI_CERERBAL_C);
    MRI_plot_csf_cervical_cerebral->graph(4)->setPen(greendashpen1);
    MRI_plot_csf_cervical_cerebral->graph(4)->setName("Min cervical");
    MRI_plot_csf_cervical_cerebral->graph(5)->setPen(greendashpen2);
    MRI_plot_csf_cervical_cerebral->graph(5)->setName("Min cerebral");
    MRI_plot_csf_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_csf_cervical_cerebral->legend->setVisible(true);
    MRI_plot_csf_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_csf_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_csf_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_csf_cervical_cerebral, MAINWINDOW_MRI_GRAPH_CSF0));

    MRI_plot_AV_flow_cervical_cerebral->graph(0)->setPen(purplepen1);
    MRI_plot_AV_flow_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_AV_flow_cervical_cerebral->graph(1)->setPen(purplepen2);
    MRI_plot_AV_flow_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_AV_flow_cervical_cerebral->graph(2)->setPen(purpledashpen1);
    MRI_plot_AV_flow_cervical_cerebral->graph(2)->setName("Max cervical");
    MRI_plot_AV_flow_cervical_cerebral->graph(3)->setPen(purpledashpen2);
    MRI_plot_AV_flow_cervical_cerebral->graph(3)->setName("Max cerebral");
    MRI_plot_AV_flow_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_AV_flow_cervical_cerebral->legend->setVisible(true);
    MRI_plot_AV_flow_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_AV_flow_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_AV_flow_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_AV_flow_cervical_cerebral, MAINWINDOW_MRI_GRAPH_AV_F));

    MRI_plot_AV_volume_cervical_cerebral->graph(0)->setPen(orangepen1);
    MRI_plot_AV_volume_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_AV_volume_cervical_cerebral->graph(1)->setPen(orangepen2);
    MRI_plot_AV_volume_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_AV_volume_cervical_cerebral->graph(2)->setPen(orangedashpen1);
    MRI_plot_AV_volume_cervical_cerebral->graph(2)->setName("Max cervical");
    MRI_plot_AV_volume_cervical_cerebral->graph(3)->setPen(orangedashpen2);
    MRI_plot_AV_volume_cervical_cerebral->graph(3)->setName("Max cerebral");
    MRI_plot_AV_volume_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_AV_volume_cervical_cerebral->legend->setVisible(true);
    MRI_plot_AV_volume_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_AV_volume_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_AV_volume_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_AV_volume_cervical_cerebral, MAINWINDOW_MRI_GRAPH_AV_V));

    MRI_plot_ICVC_flow_cervical_cerebral->graph(0)->setPen(purplepen1);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(1)->setPen(purplepen2);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(2)->setPen(purpledashpen1);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(2)->setName("Max cervical");
    MRI_plot_ICVC_flow_cervical_cerebral->graph(3)->setPen(purpledashpen2);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(3)->setName("Max cerebral");
    MRI_plot_ICVC_flow_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_ICVC_flow_cervical_cerebral->legend->setVisible(true);
    MRI_plot_ICVC_flow_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_ICVC_flow_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_ICVC_flow_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_ICVC_flow_cervical_cerebral, MAINWINDOW_MRI_GRAPH_ICVC_F));

    MRI_plot_ICVC_volume_cervical_cerebral->graph(0)->setPen(orangepen1);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(1)->setPen(orangepen2);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(2)->setPen(orangedashpen1);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(2)->setName("Max cervical");
    MRI_plot_ICVC_volume_cervical_cerebral->graph(3)->setPen(orangedashpen2);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(3)->setName("Max cerebral");
    MRI_plot_ICVC_volume_cervical_cerebral->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_ICVC_volume_cervical_cerebral->legend->setVisible(true);
    MRI_plot_ICVC_volume_cervical_cerebral->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    MRI_plot_ICVC_volume_cervical_cerebral->plotLayout()->insertRow(0);
    MRI_plot_ICVC_volume_cervical_cerebral->plotLayout()->addElement(0, 0, new QCPPlotTitle(MRI_plot_ICVC_volume_cervical_cerebral, MAINWINDOW_MRI_GRAPH_ICVC_V));

    //

    MRI_plot_arterial_spectrum->graph(0)->setPen(redpen1);
    MRI_plot_arterial_spectrum->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 100)));
    MRI_plot_arterial_spectrum->graph(1)->setPen(redpen2);
    MRI_plot_arterial_spectrum->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 100)));
    MRI_plot_venous_spectrum->graph(0)->setPen(bluepen1);
    MRI_plot_venous_spectrum->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 100)));
    MRI_plot_venous_spectrum->graph(1)->setPen(bluepen2);
    MRI_plot_venous_spectrum->graph(1)->setBrush(QBrush(QColor(0, 0, 255, 100)));
    MRI_plot_csf_spectrum->graph(0)->setPen(greenpen1);
    MRI_plot_csf_spectrum->graph(0)->setBrush(QBrush(QColor(0, 255, 0, 100)));
    MRI_plot_csf_spectrum->graph(1)->setPen(greenpen2);
    MRI_plot_csf_spectrum->graph(1)->setBrush(QBrush(QColor(0, 255, 0, 100)));
    MRI_plot_AV_flow_spectrum->graph(0)->setPen(purplepen1);
    MRI_plot_AV_flow_spectrum->graph(0)->setBrush(QBrush(QColor(128, 0, 128, 100)));
    MRI_plot_AV_flow_spectrum->graph(1)->setPen(purplepen2);
    MRI_plot_AV_flow_spectrum->graph(1)->setBrush(QBrush(QColor(128, 0, 128, 100)));
    MRI_plot_AV_volume_spectrum->graph(0)->setPen(orangepen1);
    MRI_plot_AV_volume_spectrum->graph(0)->setBrush(QBrush(QColor(255, 165, 0, 100)));
    MRI_plot_AV_volume_spectrum->graph(1)->setPen(orangepen2);
    MRI_plot_AV_volume_spectrum->graph(1)->setBrush(QBrush(QColor(255, 165, 0, 100)));
    MRI_plot_ICVC_flow_spectrum->graph(0)->setPen(purplepen1);
    MRI_plot_ICVC_flow_spectrum->graph(0)->setBrush(QBrush(QColor(128, 0, 128, 100)));
    MRI_plot_ICVC_flow_spectrum->graph(1)->setPen(purplepen2);
    MRI_plot_ICVC_flow_spectrum->graph(1)->setBrush(QBrush(QColor(128, 0, 128, 100)));
    MRI_plot_ICVC_volume_spectrum->graph(0)->setPen(orangepen1);
    MRI_plot_ICVC_volume_spectrum->graph(0)->setBrush(QBrush(QColor(255, 165, 0, 100)));
    MRI_plot_ICVC_volume_spectrum->graph(1)->setPen(orangepen2);
    MRI_plot_ICVC_volume_spectrum->graph(1)->setBrush(QBrush(QColor(255, 165, 0, 100)));

    //

    MRI_plot_arterial_others->graph(0)->setPen(QPen(Qt::red));
    MRI_plot_arterial_others->graph(0)->setName(MAINWINDOW_MRI_GRAPH_ART0);
    MRI_plot_arterial_others->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_arterial_others->legend->setVisible(true);
    MRI_plot_arterial_others->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_venous_others->graph(0)->setPen(QPen(Qt::blue));
    MRI_plot_venous_others->graph(0)->setName(MAINWINDOW_MRI_GRAPH_VEN0);
    MRI_plot_venous_others->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_venous_others->legend->setVisible(true);
    MRI_plot_venous_others->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);

    MRI_plot_csf_others->graph(0)->setPen(QPen(Qt::green));
    MRI_plot_csf_others->graph(0)->setName(MAINWINDOW_MRI_GRAPH_CSF0);
    MRI_plot_csf_others->legend->setBrush(QBrush(QColor(255, 255, 255, 200)));
    MRI_plot_csf_others->legend->setVisible(true);
    MRI_plot_csf_others->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);


    //Box
    MRI_box_systole_threshold_cervical->setStyleSheet(CSS_DSPINBOX);
    MRI_box_systole_delay_cervical->setStyleSheet(CSS_SPINBOX);
    MRI_box_arterial_move_cervical->setStyleSheet(CSS_SPINBOX);
    MRI_box_venous_move_cervical->setStyleSheet(CSS_SPINBOX);
    MRI_box_csf_move_cervical->setStyleSheet(CSS_SPINBOX);
    MRI_box_AV_adjust_cervical->setStyleSheet(CSS_COMBOBOX);
    MRI_box_ICVC_adjust_cervical->setStyleSheet(CSS_COMBOBOX);

    MRI_box_systole_threshold_cerebral->setStyleSheet(CSS_DSPINBOX);
    MRI_box_systole_delay_cerebral->setStyleSheet(CSS_SPINBOX);
    MRI_box_arterial_move_cerebral->setStyleSheet(CSS_SPINBOX);
    MRI_box_venous_move_cerebral->setStyleSheet(CSS_SPINBOX);
    MRI_box_csf_move_cerebral->setStyleSheet(CSS_SPINBOX);
    MRI_box_AV_adjust_cerebral->setStyleSheet(CSS_COMBOBOX);
    MRI_box_ICVC_adjust_cerebral->setStyleSheet(CSS_COMBOBOX);

    //Check
    MRI_check_move_cervical->setStyleSheet(CSS_CHECKBOX);
    MRI_check_move_cerebral->setStyleSheet(CSS_CHECKBOX);
    MRI_check_move_others->setStyleSheet(CSS_CHECKBOX);

    //Button
    MRI_button_quality_cervical->setStyleSheet(CSS_BUTTON);

    MRI_button_detect_systole_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_adjust_systole_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_show_systole_cervical->setStyleSheet(CSS_BUTTON);

    MRI_button_venous_corr_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_corr_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_auto_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_auto_cervical->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_move_right_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_move_left_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_right_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_left_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_right_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_left_cervical->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_smooth_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_legend_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_smooth_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_corr_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_smooth_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_corr_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_adjust_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_normalize_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_smooth_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_save_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_adjust_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_normalize_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_smooth_cervical->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_save_cervical->setStyleSheet(CSS_BUTTON);

    MRI_button_quality_cerebral->setStyleSheet(CSS_BUTTON);

    MRI_button_detect_systole_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_adjust_systole_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_show_systole_cerebral->setStyleSheet(CSS_BUTTON);

    MRI_button_venous_corr_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_corr_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_auto_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_auto_cerebral->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_move_right_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_move_left_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_right_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_left_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_right_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_left_cerebral->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_smooth_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_legend_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_smooth_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_corr_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_smooth_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_corr_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_adjust_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_normalize_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_smooth_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_AV_save_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_adjust_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_normalize_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_smooth_cerebral->setStyleSheet(CSS_BUTTON);
    MRI_button_ICVC_save_cerebral->setStyleSheet(CSS_BUTTON);

    //

    MRI_button_legend_cervical_cerebral->setStyleSheet(CSS_BUTTON);

    //

    MRI_button_quality_others->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_move_right_others->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_move_left_others->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_right_others->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_move_left_others->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_right_others->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_move_left_others->setStyleSheet(CSS_BUTTON);

    MRI_button_arterial_smooth_others->setStyleSheet(CSS_BUTTON);
    MRI_button_arterial_save_others->setStyleSheet(CSS_BUTTON);
    MRI_button_legend_others->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_smooth_others->setStyleSheet(CSS_BUTTON);
    MRI_button_venous_save_others->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_smooth_others->setStyleSheet(CSS_BUTTON);
    MRI_button_csf_save_others->setStyleSheet(CSS_BUTTON);


    //Label
    MRI_label_heart_rate_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_stroke_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_corr_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_stroke_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_corr_min_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_max_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_mean_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_grad_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_stroke_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_heart_rate_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_stroke_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_corr_min_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_max_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_mean_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_grad_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_stroke_cervical->setStyleSheet(CSS_LABEL_RED);
    MRI_label_AV_flow_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_stroke_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_stroke_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_min_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_max_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_mean_cervical->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_grad_cervical->setStyleSheet(CSS_LABEL_GLOBAL);

    MRI_label_heart_rate_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_stroke_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_corr_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_stroke_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_corr_min_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_max_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_mean_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_grad_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_venous_corr_stroke_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_heart_rate_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_stroke_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_corr_min_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_max_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_mean_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_grad_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_csf_corr_stroke_cerebral->setStyleSheet(CSS_LABEL_RED);
    MRI_label_AV_flow_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_flow_stroke_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_AV_volume_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_flow_stroke_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_min_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_max_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_mean_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_ICVC_volume_grad_cerebral->setStyleSheet(CSS_LABEL_GLOBAL);

    //

    MRI_label_heart_rate_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_min_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_max_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_mean_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_grad_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_arterial_stroke_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_min_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_max_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_mean_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_grad_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_venous_stroke_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_heart_rate_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_min_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_max_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_mean_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_grad_others->setStyleSheet(CSS_LABEL_GLOBAL);
    MRI_label_csf_stroke_others->setStyleSheet(CSS_LABEL_GLOBAL);
}


//**********//
//***PLOT***//
//**********//
/*!
 * \brief MainWindow::plot_MRI_cervical
 */
bool MainWindow::plot_MRI_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res1 = plot_MRI_arterial_cervical();
    bool res2 = plot_MRI_venous_cervical();
    if (res2){
        plot_MRI_venous_corr_cervical();
    }
    bool res3 = plot_MRI_csf_cervical();
    if (res3){
        plot_MRI_csf_corr_cervical();
    }

    if (res1 && res2 && res3){
        return true;
    }
    else{
        status_error(MRI_ERROR_001);
        return false;
    }
}

/*!
 * \brief MainWindow::plot_MRI_arterial_cervical
 */
bool MainWindow::plot_MRI_arterial_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cervical >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cervical == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_arterial_cervical->graph(0)->setData(xy1, xy2);

        MRI_plot_arterial_cervical->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cervical == 0){
            MRI_plot_arterial_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));
        }
        else{
            MRI_plot_arterial_cervical->yAxis->setRange(0, max(xy[1]));
        }

        delete[] xy;

        MRI_plot_arterial_cervical->xAxis->setLabel(MRI_time_unity);
        MRI_plot_arterial_cervical->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_arterial_files_cervical->size(); i++){
            files_names.append(MRI_arterial_files_cervical->at(i));
            if (i < MRI_arterial_files_cervical->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_arterial_cervical->graph(0)->setName(files_names);

        MRI_plot_arterial_cervical->replot();

        //Print
        print_MRI_arterial_cervical();



        return true;
    }
    else{
        status_error(MRI_ERROR_002);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_systole_cervical
 */
bool MainWindow::plot_MRI_systole_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_systole_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_systole_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        MRI_plot_arterial_cervical->graph(1)->setData(xy[0], xy[1]);

        delete[] xy;

        MRI_plot_arterial_cervical->replot();

        return true;
    }
    else{
        status_error(MRI_ERROR_003);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_venous_cervical
 */
bool MainWindow::plot_MRI_venous_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_venous_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        if (MRI_check_venous_cervical->isChecked()){
            for (int i = 0; i < npi; i++){
                xy[1][i] = -xy[1][i];
            }
        }

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cervical >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cervical == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_venous_cervical->graph(0)->setData(xy1, xy2);

        MRI_plot_venous_cervical->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cervical == 0){
            MRI_plot_venous_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));
        }
        else{
            if (MRI_check_venous_cervical->isChecked()){
                MRI_plot_venous_cervical->yAxis->setRange(0, max(xy[1]));
            }
            else{
                MRI_plot_venous_cervical->yAxis->setRange(min(xy[1]), 0);
            }
        }

        delete[] xy;

        MRI_plot_venous_cervical->xAxis->setLabel(MRI_time_unity);
        MRI_plot_venous_cervical->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_venous_files_cervical->size(); i++){
            files_names.append(MRI_venous_files_cervical->at(i));
            if (i < MRI_venous_files_cervical->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_venous_cervical->graph(0)->setName(files_names);

        MRI_plot_venous_cervical->replot();

        //Print
        print_MRI_venous_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_004);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_venous_corr_cervical
 */
bool MainWindow::plot_MRI_venous_corr_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_corr_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_venous_corr_cervical);
        QVector<double> *xy_2 = Coord2QVector(MRI_coord_venous_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy_2, MRI_flow_unity, MRI_time_unity);

        if (MRI_check_venous_cervical->isChecked()){
            for (int i = 0; i < npi; i++){
                xy[1][i] = -xy[1][i];
                xy_2[1][i] = -xy_2[1][i];
            }
        }

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cervical >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cervical == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_venous_cervical->graph(1)->setData(xy1, xy2);

        MRI_plot_venous_cervical->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cervical == 0){
            MRI_plot_venous_cervical->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), max(max(xy[1]), max(xy_2[1])));
        }
        else{
            if (MRI_check_venous_cervical->isChecked()){
                MRI_plot_venous_cervical->yAxis->setRange(0, max(max(xy[1]), max(xy_2[1])));
            }
            else{
                MRI_plot_venous_cervical->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), 0);
            }
        }

        delete[] xy;
        delete[] xy_2;

        MRI_plot_venous_cervical->replot();

        print_MRI_venous_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_005);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_csf_cervical
 */
bool MainWindow::plot_MRI_csf_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_csf_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cervical >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cervical == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_csf_cervical->graph(0)->setData(xy1, xy2);

        MRI_plot_csf_cervical->xAxis->setRange(min(xy1), max(xy1));
        MRI_plot_csf_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));

        delete[] xy;

        MRI_plot_csf_cervical->xAxis->setLabel(MRI_time_unity);
        MRI_plot_csf_cervical->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_CSF_files_cervical->size(); i++){
            files_names.append(MRI_CSF_files_cervical->at(i));
            if (i < MRI_CSF_files_cervical->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_csf_cervical->graph(0)->setName(files_names);

        MRI_plot_csf_cervical->replot();

        //Print
        print_MRI_csf_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_006);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_csf_corr_cervical
 */
bool MainWindow::plot_MRI_csf_corr_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_corr_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_csf_corr_cervical);
        QVector<double> *xy_2 = Coord2QVector(MRI_coord_csf_cervical);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy_2, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cervical >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cervical == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_csf_cervical->graph(1)->setData(xy1, xy2);

        MRI_plot_csf_cervical->xAxis->setRange(min(xy1), max(xy1));
        MRI_plot_csf_cervical->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), max(max(xy[1]), max(xy_2[1])));

        delete[] xy;
        delete[] xy_2;

        MRI_plot_csf_cervical->replot();

        print_MRI_csf_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_007);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_AV_cervical
 */
bool MainWindow::plot_MRI_AV_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cervical->size();
    n = min(n, MRI_coord_AV_volume_cervical->size());

    if (n > 0){
        double minx, maxx;
        double miny, maxy;

        QVector<double> *xy;
        if (MRI_box_AV_flow_volume_cervical->currentIndex() == 0){
            QPen purplepen;
            purplepen.setColor(QColor(128, 0, 128));
            MRI_plot_AV_cervical->graph(0)->setPen(purplepen);
            xy= Coord2QVector(MRI_coord_AV_flow_cervical);
            if (MRI_AV_flow_cervical_normalized == 0) unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            if (MRI_check_AV_csf_cervical->isChecked()){
                QVector<double> *xy2 = Coord2QVector(MRI_coord_csf_corr_cervical);

                if (MRI_AV_flow_cervical_normalized == 0) unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

                MRI_plot_AV_cervical->graph(1)->setData(xy[0], xy2[1]);

                minx = min(minx, min(xy2[0]));
                maxx = max(maxx, max(xy2[0]));
                miny = min(miny, min(xy2[1]));
                maxy = max(maxy, max(xy2[1]));

                delete[] xy2;
            }
            else{
                MRI_plot_AV_cervical->graph(1)->clearData();
            }
        }
        else{
            QPen orangepen;
            orangepen.setColor(QColor(255, 165, 0));
            MRI_plot_AV_cervical->graph(0)->setPen(orangepen);
            xy= Coord2QVector(MRI_coord_AV_volume_cervical);
            if (MRI_AV_volume_cervical_normalized == 0) unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            if (MRI_check_AV_csf_cervical->isChecked()){
                QVector<double> *xy2 = Coord2QVector(MRI_coord_csf_corr_cervical);

                if (MRI_AV_volume_cervical_normalized == 0) unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

                QVector<double> *csf_volume = new QVector<double>;
                csf_volume->append(xy2[1].at(0) * xy2[0].at(0));
                for (int i = 1; i < MRI_coord_csf_corr_cervical->size(); i++){
                    csf_volume->append(csf_volume->at(i-1) + (xy2[1].at(i) * (xy2[0].at(i) - xy2[0].at(i-1))) );
                }

                MRI_plot_AV_cervical->graph(1)->setData(xy[0], *csf_volume);

                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(*csf_volume));
                maxy = max(maxy, max(*csf_volume));

                delete[] xy2;
            }
            else{
                MRI_plot_AV_cervical->graph(1)->clearData();
            }
        }

        MRI_plot_AV_cervical->graph(0)->setData(xy[0], xy[1]);

        delete[] xy;

        MRI_plot_AV_cervical->xAxis->setRange(minx, maxx);
        MRI_plot_AV_cervical->yAxis->setRange(miny, maxy);

        MRI_plot_AV_cervical->replot();

        //Print
        print_MRI_AV_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_008);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_ICVC_cervical
 */
bool MainWindow::plot_MRI_ICVC_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cervical->size();
    n = min(n, MRI_coord_ICVC_volume_cervical->size());

    if (n > 0){
        //Plot
        QVector<double> *xy;
        if (MRI_box_ICVC_flow_volume_cervical->currentIndex() == 0){
            QPen purplepen;
            purplepen.setColor(QColor(128, 0, 128));
            MRI_plot_ICVC_cervical->graph(0)->setPen(purplepen);
            xy= Coord2QVector(MRI_coord_ICVC_flow_cervical);
            if (MRI_ICVC_flow_cervical_normalized == 0) unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        }
        else{
            QPen orangepen;
            orangepen.setColor(QColor(255, 165, 0));
            MRI_plot_ICVC_cervical->graph(0)->setPen(orangepen);
            xy= Coord2QVector(MRI_coord_ICVC_volume_cervical);
            if (MRI_ICVC_volume_cervical_normalized == 0) unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);
        }

        MRI_plot_ICVC_cervical->graph(0)->setData(xy[0], xy[1]);

        MRI_plot_ICVC_cervical->xAxis->setRange(min(xy[0]), max(xy[0]));
        MRI_plot_ICVC_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));

        delete[] xy;

        MRI_plot_ICVC_cervical->replot();

        //Print
        print_MRI_ICVC_cervical();

        return true;
    }
    else{
        status_error(MRI_ERROR_009);
    }

    return false;
}

//

/*!
 * \brief MainWindow::plot_MRI_cerebral
 */
bool MainWindow::plot_MRI_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res1 = plot_MRI_arterial_cerebral();
    bool res2 = plot_MRI_venous_cerebral();
    if (res2){
        plot_MRI_venous_corr_cerebral();
    }
    bool res3 = plot_MRI_csf_cerebral();
    if (res3){
        plot_MRI_csf_corr_cerebral();
    }

    if (res1 && res2 && res3){
        return true;
    }
    else{
        status_error(MRI_ERROR_010);
        return false;
    }
}

/*!
 * \brief MainWindow::plot_MRI_arterial_cerebral
 */
bool MainWindow::plot_MRI_arterial_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cerebral >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cerebral == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_arterial_cerebral->graph(0)->setData(xy1, xy2);

        MRI_plot_arterial_cerebral->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cerebral == 0){
            MRI_plot_arterial_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));
        }
        else{
            MRI_plot_arterial_cerebral->yAxis->setRange(0, max(xy[1]));
        }

        delete[] xy;

        MRI_plot_arterial_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_arterial_cerebral->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_arterial_files_cerebral->size(); i++){
            files_names.append(MRI_arterial_files_cerebral->at(i));
            if (i < MRI_arterial_files_cerebral->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_arterial_cerebral->graph(0)->setName(files_names);

        MRI_plot_arterial_cerebral->replot();

        //Print
        print_MRI_arterial_cerebral();



        return true;
    }
    else{
        status_error(MRI_ERROR_011);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_systole_cerebral
 */
bool MainWindow::plot_MRI_systole_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_systole_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_systole_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        MRI_plot_arterial_cerebral->graph(1)->setData(xy[0], xy[1]);

        delete[] xy;

        MRI_plot_arterial_cerebral->replot();

        return true;
    }
    else{
        status_error(MRI_ERROR_012);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_venous_cerebral
 */
bool MainWindow::plot_MRI_venous_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_venous_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        if (MRI_check_venous_cerebral->isChecked()){
            for (int i = 0; i < npi; i++){
                xy[1][i] = -xy[1][i];
            }
        }

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cerebral >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cerebral == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_venous_cerebral->graph(0)->setData(xy1, xy2);

        MRI_plot_venous_cerebral->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cerebral == 0){
            MRI_plot_venous_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));
        }
        else{
            if (MRI_check_venous_cerebral->isChecked()){
                MRI_plot_venous_cerebral->yAxis->setRange(0, max(xy[1]));
            }
            else{
                MRI_plot_venous_cerebral->yAxis->setRange(min(xy[1]), 0);
            }
        }

        delete[] xy;

        MRI_plot_venous_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_venous_cerebral->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_venous_files_cerebral->size(); i++){
            files_names.append(MRI_venous_files_cerebral->at(i));
            if (i < MRI_venous_files_cerebral->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_venous_cerebral->graph(0)->setName(files_names);

        MRI_plot_venous_cerebral->replot();

        //Print
        print_MRI_venous_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_013);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_venous_corr_cerebral
 */
bool MainWindow::plot_MRI_venous_corr_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_corr_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_venous_corr_cerebral);
        QVector<double> *xy_2 = Coord2QVector(MRI_coord_venous_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy_2, MRI_flow_unity, MRI_time_unity);

        if (MRI_check_venous_cerebral->isChecked()){
            for (int i = 0; i < npi; i++){
                xy[1][i] = -xy[1][i];
                xy_2[1][i] = -xy_2[1][i];
            }
        }

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cerebral >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cerebral == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_venous_cerebral->graph(1)->setData(xy1, xy2);

        MRI_plot_venous_cerebral->xAxis->setRange(min(xy1), max(xy1));
        if (MRI_plot_00_cerebral == 0){
            MRI_plot_venous_cerebral->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), max(max(xy[1]), max(xy_2[1])));
        }
        else{
            if (MRI_check_venous_cerebral->isChecked()){
                MRI_plot_venous_cerebral->yAxis->setRange(0, max(max(xy[1]), max(xy_2[1])));
            }
            else{
                MRI_plot_venous_cerebral->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), 0);
            }
        }

        delete[] xy;
        delete[] xy_2;

        MRI_plot_venous_cerebral->replot();

        print_MRI_venous_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_014);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_csf_cerebral
 */
bool MainWindow::plot_MRI_csf_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        //Plot
        QVector<double> *xy = Coord2QVector(MRI_coord_csf_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cerebral >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cerebral == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_csf_cerebral->graph(0)->setData(xy1, xy2);

        MRI_plot_csf_cerebral->xAxis->setRange(min(xy1), max(xy1));
        MRI_plot_csf_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));

        delete[] xy;

        MRI_plot_csf_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_csf_cerebral->yAxis->setLabel(MRI_flow_unity);

        QString files_names;
        for (int i = 0; i < MRI_CSF_files_cerebral->size(); i++){
            files_names.append(MRI_CSF_files_cerebral->at(i));
            if (i < MRI_CSF_files_cerebral->size()-1){
                files_names.append(MAINWINDOW_MRI_PLUS);
            }
        }
        MRI_plot_csf_cerebral->graph(0)->setName(files_names);

        MRI_plot_csf_cerebral->replot();

        //Print
        print_MRI_csf_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_015);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_csf_corr_cerebral
 */
bool MainWindow::plot_MRI_csf_corr_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_corr_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_csf_corr_cerebral);
        QVector<double> *xy_2 = Coord2QVector(MRI_coord_csf_cerebral);

        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy_2, MRI_flow_unity, MRI_time_unity);

        QVector<double> xy1, xy2;
        int n = xy[0].size();
        for (int i = 0; i < n; i++){
            xy1.append(xy[0].at(i));
            xy2.append(xy[1].at(i));
        }
        if (MRI_ncycles_cerebral >=2){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step1+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }
        if (MRI_ncycles_cerebral == 3){
            double step1 = (xy[0].at(n-1) / n) + xy[0].at(n-1);
            double step2 = step1 + xy[0].at(n-1);
            for (int i = 0; i < n; i++){
                xy1.append(step2+xy[0].at(i));
                xy2.append(xy[1].at(i));
            }
        }

        MRI_plot_csf_cerebral->graph(1)->setData(xy1, xy2);

        MRI_plot_csf_cerebral->xAxis->setRange(min(xy1), max(xy1));
        MRI_plot_csf_cerebral->yAxis->setRange(min(min(xy[1]), min(xy_2[1])), max(max(xy[1]), max(xy_2[1])));

        delete[] xy;
        delete[] xy_2;

        MRI_plot_csf_cerebral->replot();

        print_MRI_csf_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_016);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_AV_cerebral
 */
bool MainWindow::plot_MRI_AV_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cerebral->size();
    n = min(n, MRI_coord_AV_volume_cerebral->size());

    if (n > 0){
        double minx, maxx;
        double miny, maxy;

        QVector<double> *xy;
        if (MRI_box_AV_flow_volume_cerebral->currentIndex() == 0){
            QPen purplepen;
            purplepen.setColor(QColor(128, 0, 128));
            MRI_plot_AV_cerebral->graph(0)->setPen(purplepen);
            xy = Coord2QVector(MRI_coord_AV_flow_cerebral);
            if (MRI_AV_flow_cerebral_normalized == 0) unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            if (MRI_check_AV_csf_cerebral->isChecked()){
                QVector<double> *xy2 = Coord2QVector(MRI_coord_csf_corr_cerebral);

                if (MRI_AV_flow_cerebral_normalized == 0) unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

                MRI_plot_AV_cerebral->graph(1)->setData(xy[0], xy2[1]);

                minx = min(minx, min(xy2[0]));
                maxx = max(maxx, max(xy2[0]));
                miny = min(miny, min(xy2[1]));
                maxy = max(maxy, max(xy2[1]));

                delete[] xy2;
            }
            else{
                MRI_plot_AV_cerebral->graph(1)->clearData();
            }
        }
        else{
            QPen orangepen;
            orangepen.setColor(QColor(255, 165, 0));
            MRI_plot_AV_cerebral->graph(0)->setPen(orangepen);
            xy = Coord2QVector(MRI_coord_AV_volume_cerebral);
            if (MRI_AV_volume_cerebral_normalized == 0) unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            if(MRI_check_AV_csf_cerebral->isChecked()){
                QVector<double> *xy2 = Coord2QVector(MRI_coord_csf_corr_cerebral);

                if (MRI_AV_volume_cerebral_normalized == 0) unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

                QVector<double> *csf_volume = new QVector<double>;
                csf_volume->append(xy2[1].at(0) * xy2[0].at(0));
                for (int i = 1; i < MRI_coord_csf_corr_cerebral->size(); i++){
                    csf_volume->append(csf_volume->at(i-1) + (xy2[1].at(i) * (xy2[0].at(i) - xy2[0].at(i-1))) );
                }

                MRI_plot_AV_cerebral->graph(1)->setData(xy[0], *csf_volume);

                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(*csf_volume));
                maxy = max(maxy, max(*csf_volume));

                delete[] xy2;
            }
            else{
                MRI_plot_AV_cerebral->graph(1)->clearData();
            }
        }

        MRI_plot_AV_cerebral->graph(0)->setData(xy[0], xy[1]);

        delete[] xy;

        MRI_plot_AV_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_AV_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_AV_cerebral->replot();

        //Print
        print_MRI_AV_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_017);
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_ICVC_cerebral
 */
bool MainWindow::plot_MRI_ICVC_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cerebral->size();
    n = min(n, MRI_coord_ICVC_volume_cerebral->size());

    if (n > 0){
        //Plot
        QVector<double> *xy;
        if (MRI_box_ICVC_flow_volume_cerebral->currentIndex() == 0){
            QPen purplepen;
            purplepen.setColor(QColor(128, 0, 128));
            MRI_plot_ICVC_cerebral->graph(0)->setPen(purplepen);
            xy= Coord2QVector(MRI_coord_ICVC_flow_cerebral);
            if (MRI_ICVC_flow_cerebral_normalized == 0) unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);
        }
        else{
            QPen orangepen;
            orangepen.setColor(QColor(255, 165, 0));
            MRI_plot_ICVC_cerebral->graph(0)->setPen(orangepen);
            xy= Coord2QVector(MRI_coord_ICVC_volume_cerebral);
            if (MRI_ICVC_volume_cerebral_normalized == 0) unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);
        }

        MRI_plot_ICVC_cerebral->graph(0)->setData(xy[0], xy[1]);

        MRI_plot_ICVC_cerebral->xAxis->setRange(min(xy[0]), max(xy[0]));
        MRI_plot_ICVC_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));

        delete[] xy;

        MRI_plot_ICVC_cerebral->replot();

        //Print
        print_MRI_ICVC_cerebral();

        return true;
    }
    else{
        status_error(MRI_ERROR_018);
    }

    return false;
}

//

bool MainWindow::plot_MRI_cervical_cerebral(){
    bool res1 = plot_MRI_arterial_cervical_cerebral();
    bool res2 = plot_MRI_venous_cervical_cerebral();
    bool res3 = plot_MRI_csf_cervical_cerebral();
    bool res4 = plot_MRI_AV_flow_cervical_cerebral();
    if (res4){
        plot_MRI_AV_volume_cervical_cerebral();
    }
    bool res5 = plot_MRI_ICVC_flow_cervical_cerebral();
    if (res5){
        plot_MRI_ICVC_volume_cervical_cerebral();
    }
    do_MRI_dphi();

    if(res1 && res2 && res3 && res4 && res5){
        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_arterial_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cerebral->size();
    int n2 = MRI_coord_arterial_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cervical);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_arterial_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

            ok = true;
            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            delete[] xy;
        }
        if (n2 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cerebral);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_arterial_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

            if (ok){
                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(xy[1]));
                maxy = max(maxy, max(xy[1]));
            }
            else{
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);
            }

            delete[] xy;
        }
        MRI_plot_arterial_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_arterial_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_arterial_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_arterial_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_arterial_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_venous_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_venous_cerebral->size();
    int n2 = MRI_coord_venous_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        bool ok2 = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            if (MRI_coord_venous_corr_cervical->size() > 0){
                n1 = MRI_coord_venous_corr_cervical->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_venous_corr_cervical);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                if (MRI_check_venous_cervical->isChecked()){
                    for (int i = 0; i < npi; i++){
                        xy[1][i] = -xy[1][i];
                    }
                }

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_venous_cervical_cerebral->graph(2)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;

                if (!MRI_check_venous_cervical_cerebral->isChecked()) MRI_plot_venous_cervical_cerebral->graph(0)->clearData();
            }
            if (!ok || MRI_check_venous_cervical_cerebral->isChecked()){
                n1 = MRI_coord_venous_cerebral->size();
                QVector<double> *xy = Coord2QVector(MRI_coord_venous_cervical);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                if (MRI_check_venous_cervical->isChecked()){
                    for (int i = 0; i < npi; i++){
                        xy[1][i] = -xy[1][i];
                    }
                }

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_venous_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;

                ok = true;

                if (!MRI_check_venous_cervical_cerebral->isChecked()) MRI_plot_venous_cervical_cerebral->graph(2)->clearData();
            }
        }
        if (n2 > 0){
            if (MRI_coord_venous_corr_cerebral->size() > 0){
                n2 = MRI_coord_venous_corr_cerebral->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_venous_corr_cerebral);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                if (MRI_check_venous_cervical->isChecked()){
                    for (int i = 0; i < npi; i++){
                        xy[1][i] = -xy[1][i];
                    }
                }

                MRI_plot_venous_cervical_cerebral->graph(3)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;

                ok2 = true;

                if (!MRI_check_venous_cervical_cerebral->isChecked()) MRI_plot_venous_cervical_cerebral->graph(1)->clearData();
            }
            if(!ok2 || MRI_check_venous_cervical_cerebral->isChecked()){
                n2 = MRI_coord_venous_cerebral->size();
                QVector<double> *xy = Coord2QVector(MRI_coord_venous_cerebral);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                if (MRI_check_venous_cerebral->isChecked()){
                    for (int i = 0; i < npi; i++){
                        xy[1][i] = -xy[1][i];
                    }
                }

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_venous_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

                if (ok || ok2){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;

                if (!MRI_check_venous_cervical_cerebral->isChecked()) MRI_plot_venous_cervical_cerebral->graph(3)->clearData();
            }
        }
        MRI_plot_venous_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_venous_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_venous_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_venous_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_venous_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_csf_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_csf_cerebral->size();
    int n2 = MRI_coord_csf_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        bool ok2 = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            if (MRI_coord_csf_corr_cervical->size() > 0){
                n1 = MRI_coord_csf_corr_cervical->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_csf_corr_cervical);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_csf_cervical_cerebral->graph(2)->setData(xy[0], xy[1]);

                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;

                ok = true;

                if (!MRI_check_csf_cervical_cerebral->isChecked()) MRI_plot_csf_cervical_cerebral->graph(0)->clearData();
            }
            if (!ok || MRI_check_csf_cervical_cerebral->isChecked()){
                n1 = MRI_coord_csf_cerebral->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_csf_cervical);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_csf_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;

                ok = true;

                if(!MRI_check_csf_cervical_cerebral->isChecked()) MRI_plot_csf_cervical_cerebral->graph(2)->clearData();
            }
        }
        if (n2 > 0){
            if (MRI_coord_csf_corr_cerebral->size() > 0){
                n2 = MRI_coord_csf_corr_cerebral->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_csf_corr_cerebral);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_csf_cervical_cerebral->graph(3)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;

                ok2 = true;

                if (!MRI_check_csf_cervical_cerebral->isChecked()) MRI_plot_csf_cervical_cerebral->graph(1)->clearData();
            }
            if (!ok2 || MRI_check_csf_cervical_cerebral->isChecked()){
                n2 = MRI_coord_csf_cerebral->size();

                QVector<double> *xy = Coord2QVector(MRI_coord_csf_cerebral);

                unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                //Normalize x
                {
                    double maxx = max(xy[0]);
                    for (int i = 0; i < n1; i++){
                        xy[0][i] = xy[0][i] / maxx;
                    }
                }

                MRI_plot_csf_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

                if (ok || ok2){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_csf_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_csf_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_csf_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_csf_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_csf_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_AV_flow_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_AV_flow_cervical->size();
    int n2 = MRI_coord_AV_flow_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_AV_flow_cervical);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_AV_flow_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

            ok = true;
            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            delete[] xy;
        }
        if (n2 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_AV_flow_cerebral);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_AV_flow_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

            if (ok){
                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(xy[1]));
                maxy = max(maxy, max(xy[1]));
            }
            else{
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);
            }

            delete[] xy;
        }
        MRI_plot_AV_flow_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_AV_flow_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_AV_flow_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_AV_flow_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_AV_flow_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_AV_volume_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_AV_volume_cervical->size();
    int n2 = MRI_coord_AV_volume_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_AV_volume_cervical);

            unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_AV_volume_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

            ok = true;
            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            delete[] xy;
        }
        if (n2 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_AV_volume_cerebral);

            unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_AV_volume_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

            if (ok){
                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(xy[1]));
                maxy = max(maxy, max(xy[1]));
            }
            else{
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);
            }

            delete[] xy;
        }

        MRI_plot_AV_volume_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_AV_volume_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_AV_volume_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_AV_volume_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_AV_volume_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_ICVC_flow_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_ICVC_flow_cerebral->size();
    int n2 = MRI_coord_ICVC_flow_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_ICVC_flow_cervical);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_ICVC_flow_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

            ok = true;
            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            delete[] xy;
        }
        if (n2 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_ICVC_flow_cerebral);

            unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_ICVC_flow_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

            if (ok){
                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(xy[1]));
                maxy = max(maxy, max(xy[1]));
            }
            else{
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);
            }

            delete[] xy;
        }
        MRI_plot_ICVC_flow_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_ICVC_flow_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_ICVC_flow_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_ICVC_flow_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_ICVC_flow_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::plot_MRI_ICVC_volume_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_ICVC_volume_cervical->size();
    int n2 = MRI_coord_ICVC_volume_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_ICVC_volume_cervical);

            unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_ICVC_volume_cervical_cerebral->graph(0)->setData(xy[0], xy[1]);

            ok = true;
            minx = min(xy[0]);
            maxx = max(xy[0]);
            miny = min(xy[1]);
            maxy = max(xy[1]);

            delete[] xy;
        }
        if (n2 > 0){
            QVector<double> *xy = Coord2QVector(MRI_coord_ICVC_volume_cerebral);

            unity_convert_volume(xy, MRI_volume_unity, MRI_time_unity);

            //Normalize x
            {
                double maxx = max(xy[0]);
                for (int i = 0; i < n1; i++){
                    xy[0][i] = xy[0][i] / maxx;
                }
            }

            MRI_plot_ICVC_volume_cervical_cerebral->graph(1)->setData(xy[0], xy[1]);

            if (ok){
                minx = min(minx, min(xy[0]));
                maxx = max(maxx, max(xy[0]));
                miny = min(miny, min(xy[1]));
                maxy = max(maxy, max(xy[1]));
            }
            else{
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);
            }

            delete[] xy;
        }
        MRI_plot_ICVC_volume_cervical_cerebral->xAxis->setRange(minx, maxx);
        MRI_plot_ICVC_volume_cervical_cerebral->yAxis->setRange(miny, maxy);

        MRI_plot_ICVC_volume_cervical_cerebral->xAxis->setLabel(MRI_time_unity);
        MRI_plot_ICVC_volume_cervical_cerebral->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_ICVC_volume_cervical_cerebral->replot();

        return true;
    }
    else{
        return false;
    }
}

void MainWindow::do_MRI_legend_cervical_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if(MRI_legend_cervical_cerebral == 0){
        MRI_plot_arterial_cervical_cerebral->legend->setVisible(true);
        MRI_plot_arterial_cervical_cerebral->replot();
        MRI_plot_venous_cervical_cerebral->legend->setVisible(true);
        MRI_plot_venous_cervical_cerebral->replot();
        MRI_plot_csf_cervical_cerebral->legend->setVisible(true);
        MRI_plot_csf_cervical_cerebral->replot();
        MRI_plot_AV_flow_cervical_cerebral->legend->setVisible(true);
        MRI_plot_AV_flow_cervical_cerebral->replot();
        MRI_plot_AV_volume_cervical_cerebral->legend->setVisible(true);
        MRI_plot_AV_volume_cervical_cerebral->replot();
        MRI_plot_ICVC_flow_cervical_cerebral->legend->setVisible(true);
        MRI_plot_ICVC_flow_cervical_cerebral->replot();
        MRI_plot_ICVC_volume_cervical_cerebral->legend->setVisible(true);
        MRI_plot_ICVC_volume_cervical_cerebral->replot();


        MRI_legend_cervical_cerebral++;
        MRI_legend_cervical_cerebral = MRI_legend_cervical_cerebral % 2;
    }
    else{
        MRI_plot_arterial_cervical_cerebral->legend->setVisible(false);
        MRI_plot_arterial_cervical_cerebral->replot();
        MRI_plot_venous_cervical_cerebral->legend->setVisible(false);
        MRI_plot_venous_cervical_cerebral->replot();
        MRI_plot_csf_cervical_cerebral->legend->setVisible(false);
        MRI_plot_csf_cervical_cerebral->replot();
        MRI_plot_AV_flow_cervical_cerebral->legend->setVisible(false);
        MRI_plot_AV_flow_cervical_cerebral->replot();
        MRI_plot_AV_volume_cervical_cerebral->legend->setVisible(false);
        MRI_plot_AV_volume_cervical_cerebral->replot();
        MRI_plot_ICVC_flow_cervical_cerebral->legend->setVisible(false);
        MRI_plot_ICVC_flow_cervical_cerebral->replot();
        MRI_plot_ICVC_volume_cervical_cerebral->legend->setVisible(false);
        MRI_plot_ICVC_volume_cervical_cerebral->replot();

        MRI_legend_cervical_cerebral++;
        MRI_legend_cervical_cerebral = MRI_legend_cervical_cerebral % 2;
    }
}

//

bool MainWindow::plot_MRI_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res1 = plot_MRI_arterial_spectrum();
    bool res2 = plot_MRI_venous_spectrum();
    bool res3 = plot_MRI_csf_spectrum();
    bool res4 = plot_MRI_AV_flow_spectrum();
    bool res5 = plot_MRI_AV_volume_spectrum();
    bool res6 = plot_MRI_ICVC_flow_spectrum();
    bool res7 = plot_MRI_ICVC_volume_spectrum();

    if (res1 && res2 && res3 && res4 && res5 && res6 && res7){
        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_arterial_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cervical->size();
    int n2 = MRI_coord_arterial_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier(coord_fourier, *MRI_coord_arterial_cervical);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                double sample = 1. / (MRI_coord_arterial_cervical->coord(1, XCOORD) - MRI_coord_arterial_cervical->coord(0, XCOORD)) / MRI_coord_arterial_cervical->size();   //bug correction 25/04/2016
                for (int i = 0; i < xy[0].size(); i++){
                    xy[0].replace(i, xy[0].at(i) * sample);
                }

                MRI_plot_arterial_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier(coord_fourier, *MRI_coord_arterial_cerebral);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                double sample = 1. / (MRI_coord_arterial_cerebral->coord(1, XCOORD) - MRI_coord_arterial_cerebral->coord(0, XCOORD)) / MRI_coord_arterial_cerebral->size();   //bug correction 25/04/2016
                for (int i = 0; i < xy[0].size(); i++){
                    xy[0].replace(i, xy[0].at(i) * sample);
                }

                MRI_plot_arterial_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_arterial_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_arterial_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_arterial_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_venous_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_venous_cervical->size();
    int n2 = MRI_coord_venous_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res;
            if (MRI_coord_venous_corr_cervical->size() > 0){
                res = fourier_test(coord_fourier, *MRI_coord_venous_corr_cervical);
            }
            else{
                res = fourier_test(coord_fourier, *MRI_coord_venous_cervical);
            }

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_venous_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res;
            if (MRI_coord_venous_corr_cerebral->size() > 0){
                res = fourier_test(coord_fourier, *MRI_coord_venous_corr_cerebral);
            }
            else{
                res = fourier_test(coord_fourier, *MRI_coord_venous_cerebral);
            }

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_venous_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_venous_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_venous_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_venous_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_csf_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_csf_cervical->size();
    int n2 = MRI_coord_csf_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res;
            if (MRI_coord_csf_corr_cervical->size() > 0){
                res = fourier_test(coord_fourier, *MRI_coord_csf_corr_cervical);
            }
            else{
                res = fourier_test(coord_fourier, *MRI_coord_csf_cervical);
            }

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_csf_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res;
            if (MRI_coord_csf_corr_cerebral->size() > 0){
                res = fourier_test(coord_fourier, *MRI_coord_csf_corr_cerebral);
            }
            else{
                res = fourier_test(coord_fourier, *MRI_coord_csf_cerebral);
            }

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_csf_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_csf_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_csf_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_csf_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_AV_flow_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_AV_flow_cervical->size();
    int n2 = MRI_coord_AV_flow_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_AV_flow_cervical);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_AV_flow_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_AV_flow_cerebral);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_AV_flow_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_AV_flow_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_AV_flow_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_AV_flow_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_AV_volume_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_AV_volume_cervical->size();
    int n2 = MRI_coord_AV_volume_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_AV_volume_cervical);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_AV_volume_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_AV_volume_cerebral);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_AV_volume_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_AV_volume_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_AV_volume_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_AV_volume_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_ICVC_flow_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_ICVC_flow_cervical->size();
    int n2 = MRI_coord_ICVC_flow_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_ICVC_flow_cervical);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_ICVC_flow_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_ICVC_flow_cerebral);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_ICVC_flow_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_ICVC_flow_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_ICVC_flow_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_ICVC_flow_spectrum->replot();

        return true;
    }
    return false;
}

bool MainWindow::plot_MRI_ICVC_volume_spectrum(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_ICVC_volume_cervical->size();
    int n2 = MRI_coord_ICVC_volume_cerebral->size();

    if (n1 > 0 || n2 > 0){
        bool ok = false;
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        if (n1 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_ICVC_volume_cervical);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_ICVC_volume_spectrum->graph(0)->setData(xy[0], xy[1]);

                ok = true;
                minx = min(xy[0]);
                maxx = max(xy[0]);
                miny = min(xy[1]);
                maxy = max(xy[1]);

                delete[] xy;
            }
        }
        if (n2 > 0){
            //Fourier
            Coord *coord_fourier = new Coord;
            bool res = fourier_test(coord_fourier, *MRI_coord_ICVC_volume_cerebral);

            if (res){
                QVector<double> *xy = Coord2QVector(coord_fourier);

                MRI_plot_ICVC_volume_spectrum->graph(1)->setData(xy[0], xy[1]);

                if (ok){
                    minx = min(minx, min(xy[0]));
                    maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1]));
                    maxy = max(maxy, max(xy[1]));
                }
                else{
                    minx = min(xy[0]);
                    maxx = max(xy[0]);
                    miny = min(xy[1]);
                    maxy = max(xy[1]);
                }

                delete[] xy;
            }
        }
        MRI_plot_ICVC_volume_spectrum->xAxis->setRange(minx, maxx/5.);  //test sg 30/05/2016
        MRI_plot_ICVC_volume_spectrum->yAxis->setRange(miny, maxy);

        MRI_plot_ICVC_volume_spectrum->replot();

        return true;
    }
    return false;
}

//

/*!
 * \brief MainWindow::plot_MRI_others
 */
bool MainWindow::plot_MRI_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res1 = plot_MRI_arterial_others();
    bool res2 = plot_MRI_venous_others();
    bool res3 = plot_MRI_csf_others();

    if (res1 && res2 && res3){
        return true;
    }
    else{
        status_error(MRI_ERROR_019);
        return false;
    }
}

/*!
 * \brief MainWindow::plot_MRI_arterial_others
 */
bool MainWindow::plot_MRI_arterial_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_plot_arterial_others->clearGraphs();

    int n_actions = MRI_button_arterial_choice->menu()->actions().count();

    if (n_actions > 0){
        int n_actions_plus = n_actions + MRI_button_venous_choice->menu()->actions().count() + MRI_button_csf_choice->menu()->actions().count();

        double *xmin = new double[n_actions_plus];
        double *xmax = new double[n_actions_plus];
        double *ymin = new double[n_actions_plus];
        double *ymax = new double[n_actions_plus];

        int n_graph = 0;
        QCPScatterStyle *styles = new QCPScatterStyle[15];
        styles[0] = QCPScatterStyle::ssNone;
        styles[1] = QCPScatterStyle::ssCross;
        styles[2] = QCPScatterStyle::ssPlus;
        styles[3] = QCPScatterStyle::ssCircle;
        styles[4] = QCPScatterStyle::ssDisc;
        styles[5] = QCPScatterStyle::ssSquare;
        styles[6] = QCPScatterStyle::ssDiamond;
        styles[7] = QCPScatterStyle::ssStar;
        styles[8] = QCPScatterStyle::ssTriangle;
        styles[9] = QCPScatterStyle::ssTriangleInverted;
        styles[10] = QCPScatterStyle::ssCrossSquare;
        styles[11] = QCPScatterStyle::ssPlusSquare;
        styles[12] = QCPScatterStyle::ssCrossCircle;
        styles[13] = QCPScatterStyle::ssPlusCircle;
        styles[14] = QCPScatterStyle::ssPeace;
        for (int i = 0; i < n_actions; i++){
            if (MRI_arterial_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_arterial){
                    int n = MRI_coords_arterial_other[i]->size();

                    if (n > 0){
                        //Plot
                        QVector<double> *xy = Coord2QVector(MRI_coords_arterial_other[i]);

                        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                        //Normalize x
                        {
                            double maxx = max(xy[0]);
                            for (int i = 0; i < n; i++){
                                xy[0][i] = xy[0][i] / maxx;
                            }
                        }

                        MRI_plot_arterial_others->addGraph();
                        MRI_plot_arterial_others->graph(n_graph)->setPen(QPen(Qt::red));
                        MRI_plot_arterial_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                        MRI_plot_arterial_others->graph(n_graph)->setData(xy[0], xy[1]);
                        MRI_plot_arterial_others->graph(n_graph)->setName(MRI_arterial_menu->actions().at(i)->text());

                        xmin[n_graph] = min(xy[0]);
                        xmax[n_graph] = max(xy[0]);
                        ymin[n_graph] = min(xy[1]);
                        ymax[n_graph] = max(xy[1]);

                        delete[] xy;

                        n_graph++;
                    }
                }
                else{
                    if (i == MRI_number_arterial){
                        //venous
                        int n_actions_venous = MRI_button_venous_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_venous; j++){
                            if (MRI_venous_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_venous_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_venous_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_arterial_others->addGraph();
                                    MRI_plot_arterial_others->graph(n_graph)->setPen(QPen(Qt::blue));
                                    MRI_plot_arterial_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_arterial_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_arterial_others->graph(n_graph)->setName(MRI_venous_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                    else if (i == MRI_number_arterial+1){
                        //csf
                        int n_actions_csf = MRI_button_csf_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_csf; j++){
                            if (MRI_csf_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_csf_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_csf_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_arterial_others->addGraph();
                                    MRI_plot_arterial_others->graph(n_graph)->setPen(QPen(Qt::green));
                                    MRI_plot_arterial_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_arterial_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_arterial_others->graph(n_graph)->setName(MRI_csf_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                }
            }
        }

        delete[] styles;

        double minx = xmin[0];
        double maxx = xmax[0];
        double miny = ymin[0];
        double maxy = ymax[0];

        for (int i = 1; i < n_graph; i++){
            if (minx > xmin[i]){
                minx = xmin[i];
            }
            if (maxx < xmax[i]){
                maxx = xmax[i];
            }
            if (miny > ymin[i]){
                miny = ymin[i];
            }
            if (maxy < ymax[i]){
                maxy = ymax[i];
            }
        }

        delete[] xmin;
        delete[] xmax;
        delete[] ymin;
        delete[] ymax;

        MRI_plot_arterial_others->xAxis->setRange(minx, maxx);
        MRI_plot_arterial_others->yAxis->setRange(miny, maxy);

        MRI_plot_arterial_others->xAxis->setLabel(MRI_time_unity);
        MRI_plot_arterial_others->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_arterial_others->replot();

        //Print
        print_MRI_arterial_others();

        return true;
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_venous_others
 */
bool MainWindow::plot_MRI_venous_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_plot_venous_others->clearGraphs();

    int n_actions = MRI_button_venous_choice->menu()->actions().count();

    if (n_actions > 0){
        int n_actions_plus = n_actions + MRI_button_arterial_choice->menu()->actions().count() + MRI_button_csf_choice->menu()->actions().count();

        double *xmin = new double[n_actions_plus];
        double *xmax = new double[n_actions_plus];
        double *ymin = new double[n_actions_plus];
        double *ymax = new double[n_actions_plus];

        int n_graph = 0;
        QCPScatterStyle *styles = new QCPScatterStyle[15];
        styles[0] = QCPScatterStyle::ssNone;
        styles[1] = QCPScatterStyle::ssCross;
        styles[2] = QCPScatterStyle::ssPlus;
        styles[3] = QCPScatterStyle::ssCircle;
        styles[4] = QCPScatterStyle::ssDisc;
        styles[5] = QCPScatterStyle::ssSquare;
        styles[6] = QCPScatterStyle::ssDiamond;
        styles[7] = QCPScatterStyle::ssStar;
        styles[8] = QCPScatterStyle::ssTriangle;
        styles[9] = QCPScatterStyle::ssTriangleInverted;
        styles[10] = QCPScatterStyle::ssCrossSquare;
        styles[11] = QCPScatterStyle::ssPlusSquare;
        styles[12] = QCPScatterStyle::ssCrossCircle;
        styles[13] = QCPScatterStyle::ssPlusCircle;
        styles[14] = QCPScatterStyle::ssPeace;
        for (int i = 0; i < n_actions; i++){
            if (MRI_venous_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_venous){
                    int n = MRI_coords_venous_other[i]->size();

                    if (n > 0){
                        //Plot
                        QVector<double> *xy = Coord2QVector(MRI_coords_venous_other[i]);

                        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                        //Normalize x
                        {
                            double maxx = max(xy[0]);
                            for (int i = 0; i < n; i++){
                                xy[0][i] = xy[0][i] / maxx;
                            }
                        }

                        MRI_plot_venous_others->addGraph();
                        MRI_plot_venous_others->graph(n_graph)->setPen(QPen(Qt::blue));
                        MRI_plot_venous_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                        MRI_plot_venous_others->graph(n_graph)->setData(xy[0], xy[1]);
                        MRI_plot_venous_others->graph(n_graph)->setName(MRI_venous_menu->actions().at(i)->text());

                        xmin[n_graph] = min(xy[0]);
                        xmax[n_graph] = max(xy[0]);
                        ymin[n_graph] = min(xy[1]);
                        ymax[n_graph] = max(xy[1]);

                        delete[] xy;

                        n_graph++;
                    }
                }
                else{
                    if (i == MRI_number_venous){
                        //arterial
                        int n_actions_arterial = MRI_button_arterial_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_arterial; j++){
                            if (MRI_arterial_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_arterial_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_arterial_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_venous_others->addGraph();
                                    MRI_plot_venous_others->graph(n_graph)->setPen(QPen(Qt::red));
                                    MRI_plot_venous_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_venous_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_venous_others->graph(n_graph)->setName(MRI_arterial_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                    else if (i == MRI_number_venous+1){
                        //csf
                        int n_actions_csf = MRI_button_csf_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_csf; j++){
                            if (MRI_csf_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_csf_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_csf_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_venous_others->addGraph();
                                    MRI_plot_venous_others->graph(n_graph)->setPen(QPen(Qt::green));
                                    MRI_plot_venous_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_venous_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_venous_others->graph(n_graph)->setName(MRI_csf_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                }
            }
        }
        delete[] styles;

        double minx = xmin[0];
        double maxx = xmax[0];
        double miny = ymin[0];
        double maxy = ymax[0];

        for (int i = 1; i < n_graph; i++){
            if (minx > xmin[i]){
                minx = xmin[i];
            }
            if (maxx < xmax[i]){
                maxx = xmax[i];
            }
            if (miny > ymin[i]){
                miny = ymin[i];
            }
            if (maxy < ymax[i]){
                maxy = ymax[i];
            }
        }

        delete[] xmin;
        delete[] xmax;
        delete[] ymin;
        delete[] ymax;

        MRI_plot_venous_others->xAxis->setRange(minx, maxx);
        MRI_plot_venous_others->yAxis->setRange(miny, maxy);

        MRI_plot_venous_others->xAxis->setLabel(MRI_time_unity);
        MRI_plot_venous_others->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_venous_others->replot();

        //Print
        print_MRI_venous_others();

        return true;
    }

    return false;
}

/*!
 * \brief MainWindow::plot_MRI_csf_others
 */
bool MainWindow::plot_MRI_csf_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_plot_csf_others->clearGraphs();

    int n_actions = MRI_button_csf_choice->menu()->actions().count();

    if (n_actions > 0){
        int n_actions_plus = n_actions + MRI_button_arterial_choice->menu()->actions().count() + MRI_button_venous_choice->menu()->actions().count();

        double *xmin = new double[n_actions_plus];
        double *xmax = new double[n_actions_plus];
        double *ymin = new double[n_actions_plus];
        double *ymax = new double[n_actions_plus];

        int n_graph = 0;
        QCPScatterStyle *styles = new QCPScatterStyle[15];
        styles[0] = QCPScatterStyle::ssNone;
        styles[1] = QCPScatterStyle::ssCross;
        styles[2] = QCPScatterStyle::ssPlus;
        styles[3] = QCPScatterStyle::ssCircle;
        styles[4] = QCPScatterStyle::ssDisc;
        styles[5] = QCPScatterStyle::ssSquare;
        styles[6] = QCPScatterStyle::ssDiamond;
        styles[7] = QCPScatterStyle::ssStar;
        styles[8] = QCPScatterStyle::ssTriangle;
        styles[9] = QCPScatterStyle::ssTriangleInverted;
        styles[10] = QCPScatterStyle::ssCrossSquare;
        styles[11] = QCPScatterStyle::ssPlusSquare;
        styles[12] = QCPScatterStyle::ssCrossCircle;
        styles[13] = QCPScatterStyle::ssPlusCircle;
        styles[14] = QCPScatterStyle::ssPeace;
        for (int i = 0; i < n_actions; i++){
            if (MRI_csf_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_csf){
                    int n = MRI_coords_csf_other[i]->size();

                    if (n > 0){
                        //Plot
                        QVector<double> *xy = Coord2QVector(MRI_coords_csf_other[i]);

                        unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                        //Normalize x
                        {
                            double maxx = max(xy[0]);
                            for (int i = 0; i < n; i++){
                                xy[0][i] = xy[0][i] / maxx;
                            }
                        }

                        MRI_plot_csf_others->addGraph();
                        MRI_plot_csf_others->graph(n_graph)->setPen(QPen(Qt::green));
                        MRI_plot_csf_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                        MRI_plot_csf_others->graph(n_graph)->setData(xy[0], xy[1]);
                        MRI_plot_csf_others->graph(n_graph)->setName(MRI_csf_menu->actions().at(i)->text());

                        xmin[n_graph] = min(xy[0]);
                        xmax[n_graph] = max(xy[0]);
                        ymin[n_graph] = min(xy[1]);
                        ymax[n_graph] = max(xy[1]);

                        delete[] xy;

                        n_graph++;
                    }
                }
                else{
                    if (i == MRI_number_csf){
                        //arterial
                        int n_actions_arterial = MRI_button_arterial_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_arterial; j++){
                            if (MRI_arterial_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_arterial_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_arterial_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_csf_others->addGraph();
                                    MRI_plot_csf_others->graph(n_graph)->setPen(QPen(Qt::red));
                                    MRI_plot_csf_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_csf_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_csf_others->graph(n_graph)->setName(MRI_arterial_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                    else if (i == MRI_number_csf+1){
                        //csf
                        int n_actions_csf = MRI_button_venous_choice->menu()->actions().count()-2;

                        for (int j = 0; j < n_actions_csf; j++){
                            if (MRI_venous_menu->actions().at(j)->isChecked()){
                                int n = MRI_coords_venous_other[j]->size();

                                if (n > 0){
                                    QVector<double> *xy = Coord2QVector(MRI_coords_venous_other[j]);

                                    unity_convert_flow(xy, MRI_flow_unity, MRI_time_unity);

                                    //Normalize x
                                    {
                                        double maxx = max(xy[0]);
                                        for (int i = 0; i < n; i++){
                                            xy[0][i] = xy[0][i] / maxx;
                                        }
                                    }

                                    MRI_plot_csf_others->addGraph();
                                    MRI_plot_csf_others->graph(n_graph)->setPen(QPen(Qt::blue));
                                    MRI_plot_csf_others->graph(n_graph)->setScatterStyle(styles[n_graph%15]);
                                    MRI_plot_csf_others->graph(n_graph)->setData(xy[0], xy[1]);
                                    MRI_plot_csf_others->graph(n_graph)->setName(MRI_venous_menu->actions().at(j)->text());

                                    xmin[n_graph] = min(xy[0]);
                                    xmax[n_graph] = max(xy[0]);
                                    ymin[n_graph] = min(xy[1]);
                                    ymax[n_graph] = max(xy[1]);

                                    delete[] xy;

                                    n_graph++;
                                }
                            }
                        }
                    }
                }
            }
        }
        delete[] styles;

        double minx = xmin[0];
        double maxx = xmax[0];
        double miny = ymin[0];
        double maxy = ymax[0];

        for (int i = 1; i < n_graph; i++){
            if (minx > xmin[i]){
                minx = xmin[i];
            }
            if (maxx < xmax[i]){
                maxx = xmax[i];
            }
            if (miny > ymin[i]){
                miny = ymin[i];
            }
            if (maxy < ymax[i]){
                maxy = ymax[i];
            }
        }

        delete[] xmin;
        delete[] xmax;
        delete[] ymin;
        delete[] ymax;

        MRI_plot_csf_others->xAxis->setRange(minx, maxx);
        MRI_plot_csf_others->yAxis->setRange(miny, maxy);

        MRI_plot_csf_others->xAxis->setLabel(MRI_time_unity);
        MRI_plot_csf_others->yAxis->setLabel(MRI_flow_unity);

        MRI_plot_csf_others->replot();

        //Print
        print_MRI_csf_others();

        return true;
    }

    return false;
}
//**********//
//**********//


//***********//
//***PRINT***//
//***********//
/*!
 * \brief MainWindow::print_MRI_arterial_cervical
 */
bool MainWindow::print_MRI_arterial_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        double arterial_min = min(MRI_coord_arterial_cervical->coords(YCOORD), n);;
        double arterial_max = max(MRI_coord_arterial_cervical->coords(YCOORD), n);
        double arterial_mean = mean(*MRI_coord_arterial_cervical, YCOORD);
        double arterial_sv = stroke_volume(*MRI_coord_arterial_cervical);

        double time_max = max(MRI_coord_arterial_cervical->coords(XCOORD), n);
        double heart_rate = 0.;
        if (MRI_time_unity.compare(UNITY_S) == 0){
            heart_rate = (1. / time_max) * 60.;
        }
        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
            heart_rate = (1. / time_max);
        }

        unity_convert_flow_data(&arterial_min, &arterial_max, &arterial_mean, &arterial_sv, MRI_flow_unity, MRI_volume_unity);

        double arterial_grad = arterial_max - arterial_min;

        MRI_label_heart_rate_cervical->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate, 'f', 0) + UNITY_BPM);

        MRI_label_arterial_min_cervical->setText(MAINWINDOW_MRI_MIN_F + QString::number(arterial_min, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_max_cervical->setText(MAINWINDOW_MRI_MAX_F + QString::number(arterial_max, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_mean_cervical->setText(MAINWINDOW_MRI_MEAN_F + QString::number(arterial_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_grad_cervical->setText(MAINWINDOW_MRI_GRAD_F + QString::number(arterial_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_stroke_cervical->setText(MAINWINDOW_MRI_STROKE + QString::number(arterial_sv, 'f', 1) + MRI_volume_unity);

        return true;
    }
    else{
        status_error(MRI_ERROR_002);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_venous_cervical
 */
bool MainWindow::print_MRI_venous_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        double venous_min = min(MRI_coord_venous_cervical->coords(YCOORD), n);
        double venous_max = max(MRI_coord_venous_cervical->coords(YCOORD), n);
        double venous_mean = mean(*MRI_coord_venous_cervical, YCOORD);
        double venous_sv = stroke_volume(*MRI_coord_venous_cervical);

        unity_convert_flow_data(&venous_min, &venous_max, &venous_mean, &venous_sv, MRI_flow_unity, MRI_volume_unity);

        double venous_grad = venous_max - venous_min;

        MRI_label_venous_min_cervical->setText(MAINWINDOW_MRI_MIN_F + QString::number(venous_min, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_max_cervical->setText(MAINWINDOW_MRI_MAX_F + QString::number(venous_max, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_mean_cervical->setText(MAINWINDOW_MRI_MEAN_F + QString::number(venous_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_grad_cervical->setText(MAINWINDOW_MRI_GRAD_F + QString::number(venous_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_stroke_cervical->setText(MAINWINDOW_MRI_STROKE + QString::number(venous_sv, 'f', 1) + MRI_volume_unity);

        n = MRI_coord_venous_corr_cervical->size();
        if (n > 0){
            venous_min = min(MRI_coord_venous_corr_cervical->coords(YCOORD), n);
            venous_max = max(MRI_coord_venous_corr_cervical->coords(YCOORD), n);
            venous_mean = mean(*MRI_coord_venous_corr_cervical, YCOORD);
            venous_sv = stroke_volume(*MRI_coord_venous_corr_cervical);

            unity_convert_flow_data(&venous_min, &venous_max, &venous_mean, &venous_sv, MRI_flow_unity, MRI_volume_unity);

            venous_grad = venous_max - venous_min;

            MRI_label_venous_corr_min_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_min, 'f', 0)  + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_max_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_max, 'f', 0)  + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_mean_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_mean, 'f', 0)  + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_grad_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_grad, 'f', 0)  + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_stroke_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_sv, 'f', 1)  + MAINWINDOW_MRI_RBRACKET);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_004);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_csf_cervical
 */
bool MainWindow::print_MRI_csf_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        double csf_min = min(MRI_coord_csf_cervical->coords(YCOORD), n);
        double csf_max = max(MRI_coord_csf_cervical->coords(YCOORD), n);
        double csf_mean = mean(*MRI_coord_csf_cervical, YCOORD);
        double csf_sv = stroke_volume_csf(*MRI_coord_csf_cervical);

        double time_max = max(MRI_coord_csf_cervical->coords(XCOORD), n);
        double heart_rate = 0.;
        if (MRI_time_unity.compare(UNITY_S) == 0){
            heart_rate = (1. / time_max) * 60.;
        }
        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
            heart_rate = (1. / time_max);
        }

        unity_convert_flow_data(&csf_min, &csf_max, &csf_mean, &csf_sv, MRI_flow_unity, MRI_volume_unity);

        double csf_grad = csf_max - csf_min;

        MRI_label_csf_heart_rate_cervical->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate, 'f', 0) + UNITY_BPM);

        MRI_label_csf_min_cervical->setText(MAINWINDOW_MRI_MIN_F + QString::number(csf_min, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_max_cervical->setText(MAINWINDOW_MRI_MAX_F + QString::number(csf_max, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_mean_cervical->setText(MAINWINDOW_MRI_MEAN_F + QString::number(csf_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_grad_cervical->setText(MAINWINDOW_MRI_GRAD_F + QString::number(csf_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_stroke_cervical->setText(MAINWINDOW_MRI_STROKE + QString::number(csf_sv, 'f', 1) + MRI_volume_unity);

        n = MRI_coord_csf_corr_cervical->size();
        if (n > 0){
            csf_min = min(MRI_coord_csf_corr_cervical->coords(YCOORD), n);
            csf_max = max(MRI_coord_csf_corr_cervical->coords(YCOORD), n);
            csf_mean = mean(*MRI_coord_csf_corr_cervical, YCOORD);
            csf_sv = stroke_volume_csf(*MRI_coord_csf_corr_cervical);

            unity_convert_flow_data(&csf_min, &csf_max, &csf_mean, &csf_sv, MRI_flow_unity, MRI_volume_unity);

            csf_grad = csf_max - csf_min;

            MRI_label_csf_corr_min_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_min, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_max_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_max, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_mean_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_mean, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_grad_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_grad, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_stroke_cervical->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_sv, 'f', 1) + MAINWINDOW_MRI_RBRACKET);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_006);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_AV_cervical
 */
bool MainWindow::print_MRI_AV_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cervical->size();
    n = min(n, MRI_coord_AV_volume_cervical->size());

    if (n > 0){
        double AV_flow_min = min(MRI_coord_AV_flow_cervical->coords(YCOORD), n);
        double AV_flow_max = max(MRI_coord_AV_flow_cervical->coords(YCOORD), n);
        double AV_flow_mean = mean(*MRI_coord_AV_flow_cervical, YCOORD);
        double AV_flow_stroke = stroke_volume(*MRI_coord_AV_flow_cervical);

        unity_convert_flow_data(&AV_flow_min, &AV_flow_max, &AV_flow_mean, &AV_flow_stroke, MRI_flow_unity, MRI_volume_unity);

        double AV_flow_grad = AV_flow_max - AV_flow_min;

        MRI_label_AV_flow_min_cervical->setText(MAINWINDOW_MRI_MIN_F + QString::number(AV_flow_min, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_max_cervical->setText(MAINWINDOW_MRI_MAX_F + QString::number(AV_flow_max, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_mean_cervical->setText(MAINWINDOW_MRI_MEAN_F + QString::number(AV_flow_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_grad_cervical->setText(MAINWINDOW_MRI_GRAD_F + QString::number(AV_flow_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_stroke_cervical->setText(MAINWINDOW_MRI_STROKE + QString::number(AV_flow_stroke, 'f', 1) + MRI_volume_unity);

        double AV_volume_min = min(MRI_coord_AV_volume_cervical->coords(YCOORD), n);
        double AV_volume_max = max(MRI_coord_AV_volume_cervical->coords(YCOORD), n);
        double AV_volume_mean = mean(*MRI_coord_AV_volume_cervical, YCOORD);

        unity_convert_volume_data(&AV_volume_min, &AV_volume_max, &AV_volume_mean, MRI_volume_unity);

        double AV_volume_grad = AV_volume_max - AV_volume_min;

        MRI_label_AV_volume_min_cervical->setText(MAINWINDOW_MRI_MIN_V + QString::number(AV_volume_min, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_max_cervical->setText(MAINWINDOW_MRI_MAX_V + QString::number(AV_volume_max, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_mean_cervical->setText(MAINWINDOW_MRI_MEAN_V + QString::number(AV_volume_mean, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_grad_cervical->setText(MAINWINDOW_MRI_GRAD_V + QString::number(AV_volume_grad, 'f', 1) + MRI_volume_unity);

        if (MRI_box_AV_flow_volume_cervical->currentIndex() == 0){
            MRI_label_AV_flow_min_cervical->setHidden(false);
            MRI_label_AV_flow_max_cervical->setHidden(false);
            MRI_label_AV_flow_mean_cervical->setHidden(false);
            MRI_label_AV_flow_grad_cervical->setHidden(false);
            MRI_label_AV_flow_stroke_cervical->setHidden(false);

            MRI_label_AV_volume_min_cervical->setHidden(true);
            MRI_label_AV_volume_max_cervical->setHidden(true);
            MRI_label_AV_volume_mean_cervical->setHidden(true);
            MRI_label_AV_volume_grad_cervical->setHidden(true);
        }
        else{
            MRI_label_AV_flow_min_cervical->setHidden(true);
            MRI_label_AV_flow_max_cervical->setHidden(true);
            MRI_label_AV_flow_mean_cervical->setHidden(true);
            MRI_label_AV_flow_grad_cervical->setHidden(true);
            MRI_label_AV_flow_stroke_cervical->setHidden(true);

            MRI_label_AV_volume_min_cervical->setHidden(false);
            MRI_label_AV_volume_max_cervical->setHidden(false);
            MRI_label_AV_volume_mean_cervical->setHidden(false);
            MRI_label_AV_volume_grad_cervical->setHidden(false);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_008);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_ICVC_cervical
 */
bool MainWindow::print_MRI_ICVC_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cervical->size();
    n = min(n, MRI_coord_ICVC_volume_cervical->size());

    if (n > 0){
        double ICVC_flow_min = min(MRI_coord_ICVC_flow_cervical->coords(YCOORD), n);
        double ICVC_flow_max = max(MRI_coord_ICVC_flow_cervical->coords(YCOORD), n);
        double ICVC_flow_mean = mean(*MRI_coord_ICVC_flow_cervical, YCOORD);
        double ICVC_flow_stroke = stroke_volume(*MRI_coord_ICVC_flow_cervical);

        unity_convert_flow_data(&ICVC_flow_min, &ICVC_flow_max, &ICVC_flow_mean, &ICVC_flow_stroke, MRI_flow_unity, MRI_volume_unity);

        double ICVC_flow_grad = ICVC_flow_max - ICVC_flow_min;

        MRI_label_ICVC_flow_min_cervical->setText(MAINWINDOW_MRI_MIN_F + QString::number(ICVC_flow_min, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_max_cervical->setText(MAINWINDOW_MRI_MAX_F + QString::number(ICVC_flow_max, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_mean_cervical->setText(MAINWINDOW_MRI_MEAN_F + QString::number(ICVC_flow_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_grad_cervical->setText(MAINWINDOW_MRI_GRAD_F + QString::number(ICVC_flow_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_stroke_cervical->setText(MAINWINDOW_MRI_STROKE + QString::number(ICVC_flow_stroke, 'f', 1) + MRI_volume_unity);

        double ICVC_volume_min = min(MRI_coord_ICVC_volume_cervical->coords(YCOORD), n);
        double ICVC_volume_max = max(MRI_coord_ICVC_volume_cervical->coords(YCOORD), n);
        double ICVC_volume_mean = mean(*MRI_coord_ICVC_volume_cervical, YCOORD);

        unity_convert_volume_data(&ICVC_volume_min, &ICVC_volume_max, &ICVC_volume_mean, MRI_volume_unity);

        double ICVC_volume_grad = ICVC_volume_max - ICVC_volume_min;

        MRI_label_ICVC_volume_min_cervical->setText(MAINWINDOW_MRI_MIN_V + QString::number(ICVC_volume_min, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_max_cervical->setText(MAINWINDOW_MRI_MAX_V + QString::number(ICVC_volume_max, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_mean_cervical->setText(MAINWINDOW_MRI_MEAN_V + QString::number(ICVC_volume_mean, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_grad_cervical->setText(MAINWINDOW_MRI_GRAD_V + QString::number(ICVC_volume_grad, 'f', 1) + MRI_volume_unity);

        if (MRI_box_ICVC_flow_volume_cervical->currentIndex() == 0){
            MRI_label_ICVC_flow_min_cervical->setHidden(false);
            MRI_label_ICVC_flow_max_cervical->setHidden(false);
            MRI_label_ICVC_flow_mean_cervical->setHidden(false);
            MRI_label_ICVC_flow_grad_cervical->setHidden(false);
            MRI_label_ICVC_flow_stroke_cervical->setHidden(false);

            MRI_label_ICVC_volume_min_cervical->setHidden(true);
            MRI_label_ICVC_volume_max_cervical->setHidden(true);
            MRI_label_ICVC_volume_mean_cervical->setHidden(true);
            MRI_label_ICVC_volume_grad_cervical->setHidden(true);
        }
        else{
            MRI_label_ICVC_flow_min_cervical->setHidden(true);
            MRI_label_ICVC_flow_max_cervical->setHidden(true);
            MRI_label_ICVC_flow_mean_cervical->setHidden(true);
            MRI_label_ICVC_flow_grad_cervical->setHidden(true);
            MRI_label_ICVC_flow_stroke_cervical->setHidden(true);

            MRI_label_ICVC_volume_min_cervical->setHidden(false);
            MRI_label_ICVC_volume_max_cervical->setHidden(false);
            MRI_label_ICVC_volume_mean_cervical->setHidden(false);
            MRI_label_ICVC_volume_grad_cervical->setHidden(false);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_009);
    }

    return false;
}

//

/*!
 * \brief MainWindow::print_MRI_arterial_cerebral
 */
bool MainWindow::print_MRI_arterial_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        double arterial_min = min(MRI_coord_arterial_cerebral->coords(YCOORD), n);;
        double arterial_max = max(MRI_coord_arterial_cerebral->coords(YCOORD), n);
        double arterial_mean = mean(*MRI_coord_arterial_cerebral, YCOORD);
        double arterial_sv = stroke_volume(*MRI_coord_arterial_cerebral);

        double time_max = max(MRI_coord_arterial_cerebral->coords(XCOORD), n);
        double heart_rate = 0.;
        if (MRI_time_unity.compare(UNITY_S) == 0){
            heart_rate = (1. / time_max) * 60.;
        }
        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
            heart_rate = (1. / time_max);
        }

        unity_convert_flow_data(&arterial_min, &arterial_max, &arterial_mean, &arterial_sv, MRI_flow_unity, MRI_volume_unity);

        double arterial_grad = arterial_max - arterial_min;

        MRI_label_heart_rate_cerebral->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate, 'f', 0) + UNITY_BPM);

        MRI_label_arterial_min_cerebral->setText(MAINWINDOW_MRI_MIN_F + QString::number(arterial_min, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_max_cerebral->setText(MAINWINDOW_MRI_MAX_F + QString::number(arterial_max, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_F + QString::number(arterial_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_F + QString::number(arterial_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_arterial_stroke_cerebral->setText(MAINWINDOW_MRI_STROKE + QString::number(arterial_sv, 'f', 1) + MRI_volume_unity);

        return true;
    }
    else{
        status_error(MRI_ERROR_011);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_venous_cerebral
 */
bool MainWindow::print_MRI_venous_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        double venous_min = min(MRI_coord_venous_cerebral->coords(YCOORD), n);
        double venous_max = max(MRI_coord_venous_cerebral->coords(YCOORD), n);
        double venous_mean = mean(*MRI_coord_venous_cerebral, YCOORD);
        double venous_sv = stroke_volume(*MRI_coord_venous_cerebral);

        unity_convert_flow_data(&venous_min, &venous_max, &venous_mean, &venous_sv, MRI_flow_unity, MRI_volume_unity);

        double venous_grad = venous_max - venous_min;

        MRI_label_venous_min_cerebral->setText(MAINWINDOW_MRI_MIN_F + QString::number(venous_min, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_max_cerebral->setText(MAINWINDOW_MRI_MAX_F + QString::number(venous_max, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_F + QString::number(venous_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_F + QString::number(venous_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_venous_stroke_cerebral->setText(MAINWINDOW_MRI_STROKE + QString::number(venous_sv, 'f', 1) + MRI_volume_unity);

        n = MRI_coord_venous_corr_cerebral->size();
        if (n > 0){
            venous_min = min(MRI_coord_venous_corr_cerebral->coords(YCOORD), n);
            venous_max = max(MRI_coord_venous_corr_cerebral->coords(YCOORD), n);
            venous_mean = mean(*MRI_coord_venous_corr_cerebral, YCOORD);
            venous_sv = stroke_volume(*MRI_coord_venous_corr_cerebral);

            unity_convert_flow_data(&venous_min, &venous_max, &venous_mean, &venous_sv, MRI_flow_unity, MRI_volume_unity);

            venous_grad = venous_max - venous_min;

            MRI_label_venous_corr_min_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_min, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_max_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_max, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_mean_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_mean, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_grad_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_grad, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_venous_corr_stroke_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(venous_sv, 'f', 1) + MAINWINDOW_MRI_RBRACKET);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_013);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_csf_cerebral
 */
bool MainWindow::print_MRI_csf_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        double csf_min = min(MRI_coord_csf_cerebral->coords(YCOORD), n);
        double csf_max = max(MRI_coord_csf_cerebral->coords(YCOORD), n);
        double csf_mean = mean(*MRI_coord_csf_cerebral, YCOORD);
        double csf_sv = stroke_volume_csf(*MRI_coord_csf_cerebral);

        double time_max = max(MRI_coord_csf_cerebral->coords(XCOORD), n);
        double heart_rate = 0.;
        if (MRI_time_unity.compare(UNITY_S) == 0){
            heart_rate = (1. / time_max) * 60.;
        }
        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
            heart_rate = (1. / time_max);
        }

        unity_convert_flow_data(&csf_min, &csf_max, &csf_mean, &csf_sv, MRI_flow_unity, MRI_volume_unity);

        double csf_grad = csf_max - csf_min;

        MRI_label_csf_heart_rate_cerebral->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate, 'f', 0) + UNITY_BPM);

        MRI_label_csf_min_cerebral->setText(MAINWINDOW_MRI_MIN_F + QString::number(csf_min, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_max_cerebral->setText(MAINWINDOW_MRI_MAX_F + QString::number(csf_max, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_F + QString::number(csf_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_F + QString::number(csf_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_csf_stroke_cerebral->setText(MAINWINDOW_MRI_STROKE + QString::number(csf_sv, 'f', 1) + MRI_volume_unity);

        n = MRI_coord_csf_corr_cerebral->size();
        if (n > 0){
            double csf_min = min(MRI_coord_csf_corr_cerebral->coords(YCOORD), n);
            double csf_max = max(MRI_coord_csf_corr_cerebral->coords(YCOORD), n);
            double csf_mean = mean(*MRI_coord_csf_corr_cerebral, YCOORD);
            double csf_sv = stroke_volume_csf(*MRI_coord_csf_corr_cerebral);

            unity_convert_flow_data(&csf_min, &csf_max, &csf_mean, &csf_sv, MRI_flow_unity, MRI_volume_unity);

            double csf_grad = csf_max - csf_min;

            MRI_label_csf_corr_min_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_min, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_max_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_max, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_mean_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_mean, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_grad_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_grad, 'f', 0) + MAINWINDOW_MRI_RBRACKET);
            MRI_label_csf_corr_stroke_cerebral->setText(MAINWINDOW_MRI_LBRACKET + QString::number(csf_sv, 'f', 1) + MAINWINDOW_MRI_RBRACKET);
        }
        return true;
    }
    else{
        status_error(MRI_ERROR_015);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_AV_cerebral
 */
bool MainWindow::print_MRI_AV_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cerebral->size();
    n = min(n, MRI_coord_AV_volume_cerebral->size());

    if (n > 0){
        double AV_flow_min = min(MRI_coord_AV_flow_cerebral->coords(YCOORD), n);
        double AV_flow_max = max(MRI_coord_AV_flow_cerebral->coords(YCOORD), n);
        double AV_flow_mean = mean(*MRI_coord_AV_flow_cerebral, YCOORD);
        double AV_flow_stroke = stroke_volume(*MRI_coord_AV_flow_cerebral);

        unity_convert_flow_data(&AV_flow_min, &AV_flow_max, &AV_flow_mean, &AV_flow_stroke, MRI_flow_unity, MRI_volume_unity);

        double AV_flow_grad = AV_flow_max - AV_flow_min;

        MRI_label_AV_flow_min_cerebral->setText(MAINWINDOW_MRI_MIN_F + QString::number(AV_flow_min, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_max_cerebral->setText(MAINWINDOW_MRI_MAX_F + QString::number(AV_flow_max, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_F + QString::number(AV_flow_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_F + QString::number(AV_flow_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_AV_flow_stroke_cerebral->setText(MAINWINDOW_MRI_STROKE + QString::number(AV_flow_stroke, 'f', 1) + MRI_volume_unity);

        double AV_volume_min = min(MRI_coord_AV_volume_cerebral->coords(YCOORD), n);
        double AV_volume_max = max(MRI_coord_AV_volume_cerebral->coords(YCOORD), n);
        double AV_volume_mean = mean(*MRI_coord_AV_volume_cerebral, YCOORD);

        unity_convert_volume_data(&AV_volume_min, &AV_volume_max, &AV_volume_mean, MRI_volume_unity);

        double AV_volume_grad = AV_volume_max - AV_volume_min;

        MRI_label_AV_volume_min_cerebral->setText(MAINWINDOW_MRI_MIN_V + QString::number(AV_volume_min, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_max_cerebral->setText(MAINWINDOW_MRI_MAX_V + QString::number(AV_volume_max, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_V + QString::number(AV_volume_mean, 'f', 1) + MRI_volume_unity);
        MRI_label_AV_volume_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_V + QString::number(AV_volume_grad, 'f', 1) + MRI_volume_unity);
        if (MRI_box_AV_flow_volume_cerebral->currentIndex() == 0){
            MRI_label_AV_flow_min_cerebral->setHidden(false);
            MRI_label_AV_flow_max_cerebral->setHidden(false);
            MRI_label_AV_flow_mean_cerebral->setHidden(false);
            MRI_label_AV_flow_grad_cerebral->setHidden(false);
            MRI_label_AV_flow_stroke_cerebral->setHidden(false);

            MRI_label_AV_volume_min_cerebral->setHidden(true);
            MRI_label_AV_volume_max_cerebral->setHidden(true);
            MRI_label_AV_volume_mean_cerebral->setHidden(true);
            MRI_label_AV_volume_grad_cerebral->setHidden(true);
        }
        else{
            MRI_label_AV_flow_min_cerebral->setHidden(true);
            MRI_label_AV_flow_max_cerebral->setHidden(true);
            MRI_label_AV_flow_mean_cerebral->setHidden(true);
            MRI_label_AV_flow_grad_cerebral->setHidden(true);
            MRI_label_AV_flow_stroke_cerebral->setHidden(true);

            MRI_label_AV_volume_min_cerebral->setHidden(false);
            MRI_label_AV_volume_max_cerebral->setHidden(false);
            MRI_label_AV_volume_mean_cerebral->setHidden(false);
            MRI_label_AV_volume_grad_cerebral->setHidden(false);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_017);
    }

    return false;
}

/*!
 * \brief MainWindow::print_MRI_ICVC_cerebral
 */
bool MainWindow::print_MRI_ICVC_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cerebral->size();
    n = min(n, MRI_coord_ICVC_volume_cerebral->size());

    if (n > 0){
        double ICVC_flow_min = min(MRI_coord_ICVC_flow_cerebral->coords(YCOORD), n);
        double ICVC_flow_max = max(MRI_coord_ICVC_flow_cerebral->coords(YCOORD), n);
        double ICVC_flow_mean = mean(*MRI_coord_ICVC_flow_cerebral, YCOORD);
        double ICVC_flow_stroke = stroke_volume(*MRI_coord_ICVC_flow_cerebral);

        unity_convert_flow_data(&ICVC_flow_min, &ICVC_flow_max, &ICVC_flow_mean, &ICVC_flow_stroke, MRI_flow_unity, MRI_volume_unity);

        double ICVC_flow_grad = ICVC_flow_max - ICVC_flow_min;

        MRI_label_ICVC_flow_min_cerebral->setText(MAINWINDOW_MRI_MIN_F + QString::number(ICVC_flow_min, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_max_cerebral->setText(MAINWINDOW_MRI_MAX_F + QString::number(ICVC_flow_max, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_F + QString::number(ICVC_flow_mean, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_F + QString::number(ICVC_flow_grad, 'f', 0) + MRI_flow_unity);
        MRI_label_ICVC_flow_stroke_cerebral->setText(MAINWINDOW_MRI_STROKE + QString::number(ICVC_flow_stroke, 'f', 1) + MRI_volume_unity);

        double ICVC_volume_min = min(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), n);
        double ICVC_volume_max = max(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), n);
        double ICVC_volume_mean = mean(*MRI_coord_ICVC_volume_cerebral, YCOORD);

        unity_convert_volume_data(&ICVC_volume_min, &ICVC_volume_max, &ICVC_volume_mean, MRI_volume_unity);

        double ICVC_volume_grad = ICVC_volume_max - ICVC_volume_min;

        MRI_label_ICVC_volume_min_cerebral->setText(MAINWINDOW_MRI_MIN_V + QString::number(ICVC_volume_min, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_max_cerebral->setText(MAINWINDOW_MRI_MAX_V + QString::number(ICVC_volume_max, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_mean_cerebral->setText(MAINWINDOW_MRI_MEAN_V + QString::number(ICVC_volume_mean, 'f', 1) + MRI_volume_unity);
        MRI_label_ICVC_volume_grad_cerebral->setText(MAINWINDOW_MRI_GRAD_V + QString::number(ICVC_volume_grad, 'f', 1) + MRI_volume_unity);

        if (MRI_box_ICVC_flow_volume_cerebral->currentIndex() == 0){
            MRI_label_ICVC_flow_min_cerebral->setHidden(false);
            MRI_label_ICVC_flow_max_cerebral->setHidden(false);
            MRI_label_ICVC_flow_mean_cerebral->setHidden(false);
            MRI_label_ICVC_flow_grad_cerebral->setHidden(false);
            MRI_label_ICVC_flow_stroke_cerebral->setHidden(false);

            MRI_label_ICVC_volume_min_cerebral->setHidden(true);
            MRI_label_ICVC_volume_max_cerebral->setHidden(true);
            MRI_label_ICVC_volume_mean_cerebral->setHidden(true);
            MRI_label_ICVC_volume_grad_cerebral->setHidden(true);
        }
        else{
            MRI_label_ICVC_flow_min_cerebral->setHidden(true);
            MRI_label_ICVC_flow_max_cerebral->setHidden(true);
            MRI_label_ICVC_flow_mean_cerebral->setHidden(true);
            MRI_label_ICVC_flow_grad_cerebral->setHidden(true);
            MRI_label_ICVC_flow_stroke_cerebral->setHidden(true);

            MRI_label_ICVC_volume_min_cerebral->setHidden(false);
            MRI_label_ICVC_volume_max_cerebral->setHidden(false);
            MRI_label_ICVC_volume_mean_cerebral->setHidden(false);
            MRI_label_ICVC_volume_grad_cerebral->setHidden(false);
        }

        return true;
    }
    else{
        status_error(MRI_ERROR_018);
    }

    return false;
}

//


/*!
 * \brief MainWindow::print_MRI_arterial_others
 */
bool MainWindow::print_MRI_arterial_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_button_arterial_choice->menu()->actions().count();

    if (n_actions > 0){
        double *arterial_min = new double[n_actions];
        double *arterial_max = new double[n_actions];
        double *arterial_mean = new double[n_actions];
        double *arterial_sv = new double[n_actions];
        double *arterial_grad = new double[n_actions];
        double *heart_rate = new double[n_actions];

        int n_graph = 0;
        for (int i = 0; i < n_actions; i++){
            if (MRI_arterial_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_arterial){
                    int n = MRI_coords_arterial_other[i]->size();

                    if (n > 0){
                        arterial_min[n_graph] = min(MRI_coords_arterial_other[i]->coords(YCOORD), n);
                        arterial_max[n_graph] = max(MRI_coords_arterial_other[i]->coords(YCOORD), n);
                        arterial_mean[n_graph] = mean(*MRI_coords_arterial_other[i], YCOORD);
                        arterial_sv[n_graph] = stroke_volume(*MRI_coords_arterial_other[i]);

                        unity_convert_flow_data(&arterial_min[n_graph], &arterial_max[n_graph], &arterial_mean[n_graph], &arterial_sv[n_graph], MRI_flow_unity, MRI_volume_unity);

                        arterial_grad[n_graph] = arterial_max[n_graph] - arterial_min[n_graph];

                        double time_max = max(MRI_coords_arterial_other[i]->coords(XCOORD), n);
                        heart_rate[n_graph] = 0.;
                        if (MRI_time_unity.compare(UNITY_S) == 0){
                            heart_rate[n_graph] = (1. / time_max) * 60.;
                        }
                        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
                            heart_rate[n_graph] = (1. / time_max);
                        }

                        n_graph++;
                    }
                }
            }
        }

        if (n_graph == 0){
            MRI_label_heart_rate_others->setText("");
            MRI_label_arterial_min_others->setText("");
            MRI_label_arterial_max_others->setText("");
            MRI_label_arterial_mean_others->setText("");
            MRI_label_arterial_grad_others->setText("");
            MRI_label_arterial_stroke_others->setText("");
        }
        else if (n_graph == 1){
            MRI_label_heart_rate_others->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate[0], 'f', 0) + UNITY_BPM);
            MRI_label_arterial_min_others->setText(MAINWINDOW_MRI_MIN_F + QString::number(arterial_min[0], 'f', 0) + MRI_flow_unity);
            MRI_label_arterial_max_others->setText(MAINWINDOW_MRI_MAX_F + QString::number(arterial_max[0], 'f', 0) + MRI_flow_unity);
            MRI_label_arterial_mean_others->setText(MAINWINDOW_MRI_MEAN_F + QString::number(arterial_mean[0], 'f', 0) + MRI_flow_unity);
            MRI_label_arterial_grad_others->setText(MAINWINDOW_MRI_GRAD_F + QString::number(arterial_grad[0], 'f', 0) + MRI_flow_unity);
            MRI_label_arterial_stroke_others->setText(MAINWINDOW_MRI_STROKE + QString::number(arterial_sv[0], 'f', 1) + MRI_volume_unity);
        }
        else{
            MRI_label_heart_rate_others->setText("No data (multi-selection)");
            MRI_label_arterial_min_others->setText("");
            MRI_label_arterial_max_others->setText("");
            MRI_label_arterial_mean_others->setText("");
            MRI_label_arterial_grad_others->setText("");
            MRI_label_arterial_stroke_others->setText("");
        }

        delete[] arterial_min;
        delete[] arterial_max;
        delete[] arterial_mean;
        delete[] arterial_sv;
        delete[] arterial_grad;
        delete[] heart_rate;

        return true;
    }
    return false;
}

/*!
 * \brief MainWindow::print_MRI_venous_others
 */
bool MainWindow::print_MRI_venous_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_button_venous_choice->menu()->actions().count();

    if (n_actions > 0){
        double *venous_min = new double[n_actions];
        double *venous_max = new double[n_actions];
        double *venous_mean = new double[n_actions];
        double *venous_sv = new double[n_actions];
        double *venous_grad = new double[n_actions];

        int n_graph = 0;
        for (int i = 0; i < n_actions; i++){
            if (MRI_venous_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_venous){
                    int n = MRI_coords_venous_other[i]->size();

                    if (n > 0){
                        venous_min[n_graph] = min(MRI_coords_venous_other[i]->coords(YCOORD), n);
                        venous_max[n_graph] = max(MRI_coords_venous_other[i]->coords(YCOORD), n);
                        venous_mean[n_graph] = mean(*MRI_coords_venous_other[i], YCOORD);
                        venous_sv[n_graph] = stroke_volume(*MRI_coords_venous_other[i]);

                        unity_convert_flow_data(&venous_min[n_graph], &venous_max[n_graph], &venous_mean[n_graph], &venous_sv[n_graph], MRI_flow_unity, MRI_volume_unity);

                        venous_grad[n_graph] = venous_max[n_graph] - venous_min[n_graph];

                        n_graph++;
                    }
                }
            }
        }

        if (n_graph == 0){
            MRI_label_venous_min_others->setText("");
            MRI_label_venous_max_others->setText("");
            MRI_label_venous_mean_others->setText("");
            MRI_label_venous_grad_others->setText("");
            MRI_label_venous_stroke_others->setText("");
        }
        else if (n_graph == 1){
            MRI_label_venous_min_others->setText(MAINWINDOW_MRI_MIN_F + QString::number(venous_min[0], 'f', 0) + MRI_flow_unity);
            MRI_label_venous_max_others->setText(MAINWINDOW_MRI_MAX_F + QString::number(venous_max[0], 'f', 0) + MRI_flow_unity);
            MRI_label_venous_mean_others->setText(MAINWINDOW_MRI_MEAN_F + QString::number(venous_mean[0], 'f', 0) + MRI_flow_unity);
            MRI_label_venous_grad_others->setText(MAINWINDOW_MRI_GRAD_F + QString::number(venous_grad[0], 'f', 0) + MRI_flow_unity);
            MRI_label_venous_stroke_others->setText(MAINWINDOW_MRI_STROKE + QString::number(venous_sv[0], 'f', 1) + MRI_volume_unity);
        }
        else{
            MRI_label_venous_min_others->setText("No data (multi-selection)");
            MRI_label_venous_max_others->setText("");
            MRI_label_venous_mean_others->setText("");
            MRI_label_venous_grad_others->setText("");
            MRI_label_venous_stroke_others->setText("");
        }

        delete[] venous_min;
        delete[] venous_max;
        delete[] venous_mean;
        delete[] venous_sv;
        delete[] venous_grad;

        return true;
    }
    return false;
}

/*!
 * \brief MainWindow::print_MRI_csf_others
 */
bool MainWindow::print_MRI_csf_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_button_csf_choice->menu()->actions().count();

    if (n_actions > 0){
        double *csf_min = new double[n_actions];
        double *csf_max = new double[n_actions];
        double *csf_mean = new double[n_actions];
        double *csf_sv = new double[n_actions];
        double *csf_grad = new double[n_actions];
        double *heart_rate = new double[n_actions];

        int n_graph = 0;
        for (int i = 0; i < n_actions; i++){
            if (MRI_csf_menu->actions().at(i)->isChecked()){
                if (i < MRI_number_csf){
                    int n = MRI_coords_csf_other[i]->size();

                    if (n > 0){
                        csf_min[n_graph] = min(MRI_coords_csf_other[i]->coords(YCOORD), n);
                        csf_max[n_graph] = max(MRI_coords_csf_other[i]->coords(YCOORD), n);
                        csf_mean[n_graph] = mean(*MRI_coords_csf_other[i], YCOORD);
                        csf_sv[n_graph] = stroke_volume_csf(*MRI_coords_csf_other[i]);

                        unity_convert_flow_data(&csf_min[n_graph], &csf_max[n_graph], &csf_mean[n_graph], &csf_sv[n_graph], MRI_flow_unity, MRI_volume_unity);

                        csf_grad[n_graph] = csf_max[n_graph] - csf_min[n_graph];

                        double time_max = max(MRI_coords_csf_other[i]->coords(XCOORD), n);
                        heart_rate[n_graph] = 0.;
                        if (MRI_time_unity.compare(UNITY_S) == 0){
                            heart_rate[n_graph] = (1. / time_max) * 60.;
                        }
                        else if (MRI_time_unity.compare(UNITY_MIN) == 0){
                            heart_rate[n_graph] = (1. / time_max);
                        }

                        n_graph++;
                    }
                }
            }
        }

        if (n_graph == 0){
            MRI_label_csf_heart_rate_others->setText("");
            MRI_label_csf_min_others->setText("");
            MRI_label_csf_max_others->setText("");
            MRI_label_csf_mean_others->setText("");
            MRI_label_csf_grad_others->setText("");
            MRI_label_csf_stroke_others->setText("");
        }
        else if (n_graph == 1){
            MRI_label_csf_heart_rate_others->setText(MAINWINDOW_MRI_HR + QString::number(heart_rate[0], 'f', 0) + UNITY_BPM);
            MRI_label_csf_min_others->setText(MAINWINDOW_MRI_MIN_F + QString::number(csf_min[0], 'f', 0) + MRI_flow_unity);
            MRI_label_csf_max_others->setText(MAINWINDOW_MRI_MAX_F + QString::number(csf_max[0], 'f', 0) + MRI_flow_unity);
            MRI_label_csf_mean_others->setText(MAINWINDOW_MRI_MEAN_F + QString::number(csf_mean[0], 'f', 0) + MRI_flow_unity);
            MRI_label_csf_grad_others->setText(MAINWINDOW_MRI_GRAD_F + QString::number(csf_grad[0], 'f', 0) + MRI_flow_unity);
            MRI_label_csf_stroke_others->setText(MAINWINDOW_MRI_STROKE + QString::number(csf_sv[0], 'f', 2) + MRI_volume_unity);
        }
        else{
            MRI_label_csf_heart_rate_others->setText("No data (multi-selection)");
            MRI_label_csf_min_others->setText("");
            MRI_label_csf_max_others->setText("");
            MRI_label_csf_mean_others->setText("");
            MRI_label_csf_grad_others->setText("");
            MRI_label_csf_stroke_others->setText("");
        }

        delete[] csf_min;
        delete[] csf_max;
        delete[] csf_mean;
        delete[] csf_sv;
        delete[] csf_grad;
        delete[] heart_rate;

        return true;
    }
    return false;
}
//***********//
//***********//


//*************//
//***BUTTONS***//
//*************//
/*!
 * \brief MainWindow::do_MRI_quality_cervical
 */
void MainWindow::do_MRI_quality_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){
        DialogQuality *dialog = new DialogQuality(current_dir, DIALOG_QUALITY_PARAM1, NULL, NULL, this);
        int res = dialog->exec();
        if (res == QDialog::Accepted){
            MRI_quality_arterial_cervical = get_MRI_arterial_cervical_quality_source(current_dir).toInt();
            MRI_quality_venous_cervical = get_MRI_venous_cervical_quality_source(current_dir).toInt();
            MRI_quality_csf_cervical = get_MRI_csf_cervical_quality_source(current_dir).toInt();
        }
        delete dialog;
    }
}

/*!
 * \brief MainWindow::do_MRI_plot_00_cervical
 */
void MainWindow::do_MRI_plot_00_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_plot_00_cervical++;
    MRI_plot_00_cervical = MRI_plot_00_cervical%2;

    plot_MRI_cervical();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cervical_1
 */
void MainWindow::do_MRI_choice_ncycles_cervical_1(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cervical = 1;

    MRI_menu_ncycles_cervical->actions().at(1)->setChecked(false);
    MRI_menu_ncycles_cervical->actions().at(2)->setChecked(false);

    plot_MRI_cervical();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cervical_2
 */
void MainWindow::do_MRI_choice_ncycles_cervical_2(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cervical = 2;

    MRI_menu_ncycles_cervical->actions().at(0)->setChecked(false);
    MRI_menu_ncycles_cervical->actions().at(2)->setChecked(false);

    plot_MRI_cervical();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cervical_3
 */
void MainWindow::do_MRI_choice_ncycles_cervical_3(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cervical = 3;

    MRI_menu_ncycles_cervical->actions().at(0)->setChecked(false);
    MRI_menu_ncycles_cervical->actions().at(1)->setChecked(false);

    plot_MRI_cervical();
}

/*!
 * \brief MainWindow::do_MRI_systole_detect_cervical
 */
void MainWindow::do_MRI_systole_detect_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        //Detect
        MRI_coord_systole_cervical = detect_systole(*MRI_coord_arterial_cervical, MRI_box_systole_delay_cervical->value(), MRI_box_systole_threshold_cervical->value());

        n = MRI_coord_systole_cervical->size();

        if (n > 0){
            //Plot
            plot_MRI_systole_cervical();
        }
        else{
            status_error(MRI_ERROR_003);
        }
    }
    else{
        status_error(MRI_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_MRI_systole_adjust_cervical
 */
void MainWindow::do_MRI_systole_adjust_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_systole_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cervical);
        double min_arterial = min(xy[1]);

        delete[] xy;

        int pos = 0, pos2 = 0;
        for (int i = 0; i < MRI_coord_systole_cervical->size(); i++){
            if (MRI_coord_systole_cervical->coord(i, XCOORD) > min_arterial){
                pos = i;
                break;
            }
        }
        for (int i = 0; i < MRI_coord_arterial_cervical->size(); i++){
            if (MRI_coord_arterial_cervical->coord(i, XCOORD) > MRI_coord_systole_cervical->coord(pos, XCOORD)){
                pos2 = i;
                break;
            }
        }
        for (int i = 0; i < pos2; i++){
            bool modified = false;
            if (MRI_check_move_cerebral->isChecked()){
                MRI_check_move_cerebral->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_left_cervical();
            if (modified){
                MRI_check_move_cerebral->setChecked(true);
            }
        }

        do_MRI_systole_detect_cervical();
    }
    else{
        status_error(MRI_ERROR_003);
    }
}

void MainWindow::do_MRI_systole_show_cervical(){
    MRI_plot_arterial_cervical->graph(1)->clearData();
    MRI_plot_arterial_cervical->replot();
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_right_cervical
 */
void MainWindow::do_MRI_move_arterial_right_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        double end = MRI_coord_arterial_cervical->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_arterial_cervical->set_coord(MRI_coord_arterial_cervical->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_arterial_cervical->set_coord(end, 0, YCOORD);

        int pos = MRI_box_arterial_move_cervical->value();
        pos++;
        pos = pos % npi;
        MRI_box_arterial_move_cervical->setValue(pos);

        plot_MRI_arterial_cervical();

        if (MRI_check_move_cervical->isChecked()){
            do_MRI_move_venous_right_cervical();
            do_MRI_move_csf_right_cervical();

            bool modified = false;
            if (MRI_check_move_cerebral->isChecked()){
                MRI_check_move_cerebral->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_right_cerebral();
            do_MRI_move_venous_right_cerebral();
            do_MRI_move_csf_right_cerebral();
            if (modified){
                MRI_check_move_cerebral->setChecked(true);
            }
        }

        if (MRI_coord_systole_cervical->size() > 0){
            do_MRI_systole_detect_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_left_cervical
 */
void MainWindow::do_MRI_move_arterial_left_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        double begin = MRI_coord_arterial_cervical->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_arterial_cervical->set_coord(MRI_coord_arterial_cervical->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_arterial_cervical->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_arterial_move_cervical->value();
        pos--;
        pos = pos % npi;
        MRI_box_arterial_move_cervical->setValue(pos);

        plot_MRI_arterial_cervical();

        if (MRI_check_move_cervical->isChecked()){
            do_MRI_move_venous_left_cervical();
            do_MRI_move_csf_left_cervical();

            bool modified = false;
            if (MRI_check_move_cerebral->isChecked()){
                MRI_check_move_cerebral->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_left_cerebral();
            do_MRI_move_venous_left_cerebral();
            do_MRI_move_csf_left_cerebral();
            if (modified){
                MRI_check_move_cerebral->setChecked(true);
            }
        }

        if (MRI_coord_systole_cervical->size() > 0){
            do_MRI_systole_detect_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_venous_right_cervical
 */
void MainWindow::do_MRI_move_venous_right_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        double end = MRI_coord_venous_cervical->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_venous_cervical->set_coord(MRI_coord_venous_cervical->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_venous_cervical->set_coord(end, 0, YCOORD);

        int pos = MRI_box_venous_move_cervical->value();
        pos++;
        pos = pos % npi;
        MRI_box_venous_move_cervical->setValue(pos);

        plot_MRI_venous_cervical();

        if (MRI_coord_venous_corr_cervical->size() > 0){
            do_MRI_venous_corr_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_004);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_venous_left_cervical
 */
void MainWindow::do_MRI_move_venous_left_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        double begin = MRI_coord_venous_cervical->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_venous_cervical->set_coord(MRI_coord_venous_cervical->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_venous_cervical->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_venous_move_cervical->value();
        pos--;
        pos = pos % npi;
        MRI_box_venous_move_cervical->setValue(pos);

        plot_MRI_venous_cervical();

        if (MRI_coord_venous_corr_cervical->size() > 0){
            do_MRI_venous_corr_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_004);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_csf_right_cervical
 */
void MainWindow::do_MRI_move_csf_right_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        double end = MRI_coord_csf_cervical->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_csf_cervical->set_coord(MRI_coord_csf_cervical->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_csf_cervical->set_coord(end, 0, YCOORD);

        int pos = MRI_box_csf_move_cervical->value();
        pos++;
        pos = pos % npi;
        MRI_box_csf_move_cervical->setValue(pos);

        plot_MRI_csf_cervical();

        if (MRI_coord_csf_corr_cervical->size() > 0){
            do_MRI_csf_corr_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_006);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_csf_left_cervical
 */
void MainWindow::do_MRI_move_csf_left_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        double begin = MRI_coord_csf_cervical->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_csf_cervical->set_coord(MRI_coord_csf_cervical->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_csf_cervical->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_csf_move_cervical->value();
        pos--;
        pos = pos % npi;
        MRI_box_csf_move_cervical->setValue(pos);

        plot_MRI_csf_cervical();

        if (MRI_coord_csf_corr_cervical->size() > 0){
            do_MRI_csf_corr_cervical();
        }
    }
    else{
        status_error(MRI_ERROR_006);
    }
}

/*!
 * \brief MainWindow::do_MRI_arterial_restore_cervical
 */
void MainWindow::do_MRI_arterial_restore_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_arterial_cervical->clear();
            MRI_coord_arterial_cervical->set_size(npi);
            MRI_coord_arterial_cervical->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_arterial_move_cervical->setValue(0);
            plot_MRI_arterial_cervical();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_arterial_smooth_cervical
 */
void MainWindow::do_MRI_arterial_smooth_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        MRI_coord_arterial_cervical = smooth(*MRI_coord_arterial_cervical);

        plot_MRI_arterial_cervical();
    }
    else{
        status_error(MRI_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_MRI_arterial_save_cervical
 */
void MainWindow::do_MRI_arterial_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_arterial_cervical);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_arterial_cervical();

        int n = MRI_ARTERIAL_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_ARTERIAL_DATA_ITEM01;    list2[0] = QString::number(MRI_box_systole_threshold_cervical->value()).toStdString();
        list1[1] = MRI_ARTERIAL_DATA_ITEM02;    list2[1] = QString::number(MRI_box_systole_delay_cervical->value()).toStdString();
        list1[2] = MRI_ARTERIAL_DATA_ITEM03;    list2[2] = MRI_box_arterial_move_cervical->text().toStdString();
        list1[3] = MRI_ARTERIAL_DATA_ITEM04;    list2[3] = MRI_label_heart_rate_cervical->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[4] = MRI_ARTERIAL_DATA_ITEM05;    list2[4] = MRI_label_arterial_min_cervical->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_ARTERIAL_DATA_ITEM06;    list2[5] = MRI_label_arterial_max_cervical->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[6] = MRI_ARTERIAL_DATA_ITEM07;    list2[6] = MRI_label_arterial_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[7] = MRI_ARTERIAL_DATA_ITEM08;    list2[7] = MRI_label_arterial_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[8] = MRI_ARTERIAL_DATA_ITEM09;    list2[8] = MRI_label_arterial_stroke_cervical->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_arterial_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_MRI_legend_cervical
 */
void MainWindow::do_MRI_legend_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if(MRI_legend_cervical == 0){
        MRI_plot_arterial_cervical->legend->setVisible(true);
        MRI_plot_arterial_cervical->replot();
        MRI_plot_venous_cervical->legend->setVisible(true);
        MRI_plot_venous_cervical->replot();
        MRI_plot_csf_cervical->legend->setVisible(true);
        MRI_plot_csf_cervical->replot();

        MRI_legend_cervical++;
        MRI_legend_cervical = MRI_legend_cervical % 2;
    }
    else{
        MRI_plot_arterial_cervical->legend->setVisible(false);
        MRI_plot_arterial_cervical->replot();
        MRI_plot_venous_cervical->legend->setVisible(false);
        MRI_plot_venous_cervical->replot();
        MRI_plot_csf_cervical->legend->setVisible(false);
        MRI_plot_csf_cervical->replot();

        MRI_legend_cervical++;
        MRI_legend_cervical = MRI_legend_cervical % 2;
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_restore_cervical
 */
void MainWindow::do_MRI_venous_restore_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_venous_cervical->clear();
            MRI_coord_venous_cervical->set_size(npi);
            MRI_coord_venous_cervical->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_venous_move_cervical->setValue(0);
            plot_MRI_venous_cervical();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_smooth_cervical
 */
void MainWindow::do_MRI_venous_smooth_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        MRI_coord_venous_cervical = smooth(*MRI_coord_venous_cervical);

        plot_MRI_venous_cervical();
    }
    else{
        status_error(MRI_ERROR_004);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_save_cervical
 */
void MainWindow::do_MRI_venous_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_venous_cervical);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_venous_cervical();

        int n = MRI_VENOUS_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_VENOUS_DATA_ITEM01;  list2[0] = MRI_box_venous_move_cervical->text().toStdString();
        list1[1] = MRI_VENOUS_DATA_ITEM02;  list2[1] = MRI_label_venous_min_cervical->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[2] = MRI_VENOUS_DATA_ITEM03;  list2[2] = MRI_label_venous_max_cervical->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[3] = MRI_VENOUS_DATA_ITEM04;  list2[3] = MRI_label_venous_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[4] = MRI_VENOUS_DATA_ITEM05;  list2[4] = MRI_label_venous_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_VENOUS_DATA_ITEM06;  list2[5] = MRI_label_venous_stroke_cervical->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_venous_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_004);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_corr_save_cervical
 */
void MainWindow::do_MRI_venous_corr_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_corr_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_COR_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_COR_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_venous_corr_cervical, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_venous_cervical();

        int n = MRI_VENOUS_CORR_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_VENOUS_CORR_DATA_ITEM01; list2[0] = MRI_label_venous_corr_cervical->text().remove(MAINWINDOW_MRI_V_CORR).toStdString();
        list1[1] = MRI_VENOUS_CORR_DATA_ITEM02; list2[1] = MRI_box_venous_move_cervical->text().toStdString();
        list1[2] = MRI_VENOUS_CORR_DATA_ITEM03; list2[2] = MRI_label_venous_corr_min_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[3] = MRI_VENOUS_CORR_DATA_ITEM04; list2[3] = MRI_label_venous_corr_max_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[4] = MRI_VENOUS_CORR_DATA_ITEM05; list2[4] = MRI_label_venous_corr_mean_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[5] = MRI_VENOUS_CORR_DATA_ITEM06; list2[5] = MRI_label_venous_corr_grad_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[6] = MRI_VENOUS_CORR_DATA_ITEM07; list2[6] = MRI_label_venous_corr_stroke_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_venous_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_005);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_restore_cervical
 */
void MainWindow::do_MRI_csf_restore_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_csf_cervical->clear();
            MRI_coord_csf_cervical->set_size(npi);
            MRI_coord_csf_cervical->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_csf_move_cervical->setValue(0);
            plot_MRI_csf_cervical();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_smooth_cervical
 */
void MainWindow::do_MRI_csf_smooth_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        MRI_coord_csf_cervical = smooth(*MRI_coord_csf_cervical);

        plot_MRI_csf_cervical();
    }
    else{
        status_error(MRI_ERROR_006);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_save_cervical
 */
void MainWindow::do_MRI_csf_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_csf_cervical, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_csf_cervical();

        int n = MRI_CSF_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_CSF_DATA_ITEM01; list2[0] = MRI_box_csf_move_cervical->text().toStdString();
        list1[1] = MRI_CSF_DATA_ITEM02; list2[1] = MRI_label_csf_heart_rate_cervical->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[2] = MRI_CSF_DATA_ITEM03; list2[2] = MRI_label_csf_min_cervical->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[3] = MRI_CSF_DATA_ITEM04; list2[3] = MRI_label_csf_max_cervical->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[4] = MRI_CSF_DATA_ITEM05; list2[4] = MRI_label_csf_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_CSF_DATA_ITEM06; list2[5] = MRI_label_csf_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[6] = MRI_CSF_DATA_ITEM07; list2[6] = MRI_label_csf_stroke_cervical->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_csf_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_006);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_corr_save_cervical
 */
void MainWindow::do_MRI_csf_corr_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_corr_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_COR_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_COR_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_csf_corr_cervical, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_csf_cervical();

        int n = MRI_CSF_CORR_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_CSF_CORR_DATA_ITEM01;    list2[0] = MRI_label_csf_corr_cervical->text().remove(MAINWINDOW_MRI_C_CORR).toStdString();
        list1[1] = MRI_CSF_CORR_DATA_ITEM02;    list2[1] = MRI_box_csf_move_cervical->text().toStdString();
        list1[2] = MRI_CSF_CORR_DATA_ITEM03;    list2[2] = MRI_label_csf_heart_rate_cervical->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[3] = MRI_CSF_CORR_DATA_ITEM04;    list2[3] = MRI_label_csf_corr_min_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[4] = MRI_CSF_CORR_DATA_ITEM05;    list2[4] = MRI_label_csf_corr_max_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[5] = MRI_CSF_CORR_DATA_ITEM06;    list2[5] = MRI_label_csf_corr_mean_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[6] = MRI_CSF_CORR_DATA_ITEM07;    list2[6] = MRI_label_csf_corr_grad_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[7] = MRI_CSF_CORR_DATA_ITEM08;    list2[7] = MRI_label_csf_corr_stroke_cervical->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_csf_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_007);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_corr_cervical
 */
void MainWindow::do_MRI_venous_corr_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cervical->size();
    int n2 = MRI_coord_venous_cervical->size();

    if (n1 > 0 && n2 > 0 && n1 == n2){
        //Calculus
        double corr_value = av_conservation(*MRI_coord_arterial_cervical, *MRI_coord_venous_cervical);

        //Venous corrected
        MRI_coord_venous_corr_cervical->set_size(n1);
        for (int i = 0; i < n1; i++){
            MRI_coord_venous_corr_cervical->set_coord(MRI_coord_venous_cervical->coord(i, XCOORD), i, XCOORD);
            MRI_coord_venous_corr_cervical->set_coord(MRI_coord_venous_cervical->coord(i, YCOORD)*corr_value, i, YCOORD);
        }

        //Plot
        plot_MRI_venous_corr_cervical();

        //Print
        MRI_label_venous_corr_cervical->setText(QString::fromStdString(MAINWINDOW_MRI_V_CORR) + QString::number(corr_value, 'f', 2));
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_corr_cervical
 */
void MainWindow::do_MRI_csf_corr_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cervical->size();

    if (n > 0){
        //Calculus
        double corr_value = mean(*MRI_coord_csf_cervical, YCOORD);

        //CSF corrected
        MRI_coord_csf_corr_cervical->set_size(n);
        for (int i = 0; i < n; i++){
            MRI_coord_csf_corr_cervical->set_coord(MRI_coord_csf_cervical->coord(i, XCOORD), i, XCOORD);
            MRI_coord_csf_corr_cervical->set_coord(MRI_coord_csf_cervical->coord(i, YCOORD) - corr_value, i, YCOORD);
        }

        //Plot
        plot_MRI_csf_corr_cervical();

        //Print
        MRI_label_csf_corr_cervical->setText(QString::fromStdString(MAINWINDOW_MRI_C_CORR) + QString::number(corr_value, 'f', 2));
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_cervical
 */
void MainWindow::do_MRI_AV_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cervical->size();
    int n2 = MRI_coord_venous_corr_cervical->size();

    if (n1 > 0 && n2 > 0 && n1 == n2){
        arteriovenous_flow(MRI_coord_AV_flow_cervical, *MRI_coord_arterial_cervical, *MRI_coord_venous_corr_cervical);
        arteriovenous_volume(MRI_coord_AV_volume_cervical, *MRI_coord_arterial_cervical, *MRI_coord_venous_corr_cervical);

        MRI_AV_flow_cervical_normalized = 0;
        MRI_AV_volume_cervical_normalized = 0;

        //Plot
        plot_MRI_AV_cervical();

        //AV-ICVC ratio
        if (MRI_coord_ICVC_volume_cervical->size() > 0){
            double AV_min = min(MRI_coord_AV_volume_cervical->coords(YCOORD), npi);
            double AV_max = max(MRI_coord_AV_volume_cervical->coords(YCOORD), npi);
            double ICVC_min = min(MRI_coord_ICVC_volume_cervical->coords(YCOORD), npi);
            double ICVC_max = max(MRI_coord_ICVC_volume_cervical->coords(YCOORD), npi);
            double AV_ICVC_ratio = (AV_max - AV_min) / (ICVC_max - ICVC_min);
            MRI_label_AV_ICVC_ratio_cervical->setText(MAINWINDOW_MRI_AI_RATIO + QString::number(AV_ICVC_ratio, 'f', 2));
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_auto_cervical
 */
void MainWindow::do_MRI_AV_auto_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_MRI_venous_corr_cervical();
    do_MRI_csf_corr_cervical();
    do_MRI_AV_cervical();
}

/*!
 * \brief MainWindow::do_MRI_AV_adjust_cervical
 */
void MainWindow::do_MRI_AV_adjust_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cervical->size();

        if (n > 0){
            adjust(MRI_coord_AV_flow_cervical, NULL, MRI_box_AV_adjust_cervical->currentText().toLower().toStdString());

            //Plot
            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
    else{
        int n = MRI_coord_AV_flow_cervical->size();

        if (n > 0){
            adjust(MRI_coord_AV_volume_cervical, NULL, MRI_box_AV_adjust_cervical->currentText().toLower().toStdString());

            //Plot
            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_normalize_cervical
 */
void MainWindow::do_MRI_AV_normalize_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cervical->size();

        if (n > 0){
            normalize(MRI_coord_AV_flow_cervical, NULL);

            MRI_AV_flow_cervical_normalized = 1;

            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
    else{
        int n = MRI_coord_AV_volume_cervical->size();

        if (n > 0){
            normalize(MRI_coord_AV_volume_cervical, NULL);

            MRI_AV_volume_cervical_normalized = 1;

            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_smooth_cervical
 */
void MainWindow::do_MRI_AV_smooth_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cervical->size();

        if (n > 0){
            MRI_coord_AV_flow_cervical = smooth(*MRI_coord_AV_flow_cervical);

            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
    else{
        int n = MRI_coord_AV_volume_cervical->size();

        if (n > 0){
            MRI_coord_AV_volume_cervical = smooth(*MRI_coord_AV_volume_cervical);

            plot_MRI_AV_cervical();
        }
        else{
            status_error(MRI_ERROR_008);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_save_cervical
 */
void MainWindow::do_MRI_AV_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_AV_FLOW_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_AV_FLOW_CERVICAL_FILE_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_AV_flow_cervical, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_AV_cervical();

        int n = MRI_AV_DATA_LENGTH+1;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_AV_DATA_ITEM01;   string_list2[0] = MRI_label_AV_flow_min_cervical->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[1] = MRI_AV_DATA_ITEM02;   string_list2[1] = MRI_label_AV_flow_max_cervical->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        string_list1[2] = MRI_AV_DATA_ITEM03;   string_list2[2] = MRI_label_AV_flow_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[3] = MRI_AV_DATA_ITEM04;   string_list2[3] = MRI_label_AV_flow_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        string_list1[4] = MRI_AV_DATA_ITEM05;   string_list2[4] = MRI_label_AV_flow_stroke_cervical->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();
        string_list1[5] = MRI_AV_DATA_ITEM06;   string_list2[5] = MRI_label_AV_ICVC_ratio_cervical->text().remove(MAINWINDOW_MRI_AI_RATIO).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_AV_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_008);
    }

    n = MRI_coord_AV_volume_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_AV_VOLUME_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_AV_VOLUME_CERVICAL_FILE_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_AV_volume_cervical, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_AV_cervical();

        int n = MRI_AV_DATA_LENGTH;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_AV_DATA_ITEM01;   string_list2[0] = MRI_label_AV_volume_min_cervical->text().remove(MAINWINDOW_MRI_MIN_V).remove(UNITY_MM3).toStdString();
        string_list1[1] = MRI_AV_DATA_ITEM02;   string_list2[1] = MRI_label_AV_volume_max_cervical->text().remove(MAINWINDOW_MRI_MAX_V).remove(UNITY_MM3).toStdString();
        string_list1[2] = MRI_AV_DATA_ITEM03;   string_list2[2] = MRI_label_AV_volume_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_V).remove(UNITY_MM3).toStdString();
        string_list1[3] = MRI_AV_DATA_ITEM04;   string_list2[3] = MRI_label_AV_volume_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_V).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_AV_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_008);
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_cervical
 */
void MainWindow::do_MRI_ICVC_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cervical->size();
    int n2 = MRI_coord_venous_corr_cervical->size();
    int n3 = MRI_coord_csf_corr_cervical->size();

    if (n1 > 0 &&  n2 > 0 && n3 > 0 && n1 == n2 && n2 == n3){
        icvc_flow(MRI_coord_ICVC_flow_cervical, *MRI_coord_arterial_cervical, *MRI_coord_venous_corr_cervical, *MRI_coord_csf_corr_cervical);
        icvc_volume(MRI_coord_ICVC_volume_cervical, *MRI_coord_arterial_cervical, *MRI_coord_venous_corr_cervical, *MRI_coord_csf_corr_cervical);

        MRI_ICVC_flow_cervical_normalized = 0;
        MRI_ICVC_volume_cervical_normalized = 0;

        //Plot
        plot_MRI_ICVC_cervical();

        //AV-ICVC ratio
        if (MRI_coord_AV_volume_cervical->size() > 0){
            double AV_min = min(MRI_coord_AV_volume_cervical->coords(YCOORD), npi);
            double AV_max = max(MRI_coord_AV_volume_cervical->coords(YCOORD), npi);
            double ICVC_min = min(MRI_coord_ICVC_volume_cervical->coords(YCOORD), npi);
            double ICVC_max = max(MRI_coord_ICVC_volume_cervical->coords(YCOORD), npi);
            double AV_ICVC_ratio = (AV_max - AV_min) / (ICVC_max - ICVC_min);
            MRI_label_AV_ICVC_ratio_cervical->setText(MAINWINDOW_MRI_AI_RATIO + QString::number(AV_ICVC_ratio, 'f', 2));
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_auto_cervical
 */
void MainWindow::do_MRI_ICVC_auto_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_MRI_venous_corr_cervical();
    do_MRI_csf_corr_cervical();
    do_MRI_ICVC_cervical();
}

/*!
 * \brief MainWindow::do_MRI_ICVC_adjust_cervical
 */
void MainWindow::do_MRI_ICVC_adjust_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cervical->size();

        if (n > 0){
            adjust(MRI_coord_ICVC_flow_cervical, NULL, MRI_box_ICVC_adjust_cervical->currentText().toLower().toStdString());

            //Plot
            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cervical->size();

        if (n > 0){
            adjust(MRI_coord_ICVC_volume_cervical, NULL, MRI_box_ICVC_adjust_cervical->currentText().toLower().toStdString());

            //Plot
            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_normalize_cervical
 */
void MainWindow::do_MRI_ICVC_normalize_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cervical->size();

        if (n > 0){
            normalize(MRI_coord_ICVC_flow_cervical, NULL);

            MRI_ICVC_flow_cervical_normalized = 1;

            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cervical->size();

        if (n > 0){
            normalize(MRI_coord_ICVC_volume_cervical, NULL);

            MRI_ICVC_volume_cervical_normalized = 1;

            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_smooth_cervical
 */
void MainWindow::do_MRI_ICVC_smooth_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cervical->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cervical->size();

        if (n > 0){
            MRI_coord_ICVC_flow_cervical = smooth(*MRI_coord_ICVC_flow_cervical);

            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cervical->size();

        if (n > 0){
            MRI_coord_ICVC_volume_cervical = smooth(*MRI_coord_ICVC_volume_cervical);

            plot_MRI_ICVC_cervical();
        }
        else{
            status_error(MRI_ERROR_009);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_save_cervical
 */
void MainWindow::do_MRI_ICVC_save_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ICVC_FLOW_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ICVC_FLOW_CERVICAL_FILE_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_ICVC_flow_cervical);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_ICVC_cervical();

        int n = MRI_ICVC_DATA_LENGTH+1;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_ICVC_DATA_ITEM01;  string_list2[0] = MRI_label_ICVC_flow_min_cervical->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[1] = MRI_ICVC_DATA_ITEM02;  string_list2[1] = MRI_label_ICVC_flow_max_cervical->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        string_list1[2] = MRI_ICVC_DATA_ITEM03;  string_list2[2] = MRI_label_ICVC_flow_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[3] = MRI_ICVC_DATA_ITEM04;  string_list2[3] = MRI_label_ICVC_flow_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        string_list1[4] = MRI_ICVC_DATA_ITEM05;  string_list2[4] = MRI_label_ICVC_flow_stroke_cervical->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();
        string_list1[5] = MRI_ICVC_DATA_ITEM06;  string_list2[5] = MRI_label_AV_ICVC_ratio_cervical->text().remove(MAINWINDOW_MRI_AI_RATIO).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_ICVC_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_009);
    }

    n = MRI_coord_ICVC_volume_cervical->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ICVC_VOLUME_CERVICAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ICVC_VOLUME_CERVICAL_FILE_DAT;

        bool res;

        //DATA
        res = save_data(file_name_pro, MRI_coord_ICVC_volume_cervical);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_ICVC_cervical();

        int n = MRI_ICVC_DATA_LENGTH;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_ICVC_DATA_ITEM01;  string_list2[0] = MRI_label_ICVC_volume_min_cervical->text().remove(MAINWINDOW_MRI_MIN_V).remove(UNITY_MM3).toStdString();
        string_list1[1] = MRI_ICVC_DATA_ITEM02;  string_list2[1] = MRI_label_ICVC_volume_max_cervical->text().remove(MAINWINDOW_MRI_MAX_V).remove(UNITY_MM3).toStdString();
        string_list1[2] = MRI_ICVC_DATA_ITEM03;  string_list2[2] = MRI_label_ICVC_volume_mean_cervical->text().remove(MAINWINDOW_MRI_MEAN_V).remove(UNITY_MM3).toStdString();
        string_list1[3] = MRI_ICVC_DATA_ITEM04;  string_list2[3] = MRI_label_ICVC_volume_grad_cervical->text().remove(MAINWINDOW_MRI_GRAD_V).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_ICVC_cervical();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_009);
    }
}

//

/*!
 * \brief MainWindow::do_MRI_quality_cerebral
 */
void MainWindow::do_MRI_quality_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){
        DialogQuality *dialog = new DialogQuality(current_dir, DIALOG_QUALITY_PARAM2, NULL, NULL, this);
        int res = dialog->exec();
        if (res == QDialog::Accepted){
            MRI_quality_arterial_cerebral = get_MRI_arterial_cerebral_quality_source(current_dir).toInt();
            MRI_quality_venous_cerebral = get_MRI_venous_cerebral_quality_source(current_dir).toInt();
            MRI_quality_csf_cerebral = get_MRI_csf_cerebral_quality_source(current_dir).toInt();
        }
        delete dialog;
    }
}

/*!
 * \brief MainWindow::do_MRI_plot_00_cerebral
 */
void MainWindow::do_MRI_plot_00_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_plot_00_cerebral++;
    MRI_plot_00_cerebral = MRI_plot_00_cerebral%2;

    plot_MRI_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cerebral_1
 */
void MainWindow::do_MRI_choice_ncycles_cerebral_1(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cerebral = 1;

    MRI_menu_ncycles_cerebral->actions().at(1)->setChecked(false);
    MRI_menu_ncycles_cerebral->actions().at(2)->setChecked(false);

    plot_MRI_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cerebral_2
 */
void MainWindow::do_MRI_choice_ncycles_cerebral_2(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cerebral = 2;

    MRI_menu_ncycles_cerebral->actions().at(0)->setChecked(false);
    MRI_menu_ncycles_cerebral->actions().at(2)->setChecked(false);

    plot_MRI_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_choice_ncycles_cerebral_3
 */
void MainWindow::do_MRI_choice_ncycles_cerebral_3(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    MRI_ncycles_cerebral = 3;

    MRI_menu_ncycles_cerebral->actions().at(0)->setChecked(false);
    MRI_menu_ncycles_cerebral->actions().at(1)->setChecked(false);

    plot_MRI_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_systole_detect_cerebral
 */
void MainWindow::do_MRI_systole_detect_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        //Detect
        MRI_coord_systole_cerebral = detect_systole(*MRI_coord_arterial_cerebral, MRI_box_systole_delay_cerebral->value(), MRI_box_systole_threshold_cerebral->value());

        n = MRI_coord_systole_cerebral->size();

        if (n > 0){
            //Plot
            plot_MRI_systole_cerebral();
        }
        else{
            status_error(MRI_ERROR_012);
        }
    }
    else{
        status_error(MRI_ERROR_011);
    }
}

/*!
 * \brief MainWindow::do_MRI_systole_adjust_cerebral
 */
void MainWindow::do_MRI_systole_adjust_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_systole_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(MRI_coord_arterial_cerebral);
        double min_arterial = min(xy[1]);

        delete[] xy;

        int pos = 0, pos2 = 0;
        for (int i = 0; i < MRI_coord_systole_cerebral->size(); i++){
            if (MRI_coord_systole_cerebral->coord(i, XCOORD) > min_arterial){
                pos = i;
                break;
            }
        }
        for (int i = 0; i < MRI_coord_arterial_cerebral->size(); i++){
            if (MRI_coord_arterial_cerebral->coord(i, XCOORD) > MRI_coord_systole_cerebral->coord(pos, XCOORD)){
                pos2 = i;
                break;
            }
        }
        for (int i = 0; i < pos2; i++){
            bool modified = false;
            if(MRI_check_move_cervical->isChecked()){
                MRI_check_move_cervical->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_left_cerebral();
            if (modified){
                MRI_check_move_cervical->setChecked(true);
            }
        }

        do_MRI_systole_detect_cerebral();
    }
    else{
        status_error(MRI_ERROR_012);
    }
}

void MainWindow::do_MRI_systole_show_cerebral(){
    MRI_plot_arterial_cerebral->graph(1)->clearData();
    MRI_plot_arterial_cerebral->replot();
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_right_cerebral
 */
void MainWindow::do_MRI_move_arterial_right_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        double end = MRI_coord_arterial_cerebral->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_arterial_cerebral->set_coord(MRI_coord_arterial_cerebral->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_arterial_cerebral->set_coord(end, 0, YCOORD);

        int pos = MRI_box_arterial_move_cerebral->value();
        pos++;
        pos = pos % npi;
        MRI_box_arterial_move_cerebral->setValue(pos);

        plot_MRI_arterial_cerebral();

        if (MRI_check_move_cerebral->isChecked()){
            do_MRI_move_venous_right_cerebral();
            do_MRI_move_csf_right_cerebral();

            bool modified = false;
            if (MRI_check_move_cervical->isChecked()){
                MRI_check_move_cervical->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_right_cervical();
            do_MRI_move_venous_right_cervical();
            do_MRI_move_csf_right_cervical();
            if (modified){
                MRI_check_move_cervical->setChecked(true);
            }
        }

        if (MRI_coord_systole_cerebral->size() > 0){
            do_MRI_systole_detect_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_011);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_left_cerebral
 */
void MainWindow::do_MRI_move_arterial_left_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        double begin = MRI_coord_arterial_cerebral->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_arterial_cerebral->set_coord(MRI_coord_arterial_cerebral->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_arterial_cerebral->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_arterial_move_cerebral->value();
        pos--;
        pos = pos % npi;
        MRI_box_arterial_move_cerebral->setValue(pos);

        plot_MRI_arterial_cerebral();

        if (MRI_check_move_cerebral->isChecked()){
            do_MRI_move_venous_left_cerebral();
            do_MRI_move_csf_left_cerebral();

            bool modified = false;
            if (MRI_check_move_cervical->isChecked()){
                MRI_check_move_cervical->setChecked(false);
                modified = true;
            }
            do_MRI_move_arterial_left_cervical();
            do_MRI_move_venous_left_cervical();
            do_MRI_move_csf_left_cervical();
            if (modified){
                MRI_check_move_cervical->setChecked(true);
            }
        }

        if (MRI_coord_systole_cerebral->size() > 0){
            do_MRI_systole_detect_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_011);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_venous_right_cerebral
 */
void MainWindow::do_MRI_move_venous_right_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        double end = MRI_coord_venous_cerebral->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_venous_cerebral->set_coord(MRI_coord_venous_cerebral->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_venous_cerebral->set_coord(end, 0, YCOORD);

        int pos = MRI_box_venous_move_cerebral->value();
        pos++;
        pos = pos % npi;
        MRI_box_venous_move_cerebral->setValue(pos);

        plot_MRI_venous_cerebral();

        if (MRI_coord_venous_corr_cerebral->size() > 0){
            do_MRI_venous_corr_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_013);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_venous_left_cerebral
 */
void MainWindow::do_MRI_move_venous_left_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        double begin = MRI_coord_venous_cerebral->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_venous_cerebral->set_coord(MRI_coord_venous_cerebral->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_venous_cerebral->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_venous_move_cerebral->value();
        pos--;
        pos = pos % npi;
        MRI_box_venous_move_cerebral->setValue(pos);

        plot_MRI_venous_cerebral();

        if (MRI_coord_venous_corr_cerebral->size() > 0){
            do_MRI_venous_corr_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_013);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_csf_right_cerebral
 */
void MainWindow::do_MRI_move_csf_right_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        double end = MRI_coord_csf_cerebral->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            MRI_coord_csf_cerebral->set_coord(MRI_coord_csf_cerebral->coord(i-1, YCOORD), i, YCOORD);
        }
        MRI_coord_csf_cerebral->set_coord(end, 0, YCOORD);

        int pos = MRI_box_csf_move_cerebral->value();
        pos++;
        pos = pos % npi;
        MRI_box_csf_move_cerebral->setValue(pos);

        plot_MRI_csf_cerebral();

        if (MRI_coord_csf_corr_cerebral->size() > 0){
            do_MRI_csf_corr_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_015);
    }
}

/*!
 * \brief MainWindow::do_MRI_move_csf_left_cerebral
 */
void MainWindow::do_MRI_move_csf_left_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        double begin = MRI_coord_csf_cerebral->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            MRI_coord_csf_cerebral->set_coord(MRI_coord_csf_cerebral->coord(i+1, YCOORD), i, YCOORD);
        }
        MRI_coord_csf_cerebral->set_coord(begin, n-1, YCOORD);

        int pos = MRI_box_csf_move_cerebral->value();
        pos--;
        pos = pos % npi;
        MRI_box_csf_move_cerebral->setValue(pos);

        plot_MRI_csf_cerebral();

        if (MRI_coord_csf_corr_cerebral->size() > 0){
            do_MRI_csf_corr_cerebral();
        }
    }
    else{
        status_error(MRI_ERROR_015);
    }
}

void MainWindow::do_MRI_arterial_restore_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_arterial_cerebral->clear();
            MRI_coord_arterial_cerebral->set_size(npi);
            MRI_coord_arterial_cerebral->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_arterial_move_cerebral->setValue(0);
            plot_MRI_arterial_cerebral();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_arterial_smooth_cerebral
 */
void MainWindow::do_MRI_arterial_smooth_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        MRI_coord_arterial_cerebral = smooth(*MRI_coord_arterial_cerebral);

        plot_MRI_arterial_cerebral();
    }
    else{
        status_error(MRI_ERROR_011);
    }
}

/*!
 * \brief MainWindow::do_MRI_arterial_save_cerebral
 */
void MainWindow::do_MRI_arterial_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_arterial_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_arterial_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_arterial_cerebral();

        int n = MRI_ARTERIAL_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_ARTERIAL_DATA_ITEM01;    list2[0] = QString::number(MRI_box_systole_threshold_cerebral->value()).toStdString();
        list1[1] = MRI_ARTERIAL_DATA_ITEM02;    list2[1] = QString::number(MRI_box_systole_delay_cerebral->value()).toStdString();
        list1[2] = MRI_ARTERIAL_DATA_ITEM03;    list2[2] = MRI_box_arterial_move_cerebral->text().toStdString();
        list1[3] = MRI_ARTERIAL_DATA_ITEM04;    list2[3] = MRI_label_heart_rate_cerebral->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[4] = MRI_ARTERIAL_DATA_ITEM05;    list2[4] = MRI_label_arterial_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_ARTERIAL_DATA_ITEM06;    list2[5] = MRI_label_arterial_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[6] = MRI_ARTERIAL_DATA_ITEM07;    list2[6] = MRI_label_arterial_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[7] = MRI_ARTERIAL_DATA_ITEM08;    list2[7] = MRI_label_arterial_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[8] = MRI_ARTERIAL_DATA_ITEM09;    list2[8] = MRI_label_arterial_stroke_cerebral->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_arterial_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_011);
    }
}

/*!
 * \brief MainWindow::do_MRI_legend_cerebral
 */
void MainWindow::do_MRI_legend_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if(MRI_legend_cerebral == 0){
        MRI_plot_arterial_cerebral->legend->setVisible(true);
        MRI_plot_arterial_cerebral->replot();
        MRI_plot_venous_cerebral->legend->setVisible(true);
        MRI_plot_venous_cerebral->replot();
        MRI_plot_csf_cerebral->legend->setVisible(true);
        MRI_plot_csf_cerebral->replot();

        MRI_legend_cerebral++;
        MRI_legend_cerebral = MRI_legend_cerebral % 2;
    }
    else{
        MRI_plot_arterial_cerebral->legend->setVisible(false);
        MRI_plot_arterial_cerebral->replot();
        MRI_plot_venous_cerebral->legend->setVisible(false);
        MRI_plot_venous_cerebral->replot();
        MRI_plot_csf_cerebral->legend->setVisible(false);
        MRI_plot_csf_cerebral->replot();

        MRI_legend_cerebral++;
        MRI_legend_cerebral = MRI_legend_cerebral % 2;
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_restore_cerebral
 */
void MainWindow::do_MRI_venous_restore_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_venous_cerebral->clear();
            MRI_coord_venous_cerebral->set_size(npi);
            MRI_coord_venous_cerebral->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_venous_move_cerebral->setValue(0);
            plot_MRI_venous_cerebral();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_smooth_cerebral
 */
void MainWindow::do_MRI_venous_smooth_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        MRI_coord_venous_cerebral = smooth(*MRI_coord_venous_cerebral);

        plot_MRI_venous_cerebral();
    }
    else{
        status_error(MRI_ERROR_013);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_save_cerebral
 */
void MainWindow::do_MRI_venous_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_venous_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_venous_cerebral();

        int n = MRI_VENOUS_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_VENOUS_DATA_ITEM01;  list2[0] = MRI_box_venous_move_cerebral->text().toStdString();
        list1[1] = MRI_VENOUS_DATA_ITEM02;  list2[1] = MRI_label_venous_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[2] = MRI_VENOUS_DATA_ITEM03;  list2[2] = MRI_label_venous_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[3] = MRI_VENOUS_DATA_ITEM04;  list2[3] = MRI_label_venous_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[4] = MRI_VENOUS_DATA_ITEM05;  list2[4] = MRI_label_venous_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_VENOUS_DATA_ITEM06;  list2[5] = MRI_label_venous_stroke_cerebral->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_venous_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_013);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_corr_save_cerebral
 */
void MainWindow::do_MRI_venous_corr_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_venous_corr_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_COR_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_COR_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_venous_corr_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_venous_cerebral();

        int n = MRI_VENOUS_CORR_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_VENOUS_CORR_DATA_ITEM01; list2[0] = MRI_label_venous_corr_cerebral->text().remove(MAINWINDOW_MRI_V_CORR).toStdString();
        list1[1] = MRI_VENOUS_CORR_DATA_ITEM02; list2[1] = MRI_box_venous_move_cerebral->text().toStdString();
        list1[2] = MRI_VENOUS_CORR_DATA_ITEM03; list2[2] = MRI_label_venous_corr_min_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[3] = MRI_VENOUS_CORR_DATA_ITEM04; list2[3] = MRI_label_venous_corr_max_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[4] = MRI_VENOUS_CORR_DATA_ITEM05; list2[4] = MRI_label_venous_corr_mean_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[5] = MRI_VENOUS_CORR_DATA_ITEM06; list2[5] = MRI_label_venous_corr_grad_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[6] = MRI_VENOUS_CORR_DATA_ITEM07; list2[6] = MRI_label_venous_corr_stroke_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_venous_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_014);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_restore_cerebral
 */
void MainWindow::do_MRI_csf_restore_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        Coord *restore = new Coord;
        bool res = load_data(current_dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE, restore);

        if (res){
            extend(restore, npi);
            MRI_coord_csf_cerebral->clear();
            MRI_coord_csf_cerebral->set_size(npi);
            MRI_coord_csf_cerebral->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
            MRI_box_csf_move_cerebral->setValue(0);
            plot_MRI_csf_cerebral();
        }
        else{
            status_error(MRI_ERROR_024);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_smooth_cerebral
 */
void MainWindow::do_MRI_csf_smooth_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        MRI_coord_csf_cerebral = smooth(*MRI_coord_csf_cerebral);

        plot_MRI_csf_cerebral();
    }
    else{
        status_error(MRI_ERROR_015);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_save_cerebral
 */
void MainWindow::do_MRI_csf_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_csf_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_csf_cerebral();

        int n = MRI_CSF_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_CSF_DATA_ITEM01; list2[0] = MRI_box_csf_move_cerebral->text().toStdString();
        list1[1] = MRI_CSF_DATA_ITEM02; list2[1] = MRI_label_csf_heart_rate_cerebral->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[2] = MRI_CSF_DATA_ITEM03; list2[2] = MRI_label_csf_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        list1[3] = MRI_CSF_DATA_ITEM04; list2[3] = MRI_label_csf_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        list1[4] = MRI_CSF_DATA_ITEM05; list2[4] = MRI_label_csf_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        list1[5] = MRI_CSF_DATA_ITEM06; list2[5] = MRI_label_csf_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        list1[6] = MRI_CSF_DATA_ITEM07; list2[6] = MRI_label_csf_stroke_cerebral->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_csf_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_015);
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_corr_save_cerebral
 */
void MainWindow::do_MRI_csf_corr_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_corr_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_COR_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_COR_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_csf_corr_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_csf_cerebral();

        int n = MRI_CSF_CORR_DATA_LENGTH;
        string *list1 = new string[n];
        string *list2 = new string[n];

        list1[0] = MRI_CSF_CORR_DATA_ITEM01;    list2[0] = MRI_label_csf_corr_cerebral->text().remove(MAINWINDOW_MRI_C_CORR).toStdString();
        list1[1] = MRI_CSF_CORR_DATA_ITEM02;    list2[1] = MRI_box_csf_move_cerebral->text().toStdString();
        list1[2] = MRI_CSF_CORR_DATA_ITEM03;    list2[2] = MRI_label_csf_heart_rate_cerebral->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
        list1[3] = MRI_CSF_CORR_DATA_ITEM04;    list2[3] = MRI_label_csf_corr_min_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[4] = MRI_CSF_CORR_DATA_ITEM05;    list2[4] = MRI_label_csf_corr_max_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[5] = MRI_CSF_CORR_DATA_ITEM06;    list2[5] = MRI_label_csf_corr_mean_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[6] = MRI_CSF_CORR_DATA_ITEM07;    list2[6] = MRI_label_csf_corr_grad_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();
        list1[7] = MRI_CSF_CORR_DATA_ITEM08;    list2[7] = MRI_label_csf_corr_stroke_cerebral->text().remove(MAINWINDOW_MRI_LBRACKET).remove(MAINWINDOW_MRI_RBRACKET).toStdString();

        res = save_sup_data(file_name_dat, list1, list2, n);

        delete[] list1;
        delete[] list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_csf_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_016);
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_corr_cerebral
 */
void MainWindow::do_MRI_venous_corr_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cerebral->size();
    int n2 = MRI_coord_venous_cerebral->size();

    if (n1 > 0 && n2 > 0 && n1 == n2){
        //Calculus
        double corr_value = av_conservation(*MRI_coord_arterial_cerebral, *MRI_coord_venous_cerebral);

        //Venous corrected
        MRI_coord_venous_corr_cerebral->set_size(n1);
        for (int i = 0; i < n1; i++){
            MRI_coord_venous_corr_cerebral->set_coord(MRI_coord_venous_cerebral->coord(i, XCOORD), i, XCOORD);
            MRI_coord_venous_corr_cerebral->set_coord(MRI_coord_venous_cerebral->coord(i, YCOORD)*corr_value, i, YCOORD);
        }

        //Plot
        plot_MRI_venous_corr_cerebral();

        //Print
        MRI_label_venous_corr_cerebral->setText(QString::fromStdString(MAINWINDOW_MRI_V_CORR) + QString::number(corr_value, 'f', 2));
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_corr_cerebral
 */
void MainWindow::do_MRI_csf_corr_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_csf_cerebral->size();

    if (n > 0){
        //Calculus
        double corr_value = mean(*MRI_coord_csf_cerebral, YCOORD);

        //CSF corrected
        MRI_coord_csf_corr_cerebral->set_size(n);
        for (int i = 0; i < n; i++){
            MRI_coord_csf_corr_cerebral->set_coord(MRI_coord_csf_cerebral->coord(i, XCOORD), i, XCOORD);
            MRI_coord_csf_corr_cerebral->set_coord(MRI_coord_csf_cerebral->coord(i, YCOORD) - corr_value, i, YCOORD);
        }

        //Plot
        plot_MRI_csf_corr_cerebral();

        //Print
        MRI_label_csf_corr_cerebral->setText(QString::fromStdString(MAINWINDOW_MRI_C_CORR) + QString::number(corr_value, 'f', 2));
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_cerebral
 */
void MainWindow::do_MRI_AV_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cerebral->size();
    int n2 = MRI_coord_venous_corr_cerebral->size();

    if (n1 > 0 && n2 > 0 && n1 == n2){
        arteriovenous_flow(MRI_coord_AV_flow_cerebral, *MRI_coord_arterial_cerebral, *MRI_coord_venous_corr_cerebral);
        arteriovenous_volume(MRI_coord_AV_volume_cerebral, *MRI_coord_arterial_cerebral, *MRI_coord_venous_corr_cerebral);

        MRI_AV_flow_cerebral_normalized = 0;
        MRI_AV_volume_cerebral_normalized = 0;

        //Plot
        plot_MRI_AV_cerebral();

        //AV-ICVC ratio
        if (MRI_coord_ICVC_volume_cerebral->size() > 0){
            double AV_min = min(MRI_coord_AV_volume_cerebral->coords(YCOORD), npi);
            double AV_max = max(MRI_coord_AV_volume_cerebral->coords(YCOORD), npi);
            double ICVC_min = min(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), npi);
            double ICVC_max = max(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), npi);
            double AV_ICVC_ratio = (AV_max - AV_min) / (ICVC_max - ICVC_min);
            MRI_label_AV_ICVC_ratio_cerebral->setText(MAINWINDOW_MRI_AI_RATIO + QString::number(AV_ICVC_ratio, 'f', 2));
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_auto_cerebral
 */
void MainWindow::do_MRI_AV_auto_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_MRI_venous_corr_cerebral();
    do_MRI_csf_corr_cerebral();
    do_MRI_AV_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_AV_adjust_cerebral
 */
void MainWindow::do_MRI_AV_adjust_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cerebral->size();

        if (n > 0){
            adjust(MRI_coord_AV_flow_cerebral, NULL, MRI_box_AV_adjust_cerebral->currentText().toLower().toStdString());

            //Plot
            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
    else{
        int n = MRI_coord_AV_volume_cerebral->size();

        if (n > 0){
            adjust(MRI_coord_AV_volume_cerebral, NULL, MRI_box_AV_adjust_cerebral->currentText().toLower().toStdString());

            //Plot
            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_normalize_cerebral
 */
void MainWindow::do_MRI_AV_normalize_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cerebral->size();

        if (n > 0){
            normalize(MRI_coord_AV_flow_cerebral, NULL);

            MRI_AV_flow_cerebral_normalized = 1;

            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
    else{
        int n = MRI_coord_AV_volume_cerebral->size();

        if (n > 0){
            normalize(MRI_coord_AV_volume_cerebral, NULL);

            MRI_AV_volume_cerebral_normalized = 1;

            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_smooth_cerebral
 */
void MainWindow::do_MRI_AV_smooth_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_AV_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_AV_flow_cerebral->size();

        if (n > 0){
            MRI_coord_AV_flow_cerebral = smooth(*MRI_coord_AV_flow_cerebral);

            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
    else{
        int n = MRI_coord_AV_volume_cerebral->size();

        if (n > 0){
            MRI_coord_AV_volume_cerebral = smooth(*MRI_coord_AV_volume_cerebral);

            plot_MRI_AV_cerebral();
        }
        else{
            status_error(MRI_ERROR_017);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_AV_save_cerebral
 */
void MainWindow::do_MRI_AV_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_AV_flow_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_AV_FLOW_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_AV_FLOW_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_AV_flow_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_AV_cerebral();

        int n = MRI_AV_DATA_LENGTH+1;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_AV_DATA_ITEM01;   string_list2[0] = MRI_label_AV_flow_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[1] = MRI_AV_DATA_ITEM02;   string_list2[1] = MRI_label_AV_flow_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        string_list1[2] = MRI_AV_DATA_ITEM03;   string_list2[2] = MRI_label_AV_flow_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[3] = MRI_AV_DATA_ITEM04;   string_list2[3] = MRI_label_AV_flow_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        string_list1[4] = MRI_AV_DATA_ITEM05;   string_list2[4] = MRI_label_AV_flow_stroke_cerebral->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();
        string_list1[5] = MRI_AV_DATA_ITEM06;   string_list2[5] = MRI_label_AV_ICVC_ratio_cerebral->text().remove(MAINWINDOW_MRI_AI_RATIO).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_AV_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_017);
    }

    n = MRI_coord_AV_volume_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_AV_VOLUME_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_AV_VOLUME_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_AV_volume_cerebral, NULL);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_AV_cerebral();

        int n = MRI_AV_DATA_LENGTH;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_AV_DATA_ITEM01;   string_list2[0] = MRI_label_AV_volume_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_V).remove(UNITY_MM3).toStdString();
        string_list1[1] = MRI_AV_DATA_ITEM02;   string_list2[1] = MRI_label_AV_volume_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_V).remove(UNITY_MM3).toStdString();
        string_list1[2] = MRI_AV_DATA_ITEM03;   string_list2[2] = MRI_label_AV_volume_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_V).remove(UNITY_MM3).toStdString();
        string_list1[3] = MRI_AV_DATA_ITEM04;   string_list2[3] = MRI_label_AV_volume_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_V).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_AV_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_017);
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_cerebral
 */
void MainWindow::do_MRI_ICVC_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_arterial_cerebral->size();
    int n2 = MRI_coord_venous_corr_cerebral->size();
    int n3 = MRI_coord_csf_corr_cervical->size();   //C2C3

    if (n1 > 0 &&  n2 > 0 && n3 > 0 && n1 == n2 && n2 == n3){
        icvc_flow(MRI_coord_ICVC_flow_cerebral, *MRI_coord_arterial_cerebral, *MRI_coord_venous_corr_cerebral, *MRI_coord_csf_corr_cervical);
        icvc_volume(MRI_coord_ICVC_volume_cerebral, *MRI_coord_arterial_cerebral, *MRI_coord_venous_corr_cerebral, *MRI_coord_csf_corr_cervical);

        MRI_ICVC_flow_cerebral_normalized = 0;
        MRI_ICVC_volume_cerebral_normalized = 0;

        //Plot
        plot_MRI_ICVC_cerebral();

        //AV-ICVC ratio
        if (MRI_coord_AV_volume_cerebral->size() > 0){
            double AV_min = min(MRI_coord_AV_volume_cerebral->coords(YCOORD), npi);
            double AV_max = max(MRI_coord_AV_volume_cerebral->coords(YCOORD), npi);
            double ICVC_min = min(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), npi);
            double ICVC_max = max(MRI_coord_ICVC_volume_cerebral->coords(YCOORD), npi);
            double AV_ICVC_ratio = (AV_max - AV_min) / (ICVC_max - ICVC_min);
            MRI_label_AV_ICVC_ratio_cerebral->setText(MAINWINDOW_MRI_AI_RATIO + QString::number(AV_ICVC_ratio, 'f', 2));
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_auto_cerebral
 */
void MainWindow::do_MRI_ICVC_auto_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_MRI_venous_corr_cerebral();
    do_MRI_csf_corr_cervical();
    do_MRI_ICVC_cerebral();
}

/*!
 * \brief MainWindow::do_MRI_ICVC_adjust_cerebral
 */
void MainWindow::do_MRI_ICVC_adjust_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cerebral->size();

        if (n > 0){
            adjust(MRI_coord_ICVC_flow_cerebral, NULL, MRI_box_ICVC_adjust_cerebral->currentText().toLower().toStdString());

            //Plot
            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cerebral->size();

        if (n > 0){
            adjust(MRI_coord_ICVC_volume_cerebral, NULL, MRI_box_ICVC_adjust_cerebral->currentText().toLower().toStdString());

            //Plot
            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_normalize_cerebral
 */
void MainWindow::do_MRI_ICVC_normalize_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cerebral->size();

        if (n > 0){
            normalize(MRI_coord_ICVC_flow_cerebral, NULL);

            MRI_ICVC_flow_cerebral_normalized = 1;

            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cerebral->size();

        if (n > 0){
            normalize(MRI_coord_ICVC_volume_cerebral, NULL);

            MRI_ICVC_volume_cerebral_normalized = 1;

            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_smooth_cerebral
 */
void MainWindow::do_MRI_ICVC_smooth_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (MRI_box_ICVC_flow_volume_cerebral->currentIndex() == 0){
        int n = MRI_coord_ICVC_flow_cerebral->size();

        if (n > 0){
            MRI_coord_ICVC_flow_cerebral = smooth(*MRI_coord_ICVC_flow_cerebral);

            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
    else{
        int n = MRI_coord_ICVC_volume_cerebral->size();

        if (n > 0){
            MRI_coord_ICVC_volume_cerebral = smooth(*MRI_coord_ICVC_volume_cerebral);

            plot_MRI_ICVC_cerebral();
        }
        else{
            status_error(MRI_ERROR_018);
        }
    }
}

/*!
 * \brief MainWindow::do_MRI_ICVC_save_cerebral
 */
void MainWindow::do_MRI_ICVC_save_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = MRI_coord_ICVC_flow_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ICVC_FLOW_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ICVC_FLOW_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_ICVC_flow_cerebral);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_ICVC_cerebral();

        int n = MRI_ICVC_DATA_LENGTH+1;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_ICVC_DATA_ITEM01;  string_list2[0] = MRI_label_ICVC_flow_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[1] = MRI_ICVC_DATA_ITEM02;  string_list2[1] = MRI_label_ICVC_flow_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
        string_list1[2] = MRI_ICVC_DATA_ITEM03;  string_list2[2] = MRI_label_ICVC_flow_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
        string_list1[3] = MRI_ICVC_DATA_ITEM04;  string_list2[3] = MRI_label_ICVC_flow_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
        string_list1[4] = MRI_ICVC_DATA_ITEM05;  string_list2[4] = MRI_label_ICVC_flow_stroke_cerebral->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();
        string_list1[5] = MRI_ICVC_DATA_ITEM06;  string_list2[5] = MRI_label_AV_ICVC_ratio_cerebral->text().remove(MAINWINDOW_MRI_AI_RATIO).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_ICVC_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_018);
    }

    n = MRI_coord_ICVC_volume_cerebral->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_ICVC_VOLUME_CEREBRAL_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_ICVC_VOLUME_CEREBRAL_FILE_DAT;

        bool res = true;

        //DATA
        res = save_data(file_name_pro, MRI_coord_ICVC_volume_cerebral);
        if (!res){
            QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
        }

        //SUP DATA
        string current_flow_unity = MRI_flow_unity.toStdString();
        string current_volume_unity = MRI_volume_unity.toStdString();
        string current_time_unity = MRI_time_unity.toStdString();

        MRI_flow_unity = UNITY_MM3_S;
        MRI_volume_unity = UNITY_MM3;
        MRI_time_unity = UNITY_S;

        print_MRI_ICVC_cerebral();

        int n = MRI_ICVC_DATA_LENGTH;
        string *string_list1 = new string[n];
        string *string_list2 = new string[n];

        string_list1[0] = MRI_ICVC_DATA_ITEM01;  string_list2[0] = MRI_label_ICVC_volume_min_cerebral->text().remove(MAINWINDOW_MRI_MIN_V).remove(UNITY_MM3).toStdString();
        string_list1[1] = MRI_ICVC_DATA_ITEM02;  string_list2[1] = MRI_label_ICVC_volume_max_cerebral->text().remove(MAINWINDOW_MRI_MAX_V).remove(UNITY_MM3).toStdString();
        string_list1[2] = MRI_ICVC_DATA_ITEM03;  string_list2[2] = MRI_label_ICVC_volume_mean_cerebral->text().remove(MAINWINDOW_MRI_MEAN_V).remove(UNITY_MM3).toStdString();
        string_list1[3] = MRI_ICVC_DATA_ITEM04;  string_list2[3] = MRI_label_ICVC_volume_grad_cerebral->text().remove(MAINWINDOW_MRI_GRAD_V).remove(UNITY_MM3).toStdString();

        res = save_sup_data(file_name_dat, string_list1, string_list2, n);

        delete[] string_list1;
        delete[] string_list2;

        MRI_flow_unity = QString::fromStdString(current_flow_unity);
        MRI_volume_unity = QString::fromStdString(current_volume_unity);
        MRI_time_unity = QString::fromStdString(current_time_unity);

        print_MRI_ICVC_cerebral();

        if (!res){
            QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
        }
    }
    else{
        status_error(MRI_ERROR_018);
    }
}

//

void MainWindow::do_MRI_dphi(){
    //ARTERIAL
    int n1 = MRI_coord_arterial_cervical->size();
    int n2 = MRI_coord_arterial_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_arterial_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_arterial_cerebral);

        unity_convert_flow(xy1, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double max_pos1 = 0;
        double maxx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (maxx1 < xy1[1][i]){
                maxx1 = xy1[1][i];
                max_pos1 = i;
            }
        }

        double max_pos2 = 0;
        double maxx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (maxx2 < xy2[1][i]){
                maxx2 = xy2[1][i];
                max_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][max_pos1]);
        b11.append(xy1[0][max_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_arterial_cervical_cerebral->graph(2)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][max_pos2]);
        b21.append(xy2[0][max_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_arterial_cervical_cerebral->graph(3)->setData(b21, b22);

        MRI_plot_arterial_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][max_pos1] - xy2[0][max_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_arterial_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //VENOUS
    n1 = MRI_coord_venous_cervical->size();
    n2 = MRI_coord_venous_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_venous_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_venous_cerebral);

        unity_convert_flow(xy1, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Min y
        double min_pos1 = 0;
        double minx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (minx1 > xy1[1][i]){
                minx1 = xy1[1][i];
                min_pos1 = i;
            }
        }

        double min_pos2 = 0;
        double minx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (minx2 > xy2[1][i]){
                minx2 = xy2[1][i];
                min_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][min_pos1]);
        b11.append(xy1[0][min_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_venous_cervical_cerebral->graph(4)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][min_pos2]);
        b21.append(xy2[0][min_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_venous_cervical_cerebral->graph(5)->setData(b21, b22);

        MRI_plot_venous_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][min_pos1] - xy2[0][min_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_venous_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //CSF
    n1 = MRI_coord_csf_cervical->size();
    n2 = MRI_coord_csf_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_csf_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_csf_cerebral);

        unity_convert_flow(xy1, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double min_pos1 = 0;
        double minx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (minx1 > xy1[1][i]){
                minx1 = xy1[1][i];
                min_pos1 = i;
            }
        }

        double min_pos2 = 0;
        double minx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (minx2 > xy2[1][i]){
                minx2 = xy2[1][i];
                min_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][min_pos1]);
        b11.append(xy1[0][min_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_csf_cervical_cerebral->graph(4)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][min_pos2]);
        b21.append(xy2[0][min_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_csf_cervical_cerebral->graph(5)->setData(b21, b22);

        MRI_plot_csf_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][min_pos1] - xy2[0][min_pos2]);
        dphi = dphi * 100.;
        MRI_label_csf_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //AV FLOW
    n1 = MRI_coord_AV_flow_cervical->size();
    n2 = MRI_coord_AV_flow_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_AV_flow_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_AV_flow_cerebral);

        unity_convert_flow(xy1, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double max_pos1 = 0;
        double maxx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (maxx1 < xy1[1][i]){
                maxx1 = xy1[1][i];
                max_pos1 = i;
            }
        }

        double max_pos2 = 0;
        double maxx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (maxx2 < xy2[1][i]){
                maxx2 = xy2[1][i];
                max_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][max_pos1]);
        b11.append(xy1[0][max_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_AV_flow_cervical_cerebral->graph(2)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][max_pos2]);
        b21.append(xy2[0][max_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_AV_flow_cervical_cerebral->graph(3)->setData(b21, b22);

        MRI_plot_AV_flow_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][max_pos1] - xy2[0][max_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_AV_flow_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //ICVC FLOW
    n1 = MRI_coord_ICVC_flow_cervical->size();
    n2 = MRI_coord_ICVC_flow_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_ICVC_flow_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_ICVC_flow_cerebral);

        unity_convert_flow(xy1, MRI_flow_unity, MRI_time_unity);
        unity_convert_flow(xy2, MRI_flow_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double max_pos1 = 0;
        double maxx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (maxx1 < xy1[1][i]){
                maxx1 = xy1[1][i];
                max_pos1 = i;
            }
        }

        double max_pos2 = 0;
        double maxx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (maxx2 < xy2[1][i]){
                maxx2 = xy2[1][i];
                max_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][max_pos1]);
        b11.append(xy1[0][max_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_ICVC_flow_cervical_cerebral->graph(2)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][max_pos2]);
        b21.append(xy2[0][max_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_ICVC_flow_cervical_cerebral->graph(3)->setData(b21, b22);

        MRI_plot_ICVC_flow_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][max_pos1] - xy2[0][max_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_ICVC_flow_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //AV VOLUME
    n1 = MRI_coord_AV_volume_cervical->size();
    n2 = MRI_coord_AV_volume_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_AV_volume_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_AV_volume_cerebral);

        unity_convert_volume(xy1, MRI_volume_unity, MRI_time_unity);
        unity_convert_volume(xy2, MRI_volume_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double max_pos1 = 0;
        double maxx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (maxx1 < xy1[1][i]){
                maxx1 = xy1[1][i];
                max_pos1 = i;
            }
        }

        double max_pos2 = 0;
        double maxx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (maxx2 < xy2[1][i]){
                maxx2 = xy2[1][i];
                max_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][max_pos1]);
        b11.append(xy1[0][max_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_AV_volume_cervical_cerebral->graph(2)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][max_pos2]);
        b21.append(xy2[0][max_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_AV_volume_cervical_cerebral->graph(3)->setData(b21, b22);

        MRI_plot_AV_volume_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][max_pos1] - xy2[0][max_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_AV_volume_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }

    //ICVC VOLUME
    n1 = MRI_coord_ICVC_volume_cervical->size();
    n2 = MRI_coord_ICVC_volume_cerebral->size();

    if (n1 > 0 && n2 > 0){
        QVector<double> *xy1 = Coord2QVector(MRI_coord_ICVC_volume_cervical);
        QVector<double> *xy2 = Coord2QVector(MRI_coord_ICVC_volume_cerebral);

        unity_convert_volume(xy1, MRI_volume_unity, MRI_time_unity);
        unity_convert_volume(xy2, MRI_volume_unity, MRI_time_unity);

        //Normalize x
        {
            double maxx1 = max(xy1[0]);
            for (int i = 0; i < n1; i++){
                xy1[0][i] = xy1[0][i] / maxx1;
            }
            double maxx2 = max(xy2[0]);
            for (int i = 0; i < n2; i++){
                xy2[0][i] = xy2[0][i] / maxx2;
            }
        }

        //Max y
        double max_pos1 = 0;
        double maxx1 = xy1[1][0];
        for (int i = 1; i < n1; i++){
            if (maxx1 < xy1[1][i]){
                maxx1 = xy1[1][i];
                max_pos1 = i;
            }
        }

        double max_pos2 = 0;
        double maxx2 = xy2[1][0];
        for (int i = 1; i < n2; i++){
            if (maxx2 < xy2[1][i]){
                maxx2 = xy2[1][i];
                max_pos2 = i;
            }
        }

        //Plot
        QVector<double> b11, b12;
        b11.append(xy1[0][max_pos1]);
        b11.append(xy1[0][max_pos1]);
        b12.append(-1e6);
        b12.append(1e6);
        MRI_plot_ICVC_volume_cervical_cerebral->graph(2)->setData(b11, b12);

        QVector<double> b21, b22;
        b21.append(xy2[0][max_pos2]);
        b21.append(xy2[0][max_pos2]);
        b22.append(-1e6);
        b22.append(1e6);
        MRI_plot_ICVC_volume_cervical_cerebral->graph(3)->setData(b21, b22);

        MRI_plot_ICVC_volume_cervical_cerebral->replot();

        //Print
        double dphi = (xy1[0][max_pos1] - xy2[0][max_pos2]);
        dphi = dphi * 100.;
        /*if (dphi > 0){
            dphi = min(dphi, 100-dphi);
        }
        else{
            dphi = max(dphi, -100-dphi);
        }*/
        MRI_label_ICVC_volume_dphi->setText(MAINWINDOW_MRI_DPHI + QString::number(dphi, 'f', 1) + "% CC");

        delete[] xy1;
        delete[] xy2;
    }
}

//

/*!
 * \brief MainWindow::do_MRI_quality_others
 */
void MainWindow::do_MRI_quality_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){

        int n_actions_arterial = MRI_arterial_menu->actions().count();
        int n_actions_venous = MRI_venous_menu->actions().count();
        int n_actions_csf = MRI_csf_menu->actions().count();

        int n_selected_arterial = 0;
        int n_selected_venous = 0;
        int n_selected_csf = 0;

        int *current_index = new int[3];

        for (int i = 0; i < n_actions_arterial; i++){
            if (MRI_arterial_menu->actions().at(i)->isChecked()){
                n_selected_arterial++;
                current_index[0] = i;
            }
        }

        for (int i = 0; i < n_actions_venous; i++){
            if (MRI_venous_menu->actions().at(i)->isChecked()){
                n_selected_venous++;
                current_index[1] = i;
            }
        }

        for (int i = 0; i < n_actions_csf; i++){
            if (MRI_csf_menu->actions().at(i)->isChecked()){
                n_selected_csf++;
                current_index[2] = i;
            }
        }

        if (n_selected_arterial == 1 && n_selected_venous == 1 && n_selected_csf == 1){
            QStringList *current_names = new QStringList;
            current_names->append(MRI_arterial_files_other->at(current_index[0]));
            current_names->append(MRI_venous_files_other->at(current_index[1]));
            current_names->append(MRI_csf_files_other->at(current_index[2]));
            DialogQuality *dialog = new DialogQuality(current_dir, DIALOG_QUALITY_PARAM3, current_index, current_names, this);
            int res = dialog->exec();
            if (res == QDialog::Accepted){
                MRI_quality_arterial_other[current_index[0]] = get_MRI_arterial_other_quality_source(current_dir, current_index[0]).toInt();
                MRI_quality_venous_other[current_index[1]] = get_MRI_venous_other_quality_source(current_dir, current_index[1]).toInt();
                MRI_quality_csf_other[current_index[2]] = get_MRI_csf_other_quality_source(current_dir, current_index[2]).toInt();
            }
            delete dialog;
            delete current_names;
        }
        else{
            QMessageBox::critical(this, "Quality", "Qualilty box does not support multi-selection or no-selection");
        }

        delete[] current_index;
    }
}

/*!
 * \brief MainWindow::do_MRI_button_arterial_others_visible
 */
void MainWindow::do_MRI_menu_arterial_others_visible(){
    MRI_button_arterial_choice->menu()->setVisible(true);
}

/*!
 * \brief MainWindow::do_MRI_button_venous_others_visible
 */
void MainWindow::do_MRI_menu_venous_others_visible(){
    MRI_button_venous_choice->menu()->setVisible(true);
}

/*!
 * \brief MainWindow::do_MRI_button_csf_others_visible
 */
void MainWindow::do_MRI_menu_csf_others_visible(){
    MRI_button_csf_choice->menu()->setVisible(true);
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_right_others
 */
void MainWindow::do_MRI_move_arterial_right_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_arterial = MRI_arterial_menu->actions().count()-2;

    for (int k = 0; k < n_actions_arterial; k++){
        if (MRI_arterial_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_arterial_other[k]->size();

            if (n > 0){
                double end = MRI_coords_arterial_other[k]->coord(n-1, YCOORD);
                for (int i = n-1; i >= 0; i--){
                    MRI_coords_arterial_other[k]->set_coord(MRI_coords_arterial_other[k]->coord(i-1, YCOORD), i, YCOORD);
                }
                MRI_coords_arterial_other[k]->set_coord(end, 0, YCOORD);

                if (MRI_check_move_others->isChecked()){
                    do_MRI_move_venous_right_others();
                    do_MRI_move_csf_right_others();
                }
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_move_arterial_left_others
 */
void MainWindow::do_MRI_move_arterial_left_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_arterial = MRI_arterial_menu->actions().count()-2;

    for (int k = 0; k < n_actions_arterial; k++){
        if (MRI_arterial_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_arterial_other[k]->size();

            if (n > 0){
                double begin = MRI_coords_arterial_other[k]->coord(0, YCOORD);
                for (int i = 0; i < n-1; i++){
                    MRI_coords_arterial_other[k]->set_coord(MRI_coords_arterial_other[k]->coord(i+1, YCOORD), i, YCOORD);
                }
                MRI_coords_arterial_other[k]->set_coord(begin, n-1, YCOORD);

                if (MRI_check_move_others->isChecked()){
                    do_MRI_move_venous_left_others();
                    do_MRI_move_csf_left_others();
                }
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_move_venous_right_others
 */
void MainWindow::do_MRI_move_venous_right_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_venous = MRI_venous_menu->actions().count()-2;

    for (int k = 0; k < n_actions_venous; k++){
        if (MRI_venous_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_venous_other[k]->size();

            if (n > 0){
                double end = MRI_coords_venous_other[k]->coord(n-1, YCOORD);
                for (int i = n-1; i >= 0; i--){
                    MRI_coords_venous_other[k]->set_coord(MRI_coords_venous_other[k]->coord(i-1, YCOORD), i, YCOORD);
                }
                MRI_coords_venous_other[k]->set_coord(end, 0, YCOORD);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_move_venous_left_others
 */
void MainWindow::do_MRI_move_venous_left_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_venous = MRI_venous_menu->actions().count()-2;

    for (int k = 0; k < n_actions_venous; k++){
        if (MRI_venous_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_venous_other[k]->size();

            if (n > 0){
                double begin = MRI_coords_venous_other[k]->coord(0, YCOORD);
                for (int i = 0; i < n-1; i++){
                    MRI_coords_venous_other[k]->set_coord(MRI_coords_venous_other[k]->coord(i+1, YCOORD), i, YCOORD);
                }
                MRI_coords_venous_other[k]->set_coord(begin, n-1, YCOORD);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_move_csf_right_others
 */
void MainWindow::do_MRI_move_csf_right_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_csf = MRI_csf_menu->actions().count()-2;

    for (int k = 0; k < n_actions_csf; k++){
        if (MRI_csf_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_csf_other[k]->size();

            if (n > 0){
                double end = MRI_coords_csf_other[k]->coord(n-1, YCOORD);
                for (int i = n-1; i >= 0; i--){
                    MRI_coords_csf_other[k]->set_coord(MRI_coords_csf_other[k]->coord(i-1, YCOORD), i, YCOORD);
                }
                MRI_coords_csf_other[k]->set_coord(end, 0, YCOORD);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_move_csf_left_others
 */
void MainWindow::do_MRI_move_csf_left_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions_csf = MRI_csf_menu->actions().count()-2;

    for (int k = 0; k < n_actions_csf; k++){
        if (MRI_csf_menu->actions().at(k)->isChecked()){
            int n = MRI_coords_csf_other[k]->size();

            if (n > 0){
                double begin = MRI_coords_csf_other[k]->coord(0, YCOORD);
                for (int i = 0; i < n-1; i++){
                    MRI_coords_csf_other[k]->set_coord(MRI_coords_csf_other[k]->coord(i+1, YCOORD), i, YCOORD);
                }
                MRI_coords_csf_other[k]->set_coord(begin, n-1, YCOORD);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

void MainWindow::do_MRI_arterial_restore_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_arterial_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_arterial_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_arterial_other[i]->size();

            if (n > 0){
                Coord *restore = new Coord;
                bool res = load_data(current_dir + DIR_SEPARATOR + MRI_arterial_files_other->at(i), restore);

                if (res){
                    extend(restore, npi);
                    MRI_coords_arterial_other[i]->clear();
                    MRI_coords_arterial_other[i]->set_size(npi);
                    MRI_coords_arterial_other[i]->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
                }
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_arterial_smooth_others
 */
void MainWindow::do_MRI_arterial_smooth_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_arterial_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_arterial_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_arterial_other[i]->size();

            if (n > 0){
                MRI_coords_arterial_other[i] = smooth(*MRI_coords_arterial_other[i]);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_arterial_save_others
 */
void MainWindow::do_MRI_arterial_save_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_arterial_menu->actions().count()-2;
    int selected_actions = 0;
    int pos = 0;

    for (int i = 0; i < n_actions; i++){
        if (MRI_arterial_menu->actions().at(i)->isChecked()){
            selected_actions++;
            pos = i;
        }
    }

    if (selected_actions == 1){
        int n = MRI_coords_arterial_other[pos]->size();

        if (n > 0){
            QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_arterial_files_other->at(pos) + "__processed.dat";
            QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_arterial_files_other->at(pos) + "__data.dat";

            bool res = true;

            //DATA
            res = save_data(file_name_pro, MRI_coords_arterial_other[pos], NULL);
            if (!res){
                QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
            }

            //SUP DATA
            string current_flow_unity = MRI_flow_unity.toStdString();
            string current_volume_unity = MRI_volume_unity.toStdString();
            string current_time_unity = MRI_time_unity.toStdString();

            MRI_flow_unity = UNITY_MM3_S;
            MRI_volume_unity = UNITY_MM3;
            MRI_time_unity = UNITY_S;

            print_MRI_arterial_others();

            int n = MRI_ARTERIAL_DATA_LENGTH;
            string *list1 = new string[n];
            string *list2 = new string[n];

            list1[0] = MRI_ARTERIAL_DATA_ITEM01;    list2[0] = EMPTY_STRING;
            list1[1] = MRI_ARTERIAL_DATA_ITEM02;    list2[1] = EMPTY_STRING;
            list1[2] = MRI_ARTERIAL_DATA_ITEM03;    list2[2] = EMPTY_STRING;
            list1[3] = MRI_ARTERIAL_DATA_ITEM04;    list2[3] = MRI_label_heart_rate_others->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
            list1[4] = MRI_ARTERIAL_DATA_ITEM05;    list2[4] = MRI_label_arterial_min_others->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
            list1[5] = MRI_ARTERIAL_DATA_ITEM06;    list2[5] = MRI_label_arterial_max_others->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
            list1[6] = MRI_ARTERIAL_DATA_ITEM07;    list2[6] = MRI_label_arterial_mean_others->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
            list1[7] = MRI_ARTERIAL_DATA_ITEM08;    list2[7] = MRI_label_arterial_grad_others->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
            list1[8] = MRI_ARTERIAL_DATA_ITEM09;    list2[8] = MRI_label_arterial_stroke_others->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

            res = save_sup_data(file_name_dat, list1, list2, n);

            delete[] list1;
            delete[] list2;

            MRI_flow_unity = QString::fromStdString(current_flow_unity);
            MRI_volume_unity = QString::fromStdString(current_volume_unity);
            MRI_time_unity = QString::fromStdString(current_time_unity);

            print_MRI_arterial_others();

            if (!res){
                QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
            }
        }
        else{
            status_error(MRI_ERROR_020);
        }
    }
    else{
        QMessageBox::critical(this, "Save", "Save box does not support multi-selection or no-selection");
    }
}

/*!
 * \brief MainWindow::do_MRI_legend_others
 */
void MainWindow::do_MRI_legend_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if(MRI_legend_others == 0){
        MRI_plot_arterial_others->legend->setVisible(true);
        MRI_plot_arterial_others->replot();
        MRI_plot_venous_others->legend->setVisible(true);
        MRI_plot_venous_others->replot();
        MRI_plot_csf_others->legend->setVisible(true);
        MRI_plot_csf_others->replot();

        MRI_legend_others++;
        MRI_legend_others = MRI_legend_others % 2;
    }
    else{
        MRI_plot_arterial_others->legend->setVisible(false);
        MRI_plot_arterial_others->replot();
        MRI_plot_venous_others->legend->setVisible(false);
        MRI_plot_venous_others->replot();
        MRI_plot_csf_others->legend->setVisible(false);
        MRI_plot_csf_others->replot();

        MRI_legend_others++;
        MRI_legend_others = MRI_legend_others % 2;
    }
}

/*!
 * \brief MainWindow::do_MRI_venous_restore_others
 */
void MainWindow::do_MRI_venous_restore_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_venous_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_venous_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_venous_other[i]->size();

            if (n > 0){
                Coord *restore = new Coord;
                bool res = load_data(current_dir + DIR_SEPARATOR + MRI_venous_files_other->at(i), restore);

                if (res){
                    extend(restore, npi);
                    MRI_coords_venous_other[i]->clear();
                    MRI_coords_venous_other[i]->set_size(npi);
                    MRI_coords_venous_other[i]->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
                }
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_venous_smooth_others
 */
void MainWindow::do_MRI_venous_smooth_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_venous_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_venous_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_venous_other[i]->size();

            if (n > 0){
                MRI_coords_venous_other[i] = smooth(*MRI_coords_venous_other[i]);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_venous_save_others
 */
void MainWindow::do_MRI_venous_save_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_venous_menu->actions().count()-2;
    int selected_actions = 0;
    int pos = 0;

    for (int i = 0; i < n_actions; i++){
        if (MRI_venous_menu->actions().at(i)->isChecked()){
            selected_actions++;
            pos = i;
        }
    }

    if (selected_actions == 1){
        int n = MRI_coords_venous_other[pos]->size();

        if (n > 0){
            QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_venous_files_other->at(pos) + "__processed.dat";
            QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_venous_files_other->at(pos) + "__data.dat";

            bool res = true;

            //DATA
            res = save_data(file_name_pro, MRI_coords_venous_other[pos], NULL);
            if (!res){
                QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
            }

            //SUP DATA
            string current_flow_unity = MRI_flow_unity.toStdString();
            string current_volume_unity = MRI_volume_unity.toStdString();
            string current_time_unity = MRI_time_unity.toStdString();

            MRI_flow_unity = UNITY_MM3_S;
            MRI_volume_unity = UNITY_MM3;
            MRI_time_unity = UNITY_S;

            print_MRI_venous_others();

            int n = MRI_VENOUS_DATA_LENGTH;
            string *list1 = new string[n];
            string *list2 = new string[n];

            list1[0] = MRI_VENOUS_DATA_ITEM01;  list2[0] = EMPTY_STRING;
            list1[1] = MRI_VENOUS_DATA_ITEM02;  list2[1] = MRI_label_venous_min_others->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
            list1[2] = MRI_VENOUS_DATA_ITEM03;  list2[2] = MRI_label_venous_max_others->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
            list1[3] = MRI_VENOUS_DATA_ITEM04;  list2[3] = MRI_label_venous_mean_others->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
            list1[4] = MRI_VENOUS_DATA_ITEM05;  list2[4] = MRI_label_venous_grad_others->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
            list1[5] = MRI_VENOUS_DATA_ITEM06;  list2[5] = MRI_label_venous_stroke_others->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

            res = save_sup_data(file_name_dat, list1, list2, n);

            delete[] list1;
            delete[] list2;

            MRI_flow_unity = QString::fromStdString(current_flow_unity);
            MRI_volume_unity = QString::fromStdString(current_volume_unity);
            MRI_time_unity = QString::fromStdString(current_time_unity);

            print_MRI_venous_others();

            if (!res){
                QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
            }
        }
        else{
            status_error(MRI_ERROR_022);
        }
    }
    else{
        QMessageBox::critical(this, "Save", "Save box does not support multi-selection or no-selection");
    }
}

/*!
 * \brief MainWindow::do_MRI_csf_restore_others
 */
void MainWindow::do_MRI_csf_restore_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_csf_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_csf_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_csf_other[i]->size();

            if (n > 0){
                Coord *restore = new Coord;
                bool res = load_data(current_dir + DIR_SEPARATOR + MRI_csf_files_other->at(i), restore);

                if (res){
                    extend(restore, npi);
                    MRI_coords_csf_other[i]->clear();
                    MRI_coords_csf_other[i]->set_size(npi);
                    MRI_coords_csf_other[i]->set_coords(restore->coords(XCOORD), restore->coords(YCOORD));
                }
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_csf_smooth_others
 */
void MainWindow::do_MRI_csf_smooth_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_csf_menu->actions().count()-2;

    for (int i = 0; i < n_actions; i++){
        if (MRI_csf_menu->actions().at(i)->isChecked()){
            int n = MRI_coords_csf_other[i]->size();

            if (n > 0){
                MRI_coords_csf_other[i] = smooth(*MRI_coords_csf_other[i]);
            }
        }
    }

    plot_MRI_arterial_others();
    plot_MRI_venous_others();
    plot_MRI_csf_others();
}

/*!
 * \brief MainWindow::do_MRI_csf_save_others
 */
void MainWindow::do_MRI_csf_save_others(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n_actions = MRI_csf_menu->actions().count()-2;
    int selected_actions = 0;
    int pos = 0;

    for (int i = 0; i < n_actions; i++){
        if (MRI_csf_menu->actions().at(i)->isChecked()){
            selected_actions++;
            pos = i;
        }
    }

    if (selected_actions == 1){
        int n = MRI_coords_csf_other[pos]->size();

        if (n > 0){
            QString file_name_pro = current_dir + DIR_SEPARATOR + MRI_csf_files_other->at(pos) + "__processed.dat";
            QString file_name_dat = current_dir + DIR_SEPARATOR + MRI_csf_files_other->at(pos) + "__data.dat";

            bool res = true;

            //DATA
            res = save_data(file_name_pro, MRI_coords_csf_other[pos], NULL);
            if (!res){
                QMessageBox::critical(this, MRI_ERROR_098_N, MRI_ERROR_098);
            }

            //SUP DATA
            string current_flow_unity = MRI_flow_unity.toStdString();
            string current_volume_unity = MRI_volume_unity.toStdString();
            string current_time_unity = MRI_time_unity.toStdString();

            MRI_flow_unity = UNITY_MM3_S;
            MRI_volume_unity = UNITY_MM3;
            MRI_time_unity = UNITY_S;

            print_MRI_csf_others();

            int n = MRI_CSF_DATA_LENGTH;
            string *list1 = new string[n];
            string *list2 = new string[n];

            list1[0] = MRI_CSF_DATA_ITEM01; list2[0] = EMPTY_STRING;
            list1[1] = MRI_CSF_DATA_ITEM02; list2[1] = MRI_label_csf_heart_rate_others->text().remove(MAINWINDOW_MRI_HR).remove(UNITY_BPM).toStdString();
            list1[2] = MRI_CSF_DATA_ITEM03; list2[2] = MRI_label_csf_min_others->text().remove(MAINWINDOW_MRI_MIN_F).remove(UNITY_MM3_S).toStdString();
            list1[3] = MRI_CSF_DATA_ITEM04; list2[3] = MRI_label_csf_max_others->text().remove(MAINWINDOW_MRI_MAX_F).remove(UNITY_MM3_S).toStdString();
            list1[4] = MRI_CSF_DATA_ITEM05; list2[4] = MRI_label_csf_mean_others->text().remove(MAINWINDOW_MRI_MEAN_F).remove(UNITY_MM3_S).toStdString();
            list1[5] = MRI_CSF_DATA_ITEM06; list2[5] = MRI_label_csf_grad_others->text().remove(MAINWINDOW_MRI_GRAD_F).remove(UNITY_MM3_S).toStdString();
            list1[6] = MRI_CSF_DATA_ITEM07; list2[6] = MRI_label_csf_stroke_others->text().remove(MAINWINDOW_MRI_STROKE).remove(UNITY_MM3).toStdString();

            res = save_sup_data(file_name_dat, list1, list2, n);

            delete[] list1;
            delete[] list2;

            MRI_flow_unity = QString::fromStdString(current_flow_unity);
            MRI_volume_unity = QString::fromStdString(current_volume_unity);
            MRI_time_unity = QString::fromStdString(current_time_unity);

            print_MRI_csf_others();

            if (!res){
                QMessageBox::critical(this, MRI_ERROR_099_N, MRI_ERROR_099);
            }
        }
        else{
            status_error(MRI_ERROR_023);
        }
    }
    else{
        QMessageBox::critical(this, "Save", "Save box does not support multi-selection or no-selection");
    }
}


//***********//
//***OTHER***//
//***********//
/*!
 * \brief MainWindow::save_MRI
 */
void MainWindow::save_MRI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_MRI_arterial_save_cervical();
    do_MRI_venous_save_cervical();
    do_MRI_venous_corr_save_cervical();
    do_MRI_csf_save_cervical();
    do_MRI_csf_corr_save_cervical();
    do_MRI_AV_save_cervical();
    do_MRI_ICVC_save_cervical();

    do_MRI_arterial_save_cerebral();
    do_MRI_venous_save_cerebral();
    do_MRI_venous_corr_save_cerebral();
    do_MRI_csf_save_cerebral();
    do_MRI_csf_corr_save_cerebral();
    do_MRI_AV_save_cerebral();
    do_MRI_ICVC_save_cerebral();

    {
        int n_actions = MRI_arterial_menu->actions().count()-2;
        int *selected = new int[n_actions+2];

        for (int i = 0; i < n_actions+2; i++){
            if (MRI_arterial_menu->actions().at(i)->isChecked()){
                selected[i] = 1;
                MRI_arterial_menu->actions().at(i)->setChecked(false);
            }
            else{
                selected[i] = 0;
            }
        }

        for (int i = 0; i < n_actions; i++){
            MRI_arterial_menu->actions().at(i)->setChecked(true);
            plot_MRI_arterial_others();
            do_MRI_arterial_save_others();
            MRI_arterial_menu->actions().at(i)->setChecked(false);
        }

        for (int i = 0; i < n_actions+2; i++){
            if (selected[i] == 1){
                MRI_arterial_menu->actions().at(i)->setChecked(true);
            }
        }
        plot_MRI_arterial_others();

        delete[] selected;
    }

    {
        int n_actions = MRI_venous_menu->actions().count()-2;
        int *selected = new int[n_actions+2];

        for (int i = 0; i < n_actions+2; i++){
            if (MRI_venous_menu->actions().at(i)->isChecked()){
                selected[i] = 1;
                MRI_venous_menu->actions().at(i)->setChecked(false);
            }
            else{
                selected[i] = 0;
            }
        }

        for (int i = 0; i < n_actions; i++){
            MRI_venous_menu->actions().at(i)->setChecked(true);
            plot_MRI_venous_others();
            do_MRI_venous_save_others();
            MRI_venous_menu->actions().at(i)->setChecked(false);
        }

        for (int i = 0; i < n_actions+2; i++){
            if (selected[i] == 1){
                MRI_venous_menu->actions().at(i)->setChecked(true);
            }
        }
        plot_MRI_venous_others();

        delete[] selected;
    }

    {
        int n_actions = MRI_csf_menu->actions().count()-2;
        int *selected = new int[n_actions+2];

        for (int i = 0; i < n_actions+2; i++){
            if (MRI_csf_menu->actions().at(i)->isChecked()){
                selected[i] = 1;
                MRI_csf_menu->actions().at(i)->setChecked(false);
            }
            else{
                selected[i] = 0;
            }
        }

        for (int i = 0; i < n_actions; i++){
            MRI_csf_menu->actions().at(i)->setChecked(true);
            plot_MRI_csf_others();
            do_MRI_csf_save_others();
            MRI_csf_menu->actions().at(i)->setChecked(false);
        }

        for (int i = 0; i <n_actions+2; i++){
            if (selected[i] == 1){
                MRI_csf_menu->actions().at(i)->setChecked(true);
            }
        }
        plot_MRI_csf_others();

        delete[] selected;
    }
}

/*!
 * \brief MainWindow::clear_MRI
 */
void MainWindow::clear_MRI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Plot
    MRI_plot_arterial_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_ART0);
    MRI_plot_arterial_cervical->graph(0)->clearData();
    MRI_plot_arterial_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_ART1);
    MRI_plot_arterial_cervical->graph(1)->clearData();
    MRI_plot_arterial_cervical->replot();
    MRI_plot_venous_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_VEN0);
    MRI_plot_venous_cervical->graph(0)->clearData();
    MRI_plot_venous_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_VEN1);
    MRI_plot_venous_cervical->graph(1)->clearData();
    MRI_plot_venous_cervical->replot();
    MRI_plot_csf_cervical->graph(0)->setName(MAINWINDOW_MRI_GRAPH_CSF0);
    MRI_plot_csf_cervical->graph(0)->clearData();
    MRI_plot_csf_cervical->graph(1)->setName(MAINWINDOW_MRI_GRAPH_CSF1);
    MRI_plot_csf_cervical->graph(1)->clearData();
    MRI_plot_csf_cervical->replot();
    MRI_plot_AV_cervical->graph(0)->clearData();
    MRI_plot_AV_cervical->replot();
    MRI_plot_ICVC_cervical->graph(0)->clearData();
    MRI_plot_ICVC_cervical->replot();

    MRI_plot_arterial_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_ART0);
    MRI_plot_arterial_cerebral->graph(0)->clearData();
    MRI_plot_arterial_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_ART1);
    MRI_plot_arterial_cerebral->graph(1)->clearData();
    MRI_plot_arterial_cerebral->replot();
    MRI_plot_venous_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_VEN0);
    MRI_plot_venous_cerebral->graph(0)->clearData();
    MRI_plot_venous_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_VEN1);
    MRI_plot_venous_cerebral->graph(1)->clearData();
    MRI_plot_venous_cerebral->replot();
    MRI_plot_csf_cerebral->graph(0)->setName(MAINWINDOW_MRI_GRAPH_CSF0);
    MRI_plot_csf_cerebral->graph(0)->clearData();
    MRI_plot_csf_cerebral->graph(1)->setName(MAINWINDOW_MRI_GRAPH_CSF1);
    MRI_plot_csf_cerebral->graph(1)->clearData();
    MRI_plot_csf_cerebral->replot();
    MRI_plot_AV_cerebral->graph(0)->clearData();
    MRI_plot_AV_cerebral->replot();
    MRI_plot_ICVC_cerebral->graph(0)->clearData();
    MRI_plot_ICVC_cerebral->replot();

    MRI_plot_arterial_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_arterial_cervical_cerebral->graph(0)->clearData();
    MRI_plot_arterial_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_arterial_cervical_cerebral->graph(1)->clearData();
    MRI_plot_arterial_cervical_cerebral->graph(2)->clearData();
    MRI_plot_arterial_cervical_cerebral->graph(3)->clearData();
    MRI_plot_arterial_cervical_cerebral->replot();
    MRI_plot_venous_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_venous_cervical_cerebral->graph(0)->clearData();
    MRI_plot_venous_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_venous_cervical_cerebral->graph(1)->clearData();
    MRI_plot_venous_cervical_cerebral->graph(2)->setName(MAINWINDOW_MRI_CERVICAL_C);
    MRI_plot_venous_cervical_cerebral->graph(2)->clearData();
    MRI_plot_venous_cervical_cerebral->graph(3)->setName(MAINWINDOW_MRI_CERERBAL_C);
    MRI_plot_venous_cervical_cerebral->graph(3)->clearData();
    MRI_plot_venous_cervical_cerebral->graph(4)->clearData();
    MRI_plot_venous_cervical_cerebral->graph(5)->clearData();
    MRI_plot_venous_cervical_cerebral->replot();
    MRI_plot_csf_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_csf_cervical_cerebral->graph(0)->clearData();
    MRI_plot_csf_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_csf_cervical_cerebral->graph(1)->clearData();
    MRI_plot_csf_cervical_cerebral->graph(2)->setName(MAINWINDOW_MRI_CERERBAL_C);
    MRI_plot_csf_cervical_cerebral->graph(2)->clearData();
    MRI_plot_csf_cervical_cerebral->graph(3)->setName(MAINWINDOW_MRI_CERERBAL_C);
    MRI_plot_csf_cervical_cerebral->graph(3)->clearData();
    MRI_plot_csf_cervical_cerebral->graph(4)->clearData();
    MRI_plot_csf_cervical_cerebral->graph(5)->clearData();
    MRI_plot_csf_cervical_cerebral->replot();
    MRI_plot_AV_flow_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_AV_flow_cervical_cerebral->graph(0)->clearData();
    MRI_plot_AV_flow_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_AV_flow_cervical_cerebral->graph(1)->clearData();
    MRI_plot_AV_flow_cervical_cerebral->graph(2)->clearData();
    MRI_plot_AV_flow_cervical_cerebral->graph(3)->clearData();
    MRI_plot_AV_volume_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_AV_volume_cervical_cerebral->graph(0)->clearData();
    MRI_plot_AV_volume_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_AV_volume_cervical_cerebral->graph(1)->clearData();
    MRI_plot_AV_volume_cervical_cerebral->graph(2)->clearData();
    MRI_plot_AV_volume_cervical_cerebral->graph(3)->clearData();
    MRI_plot_ICVC_flow_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(0)->clearData();
    MRI_plot_ICVC_flow_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_ICVC_flow_cervical_cerebral->graph(1)->clearData();
    MRI_plot_ICVC_flow_cervical_cerebral->graph(2)->clearData();
    MRI_plot_ICVC_flow_cervical_cerebral->graph(3)->clearData();
    MRI_plot_ICVC_volume_cervical_cerebral->graph(0)->setName(MAINWINDOW_MRI_CERVICAL);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(0)->clearData();
    MRI_plot_ICVC_volume_cervical_cerebral->graph(1)->setName(MAINWINDOW_MRI_CEREBRAL);
    MRI_plot_ICVC_volume_cervical_cerebral->graph(1)->clearData();
    MRI_plot_ICVC_volume_cervical_cerebral->graph(2)->clearData();
    MRI_plot_ICVC_volume_cervical_cerebral->graph(3)->clearData();

    MRI_plot_arterial_others->clearGraphs();
    MRI_plot_venous_others->clearGraphs();
    MRI_plot_csf_others->clearGraphs();

    //Coord
    MRI_coord_arterial_cervical->clear();
    MRI_coord_systole_cervical->clear();
    MRI_coord_venous_cervical->clear();
    MRI_coord_venous_corr_cervical->clear();
    MRI_coord_csf_cervical->clear();
    MRI_coord_csf_corr_cervical->clear();
    MRI_coord_AV_flow_cervical->clear();
    MRI_coord_AV_volume_cervical->clear();
    MRI_coord_ICVC_flow_cervical->clear();
    MRI_coord_ICVC_volume_cervical->clear();

    MRI_coord_arterial_cerebral->clear();
    MRI_coord_systole_cerebral->clear();
    MRI_coord_venous_cerebral->clear();
    MRI_coord_venous_corr_cerebral->clear();
    MRI_coord_csf_cerebral->clear();
    MRI_coord_csf_corr_cerebral->clear();
    MRI_coord_AV_flow_cerebral->clear();
    MRI_coord_AV_volume_cerebral->clear();
    MRI_coord_ICVC_flow_cerebral->clear();
    MRI_coord_ICVC_volume_cerebral->clear();

    if (MRI_number_arterial > 0){
        for (int i = 0; i < MRI_number_arterial; i++){
            MRI_coords_arterial_other[i]->clear();
        }
        if (MRI_coords_arterial_other != NULL) delete[] MRI_coords_arterial_other; MRI_coords_arterial_other = NULL;
    }
    if (MRI_number_venous > 0){
        for (int i = 0; i < MRI_number_venous; i++){
            MRI_coords_venous_other[i]->clear();
        }
        if (MRI_coords_venous_other != NULL) delete[] MRI_coords_venous_other; MRI_coords_venous_other = NULL;
    }
    if (MRI_number_csf > 0){
        for (int i = 0; i < MRI_number_csf; i++){
            MRI_coords_csf_other[i]->clear();
        }
        if (MRI_coords_csf_other != NULL) delete[] MRI_coords_csf_other; MRI_coords_csf_other = NULL;
    }

    //Box
    MRI_box_systole_threshold_cervical->setValue(0.);
    MRI_box_systole_delay_cervical->setValue(0);
    MRI_box_arterial_move_cervical->setValue(0);
    MRI_box_venous_move_cervical->setValue(0);
    MRI_box_csf_move_cervical->setValue(0);

    MRI_box_systole_threshold_cerebral->setValue(0.);
    MRI_box_systole_delay_cerebral->setValue(0);
    MRI_box_arterial_move_cerebral->setValue(0);
    MRI_box_venous_move_cerebral->setValue(0);
    MRI_box_csf_move_cerebral->setValue(0);

    MRI_button_arterial_choice->menu()->clear();
    MRI_button_venous_choice->menu()->clear();
    MRI_button_csf_choice->menu()->clear();

    //Check
    MRI_check_move_cervical->setChecked(true);

    MRI_check_move_cerebral->setChecked(true);

    MRI_check_move_others->setChecked(true);

    //Label
    MRI_label_heart_rate_cervical->clear();
    MRI_label_arterial_min_cervical->clear();
    MRI_label_arterial_max_cervical->clear();
    MRI_label_arterial_mean_cervical->clear();
    MRI_label_arterial_grad_cervical->clear();
    MRI_label_arterial_stroke_cervical->clear();
    MRI_label_venous_corr_cervical->clear();
    MRI_label_venous_min_cervical->clear();
    MRI_label_venous_max_cervical->clear();
    MRI_label_venous_mean_cervical->clear();
    MRI_label_venous_grad_cervical->clear();
    MRI_label_venous_stroke_cervical->clear();
    MRI_label_venous_corr_min_cervical->clear();
    MRI_label_venous_corr_max_cervical->clear();
    MRI_label_venous_corr_mean_cervical->clear();
    MRI_label_venous_corr_grad_cervical->clear();
    MRI_label_venous_corr_stroke_cervical->clear();
    MRI_label_csf_corr_cervical->clear();
    MRI_label_csf_heart_rate_cervical->clear();
    MRI_label_csf_min_cervical->clear();
    MRI_label_csf_max_cervical->clear();
    MRI_label_csf_mean_cervical->clear();
    MRI_label_csf_grad_cervical->clear();
    MRI_label_csf_stroke_cervical->clear();
    MRI_label_csf_corr_min_cervical->clear();
    MRI_label_csf_corr_max_cervical->clear();
    MRI_label_csf_corr_mean_cervical->clear();
    MRI_label_csf_corr_grad_cervical->clear();
    MRI_label_csf_corr_stroke_cervical->clear();
    MRI_label_AV_ICVC_ratio_cervical->clear();
    MRI_label_AV_flow_min_cervical->clear();
    MRI_label_AV_flow_max_cervical->clear();
    MRI_label_AV_flow_mean_cervical->clear();
    MRI_label_AV_flow_grad_cervical->clear();
    MRI_label_AV_flow_stroke_cervical->clear();
    MRI_label_AV_volume_min_cervical->clear();
    MRI_label_AV_volume_max_cervical->clear();
    MRI_label_AV_volume_mean_cervical->clear();
    MRI_label_AV_volume_grad_cervical->clear();
    MRI_label_ICVC_flow_min_cervical->clear();
    MRI_label_ICVC_flow_max_cervical->clear();
    MRI_label_ICVC_flow_mean_cervical->clear();
    MRI_label_ICVC_flow_grad_cervical->clear();
    MRI_label_ICVC_flow_stroke_cervical->clear();
    MRI_label_ICVC_volume_min_cervical->clear();
    MRI_label_ICVC_volume_max_cervical->clear();
    MRI_label_ICVC_volume_mean_cervical->clear();
    MRI_label_ICVC_volume_grad_cervical->clear();

    MRI_label_heart_rate_cerebral->clear();
    MRI_label_arterial_min_cerebral->clear();
    MRI_label_arterial_max_cerebral->clear();
    MRI_label_arterial_mean_cerebral->clear();
    MRI_label_arterial_grad_cerebral->clear();
    MRI_label_arterial_stroke_cerebral->clear();
    MRI_label_venous_corr_cerebral->clear();
    MRI_label_venous_min_cerebral->clear();
    MRI_label_venous_max_cerebral->clear();
    MRI_label_venous_mean_cerebral->clear();
    MRI_label_venous_grad_cerebral->clear();
    MRI_label_venous_stroke_cerebral->clear();
    MRI_label_venous_corr_min_cerebral->clear();
    MRI_label_venous_corr_max_cerebral->clear();
    MRI_label_venous_corr_mean_cerebral->clear();
    MRI_label_venous_corr_grad_cerebral->clear();
    MRI_label_venous_corr_stroke_cerebral->clear();
    MRI_label_csf_corr_cerebral->clear();
    MRI_label_csf_heart_rate_cerebral->clear();
    MRI_label_csf_min_cerebral->clear();
    MRI_label_csf_max_cerebral->clear();
    MRI_label_csf_mean_cerebral->clear();
    MRI_label_csf_grad_cerebral->clear();
    MRI_label_csf_stroke_cerebral->clear();
    MRI_label_csf_corr_min_cerebral->clear();
    MRI_label_csf_corr_max_cerebral->clear();
    MRI_label_csf_corr_mean_cerebral->clear();
    MRI_label_csf_corr_grad_cerebral->clear();
    MRI_label_csf_corr_stroke_cerebral->clear();
    MRI_label_AV_ICVC_ratio_cerebral->clear();
    MRI_label_AV_flow_min_cerebral->clear();
    MRI_label_AV_flow_max_cerebral->clear();
    MRI_label_AV_flow_mean_cerebral->clear();
    MRI_label_AV_flow_grad_cerebral->clear();
    MRI_label_AV_flow_stroke_cerebral->clear();
    MRI_label_AV_volume_min_cerebral->clear();
    MRI_label_AV_volume_max_cerebral->clear();
    MRI_label_AV_volume_mean_cerebral->clear();
    MRI_label_AV_volume_grad_cerebral->clear();
    MRI_label_ICVC_flow_min_cerebral->clear();
    MRI_label_ICVC_flow_max_cerebral->clear();
    MRI_label_ICVC_flow_mean_cerebral->clear();
    MRI_label_ICVC_flow_grad_cerebral->clear();
    MRI_label_ICVC_flow_stroke_cerebral->clear();
    MRI_label_ICVC_volume_min_cerebral->clear();
    MRI_label_ICVC_volume_max_cerebral->clear();
    MRI_label_ICVC_volume_mean_cerebral->clear();
    MRI_label_ICVC_volume_grad_cerebral->clear();

    MRI_label_arterial_dphi->clear();
    MRI_label_venous_dphi->clear();
    MRI_label_csf_dphi->clear();
    MRI_label_AV_flow_dphi->clear();
    MRI_label_AV_volume_dphi->clear();
    MRI_label_ICVC_flow_dphi->clear();
    MRI_label_ICVC_volume_dphi->clear();

    MRI_label_heart_rate_others->clear();
    MRI_label_arterial_min_others->clear();
    MRI_label_arterial_max_others->clear();
    MRI_label_arterial_mean_others->clear();
    MRI_label_arterial_grad_others->clear();
    MRI_label_arterial_stroke_others->clear();
    MRI_label_venous_min_others->clear();
    MRI_label_venous_max_others->clear();
    MRI_label_venous_mean_others->clear();
    MRI_label_venous_grad_others->clear();
    MRI_label_venous_stroke_others->clear();
    MRI_label_csf_min_others->clear();
    MRI_label_csf_max_others->clear();
    MRI_label_csf_mean_others->clear();
    MRI_label_csf_grad_others->clear();
    MRI_label_csf_stroke_others->clear();

    //String
    MRI_arterial_files_cervical->clear();
    MRI_arterial_files_cerebral->clear();
    MRI_venous_files_cervical->clear();
    MRI_venous_files_cerebral->clear();
    MRI_CSF_files_cervical->clear();
    MRI_CSF_files_cerebral->clear();
    MRI_arterial_files_other->clear();
    MRI_venous_files_other->clear();
    MRI_csf_files_other->clear();

    //Int
    MRI_number_arterial = 0;
    MRI_number_venous = 0;
    MRI_number_csf = 0;

    MRI_quality_arterial_cervical = QUALITY5;
    MRI_quality_venous_cervical = QUALITY5;
    MRI_quality_csf_cervical = QUALITY5;
    MRI_quality_arterial_cerebral = QUALITY5;
    MRI_quality_venous_cerebral = QUALITY5;
    MRI_quality_csf_cerebral = QUALITY5;
    if (MRI_quality_arterial_other != NULL) delete[] MRI_quality_arterial_other; MRI_quality_arterial_other = NULL;
    if (MRI_quality_venous_other != NULL) delete[] MRI_quality_venous_other; MRI_quality_venous_other = NULL;
    if (MRI_quality_csf_other != NULL) delete[] MRI_quality_csf_other; MRI_quality_csf_other = NULL;
}
//***********//
//***********//


void MainWindow::do_MRI_AV_flow_volume_cervical(int pos){
    if (pos == 0 || pos == 1) plot_MRI_AV_cervical();
}

void MainWindow::do_MRI_ICVC_flow_volume_cervical(int pos){
    if (pos == 0 || pos == 1) plot_MRI_ICVC_cervical();
}

void MainWindow::do_MRI_AV_flow_volume_cerebral(int pos){
    if (pos == 0 || pos == 1) plot_MRI_AV_cerebral();
}

void MainWindow::do_MRI_ICVC_flow_volume_cerebral(int pos){
    if (pos == 0 || pos == 1) plot_MRI_ICVC_cerebral();
}


