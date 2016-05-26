/****************************************************************************
**  This is a part of MRiCP                                                **
**  Copyright (C) 2016  Simon Garnotel                                     **
**                                                                         **
**  This program is free software: you can redistribute it and/or modify   **
**  it under the terms of the GNU General Public License as published by   **
**  the Free Software Foundation, either version 3 of the License, or      **
**  (at your option) any later version.                                    **
**                                                                         **
**  This program is distributed in the hope that it will be useful,        **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**  GNU General Public License for more details.                           **
**                                                                         **
**  You should have received a copy of the GNU General Public License      **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.  **
**                                                                         **
** **************************************************************************
**                                                                         **
** Author: Simon Garnotel                                                  **
** Contact: simon.garnotel@gmail.com                                       **
** Date: 05/2016                                                           **
** Version: 1.0                                                            **
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "headers.h"
#include "dialogsettings.h"
#include "dialogflowlocation.h"
#include "dialogimportflowexplorer.h"
#include "dialogexportdata.h"
#include "dialogexportreport.h"

#define DOUBLETOINT 100

#define FOURIER_XMIN_VIEW   0.2
#define FOURIER_XMAX_VIEW   2.

#define FOURIER_ROI_RANGE   0.1

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    //GLOBAL
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void module_PATIENT();
    void module_MRI();
    void module_ICP();
    void module_EPI();
    void module_COMPLIANCE();
    void module_TRANSFERTFUNCTION();
    void module_STATISTICS();

    bool action_import_Flow_eXplorer();
    bool action_export_data();
    bool action_export_report();

    void settings();

    void statusbar_show_message(QString message);
    void statusbar_show_warning(QString message);
    void statusbar_show_critical(QString message);

    void aboutQt();
    void aboutMRiCP();

    void quit();

    void resizeEvent(QResizeEvent *);


    //PATIENT
    void PATIENT__init_var();
    void PATIENT__init_win();
    void PATIENT__init_sig();
    void PATIENT__init_css();

    bool PATIENT__load();
    bool PATIENT__save();

    void PATIENT__do_calendar_birth_date(QDate date);
    bool PATIENT__do_lineedit_birth_date(QString date_str);

    bool PATIENT__do_add_pathology();


    //MRI
    void MRI__init_var();
    void MRI__init_win();
    void MRI__init_sig();
    void MRI__init_css();

    bool MRI__load();
    bool MRI__load(const QString DirName);
    bool MRI__save();

    //spinal
    void MRI__init_var_spinal();
    void MRI__init_win_spinal();
    void MRI__init_sig_spinal();
    void MRI__init_css_spinal();

    bool MRI__do_plot_arterial_spinal();
    bool MRI__do_plot_venous_spinal();
    bool MRI__do_plot_csf_spinal();
    bool MRI__do_plot_systole_spinal();

    bool MRI__do_smooth_arterial_spinal();
    bool MRI__do_smooth_venous_spinal();
    bool MRI__do_smooth_csf_spinal();

    bool MRI__do_move_right_arterial_spinal();
    bool MRI__do_move_right_venous_spinal();
    bool MRI__do_move_right_csf_spinal();

    bool MRI__do_move_left_arterial_spinal();
    bool MRI__do_move_left_venous_spinal();
    bool MRI__do_move_left_csf_spinal();

    bool MRI__do_print_arterial_spinal();
    bool MRI__do_print_venous_spinal();
    bool MRI__do_print_csf_spinal();
    bool MRI__do_print_arteriovenous_spinal();
    bool MRI__do_print_arteriovenouscsf_spinal();

    bool MRI__do_detect_systole_spinal();
    bool MRI__do_adjust_systole_spinal();
    bool MRI__do_ncycles_spinal(QAction *action);
    bool MRI__do_legend_spinal();

    bool MRI__do_venous_spinal();
    bool MRI__do_csf_spinal();

    bool MRI__do_arteriovenous_spinal();
    bool MRI__do_arteriovenous_auto_spinal();
    bool MRI__do_arteriovenouscsf_spinal();
    bool MRI__do_arteriovenouscsf_auto_spinal();

    bool MRI__do_plot_arteriovenous_spinal();
    bool MRI__do_plot_arteriovenouscsf_spinal();

    //intracranial
    void MRI__init_var_intracranial();
    void MRI__init_win_intracranial();
    void MRI__init_sig_intracranial();
    void MRI__init_css_intracranial();

    bool MRI__do_plot_arterial_intracranial();
    bool MRI__do_plot_venous_intracranial();
    bool MRI__do_plot_csf_intracranial();
    bool MRI__do_plot_systole_intracranial();

    bool MRI__do_smooth_arterial_intracranial();
    bool MRI__do_smooth_venous_intracranial();
    bool MRI__do_smooth_csf_intracranial();

    bool MRI__do_move_right_arterial_intracranial();
    bool MRI__do_move_right_venous_intracranial();
    bool MRI__do_move_right_csf_intracranial();

    bool MRI__do_move_left_arterial_intracranial();
    bool MRI__do_move_left_venous_intracranial();
    bool MRI__do_move_left_csf_intracranial();

    bool MRI__do_print_arterial_intracranial();
    bool MRI__do_print_venous_intracranial();
    bool MRI__do_print_csf_intracranial();
    bool MRI__do_print_arteriovenous_intracranial();
    bool MRI__do_print_arteriovenouscsf_intracranial();

    bool MRI__do_detect_systole_intracranial();
    bool MRI__do_adjust_systole_intracranial();
    bool MRI__do_ncycles_intracranial(QAction *action);
    bool MRI__do_legend_intracranial();

    bool MRI__do_venous_intracranial();
    bool MRI__do_csf_intracranial();

    bool MRI__do_arteriovenous_intracranial();
    bool MRI__do_arteriovenous_auto_intracranial();
    bool MRI__do_arteriovenouscsf_intracranial();
    bool MRI__do_arteriovenouscsf_auto_intracranial();

    bool MRI__do_plot_arteriovenous_intracranial();
    bool MRI__do_plot_arteriovenouscsf_intracranial();

    //spinal/intracranial
    void MRI__init_var_spinal_intracranial();
    void MRI__init_win_spinal_intracranial();
    void MRI__init_sig_spinal_intracranial();
    void MRI__init_css_spinal_intracranial();

    bool MRI__do_plot_arterial_spinal_intracranial();
    bool MRI__do_plot_venous_spinal_intracranial();
    bool MRI__do_plot_csf_spinal_intracranial();
    bool MRI__do_plot_arteriovenous_flow_spinal_intracranial();
    bool MRI__do_plot_arteriovenous_volume_spinal_intracranial();
    bool MRI__do_plot_arteriovenouscsf_flow_spinal_intracranial();
    bool MRI__do_plot_arteriovenouscsf_volume_spinal_intracranial();

    bool MRI__do_ncycles_spinal_intracranial(QAction *action);
    bool MRI__do_legend_spinal_intracranial();

    //spectrum
    bool MRI__do_plot_arterial_spectrum();
    bool MRI__do_plot_venous_spectrum();
    bool MRI__do_plot_csf_spectrum();
    bool MRI__do_plot_arteriovenous_flow_spectrum();
    bool MRI__do_plot_arteriovenous_volume_spectrum();
    bool MRI__do_plot_arteriovenouscsf_flow_spectrum();
    bool MRI__do_plot_arteriovenouscsf_volume_spectrum();

    bool MRI__do_legend_spectrum();

    //all
    bool MRI__do_plot_arterial_all();
    bool MRI__do_plot_venous_all();
    bool MRI__do_plot_csf_all();
    bool MRI__do_plot_undefined_all();


    //ICP
    void ICP__init_var();
    void ICP__init_win();
    void ICP__init_sig();
    void ICP__init_css();

    bool ICP__load();
    bool ICP__load(const QString DirName);
    bool ICP__save();

    void ICP__do_show_basal();
    void ICP__do_show_plateau();

    void ICP__do_mouse_press_signal(QMouseEvent *m_event);
    void ICP__do_mouse_move_signal(QMouseEvent *m_event);
    void ICP__do_mouse_release_signal(QMouseEvent *m_event);

    bool ICP__do_plot_signal();
    bool ICP__do_plot_signal_basal();
    bool ICP__do_plot_signal_plateau();

    bool ICP__do_plot_selection_basal();
    bool ICP__do_plot_selection_plateau();

    bool ICP__do_FFT_basal();
    bool ICP__do_FFT_plateau();

    bool ICP__do_plot_FFT_basal();
    bool ICP__do_plot_FFT_plateau();

    bool ICP__do_plot_FFT_ROI_basal();
    bool ICP__do_plot_FFT_ROI_plateau();

    bool ICP__do_FFT_ROI_basal();
    bool ICP__do_FFT_ROI_plateau();

    bool ICP__do_IFFT_basal();
    bool ICP__do_IFFT_plateau();

    bool ICP__do_plot_IFFT_basal();
    bool ICP__do_plot_IFFT_plateau();

    bool ICP__do_plot_thresold_basal();
    bool ICP__do_plot_thresold_plateau();

    bool ICP__do_peak_basal();
    bool ICP__do_peak_plateau();

    bool ICP__do_plot_peak_basal();
    bool ICP__do_plot_peak_plateau();

    bool ICP__do_mean_basal();
    bool ICP__do_mean_plateau();

    bool ICP__do_plot_mean_basal();
    bool ICP__do_plot_mean_plateau();

    bool ICP__do_print_mean_basal();
    bool ICP__do_print_mean_plateau();

    bool ICP__do_auto();

    bool ICP__do_adjust_basal();
    bool ICP__do_adjust_plateau();


    //EPI
    void EPI__init_var();
    void EPI__init_win();
    void EPI__init_sig();
    void EPI__init_css();

    bool EPI__load();
    bool EPI__load(const QString DirName);
    bool EPI__save();


    //COMPLIANCE
    void COMPLIANCE__init_var();
    void COMPLIANCE__init_win();
    void COMPLIANCE__init_sig();
    void COMPLIANCE__init_css();

    bool COMPLIANCE__load(const QString DirName);
    bool COMPLIANCE__save();

    bool COMPLIANCE__do_plot_arteriovenous_volume_spinal();
    bool COMPLIANCE__do_plot_arteriovenouscsf_volume_spinal();
    bool COMPLIANCE__do_plot_arteriovenous_volume_intracranial();
    bool COMPLIANCE__do_plot_arteriovenouscsf_volume_intracranial();
    bool COMPLIANCE__do_plot_icp_basal();
    bool COMPLIANCE__do_plot_icp_plateau();

    bool COMPLIANCE__do_compliance();


    //TRANSFERTFUNCTION
    void TRANSFERTFUNCTION__init_var();
    void TRANSFERTFUNCTION__init_win();
    void TRANSFERTFUNCTION__init_sig();
    void TRANSFERTFUNCTION__init_css();

    bool TRANSFERTFUNCTION__load(const QString DirName);
    bool TRANSFERTFUNCTION__save();

    bool TRANSFERTFUNCTION__do_plot_arteriovenous_volume_spinal();
    bool TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_spinal();
    bool TRANSFERTFUNCTION__do_plot_arteriovenous_volume_intracranial();
    bool TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_intracranial();
    bool TRANSFERTFUNCTION__do_plot_icp_basal();
    bool TRANSFERTFUNCTION__do_plot_icp_plateau();
    bool TRANSFERTFUNCTION__do_plot_transfert_function();

    bool TRANSFERTFUNCTION__do_transfert_function();


    //STATISTICS
    void STATISTICS__init_var();
    void STATISTICS__init_win();
    void STATISTICS__init_sig();
    void STATISTICS__init_css();

    bool STATISTICS__do_load();
    void STATISTICS__do_combobox(const QStringList Items);
    bool STATISTICS__do_make_group();
    bool STATISTICS__do_remove();

    bool STATISTICS__do_plot();

    bool STATISTICS__do_regression();
    bool STATISTICS__do_clustering();
    bool STATISTICS__do_export();

private:
    //GLOBAL
    //Menu
    QMenu *menu_file;
    QMenu *menu_modules;
    QMenu *menu_actions;
    QMenu *menu_edit;
    QMenu *menu_help;

    QMenu *menu_file_load;

    //Action
    QAction *action_file_load_PATIENT;
    QAction *action_file_load_MRI;
    QAction *action_file_load_ICP;
    QAction *action_file_load_EPI;
    QAction *action_file_save_PATIENT;
    QAction *action_file_quit;

    QAction *action_module_PATIENT;
    QAction *action_module_MRI;
    QAction *action_module_ICP;
    QAction *action_module_EPI;
    QAction *action_module_COMPLIANCE;
    QAction *action_module_TRANSFERTFUNCTION;
    QAction *action_module_STATISTICS;

    QAction *action_action_import_Flow_eXplorer;
    QAction *action_action_export_data;
    QAction *action_action_export_report;

    QAction *action_edit_settings;

    QAction *action_help_user;
    QAction *action_help_about_Qt;
    QAction *action_help_about_MRiCP;

    //Toolbar
    QToolBar *toolbar_file;
    QToolBar *toolbar_module;
    QToolBar *toolbar_edit;
    QToolBar *toolbar_help;

    //Statusbar
    QStatusBar *statusbar;

    //ScrollArea
    QScrollArea *scrollarea_PATIENT;
    QScrollArea *scrollarea_MRI;
    QScrollArea *scrollarea_ICP;
    QScrollArea *scrollarea_EPI;
    QScrollArea *scrollarea_COMPLIANCE;
    QScrollArea *scrollarea_TRANSFERTFUNCTION;
    QScrollArea *scrollarea_STATISTICS;

    //Widget
    QStackedWidget *stacked_widget;

    QWidget *central_widget_PATIENT;
    QWidget *central_widget_MRI;
    QWidget *central_widget_ICP;
    QWidget *central_widget_EPI;
    QWidget *central_widget_COMPLIANCE;
    QWidget *central_widget_TRANSFERTFUNCTION;
    QWidget *central_widget_STATISTICS;

    QWidget *scrollwidget_PATIENT;
    QWidget *scrollwidget_MRI;
    QWidget *scrollwidget_ICP;
    QWidget *scrollwidget_EPI;
    QWidget *scrollwidget_COMPLIANCE;
    QWidget *scrollwidget_TRANSFERTFUNCTION;
    QWidget *scrollwidget_STATISTICS;

    //Grid
    QGridLayout *grid_PATIENT;
    QGridLayout *grid_MRI;
    QGridLayout *grid_ICP;
    QGridLayout *grid_EPI;
    QGridLayout *grid_COMPLIANCE;
    QGridLayout *grid_TRANSFERTFUNCTION;
    QGridLayout *grid_STATISTICS;

    //VBox
    QVBoxLayout *vbox_PATIENT;
    QVBoxLayout *vbox_MRI;
    QVBoxLayout *vbox_ICP;
    QVBoxLayout *vbox_EPI;
    QVBoxLayout *vbox_COMPLIANCE;
    QVBoxLayout *vbox_TRANSFERTFUNCTION;
    QVBoxLayout *vbox_STATISTICS;


    //PATIENT
    //Label
    QLabel *PATIENT__label_name;
    QLabel *PATIENT__label_birth_date;
    QLabel *PATIENT__label_age;
    QLabel *PATIENT__label_sexe;
    QLabel *PATIENT__label_pathology;
    QLabel *PATIENT__label_MRI;
    QLabel *PATIENT__label_ICP;
    QLabel *PATIENT__label_EPI;

    //Text
    QLineEdit *PATIENT__lineedit_name;
    QLineEdit *PATIENT__lineedit_birth_date;

    QTextEdit *PATIENT__textedit_MRI;
    QTextEdit *PATIENT__textedit_ICP;
    QTextEdit *PATIENT__textedit_EPI;

    //SpinBox
    QSpinBox *PATIENT__spinbox_age;

    //ComboBox
    QComboBox *PATIENT__combobox_pathology;

    //Calendar
    QCalendarWidget *PATIENT__calendar_birth_date;

    //RadioButton
    QButtonGroup *PATIENT__radiobutton_group;
    QRadioButton *PATIENT__radiobutton_sexe_M;
    QRadioButton *PATIENT__radiobutton_sexe_F;

    //Button
    QPushButton *PATIENT__button_pathology;


    //MRI
    //Methods
    //spectrum
    void MRI__init_var_spectrum();
    void MRI__init_win_spectrum();
    void MRI__init_sig_spectrum();
    void MRI__init_css_spectrum();

    bool DoSpectrum(QVector<double> *SpectrumX, QVector<double> *SpectrumY,
                    const QVector<double> *X, const QVector<double> *Y,
                    const QVector<double> *SpectrumXO,
                    QDoubleSpinBox *Down, QDoubleSpinBox *Up,
                    bool (MainWindow::*PlotFunction)(),
                    const QString StatusText);
    bool PlotSpectrum(const QVector<double> *XS, const QVector<double> *YS,
                      const QVector<double> *XI, const QVector<double> *YI,
                      const QDoubleSpinBox *Down, const QDoubleSpinBox *Up,
                      QCustomPlot *Plot,
                      const QString StatusText);

    bool MRI__do_arterial_spinal_spectrum();
    bool MRI__do_venous_spinal_spectrum();
    bool MRI__do_csf_spinal_spectrum();
    bool MRI__do_arteriovenous_flow_spinal_spectrum();
    bool MRI__do_arteriovenous_volume_spinal_spectrum();
    bool MRI__do_arteriovenouscsf_flow_spinal_spectrum();
    bool MRI__do_arteriovenouscsf_volume_spinal_spectrum();
    bool MRI__do_arterial_intracranial_spectrum();
    bool MRI__do_venous_intracranial_spectrum();
    bool MRI__do_csf_intracranial_spectrum();
    bool MRI__do_arteriovenous_flow_intracranial_spectrum();
    bool MRI__do_arteriovenous_volume_intracranial_spectrum();
    bool MRI__do_arteriovenouscsf_flow_intracranial_spectrum();
    bool MRI__do_arteriovenouscsf_volume_intracranial_spectrum();

    //all
    void MRI__init_var_all();
    void MRI__init_win_all();
    void MRI__init_sig_all();
    void MRI__init_css_all();

    bool MRI__do_plot_all(QMenu *Menu, QCustomPlot *Plot,
                          QVector<double> **VectorX, QVector<double> **VectorY,
                          bool (MainWindow::*PrintFunction)(int), bool (MainWindow::*ImageFunction)(int),
                          QString StatusText);

    bool MRI__do_print_all(QLabel *LabelHeartRate, QLabel *LabelMin, QLabel *LabelMax, QLabel *LabelMean, QLabel *LabelAmplitude, QLabel *LabelStrokeVolume,
                           QVector<double> *VectorX, QVector<double> *VectorY,
                           QString StatusText,
                           int k);
    bool MRI__do_print_arterial_all(int k);
    bool MRI__do_print_venous_all(int k);
    bool MRI__do_print_csf_all(int k);
    bool MRI__do_print_undefined_all(int k);

    bool MRI__do_image_all(QLabel *Label,
                           QVector<QString> *Vector,
                           QString StatusText,
                           int k);
    bool MRI__do_image_arterial_all(int k);
    bool MRI__do_image_venous_all(int k);
    bool MRI__do_image_csf_all(int k);
    bool MRI__do_image_undefined_all(int k);

    //Menu
    QMenu *MRI__menu_ncycles_spinal;
    QMenu *MRI__menu_ncycles_intracranial;
    QMenu *MRI__menu_ncycles_spinal_intracranial;
    QMenu *MRI__menu_arterial_all;
    QMenu *MRI__menu_venous_all;
    QMenu *MRI__menu_csf_all;
    QMenu *MRI__menu_undefined_all;

    //Tab
    QTabWidget *MRI__tab;

    //Widget
    QWidget *MRI__widget_tab_spinal;
    QWidget *MRI__widget_tab_intracranial;
    QWidget *MRI__widget_tab_spinal_intracranial;
    QWidget *MRI__widget_tab_spectrum;
    QWidget *MRI__widget_tab_all;

    //Grid
    QGridLayout *MRI__grid_spinal;
    QGridLayout *MRI__grid_intracranial;
    QGridLayout *MRI__grid_spinal_intracranial;
    QGridLayout *MRI__grid_spectrum;
    QGridLayout *MRI__grid_all;

    //VBox
    QVBoxLayout *MRI__vbox_arterial_button_spinal;
    QVBoxLayout *MRI__vbox_arterial_spinal;
    QVBoxLayout *MRI__vbox_venous_button_spinal;
    QVBoxLayout *MRI__vbox_venous_spinal;
    QVBoxLayout *MRI__vbox_csf_button_spinal;
    QVBoxLayout *MRI__vbox_csf_spinal;
    QVBoxLayout *MRI__vbox_arteriovenous_spinal;
    QVBoxLayout *MRI__vbox_arteriovenouscsf_spinal;

    QVBoxLayout *MRI__vbox_arterial_button_intracranial;
    QVBoxLayout *MRI__vbox_arterial_intracranial;
    QVBoxLayout *MRI__vbox_venous_button_intracranial;
    QVBoxLayout *MRI__vbox_venous_intracranial;
    QVBoxLayout *MRI__vbox_csf_button_intracranial;
    QVBoxLayout *MRI__vbox_csf_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenous_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenouscsf_intracranial;

    QVBoxLayout *MRI__vbox_arterial_spinal_intracranial;
    QVBoxLayout *MRI__vbox_venous_spinal_intracranial;
    QVBoxLayout *MRI__vbox_csf_spinal_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenous_flow_spinal_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenous_volume_spinal_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenouscsf_flow_spinal_intracranial;
    QVBoxLayout *MRI__vbox_arteriovenouscsf_volume_spinal_intracranial;

    QVBoxLayout *MRI__vbox_arterial_all;
    QVBoxLayout *MRI__vbox_venous_all;
    QVBoxLayout *MRI__vbox_csf_all;
    QVBoxLayout *MRI__vbox_undefined_all;
    QVBoxLayout *MRI__vbox_image_arterial_all;
    QVBoxLayout *MRI__vbox_image_venous_all;
    QVBoxLayout *MRI__vbox_image_csf_all;
    QVBoxLayout *MRI__vbox_image_undefined_all;

    //HBox
    QHBoxLayout *MRI__hbox_arterial_spinal;
    QHBoxLayout *MRI__hbox_venous_spinal;
    QHBoxLayout *MRI__hbox_csf_spinal;
    QHBoxLayout *MRI__hbox_arteriovenous_spinal;
    QHBoxLayout *MRI__hbox_arteriovenouscsf_spinal;

    QHBoxLayout *MRI__hbox_arterial_intracranial;
    QHBoxLayout *MRI__hbox_venous_intracranial;
    QHBoxLayout *MRI__hbox_csf_intracranial;
    QHBoxLayout *MRI__hbox_arteriovenous_intracranial;
    QHBoxLayout *MRI__hbox_arteriovenouscsf_intracranial;

    QHBoxLayout *MRI__hbox_button_spinal_intracranial;

    QHBoxLayout *MRI__hbox_arterial_spectrum;
    QHBoxLayout *MRI__hbox_venous_spectrum;
    QHBoxLayout *MRI__hbox_csf_spectrum;
    QHBoxLayout *MRI__hbox_arteriovenous_flow_spectrum;
    QHBoxLayout *MRI__hbox_arteriovenous_volume_spectrum;
    QHBoxLayout *MRI__hbox_arteriovenouscsf_flow_spectrum;
    QHBoxLayout *MRI__hbox_arteriovenouscsf_volume_spectrum;

    QHBoxLayout *MRI__hbox_arterial_all;
    QHBoxLayout *MRI__hbox_venous_all;
    QHBoxLayout *MRI__hbox_csf_all;
    QHBoxLayout *MRI__hbox_undefined_all;

    //Plot
    QCustomPlot *MRI__plot_arterial_spinal;
    QCustomPlot *MRI__plot_venous_spinal;
    QCustomPlot *MRI__plot_csf_spinal;
    QCustomPlot *MRI__plot_arteriovenous_spinal;
    QCustomPlot *MRI__plot_arteriovenouscsf_spinal;

    QCustomPlot *MRI__plot_arterial_intracranial;
    QCustomPlot *MRI__plot_venous_intracranial;
    QCustomPlot *MRI__plot_csf_intracranial;
    QCustomPlot *MRI__plot_arteriovenous_intracranial;
    QCustomPlot *MRI__plot_arteriovenouscsf_intracranial;

    QCustomPlot *MRI__plot_arterial_spinal_intracranial;
    QCustomPlot *MRI__plot_venous_spinal_intracranial;
    QCustomPlot *MRI__plot_csf_spinal_intracranial;
    QCustomPlot *MRI__plot_arteriovenous_flow_spinal_intracranial;
    QCustomPlot *MRI__plot_arteriovenous_volume_spinal_intracranial;
    QCustomPlot *MRI__plot_arteriovenouscsf_flow_spinal_intracranial;
    QCustomPlot *MRI__plot_arteriovenouscsf_volume_spinal_intracranial;

    QCustomPlot *MRI__plot_arterial_spectrum;
    QCustomPlot *MRI__plot_venous_spectrum;
    QCustomPlot *MRI__plot_csf_spectrum;
    QCustomPlot *MRI__plot_arteriovenous_flow_spectrum;
    QCustomPlot *MRI__plot_arteriovenous_volume_spectrum;
    QCustomPlot *MRI__plot_arteriovenouscsf_flow_spectrum;
    QCustomPlot *MRI__plot_arteriovenouscsf_volume_spectrum;

    QCustomPlot *MRI__plot_arterial_all;
    QCustomPlot *MRI__plot_venous_all;
    QCustomPlot *MRI__plot_csf_all;
    QCustomPlot *MRI__plot_undefined_all;

    //Label
    QLabel *MRI__label_venous_spinal;
    QLabel *MRI__label_csf_spinal;
    QLabel *MRI__label_arterial_quality_spinal;
    QLabel *MRI__label_arterial_heart_rate_spinal;
    QLabel *MRI__label_arterial_min_spinal;
    QLabel *MRI__label_arterial_max_spinal;
    QLabel *MRI__label_arterial_mean_spinal;
    QLabel *MRI__label_arterial_amplitude_spinal;
    QLabel *MRI__label_arterial_stroke_volume_spinal;
    QLabel *MRI__label_venous_quality_spinal;
    QLabel *MRI__label_venous_min_spinal;
    QLabel *MRI__label_venous_max_spinal;
    QLabel *MRI__label_venous_mean_spinal;
    QLabel *MRI__label_venous_amplitude_spinal;
    QLabel *MRI__label_venous_stroke_volume_spinal;
    QLabel *MRI__label_csf_quality_spinal;
    QLabel *MRI__label_csf_heart_rate_spinal;
    QLabel *MRI__label_csf_min_spinal;
    QLabel *MRI__label_csf_max_spinal;
    QLabel *MRI__label_csf_mean_spinal;
    QLabel *MRI__label_csf_amplitude_spinal;
    QLabel *MRI__label_csf_stroke_volume_spinal;
    QLabel *MRI__label_arteriovenous_min_spinal;
    QLabel *MRI__label_arteriovenous_max_spinal;
    QLabel *MRI__label_arteriovenous_mean_spinal;
    QLabel *MRI__label_arteriovenous_amplitude_spinal;
    QLabel *MRI__label_arteriovenous_stroke_volume_spinal;
    QLabel *MRI__label_arteriovenouscsf_min_spinal;
    QLabel *MRI__label_arteriovenouscsf_max_spinal;
    QLabel *MRI__label_arteriovenouscsf_mean_spinal;
    QLabel *MRI__label_arteriovenouscsf_amplitude_spinal;
    QLabel *MRI__label_arteriovenouscsf_stroke_volume_spinal;

    QLabel *MRI__label_venous_intracranial;
    QLabel *MRI__label_csf_intracranial;
    QLabel *MRI__label_arterial_quality_intracranial;
    QLabel *MRI__label_arterial_heart_rate_intracranial;
    QLabel *MRI__label_arterial_min_intracranial;
    QLabel *MRI__label_arterial_max_intracranial;
    QLabel *MRI__label_arterial_mean_intracranial;
    QLabel *MRI__label_arterial_amplitude_intracranial;
    QLabel *MRI__label_arterial_stroke_volume_intracranial;
    QLabel *MRI__label_venous_quality_intracranial;
    QLabel *MRI__label_venous_min_intracranial;
    QLabel *MRI__label_venous_max_intracranial;
    QLabel *MRI__label_venous_mean_intracranial;
    QLabel *MRI__label_venous_amplitude_intracranial;
    QLabel *MRI__label_venous_stroke_volume_intracranial;
    QLabel *MRI__label_csf_quality_intracranial;
    QLabel *MRI__label_csf_heart_rate_intracranial;
    QLabel *MRI__label_csf_min_intracranial;
    QLabel *MRI__label_csf_max_intracranial;
    QLabel *MRI__label_csf_mean_intracranial;
    QLabel *MRI__label_csf_amplitude_intracranial;
    QLabel *MRI__label_csf_stroke_volume_intracranial;
    QLabel *MRI__label_arteriovenous_min_intracranial;
    QLabel *MRI__label_arteriovenous_max_intracranial;
    QLabel *MRI__label_arteriovenous_mean_intracranial;
    QLabel *MRI__label_arteriovenous_amplitude_intracranial;
    QLabel *MRI__label_arteriovenous_stroke_volume_intracranial;
    QLabel *MRI__label_arteriovenouscsf_min_intracranial;
    QLabel *MRI__label_arteriovenouscsf_max_intracranial;
    QLabel *MRI__label_arteriovenouscsf_mean_intracranial;
    QLabel *MRI__label_arteriovenouscsf_amplitude_intracranial;
    QLabel *MRI__label_arteriovenouscsf_stroke_volume_intracranial;

    QLabel *MRI__label_arterial_phase_shift_spinal_intracranial;
    QLabel *MRI__label_venous_phase_shift_spinal_intracranial;
    QLabel *MRI__label_csf_phase_shift_spinal_intracranial;
    QLabel *MRI__label_arteriovenous_flow_phase_shift_spinal_intracranial;
    QLabel *MRI__label_arteriovenous_volume_phase_shift_spinal_intracranial;
    QLabel *MRI__label_arteriovenouscsf_flow_phase_shift_spinal_intracranial;
    QLabel *MRI__label_arteriovenouscsf_volume_phase_shift_spinal_intracranial;

    QLabel *MRI__label_arterial_spectrum;
    QLabel *MRI__label_venous_spectrum;
    QLabel *MRI__label_csf_spectrum;
    QLabel *MRI__label_arteriovenous_flow_spectrum;
    QLabel *MRI__label_arteriovenous_volume_spectrum;
    QLabel *MRI__label_arteriovenouscsf_flow_spectrum;
    QLabel *MRI__label_arteriovenouscsf_volume_spectrum;

    QLabel *MRI__label_arterial_heart_rate_all;
    QLabel *MRI__label_arterial_min_all;
    QLabel *MRI__label_arterial_max_all;
    QLabel *MRI__label_arterial_mean_all;
    QLabel *MRI__label_arterial_amplitude_all;
    QLabel *MRI__label_arterial_stroke_volume_all;
    QLabel *MRI__label_venous_heart_rate_all;
    QLabel *MRI__label_venous_min_all;
    QLabel *MRI__label_venous_max_all;
    QLabel *MRI__label_venous_mean_all;
    QLabel *MRI__label_venous_amplitude_all;
    QLabel *MRI__label_venous_stroke_volume_all;
    QLabel *MRI__label_csf_heart_rate_all;
    QLabel *MRI__label_csf_min_all;
    QLabel *MRI__label_csf_max_all;
    QLabel *MRI__label_csf_mean_all;
    QLabel *MRI__label_csf_amplitude_all;
    QLabel *MRI__label_csf_stroke_volume_all;
    QLabel *MRI__label_undefined_heart_rate_all;
    QLabel *MRI__label_undefined_min_all;
    QLabel *MRI__label_undefined_max_all;
    QLabel *MRI__label_undefined_mean_all;
    QLabel *MRI__label_undefined_amplitude_all;
    QLabel *MRI__label_undefined_stroke_volume_all;
    QLabel *MRI__label_image_arterial_all;
    QLabel *MRI__label_image_venous_all;
    QLabel *MRI__label_image_csf_all;
    QLabel *MRI__label_image_undefined_all;

    //SpinBox
    QSpinBox *MRI__spinbox_arterial_quality_spinal;
    QSpinBox *MRI__spinbox_venous_quality_spinal;
    QSpinBox *MRI__spinbox_csf_quality_spinal;

    QDoubleSpinBox *MRI__doublespinbox_systole_threshold_spinal;

    QSpinBox *MRI__spinbox_arterial_quality_intracranial;
    QSpinBox *MRI__spinbox_venous_quality_intracranial;
    QSpinBox *MRI__spinbox_csf_quality_intracranial;

    QDoubleSpinBox *MRI__doublespinbox_systole_threshold_intracranial;

    QDoubleSpinBox *MRI__doublespinbox_arterial_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arterial_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_venous_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_venous_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_csf_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_csf_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenous_flow_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenous_flow_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenous_volume_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenous_volume_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum;
    QDoubleSpinBox *MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum;

    //ComboBox
    QComboBox *MRI__combobox_flow_volume_arteriovenous_spinal;
    QComboBox *MRI__combobox_flow_volume_arteriovenouscsf_spinal;

    QComboBox *MRI__combobox_flow_volume_arteriovenous_intracranial;
    QComboBox *MRI__combobox_flow_volume_arteriovenouscsf_intracranial;

    //Button
    QPushButton *MRI__button_detect_systole_spinal;
    QPushButton *MRI__button_adjust_systole_spinal;
    QPushButton *MRI__button_hide_systole_spinal;
    QPushButton *MRI__button_plot_00_spinal;
    QPushButton *MRI__button_menu_ncycles_spinal;
    QPushButton *MRI__button_legend_spinal;
    QPushButton *MRI__button_venous_spinal;
    QPushButton *MRI__button_csf_spinal;
    QPushButton *MRI__button_arteriovenous_spinal;
    QPushButton *MRI__button_arteriovenous_auto_spinal;
    QPushButton *MRI__button_arteriovenouscsf_spinal;
    QPushButton *MRI__button_arteriovenouscsf_auto_spinal;
    QPushButton *MRI__button_restore_arterial_spinal;
    QPushButton *MRI__button_smooth_arterial_spinal;
    QPushButton *MRI__button_move_right_arterial_spinal;
    QPushButton *MRI__button_move_left_arterial_spinal;
    QPushButton *MRI__button_restore_venous_spinal;
    QPushButton *MRI__button_smooth_venous_spinal;
    QPushButton *MRI__button_move_right_venous_spinal;
    QPushButton *MRI__button_move_left_venous_spinal;
    QPushButton *MRI__button_show_up_venous_spinal;
    QPushButton *MRI__button_restore_csf_spinal;
    QPushButton *MRI__button_smooth_csf_spinal;
    QPushButton *MRI__button_move_right_csf_spinal;
    QPushButton *MRI__button_move_left_csf_spinal;

    QPushButton *MRI__button_detect_systole_intracranial;
    QPushButton *MRI__button_adjust_systole_intracranial;
    QPushButton *MRI__button_hide_systole_intracranial;
    QPushButton *MRI__button_plot_00_intracranial;
    QPushButton *MRI__button_menu_ncycles_intracranial;
    QPushButton *MRI__button_legend_intracranial;
    QPushButton *MRI__button_venous_intracranial;
    QPushButton *MRI__button_csf_intracranial;
    QPushButton *MRI__button_arteriovenous_intracranial;
    QPushButton *MRI__button_arteriovenous_auto_intracranial;
    QPushButton *MRI__button_arteriovenouscsf_intracranial;
    QPushButton *MRI__button_arteriovenouscsf_auto_intracranial;
    QPushButton *MRI__button_restore_arterial_intracranial;
    QPushButton *MRI__button_smooth_arterial_intracranial;
    QPushButton *MRI__button_move_right_arterial_intracranial;
    QPushButton *MRI__button_move_left_arterial_intracranial;
    QPushButton *MRI__button_restore_venous_intracranial;
    QPushButton *MRI__button_smooth_venous_intracranial;
    QPushButton *MRI__button_move_right_venous_intracranial;
    QPushButton *MRI__button_move_left_venous_intracranial;
    QPushButton *MRI__button_show_up_venous_intracranial;
    QPushButton *MRI__button_restore_csf_intracranial;
    QPushButton *MRI__button_smooth_csf_intracranial;
    QPushButton *MRI__button_move_right_csf_intracranial;
    QPushButton *MRI__button_move_left_csf_intracranial;

    QPushButton *MRI__button_plot_00_spinal_intracranial;
    QPushButton *MRI__button_menu_ncycles_spinal_intracranial;
    QPushButton *MRI__button_legend_spinal_intracranial;
    QPushButton *MRI__button_plot_all_spinal_intracranial;
    QPushButton *MRI__button_show_up_venous_spinal_intracranial;

    QPushButton *MRI__button_legend_spectrum;

    QPushButton *MRI__button_arterial_all;
    QPushButton *MRI__button_venous_all;
    QPushButton *MRI__button_csf_all;
    QPushButton *MRI__button_undefined_all;


    //Vector
    QVector<double> *MRI__vector_arterial_spinal_x;
    QVector<double> *MRI__vector_arterial_spinal_y;
    QVector<double> *MRI__vector_arterial_systole_spinal_x;
    QVector<double> *MRI__vector_arterial_systole_spinal_y;
    QVector<double> *MRI__vector_venous_spinal_x;
    QVector<double> *MRI__vector_venous_spinal_y;
    QVector<double> *MRI__vector_venous_corrected_spinal_y;
    QVector<double> *MRI__vector_csf_spinal_x;
    QVector<double> *MRI__vector_csf_spinal_y;
    QVector<double> *MRI__vector_csf_corrected_spinal_y;
    QVector<double> *MRI__vector_arteriovenous_flow_spinal_x;
    QVector<double> *MRI__vector_arteriovenous_flow_spinal_y;
    QVector<double> *MRI__vector_arteriovenous_volume_spinal_x;
    QVector<double> *MRI__vector_arteriovenous_volume_spinal_y;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_spinal_x;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_spinal_y;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_spinal_x;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_spinal_y;

    QVector<double> *MRI__vector_arterial_intracranial_x;
    QVector<double> *MRI__vector_arterial_intracranial_y;
    QVector<double> *MRI__vector_arterial_systole_intracranial_x;
    QVector<double> *MRI__vector_arterial_systole_intracranial_y;
    QVector<double> *MRI__vector_venous_intracranial_x;
    QVector<double> *MRI__vector_venous_intracranial_y;
    QVector<double> *MRI__vector_venous_corrected_intracranial_y;
    QVector<double> *MRI__vector_csf_intracranial_x;
    QVector<double> *MRI__vector_csf_intracranial_y;
    QVector<double> *MRI__vector_csf_corrected_intracranial_y;
    QVector<double> *MRI__vector_arteriovenous_flow_intracranial_x;
    QVector<double> *MRI__vector_arteriovenous_flow_intracranial_y;
    QVector<double> *MRI__vector_arteriovenous_volume_intracranial_x;
    QVector<double> *MRI__vector_arteriovenous_volume_intracranial_y;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_intracranial_x;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_intracranial_y;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_intracranial_x;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_intracranial_y;

    QVector<double> *MRI__vector_arterial_spinal_spectrum_x;
    QVector<double> *MRI__vector_arterial_spinal_spectrum_y;
    QVector<double> *MRI__vector_venous_spinal_spectrum_x;
    QVector<double> *MRI__vector_venous_spinal_spectrum_y;
    QVector<double> *MRI__vector_csf_spinal_spectrum_x;
    QVector<double> *MRI__vector_csf_spinal_spectrum_y;
    QVector<double> *MRI__vector_arteriovenous_flow_spinal_spectrum_x;
    QVector<double> *MRI__vector_arteriovenous_flow_spinal_spectrum_y;
    QVector<double> *MRI__vector_arteriovenous_volume_spinal_spectrum_x;
    QVector<double> *MRI__vector_arteriovenous_volume_spinal_spectrum_y;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_spinal_spectrum_x;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_spinal_spectrum_y;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_spinal_spectrum_x;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_spinal_spectrum_y;
    QVector<double> *MRI__vector_arterial_intracranial_spectrum_x;
    QVector<double> *MRI__vector_arterial_intracranial_spectrum_y;
    QVector<double> *MRI__vector_venous_intracranial_spectrum_x;
    QVector<double> *MRI__vector_venous_intracranial_spectrum_y;
    QVector<double> *MRI__vector_csf_intracranial_spectrum_x;
    QVector<double> *MRI__vector_csf_intracranial_spectrum_y;
    QVector<double> *MRI__vector_arteriovenous_flow_intracranial_spectrum_x;
    QVector<double> *MRI__vector_arteriovenous_flow_intracranial_spectrum_y;
    QVector<double> *MRI__vector_arteriovenous_volume_intracranial_spectrum_x;
    QVector<double> *MRI__vector_arteriovenous_volume_intracranial_spectrum_y;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_x;
    QVector<double> *MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_y;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_x;
    QVector<double> *MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_y;

    QVector<QString> *MRI__vector_arteries_images_all;
    QVector<double> **MRI__vector_arteries_all_x;
    QVector<double> **MRI__vector_arteries_all_y;
    QVector<QString> *MRI__vector_veins_images_all;
    QVector<double> **MRI__vector_veins_all_x;
    QVector<double> **MRI__vector_veins_all_y;
    QVector<QString> *MRI__vector_csfs_images_all;
    QVector<double> **MRI__vector_csfs_all_x;
    QVector<double> **MRI__vector_csfs_all_y;
    QVector<QString> *MRI__vector_undefines_images_all;
    QVector<double> **MRI__vector_undefines_all_x;
    QVector<double> **MRI__vector_undefines_all_y;

    //Double
    double MRI__double_arterial_heart_rate_spinal;
    double MRI__double_arterial_min_spinal;
    double MRI__double_arterial_max_spinal;
    double MRI__double_arterial_mean_spinal;
    double MRI__double_arterial_amplitude_spinal;
    double MRI__double_arterial_stroke_volume_spinal;
    double MRI__double_venous_min_spinal;
    double MRI__double_venous_max_spinal;
    double MRI__double_venous_mean_spinal;
    double MRI__double_venous_amplitude_spinal;
    double MRI__double_venous_stroke_volume_spinal;
    double MRI__double_venous_corrected_min_spinal;
    double MRI__double_venous_corrected_max_spinal;
    double MRI__double_venous_corrected_mean_spinal;
    double MRI__double_venous_corrected_amplitude_spinal;
    double MRI__double_venous_corrected_stroke_volume_spinal;
    double MRI__double_csf_heart_rate_spinal;
    double MRI__double_csf_min_spinal;
    double MRI__double_csf_max_spinal;
    double MRI__double_csf_mean_spinal;
    double MRI__double_csf_amplitude_spinal;
    double MRI__double_csf_stroke_volume_spinal;
    double MRI__double_csf_corrected_min_spinal;
    double MRI__double_csf_corrected_max_spinal;
    double MRI__double_csf_corrected_mean_spinal;
    double MRI__double_csf_corrected_amplitude_spinal;
    double MRI__double_csf_corrected_stroke_volume_spinal;
    double MRI__double_arteriovenous_flow_min_spinal;
    double MRI__double_arteriovenous_flow_max_spinal;
    double MRI__double_arteriovenous_flow_mean_spinal;
    double MRI__double_arteriovenous_flow_amplitude_spinal;
    double MRI__double_arteriovenous_flow_stroke_volume_spinal;
    double MRI__double_arteriovenous_volume_min_spinal;
    double MRI__double_arteriovenous_volume_max_spinal;
    double MRI__double_arteriovenous_volume_mean_spinal;
    double MRI__double_arteriovenous_volume_amplitude_spinal;
    double MRI__double_arteriovenouscsf_flow_min_spinal;
    double MRI__double_arteriovenouscsf_flow_max_spinal;
    double MRI__double_arteriovenouscsf_flow_mean_spinal;
    double MRI__double_arteriovenouscsf_flow_amplitude_spinal;
    double MRI__double_arteriovenouscsf_flow_stroke_volume_spinal;
    double MRI__double_arteriovenouscsf_volume_min_spinal;
    double MRI__double_arteriovenouscsf_volume_max_spinal;
    double MRI__double_arteriovenouscsf_volume_mean_spinal;
    double MRI__double_arteriovenouscsf_volume_amplitude_spinal;

    double MRI__double_arterial_heart_rate_intracranial;
    double MRI__double_arterial_min_intracranial;
    double MRI__double_arterial_max_intracranial;
    double MRI__double_arterial_mean_intracranial;
    double MRI__double_arterial_amplitude_intracranial;
    double MRI__double_arterial_stroke_volume_intracranial;
    double MRI__double_venous_min_intracranial;
    double MRI__double_venous_max_intracranial;
    double MRI__double_venous_mean_intracranial;
    double MRI__double_venous_amplitude_intracranial;
    double MRI__double_venous_stroke_volume_intracranial;
    double MRI__double_venous_corrected_min_intracranial;
    double MRI__double_venous_corrected_max_intracranial;
    double MRI__double_venous_corrected_mean_intracranial;
    double MRI__double_venous_corrected_amplitude_intracranial;
    double MRI__double_venous_corrected_stroke_volume_intracranial;
    double MRI__double_csf_heart_rate_intracranial;
    double MRI__double_csf_min_intracranial;
    double MRI__double_csf_max_intracranial;
    double MRI__double_csf_mean_intracranial;
    double MRI__double_csf_amplitude_intracranial;
    double MRI__double_csf_stroke_volume_intracranial;
    double MRI__double_csf_corrected_min_intracranial;
    double MRI__double_csf_corrected_max_intracranial;
    double MRI__double_csf_corrected_mean_intracranial;
    double MRI__double_csf_corrected_amplitude_intracranial;
    double MRI__double_csf_corrected_stroke_volume_intracranial;
    double MRI__double_arteriovenous_flow_min_intracranial;
    double MRI__double_arteriovenous_flow_max_intracranial;
    double MRI__double_arteriovenous_flow_mean_intracranial;
    double MRI__double_arteriovenous_flow_amplitude_intracranial;
    double MRI__double_arteriovenous_flow_stroke_volume_intracranial;
    double MRI__double_arteriovenous_volume_min_intracranial;
    double MRI__double_arteriovenous_volume_max_intracranial;
    double MRI__double_arteriovenous_volume_mean_intracranial;
    double MRI__double_arteriovenous_volume_amplitude_intracranial;
    double MRI__double_arteriovenouscsf_flow_min_intracranial;
    double MRI__double_arteriovenouscsf_flow_max_intracranial;
    double MRI__double_arteriovenouscsf_flow_mean_intracranial;
    double MRI__double_arteriovenouscsf_flow_amplitude_intracranial;
    double MRI__double_arteriovenouscsf_flow_stroke_volume_intracranial;
    double MRI__double_arteriovenouscsf_volume_min_intracranial;
    double MRI__double_arteriovenouscsf_volume_max_intracranial;
    double MRI__double_arteriovenouscsf_volume_mean_intracranial;
    double MRI__double_arteriovenouscsf_volume_amplitude_intracranial;

    //Int
    int MRI__int_ncycles_spinal;
    int MRI__int_arterial_move_spinal;
    int MRI__int_venous_move_spinal;
    int MRI__int_csf_move_spinal;

    int MRI__int_ncycles_intracranial;
    int MRI__int_arterial_move_intracranial;
    int MRI__int_venous_move_intracranial;
    int MRI__int_csf_move_intracranial;

    int MRI__int_ncycles_spinal_intracranial;


    //ICP
    //ScrollArea
    QScrollArea *ICP__scrollarea_basal;
    QScrollArea *ICP__scrollarea_plateau;

    //Widget
    QWidget *ICP__widget_basal;
    QWidget *ICP__widget_plateau;

    //Grid
    QGridLayout *ICP__grid_basal;
    QGridLayout *ICP__grid_plateau;

    //Plot
    QCustomPlot *ICP__plot_signal;
    QCustomPlot *ICP__plot_selection_basal;
    QCustomPlot *ICP__plot_FFT_basal;
    QCustomPlot *ICP__plot_IFFT_basal;
    QCustomPlot *ICP__plot_mean_basal;
    QCustomPlot *ICP__plot_selection_plateau;
    QCustomPlot *ICP__plot_FFT_plateau;
    QCustomPlot *ICP__plot_IFFT_plateau;
    QCustomPlot *ICP__plot_mean_plateau;

    //VBox
    QVBoxLayout *ICP__vbox_signal;
    QVBoxLayout *ICP__vbox_mean_basal;
    QVBoxLayout *ICP__vbox_mean_plateau;

    //HBox
    QHBoxLayout *ICP__hbox_signal;
    QHBoxLayout *ICP__hbox_FFT_basal;
    QHBoxLayout *ICP__hbox_FFT_plateau;
    QHBoxLayout *ICP__hbox_IFFT_basal;
    QHBoxLayout *ICP__hbox_IFFT_plateau;
    QHBoxLayout *ICP__hbox_mean_basal;
    QHBoxLayout *ICP__hbox_mean_plateau;

    //Label
    QLabel *ICP__label_quality_basal;
    QLabel *ICP__label_quality_plateau;
    QLabel *ICP__label_signal_basal;
    QLabel *ICP__label_signal_plateau;
    QLabel *ICP__label_FFT_view_basal;
    QLabel *ICP__label_FFT_view_plateau;
    QLabel *ICP__label_FFT_ROI_basal;
    QLabel *ICP__label_FFT_ROI_plateau;
    QLabel *ICP__label_threshold_basal;
    QLabel *ICP__label_threshold_plateau;
    QLabel *ICP__label_cardiac_cycle_basal;
    QLabel *ICP__label_heart_rate_basal;
    QLabel *ICP__label_min_basal;
    QLabel *ICP__label_max_basal;
    QLabel *ICP__label_mean_basal;
    QLabel *ICP__label_amplitude_basal;
    QLabel *ICP__label_cardiac_cycle_plateau;
    QLabel *ICP__label_heart_rate_plateau;
    QLabel *ICP__label_min_plateau;
    QLabel *ICP__label_max_plateau;
    QLabel *ICP__label_mean_plateau;
    QLabel *ICP__label_amplitude_plateau;

    //Spinbox
    QSpinBox *ICP__spinbox_quality_basal;
    QSpinBox *ICP__spinbox_quality_plateau;

    QDoubleSpinBox *ICP__doublespinbox_signal_down_basal;
    QDoubleSpinBox *ICP__doublespinbox_signal_up_basal;
    QDoubleSpinBox *ICP__doublespinbox_signal_down_plateau;
    QDoubleSpinBox *ICP__doublespinbox_signal_up_plateau;
    QDoubleSpinBox *ICP__doublespinbox_FFT_view_down_basal;
    QDoubleSpinBox *ICP__doublespinbox_FFT_view_up_basal;
    QDoubleSpinBox *ICP__doublespinbox_FFT_view_down_plateau;
    QDoubleSpinBox *ICP__doublespinbox_FFT_view_up_plateau;
    QDoubleSpinBox *ICP__doublespinbox_FFT_ROI_down_basal;
    QDoubleSpinBox *ICP__doublespinbox_FFT_ROI_up_basal;
    QDoubleSpinBox *ICP__doublespinbox_FFT_ROI_down_plateau;
    QDoubleSpinBox *ICP__doublespinbox_FFT_ROI_up_plateau;
    QDoubleSpinBox *ICP__doublespinbox_threshold_basal;
    QDoubleSpinBox *ICP__doublespinbox_threshold_plateau;

    //Button
    QPushButton *ICP__button_show_basal;
    QPushButton *ICP__button_show_plateau;
    QPushButton *ICP__button_FFT_basal;
    QPushButton *ICP__button_FFT_plateau;
    QPushButton *ICP__button_FFT_ROI_auto_basal;
    QPushButton *ICP__button_FFT_ROI_auto_plateau;
    QPushButton *ICP__button_IFFT_basal;
    QPushButton *ICP__button_IFFT_plateau;
    QPushButton *ICP__button_peak_plateau;
    QPushButton *ICP__button_peak_basal;
    QPushButton *ICP__button_mean_basal;
    QPushButton *ICP__button_mean_plateau;
    QPushButton *ICP__button_auto;
    QPushButton *ICP__button_adjust_basal;
    QPushButton *ICP__button_adjust_plateau;

    //Vector
    QVector<double> *ICP__vector_signal_x;
    QVector<double> *ICP__vector_signal_y;
    QVector<double> *ICP__vector_selection_basal_x;
    QVector<double> *ICP__vector_selection_basal_y;
    QVector<double> *ICP__vector_selection_plateau_x;
    QVector<double> *ICP__vector_selection_plateau_y;
    QVector<double> *ICP__vector_FFT_basal_x;
    QVector<double> *ICP__vector_FFT_basal_y;
    QVector<double> *ICP__vector_FFT_plateau_x;
    QVector<double> *ICP__vector_FFT_plateau_y;
    QVector<double> *ICP__vector_FFT_basal_x_ROI;
    QVector<double> *ICP__vector_FFT_basal_y_ROI;
    QVector<double> *ICP__vector_FFT_plateau_x_ROI;
    QVector<double> *ICP__vector_FFT_plateau_y_ROI;
    QVector<double> *ICP__vector_IFFT_basal_x;
    QVector<double> *ICP__vector_IFFT_basal_y;
    QVector<double> *ICP__vector_IFFT_plateau_x;
    QVector<double> *ICP__vector_IFFT_plateau_y;
    QVector<double> *ICP__vector_peak_basal_x;
    QVector<double> *ICP__vector_peak_basal_y;
    QVector<double> *ICP__vector_peak_plateau_x;
    QVector<double> *ICP__vector_peak_plateau_y;
    QVector<double> *ICP__vector_mean_basal_x;
    QVector<double> *ICP__vector_mean_basal_y;
    QVector<double> *ICP__vector_mean_sd_basal_y;
    QVector<double> *ICP__vector_mean_plateau_x;
    QVector<double> *ICP__vector_mean_plateau_y;
    QVector<double> *ICP__vector_mean_sd_plateau_y;

    //Double
    double ICP__double_cardiac_cycle_basal;
    double ICP__double_heart_rate_basal;
    double ICP__double_min_basal;
    double ICP__double_max_basal;
    double ICP__double_mean_basal;
    double ICP__double_amplitude_basal;
    double ICP__double_cardiac_cycle_plateau;
    double ICP__double_heart_rate_plateau;
    double ICP__double_min_plateau;
    double ICP__double_max_plateau;
    double ICP__double_mean_plateau;
    double ICP__double_amplitude_plateau;

    //Int
    int ICP__int_bound_select;
    int ICP__int_signal_repeat;
    int ICP__int_isadjusted_basal;
    int ICP__int_isadjusted_plateau;


    //EPI


    //COMPLIANCE
    //VBox
    QVBoxLayout *COMPLIANCE__vbox_arteriovenous_spinal;
    QVBoxLayout *COMPLIANCE__vbox_arteriovenouscsf_spinal;
    QVBoxLayout *COMPLIANCE__vbox_arteriovenous_intracranial;
    QVBoxLayout *COMPLIANCE__vbox_arteriovenouscsf_intracranial;
    QVBoxLayout *COMPLIANCE__vbox_icp_basal;
    QVBoxLayout *COMPLIANCE__vbox_icp_plateau;

    //HBox
    QHBoxLayout *COMPLIANCE__hbox_arteriovenous_spinal;
    QHBoxLayout *COMPLIANCE__hbox_arteriovenouscsf_spinal;
    QHBoxLayout *COMPLIANCE__hbox_arteriovenous_intracranial;
    QHBoxLayout *COMPLIANCE__hbox_arteriovenouscsf_intracranial;
    QHBoxLayout *COMPLIANCE__hbox_icp_basal;
    QHBoxLayout *COMPLIANCE__hbox_icp_plateau;
    QHBoxLayout *COMPLIANCE__hbox_compliance;

    //Plot
    QCustomPlot *COMPLIANCE__plot_arteriovenous_spinal;
    QCustomPlot *COMPLIANCE__plot_arteriovenouscsf_spinal;
    QCustomPlot *COMPLIANCE__plot_arteriovenous_intracranial;
    QCustomPlot *COMPLIANCE__plot_arteriovenouscsf_intracranial;
    QCustomPlot *COMPLIANCE__plot_icp_basal;
    QCustomPlot *COMPLIANCE__plot_icp_plateau;

    //Label
    QLabel *COMPLIANCE__label_arteriovenous_spinal;
    QLabel *COMPLIANCE__label_arteriovenouscsf_spinal;
    QLabel *COMPLIANCE__label_arteriovenous_intracranial;
    QLabel *COMPLIANCE__label_arteriovenouscsf_intracranial;
    QLabel *COMPLIANCE__label_icp_basal;
    QLabel *COMPLIANCE__label_icp_plateau;
    QLabel *COMPLIANCE__label_compliance;

    //RadioButton
    QButtonGroup *COMPLIANCE__radiobutton_group_volume;
    QButtonGroup *COMPLIANCE__radiobutton_group_pressure;
    QRadioButton *COMPLIANCE__radiobutton_arteriovenous_spinal;
    QRadioButton *COMPLIANCE__radiobutton_arteriovenouscsf_spinal;
    QRadioButton *COMPLIANCE__radiobutton_arteriovenous_intracranial;
    QRadioButton *COMPLIANCE__radiobutton_arteriovenouscsf_intracranial;
    QRadioButton *COMPLIANCE__radiobutton_icp_basal;
    QRadioButton *COMPLIANCE__radiobutton_icp_plateau;

    //Button
    QPushButton *COMPLIANCE__button_compliance;

    //Double
    double COMPLIANCE__double_compliance;


    //TRANSFERTFUNCTION
    //VBox
    QVBoxLayout *TRANSFERTFUNCTION__vbox_arteriovenous_spinal;
    QVBoxLayout *TRANSFERTFUNCTION__vbox_arteriovenouscsf_spinal;
    QVBoxLayout *TRANSFERTFUNCTION__vbox_arteriovenous_intracranial;
    QVBoxLayout *TRANSFERTFUNCTION__vbox_arteriovenouscsf_intracranial;
    QVBoxLayout *TRANSFERTFUNCTION__vbox_icp_basal;
    QVBoxLayout *TRANSFERTFUNCTION__vbox_icp_plateau;

    //HBox
    QHBoxLayout *TRANSFERTFUNCTION__hbox_arteriovenous_spinal;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_arteriovenouscsf_spinal;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_arteriovenous_intracranial;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_arteriovenouscsf_intracranial;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_icp_basal;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_icp_plateau;
    QHBoxLayout *TRANSFERTFUNCTION__hbox_transfert_function;

    //Plot
    QCustomPlot *TRANSFERTFUNCTION__plot_arteriovenous_spinal;
    QCustomPlot *TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal;
    QCustomPlot *TRANSFERTFUNCTION__plot_arteriovenous_intracranial;
    QCustomPlot *TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial;
    QCustomPlot *TRANSFERTFUNCTION__plot_icp_basal;
    QCustomPlot *TRANSFERTFUNCTION__plot_icp_plateau;
    QCustomPlot *TRANSFERTFUNCTION__plot_transfert_function;

    //Label
    QLabel *TRANSFERTFUNCTION__label_arteriovenous_spinal;
    QLabel *TRANSFERTFUNCTION__label_arteriovenouscsf_spinal;
    QLabel *TRANSFERTFUNCTION__label_arteriovenous_intracranial;
    QLabel *TRANSFERTFUNCTION__label_arteriovenouscsf_intracranial;
    QLabel *TRANSFERTFUNCTION__label_icp_basal;
    QLabel *TRANSFERTFUNCTION__label_icp_plateau;
    QLabel *TRANSFERTFUNCTION__label_transfert_function;

    //RadioButton
    QButtonGroup *TRANSFERTFUNCTION__radiobutton_group_volume;
    QButtonGroup *TRANSFERTFUNCTION__radiobutton_group_pressure;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_icp_basal;
    QRadioButton *TRANSFERTFUNCTION__radiobutton_icp_plateau;

    //Button
    QPushButton *TRANSFERTFUNCTION__button_transfert_function;

    //Vector
    QVector<double> *TRANSFERTFUNCTION__vector_transfert_function_x;
    QVector<double> *TRANSFERTFUNCTION__vector_transfert_function_y;


    //STATISTICS
    //VBox
    QVBoxLayout *STATISTICS__vbox_load;

    //HBox
    QHBoxLayout *STATISTICS__hbox_x;
    QHBoxLayout *STATISTICS__hbox_y;
    QHBoxLayout *STATISTICS__hbox_tools;

    //Plot
    QCustomPlot *STATISTICS__plot;

    //List
    QListWidget *STATISTICS__list_load;

    //Label
    QLabel *STATISTICS__label_x;
    QLabel *STATISTICS__label_y;
    QLabel *STATISTICS__label_weight_x;
    QLabel *STATISTICS__label_weight_y;

    //ComboBox
    QComboBox *STATISTICS__combobox_x;
    QComboBox *STATISTICS__combobox_y;
    QComboBox *STATISTICS__combobox_weight_x;
    QComboBox *STATISTICS__combobox_weight_y;

    //Button
    QPushButton *STATISTICS__button_load;
    QPushButton *STATISTICS__button_make_group;
    QPushButton *STATISTICS__button_remove;
    QPushButton *STATISTICS__button_regression;
    QPushButton *STATISTICS__button_clustering;
    QPushButton *STATISTICS__button_export;

    //Vector
    QVector<double> **STATISTICS__vector_data;

    //Int
    int STATISTICS__int_group;
};

#endif // MAINWINDOW_H
