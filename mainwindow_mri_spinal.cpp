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

void MainWindow::MRI__init_var_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_spinal = new QMenu;

    //VBox
    MRI__vbox_arterial_button_spinal = new QVBoxLayout;
    MRI__vbox_arterial_spinal = new QVBoxLayout;
    MRI__vbox_venous_button_spinal = new QVBoxLayout;
    MRI__vbox_venous_spinal = new QVBoxLayout;
    MRI__vbox_csf_button_spinal = new QVBoxLayout;
    MRI__vbox_csf_spinal = new QVBoxLayout;
    MRI__vbox_arteriovenous_spinal = new QVBoxLayout;
    MRI__vbox_arteriovenouscsf_spinal = new QVBoxLayout;

    //HBox
    MRI__hbox_arterial_spinal = new QHBoxLayout;
    MRI__hbox_venous_spinal = new QHBoxLayout;
    MRI__hbox_csf_spinal = new QHBoxLayout;
    MRI__hbox_arteriovenous_spinal = new QHBoxLayout;
    MRI__hbox_arteriovenouscsf_spinal = new QHBoxLayout;

    //Plot
    MRI__plot_arterial_spinal = new QCustomPlot;
    MRI__plot_venous_spinal = new QCustomPlot;
    MRI__plot_csf_spinal = new QCustomPlot;
    MRI__plot_arteriovenous_spinal = new QCustomPlot;
    MRI__plot_arteriovenouscsf_spinal = new QCustomPlot;

    //Label
    MRI__label_venous_spinal = new QLabel;
    MRI__label_csf_spinal = new QLabel;
    MRI__label_arterial_quality_spinal = new QLabel;
    MRI__label_arterial_heart_rate_spinal = new QLabel;
    MRI__label_arterial_min_spinal = new QLabel;
    MRI__label_arterial_max_spinal = new QLabel;
    MRI__label_arterial_mean_spinal = new QLabel;
    MRI__label_arterial_amplitude_spinal = new QLabel;
    MRI__label_arterial_stroke_volume_spinal = new QLabel;
    MRI__label_venous_quality_spinal = new QLabel;
    MRI__label_venous_min_spinal = new QLabel;
    MRI__label_venous_max_spinal = new QLabel;
    MRI__label_venous_mean_spinal = new QLabel;
    MRI__label_venous_amplitude_spinal = new QLabel;
    MRI__label_venous_stroke_volume_spinal = new QLabel;
    MRI__label_csf_quality_spinal = new QLabel;
    MRI__label_csf_heart_rate_spinal = new QLabel;
    MRI__label_csf_min_spinal = new QLabel;
    MRI__label_csf_max_spinal = new QLabel;
    MRI__label_csf_mean_spinal = new QLabel;
    MRI__label_csf_amplitude_spinal = new QLabel;
    MRI__label_csf_stroke_volume_spinal = new QLabel;
    MRI__label_arteriovenous_min_spinal = new QLabel;
    MRI__label_arteriovenous_max_spinal = new QLabel;
    MRI__label_arteriovenous_mean_spinal = new QLabel;
    MRI__label_arteriovenous_amplitude_spinal = new QLabel;
    MRI__label_arteriovenous_stroke_volume_spinal = new QLabel;
    MRI__label_arteriovenouscsf_min_spinal = new QLabel;
    MRI__label_arteriovenouscsf_max_spinal = new QLabel;
    MRI__label_arteriovenouscsf_mean_spinal = new QLabel;
    MRI__label_arteriovenouscsf_amplitude_spinal = new QLabel;
    MRI__label_arteriovenouscsf_stroke_volume_spinal = new QLabel;

    //SpinBox
    MRI__spinbox_arterial_quality_spinal = new QSpinBox;
    MRI__spinbox_venous_quality_spinal = new QSpinBox;
    MRI__spinbox_csf_quality_spinal = new QSpinBox;

    MRI__doublespinbox_systole_threshold_spinal = new QDoubleSpinBox;

    //ComboBox
    MRI__combobox_flow_volume_arteriovenous_spinal = new QComboBox;
    MRI__combobox_flow_volume_arteriovenouscsf_spinal = new QComboBox;

    //Button
    MRI__button_detect_systole_spinal = new QPushButton;
    MRI__button_adjust_systole_spinal = new QPushButton;
    MRI__button_hide_systole_spinal = new QPushButton;
    MRI__button_plot_00_spinal = new QPushButton;
    MRI__button_menu_ncycles_spinal = new QPushButton;
    MRI__button_legend_spinal = new QPushButton;
    MRI__button_venous_spinal = new QPushButton;
    MRI__button_csf_spinal = new QPushButton;
    MRI__button_arteriovenous_spinal = new QPushButton;
    MRI__button_arteriovenous_auto_spinal = new QPushButton;
    MRI__button_arteriovenouscsf_spinal = new QPushButton;
    MRI__button_arteriovenouscsf_auto_spinal = new QPushButton;
    MRI__button_restore_arterial_spinal = new QPushButton;
    MRI__button_smooth_arterial_spinal = new QPushButton;
    MRI__button_move_right_arterial_spinal = new QPushButton;
    MRI__button_move_left_arterial_spinal = new QPushButton;
    MRI__button_restore_venous_spinal = new QPushButton;
    MRI__button_smooth_venous_spinal = new QPushButton;
    MRI__button_move_right_venous_spinal = new QPushButton;
    MRI__button_move_left_venous_spinal = new QPushButton;
    MRI__button_show_up_venous_spinal = new QPushButton;
    MRI__button_restore_csf_spinal = new QPushButton;
    MRI__button_smooth_csf_spinal = new QPushButton;
    MRI__button_move_right_csf_spinal = new QPushButton;
    MRI__button_move_left_csf_spinal = new QPushButton;

    //Vector
    MRI__vector_arterial_spinal_x = new QVector<double>;
    MRI__vector_arterial_spinal_y = new QVector<double>;
    MRI__vector_arterial_systole_spinal_x = new QVector<double>;
    MRI__vector_arterial_systole_spinal_y = new QVector<double>;
    MRI__vector_venous_spinal_x = new QVector<double>;
    MRI__vector_venous_spinal_y = new QVector<double>;
    MRI__vector_venous_corrected_spinal_y = new QVector<double>;
    MRI__vector_csf_spinal_x = new QVector<double>;
    MRI__vector_csf_spinal_y = new QVector<double>;
    MRI__vector_csf_corrected_spinal_y = new QVector<double>;
    MRI__vector_arteriovenous_flow_spinal_x = new QVector<double>;
    MRI__vector_arteriovenous_flow_spinal_y = new QVector<double>;
    MRI__vector_arteriovenous_volume_spinal_x = new QVector<double>;
    MRI__vector_arteriovenous_volume_spinal_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_spinal_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_spinal_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_spinal_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_spinal_y = new QVector<double>;

    //Double
    MRI__double_arterial_heart_rate_spinal = 0.;
    MRI__double_arterial_min_spinal = 0.;
    MRI__double_arterial_max_spinal = 0.;
    MRI__double_arterial_mean_spinal = 0.;
    MRI__double_arterial_amplitude_spinal = 0.;
    MRI__double_arterial_stroke_volume_spinal = 0.;
    MRI__double_venous_min_spinal = 0.;
    MRI__double_venous_max_spinal = 0.;
    MRI__double_venous_mean_spinal = 0.;
    MRI__double_venous_amplitude_spinal = 0.;
    MRI__double_venous_stroke_volume_spinal = 0.;
    MRI__double_venous_corrected_min_spinal = 0.;
    MRI__double_venous_corrected_max_spinal = 0.;
    MRI__double_venous_corrected_mean_spinal = 0.;
    MRI__double_venous_corrected_amplitude_spinal = 0.;
    MRI__double_venous_corrected_stroke_volume_spinal = 0.;
    MRI__double_csf_heart_rate_spinal = 0.;
    MRI__double_csf_min_spinal = 0.;
    MRI__double_csf_max_spinal = 0.;
    MRI__double_csf_mean_spinal = 0.;
    MRI__double_csf_amplitude_spinal = 0.;
    MRI__double_csf_stroke_volume_spinal = 0.;
    MRI__double_csf_corrected_min_spinal = 0.;
    MRI__double_csf_corrected_max_spinal = 0.;
    MRI__double_csf_corrected_mean_spinal = 0.;
    MRI__double_csf_corrected_amplitude_spinal = 0.;
    MRI__double_csf_corrected_stroke_volume_spinal = 0.;
    MRI__double_arteriovenous_flow_min_spinal = 0.;
    MRI__double_arteriovenous_flow_max_spinal = 0.;
    MRI__double_arteriovenous_flow_mean_spinal = 0.;
    MRI__double_arteriovenous_flow_amplitude_spinal = 0.;
    MRI__double_arteriovenous_flow_stroke_volume_spinal = 0.;
    MRI__double_arteriovenous_volume_min_spinal = 0.;
    MRI__double_arteriovenous_volume_max_spinal = 0.;
    MRI__double_arteriovenous_volume_mean_spinal = 0.;
    MRI__double_arteriovenous_volume_amplitude_spinal = 0.;
    MRI__double_arteriovenouscsf_flow_min_spinal = 0.;
    MRI__double_arteriovenouscsf_flow_max_spinal = 0.;
    MRI__double_arteriovenouscsf_flow_mean_spinal = 0.;
    MRI__double_arteriovenouscsf_flow_amplitude_spinal = 0.;
    MRI__double_arteriovenouscsf_flow_stroke_volume_spinal = 0.;
    MRI__double_arteriovenouscsf_volume_min_spinal = 0.;
    MRI__double_arteriovenouscsf_volume_max_spinal = 0.;
    MRI__double_arteriovenouscsf_volume_mean_spinal = 0.;
    MRI__double_arteriovenouscsf_volume_amplitude_spinal = 0.;

    //Int
    MRI__int_ncycles_spinal = 1;
    MRI__int_arterial_move_spinal = 0;
    MRI__int_venous_move_spinal = 0;
    MRI__int_csf_move_spinal = 0;
}

void MainWindow::MRI__init_win_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_spinal->setTitle("Number of cycles");
    {
        QAction *action1 = new QAction("1", this);
        QAction *action2 = new QAction("2", this);
        QAction *action3 = new QAction("3", this);

        action1->setCheckable(true);
        action2->setCheckable(true);
        action3->setCheckable(true);

        MRI__menu_ncycles_spinal->addAction(action1);
        MRI__menu_ncycles_spinal->addAction(action2);
        MRI__menu_ncycles_spinal->addAction(action3);
    }

    //Grid
    MRI__grid_spinal->addLayout(MRI__hbox_arterial_spinal, 0, 0, 1, 10);
    MRI__grid_spinal->addWidget(MRI__plot_arterial_spinal, 1, 0, 10, 10);
    MRI__grid_spinal->addLayout(MRI__vbox_arterial_button_spinal, 0, 10, 11, 1);
    MRI__grid_spinal->addLayout(MRI__vbox_arterial_spinal, 0, 11, 11, 1);
    MRI__grid_spinal->addLayout(MRI__hbox_venous_spinal, 11, 0, 1, 10);
    MRI__grid_spinal->addWidget(MRI__plot_venous_spinal, 12, 0, 10, 10);
    MRI__grid_spinal->addLayout(MRI__vbox_venous_button_spinal, 11, 10, 11, 1);
    MRI__grid_spinal->addLayout(MRI__vbox_venous_spinal, 11, 11, 11, 1);
    MRI__grid_spinal->addLayout(MRI__hbox_csf_spinal, 22, 0, 1, 10);
    MRI__grid_spinal->addWidget(MRI__plot_csf_spinal, 23, 0, 10, 10);
    MRI__grid_spinal->addLayout(MRI__vbox_csf_button_spinal, 22, 10, 11, 1);
    MRI__grid_spinal->addLayout(MRI__vbox_csf_spinal, 22, 11, 11, 1);
    MRI__grid_spinal->addLayout(MRI__hbox_arteriovenous_spinal, 33, 0, 1, 5);
    MRI__grid_spinal->addWidget(MRI__plot_arteriovenous_spinal, 34, 0, 10, 5);
    MRI__grid_spinal->addLayout(MRI__vbox_arteriovenous_spinal, 33, 5, 10, 1);
    MRI__grid_spinal->addLayout(MRI__hbox_arteriovenouscsf_spinal, 33, 6, 1, 5);
    MRI__grid_spinal->addWidget(MRI__plot_arteriovenouscsf_spinal, 34, 6, 10, 5);
    MRI__grid_spinal->addLayout(MRI__vbox_arteriovenouscsf_spinal, 33, 11, 10, 1);

    //VBox
    MRI__vbox_arterial_button_spinal->addWidget(MRI__button_restore_arterial_spinal);
    MRI__vbox_arterial_button_spinal->addWidget(MRI__button_smooth_arterial_spinal);
    MRI__vbox_arterial_button_spinal->addWidget(MRI__button_move_right_arterial_spinal);
    MRI__vbox_arterial_button_spinal->addWidget(MRI__button_move_left_arterial_spinal);
    MRI__vbox_arterial_button_spinal->addWidget(MRI__label_arterial_quality_spinal);
    MRI__vbox_arterial_button_spinal->addWidget(MRI__spinbox_arterial_quality_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_heart_rate_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_min_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_max_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_mean_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_amplitude_spinal);
    MRI__vbox_arterial_spinal->addWidget(MRI__label_arterial_stroke_volume_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__button_restore_venous_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__button_smooth_venous_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__button_move_right_venous_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__button_move_left_venous_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__button_show_up_venous_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__label_venous_quality_spinal);
    MRI__vbox_venous_button_spinal->addWidget(MRI__spinbox_venous_quality_spinal);
    MRI__vbox_venous_spinal->addWidget(MRI__label_venous_min_spinal);
    MRI__vbox_venous_spinal->addWidget(MRI__label_venous_max_spinal);
    MRI__vbox_venous_spinal->addWidget(MRI__label_venous_mean_spinal);
    MRI__vbox_venous_spinal->addWidget(MRI__label_venous_amplitude_spinal);
    MRI__vbox_venous_spinal->addWidget(MRI__label_venous_stroke_volume_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__button_restore_csf_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__button_smooth_csf_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__button_move_right_csf_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__button_move_left_csf_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__label_csf_quality_spinal);
    MRI__vbox_csf_button_spinal->addWidget(MRI__spinbox_csf_quality_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_heart_rate_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_min_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_max_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_mean_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_amplitude_spinal);
    MRI__vbox_csf_spinal->addWidget(MRI__label_csf_stroke_volume_spinal);
    MRI__vbox_arteriovenous_spinal->addWidget(MRI__label_arteriovenous_min_spinal);
    MRI__vbox_arteriovenous_spinal->addWidget(MRI__label_arteriovenous_max_spinal);
    MRI__vbox_arteriovenous_spinal->addWidget(MRI__label_arteriovenous_mean_spinal);
    MRI__vbox_arteriovenous_spinal->addWidget(MRI__label_arteriovenous_amplitude_spinal);
    MRI__vbox_arteriovenous_spinal->addWidget(MRI__label_arteriovenous_stroke_volume_spinal);
    MRI__vbox_arteriovenouscsf_spinal->addWidget(MRI__label_arteriovenouscsf_min_spinal);
    MRI__vbox_arteriovenouscsf_spinal->addWidget(MRI__label_arteriovenouscsf_max_spinal);
    MRI__vbox_arteriovenouscsf_spinal->addWidget(MRI__label_arteriovenouscsf_mean_spinal);
    MRI__vbox_arteriovenouscsf_spinal->addWidget(MRI__label_arteriovenouscsf_amplitude_spinal);
    MRI__vbox_arteriovenouscsf_spinal->addWidget(MRI__label_arteriovenouscsf_stroke_volume_spinal);

    //HBox
    MRI__hbox_arterial_spinal->addWidget(MRI__button_detect_systole_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__doublespinbox_systole_threshold_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__button_adjust_systole_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__button_hide_systole_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__button_plot_00_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__button_menu_ncycles_spinal);
    MRI__hbox_arterial_spinal->addWidget(MRI__button_legend_spinal);

    MRI__hbox_venous_spinal->addWidget(MRI__button_venous_spinal);
    MRI__hbox_venous_spinal->addWidget(MRI__label_venous_spinal);

    MRI__hbox_csf_spinal->addWidget(MRI__button_csf_spinal);
    MRI__hbox_csf_spinal->addWidget(MRI__label_csf_spinal);

    MRI__hbox_arteriovenous_spinal->addWidget(MRI__button_arteriovenous_spinal);
    MRI__hbox_arteriovenous_spinal->addWidget(MRI__button_arteriovenous_auto_spinal);
    MRI__hbox_arteriovenous_spinal->addWidget(MRI__combobox_flow_volume_arteriovenous_spinal);

    MRI__hbox_arteriovenouscsf_spinal->addWidget(MRI__button_arteriovenouscsf_spinal);
    MRI__hbox_arteriovenouscsf_spinal->addWidget(MRI__button_arteriovenouscsf_auto_spinal);
    MRI__hbox_arteriovenouscsf_spinal->addWidget(MRI__combobox_flow_volume_arteriovenouscsf_spinal);

    //Plot
    MRI__plot_arterial_spinal->addGraph();
    MRI__plot_arterial_spinal->addGraph();
    MRI__plot_venous_spinal->addGraph();
    MRI__plot_venous_spinal->addGraph();
    MRI__plot_csf_spinal->addGraph();
    MRI__plot_csf_spinal->addGraph();
    MRI__plot_arteriovenous_spinal->addGraph();
    MRI__plot_arteriovenouscsf_spinal->addGraph();

    //Label
    MRI__label_arterial_quality_spinal->setText("Quality");
    MRI__label_venous_quality_spinal->setText("Quality");
    MRI__label_csf_quality_spinal->setText("Quality");

    //SpinBox
    MRI__spinbox_arterial_quality_spinal->setRange(0, 5);
    MRI__spinbox_arterial_quality_spinal->setValue(5);
    MRI__spinbox_venous_quality_spinal->setRange(0, 5);
    MRI__spinbox_venous_quality_spinal->setValue(5);
    MRI__spinbox_csf_quality_spinal->setRange(0, 5);
    MRI__spinbox_csf_quality_spinal->setValue(5);

    MRI__doublespinbox_systole_threshold_spinal->setRange(0., 0.);
    MRI__doublespinbox_systole_threshold_spinal->setToolTip("Systole detection threshold");

    //ComboBox
    MRI__combobox_flow_volume_arteriovenous_spinal->addItem("Flow");
    MRI__combobox_flow_volume_arteriovenous_spinal->addItem("Volume");
    MRI__combobox_flow_volume_arteriovenouscsf_spinal->addItem("Flow");
    MRI__combobox_flow_volume_arteriovenouscsf_spinal->addItem("Volume");

    //Button
    MRI__button_detect_systole_spinal->setText("Detect systole");
    MRI__button_adjust_systole_spinal->setText("Adjust from systole");
    MRI__button_hide_systole_spinal->setText("Hide systole");
    MRI__button_plot_00_spinal->setText("Plot (0,0)");
    MRI__button_plot_00_spinal->setCheckable(true);
    MRI__button_menu_ncycles_spinal->setText("Number of cycles");
    MRI__button_menu_ncycles_spinal->setMenu(MRI__menu_ncycles_spinal);
    MRI__button_legend_spinal->setText("Legend");
    MRI__button_legend_spinal->setCheckable(true);
    MRI__button_venous_spinal->setText("Venous correction");
    MRI__button_csf_spinal->setText("CSF correction");
    MRI__button_arteriovenous_spinal->setText("AV");
    MRI__button_arteriovenous_auto_spinal->setText("AUTO");
    MRI__button_arteriovenouscsf_spinal->setText("AVCSF");
    MRI__button_arteriovenouscsf_auto_spinal->setText("AUTO");
    MRI__button_restore_arterial_spinal->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_arterial_spinal->setToolTip("Restore");
    MRI__button_smooth_arterial_spinal->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_arterial_spinal->setToolTip("Smooth");
    MRI__button_move_right_arterial_spinal->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_arterial_spinal->setToolTip("Move right");
    MRI__button_move_left_arterial_spinal->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_arterial_spinal->setToolTip("Move left");
    MRI__button_restore_venous_spinal->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_venous_spinal->setToolTip("Restore");
    MRI__button_smooth_venous_spinal->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_venous_spinal->setToolTip("Smooth");
    MRI__button_move_right_venous_spinal->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_venous_spinal->setToolTip("Move right");
    MRI__button_move_left_venous_spinal->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_venous_spinal->setToolTip("Move left");
    MRI__button_show_up_venous_spinal->setIcon(QIcon("img/up.png"));
    MRI__button_show_up_venous_spinal->setToolTip("Show up");
    MRI__button_show_up_venous_spinal->setCheckable(true);
    MRI__button_restore_csf_spinal->setIcon(QIcon("img/restore.png"));
    MRI__button_restore_csf_spinal->setToolTip("Restore");
    MRI__button_smooth_csf_spinal->setIcon(QIcon("img/smooth.png"));
    MRI__button_smooth_csf_spinal->setToolTip("Smooth");
    MRI__button_move_right_csf_spinal->setIcon(QIcon("img/right.png"));
    MRI__button_move_right_csf_spinal->setToolTip("Move right");
    MRI__button_move_left_csf_spinal->setIcon(QIcon("img/left.png"));
    MRI__button_move_left_csf_spinal->setToolTip("Move left");
}

void MainWindow::MRI__init_sig_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //ComboBox
    connect(MRI__combobox_flow_volume_arteriovenous_spinal, SIGNAL(currentIndexChanged(int)), this, SLOT(MRI__do_plot_arteriovenous_spinal()));
    connect(MRI__combobox_flow_volume_arteriovenouscsf_spinal, SIGNAL(currentIndexChanged(int)), this, SLOT(MRI__do_plot_arteriovenouscsf_spinal()));

    //Button
    connect(MRI__button_plot_00_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_arterial_spinal()));
    connect(MRI__button_plot_00_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_spinal()));
    connect(MRI__button_plot_00_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_csf_spinal()));
    connect(MRI__menu_ncycles_spinal, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_ncycles_spinal(QAction*)));
    connect(MRI__button_detect_systole_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_detect_systole_spinal()));
    connect(MRI__button_adjust_systole_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_adjust_systole_spinal()));
    connect(MRI__button_hide_systole_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_arterial_spinal()));
    connect(MRI__button_legend_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_legend_spinal()));
    connect(MRI__button_venous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_venous_spinal()));
    connect(MRI__button_csf_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_csf_spinal()));
    connect(MRI__button_arteriovenous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenous_spinal()));
    connect(MRI__button_arteriovenous_auto_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenous_auto_spinal()));
    connect(MRI__button_arteriovenouscsf_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenouscsf_spinal()));
    connect(MRI__button_arteriovenouscsf_auto_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_arteriovenouscsf_auto_spinal()));
    connect(MRI__button_smooth_arterial_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_arterial_spinal()));
    connect(MRI__button_smooth_venous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_venous_spinal()));
    connect(MRI__button_smooth_csf_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_smooth_csf_spinal()));
    connect(MRI__button_move_right_arterial_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_arterial_spinal()));
    connect(MRI__button_move_right_venous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_venous_spinal()));
    connect(MRI__button_move_right_csf_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_right_csf_spinal()));
    connect(MRI__button_move_left_arterial_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_arterial_spinal()));
    connect(MRI__button_move_left_venous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_venous_spinal()));
    connect(MRI__button_move_left_csf_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_move_left_csf_spinal()));
    connect(MRI__button_show_up_venous_spinal, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_spinal()));
}

void MainWindow::MRI__init_css_spinal(){
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
    MRI__plot_arterial_spinal->graph(0)->setPen(RedPen);
    MRI__plot_arterial_spinal->graph(0)->setName("Arterial");
    MRI__plot_arterial_spinal->graph(1)->setPen(RedPen);
    MRI__plot_arterial_spinal->graph(1)->setLineStyle(QCPGraph::lsNone);
    MRI__plot_arterial_spinal->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    MRI__plot_arterial_spinal->graph(1)->setName("Systole");

    MRI__plot_venous_spinal->graph(0)->setPen(BluePen);
    MRI__plot_venous_spinal->graph(0)->setName("Venous");
    MRI__plot_venous_spinal->graph(1)->setPen(BlueDotPen);
    MRI__plot_venous_spinal->graph(1)->setName("Venous corrected");

    MRI__plot_csf_spinal->graph(0)->setPen(GreenPen);
    MRI__plot_csf_spinal->graph(0)->setName("CSF");
    MRI__plot_csf_spinal->graph(1)->setPen(GreenDotPen);
    MRI__plot_csf_spinal->graph(1)->setName("CSF corrected");

    MRI__plot_arteriovenous_spinal->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_spinal->graph(0)->setName("A-V");

    MRI__plot_arteriovenouscsf_spinal->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_spinal->graph(0)->setName("A-V-CSF");
}

bool MainWindow::MRI__do_plot_arterial_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__plot_arterial_spinal->graph(1)->clearData();

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;

        if (MRI__int_ncycles_spinal > 1){
            double maxx = max(MRI__vector_arterial_spinal_x, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR2-1");
                return res;
            }

            QVector<double> TMP__arterial_x, TMP__arterial_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nx;
                TMP__arterial_x.append(MRI__vector_arterial_spinal_x->at(i%nx) + current_cycle*maxx);
                TMP__arterial_y.append(MRI__vector_arterial_spinal_y->at(i%ny));
            }

            res = plot(MRI__plot_arterial_spinal, 0, &TMP__arterial_x, &TMP__arterial_y);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR2-2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_arterial_spinal, 0, MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR2");
                return res;
            }
        }
        if (MRI__button_plot_00_spinal->isChecked()){
            MRI__plot_arterial_spinal->yAxis->setRangeLower(0.);
            MRI__plot_arterial_spinal->replot();
        }

        res = MRI__do_print_arterial_spinal();
        if (!res){
            statusbar_show_warning("Arterial spinal plot error - ERR3");
            return res;
        }

        res = MRI__do_plot_arterial_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arterial spinal plot error - ERR4");
            return res;
        }

        res = MRI__do_arterial_spinal_spectrum();
        if (!res){
            statusbar_show_warning("Arterial spinal plot error - ERR5");
            return res;
        }

        statusbar_show_message("Arterial spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("Arterial spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_spinal_x->count();
    unsigned int ny = MRI__vector_venous_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        if (MRI__button_show_up_venous_spinal->isChecked()){
            QVector<double> TMP__venous_x, TMP__venous_y;
            if (MRI__int_ncycles_spinal > 1){
                double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR2-1");
                    return res;
                }

                for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nx) + current_cycle*maxx);
                    TMP__venous_y.append(-MRI__vector_venous_spinal_y->at(i%ny));
                }
            }
            else{
                for (unsigned int i = 0; i < nx; i++){
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i));
                    TMP__venous_y.append(-MRI__vector_venous_spinal_y->at(i));
                }
            }

            res = plot(MRI__plot_venous_spinal, 0, &TMP__venous_x, &TMP__venous_y);
            if (!res){
                statusbar_show_warning("Venous spinal plot error - ERR2");
                return res;
            }
        }
        else{
            if (MRI__int_ncycles_spinal > 1){
                double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR2-1");
                    return res;
                }

                QVector<double> TMP__venous_x, TMP__venous_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nx) + current_cycle*maxx);
                    TMP__venous_y.append(MRI__vector_venous_spinal_y->at(i%ny));
                }

                res = plot(MRI__plot_venous_spinal, 0, &TMP__venous_x, &TMP__venous_y);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR2-2");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_venous_spinal, 0, MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR2");
                    return res;
                }
            }
        }

        ny = MRI__vector_venous_corrected_spinal_y->count();
        if (nx == ny){
            if (MRI__button_show_up_venous_spinal->isChecked()){
                QVector<double> TMP__venous_x, TMP__venous_y;
                if (MRI__int_ncycles_spinal > 1){
                    double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("Venous spinal plot error - ERR3-1");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nx;
                        TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nx) + current_cycle*maxx);
                        TMP__venous_y.append(-MRI__vector_venous_corrected_spinal_y->at(i%ny));
                    }
                }
                else{
                    for (unsigned int i = 0; i < nx; i++){
                        TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i));
                        TMP__venous_y.append(-MRI__vector_venous_corrected_spinal_y->at(i));
                    }
                }

                res = plot(MRI__plot_venous_spinal, 1, &TMP__venous_x, &TMP__venous_y, false);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR3");
                    return res;
                }
                MRI__plot_venous_spinal->yAxis->setRange(-max(max(MRI__vector_venous_spinal_y), max(MRI__vector_venous_corrected_spinal_y)), -min(min(MRI__vector_venous_spinal_y), min(MRI__vector_venous_corrected_spinal_y)));
            }
            else{
                if (MRI__int_ncycles_spinal > 1){
                    QVector<double> TMP__venous_x, TMP__venous_y;

                    double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("Venous spinal plot error - ERR3-1");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nx;
                        TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nx) + current_cycle*maxx);
                        TMP__venous_y.append(MRI__vector_venous_corrected_spinal_y->at(i%ny));
                    }

                    res = plot(MRI__plot_venous_spinal, 1, &TMP__venous_x, &TMP__venous_y, false);
                    if (!res){
                        statusbar_show_warning("Venous spinal plot error - ERR3-2");
                        return res;
                    }
                }
                else{
                    res = plot(MRI__plot_venous_spinal, 1, MRI__vector_venous_spinal_x, MRI__vector_venous_corrected_spinal_y, false);
                    if (!res){
                        statusbar_show_warning("Venous spinal plot error - ERR3");
                        return res;
                    }
                }
                MRI__plot_venous_spinal->yAxis->setRange(min(min(MRI__vector_venous_spinal_y), min(MRI__vector_venous_corrected_spinal_y)), max(max(MRI__vector_venous_spinal_y), max(MRI__vector_venous_corrected_spinal_y)));
            }

            res = MRI__do_venous_spinal_spectrum();
            if (!res){
                statusbar_show_warning("Venous spinal plot error - ERR6");
                return res;
            }
        }

        if (MRI__button_plot_00_spinal->isChecked()){
            if (MRI__button_show_up_venous_spinal->isChecked()){
                MRI__plot_venous_spinal->yAxis->setRangeLower(0.);
            }
            else{
                MRI__plot_venous_spinal->yAxis->setRangeUpper(0.);
            }
        }

        MRI__plot_venous_spinal->replot();

        res = MRI__do_print_venous_spinal();
        if (!res){
            statusbar_show_warning("Venous spinal plot error - ERR4");
            return res;
        }

        res = MRI__do_plot_venous_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Venous spinal plot error - ERR5");
            return res;
        }

        statusbar_show_message("Venous spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("Venous spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_spinal_x->count();
    unsigned int ny = MRI__vector_csf_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        if (MRI__int_ncycles_spinal > 1){
            double maxx = max(MRI__vector_csf_spinal_x, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal plot error - ERR2-1");
                return res;
            }

            QVector<double> TMP__csf_x, TMP__csf_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nx;
                TMP__csf_x.append(MRI__vector_csf_spinal_x->at(i%nx) + current_cycle*maxx);
                TMP__csf_y.append(MRI__vector_csf_spinal_y->at(i%ny));
            }

            res = plot(MRI__plot_csf_spinal, 0, &TMP__csf_x, &TMP__csf_y);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR2-2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_csf_spinal, 0, MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y);
            if (!res){
                statusbar_show_warning("CSF spinal plot error - ERR2");
                return res;
            }
        }

        ny = MRI__vector_csf_corrected_spinal_y->count();
        if (ny == nx){
            if (MRI__int_ncycles_spinal > 1){
                double maxx = max(MRI__vector_csf_spinal_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF spinal plot error - ERR3-1");
                    return res;
                }

                QVector<double> TMP__csf_x, TMP__csf_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_spinal*nx; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nx;
                    TMP__csf_x.append(MRI__vector_csf_spinal_x->at(i%nx) + current_cycle*maxx);
                    TMP__csf_y.append(MRI__vector_csf_corrected_spinal_y->at(i%ny));
                }

                res = plot(MRI__plot_csf_spinal, 1, &TMP__csf_x, &TMP__csf_y, false);
                if (!res){
                    statusbar_show_warning("Arterial spinal plot error - ERR3-2");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_csf_spinal, 1, MRI__vector_csf_spinal_x, MRI__vector_csf_corrected_spinal_y, false);
                if (!res){
                    statusbar_show_warning("CSF spinal plot error - ERR3");
                    return res;
                }
            }
            MRI__plot_csf_spinal->yAxis->setRange(min(min(MRI__vector_csf_spinal_y), min(MRI__vector_csf_corrected_spinal_y)), max(max(MRI__vector_csf_spinal_y), max(MRI__vector_csf_corrected_spinal_y)));

            res = MRI__do_csf_spinal_spectrum();
            if (!res){
                statusbar_show_warning("CSF spinal plot error - ERR6");
                return res;
            }
        }

        res = MRI__do_print_csf_spinal();
        if (!res){
            statusbar_show_warning("CSF spinal plot error - ERR4");
            return res;
        }

        res = MRI__do_plot_csf_spinal_intracranial();
        if (!res){
            statusbar_show_warning("CSF spinal plot error - ERR5");
            return res;
        }

        statusbar_show_message("CSF spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("CSF spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_plot_systole_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_systole_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_systole_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(MRI__plot_arterial_spinal, 1, MRI__vector_arterial_systole_spinal_x, MRI__vector_arterial_systole_spinal_y, false);
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

bool MainWindow::MRI__do_smooth_arterial_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_arterial_spinal_y);
        if (!res){
            statusbar_show_warning("Smooth arterial error - ERR2");
            return res;
        }

        res = MRI__do_plot_arterial_spinal();
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

bool MainWindow::MRI__do_smooth_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_spinal_x->count();
    unsigned int ny = MRI__vector_venous_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_venous_spinal_y);
        if (!res){
            statusbar_show_warning("Smooth venous error - ERR2");
            return res;
        }

        res = MRI__do_venous_spinal();
        if (!res){
            statusbar_show_warning("Smooth venous error - ERR3");
            return res;
        }

        res = MRI__do_plot_venous_spinal();
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

bool MainWindow::MRI__do_smooth_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_spinal_x->count();
    unsigned int ny = MRI__vector_csf_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = smooth(MRI__vector_csf_spinal_y);
        if (!res){
            statusbar_show_warning("Smooth CSF error - ERR2");
            return res;
        }

        res = MRI__do_csf_spinal();
        if (!res){
            statusbar_show_warning("Smooth CSF error - ERR3");
            return res;
        }

        res = MRI__do_plot_csf_spinal();
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

bool MainWindow::MRI__do_move_right_arterial_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_arterial_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move arterial right error - ERR2");
            return res;
        }

        MRI__int_arterial_move_spinal--;

        res = MRI__do_plot_arterial_spinal();
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

bool MainWindow::MRI__do_move_right_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_spinal_x->count();
    unsigned int ny = MRI__vector_venous_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_venous_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move venous right error - ERR2");
            return res;
        }

        MRI__int_venous_move_spinal--;

        ny = MRI__vector_venous_corrected_spinal_y->count();
        if ((ny == nx)){
            move_curve(-1, MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move venous right error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_venous_spinal();
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

bool MainWindow::MRI__do_move_right_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_spinal_x->count();
    unsigned int ny = MRI__vector_csf_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(-1, MRI__vector_csf_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move CSF right error - ERR2");
            return res;
        }

        MRI__int_csf_move_spinal--;

        ny = MRI__vector_csf_corrected_spinal_y->count();
        if ((ny == nx)){
            move_curve(-1, MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move CSF right error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_csf_spinal();
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

bool MainWindow::MRI__do_move_left_arterial_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_arterial_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move arterial left error - ERR2");
            return res;
        }

        MRI__int_arterial_move_spinal++;

        res = MRI__do_plot_arterial_spinal();
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

bool MainWindow::MRI__do_move_left_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_spinal_x->count();
    unsigned int ny = MRI__vector_venous_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_venous_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move venous left error - ERR2");
            return res;
        }

        MRI__int_venous_move_spinal++;

        ny = MRI__vector_venous_corrected_spinal_y->count();
        if ((ny == nx)){
            move_curve(1, MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move venous left error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_venous_spinal();
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

bool MainWindow::MRI__do_move_left_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_csf_spinal_x->count();
    unsigned int ny = MRI__vector_csf_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        move_curve(1, MRI__vector_csf_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Move CSF left error - ERR2");
            return res;
        }

        MRI__int_csf_move_spinal++;

        ny = MRI__vector_csf_corrected_spinal_y->count();
        if ((ny == nx)){
            move_curve(1, MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Move CSF left error - ERR4");
                return res;
            }
        }

        res = MRI__do_plot_csf_spinal();
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

bool MainWindow::MRI__do_print_arterial_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = MRI__vector_arterial_spinal_x->count();
    int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res;
        double minx = min(MRI__vector_arterial_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR2");
            return res;
        }
        double maxx = max(MRI__vector_arterial_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR3");
            return res;
        }
        double miny = min(MRI__vector_arterial_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR4");
            return res;
        }
        double maxy = max(MRI__vector_arterial_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR5");
            return res;
        }
        double meany = mean(MRI__vector_arterial_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR6");
            return res;
        }
        double sv = stroke_volume(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print arterial spinal error - ERR7");
            return res;
        }

        MRI__double_arterial_heart_rate_spinal = 60. / (maxx - minx);
        MRI__double_arterial_min_spinal = miny;
        MRI__double_arterial_max_spinal = maxy;
        MRI__double_arterial_mean_spinal = meany;
        MRI__double_arterial_amplitude_spinal = maxy - miny;
        MRI__double_arterial_stroke_volume_spinal = sv;

        MRI__label_arterial_heart_rate_spinal->setText("<b>Heart rate</b> = " + QString::number(MRI__double_arterial_heart_rate_spinal) + " bpm");
        MRI__label_arterial_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_arterial_min_spinal) + " mm^3/s");
        MRI__label_arterial_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_arterial_max_spinal) + " mm^3/s");
        MRI__label_arterial_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arterial_mean_spinal) + " mm^3/s");
        MRI__label_arterial_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arterial_amplitude_spinal) + " mm^3/s");
        MRI__label_arterial_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arterial_stroke_volume_spinal) + " mm^3");

        statusbar_show_message("Print arterial spinal done");
        return true;
    }
    else{
        statusbar_show_warning("Print arterial spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_venous_spinal_x->count();
    unsigned int ny = MRI__vector_venous_spinal_x->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double miny = min(MRI__vector_venous_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print venous spinal error - ERR2");
            return res;
        }
        double maxy = max(MRI__vector_venous_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print venous spinal error - ERR3");
            return res;
        }
        double meany = mean(MRI__vector_venous_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print venous spinal error - ERR4");
            return res;
        }
        double sv = stroke_volume(MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print venous spinal error - ERR5");
            return res;
        }

        MRI__double_venous_min_spinal = miny;
        MRI__double_venous_max_spinal = maxy;
        MRI__double_venous_mean_spinal = meany;
        MRI__double_venous_amplitude_spinal = maxy - miny;
        MRI__double_venous_stroke_volume_spinal = sv;

        ny = MRI__vector_venous_corrected_spinal_y->count();

        if (nx == ny){
            double miny = min(MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print venous spinal error - ERR6");
                return res;
            }
            double maxy = max(MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print venous spinal error - ERR7");
                return res;
            }
            double meany = mean(MRI__vector_venous_corrected_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print venous spinal error - ERR8");
                return res;
            }
            double sv = stroke_volume(MRI__vector_venous_spinal_x, MRI__vector_venous_corrected_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print venous spinal error - ERR9");
                return res;
            }

            MRI__double_venous_corrected_min_spinal = miny;
            MRI__double_venous_corrected_max_spinal = maxy;
            MRI__double_venous_corrected_mean_spinal = meany;
            MRI__double_venous_corrected_amplitude_spinal = maxy - miny;
            MRI__double_venous_corrected_stroke_volume_spinal = sv;

            MRI__label_venous_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_venous_min_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_min_spinal) + ")</span>");
            MRI__label_venous_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_venous_max_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_max_spinal) + ")</span>");
            MRI__label_venous_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_venous_mean_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_mean_spinal) + ")</span>");
            MRI__label_venous_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_venous_amplitude_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_amplitude_spinal) + ")</span>");
            MRI__label_venous_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_venous_stroke_volume_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_venous_corrected_stroke_volume_spinal) + ")</span>");
        }
        else{
            MRI__label_venous_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_venous_min_spinal) + "mm^3/s");
            MRI__label_venous_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_venous_max_spinal) + "mm^3/s");
            MRI__label_venous_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_venous_mean_spinal) + "mm^3/s");
            MRI__label_venous_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_venous_amplitude_spinal) + "mm^3/s");
            MRI__label_venous_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_venous_stroke_volume_spinal) + "mm^3/s");
        }

        statusbar_show_message("Print venous spinal done");
        return true;
    }
    else{
        statusbar_show_warning("Print venous spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    unsigned int nx = MRI__vector_csf_spinal_x->count();
    unsigned int ny = MRI__vector_csf_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double miny = min(MRI__vector_csf_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print csf spinal error - ERR2");
            return res;
        }
        double maxy = max(MRI__vector_csf_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Print csf spinal error - ERR3");
            return res;
        }
        double meany = mean(MRI__vector_csf_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print csf spinal error - ERR4");
            return res;
        }
        double sv = stroke_volume(MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y, &res);
        if (!res){
            statusbar_show_warning("Print csf spinal error - ERR5");
            return res;
        }

        MRI__double_csf_min_spinal = miny;
        MRI__double_csf_max_spinal = maxy;
        MRI__double_csf_mean_spinal = meany;
        MRI__double_csf_amplitude_spinal = maxy - miny;
        MRI__double_csf_stroke_volume_spinal = sv;

        ny = MRI__vector_csf_corrected_spinal_y->count();

        if (nx == ny){
            double miny = min(MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print csf spinal error - ERR6");
                return res;
            }
            double maxy = max(MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print csf spinal error - ERR7");
                return res;
            }
            double meany = mean(MRI__vector_csf_corrected_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print csf spinal error - ERR8");
                return res;
            }
            double sv = stroke_volume(MRI__vector_csf_spinal_x, MRI__vector_csf_corrected_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print csf spinal error - ERR9");
                return res;
            }

            MRI__double_csf_corrected_min_spinal = miny;
            MRI__double_csf_corrected_max_spinal = maxy;
            MRI__double_csf_corrected_mean_spinal = meany;
            MRI__double_csf_corrected_amplitude_spinal = maxy - miny;
            MRI__double_csf_corrected_stroke_volume_spinal = sv;

            MRI__label_csf_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_csf_min_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_min_spinal) + ")</span>");
            MRI__label_csf_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_csf_max_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_max_spinal) + ")</span>");
            MRI__label_csf_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_csf_mean_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_mean_spinal) + ")</span>");
            MRI__label_csf_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_csf_amplitude_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_amplitude_spinal) + ")</span>");
            MRI__label_csf_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_csf_stroke_volume_spinal) + "mm^3/s <span style=\"color:red;\">(" + QString::number(MRI__double_csf_corrected_stroke_volume_spinal) + ")</span>");
        }
        else{
            MRI__label_csf_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_csf_min_spinal) + "mm^3/s");
            MRI__label_csf_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_csf_max_spinal) + "mm^3/s");
            MRI__label_csf_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_csf_mean_spinal) + "mm^3/s");
            MRI__label_csf_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_csf_amplitude_spinal) + "mm^3/s");
            MRI__label_csf_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_csf_stroke_volume_spinal) + "mm^3/s");
        }

        statusbar_show_message("Print csf spinal done");
        return true;
    }
    else{
        statusbar_show_warning("Print csf spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_arteriovenous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenous_spinal->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenous_flow_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenous_flow_spinal_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenous_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenous_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenous_flow_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR4");
                return res;
            }
            double sv = stroke_volume(MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR5");
                return res;
            }

            MRI__double_arteriovenous_flow_min_spinal = miny;
            MRI__double_arteriovenous_flow_max_spinal = maxy;
            MRI__double_arteriovenous_flow_mean_spinal = meany;
            MRI__double_arteriovenous_flow_amplitude_spinal = maxy - miny;
            MRI__double_arteriovenous_flow_stroke_volume_spinal = sv;

            MRI__label_arteriovenous_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenous_flow_min_spinal) + " mm^3/s");
            MRI__label_arteriovenous_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenous_flow_max_spinal) + " mm^3/s");
            MRI__label_arteriovenous_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenous_flow_mean_spinal) + " mm^3/s");
            MRI__label_arteriovenous_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenous_flow_amplitude_spinal) + " mm^3/s");
            MRI__label_arteriovenous_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arteriovenous_flow_stroke_volume_spinal) + " mm^3/s");

            statusbar_show_message("Print arteriovenous spinal done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenous spinal error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenous_volume_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenous_volume_spinal_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenous_volume_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenous spinal error - ERR4");
                return res;
            }

            MRI__double_arteriovenous_volume_min_spinal = miny;
            MRI__double_arteriovenous_volume_max_spinal = maxy;
            MRI__double_arteriovenous_volume_mean_spinal = meany;
            MRI__double_arteriovenous_volume_amplitude_spinal = maxy - miny;

            MRI__label_arteriovenous_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenous_volume_min_spinal) + " mm^3/s");
            MRI__label_arteriovenous_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenous_volume_max_spinal) + " mm^3/s");
            MRI__label_arteriovenous_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenous_volume_mean_spinal) + " mm^3/s");
            MRI__label_arteriovenous_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenous_volume_amplitude_spinal) + " mm^3/s");
            MRI__label_arteriovenous_stroke_volume_spinal->setText("");

            statusbar_show_message("Print arteriovenous spinal done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenous spinal error - ERR1");
            return false;
        }
    }
}

bool MainWindow::MRI__do_print_arteriovenouscsf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenouscsf_spinal->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenouscsf_flow_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_flow_spinal_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenouscsf_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenouscsf_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenouscsf_flow_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR4");
                return res;
            }
            double sv = stroke_volume(MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR5");
                return res;
            }

            MRI__double_arteriovenouscsf_flow_min_spinal = miny;
            MRI__double_arteriovenouscsf_flow_max_spinal = maxy;
            MRI__double_arteriovenouscsf_flow_mean_spinal = meany;
            MRI__double_arteriovenouscsf_flow_amplitude_spinal = maxy - miny;
            MRI__double_arteriovenouscsf_flow_stroke_volume_spinal = sv;

            MRI__label_arteriovenouscsf_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_min_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_max_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_mean_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_amplitude_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_stroke_volume_spinal->setText("<b>Stroke volume</b> = " + QString::number(MRI__double_arteriovenouscsf_flow_stroke_volume_spinal) + " mm^3/s");

            statusbar_show_message("Print arteriovenousCSF spinal done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenousCSF spinal error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenouscsf_volume_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_volume_spinal_y->count();

        if ((ny == nx) && (nx != 0)){
            bool res;
            double miny = min(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR2");
                return res;
            }
            double maxy = max(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR3");
                return res;
            }
            double meany = mean(MRI__vector_arteriovenouscsf_volume_spinal_y, &res);
            if (!res){
                statusbar_show_warning("Print arteriovenousCSF spinal error - ERR4");
                return res;
            }

            MRI__double_arteriovenouscsf_volume_min_spinal = miny;
            MRI__double_arteriovenouscsf_volume_max_spinal = maxy;
            MRI__double_arteriovenouscsf_volume_mean_spinal = meany;
            MRI__double_arteriovenouscsf_volume_amplitude_spinal = maxy - miny;

            MRI__label_arteriovenouscsf_min_spinal->setText("<b>Min flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_min_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_max_spinal->setText("<b>Max flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_max_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_mean_spinal->setText("<b>Mean flow</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_mean_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_amplitude_spinal->setText("<b>Flow amplitude</b> = " + QString::number(MRI__double_arteriovenouscsf_volume_amplitude_spinal) + " mm^3/s");
            MRI__label_arteriovenouscsf_stroke_volume_spinal->setText("");

            statusbar_show_message("Print arteriovenousCSF spinal done");
            return true;
        }
        else{
            statusbar_show_warning("Print arteriovenousCSF spinal error - ERR1");
            return false;
        }
    }
}

bool MainWindow::MRI__do_detect_systole_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        double threshold = MRI__doublespinbox_systole_threshold_spinal->value();
        bool res = detect_systole(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, threshold, MRI__vector_arterial_systole_spinal_x, MRI__vector_arterial_systole_spinal_y);
        if (!res){
            statusbar_show_warning("Detect systole error - ERR2");
            return res;
        }

        res = MRI__do_plot_systole_spinal();
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

bool MainWindow::MRI__do_adjust_systole_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arterial_spinal_x->count();
    unsigned int ny = MRI__vector_arterial_spinal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;

        double minx = min(MRI__vector_arterial_systole_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR2");
            return res;
        }

        int pos;
        move_curve(minx, MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, NULL, &pos, &res);
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR3");
            return res;
        }

        MRI__int_arterial_move_spinal = pos;

        MRI__vector_arterial_systole_spinal_x->clear();
        MRI__vector_arterial_systole_spinal_y->clear();

        res = MRI__do_plot_arterial_spinal();
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR4");
            return res;
        }

        move_curve(pos, MRI__vector_venous_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR5");
            return res;
        }

        MRI__int_venous_move_spinal = pos;

        if (MRI__vector_venous_corrected_spinal_y->count() > 0){
            move_curve(pos, MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR6");
                return res;
            }
        }

        res = MRI__do_plot_venous_spinal();
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR7");
            return res;
        }

        move_curve(pos, MRI__vector_csf_spinal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR8");
            return res;
        }

        MRI__int_csf_move_spinal = pos;

        if (MRI__vector_csf_corrected_spinal_y->count() > 0){
            move_curve(pos, MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR8");
                return res;
            }
        }

        res = MRI__do_plot_csf_spinal();
        if (!res){
            statusbar_show_warning("Adjust systole spinal error - ERR9");
            return res;
        }

        int result = QMessageBox::question(this, "Adjust from systole", "Spinal flow have been adjusted.\nDo you want to adjust intracranial flow too?", QMessageBox::Yes | QMessageBox::No);
        if (result == QMessageBox::Yes){
            move_curve(pos, MRI__vector_arterial_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR10");
                return res;
            }

            MRI__int_arterial_move_intracranial = pos;

            res = MRI__do_plot_arterial_intracranial();
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR11");
                return res;
            }

            move_curve(pos, MRI__vector_venous_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR12");
                return res;
            }

            MRI__int_venous_move_intracranial = pos;

            if (MRI__vector_venous_corrected_intracranial_y->count() > 0){
                move_curve(pos, MRI__vector_venous_corrected_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Adjust systole spinal error - ERR13");
                    return res;
                }
            }

            res = MRI__do_plot_venous_intracranial();
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR14");
                return res;
            }

            move_curve(pos, MRI__vector_csf_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR15");
                return res;
            }

            MRI__int_csf_move_intracranial = pos;

            if (MRI__vector_csf_corrected_intracranial_y->count() > 0){
                move_curve(pos, MRI__vector_csf_corrected_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Adjust systole spinal error - ERR16");
                    return res;
                }
            }

            res = MRI__do_plot_csf_intracranial();
            if (!res){
                statusbar_show_warning("Adjust systole spinal error - ERR17");
                return res;
            }
        }

        statusbar_show_message("Adjust systole spinal done");
        return res;
    }
    else{
        statusbar_show_warning("Adjust systole spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_ncycles_spinal(QAction *action){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString action_txt = action->text();
    bool res;
    int ncycles_spinal = action_txt.toInt(&res);
    if (!res){
        for (int i = 0; i < 3; i++) MRI__menu_ncycles_spinal->actions().at(i)->setChecked(false);
        statusbar_show_warning("Select number of cycles error - ERR1");
        return false;
    }
    else{
        for (int i = 0; i < 3; i++){
            if (i != (ncycles_spinal-1)) MRI__menu_ncycles_spinal->actions().at(i)->setChecked(false);
        }
        MRI__int_ncycles_spinal = ncycles_spinal;

        res = MRI__do_plot_arterial_spinal();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR2");
            return res;
        }
        res = MRI__do_plot_venous_spinal();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR3");
            return res;
        }
        res = MRI__do_plot_csf_spinal();
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

bool MainWindow::MRI__do_legend_spinal(){
    if (MRI__button_legend_spinal->isChecked()){
        MRI__plot_arterial_spinal->legend->setVisible(true);
        MRI__plot_venous_spinal->legend->setVisible(true);
        MRI__plot_csf_spinal->legend->setVisible(true);
        MRI__plot_arteriovenous_spinal->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_spinal->legend->setVisible(true);
    }
    else{
        MRI__plot_arterial_spinal->legend->setVisible(false);
        MRI__plot_venous_spinal->legend->setVisible(false);
        MRI__plot_csf_spinal->legend->setVisible(false);
        MRI__plot_arteriovenous_spinal->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_spinal->legend->setVisible(false);
    }

    bool res = MRI__do_plot_arterial_spinal();
    if (!res){
        statusbar_show_warning("Legend error - ERR1");
        return res;
    }

    res = MRI__do_plot_venous_spinal();
    if (!res){
        statusbar_show_warning("Legend error - ERR2");
        return res;
    }

    res = MRI__do_plot_csf_spinal();
    if (!res){
        statusbar_show_warning("Legend error - ERR3");
        return res;
    }

    res = MRI__do_plot_arteriovenous_spinal();
    if (!res){
        statusbar_show_warning("Legend error - ERR4");
        return res;
    }

    res = MRI__do_plot_arteriovenouscsf_spinal();
    if (!res){
        statusbar_show_warning("Legend error - ERR5");
        return res;
    }
    else{
        statusbar_show_message("Legend done");
        return res;
    }
}

bool MainWindow::MRI__do_venous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int na = MRI__vector_arterial_spinal_y->count();
    unsigned int nv = MRI__vector_venous_spinal_y->count();

    if ((na == nv) && (na != 0)){
        double correction;
        bool res = venous_correction(MRI__vector_arterial_spinal_y, MRI__vector_venous_spinal_y, MRI__vector_venous_corrected_spinal_y, &correction);
        if (!res){
            statusbar_show_warning("Venous spinal correction error - ERR2");
            return res;
        }
        res = MRI__do_plot_venous_spinal();
        if (!res){
            statusbar_show_warning("Venous spinal correction error - ERR3");
            return res;
        }

        MRI__label_venous_spinal->setText("<b>Correction</b> = " + QString::number(correction));

        statusbar_show_message("Venous spinal corrected");
        return true;
    }
    else{
        statusbar_show_warning("Venous spinal correction error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_csf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int n = MRI__vector_csf_spinal_y->count();

    if (n != 0){
        double correction;
        bool res = csf_correction(MRI__vector_csf_spinal_y, MRI__vector_csf_corrected_spinal_y, &correction);
        if (!res){
            statusbar_show_warning("CSF spinal correction error - ERR2");
            return res;
        }

        res = MRI__do_plot_csf_spinal();
        if (!res){
            statusbar_show_warning("CSF spinal correction error - ERR3");
            return res;
        }

        MRI__label_csf_spinal->setText("<b>Correction</b> = " + QString::number(correction) + " mm^3/s");

        statusbar_show_message("CSF spinal corrected");
        return true;
    }
    else{
        statusbar_show_warning("CSF spinal correction error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    MRI__vector_arteriovenous_flow_spinal_x->clear();
    MRI__vector_arteriovenous_flow_spinal_y->clear();
    MRI__vector_arteriovenous_volume_spinal_x->clear();
    MRI__vector_arteriovenous_volume_spinal_y->clear();

    unsigned int nax = MRI__vector_arterial_spinal_x->count();
    unsigned int nay = MRI__vector_arterial_spinal_y->count();
    unsigned int nvy = MRI__vector_venous_corrected_spinal_y->count();

    if ((nax == nay) && (nvy == nay) && (nax != 0)){
        bool res = arteriovenous_flow(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, MRI__vector_venous_corrected_spinal_y, MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenous spinal error - ERR2");
            return res;
        }

        res = arteriovenous_volume(MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y, MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenous spinal error - ERR3");
            return res;
        }

        res = MRI__do_plot_arteriovenous_spinal();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal error - ERR4");
            return res;
        }

        res = MRI__do_plot_arteriovenous_flow_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR5");
            return res;
        }

        res = MRI__do_plot_arteriovenous_volume_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR6");
            return res;
        }

        res = COMPLIANCE__do_plot_arteriovenous_volume_spinal();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR7");
            return res;
        }

        res = TRANSFERTFUNCTION__do_plot_arteriovenous_volume_spinal();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR8");
            return res;
        }

        res = MRI__do_arteriovenous_flow_spinal_spectrum();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR9");
            return res;
        }

        res = MRI__do_arteriovenous_volume_spinal_spectrum();
        if (!res){
            statusbar_show_warning("Arteriovenous spinal plot error - ERR10");
            return res;
        }

        statusbar_show_message("Arteriovenous spinal done");
        return res;
    }
    else{
        statusbar_show_warning("Arteriovenous spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenous_auto_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = MRI__do_venous_spinal();
    if (!res){
        statusbar_show_warning("Arteriovenous AUTO spinal error - ERR1");
        return res;
    }
    res = MRI__do_arteriovenous_spinal();
    if (!res){
        statusbar_show_warning("Arteriovenous AUTO spinal error - ERR2");
        return res;
    }
    else{
        statusbar_show_message("Arteriovenous AUTO spinal done");
        return res;
    }
}

bool MainWindow::MRI__do_arteriovenouscsf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__vector_arteriovenouscsf_flow_spinal_x->clear();
    MRI__vector_arteriovenouscsf_flow_spinal_y->clear();
    MRI__vector_arteriovenouscsf_volume_spinal_x->clear();
    MRI__vector_arteriovenouscsf_volume_spinal_y->clear();

    unsigned int nax = MRI__vector_arterial_spinal_x->count();
    unsigned int nay = MRI__vector_arterial_spinal_y->count();
    unsigned int nvy = MRI__vector_venous_corrected_spinal_y->count();
    unsigned int ncy = MRI__vector_csf_corrected_spinal_y->count();

    if ((nax == nay) && (nvy == nay) && (ncy == nay) && (nax != 0)){
        bool res = arteriovenouscsf_flow(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, MRI__vector_venous_corrected_spinal_y, MRI__vector_csf_corrected_spinal_y, MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal error - ERR2");
            return res;
        }

        res = arteriovenouscsf_volume(MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y, MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal error - ERR3");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_spinal();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal error - ERR4");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_flow_spinal_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR5");
            return res;
        }

        res = MRI__do_plot_arteriovenouscsf_volume_spinal_intracranial();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR6");
            return res;
        }

        res = COMPLIANCE__do_plot_arteriovenouscsf_volume_spinal();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR7");
            return res;
        }

        res = TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_spinal();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR8");
            return res;
        }

        res = MRI__do_arteriovenouscsf_flow_spinal_spectrum();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR9");
            return res;
        }

        res = MRI__do_arteriovenouscsf_volume_spinal_spectrum();
        if (!res){
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR10");
            return res;
        }

        statusbar_show_message("ArteriovenousCSF spinal done");
        return res;
    }
    else{
        statusbar_show_warning("ArteriovenousCSF spinal error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_arteriovenouscsf_auto_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = MRI__do_venous_spinal();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO spinal error - ERR1");
        return res;
    }
    res = MRI__do_csf_spinal();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO spinal error - ERR2");
        return res;
    }
    res = MRI__do_arteriovenouscsf_spinal();
    if (!res){
        statusbar_show_warning("ArteriovenousCSF AUTO spinal error - ERR3");
        return res;
    }
    else{
        statusbar_show_message("ArteriovenousCSF AUTO spinal done");
        return res;
    }
}

bool MainWindow::MRI__do_plot_arteriovenous_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenous_spinal->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenous_flow_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenous_flow_spinal_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenous_spinal, 0, MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y);
            if (!res){
                statusbar_show_warning("Arteriovenous spinal plot error - ERR2");
                return res;
            }

            res = MRI__do_print_arteriovenous_spinal();
            if (!res){
                statusbar_show_warning("Arteriovenous spinal plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("Arteriovenous spinal plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("Arteriovenous spinal plot error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenous_volume_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenous_volume_spinal_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenous_spinal, 0, MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y);
            if (!res){
                statusbar_show_warning("Arteriovenous spinal plot error - ERR4");
                return res;
            }

            res = MRI__do_print_arteriovenous_spinal();
            if (!res){
                statusbar_show_warning("Arteriovenous spinal plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("Arteriovenous spinal plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("Arteriovenous spinal plot error - ERR3");
            return false;
        }
    }
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__combobox_flow_volume_arteriovenouscsf_spinal->currentIndex() == 0){
        unsigned int nx = MRI__vector_arteriovenouscsf_flow_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_flow_spinal_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenouscsf_spinal, 0, MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y);
            if (!res){
                statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR2");
                return res;
            }

            res = MRI__do_print_arteriovenouscsf_spinal();
            if (!res){
                statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("ArteriovenousCSF spinal plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR1");
            return false;
        }
    }
    else{
        unsigned int nx = MRI__vector_arteriovenouscsf_volume_spinal_x->count();
        unsigned int ny = MRI__vector_arteriovenouscsf_volume_spinal_y->count();

        if ((nx == ny) && (nx != 0)){
            bool res = plot(MRI__plot_arteriovenouscsf_spinal, 0, MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y);
            if (!res){
                statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR4");
                return res;
            }

            res = MRI__do_print_arteriovenouscsf_spinal();
            if (!res){
                statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR3");
                return res;
            }
            else{
                statusbar_show_message("ArteriovenousCSF spinal plotted");
                return res;
            }
        }
        else{
            statusbar_show_warning("ArteriovenousCSF spinal plot error - ERR3");
            return false;
        }
    }
}


