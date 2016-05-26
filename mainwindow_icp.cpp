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

void MainWindow::ICP__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //ScrollArea
    ICP__scrollarea_basal = new QScrollArea;
    ICP__scrollarea_plateau = new QScrollArea;

    //Widget
    ICP__widget_basal = new QWidget;
    ICP__widget_plateau = new QWidget;

    //Grid
    ICP__grid_basal = new QGridLayout;
    ICP__grid_plateau = new QGridLayout;

    //VBox
    ICP__vbox_signal = new QVBoxLayout;
    ICP__vbox_mean_basal = new QVBoxLayout;
    ICP__vbox_mean_plateau = new QVBoxLayout;

    //HBox
    ICP__hbox_signal = new QHBoxLayout;
    ICP__hbox_FFT_basal = new QHBoxLayout;
    ICP__hbox_FFT_plateau = new QHBoxLayout;
    ICP__hbox_IFFT_basal = new QHBoxLayout;
    ICP__hbox_IFFT_plateau = new QHBoxLayout;
    ICP__hbox_mean_basal = new QHBoxLayout;
    ICP__hbox_mean_plateau = new QHBoxLayout;

    //Plot
    ICP__plot_signal = new QCustomPlot;
    ICP__plot_selection_basal = new QCustomPlot;
    ICP__plot_FFT_basal = new QCustomPlot;
    ICP__plot_IFFT_basal = new QCustomPlot;
    ICP__plot_mean_basal = new QCustomPlot;
    ICP__plot_selection_plateau = new QCustomPlot;
    ICP__plot_FFT_plateau = new QCustomPlot;
    ICP__plot_IFFT_plateau = new QCustomPlot;
    ICP__plot_mean_plateau = new QCustomPlot;

    //Label
    ICP__label_quality_basal = new QLabel;
    ICP__label_quality_plateau = new QLabel;
    ICP__label_signal_basal = new QLabel;
    ICP__label_signal_plateau = new QLabel;
    ICP__label_FFT_view_basal = new QLabel;
    ICP__label_FFT_view_plateau = new QLabel;
    ICP__label_FFT_ROI_basal = new QLabel;
    ICP__label_FFT_ROI_plateau = new QLabel;
    ICP__label_threshold_basal = new QLabel;
    ICP__label_threshold_plateau = new QLabel;
    ICP__label_cardiac_cycle_basal = new QLabel;
    ICP__label_heart_rate_basal = new QLabel;
    ICP__label_min_basal = new QLabel;
    ICP__label_max_basal = new QLabel;
    ICP__label_mean_basal = new QLabel;
    ICP__label_amplitude_basal = new QLabel;
    ICP__label_cardiac_cycle_plateau = new QLabel;
    ICP__label_heart_rate_plateau = new QLabel;
    ICP__label_min_plateau = new QLabel;
    ICP__label_max_plateau = new QLabel;
    ICP__label_mean_plateau = new QLabel;
    ICP__label_amplitude_plateau = new QLabel;

    //SpinBox
    ICP__spinbox_quality_basal = new QSpinBox;
    ICP__spinbox_quality_plateau = new QSpinBox;

    ICP__doublespinbox_signal_down_basal = new QDoubleSpinBox;
    ICP__doublespinbox_signal_up_basal = new QDoubleSpinBox;
    ICP__doublespinbox_signal_down_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_signal_up_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_view_down_basal = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_view_up_basal = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_view_down_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_view_up_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_ROI_down_basal = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_ROI_up_basal = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_ROI_down_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_FFT_ROI_up_plateau = new QDoubleSpinBox;
    ICP__doublespinbox_threshold_basal = new QDoubleSpinBox;
    ICP__doublespinbox_threshold_plateau = new QDoubleSpinBox;

    //Button
    ICP__button_show_basal = new QPushButton;
    ICP__button_show_plateau = new QPushButton;
    ICP__button_FFT_basal = new QPushButton;
    ICP__button_FFT_plateau = new QPushButton;
    ICP__button_FFT_ROI_auto_basal = new QPushButton;
    ICP__button_FFT_ROI_auto_plateau = new QPushButton;
    ICP__button_IFFT_basal = new QPushButton;
    ICP__button_IFFT_plateau = new QPushButton;
    ICP__button_peak_basal = new QPushButton;
    ICP__button_peak_plateau = new QPushButton;
    ICP__button_mean_basal = new QPushButton;
    ICP__button_mean_plateau = new QPushButton;
    ICP__button_auto = new QPushButton;
    ICP__button_adjust_basal = new QPushButton;
    ICP__button_adjust_plateau = new QPushButton;

    //Vector
    ICP__vector_signal_x = new QVector<double>;
    ICP__vector_signal_y = new QVector<double>;
    ICP__vector_selection_basal_x = new QVector<double>;
    ICP__vector_selection_basal_y = new QVector<double>;
    ICP__vector_selection_plateau_x = new QVector<double>;
    ICP__vector_selection_plateau_y = new QVector<double>;
    ICP__vector_FFT_basal_x = new QVector<double>;
    ICP__vector_FFT_basal_y = new QVector<double>;
    ICP__vector_FFT_plateau_x = new QVector<double>;
    ICP__vector_FFT_plateau_y = new QVector<double>;
    ICP__vector_FFT_basal_x_ROI = new QVector<double>;
    ICP__vector_FFT_basal_y_ROI = new QVector<double>;
    ICP__vector_FFT_plateau_x_ROI = new QVector<double>;
    ICP__vector_FFT_plateau_y_ROI = new QVector<double>;
    ICP__vector_IFFT_basal_x = new QVector<double>;
    ICP__vector_IFFT_basal_y = new QVector<double>;
    ICP__vector_IFFT_plateau_x = new QVector<double>;
    ICP__vector_IFFT_plateau_y = new QVector<double>;
    ICP__vector_peak_basal_x = new QVector<double>;
    ICP__vector_peak_basal_y = new QVector<double>;
    ICP__vector_peak_plateau_x = new QVector<double>;
    ICP__vector_peak_plateau_y = new QVector<double>;
    ICP__vector_mean_basal_x = new QVector<double>;
    ICP__vector_mean_basal_y = new QVector<double>;
    ICP__vector_mean_sd_basal_y = new QVector<double>;
    ICP__vector_mean_plateau_x = new QVector<double>;
    ICP__vector_mean_plateau_y = new QVector<double>;
    ICP__vector_mean_sd_plateau_y = new QVector<double>;

    //Double
    ICP__double_cardiac_cycle_basal = 0;
    ICP__double_heart_rate_basal = 0.;
    ICP__double_min_basal = 0.;
    ICP__double_max_basal = 0.;
    ICP__double_mean_basal = 0.;
    ICP__double_amplitude_basal = 0.;
    ICP__double_cardiac_cycle_plateau = 0;
    ICP__double_heart_rate_plateau = 0.;
    ICP__double_min_plateau = 0.;
    ICP__double_max_plateau = 0.;
    ICP__double_mean_plateau = 0.;
    ICP__double_amplitude_plateau = 0.;

    //Int
    ICP__int_bound_select = -1;
    ICP__int_signal_repeat = 0;
    ICP__int_isadjusted_basal = 0;
    ICP__int_isadjusted_plateau = 0;
}

void MainWindow::ICP__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //ScrollArea
    ICP__scrollarea_basal->setLayout(ICP__grid_basal);
    ICP__scrollarea_basal->setWidgetResizable(true);
    ICP__scrollarea_basal->setWidget(ICP__widget_basal);
    ICP__scrollarea_basal->setHidden(true);
    ICP__scrollarea_plateau->setLayout(ICP__grid_plateau);
    ICP__scrollarea_plateau->setWidgetResizable(true);
    ICP__scrollarea_plateau->setWidget(ICP__widget_plateau);
    ICP__scrollarea_plateau->setHidden(true);

    //Widget
    ICP__widget_basal->setLayout(ICP__grid_basal);
    ICP__widget_basal->setHidden(true);
    ICP__widget_plateau->setLayout(ICP__grid_plateau);
    ICP__widget_plateau->setHidden(true);

    //Grid
    ICP__grid_basal->addWidget(ICP__plot_selection_basal, 0, 0, 10, 10);
    ICP__grid_basal->addLayout(ICP__hbox_FFT_basal, 10, 0, 1, 10);
    ICP__grid_basal->addWidget(ICP__plot_FFT_basal, 20, 0, 10, 10);
    ICP__grid_basal->addLayout(ICP__hbox_IFFT_basal, 30, 0, 1, 10);
    ICP__grid_basal->addWidget(ICP__plot_IFFT_basal, 40, 0, 10, 10);
    ICP__grid_basal->addLayout(ICP__hbox_mean_basal, 50, 0, 1, 10);

    ICP__grid_plateau->addWidget(ICP__plot_selection_plateau, 0, 0, 10, 10);
    ICP__grid_plateau->addLayout(ICP__hbox_FFT_plateau, 10, 0, 1, 10);
    ICP__grid_plateau->addWidget(ICP__plot_FFT_plateau, 20, 0, 10, 10);
    ICP__grid_plateau->addLayout(ICP__hbox_IFFT_plateau, 30, 0, 1, 10);
    ICP__grid_plateau->addWidget(ICP__plot_IFFT_plateau, 40, 0, 10, 10);
    ICP__grid_plateau->addLayout(ICP__hbox_mean_plateau, 50, 0, 1, 10);

    //VBox
    ICP__vbox_signal->addWidget(ICP__label_quality_basal);
    ICP__vbox_signal->addWidget(ICP__spinbox_quality_basal);
    ICP__vbox_signal->addWidget(ICP__label_quality_plateau);
    ICP__vbox_signal->addWidget(ICP__spinbox_quality_plateau);

    ICP__vbox_mean_basal->addWidget(ICP__label_cardiac_cycle_basal);
    ICP__vbox_mean_basal->addWidget(ICP__label_heart_rate_basal);
    ICP__vbox_mean_basal->addWidget(ICP__label_min_basal);
    ICP__vbox_mean_basal->addWidget(ICP__label_max_basal);
    ICP__vbox_mean_basal->addWidget(ICP__label_mean_basal);
    ICP__vbox_mean_basal->addWidget(ICP__label_amplitude_basal);

    ICP__vbox_mean_plateau->addWidget(ICP__label_cardiac_cycle_plateau);
    ICP__vbox_mean_plateau->addWidget(ICP__label_heart_rate_plateau);
    ICP__vbox_mean_plateau->addWidget(ICP__label_min_plateau);
    ICP__vbox_mean_plateau->addWidget(ICP__label_max_plateau);
    ICP__vbox_mean_plateau->addWidget(ICP__label_mean_plateau);
    ICP__vbox_mean_plateau->addWidget(ICP__label_amplitude_plateau);

    //HBox
    ICP__hbox_signal->addWidget(ICP__label_signal_basal, Qt::AlignLeft);
    ICP__hbox_signal->addWidget(ICP__doublespinbox_signal_down_basal, Qt::AlignLeft);
    ICP__hbox_signal->addWidget(ICP__doublespinbox_signal_up_basal, Qt::AlignLeft);
    ICP__hbox_signal->addWidget(ICP__label_signal_plateau, Qt::AlignRight);
    ICP__hbox_signal->addWidget(ICP__doublespinbox_signal_down_plateau, Qt::AlignRight);
    ICP__hbox_signal->addWidget(ICP__doublespinbox_signal_up_plateau, Qt::AlignRight);

    ICP__hbox_FFT_basal->addWidget(ICP__button_FFT_basal, Qt::AlignLeft);
    ICP__hbox_FFT_basal->addWidget(ICP__label_FFT_view_basal, Qt::AlignLeft);
    ICP__hbox_FFT_basal->addWidget(ICP__doublespinbox_FFT_view_down_basal, Qt::AlignLeft);
    ICP__hbox_FFT_basal->addWidget(ICP__doublespinbox_FFT_view_up_basal, Qt::AlignLeft);

    ICP__hbox_FFT_plateau->addWidget(ICP__button_FFT_plateau, Qt::AlignLeft);
    ICP__hbox_FFT_plateau->addWidget(ICP__label_FFT_view_plateau, Qt::AlignLeft);
    ICP__hbox_FFT_plateau->addWidget(ICP__doublespinbox_FFT_view_down_plateau, Qt::AlignLeft);
    ICP__hbox_FFT_plateau->addWidget(ICP__doublespinbox_FFT_view_up_plateau, Qt::AlignLeft);

    ICP__hbox_IFFT_basal->addWidget(ICP__label_FFT_ROI_basal, Qt::AlignRight);
    ICP__hbox_IFFT_basal->addWidget(ICP__doublespinbox_FFT_ROI_down_basal, Qt::AlignRight);
    ICP__hbox_IFFT_basal->addWidget(ICP__doublespinbox_FFT_ROI_up_basal, Qt::AlignRight);
    ICP__hbox_IFFT_basal->addWidget(ICP__button_FFT_ROI_auto_basal, Qt::AlignRight);
    ICP__hbox_IFFT_basal->addWidget(ICP__button_IFFT_basal, Qt::AlignRight);

    ICP__hbox_IFFT_plateau->addWidget(ICP__label_FFT_ROI_plateau, Qt::AlignRight);
    ICP__hbox_IFFT_plateau->addWidget(ICP__doublespinbox_FFT_ROI_down_plateau, Qt::AlignRight);
    ICP__hbox_IFFT_plateau->addWidget(ICP__doublespinbox_FFT_ROI_up_plateau, Qt::AlignRight);
    ICP__hbox_IFFT_plateau->addWidget(ICP__button_FFT_ROI_auto_plateau, Qt::AlignRight);
    ICP__hbox_IFFT_plateau->addWidget(ICP__button_IFFT_plateau, Qt::AlignRight);

    ICP__hbox_mean_basal->addWidget(ICP__label_threshold_basal, Qt::AlignLeft);
    ICP__hbox_mean_basal->addWidget(ICP__doublespinbox_threshold_basal, Qt::AlignLeft);
    ICP__hbox_mean_basal->addWidget(ICP__button_peak_basal, Qt::AlignLeft);
    ICP__hbox_mean_basal->addWidget(ICP__button_mean_basal, Qt::AlignLeft);

    ICP__hbox_mean_plateau->addWidget(ICP__label_threshold_plateau, Qt::AlignLeft);
    ICP__hbox_mean_plateau->addWidget(ICP__doublespinbox_threshold_plateau, Qt::AlignLeft);
    ICP__hbox_mean_plateau->addWidget(ICP__button_peak_plateau, Qt::AlignLeft);
    ICP__hbox_mean_plateau->addWidget(ICP__button_mean_plateau, Qt::AlignLeft);

    //Plot
    ICP__plot_signal->addGraph();
    ICP__plot_signal->addGraph();
    ICP__plot_signal->addGraph();
    ICP__plot_selection_basal->addGraph();
    ICP__plot_selection_plateau->addGraph();
    ICP__plot_FFT_basal->addGraph();
    ICP__plot_FFT_basal->addGraph();
    ICP__plot_FFT_plateau->addGraph();
    ICP__plot_FFT_plateau->addGraph();
    ICP__plot_IFFT_basal->addGraph();
    ICP__plot_IFFT_basal->addGraph();
    ICP__plot_IFFT_basal->addGraph();
    ICP__plot_IFFT_plateau->addGraph();
    ICP__plot_IFFT_plateau->addGraph();
    ICP__plot_IFFT_plateau->addGraph();
    ICP__plot_mean_basal->addGraph();
    ICP__plot_mean_plateau->addGraph();

    //Label
    ICP__label_quality_basal->setText("Basal quality");
    ICP__label_quality_plateau->setText("Plateau quality");
    ICP__label_signal_basal->setText("Basal");
    ICP__label_signal_plateau->setText("Plateau");
    ICP__label_FFT_view_basal->setText("Frequency range");
    ICP__label_FFT_view_plateau->setText("Frequency range");
    ICP__label_FFT_ROI_basal->setText("Frequency ROI");
    ICP__label_FFT_ROI_plateau->setText("Frequency ROI");
    ICP__label_threshold_basal->setText("Threshold");
    ICP__label_threshold_plateau->setText("Threshold");

    //SpinBox
    ICP__spinbox_quality_basal->setRange(1, 5);
    ICP__spinbox_quality_basal->setValue(5);
    ICP__spinbox_quality_plateau->setRange(1, 5);
    ICP__spinbox_quality_plateau->setValue(5);

    ICP__doublespinbox_signal_down_basal->setRange(0., 0.);
    ICP__doublespinbox_signal_up_basal->setRange(0., 0.);
    ICP__doublespinbox_signal_down_plateau->setRange(0., 0.);
    ICP__doublespinbox_signal_up_plateau->setRange(0., 0.);
    ICP__doublespinbox_FFT_view_down_basal->setRange(0., 0.);
    ICP__doublespinbox_FFT_view_up_basal->setRange(0., 0.);
    ICP__doublespinbox_FFT_view_down_plateau->setRange(0., 0.);
    ICP__doublespinbox_FFT_view_up_plateau->setRange(0., 0.);
    ICP__doublespinbox_threshold_basal->setRange(0., 0.);
    ICP__doublespinbox_threshold_plateau->setRange(0., 0.);

    //Button
    ICP__button_show_basal->setIcon(QIcon("img/down.png"));
    ICP__button_show_basal->setToolTip("Expert mode");
    ICP__button_show_plateau->setIcon(QIcon("img/down.png"));
    ICP__button_show_plateau->setToolTip("Expert mode");
    ICP__button_FFT_basal->setText("FFT");
    ICP__button_FFT_plateau->setText("FFT");
    ICP__button_FFT_ROI_auto_basal->setText("Auto ROI");
    ICP__button_FFT_ROI_auto_plateau->setText("Auto ROI");
    ICP__button_IFFT_basal->setText("IFFT");
    ICP__button_IFFT_plateau->setText("IFFT");
    ICP__button_peak_basal->setText("Peaks detection");
    ICP__button_peak_plateau->setText("Peaks detection");
    ICP__button_mean_basal->setText("Mean");
    ICP__button_mean_plateau->setText("Mean");
    ICP__button_auto->setText("Auto");
    ICP__button_adjust_basal->setText("Adjust basal");
    ICP__button_adjust_plateau->setText("Adjust plateau");
}

void MainWindow::ICP__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    connect(ICP__plot_signal, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(ICP__do_mouse_press_signal(QMouseEvent*)));
    connect(ICP__plot_signal, SIGNAL(mouseMove(QMouseEvent*)), this, SLOT(ICP__do_mouse_move_signal(QMouseEvent*)));
    connect(ICP__plot_signal, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(ICP__do_mouse_release_signal(QMouseEvent*)));

    //SpinBox
    connect(ICP__doublespinbox_signal_down_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_signal_basal()));
    connect(ICP__doublespinbox_signal_up_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_signal_basal()));
    connect(ICP__doublespinbox_signal_down_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_signal_plateau()));
    connect(ICP__doublespinbox_signal_up_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_signal_plateau()));
    connect(ICP__doublespinbox_FFT_view_down_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_basal()));
    connect(ICP__doublespinbox_FFT_view_up_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_basal()));
    connect(ICP__doublespinbox_FFT_view_down_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_plateau()));
    connect(ICP__doublespinbox_FFT_view_up_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_plateau()));
    connect(ICP__doublespinbox_FFT_ROI_down_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_ROI_basal()));
    connect(ICP__doublespinbox_FFT_ROI_up_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_ROI_basal()));
    connect(ICP__doublespinbox_FFT_ROI_down_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_ROI_plateau()));
    connect(ICP__doublespinbox_FFT_ROI_up_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_FFT_ROI_plateau()));
    connect(ICP__doublespinbox_threshold_basal, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_thresold_basal()));
    connect(ICP__doublespinbox_threshold_plateau, SIGNAL(valueChanged(double)), this, SLOT(ICP__do_plot_thresold_plateau()));

    //Button
    connect(ICP__button_show_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_show_basal()));
    connect(ICP__button_show_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_show_plateau()));
    connect(ICP__button_FFT_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_FFT_basal()));
    connect(ICP__button_FFT_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_FFT_plateau()));
    connect(ICP__button_FFT_ROI_auto_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_FFT_ROI_basal()));
    connect(ICP__button_FFT_ROI_auto_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_FFT_ROI_plateau()));
    connect(ICP__button_IFFT_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_IFFT_basal()));
    connect(ICP__button_IFFT_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_IFFT_plateau()));
    connect(ICP__button_peak_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_peak_basal()));
    connect(ICP__button_peak_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_peak_plateau()));
    connect(ICP__button_mean_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_mean_basal()));
    connect(ICP__button_mean_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_mean_plateau()));
    connect(ICP__button_auto, SIGNAL(clicked(bool)), this, SLOT(ICP__do_auto()));
    connect(ICP__button_adjust_basal, SIGNAL(clicked(bool)), this, SLOT(ICP__do_adjust_basal()));
    connect(ICP__button_adjust_plateau, SIGNAL(clicked(bool)), this, SLOT(ICP__do_adjust_plateau()));
}

void MainWindow::ICP__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    ICP__plot_signal->graph(1)->setPen(QPen(Qt::red));
    ICP__plot_signal->graph(1)->setBrush(QBrush(Qt::red, Qt::BDiagPattern));
    ICP__plot_signal->graph(2)->setPen(QPen(Qt::green));
    ICP__plot_signal->graph(2)->setBrush(QBrush(Qt::green, Qt::FDiagPattern));

    ICP__plot_FFT_basal->graph(0)->setBrush(QBrush(Qt::blue));

    ICP__plot_FFT_plateau->graph(0)->setBrush(QBrush(Qt::blue));

    ICP__plot_FFT_basal->graph(1)->setPen(QPen(Qt::red));
    ICP__plot_FFT_basal->graph(1)->setBrush(QBrush(Qt::red, Qt::BDiagPattern));

    ICP__plot_FFT_plateau->graph(1)->setPen(QPen(Qt::red));
    ICP__plot_FFT_plateau->graph(1)->setBrush(QBrush(Qt::red, Qt::BDiagPattern));

    ICP__plot_IFFT_basal->graph(1)->setPen(QPen(Qt::red));
    ICP__plot_IFFT_basal->graph(2)->setPen(QPen(Qt::red));
    ICP__plot_IFFT_basal->graph(2)->setLineStyle(QCPGraph::lsNone);
    ICP__plot_IFFT_basal->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    ICP__plot_IFFT_plateau->graph(1)->setPen(QPen(Qt::red));
    ICP__plot_IFFT_plateau->graph(2)->setPen(QPen(Qt::red));
    ICP__plot_IFFT_plateau->graph(2)->setLineStyle(QCPGraph::lsNone);
    ICP__plot_IFFT_plateau->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    ICP__plot_mean_basal->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot));
    ICP__plot_mean_basal->graph(0)->setErrorType(QCPGraph::etValue);

    ICP__plot_mean_plateau->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot));
    ICP__plot_mean_plateau->graph(0)->setErrorType(QCPGraph::etValue);
}

bool MainWindow::ICP__load(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_signal_x->clear();
    ICP__vector_signal_y->clear();

    PATIENT__textedit_ICP->clear();

    QString patient_name;
    bool res = load_ICMP_csv(this, ICP__vector_signal_x, ICP__vector_signal_y, &patient_name);
    if (!res){
        statusbar_show_warning("ICP - Load ICP error - ERR1");
        return res;
    }

    PATIENT__textedit_ICP->append("Patient name: " + patient_name);

    res = ICP__do_plot_signal();
    if (!res){
        statusbar_show_warning("ICP - Load ICP error - ERR2");
    }
    else{
        statusbar_show_message("ICP - Load ICP done");
    }

    return res;
}

bool MainWindow::ICP__load(const QString DirName){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<double> Selection;
    QVector<int> Quality;
    QVector<double> FFTRange;
    QVector<double> FFTROI;
    QVector<double> Threshold;
    QVector<int> IsAdjusted;
    QVector<double> Results;

    QString ICPDirName = DirName + "/ICP";

    Res = LoadICP(ICPDirName,
                  ICP__vector_signal_x, ICP__vector_signal_y, &Selection, &Quality,
                  ICP__vector_selection_basal_x, ICP__vector_selection_basal_y, ICP__vector_selection_plateau_x, ICP__vector_selection_plateau_y, &FFTRange,
                  ICP__vector_FFT_basal_x, ICP__vector_FFT_basal_y, ICP__vector_FFT_plateau_x, ICP__vector_FFT_plateau_y, &FFTROI,
                  ICP__vector_IFFT_basal_x, ICP__vector_IFFT_basal_y, ICP__vector_IFFT_plateau_x, ICP__vector_IFFT_plateau_y, &Threshold, ICP__vector_peak_basal_x, ICP__vector_peak_basal_y, ICP__vector_peak_plateau_x, ICP__vector_peak_plateau_y,
                  ICP__vector_mean_basal_x, ICP__vector_mean_basal_y, ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y, &IsAdjusted, &Results
                  );
    if (Res){
        Res = ICP__do_plot_signal();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR2");
            return Res;
        }

        if (!Selection.isEmpty()){
            ICP__doublespinbox_signal_down_basal->setValue(Selection.at(0));
            ICP__doublespinbox_signal_up_basal->setValue(Selection.at(1));
            ICP__doublespinbox_signal_down_plateau->setValue(Selection.at(2));
            ICP__doublespinbox_signal_up_plateau->setValue(Selection.at(3));
        }

        if (!Quality.isEmpty()){
            ICP__spinbox_quality_basal->setValue(Quality.at(0));
            ICP__spinbox_quality_plateau->setValue(Quality.at(1));
        }

        Res = ICP__do_FFT_basal();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR3");
        }
        Res = ICP__do_FFT_plateau();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR4");
        }

        if (!FFTRange.isEmpty()){
            ICP__doublespinbox_FFT_view_down_basal->setValue(FFTRange.at(0));
            ICP__doublespinbox_FFT_view_up_basal->setValue(FFTRange.at(1));
            ICP__doublespinbox_FFT_view_down_plateau->setValue(FFTRange.at(2));
            ICP__doublespinbox_FFT_view_up_plateau->setValue(FFTRange.at(3));
        }

        if (!FFTROI.isEmpty()){
            ICP__doublespinbox_FFT_ROI_down_basal->setValue(FFTROI.at(0));
            ICP__doublespinbox_FFT_ROI_up_basal->setValue(FFTROI.at(1));
            ICP__doublespinbox_FFT_ROI_down_plateau->setValue(FFTROI.at(2));
            ICP__doublespinbox_FFT_ROI_up_plateau->setValue(FFTROI.at(3));
        }

        Res = ICP__do_IFFT_basal();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR5");
        }
        Res = ICP__do_IFFT_plateau();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR6");
        }

        if (!Threshold.isEmpty()){
            ICP__doublespinbox_threshold_basal->setValue(Threshold.at(0));
            ICP__doublespinbox_threshold_plateau->setValue(Threshold.at(1));
        }

        Res = ICP__do_peak_basal();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR7");
        }
        Res = ICP__do_peak_plateau();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR8");
        }

        Res = ICP__do_mean_basal();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR9");
        }
        Res = ICP__do_mean_plateau();
        if (!Res){
            statusbar_show_warning("ICP - Load error - ERR10");
        }

        if (!IsAdjusted.isEmpty()){
            if (IsAdjusted.at(0)){
                Res = ICP__do_adjust_basal();
                if (!Res){
                    statusbar_show_warning("ICP - Load error - ERR11");
                    return Res;
                }
            }
            if (IsAdjusted.at(1)){
                Res = ICP__do_adjust_plateau();
                if (!Res){
                    statusbar_show_warning("ICP - Load error - ERR12");
                    return Res;
                }
            }
        }

        statusbar_show_message("ICP - Loaded");
        return true;
    }
    else{
        statusbar_show_warning("ICP - Load error - ERR1");
        return Res;
    }
}

bool MainWindow::ICP__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    QVector<double> Selection;
    Selection.append(ICP__doublespinbox_signal_down_basal->value());
    Selection.append(ICP__doublespinbox_signal_up_basal->value());
    Selection.append(ICP__doublespinbox_signal_down_plateau->value());
    Selection.append(ICP__doublespinbox_signal_up_plateau->value());

    QVector<int> Quality;
    Quality.append(ICP__spinbox_quality_basal->value());
    Quality.append(ICP__spinbox_quality_plateau->value());

    QVector<double> FFTRange;
    FFTRange.append(ICP__doublespinbox_FFT_view_down_basal->value());
    FFTRange.append(ICP__doublespinbox_FFT_view_up_basal->value());
    FFTRange.append(ICP__doublespinbox_FFT_view_down_plateau->value());
    FFTRange.append(ICP__doublespinbox_FFT_view_up_plateau->value());

    QVector<double> FFTROI;
    FFTROI.append(ICP__doublespinbox_FFT_ROI_down_basal->value());
    FFTROI.append(ICP__doublespinbox_FFT_ROI_up_basal->value());
    FFTROI.append(ICP__doublespinbox_FFT_ROI_down_plateau->value());
    FFTROI.append(ICP__doublespinbox_FFT_ROI_up_plateau->value());

    QVector<double> Threshold;
    Threshold.append(ICP__doublespinbox_threshold_basal->value());
    Threshold.append(ICP__doublespinbox_threshold_plateau->value());

    QVector<int> IsAdjusted;
    IsAdjusted.append(ICP__int_isadjusted_basal);
    IsAdjusted.append(ICP__int_isadjusted_plateau);

    QVector<double> Results;
    Results.append(ICP__double_cardiac_cycle_basal);
    Results.append(ICP__double_heart_rate_basal);
    Results.append(ICP__double_min_basal);
    Results.append(ICP__double_max_basal);
    Results.append(ICP__double_mean_basal);
    Results.append(ICP__double_amplitude_basal);
    Results.append(ICP__double_cardiac_cycle_plateau);
    Results.append(ICP__double_heart_rate_plateau);
    Results.append(ICP__double_min_plateau);
    Results.append(ICP__double_max_plateau);
    Results.append(ICP__double_mean_plateau);
    Results.append(ICP__double_amplitude_plateau);

    bool Res;
    QString PatientName = PATIENT__lineedit_name->text();
    if (PatientName.isEmpty()){
        QMessageBox::warning(this, "Save error", "Patient name is not defined.<br/>Define it first.");
        return false;
    }

    {
        QString DirName = GetResultsDir(&Res) + "/" + PatientName;
        QDir ResultsDir = QDir(DirName);
        if (!ResultsDir.exists()){
            Res = ResultsDir.mkdir(DirName);
            if (!Res)return false;
        }
    }

    QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/ICP";
    if (!Res){
        statusbar_show_warning("ICP - Save error - ERR1");
        return Res;
    }

    Res = SaveICP(DirName,
                  ICP__vector_signal_x, ICP__vector_signal_y, Selection, Quality,
                  ICP__vector_selection_basal_x, ICP__vector_selection_basal_y, ICP__vector_selection_plateau_x, ICP__vector_selection_plateau_y, FFTRange,
                  ICP__vector_FFT_basal_x, ICP__vector_FFT_basal_y, ICP__vector_FFT_plateau_x, ICP__vector_FFT_plateau_y, FFTROI,
                  ICP__vector_IFFT_basal_x, ICP__vector_IFFT_basal_y, ICP__vector_IFFT_plateau_x, ICP__vector_IFFT_plateau_y, Threshold, ICP__vector_peak_basal_x, ICP__vector_peak_basal_y, ICP__vector_peak_plateau_x, ICP__vector_peak_plateau_y,
                  ICP__vector_mean_basal_x, ICP__vector_mean_basal_y, ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y, IsAdjusted, Results
                  );

    if (!Res){
        statusbar_show_warning("ICP - Save error - ERR2");
    }
    else{
        statusbar_show_message("ICP - Saved");
    }
    return Res;
}

void MainWindow::ICP__do_show_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (ICP__widget_basal->isHidden() || ICP__scrollarea_basal->isHidden()){
        ICP__scrollarea_basal->show();
        ICP__widget_basal->show();
        statusbar_show_message("ICP - Show ICP basal");
    }
    else{
        ICP__scrollarea_basal->hide();
        ICP__widget_basal->hide();
        statusbar_show_message("ICP - Hide ICP basal");
    }
}

void MainWindow::ICP__do_show_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (ICP__widget_plateau->isHidden() || ICP__scrollarea_plateau->isHidden()){
        ICP__scrollarea_plateau->show();
        ICP__widget_plateau->show();
        statusbar_show_message("ICP - Show ICP plateau");
    }
    else{
        ICP__scrollarea_plateau->hide();
        ICP__widget_plateau->hide();
        statusbar_show_message("ICP - Hide ICP plateau");
    }
}

void MainWindow::ICP__do_mouse_press_signal(QMouseEvent *m_event){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int pos_x = m_event->x();

    double value_x = ICP__plot_signal->xAxis->pixelToCoord(pos_x);

    double dist_down_basal = qAbs(value_x - ICP__doublespinbox_signal_down_basal->value());
    double dist_up_basal = qAbs(value_x - ICP__doublespinbox_signal_up_basal->value());
    double dist_down_plateau = qAbs(value_x - ICP__doublespinbox_signal_down_plateau->value());
    double dist_up_plateau = qAbs(value_x - ICP__doublespinbox_signal_up_plateau->value());

    if ((dist_down_basal < dist_up_basal) && (dist_down_basal < dist_down_plateau) && (dist_down_basal < dist_up_plateau)){
       ICP__int_bound_select = 1;
       statusbar_show_message("ICP - Basal selection");
    }
    else if ((dist_up_basal < dist_down_plateau) && (dist_up_basal < dist_up_plateau)){
       ICP__int_bound_select = 2;
       statusbar_show_message("ICP - Basal selection");
    }
    else if (dist_down_plateau < dist_up_plateau){
       ICP__int_bound_select = 3;
       statusbar_show_message("ICP - Plateau selection");
    }
    else{
       ICP__int_bound_select = 4;
       statusbar_show_message("ICP - Plateau selection");
    }
}

void MainWindow::ICP__do_mouse_move_signal(QMouseEvent *m_event){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__int_signal_repeat++;

    if (ICP__int_signal_repeat%5 == 0){
        int pos_x = m_event->x();

        double value_x = ICP__plot_signal->xAxis->pixelToCoord(pos_x);

        if (ICP__int_bound_select == 1){
            ICP__doublespinbox_signal_down_basal->setValue(value_x);
        }
        else if (ICP__int_bound_select == 2){
            ICP__doublespinbox_signal_up_basal->setValue(value_x);
        }
        else if (ICP__int_bound_select == 3){
            ICP__doublespinbox_signal_down_plateau->setValue(value_x);
        }
        else if (ICP__int_bound_select == 4){
            ICP__doublespinbox_signal_up_plateau->setValue(value_x);
        }
    }
}

void MainWindow::ICP__do_mouse_release_signal(QMouseEvent *m_event){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int pos_x = m_event->x();

    double value_x = ICP__plot_signal->xAxis->pixelToCoord(pos_x);

    if (ICP__int_bound_select == 1){
        ICP__doublespinbox_signal_down_basal->setValue(value_x);
    }
    else if (ICP__int_bound_select == 2){
        ICP__doublespinbox_signal_up_basal->setValue(value_x);
    }
    else if (ICP__int_bound_select == 3){
        ICP__doublespinbox_signal_down_plateau->setValue(value_x);
    }
    else if (ICP__int_bound_select == 4){
        ICP__doublespinbox_signal_up_plateau->setValue(value_x);
    }

   ICP__int_bound_select = -1;
}

bool MainWindow::ICP__do_plot_signal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    bool res = plot(ICP__plot_signal, 0, ICP__vector_signal_x, ICP__vector_signal_y);
    if (!res) return res;

    //Spinbox
    double xmin = min(ICP__vector_signal_x, NULL, &res);
    if (!res){
        statusbar_show_warning("ICP - Signal plot error - ERR1");
        return res;
    }
    double xmax = max(ICP__vector_signal_x, NULL, &res);
    if (!res){
        statusbar_show_warning("ICP - Signal plot error - ERR2");
        return res;
    }

    ICP__doublespinbox_signal_down_basal->blockSignals(true);
    ICP__doublespinbox_signal_down_basal->setRange(xmin, xmax);
    ICP__doublespinbox_signal_down_basal->setValue(xmin+0.3*(xmax-xmin));
    ICP__doublespinbox_signal_down_basal->blockSignals(false);
    ICP__doublespinbox_signal_up_basal->setRange(xmin, xmax);
    ICP__doublespinbox_signal_up_basal->setValue(xmin+0.4*(xmax-xmin));
    ICP__doublespinbox_signal_down_plateau->blockSignals(true);
    ICP__doublespinbox_signal_down_plateau->setRange(xmin, xmax);
    ICP__doublespinbox_signal_down_plateau->setValue(xmin+0.6*(xmax-xmin));
    ICP__doublespinbox_signal_down_plateau->blockSignals(false);
    ICP__doublespinbox_signal_up_plateau->setRange(xmin, xmax);
    ICP__doublespinbox_signal_up_plateau->setValue(xmin+0.7*(xmax-xmin));

    statusbar_show_message("ICP - Signal plotted");
    return res;
}

bool MainWindow::ICP__do_plot_signal_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_signal_x->count();
    unsigned int ny = ICP__vector_signal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double ymin = min(ICP__vector_signal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Basal plot error - ERR1");
            return res;
        }
        double ymax = max(ICP__vector_signal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Basal plot error - ERR2");
            return res;
        }

        QVector<double> bound_x, bound_y;

        bound_x.append(ICP__doublespinbox_signal_up_basal->value());
        bound_x.append(ICP__doublespinbox_signal_up_basal->value());
        bound_x.append(ICP__doublespinbox_signal_down_basal->value());
        bound_x.append(ICP__doublespinbox_signal_down_basal->value());

        bound_y.append(ymin);
        bound_y.append(ymax);
        bound_y.append(ymax);
        bound_y.append(ymin);

        res = plot(ICP__plot_signal, 1, &bound_x, &bound_y, false);
        if (!res){
            statusbar_show_warning("ICP - Basal plot error - ERR3");
            return res;
        }

        res = ICP__do_plot_selection_basal();
        if (!res){
            statusbar_show_warning("ICP - Basal plot error - ERR4");
        }
        else{
            statusbar_show_message("ICP - Basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Basal plot error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_plot_signal_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_signal_x->count();
    unsigned int ny = ICP__vector_signal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double ymin = min(ICP__vector_signal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Plateau plot error - ERR1");
            return res;
        }
        double ymax = max(ICP__vector_signal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Plateau plot error - ERR2");
            return res;
        }

        QVector<double> bound_x, bound_y;

        bound_x.append(ICP__doublespinbox_signal_up_plateau->value());
        bound_x.append(ICP__doublespinbox_signal_up_plateau->value());
        bound_x.append(ICP__doublespinbox_signal_down_plateau->value());
        bound_x.append(ICP__doublespinbox_signal_down_plateau->value());

        bound_y.append(ymin);
        bound_y.append(ymax);
        bound_y.append(ymax);
        bound_y.append(ymin);

        res = plot(ICP__plot_signal, 2, &bound_x, &bound_y, false);
        if (!res){
            statusbar_show_warning("ICP - Plateau plot error - ERR3");
            return res;
        }

        res = ICP__do_plot_selection_plateau();
        if (!res){
            statusbar_show_warning("ICP - Plateau plot error - ERR4");
        }
        else{
            statusbar_show_message("ICP - Plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Plateau plot error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_plot_selection_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_selection_basal_x->clear();
    ICP__vector_selection_basal_y->clear();

    unsigned int nx = ICP__vector_signal_x->count();
    unsigned int ny = ICP__vector_signal_y->count();

    if ((nx == ny) && (nx != 0)){
        if (ICP__doublespinbox_signal_down_basal->value() < ICP__doublespinbox_signal_up_basal->value()){
            for (unsigned int i = 0; i < nx; i++){
                if ((ICP__vector_signal_x->at(i) > ICP__doublespinbox_signal_down_basal->value()) && (ICP__vector_signal_x->at(i) < ICP__doublespinbox_signal_up_basal->value())){
                    ICP__vector_selection_basal_x->append(ICP__vector_signal_x->at(i));
                    ICP__vector_selection_basal_y->append(ICP__vector_signal_y->at(i));
                }
            }
        }
        bool res = plot(ICP__plot_selection_basal, 0, ICP__vector_selection_basal_x, ICP__vector_selection_basal_y);
        if (!res){
            statusbar_show_warning("ICP - Basal selection plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - Basal selection plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Basal selection plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_plot_selection_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_selection_plateau_x->clear();
    ICP__vector_selection_plateau_y->clear();

    unsigned int nx = ICP__vector_signal_x->count();
    unsigned int ny = ICP__vector_signal_y->count();

    if ((nx == ny) && (nx != 0)){
        if (ICP__doublespinbox_signal_down_plateau->value() < ICP__doublespinbox_signal_up_plateau->value()){
            for (unsigned int i = 0; i < nx; i++){
                if ((ICP__vector_signal_x->at(i) > ICP__doublespinbox_signal_down_plateau->value()) && (ICP__vector_signal_x->at(i) < ICP__doublespinbox_signal_up_plateau->value())){
                    ICP__vector_selection_plateau_x->append(ICP__vector_signal_x->at(i));
                    ICP__vector_selection_plateau_y->append(ICP__vector_signal_y->at(i));
                }
            }
        }
        bool res = plot(ICP__plot_selection_plateau, 0, ICP__vector_selection_plateau_x, ICP__vector_selection_plateau_y);
        if (!res){
            statusbar_show_warning("ICP - Plateau selection plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - Plateau selection plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Plateau selection plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_FFT_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_FFT_basal_x->clear();
    ICP__vector_FFT_basal_y->clear();

    unsigned int nx = ICP__vector_selection_basal_x->count();
    unsigned int ny = ICP__vector_selection_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        FFT(ICP__vector_FFT_basal_y, ICP__vector_selection_basal_y, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT basal error - ERR1");
            return res;
        }
        unsigned int nf = ICP__vector_FFT_basal_y->count();

        double sample = 1. / (ICP__vector_selection_basal_x->at(1) - ICP__vector_selection_basal_x->at(0)) / ICP__vector_selection_basal_x->count();
        for (unsigned int i = 0; i < nf; i++){
            ICP__vector_FFT_basal_x->append(i*sample);
        }

        double xmin = min(ICP__vector_FFT_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT basal error - ERR2");
            return res;
        }
        double xmax = max(ICP__vector_FFT_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT basal error - ERR3");
            return res;
        }

        ICP__doublespinbox_FFT_view_down_basal->blockSignals(true);
        ICP__doublespinbox_FFT_view_down_basal->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_view_down_basal->setValue(FOURIER_XMIN_VIEW);
        ICP__doublespinbox_FFT_view_down_basal->blockSignals(false);
        ICP__doublespinbox_FFT_view_up_basal->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_view_up_basal->setValue(FOURIER_XMAX_VIEW);

        ICP__doublespinbox_FFT_ROI_down_basal->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_ROI_up_basal->setRange(xmin, xmax);

        res = ICP__do_plot_FFT_basal();
        if (!res){
            statusbar_show_warning("ICP - FFT basal error - ERR4");
        }
        else{
            statusbar_show_message("ICP - FFT basal done");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT basal error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_FFT_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_FFT_plateau_x->clear();
    ICP__vector_FFT_plateau_y->clear();

    unsigned int nx = ICP__vector_selection_plateau_x->count();
    unsigned int ny = ICP__vector_selection_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        FFT(ICP__vector_FFT_plateau_y, ICP__vector_selection_plateau_y, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT plateau error - ERR1");
            return res;
        }
        unsigned int nf = ICP__vector_FFT_plateau_y->count();

        double sample = 1. / (ICP__vector_selection_plateau_x->at(1) - ICP__vector_selection_plateau_x->at(0)) / ICP__vector_selection_plateau_x->count();
        for (unsigned int i = 0; i < nf; i++){
            ICP__vector_FFT_plateau_x->append(i*sample);
        }

        double xmin = min(ICP__vector_FFT_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT plateau error - ERR2");
            return res;
        }
        double xmax = max(ICP__vector_FFT_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT plateau error - ERR3");
            return res;
        }

        ICP__doublespinbox_FFT_view_down_plateau->blockSignals(true);
        ICP__doublespinbox_FFT_view_down_plateau->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_view_down_plateau->setValue(FOURIER_XMIN_VIEW);
        ICP__doublespinbox_FFT_view_down_plateau->blockSignals(false);
        ICP__doublespinbox_FFT_view_up_plateau->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_view_up_plateau->setValue(FOURIER_XMAX_VIEW);

        ICP__doublespinbox_FFT_ROI_down_plateau->setRange(xmin, xmax);
        ICP__doublespinbox_FFT_ROI_up_plateau->setRange(xmin, xmax);

        res = ICP__do_plot_FFT_plateau();
        if (!res){
            statusbar_show_warning("ICP - FFT plateau error - ERR1");
        }
        else{
            statusbar_show_message("ICP - FFT plateau done");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT plateau error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_plot_FFT_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_FFT_basal_x_ROI->clear();
    ICP__vector_FFT_basal_y_ROI->clear();

    unsigned int nx = ICP__vector_FFT_basal_x->count();
    unsigned int ny = ICP__vector_FFT_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        double xminview = ICP__doublespinbox_FFT_view_down_basal->value();
        double xmaxview = ICP__doublespinbox_FFT_view_up_basal->value();

        for (unsigned int i = 0; i < nx; i++){
            if ((ICP__vector_FFT_basal_x->at(i) > xminview) && (ICP__vector_FFT_basal_x->at(i) < xmaxview)){
                ICP__vector_FFT_basal_x_ROI->append(ICP__vector_FFT_basal_x->at(i));
                ICP__vector_FFT_basal_y_ROI->append(ICP__vector_FFT_basal_y->at(i));
            }
        }

        bool res = plot(ICP__plot_FFT_basal, 0, ICP__vector_FFT_basal_x_ROI, ICP__vector_FFT_basal_y_ROI);
        if (!res){
            statusbar_show_warning("ICP - FFT basal plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - FFT basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT basal plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_plot_FFT_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_FFT_plateau_x_ROI->clear();
    ICP__vector_FFT_plateau_y_ROI->clear();

    unsigned int nx = ICP__vector_FFT_plateau_x->count();
    unsigned int ny = ICP__vector_FFT_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        double xminview = ICP__doublespinbox_FFT_view_down_plateau->value();
        double xmaxview = ICP__doublespinbox_FFT_view_up_plateau->value();

        for (unsigned int i = 0; i < nx; i++){
            if ((ICP__vector_FFT_plateau_x->at(i) > xminview) && (ICP__vector_FFT_plateau_x->at(i) < xmaxview)){
                ICP__vector_FFT_plateau_x_ROI->append(ICP__vector_FFT_plateau_x->at(i));
                ICP__vector_FFT_plateau_y_ROI->append(ICP__vector_FFT_plateau_y->at(i));
            }
        }

        bool res = plot(ICP__plot_FFT_plateau, 0, ICP__vector_FFT_plateau_x_ROI, ICP__vector_FFT_plateau_y_ROI);
        if (!res){
            statusbar_show_warning("ICP - FFT plateau plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - FFT plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT plateau plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_plot_FFT_ROI_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = ICP__vector_FFT_basal_x_ROI->count();
    int ny = ICP__vector_FFT_basal_y_ROI->count();

    if ((nx == ny) && (nx != 0)){
        QVector<double> x, y;
        x.append(ICP__doublespinbox_FFT_ROI_up_basal->value());
        x.append(ICP__doublespinbox_FFT_ROI_up_basal->value());
        x.append(ICP__doublespinbox_FFT_ROI_down_basal->value());
        x.append(ICP__doublespinbox_FFT_ROI_down_basal->value());

        bool res;
        double ymin = min(ICP__vector_FFT_basal_y_ROI, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI basal plot error - ERR1");
            return res;
        }
        double ymax = max(ICP__vector_FFT_basal_y_ROI, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI basal plot error - ERR2");
            return res;
        }

        y.append(ymin);
        y.append(ymax);
        y.append(ymax);
        y.append(ymin);

        res = plot(ICP__plot_FFT_basal, 1, &x, &y, false);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI basal plot error - ERR3");
        }
        else{
            statusbar_show_message("ICP - FFT ROI basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT ROI basal plot error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_plot_FFT_ROI_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = ICP__vector_FFT_plateau_x_ROI->count();
    int ny = ICP__vector_FFT_plateau_y_ROI->count();

    if ((nx == ny) && (nx != 0)){
        QVector<double> x, y;
        x.append(ICP__doublespinbox_FFT_ROI_up_plateau->value());
        x.append(ICP__doublespinbox_FFT_ROI_up_plateau->value());
        x.append(ICP__doublespinbox_FFT_ROI_down_plateau->value());
        x.append(ICP__doublespinbox_FFT_ROI_down_plateau->value());

        bool res;
        double ymin = min(ICP__vector_FFT_plateau_y_ROI, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI plateau plot error - ERR1");
            return res;
        }
        double ymax = max(ICP__vector_FFT_plateau_y_ROI, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI plateau plot error - ERR2");
            return res;
        }

        y.append(ymin);
        y.append(ymax);
        y.append(ymax);
        y.append(ymin);

        res = plot(ICP__plot_FFT_plateau, 1, &x, &y, false);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI plateau plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - FFT ROI plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - FFT ROI plateau plot error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_FFT_ROI_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = ICP__vector_FFT_basal_x_ROI->count();
    int ny = ICP__vector_FFT_basal_y_ROI->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        int pos = detect_max(ICP__vector_FFT_basal_y_ROI, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI basal error - ERR1");
            return res;
        }

        ICP__doublespinbox_FFT_ROI_down_basal->setValue(ICP__vector_FFT_basal_x_ROI->at(pos)-(double)FOURIER_ROI_RANGE);
        ICP__doublespinbox_FFT_ROI_up_basal->setValue(ICP__vector_FFT_basal_x_ROI->at(pos)+2.*(double)FOURIER_ROI_RANGE);

        statusbar_show_message("ICP - FFT ROI basal done");
        return true;
    }
    else{
        statusbar_show_warning("ICP - FFT ROI basal error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_FFT_ROI_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int nx = ICP__vector_FFT_plateau_x_ROI->count();
    int ny = ICP__vector_FFT_plateau_y_ROI->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        int pos = detect_max(ICP__vector_FFT_plateau_y_ROI, &res);
        if (!res){
            statusbar_show_warning("ICP - FFT ROI plateau error - ERR1");
            return res;
        }

        ICP__doublespinbox_FFT_ROI_down_plateau->setValue(ICP__vector_FFT_plateau_x_ROI->at(pos)-(double)FOURIER_ROI_RANGE);
        ICP__doublespinbox_FFT_ROI_up_plateau->setValue(ICP__vector_FFT_plateau_x_ROI->at(pos)+2.*(double)FOURIER_ROI_RANGE);

        statusbar_show_message("ICP - FFT ROI plateau done");
        return true;
    }
    else{
        statusbar_show_warning("ICP - FFT ROI plateau error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_IFFT_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_IFFT_basal_x->clear();
    ICP__vector_IFFT_basal_y->clear();

    unsigned int nx = ICP__vector_selection_basal_x->count();
    unsigned int ny = ICP__vector_selection_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        nx = ICP__vector_FFT_basal_x->count();
        ny = ICP__vector_FFT_basal_y->count();

        if ((nx == ny) && (nx != 0)){
            unsigned int min_pos = 0;
            unsigned int max_pos = 0;

            for (unsigned int i = 0; i < nx; i++){
                if (ICP__doublespinbox_FFT_ROI_down_basal->value() >= ICP__vector_FFT_basal_x->at(i)){
                    min_pos = i;
                }
                if (ICP__doublespinbox_FFT_ROI_up_basal->value() <= ICP__vector_FFT_basal_x->at(i)){
                    max_pos = i;
                    break;
                }
            }

            bool res;
            FFTIFFT(ICP__vector_IFFT_basal_x, ICP__vector_IFFT_basal_y, ICP__vector_selection_basal_x, ICP__vector_selection_basal_y, min_pos, max_pos, &res);
            if (!res){
                statusbar_show_warning("ICP - IFFT basal error - ERR1");
                return res;
            }

            res = ICP__do_plot_IFFT_basal();
            if (!res){
                statusbar_show_warning("ICP - IFFT basal error - ERR2");
            }
            else{
                statusbar_show_message("ICP - IFFT basal done");
            }
            return res;
        }
        else{
            statusbar_show_warning("ICP - IFFT basal error - ERR3");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - IFFT basal error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_IFFT_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_IFFT_plateau_x->clear();
    ICP__vector_IFFT_plateau_y->clear();

    unsigned int nx = ICP__vector_selection_plateau_x->count();
    unsigned int ny = ICP__vector_selection_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        nx = ICP__vector_FFT_plateau_x->count();
        ny = ICP__vector_FFT_plateau_y->count();

        if ((nx == ny) && (nx != 0)){
            unsigned int min_pos = 0;
            unsigned int max_pos = 0;

            for (unsigned int i = 0; i < nx; i++){
                if (ICP__doublespinbox_FFT_ROI_down_plateau->value() >= ICP__vector_FFT_plateau_x->at(i)){
                    min_pos = i;
                }
                if (ICP__doublespinbox_FFT_ROI_up_plateau->value() <= ICP__vector_FFT_plateau_x->at(i)){
                    max_pos = i;
                    break;
                }
            }

            bool res;
            FFTIFFT(ICP__vector_IFFT_plateau_x, ICP__vector_IFFT_plateau_y, ICP__vector_selection_plateau_x, ICP__vector_selection_plateau_y, min_pos, max_pos, &res);
            if (!res){
                statusbar_show_warning("ICP - IFFT plateau error - ERR1");
                return res;
            }

            res = ICP__do_plot_IFFT_plateau();
            if (!res){
                statusbar_show_warning("ICP - IFFT plateau error - ERR2");
            }
            else{
                statusbar_show_message("ICP - IFFT plateau done");
            }
            return res;
        }
        else{
            statusbar_show_warning("ICP - IFFT plateau error - ERR3");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - IFFT plateau error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_plot_IFFT_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_IFFT_basal_x->count();
    unsigned int ny = ICP__vector_IFFT_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(ICP__plot_IFFT_basal, 0, ICP__vector_IFFT_basal_x, ICP__vector_IFFT_basal_y);
        if (!res){
            statusbar_show_warning("ICP - IFFT basal plot error - ERR1");
            return res;
        }

        double ymin = min(ICP__vector_IFFT_basal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - IFFT basal plot error - ERR2");
            return res;
        }
        double ymax = max(ICP__vector_IFFT_basal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - IFFT basal plot error - ERR3");
            return res;
        }

        ICP__doublespinbox_threshold_basal->setRange(ymin, ymax);
        ICP__doublespinbox_threshold_basal->setValue(0.);

        res = ICP__do_plot_thresold_basal();
        if (!res){
            statusbar_show_warning("ICP - IFFT basal plot error - ERR4");
        }
        else{
            statusbar_show_message("ICP - IFFT basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - IFFT basal plot error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_plot_IFFT_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_IFFT_plateau_x->count();
    unsigned int ny = ICP__vector_IFFT_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(ICP__plot_IFFT_plateau, 0, ICP__vector_IFFT_plateau_x, ICP__vector_IFFT_plateau_y);
        if (!res){
            statusbar_show_warning("ICP - IFFT plateau plot error - ERR1");
            return res;
        }

        double ymin = min(ICP__vector_IFFT_plateau_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - IFFT plateau plot error - ERR2");
            return res;
        }
        double ymax = max(ICP__vector_IFFT_plateau_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - IFFT plateau plot error - ERR3");
            return res;
        }

        ICP__doublespinbox_threshold_plateau->setRange(ymin, ymax);
        ICP__doublespinbox_threshold_plateau->setValue(0.);

        res = ICP__do_plot_thresold_plateau();
        if (!res){
            statusbar_show_warning("ICP - IFFT plateau plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - IFFT plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - IFFT plateau plot error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_plot_thresold_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_IFFT_basal_x->count();
    unsigned int ny = ICP__vector_IFFT_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double xmin = min(ICP__vector_IFFT_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Threshold basal plot error - ERR1");
            return res;
        }
        double xmax = max(ICP__vector_IFFT_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Threshold basal plot error - ERR2");
            return res;
        }

        QVector<double> x, y;

        x.append(xmin);
        x.append(xmax);
        y.append(ICP__doublespinbox_threshold_basal->value());
        y.append(ICP__doublespinbox_threshold_basal->value());

        res = plot(ICP__plot_IFFT_basal, 1, &x, &y, false);
        if (!res){
            statusbar_show_warning("ICP - Threshold basal plot error - ERR3");
        }
        else{
            statusbar_show_message("ICP - Threshold basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Threshold basal plot error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_plot_thresold_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_IFFT_plateau_x->count();
    unsigned int ny = ICP__vector_IFFT_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double xmin = min(ICP__vector_IFFT_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Threshold plateau plot error - ERR1");
            return res;
        }
        double xmax = max(ICP__vector_IFFT_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Threshold plateau plot error - ERR2");
            return res;
        }

        QVector<double> x, y;

        x.append(xmin);
        x.append(xmax);
        y.append(ICP__doublespinbox_threshold_plateau->value());
        y.append(ICP__doublespinbox_threshold_plateau->value());

        res = plot(ICP__plot_IFFT_plateau, 1, &x, &y, false);
        if (!res){
            statusbar_show_warning("ICP - Threshold plateau plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - Threshold plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Threshold plateau plot error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_peak_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_peak_basal_x->clear();
    ICP__vector_peak_basal_y->clear();

    unsigned int nx = ICP__vector_IFFT_basal_x->count();
    unsigned int ny = ICP__vector_IFFT_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        detect_peaks(ICP__vector_peak_basal_x, ICP__vector_peak_basal_y, ICP__vector_IFFT_basal_x, ICP__vector_IFFT_basal_y, ICP__doublespinbox_threshold_basal->value(), &res);
        if (!res){
            statusbar_show_warning("ICP - Peak basal error - ERR1");
            return res;
        }

        res = ICP__do_plot_peak_basal();
        if (!res){
            statusbar_show_warning("ICP - Peak basal error - ERR2");
        }
        else{
            statusbar_show_message("ICP - Peak basal done");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Peak basal error - ERR3");
        return false;
    }
}

bool MainWindow::ICP__do_peak_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_peak_plateau_x->clear();
    ICP__vector_peak_plateau_y->clear();

    unsigned int nx = ICP__vector_IFFT_plateau_x->count();
    unsigned int ny = ICP__vector_IFFT_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        detect_peaks(ICP__vector_peak_plateau_x, ICP__vector_peak_plateau_y, ICP__vector_IFFT_plateau_x, ICP__vector_IFFT_plateau_y, ICP__doublespinbox_threshold_plateau->value(), &res);
        if (!res){
            statusbar_show_warning("ICP - Peak plateau error - ERR1");
            return res;
        }

        res = ICP__do_plot_peak_plateau();
        if (!res){
            statusbar_show_warning("ICP - Peak plateau error - ERR2");
        }
        else{
            statusbar_show_message("ICP - Peak plateau done");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Peak plateau error - ERR3");
        return false;
    }
}

bool MainWindow::ICP__do_plot_peak_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_peak_basal_x->count();
    unsigned int ny = ICP__vector_peak_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(ICP__plot_IFFT_basal, 2, ICP__vector_peak_basal_x, ICP__vector_peak_basal_y, false);
        if (!res){
            statusbar_show_warning("ICP - Peak basal plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - Peak basal plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Peak basal plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_plot_peak_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_peak_plateau_x->count();
    unsigned int ny = ICP__vector_peak_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(ICP__plot_IFFT_plateau, 2, ICP__vector_peak_plateau_x, ICP__vector_peak_plateau_y, false);
        if (!res){
            statusbar_show_warning("ICP - Peak plateau plot error - ERR1");
        }
        else{
            statusbar_show_message("ICP - Peak plateau plotted");
        }
        return res;
    }
    else{
        statusbar_show_warning("ICP - Peak plateau plot error - ERR2");
        return false;
    }
}

bool MainWindow::ICP__do_mean_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_mean_basal_x->clear();
    ICP__vector_mean_basal_y->clear();
    ICP__vector_mean_sd_basal_y->clear();

    unsigned int nx = ICP__vector_selection_basal_x->count();
    unsigned int ny = ICP__vector_selection_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        nx = ICP__vector_peak_basal_x->count();

        if (nx != 0){
            bool res;
            mean_icp(ICP__vector_mean_basal_x, ICP__vector_mean_basal_y, ICP__vector_mean_sd_basal_y, ICP__vector_selection_basal_x, ICP__vector_selection_basal_y, ICP__vector_peak_basal_x, &res);
            if (!res){
                statusbar_show_warning("ICP - Mean basal error - ERR1");
                return res;
            }

            res = ICP__do_plot_mean_basal();
            if (!res){
                statusbar_show_warning("ICP - Mean basal error - ERR2");
                return res;
            }

            ICP__int_isadjusted_basal = 0;

            statusbar_show_message("ICP - Mean basal done");
            return res;
        }
        else{
            statusbar_show_warning("ICP - Mean basal error - ERR3");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - Mean basal error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_mean_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    ICP__vector_mean_plateau_x->clear();
    ICP__vector_mean_plateau_y->clear();
    ICP__vector_mean_sd_plateau_y->clear();

    unsigned int nx = ICP__vector_selection_plateau_x->count();
    unsigned int ny = ICP__vector_selection_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        nx = ICP__vector_peak_plateau_x->count();

        if (nx != 0){
            bool res;
            mean_icp(ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y, ICP__vector_mean_sd_plateau_y, ICP__vector_selection_plateau_x, ICP__vector_selection_plateau_y, ICP__vector_peak_plateau_x, &res);
            if (!res){
                statusbar_show_warning("ICP - Mean plateau error - ERR1");
                return res;
            }

            res = ICP__do_plot_mean_plateau();
            if (!res){
                statusbar_show_warning("ICP - Mean plateau error - ERR2");
                return res;
            }

            ICP__int_isadjusted_plateau = 0;

            statusbar_show_message("ICP - Mean plateau done");
            return res;
        }
        else{
            statusbar_show_warning("ICP - Mean plateau error - ERR3");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - Mean plateau error - ERR4");
        return false;
    }
}

bool MainWindow::ICP__do_plot_mean_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_basal_x->count();
    unsigned int ny = ICP__vector_mean_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot_with_errorbar(ICP__plot_mean_basal, 0, ICP__vector_mean_basal_x, ICP__vector_mean_basal_y, ICP__vector_mean_sd_basal_y);
        if (!res){
            statusbar_show_warning("ICP - Mean basal plot error - ERR1");
            return res;
        }

        res = ICP__do_print_mean_basal();
        if (!res){
            statusbar_show_warning("ICP - Mean basal plot error - ERR2");
            return res;
        }

        res = COMPLIANCE__do_plot_icp_basal();
        if (!res){
            statusbar_show_warning("ICP - Mean basal plot error - ERR4");
            return res;
        }

        res = TRANSFERTFUNCTION__do_plot_icp_basal();
        if (!res){
            statusbar_show_warning("ICP - Mean basal plot error - ERR5");
            return res;
        }

        statusbar_show_message("ICP - Mean basal plotted");
        return res;
    }
    else{
        statusbar_show_warning("ICP - Mean basal plot error - ERR3");
        return false;
    }
}

bool MainWindow::ICP__do_plot_mean_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_plateau_x->count();
    unsigned int ny = ICP__vector_mean_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot_with_errorbar(ICP__plot_mean_plateau, 0, ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y, ICP__vector_mean_sd_plateau_y);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau plot error - ERR1");
            return res;
        }

        res = ICP__do_print_mean_plateau();
        if (!res){
            statusbar_show_warning("ICP - Mean plateau plot error - ERR2");
        }

        res = COMPLIANCE__do_plot_icp_plateau();
        if (!res){
            statusbar_show_warning("ICP - Mean plateau plot error - ERR4");
        }

        res = TRANSFERTFUNCTION__do_plot_icp_plateau();
        if (!res){
            statusbar_show_warning("ICP - Mean plateau plot error - ERR5");
        }

        statusbar_show_message("ICP - Mean plateau plotted");
        return res;
    }
    else{
        statusbar_show_warning("ICP - Mean plateau plot error - ERR3");
        return false;
    }
}

bool MainWindow::ICP__do_print_mean_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_basal_x->count();
    unsigned int ny = ICP__vector_mean_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double xmin = min(ICP__vector_mean_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean basal print error - ERR1");
            return res;
        }
        double xmax = max(ICP__vector_mean_basal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean basal print error - ERR2");
            return res;
        }
        double ymin = min(ICP__vector_mean_basal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean basal print error - ERR3");
            return res;
        }
        double ymax = max(ICP__vector_mean_basal_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean basal print error - ERR4");
            return res;
        }
        double ymean = mean(ICP__vector_mean_basal_y, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean basal print error - ERR5");
            return res;
        }

        ICP__double_cardiac_cycle_basal = xmax - xmin;
        ICP__double_heart_rate_basal = 60./ICP__double_cardiac_cycle_basal;
        ICP__double_min_basal = ymin;
        ICP__double_max_basal = ymax;
        ICP__double_mean_basal = ymean;
        ICP__double_amplitude_basal = ymax - ymin;

        ICP__label_cardiac_cycle_basal->setText("<b>Cardica cycle</b> = " + QString::number(ICP__double_cardiac_cycle_basal) + " s");
        ICP__label_heart_rate_basal->setText("<b>Heart rate</b> = " + QString::number(ICP__double_heart_rate_basal) + " bpm");
        ICP__label_min_basal->setText("<b>Min</b> = " + QString::number(ICP__double_min_basal) + " mmHg");
        ICP__label_max_basal->setText("<b>Max</b> = " + QString::number(ICP__double_max_basal) + " mmHg");
        ICP__label_mean_basal->setText("<b>Mean</b> = " + QString::number(ICP__double_mean_basal) + " mmHg");
        ICP__label_amplitude_basal->setText("<b>Amplitude</b> = " + QString::number(ICP__double_amplitude_basal) + " mmHg");

        statusbar_show_message("ICP - Mean basal printed");
        return true;
    }
    else{
        statusbar_show_warning("ICP - Mean basal print error - ERR6");
        return false;
    }
}

bool MainWindow::ICP__do_print_mean_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_plateau_x->count();
    unsigned int ny = ICP__vector_mean_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        bool res;
        double xmin = min(ICP__vector_mean_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau print error - ERR1");
            return res;
        }
        double xmax = max(ICP__vector_mean_plateau_x, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau print error - ERR2");
            return res;
        }
        double ymin = min(ICP__vector_mean_plateau_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau print error - ERR3");
            return res;
        }
        double ymax = max(ICP__vector_mean_plateau_y, NULL, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau print error - ERR4");
            return res;
        }
        double ymean = mean(ICP__vector_mean_plateau_y, &res);
        if (!res){
            statusbar_show_warning("ICP - Mean plateau print error - ERR5");
            return res;
        }

        ICP__double_cardiac_cycle_plateau = xmax - xmin;
        ICP__double_heart_rate_plateau = 60./ICP__double_cardiac_cycle_plateau;
        ICP__double_min_plateau = ymin;
        ICP__double_max_plateau = ymax;
        ICP__double_mean_plateau = ymean;
        ICP__double_amplitude_plateau = ymax - ymin;

        ICP__label_cardiac_cycle_plateau->setText("<b>Cardica cycle</b> = " + QString::number(ICP__double_cardiac_cycle_plateau) + " s");
        ICP__label_heart_rate_plateau->setText("<b>Heart rate</b> = " + QString::number(ICP__double_heart_rate_plateau) + " bpm");
        ICP__label_min_plateau->setText("<b>Min</b> = " + QString::number(ICP__double_min_plateau) + " mmHg");
        ICP__label_max_plateau->setText("<b>Max</b> = " + QString::number(ICP__double_max_plateau) + " mmHg");
        ICP__label_mean_plateau->setText("<b>Mean</b> = " + QString::number(ICP__double_mean_plateau) + " mmHg");
        ICP__label_amplitude_plateau->setText("<b>Amplitude</b> = " + QString::number(ICP__double_amplitude_plateau) + " mmHg");

        statusbar_show_message("ICP - Mean plateau printed");
        return true;
    }
    else{
        statusbar_show_warning("ICP - Mean plateau print error - ERR6");
        return false;
    }
}

bool MainWindow::ICP__do_auto(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = ICP__do_FFT_basal();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR1");
        return res;
    }
    res = ICP__do_FFT_ROI_basal();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR2");
        return res;
    }
    res = ICP__do_IFFT_basal();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR3");
        return res;
    }
    res = ICP__do_peak_basal();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR4");
        return res;
    }
    res = ICP__do_mean_basal();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR5");
        return res;
    }

    res = ICP__do_FFT_plateau();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR6");
        return res;
    }
    res = ICP__do_FFT_ROI_plateau();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR7");
        return res;
    }
    res = ICP__do_IFFT_plateau();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR8");
        return res;
    }
    res = ICP__do_peak_plateau();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR9");
        return res;
    }
    res = ICP__do_mean_plateau();
    if (!res){
        statusbar_show_warning("ICP - Auto error - ERR10");
        return res;
    }

    statusbar_show_message("ICP - Auto done");
    return true;
}

bool MainWindow::ICP__do_adjust_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_basal_x->count();
    unsigned int ny = ICP__vector_mean_basal_y->count();

    if ((nx == ny) && (nx != 0)){
        int pos = -1;
        bool res;
        min(ICP__vector_mean_basal_y, &pos, &res);
        if (!res){
            statusbar_show_warning("ICP - Adjust basal error - ERR1");
            return res;
        }

        if (pos != -1){
            move_curve(pos, ICP__vector_mean_basal_y, ICP__vector_mean_sd_basal_y, &res);
            if (!res){
                statusbar_show_warning("ICP - Adjust basal error - ERR2");
                return res;
            }

            res = ICP__do_plot_mean_basal();
            if (!res){
                statusbar_show_warning("ICP - Adjust basal error - ERR3");
            }
            else{
                statusbar_show_message("ICP - Adjust basal done");
            }

            ICP__int_isadjusted_basal = 1;

            return res;
        }
        else{
            statusbar_show_warning("ICP - Adjust basal error - ERR4");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - Adjust basal error - ERR5");
        return false;
    }
}

bool MainWindow::ICP__do_adjust_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_plateau_x->count();
    unsigned int ny = ICP__vector_mean_plateau_y->count();

    if ((nx == ny) && (nx != 0)){
        int pos = -1;
        bool res;
        min(ICP__vector_mean_plateau_y, &pos, &res);
        if (!res){
            statusbar_show_warning("ICP - Adjust plateau error - ERR1");
            return res;
        }

        if (pos != -1){
            move_curve(pos, ICP__vector_mean_plateau_y, ICP__vector_mean_sd_plateau_y, &res);
            if (!res){
                statusbar_show_warning("ICP - Adjust plateau error - ERR2");
                return res;
            }

            res = ICP__do_plot_mean_plateau();
            if (!res){
                statusbar_show_warning("ICP - Adjust plateau error - ERR3");
            }
            else{
                statusbar_show_message("ICP - Adjust plateau done");
            }

            ICP__int_isadjusted_plateau = 1;

            return res;
        }
        else{
            statusbar_show_warning("ICP - Adjust plateau error - ERR4");
            return false;
        }
    }
    else{
        statusbar_show_warning("ICP - Adjust plateau error - ERR5");
        return false;
    }
}


