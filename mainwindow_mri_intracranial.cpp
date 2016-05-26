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

#include "mainwindow.h"

void MainWindow::MRI__init_var_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_intracranial = new QMenu;

    //VBox
    MRI__vbox_arterial_button_intracranial = new QVBoxLayout;
    MRI__vbox_arterial_intracranial = new QVBoxLayout;
    MRI__vbox_venous_button_intracranial = new QVBoxLayout;
    MRI__vbox_venous_intracranial = new QVBoxLayout;
    MRI__vbox_csf_button_intracranial = new QVBoxLayout;
    MRI__vbox_csf_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenous_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenouscsf_intracranial = new QVBoxLayout;

    //HBox
    MRI__hbox_arterial_intracranial = new QHBoxLayout;
    MRI__hbox_venous_intracranial = new QHBoxLayout;
    MRI__hbox_csf_intracranial = new QHBoxLayout;
    MRI__hbox_arteriovenous_intracranial = new QHBoxLayout;
    MRI__hbox_arteriovenouscsf_intracranial = new QHBoxLayout;

    //Plot
    MRI__plot_arterial_intracranial = new QCustomPlot;
    MRI__plot_venous_intracranial = new QCustomPlot;
    MRI__plot_csf_intracranial = new QCustomPlot;
    MRI__plot_arteriovenous_intracranial = new QCustomPlot;
    MRI__plot_arteriovenouscsf_intracranial = new QCustomPlot;

    //Label
    MRI__label_venous_intracranial = new QLabel;
    MRI__label_csf_intracranial = new QLabel;
    MRI__label_arterial_quality_intracranial = new QLabel;
    MRI__label_arterial_heart_rate_intracranial = new QLabel;
    MRI__label_arterial_min_intracranial = new QLabel;
    MRI__label_arterial_max_intracranial = new QLabel;
    MRI__label_arterial_mean_intracranial = new QLabel;
    MRI__label_arterial_amplitude_intracranial = new QLabel;
    MRI__label_arterial_stroke_volume_intracranial = new QLabel;
    MRI__label_venous_quality_intracranial = new QLabel;
    MRI__label_venous_min_intracranial = new QLabel;
    MRI__label_venous_max_intracranial = new QLabel;
    MRI__label_venous_mean_intracranial = new QLabel;
    MRI__label_venous_amplitude_intracranial = new QLabel;
    MRI__label_venous_stroke_volume_intracranial = new QLabel;
    MRI__label_csf_quality_intracranial = new QLabel;
    MRI__label_csf_heart_rate_intracranial = new QLabel;
    MRI__label_csf_min_intracranial = new QLabel;
    MRI__label_csf_max_intracranial = new QLabel;
    MRI__label_csf_mean_intracranial = new QLabel;
    MRI__label_csf_amplitude_intracranial = new QLabel;
    MRI__label_csf_stroke_volume_intracranial = new QLabel;
    MRI__label_arteriovenous_min_intracranial = new QLabel;
    MRI__label_arteriovenous_max_intracranial = new QLabel;
    MRI__label_arteriovenous_mean_intracranial = new QLabel;
    MRI__label_arteriovenous_amplitude_intracranial = new QLabel;
    MRI__label_arteriovenous_stroke_volume_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_min_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_max_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_mean_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_amplitude_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_stroke_volume_intracranial = new QLabel;

    //Spinbox
    MRI__spinbox_arterial_quality_intracranial = new QSpinBox;
    MRI__spinbox_venous_quality_intracranial = new QSpinBox;
    MRI__spinbox_csf_quality_intracranial = new QSpinBox;

    MRI__doublespinbox_systole_threshold_intracranial = new QDoubleSpinBox;

    //ComboBox
    MRI__combobox_flow_volume_arteriovenous_intracranial = new QComboBox;
    MRI__combobox_flow_volume_arteriovenouscsf_intracranial = new QComboBox;

    //Button
    MRI__button_detect_systole_intracranial = new QPushButton;
    MRI__button_adjust_systole_intracranial = new QPushButton;
    MRI__button_hide_systole_intracranial = new QPushButton;
    MRI__button_plot_00_intracranial = new QPushButton;
    MRI__button_menu_ncycles_intracranial = new QPushButton;
    MRI__button_legend_intracranial = new QPushButton;
    MRI__button_venous_intracranial = new QPushButton;
    MRI__button_csf_intracranial = new QPushButton;
    MRI__button_arteriovenous_intracranial = new QPushButton;
    MRI__button_arteriovenous_auto_intracranial = new QPushButton;
    MRI__button_arteriovenouscsf_intracranial = new QPushButton;
    MRI__button_arteriovenouscsf_auto_intracranial = new QPushButton;
    MRI__button_restore_arterial_intracranial = new QPushButton;
    MRI__button_smooth_arterial_intracranial = new QPushButton;
    MRI__button_move_right_arterial_intracranial = new QPushButton;
    MRI__button_move_left_arterial_intracranial = new QPushButton;
    MRI__button_restore_venous_intracranial = new QPushButton;
    MRI__button_smooth_venous_intracranial = new QPushButton;
    MRI__button_move_right_venous_intracranial = new QPushButton;
    MRI__button_move_left_venous_intracranial = new QPushButton;
    MRI__button_show_up_venous_intracranial = new QPushButton;
    MRI__button_restore_csf_intracranial = new QPushButton;
    MRI__button_smooth_csf_intracranial = new QPushButton;
    MRI__button_move_right_csf_intracranial = new QPushButton;
    MRI__button_move_left_csf_intracranial = new QPushButton;

    //Vector
    MRI__vector_arterial_intracranial_x = new QVector<double>;
    MRI__vector_arterial_intracranial_y = new QVector<double>;
    MRI__vector_arterial_systole_intracranial_x = new QVector<double>;
    MRI__vector_arterial_systole_intracranial_y = new QVector<double>;
    MRI__vector_venous_intracranial_x = new QVector<double>;
    MRI__vector_venous_intracranial_y = new QVector<double>;
    MRI__vector_venous_corrected_intracranial_y = new QVector<double>;
    MRI__vector_csf_intracranial_x = new QVector<double>;
    MRI__vector_csf_intracranial_y = new QVector<double>;
    MRI__vector_csf_corrected_intracranial_y = new QVector<double>;
    MRI__vector_arteriovenous_flow_intracranial_x = new QVector<double>;
    MRI__vector_arteriovenous_flow_intracranial_y = new QVector<double>;
    MRI__vector_arteriovenous_volume_intracranial_x = new QVector<double>;
    MRI__vector_arteriovenous_volume_intracranial_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_intracranial_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_intracranial_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_intracranial_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_intracranial_y = new QVector<double>;

    //Double
    MRI__double_arterial_heart_rate_intracranial = 0.;
    MRI__double_arterial_min_intracranial = 0.;
    MRI__double_arterial_max_intracranial = 0.;
    MRI__double_arterial_mean_intracranial = 0.;
    MRI__double_arterial_amplitude_intracranial = 0.;
    MRI__double_arterial_stroke_volume_intracranial = 0.;
    MRI__double_venous_min_intracranial = 0.;
    MRI__double_venous_max_intracranial = 0.;
    MRI__double_venous_mean_intracranial = 0.;
    MRI__double_venous_amplitude_intracranial = 0.;
    MRI__double_venous_stroke_volume_intracranial = 0.;
    MRI__double_venous_corrected_min_intracranial = 0.;
    MRI__double_venous_corrected_max_intracranial = 0.;
    MRI__double_venous_corrected_mean_intracranial = 0.;
    MRI__double_venous_corrected_amplitude_intracranial = 0.;
    MRI__double_venous_corrected_stroke_volume_intracranial = 0.;
    MRI__double_csf_heart_rate_intracranial = 0.;
    MRI__double_csf_min_intracranial = 0.;
    MRI__double_csf_max_intracranial = 0.;
    MRI__double_csf_mean_intracranial = 0.;
    MRI__double_csf_amplitude_intracranial = 0.;
    MRI__double_csf_stroke_volume_intracranial = 0.;
    MRI__double_csf_corrected_min_intracranial = 0.;
    MRI__double_csf_corrected_max_intracranial = 0.;
    MRI__double_csf_corrected_mean_intracranial = 0.;
    MRI__double_csf_corrected_amplitude_intracranial = 0.;
    MRI__double_csf_corrected_stroke_volume_intracranial = 0.;
    MRI__double_arteriovenous_flow_min_intracranial = 0.;
    MRI__double_arteriovenous_flow_max_intracranial = 0.;
    MRI__double_arteriovenous_flow_mean_intracranial = 0.;
    MRI__double_arteriovenous_flow_amplitude_intracranial = 0.;
    MRI__double_arteriovenous_flow_stroke_volume_intracranial = 0.;
    MRI__double_arteriovenous_volume_min_intracranial = 0.;
    MRI__double_arteriovenous_volume_max_intracranial = 0.;
    MRI__double_arteriovenous_volume_mean_intracranial = 0.;
    MRI__double_arteriovenous_volume_amplitude_intracranial = 0.;
    MRI__double_arteriovenouscsf_flow_min_intracranial = 0.;
    MRI__double_arteriovenouscsf_flow_max_intracranial = 0.;
    MRI__double_arteriovenouscsf_flow_mean_intracranial = 0.;
    MRI__double_arteriovenouscsf_flow_amplitude_intracranial = 0.;
    MRI__double_arteriovenouscsf_flow_stroke_volume_intracranial = 0.;
    MRI__double_arteriovenouscsf_volume_min_intracranial = 0.;
    MRI__double_arteriovenouscsf_volume_max_intracranial = 0.;
    MRI__double_arteriovenouscsf_volume_mean_intracranial = 0.;
    MRI__double_arteriovenouscsf_volume_amplitude_intracranial = 0.;

    //Int
    MRI__int_ncycles_intracranial = 1;
    MRI__int_arterial_move_intracranial = 0;
    MRI__int_venous_move_intracranial = 0;
    MRI__int_csf_move_intracranial = 0;
}

void MainWindow::MRI__init_win_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_intracranial->setTitle("Number of cycles");
    {
        QAction *action1 = new QAction("1", this);
        QAction *action2 = new QAction("2", this);
        QAction *action3 = new QAction("3", this);

        action1->setCheckable(true);
        action2->setCheckable(true);
        action3->setCheckable(true);

        MRI__menu_ncycles_intracranial->addAction(action1);
        MRI__menu_ncycles_intracranial->addAction(action2);
        MRI__menu_ncycles_intracranial->addAction(action3);
    }

    //Grid
    MRI__grid_intracranial->addLayout(MRI__hbox_arterial_intracranial, 0, 0, 1, 10);
    MRI__grid_intracranial->addWidget(MRI__plot_arterial_intracranial, 1, 0, 10, 10);
    MRI__grid_intracranial->addLayout(MRI__vbox_arterial_button_intracranial, 0, 10, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__vbox_arterial_intracranial, 0, 11, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__hbox_venous_intracranial, 11, 0, 1, 10);
    MRI__grid_intracranial->addWidget(MRI__plot_venous_intracranial, 12, 0, 10, 10);
    MRI__grid_intracranial->addLayout(MRI__vbox_venous_button_intracranial, 11, 10, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__vbox_venous_intracranial, 11, 11, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__hbox_csf_intracranial, 22, 0, 1, 10);
    MRI__grid_intracranial->addWidget(MRI__plot_csf_intracranial, 23, 0, 10, 10);
    MRI__grid_intracranial->addLayout(MRI__vbox_csf_button_intracranial, 22, 10, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__vbox_csf_intracranial, 22, 11, 11, 1);
    MRI__grid_intracranial->addLayout(MRI__hbox_arteriovenous_intracranial, 33, 0, 1, 5);
    MRI__grid_intracranial->addWidget(MRI__plot_arteriovenous_intracranial, 34, 0, 10, 5);
    MRI__grid_intracranial->addLayout(MRI__vbox_arteriovenous_intracranial, 33, 5, 10, 1);
    MRI__grid_intracranial->addLayout(MRI__hbox_arteriovenouscsf_intracranial, 33, 6, 1, 5);
    MRI__grid_intracranial->addWidget(MRI__plot_arteriovenouscsf_intracranial, 34, 6, 10, 5);
    MRI__grid_intracranial->addLayout(MRI__vbox_arteriovenouscsf_intracranial, 33, 11, 10, 1);

    //VBox
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__button_restore_arterial_intracranial);
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__button_smooth_arterial_intracranial);
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__button_move_right_arterial_intracranial);
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__button_move_left_arterial_intracranial);
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__label_arterial_quality_intracranial);
    MRI__vbox_arterial_button_intracranial->addWidget(MRI__spinbox_arterial_quality_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_heart_rate_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_min_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_max_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_mean_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_amplitude_intracranial);
    MRI__vbox_arterial_intracranial->addWidget(MRI__label_arterial_stroke_volume_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__button_restore_venous_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__button_smooth_venous_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__button_move_right_venous_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__button_move_left_venous_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__button_show_up_venous_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__label_venous_quality_intracranial);
    MRI__vbox_venous_button_intracranial->addWidget(MRI__spinbox_venous_quality_intracranial);
    MRI__vbox_venous_intracranial->addWidget(MRI__label_venous_min_intracranial);
    MRI__vbox_venous_intracranial->addWidget(MRI__label_venous_max_intracranial);
    MRI__vbox_venous_intracranial->addWidget(MRI__label_venous_mean_intracranial);
    MRI__vbox_venous_intracranial->addWidget(MRI__label_venous_amplitude_intracranial);
    MRI__vbox_venous_intracranial->addWidget(MRI__label_venous_stroke_volume_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__button_restore_csf_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__button_smooth_csf_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__button_move_right_csf_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__button_move_left_csf_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__label_csf_quality_intracranial);
    MRI__vbox_csf_button_intracranial->addWidget(MRI__spinbox_csf_quality_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_heart_rate_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_min_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_max_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_mean_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_amplitude_intracranial);
    MRI__vbox_csf_intracranial->addWidget(MRI__label_csf_stroke_volume_intracranial);
    MRI__vbox_arteriovenous_intracranial->addWidget(MRI__label_arteriovenous_min_intracranial);
    MRI__vbox_arteriovenous_intracranial->addWidget(MRI__label_arteriovenous_max_intracranial);
    MRI__vbox_arteriovenous_intracranial->addWidget(MRI__label_arteriovenous_mean_intracranial);
    MRI__vbox_arteriovenous_intracranial->addWidget(MRI__label_arteriovenous_amplitude_intracranial);
    MRI__vbox_arteriovenous_intracranial->addWidget(MRI__label_arteriovenous_stroke_volume_intracranial);
    MRI__vbox_arteriovenouscsf_intracranial->addWidget(MRI__label_arteriovenouscsf_min_intracranial);
    MRI__vbox_arteriovenouscsf_intracranial->addWidget(MRI__label_arteriovenouscsf_max_intracranial);
    MRI__vbox_arteriovenouscsf_intracranial->addWidget(MRI__label_arteriovenouscsf_mean_intracranial);
    MRI__vbox_arteriovenouscsf_intracranial->addWidget(MRI__label_arteriovenouscsf_amplitude_intracranial);
    MRI__vbox_arteriovenouscsf_intracranial->addWidget(MRI__label_arteriovenouscsf_stroke_volume_intracranial);

    //HBox
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_detect_systole_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__doublespinbox_systole_threshold_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_adjust_systole_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_hide_systole_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_plot_00_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_menu_ncycles_intracranial);
    MRI__hbox_arterial_intracranial->addWidget(MRI__button_legend_intracranial);

    MRI__hbox_venous_intracranial->addWidget(MRI__button_venous_intracranial);
    MRI__hbox_venous_intracranial->addWidget(MRI__label_venous_intracranial);

    MRI__hbox_csf_intracranial->addWidget(MRI__button_csf_intracranial);
    MRI__hbox_csf_intracranial->addWidget(MRI__label_csf_intracranial);

    MRI__hbox_arteriovenous_intracranial->addWidget(MRI__button_arteriovenous_intracranial);
    MRI__hbox_arteriovenous_intracranial->addWidget(MRI__button_arteriovenous_auto_intracranial);
    MRI__hbox_arteriovenous_intracranial->addWidget(MRI__combobox_flow_volume_arteriovenous_intracranial);

    MRI__hbox_arteriovenouscsf_intracranial->addWidget(MRI__button_arteriovenouscsf_intracranial);
    MRI__hbox_arteriovenouscsf_intracranial->addWidget(MRI__button_arteriovenouscsf_auto_intracranial);
    MRI__hbox_arteriovenouscsf_intracranial->addWidget(MRI__combobox_flow_volume_arteriovenouscsf_intracranial);

    //Plot
    MRI__plot_arterial_intracranial->addGraph();
    MRI__plot_arterial_intracranial->addGraph();
    MRI__plot_venous_intracranial->addGraph();
    MRI__plot_venous_intracranial->addGraph();
    MRI__plot_csf_intracranial->addGraph();
    MRI__plot_csf_intracranial->addGraph();
    MRI__plot_arteriovenous_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_intracranial->addGraph();

    //Label
    MRI__label_arterial_quality_intracranial->setText("Quality");
    MRI__label_venous_quality_intracranial->setText("Quality");
    MRI__label_csf_quality_intracranial->setText("Quality");

    //SpinBox
    MRI__spinbox_arterial_quality_intracranial->setRange(0, 5);
    MRI__spinbox_arterial_quality_intracranial->setValue(5);
    MRI__spinbox_venous_quality_intracranial->setRange(0, 5);
    MRI__spinbox_venous_quality_intracranial->setValue(5);
    MRI__spinbox_csf_quality_intracranial->setRange(0, 5);
    MRI__spinbox_csf_quality_intracranial->setValue(5);

    MRI__doublespinbox_systole_threshold_intracranial->setRange(0., 0.);
    MRI__doublespinbox_systole_threshold_intracranial->setToolTip("Systole detection threshold");

    //ComboBox
    MRI__combobox_flow_volume_arteriovenous_intracranial->addItem("Flow");
    MRI__combobox_flow_volume_arteriovenous_intracranial->addItem("Volume");
    MRI__combobox_flow_volume_arteriovenouscsf_intracranial->addItem("Flow");
    MRI__combobox_flow_volume_arteriovenouscsf_intracranial->addItem("Volume");

    //Button
    MRI__button_detect_systole_intracranial->setText("Detect systole");
    MRI__button_adjust_systole_intracranial->setText("Adjust from systole");
    MRI__button_hide_systole_intracranial->setText("Hide systole");
    MRI__button_plot_00_intracranial->setText("Plot (0,0)");
    MRI__button_plot_00_intracranial->setCheckable(true);
    MRI__button_menu_ncycles_intracranial->setText("Number of cycles");
    MRI__button_menu_ncycles_intracranial->setMenu(MRI__menu_ncycles_intracranial);
    MRI__button_legend_intracranial->setText("Legend");
    MRI__button_legend_intracranial->setCheckable(true);
    MRI__button_venous_intracranial->setText("Venous correction");
    MRI__button_csf_intracranial->setText("CSF correction");
    MRI__button_arteriovenous_intracranial->setText("AV");
    MRI__button_arteriovenous_auto_intracranial->setText("AUTO");
    MRI__button_arteriovenouscsf_intracranial->setText("AVCSF (Spinal CSF)");
    MRI__button_arteriovenouscsf_auto_intracranial->setText("AUTO");
    MRI__button_restore_arterial_intracranial->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_arterial_intracranial->setToolTip("Restore");
    MRI__button_smooth_arterial_intracranial->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_arterial_intracranial->setToolTip("Smooth");
    MRI__button_move_right_arterial_intracranial->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_arterial_intracranial->setToolTip("Move right");
    MRI__button_move_left_arterial_intracranial->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_arterial_intracranial->setToolTip("Move left");
    MRI__button_restore_venous_intracranial->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_venous_intracranial->setToolTip("Restore");
    MRI__button_smooth_venous_intracranial->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_venous_intracranial->setToolTip("Smooth");
    MRI__button_move_right_venous_intracranial->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_venous_intracranial->setToolTip("Move right");
    MRI__button_move_left_venous_intracranial->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_venous_intracranial->setToolTip("Move left");
    MRI__button_show_up_venous_intracranial->setIcon(QIcon("img/up.png"));
    MRI__button_show_up_venous_intracranial->setToolTip("Show up");
    MRI__button_show_up_venous_intracranial->setCheckable(true);
    MRI__button_restore_csf_intracranial->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_csf_intracranial->setToolTip("Restore");
    MRI__button_smooth_csf_intracranial->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_csf_intracranial->setToolTip("Smooth");
    MRI__button_move_right_csf_intracranial->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_csf_intracranial->setToolTip("Move right");
    MRI__button_move_left_csf_intracranial->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_csf_intracranial->setToolTip("Move left");
}

void MainWindow::MRI__init_sig_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //ComboBox
    connect(MRI__combobox_flow_volume_arteriovenous_intracranial, SIGNAL(currentIndexChanged(int)), this, SLOT(MRI__do_plot_arteriovenous_intracranial()));
    connect(MRI__combobox_flow_volume_arteriovenouscsf_intracranial, SIGNAL(currentIndexChanged(int)), this, SLOT(MRI__do_plot_arteriovenouscsf_intracranial()));

    //Button
    connect(MRI__button_plot_00_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_arterial_intracranial()));
    connect(MRI__button_plot_00_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_intracranial()));
    connect(MRI__button_plot_00_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_csf_intracranial()));
    connect(MRI__menu_ncycles_intracranial, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_ncycles_intracranial(QAction*)));
    connect(MRI__button_detect_systole_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_detect_systole_intracranial()));
    connect(MRI__button_adjust_systole_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_adjust_systole_intracranial()));
    connect(MRI__button_hide_systole_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_arterial_intracranial()));
    connect(MRI__button_legend_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_legend_intracranial()));
    connect(MRI__button_venous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_venous_intracranial()));
    connect(MRI__button_csf_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_csf_intracranial()));
    connect(MRI__button_arteriovenous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenous_intracranial()));
    connect(MRI__button_arteriovenous_auto_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenous_auto_intracranial()));
    connect(MRI__button_arteriovenouscsf_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenouscsf_intracranial()));
    connect(MRI__button_arteriovenouscsf_auto_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenouscsf_auto_intracranial()));
    connect(MRI__button_smooth_arterial_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_arterial_intracranial()));
    connect(MRI__button_smooth_venous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_venous_intracranial()));
    connect(MRI__button_smooth_csf_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_csf_intracranial()));
    connect(MRI__button_move_right_arterial_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_arterial_intracranial()));
    connect(MRI__button_move_right_venous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_venous_intracranial()));
    connect(MRI__button_move_right_csf_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_csf_intracranial()));
    connect(MRI__button_move_left_arterial_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_arterial_intracranial()));
    connect(MRI__button_move_left_venous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_venous_intracranial()));
    connect(MRI__button_move_left_csf_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_csf_intracranial()));
    connect(MRI__button_show_up_venous_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_intracranial()));
}

void MainWindow::MRI__init_css_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPen RedPen;
    RedPen.setColor(Qt::red);

    QPen BluePen;
    BluePen.setColor(Qt::blue);
    QPen BlueDotPen = QPen(BluePen);
    BlueDotPen.setStyle(Qt::DashLine);

    QPen GreenPen;
    GreenPen.setColor(Qt::green);
    QPen GreenDotPen = QPen(GreenPen);
    GreenDotPen.setStyle(Qt::DashLine);

    QPen CyanPen;
    CyanPen.setColor(Qt::darkCyan);

    QPen YellowPen;
    YellowPen.setColor(Qt::darkYellow);

    //Plot
    MRI__plot_arterial_intracranial->graph(0)->setPen(RedPen);
    MRI__plot_arterial_intracranial->graph(0)->setName("Arterial");
    MRI__plot_arterial_intracranial->graph(1)->setPen(RedPen);
    MRI__plot_arterial_intracranial->graph(1)->setLineStyle(QCPGraph::lsNone);
    MRI__plot_arterial_intracranial->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    MRI__plot_arterial_intracranial->graph(1)->setName("Systole");

    MRI__plot_venous_intracranial->graph(0)->setPen(BluePen);
    MRI__plot_venous_intracranial->graph(0)->setName("Venous");
    MRI__plot_venous_intracranial->graph(1)->setPen(BlueDotPen);
    MRI__plot_venous_intracranial->graph(1)->setName("Venous corrected");

    MRI__plot_csf_intracranial->graph(0)->setPen(GreenPen);
    MRI__plot_csf_intracranial->graph(0)->setName("CSF");
    MRI__plot_csf_intracranial->graph(1)->setPen(GreenDotPen);
    MRI__plot_csf_intracranial->graph(1)->setName("CSF corrected");

    MRI__plot_arteriovenous_intracranial->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_intracranial->graph(0)->setName("A-V");

    MRI__plot_arteriovenouscsf_intracranial->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_intracranial->graph(0)->setName("A-V-CSF");
}

bool MainWindow::MRI__do_plot_arterial_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__plot_arterial_intracranial->graph(1)->clearData();

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;

        if (MRI__int_ncycles_intracranial > 1){
            double maxx = max(MRI__vector_arterial_intracranial_x, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial intracranial plot error - ERR2-1");
                return res;
            }

            QVector<double> TMP__arterial_x, TMP__arterial_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nx;
                TMP__arterial_x.append(MRI__vector_arterial_intracranial_x->at(i%nx) + current_cycle*maxx);
                TMP__arterial_y.append(MRI__vector_arterial_intracranial_y->at(i%ny));
            }

            res = plot(MRI__plot_arterial_intracranial, 0, &TMP__arterial_x, &TMP__arterial_y);
            if (!res){
                statusbar_show_warning("Arterial intracranial plot error - ERR2-2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_arterial_intracranial, 0, MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y);
            if (!res){
                statusbar_show_warning("Arterial intracranial plot error - ERR2");
                return res;
            }
        }
        if (MRI__button_plot_00_intracranial->isChecked()){
            MRI__plot_arterial_intracranial->yAxis->setRangeLower(0.);
            MRI__plot_arterial_intracranial->replot();
        }

        res = MRI__do_print_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Arterial intracranial plot error - ERR3");
            return res;
        }

        res = MRI__do_plot_arterial_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arterial intracranial plot error - ERR4");
            return res;
        }

        res = MRI__do_arterial_intracranial_spectrum();
        if (!res){
            statusbar_show_warning("Arterial intracranial plot error - ERR5");
            return res;
        }

        statusbar_show_message("Arterial intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("Arterial intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_intracranial_x->count();
    unsigned int ny = MRI__vector_venous_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        if (MRI__button_show_up_venous_intracranial->isChecked()){
            QVector<double> TMP__venous_x, TMP__venous_y;
            if (MRI__int_ncycles_intracranial > 1){
                double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous intracranial plot error - ERR2-1");
                    return res;
                }

                for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nx) + current_cycle*maxx);
                    TMP__venous_y.append(-MRI__vector_venous_intracranial_y->at(i%ny));
                }
            }
            else{
                for (unsigned int i = 0; i < nx; i++){
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i));
                    TMP__venous_y.append(-MRI__vector_venous_intracranial_y->at(i));
                }
            }

            res = plot(MRI__plot_venous_intracranial, 0, &TMP__venous_x, &TMP__venous_y);
            if (!res){
                statusbar_show_warning("Venous intracranial plot error - ERR2");
                return res;
            }
        }
        else{
            if (MRI__int_ncycles_intracranial > 1){
                double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous intracranial plot error - ERR2-1");
                    return res;
                }

                QVector<double> TMP__venous_x, TMP__venous_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nx) + current_cycle*maxx);
                    TMP__venous_y.append(MRI__vector_venous_intracranial_y->at(i%ny));
                }

                res = plot(MRI__plot_venous_intracranial, 0, &TMP__venous_x, &TMP__venous_y);
                if (!res){
                    statusbar_show_warning("Venous intracranial plot error - ERR2-2");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_venous_intracranial, 0, MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y);
                if (!res){
                    statusbar_show_warning("Venous intracranial plot error - ERR2");
                    return res;
                }
            }
        }

        ny = MRI__vector_venous_corrected_intracranial_y->count();
        if (nx == ny){
            if (MRI__button_show_up_venous_intracranial->isChecked()){
                QVector<double> TMP__venous_x, TMP__venous_y;
                if (MRI__int_ncycles_intracranial > 1){
                    double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("Venous intracranial plot error - ERR3-1");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nx;
                        TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nx) + current_cycle*maxx);
                        TMP__venous_y.append(-MRI__vector_venous_corrected_intracranial_y->at(i%ny));
                    }
                }
                else{
                    for (unsigned int i = 0; i < nx; i++){
                        TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i));
                        TMP__venous_y.append(-MRI__vector_venous_corrected_intracranial_y->at(i));
                    }
                }

                res = plot(MRI__plot_venous_intracranial, 1, &TMP__venous_x, &TMP__venous_y, false);
                if (!res){
                    statusbar_show_warning("Venous intracranial plot error - ERR3");
                    return res;
                }
                MRI__plot_venous_intracranial->yAxis->setRange(-max(max(MRI__vector_venous_intracranial_y), max(MRI__vector_venous_corrected_intracranial_y)), -min(min(MRI__vector_venous_intracranial_y), min(MRI__vector_venous_corrected_intracranial_y)));
            }
            else{
                if (MRI__int_ncycles_intracranial > 1){
                    QVector<double> TMP__venous_x, TMP__venous_y;

                    double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("Venous intracranial plot error - ERR3-1");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nx;
                        TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nx) + current_cycle*maxx);
                        TMP__venous_y.append(MRI__vector_venous_corrected_intracranial_y->at(i%ny));
                    }

                    res = plot(MRI__plot_venous_intracranial, 1, &TMP__venous_x, &TMP__venous_y, false);
                    if (!res){
                        statusbar_show_warning("Venous intracranial plot error - ERR3-2");
                        return res;
                    }
                }
                else{
                    res = plot(MRI__plot_venous_intracranial, 1, MRI__vector_venous_intracranial_x, MRI__vector_venous_corrected_intracranial_y, false);
                    if (!res){
                        statusbar_show_warning("Venous intracranial plot error - ERR3");
                        return res;
                    }
                }
                MRI__plot_venous_intracranial->yAxis->setRange(min(min(MRI__vector_venous_intracranial_y), min(MRI__vector_venous_corrected_intracranial_y)), max(max(MRI__vector_venous_intracranial_y), max(MRI__vector_venous_corrected_intracranial_y)));
            }

            res = MRI__do_venous_intracranial_spectrum();
            if (!res){
                statusbar_show_warning("Venous intracranial plot error - ERR6");
                return res;
            }
        }

        if (MRI__button_plot_00_intracranial->isChecked()){
            if (MRI__button_show_up_venous_intracranial->isChecked()){
                MRI__plot_venous_intracranial->yAxis->setRangeLower(0.);
            }
            else{
                MRI__plot_venous_intracranial->yAxis->setRangeUpper(0.);
            }
        }

        MRI__plot_venous_intracranial->replot();

        res = MRI__do_print_venous_intracranial();
        if (!res){
            statusbar_show_warning("Venous intracranial plot error - ERR4");
            return res;
        }

        res = MRI__do_plot_venous_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Venous intracranial plot error - ERR5");
            return res;
        }

        statusbar_show_message("Venous intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("Venous intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_intracranial_x->count();
    unsigned int ny = MRI__vector_csf_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        if (MRI__int_ncycles_intracranial > 1){
            double maxx = max(MRI__vector_csf_intracranial_x, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF intracranial plot error - ERR2-1");
                return res;
            }

            QVector<double> TMP__csf_x, TMP__csf_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nx;
                TMP__csf_x.append(MRI__vector_csf_intracranial_x->at(i%nx) + current_cycle*maxx);
                TMP__csf_y.append(MRI__vector_csf_intracranial_y->at(i%ny));
            }

            res = plot(MRI__plot_csf_intracranial, 0, &TMP__csf_x, &TMP__csf_y);
            if (!res){
                statusbar_show_warning("Arterial intracranial plot error - ERR2-2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_csf_intracranial, 0, MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y);
            if (!res){
                statusbar_show_warning("CSF intracranial plot error - ERR2");
                return res;
            }
        }

        ny = MRI__vector_csf_corrected_intracranial_y->count();
        if (ny == nx){
            if (MRI__int_ncycles_intracranial > 1){
                double maxx = max(MRI__vector_csf_intracranial_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF intracranial plot error - ERR3-1");
                    return res;
                }

                QVector<double> TMP__csf_x, TMP__csf_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_intracranial*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__csf_x.append(MRI__vector_csf_intracranial_x->at(i%nx) + current_cycle*maxx);
                    TMP__csf_y.append(MRI__vector_csf_corrected_intracranial_y->at(i%ny));
                }

                res = plot(MRI__plot_csf_intracranial, 1, &TMP__csf_x, &TMP__csf_y, false);
                if (!res){
                    statusbar_show_warning("Arterial intracranial plot error - ERR3-2");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_csf_intracranial, 1, MRI__vector_csf_intracranial_x, MRI__vector_csf_corrected_intracranial_y, false);
                if (!res){
                    statusbar_show_warning("CSF intracranial plot error - ERR3");
                    return res;
                }
            }
            MRI__plot_csf_intracranial->yAxis->setRange(min(min(MRI__vector_csf_intracranial_y), min(MRI__vector_csf_corrected_intracranial_y)), max(max(MRI__vector_csf_intracranial_y), max(MRI__vector_csf_corrected_intracranial_y)));

            res = MRI__do_csf_intracranial_spectrum();
            if (!res){
                statusbar_show_warning("CSF intracranial plot error - ERR6");
                return res;
            }
        }

        res = MRI__do_print_csf_intracranial();
        if (!res){
            statusbar_show_warning("CSF intracranial plot error - ERR4");
            return res;
        }

        res = MRI__do_plot_csf_spinal_intracranial();
        if (!res){
            statusbar_show_warning("CSF intracranial plot error - ERR5");
            return res;
        }

        statusbar_show_message("CSF intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("CSF intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_systole_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_systole_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_systole_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(MRI__plot_arterial_intracranial, 1, MRI__vector_arterial_systole_intracranial_x, MRI__vector_arterial_systole_intracranial_y, false);
        if (!res){
            statusbar_show_warning("Systole plot error - ERR2");
            return res;
        }
        else{
            statusbar_show_message("Systole plotted");
            return res;
        }
    }
    else{
        statusbar_show_warning("Systole plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_smooth_arterial_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_arterial_intracranial_y);
        if (!res){
            statusbar_show_warning("Smooth arterial error - ERR2");
            return res;
        }

        res = MRI__do_plot_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Smooth arterial error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Smooth arterial done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Smooth arterial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_smooth_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_intracranial_x->count();
    unsigned int ny = MRI__vector_venous_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_venous_intracranial_y);
        if (!res){
            statusbar_show_warning("Smooth venous error - ERR2");
            return res;
        }

        res = MRI__do_venous_intracranial();
        if (!res){
            statusbar_show_warning("Smooth venous error - ERR3");
            return res;
        }

        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Smooth venous error - ERR4");
            return res;
        }
        else{
            statusbar_show_message("Smooth venous done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Smooth venous error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_smooth_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_intracranial_x->count();
    unsigned int ny = MRI__vector_csf_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_csf_intracranial_y);
        if (!res){
            statusbar_show_warning("Smooth CSF error - ERR2");
            return res;
        }

        res = MRI__do_csf_intracranial();
        if (!res){
            statusbar_show_warning("Smooth CSF error - ERR3");
            return res;
        }

        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("Smooth CSF error - ERR4");
            return res;
        }
        else{
            statusbar_show_message("Smooth CSF done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Smooth CSF error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_right_arterial_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_arterial_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move arterial right error - ERR2");
            return res;
        }

        MRI__int_arterial_move_intracranial--;

        res = MRI__do_plot_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Move arterial right error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move arterial right done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move arterial right error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_right_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_intracranial_x->count();
    unsigned int ny = MRI__vector_venous_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_venous_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move venous right error - ERR2");
            return res;
        }

        MRI__int_venous_move_intracranial--;

        ny = MRI__vector_venous_corrected_intracranial_y->count();
        if ((ny == nx)){
            move_curve(-1, MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move venous right error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Move venous right error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move venous right done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move venous right error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_right_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_intracranial_x->count();
    unsigned int ny = MRI__vector_csf_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_csf_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move CSF right error - ERR2");
            return res;
        }

        MRI__int_csf_move_intracranial--;

        ny = MRI__vector_csf_corrected_intracranial_y->count();
        if ((ny == nx)){
            move_curve(-1, MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move CSF right error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("Move CSF right error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move CSF right done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move CSF right error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_left_arterial_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_arterial_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move arterial left error - ERR2");
            return res;
        }

        MRI__int_arterial_move_intracranial++;

        res = MRI__do_plot_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Move arterial left error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move arterial left done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move arterial left error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_left_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_intracranial_x->count();
    unsigned int ny = MRI__vector_venous_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_venous_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move venous left error - ERR2");
            return res;
        }

        MRI__int_venous_move_intracranial++;

        ny = MRI__vector_venous_corrected_intracranial_y->count();
        if ((ny == nx)){
            move_curve(1, MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move venous left error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Move venous left error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move venous left done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move venous left error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_move_left_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_intracranial_x->count();
    unsigned int ny = MRI__vector_csf_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_csf_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move CSF left error - ERR2");
            return res;
        }

        MRI__int_csf_move_intracranial++;

        ny = MRI__vector_csf_corrected_intracranial_y->count();
        if ((ny == nx)){
            move_curve(1, MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move CSF left error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("Move CSF left error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Move CSF left done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Move CSF left error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_arterial_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = MRI__vector_arterial_intracranial_x->count();
    int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res;
        double minx = min(MRI__vector_arterial_intracranial_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR2");
            return res;
        }
        double maxx = max(MRI__vector_arterial_intracranial_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR3");
            return res;
        }
        double miny = min(MRI__vector_arterial_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR4");
            return res;
        }
        double maxy = max(MRI__vector_arterial_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR5");
            return res;
        }
        double meany = mean(MRI__vector_arterial_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR6");
            return res;
        }
        double sv = stroke_volume(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print arterial intracranial error - ERR7");
            return res;
        }

        MRI__double_arterial_heart_rate_intracranial = 60. / (maxx - minx);
        MRI__double_arterial_min_intracranial = miny;
        MRI__double_arterial_max_intracranial = maxy;
        MRI__double_arterial_mean_intracranial = meany;
        MRI__double_arterial_amplitude_intracranial = maxy - miny;
        MRI__double_arterial_stroke_volume_intracranial = sv;

        MRI__label_arterial_heart_rate_intracranial->setText("<b>Heart rate</b> = " + QString::number(MRI__double_arterial_heart_rate_intracranial) + " bpm");
        MRI__label_arterial_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_arterial_min_intracranial) + " mm^3/s");
        MRI__label_arterial_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_arterial_max_intracranial) + " mm^3/s");
        MRI__label_arterial_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arterial_mean_intracranial) + " mm^3/s");
        MRI__label_arterial_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arterial_amplitude_intracranial) + " mm^3/s");
        MRI__label_arterial_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arterial_stroke_volume_intracranial) + " mm^3");

        statusbar_show_message("Print arterial intracranial done");
        return true;
    }
    else{
        statusbar_show_warning("Print arterial intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_intracranial_x->count();
    unsigned int ny = MRI__vector_venous_intracranial_x->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double miny = min(MRI__vector_venous_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print venous intracranial error - ERR2");
            return res;
        }
        double maxy = max(MRI__vector_venous_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print venous intracranial error - ERR3");
            return res;
        }
        double meany = mean(MRI__vector_venous_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print venous intracranial error - ERR4");
            return res;
        }
        double sv = stroke_volume(MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print venous intracranial error - ERR5");
            return res;
        }

        MRI__double_venous_min_intracranial = miny;
        MRI__double_venous_max_intracranial = maxy;
        MRI__double_venous_mean_intracranial = meany;
        MRI__double_venous_amplitude_intracranial = maxy - miny;
        MRI__double_venous_stroke_volume_intracranial = sv;

        ny = MRI__vector_venous_corrected_intracranial_y->count();

        if (nx == ny){
            double miny = min(MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print venous intracranial error - ERR6");
                return res;
            }
            double maxy = max(MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print venous intracranial error - ERR7");
                return res;
            }
            double meany = mean(MRI__vector_venous_corrected_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print venous intracranial error - ERR8");
                return res;
            }
            double sv = stroke_volume(MRI__vector_venous_intracranial_x, MRI__vector_venous_corrected_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print venous intracranial error - ERR9");
                return res;
            }

            MRI__double_venous_corrected_min_intracranial = miny;
            MRI__double_venous_corrected_max_intracranial = maxy;
            MRI__double_venous_corrected_mean_intracranial = meany;
            MRI__double_venous_corrected_amplitude_intracranial = maxy - miny;
            MRI__double_venous_corrected_stroke_volume_intracranial = sv;

            MRI__label_venous_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_venous_min_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_min_intracranial) + ")</span>");
            MRI__label_venous_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_venous_max_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_max_intracranial) + ")</span>");
            MRI__label_venous_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_venous_mean_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_mean_intracranial) + ")</span>");
            MRI__label_venous_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_venous_amplitude_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_amplitude_intracranial) + ")</span>");
            MRI__label_venous_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_venous_stroke_volume_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_stroke_volume_intracranial) + ")</span>");
        }
        else{
            MRI__label_venous_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_venous_min_intracranial) + "mm^3/s");
            MRI__label_venous_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_venous_max_intracranial) + "mm^3/s");
            MRI__label_venous_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_venous_mean_intracranial) + "mm^3/s");
            MRI__label_venous_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_venous_amplitude_intracranial) + "mm^3/s");
            MRI__label_venous_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_venous_stroke_volume_intracranial) + "mm^3/s");
        }

        statusbar_show_message("Print venous intracranial done");
        return true;
    }
    else{
        statusbar_show_warning("Print venous intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    unsigned int nx = MRI__vector_csf_intracranial_x->count();
    unsigned int ny = MRI__vector_csf_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double miny = min(MRI__vector_csf_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print csf intracranial error - ERR2");
            return res;
        }
        double maxy = max(MRI__vector_csf_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print csf intracranial error - ERR3");
            return res;
        }
        double meany = mean(MRI__vector_csf_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print csf intracranial error - ERR4");
            return res;
        }
        double sv = stroke_volume(MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y, &res);
        if (!res){
            statusbar_show_warning("Print csf intracranial error - ERR5");
            return res;
        }

        MRI__double_csf_min_intracranial = miny;
        MRI__double_csf_max_intracranial = maxy;
        MRI__double_csf_mean_intracranial = meany;
        MRI__double_csf_amplitude_intracranial = maxy - miny;
        MRI__double_csf_stroke_volume_intracranial = sv;

        ny = MRI__vector_csf_corrected_intracranial_y->count();

        if (nx == ny){
            double miny = min(MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print csf intracranial error - ERR6");
                return res;
            }
            double maxy = max(MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print csf intracranial error - ERR7");
                return res;
            }
            double meany = mean(MRI__vector_csf_corrected_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print csf intracranial error - ERR8");
                return res;
            }
            double sv = stroke_volume(MRI__vector_csf_intracranial_x, MRI__vector_csf_corrected_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print csf intracranial error - ERR9");
                return res;
            }

            MRI__double_csf_corrected_min_intracranial = miny;
            MRI__double_csf_corrected_max_intracranial = maxy;
            MRI__double_csf_corrected_mean_intracranial = meany;
            MRI__double_csf_corrected_amplitude_intracranial = maxy - miny;
            MRI__double_csf_corrected_stroke_volume_intracranial = sv;

            MRI__label_csf_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_csf_min_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_min_intracranial) + ")</span>");
            MRI__label_csf_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_csf_max_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_max_intracranial) + ")</span>");
            MRI__label_csf_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_csf_mean_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_mean_intracranial) + ")</span>");
            MRI__label_csf_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_csf_amplitude_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_amplitude_intracranial) + ")</span>");
            MRI__label_csf_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_csf_stroke_volume_intracranial) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_stroke_volume_intracranial) + ")</span>");
        }
        else{
            MRI__label_csf_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_csf_min_intracranial) + "mm^3/s");
            MRI__label_csf_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_csf_max_intracranial) + "mm^3/s");
            MRI__label_csf_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_csf_mean_intracranial) + "mm^3/s");
            MRI__label_csf_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_csf_amplitude_intracranial) + "mm^3/s");
            MRI__label_csf_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_csf_stroke_volume_intracranial) + "mm^3/s");
        }

        statusbar_show_message("Print csf intracranial done");
        return true;
    }
    else{
        statusbar_show_warning("Print csf intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_arteriovenous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenous_intracranial->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenous_flow_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenous_flow_intracranial_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenous_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenous_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenous_flow_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR4");
                return res;
            }
            double sv = stroke_volume(MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR5");
                return res;
            }

            MRI__double_arteriovenous_flow_min_intracranial = miny;
            MRI__double_arteriovenous_flow_max_intracranial = maxy;
            MRI__double_arteriovenous_flow_mean_intracranial = meany;
            MRI__double_arteriovenous_flow_amplitude_intracranial = maxy - miny;
            MRI__double_arteriovenous_flow_stroke_volume_intracranial = sv;

            MRI__label_arteriovenous_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenous_flow_min_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenous_flow_max_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenous_flow_mean_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenous_flow_amplitude_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arteriovenous_flow_stroke_volume_intracranial) + " mm^3/s");

            statusbar_show_message("Print arteriovenous intracranial done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenous intracranial error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenous_volume_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenous_volume_intracranial_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenous_volume_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous intracranial error - ERR4");
                return res;
            }

            MRI__double_arteriovenous_volume_min_intracranial = miny;
            MRI__double_arteriovenous_volume_max_intracranial = maxy;
            MRI__double_arteriovenous_volume_mean_intracranial = meany;
            MRI__double_arteriovenous_volume_amplitude_intracranial = maxy - miny;

            MRI__label_arteriovenous_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenous_volume_min_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenous_volume_max_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenous_volume_mean_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenous_volume_amplitude_intracranial) + " mm^3/s");
            MRI__label_arteriovenous_stroke_volume_intracranial->setText("");

            statusbar_show_message("Print arteriovenous intracranial done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenous intracranial error - ERR1");
            return false;
        }
    }
}

bool MainWindow::MRI__do_print_arteriovenouscsf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenouscsf_intracranial->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenouscsf_flow_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_flow_intracranial_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenouscsf_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenouscsf_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenouscsf_flow_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR4");
                return res;
            }
            double sv = stroke_volume(MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR5");
                return res;
            }

            MRI__double_arteriovenouscsf_flow_min_intracranial = miny;
            MRI__double_arteriovenouscsf_flow_max_intracranial = maxy;
            MRI__double_arteriovenouscsf_flow_mean_intracranial = meany;
            MRI__double_arteriovenouscsf_flow_amplitude_intracranial = maxy - miny;
            MRI__double_arteriovenouscsf_flow_stroke_volume_intracranial = sv;

            MRI__label_arteriovenouscsf_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_min_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_max_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_mean_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_amplitude_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_stroke_volume_intracranial->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_stroke_volume_intracranial) + " mm^3/s");

            statusbar_show_message("Print arteriovenousCSF intracranial done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenouscsf_volume_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_volume_intracranial_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenouscsf_volume_intracranial_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR4");
                return res;
            }

            MRI__double_arteriovenouscsf_volume_min_intracranial = miny;
            MRI__double_arteriovenouscsf_volume_max_intracranial = maxy;
            MRI__double_arteriovenouscsf_volume_mean_intracranial = meany;
            MRI__double_arteriovenouscsf_volume_amplitude_intracranial = maxy - miny;

            MRI__label_arteriovenouscsf_min_intracranial->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_min_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_max_intracranial->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_max_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_mean_intracranial->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_mean_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_amplitude_intracranial->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_amplitude_intracranial) + " mm^3/s");
            MRI__label_arteriovenouscsf_stroke_volume_intracranial->setText("");

            statusbar_show_message("Print arteriovenousCSF intracranial done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenousCSF intracranial error - ERR1");
            return false;
        }
    }
}

bool MainWindow::MRI__do_detect_systole_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        double threshold = MRI__doublespinbox_systole_threshold_intracranial->value();
        bool res = detect_systole(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, threshold, MRI__vector_arterial_systole_intracranial_x, MRI__vector_arterial_systole_intracranial_y);
        if (!res){
            statusbar_show_warning("Detect systole error - ERR2");
            return res;
        }

        res = MRI__do_plot_systole_intracranial();
        if (!res){
            statusbar_show_warning("Detect systole error - ERR3");
            return res;
        }
        else{
            statusbar_show_message("Detect systole done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Detect systole error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_adjust_systole_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_intracranial_x->count();
    unsigned int ny = MRI__vector_arterial_intracranial_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;

        double minx = min(MRI__vector_arterial_systole_intracranial_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR2");
            return res;
        }

        int pos;
        move_curve(minx, MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, NULL, &pos, &res);
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR3");
            return res;
        }

        MRI__int_arterial_move_intracranial = pos;

        MRI__vector_arterial_systole_intracranial_x->clear();
        MRI__vector_arterial_systole_intracranial_y->clear();

        res = MRI__do_plot_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR4");
            return res;
        }

        move_curve(pos, MRI__vector_venous_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR5");
            return res;
        }

        MRI__int_venous_move_intracranial = pos;

        if (MRI__vector_venous_corrected_intracranial_y->count() > 0){
            move_curve(pos, MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole intracranial error - ERR6");
                return res;
            }
        }

        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR7");
            return res;
        }

        move_curve(pos, MRI__vector_csf_intracranial_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR8");
            return res;
        }

        MRI__int_csf_move_intracranial = pos;

        if (MRI__vector_csf_corrected_intracranial_y->count() > 0){
            move_curve(pos, MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole intracranial error - ERR8");
                return res;
            }
        }

        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("Adjust systole intracranial error - ERR9");
            return res;
        }
        else{
            statusbar_show_message("Adjust systole intracranial done");
            return res;
        }
    }
    else{
        statusbar_show_warning("Adjust systole intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_ncycles_intracranial(QAction *action){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString action_txt = action->text();
    bool res;
    int ncycles_intracranial = action_txt.toInt(&res);
    if (!res){
        for (int i = 0; i < 3; i++) MRI__menu_ncycles_intracranial->actions().at(i)->setChecked(false);
        statusbar_show_warning("Select number of cycles error - ERR1");
        return false;
    }
    else{
        for (int i = 0; i < 3; i++){
            if (i != (ncycles_intracranial-1)) MRI__menu_ncycles_intracranial->actions().at(i)->setChecked(false);
        }
        MRI__int_ncycles_intracranial = ncycles_intracranial;

        res = MRI__do_plot_arterial_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR2");
            return res;
        }
        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR3");
            return res;
        }
        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR4");
            return res;
        }
        else{
            statusbar_show_message("Select number of cycles done");
            return res;
        }
    }
}

bool MainWindow::MRI__do_legend_intracranial(){
    if (MRI__button_legend_intracranial->isChecked()){
        MRI__plot_arterial_intracranial->legend->setVisible(true);
        MRI__plot_venous_intracranial->legend->setVisible(true);
        MRI__plot_csf_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenous_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_intracranial->legend->setVisible(true);
    }
    else{
        MRI__plot_arterial_intracranial->legend->setVisible(false);
        MRI__plot_venous_intracranial->legend->setVisible(false);
        MRI__plot_csf_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenous_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_intracranial->legend->setVisible(false);
    }

    bool res = MRI__do_plot_arterial_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR1");
        return res;
    }

    res = MRI__do_plot_venous_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR2");
        return res;
    }

    res = MRI__do_plot_csf_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR3");
        return res;
    }

    res = MRI__do_plot_arteriovenous_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR4");
        return res;
    }

    res = MRI__do_plot_arteriovenouscsf_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR5");
        return res;
    }
    else{
        statusbar_show_message("Legend done");
        return res;
    }
}

bool MainWindow::MRI__do_venous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int na = MRI__vector_arterial_intracranial_y->count();
    unsigned int nv = MRI__vector_venous_intracranial_y->count();

    if ((na == nv) && (na != 0)){
        double correction;
        bool res = venous_correction(MRI__vector_arterial_intracranial_y, MRI__vector_venous_intracranial_y, MRI__vector_venous_corrected_intracranial_y, &correction);
        if (!res){
            statusbar_show_warning("Venous intracranial correction error - ERR2");
            return res;
        }
        res = MRI__do_plot_venous_intracranial();
        if (!res){
            statusbar_show_warning("Venous intracranial correction error - ERR3");
            return res;
        }

        MRI__label_venous_intracranial->setText("<b>Correction</b> = " + QString::number(correction));

        statusbar_show_message("Venous intracranial corrected");
        return true;
    }
    else{
        statusbar_show_warning("Venous intracranial correction error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_csf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int n = MRI__vector_csf_intracranial_y->count();

    if (n != 0){
        double correction;
        bool res = csf_correction(MRI__vector_csf_intracranial_y, MRI__vector_csf_corrected_intracranial_y, &correction);
        if (!res){
            statusbar_show_warning("CSF intracranial correction error - ERR2");
            return res;
        }

        res = MRI__do_plot_csf_intracranial();
        if (!res){
            statusbar_show_warning("CSF intracranial correction error - ERR3");
            return res;
        }

        MRI__label_csf_intracranial->setText("<b>Correction</b> = " + QString::number(correction) + " mm^3/s");

        statusbar_show_message("CSF intracranial corrected");
        return true;
    }
    else{
        statusbar_show_warning("CSF intracranial correction error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    MRI__vector_arteriovenous_flow_intracranial_x->clear();
    MRI__vector_arteriovenous_flow_intracranial_y->clear();
    MRI__vector_arteriovenous_volume_intracranial_x->clear();
    MRI__vector_arteriovenous_volume_intracranial_y->clear();

    unsigned int nax = MRI__vector_arterial_intracranial_x->count();
    unsigned int nay = MRI__vector_arterial_intracranial_y->count();
    unsigned int nvy = MRI__vector_venous_corrected_intracranial_y->count();

    if ((nax == nay) && (nvy == nay) && (nax != 0)){
        bool res = arteriovenous_flow(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, MRI__vector_venous_corrected_intracranial_y, MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial error - ERR2");
            return res;
        }

        res = arteriovenous_volume(MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y, MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial error - ERR3");
            return res;
        }

        res = MRI__do_plot_arteriovenous_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial error - ERR4");
            return res;
        }

        res = MRI__do_plot_arteriovenous_flow_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR5");
            return res;
        }

        res = MRI__do_plot_arteriovenous_volume_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR6");
            return res;
        }

        res = COMPLIANCE__do_plot_arteriovenous_volume_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR7");
            return res;
        }

        res = TRANSFERTFUNCTION__do_plot_arteriovenous_volume_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR8");
            return res;
        }

        res = MRI__do_arteriovenous_flow_intracranial_spectrum();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR9");
            return res;
        }

        res = MRI__do_arteriovenous_volume_intracranial_spectrum();
        if (!res){
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR10");
            return res;
        }

        statusbar_show_message("Arteriovenous intracranial done");
        return res;
    }
    else{
        statusbar_show_warning("Arteriovenous intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenous_auto_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = MRI__do_venous_intracranial();
    if (!res){
        statusbar_show_warning("Arteriovenous AUTO intracranial error - ERR1");
        return res;
    }
    res = MRI__do_arteriovenous_intracranial();
    if (!res){
        statusbar_show_warning("Arteriovenous AUTO intracranial error - ERR2");
        return res;
    }
    else{
        statusbar_show_message("Arteriovenous AUTO intracranial done");
        return res;
    }
}

bool MainWindow::MRI__do_arteriovenouscsf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__vector_arteriovenouscsf_flow_intracranial_x->clear();
    MRI__vector_arteriovenouscsf_flow_intracranial_y->clear();
    MRI__vector_arteriovenouscsf_volume_intracranial_x->clear();
    MRI__vector_arteriovenouscsf_volume_intracranial_y->clear();

    unsigned int nax = MRI__vector_arterial_intracranial_x->count();
    unsigned int nay = MRI__vector_arterial_intracranial_y->count();
    unsigned int nvy = MRI__vector_venous_corrected_intracranial_y->count();
    unsigned int ncy = MRI__vector_csf_corrected_spinal_y->count(); //SPINAL CSF FLOW TO CALCULATE AVCSF INTRACRANIAL

    if ((nax == nay) && (nvy == nay) && (ncy == nay) && (nax != 0)){
        bool res = arteriovenouscsf_flow(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, MRI__vector_venous_corrected_intracranial_y, MRI__vector_csf_corrected_spinal_y, MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial error - ERR2");
            return res;
        }

        res = arteriovenouscsf_volume(MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y, MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial error - ERR3");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial error - ERR4");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_flow_spinal_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR5");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_volume_spinal_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR6");
            return res;
        }

        res = COMPLIANCE__do_plot_arteriovenouscsf_volume_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR7");
            return res;
        }

        res = TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR8");
            return res;
        }

        res = MRI__do_arteriovenouscsf_flow_intracranial_spectrum();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR9");
            return res;
        }

        res = MRI__do_arteriovenouscsf_volume_intracranial_spectrum();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR10");
            return res;
        }

        statusbar_show_message("ArteriovenousCSF intracranial done");
        return res;
    }
    else{
        statusbar_show_warning("ArteriovenousCSF intracranial error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenouscsf_auto_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = MRI__do_venous_intracranial();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO intracranial error - ERR1");
        return res;
    }
    res = MRI__do_csf_intracranial();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO intracranial error - ERR2");
        return res;
    }
    res = MRI__do_arteriovenouscsf_intracranial();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO intracranial error - ERR3");
        return res;
    }
    else{
        statusbar_show_message("ArteriovenousCSF AUTO intracranial done");
        return res;
    }
}

bool MainWindow::MRI__do_plot_arteriovenous_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenous_intracranial->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenous_flow_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenous_flow_intracranial_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenous_intracranial, 0, MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y);
            if (!res){
                statusbar_show_warning("Arteriovenous intracranial plot error - ERR2");
                return res;
            }

            res = MRI__do_print_arteriovenous_intracranial();
            if (!res){
                statusbar_show_warning("Arteriovenous intracranial plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("Arteriovenous intracranial plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenous_volume_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenous_volume_intracranial_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenous_intracranial, 0, MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y);
            if (!res){
                statusbar_show_warning("Arteriovenous intracranial plot error - ERR4");
                return res;
            }

            res = MRI__do_print_arteriovenous_intracranial();
            if (!res){
                statusbar_show_warning("Arteriovenous intracranial plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("Arteriovenous intracranial plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("Arteriovenous intracranial plot error - ERR3");
            return false;
        }
    }
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenouscsf_intracranial->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenouscsf_flow_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_flow_intracranial_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenouscsf_intracranial, 0, MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y);
            if (!res){
                statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR2");
                return res;
            }

            res = MRI__do_print_arteriovenouscsf_intracranial();
            if (!res){
                statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("ArteriovenousCSF intracranial plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenouscsf_volume_intracranial_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_volume_intracranial_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenouscsf_intracranial, 0, MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y);
            if (!res){
                statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR4");
                return res;
            }

            res = MRI__do_print_arteriovenouscsf_intracranial();
            if (!res){
                statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("ArteriovenousCSF intracranial plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("ArteriovenousCSF intracranial plot error - ERR3");
            return false;
        }
    }
}



