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

void MainWindow::MRI__init_var_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_spinal_intracranial = new QMenu;

    //VBox
    MRI__vbox_arterial_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_venous_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_csf_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenous_flow_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenous_volume_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenouscsf_flow_spinal_intracranial = new QVBoxLayout;
    MRI__vbox_arteriovenouscsf_volume_spinal_intracranial = new QVBoxLayout;

    //HBox
    MRI__hbox_button_spinal_intracranial = new QHBoxLayout;

    //Plot
    MRI__plot_arterial_spinal_intracranial = new QCustomPlot;
    MRI__plot_venous_spinal_intracranial = new QCustomPlot;
    MRI__plot_csf_spinal_intracranial = new QCustomPlot;
    MRI__plot_arteriovenous_flow_spinal_intracranial = new QCustomPlot;
    MRI__plot_arteriovenous_volume_spinal_intracranial = new QCustomPlot;
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial = new QCustomPlot;
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial = new QCustomPlot;

    //Label
    MRI__label_arterial_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_venous_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_csf_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_arteriovenous_flow_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_arteriovenous_volume_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_flow_phase_shift_spinal_intracranial = new QLabel;
    MRI__label_arteriovenouscsf_volume_phase_shift_spinal_intracranial = new QLabel;

    //Button
    MRI__button_plot_00_spinal_intracranial = new QPushButton;
    MRI__button_menu_ncycles_spinal_intracranial = new QPushButton;
    MRI__button_legend_spinal_intracranial = new QPushButton;
    MRI__button_plot_all_spinal_intracranial = new QPushButton;
    MRI__button_show_up_venous_spinal_intracranial = new QPushButton;

    //Int
    MRI__int_ncycles_spinal_intracranial = 1;
}

void MainWindow::MRI__init_win_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_ncycles_spinal_intracranial->setTitle("Number of cycles");
    {
        QAction *action1 = new QAction("1", this);
        QAction *action2 = new QAction("2", this);
        QAction *action3 = new QAction("3", this);

        action1->setCheckable(true);
        action2->setCheckable(true);
        action3->setCheckable(true);

        MRI__menu_ncycles_spinal_intracranial->addAction(action1);
        MRI__menu_ncycles_spinal_intracranial->addAction(action2);
        MRI__menu_ncycles_spinal_intracranial->addAction(action3);
    }

    //Grid
    MRI__grid_spinal_intracranial->addLayout(MRI__hbox_button_spinal_intracranial, 0, 0, 1, 12);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_arterial_spinal_intracranial, 1, 0, 10, 11);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_arterial_spinal_intracranial, 1, 11, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_venous_spinal_intracranial, 11, 0, 10, 11);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_venous_spinal_intracranial, 11, 11, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_csf_spinal_intracranial, 21, 0, 10, 11);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_csf_spinal_intracranial, 21, 11, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_arteriovenous_flow_spinal_intracranial, 31, 0, 10, 5);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_arteriovenous_flow_spinal_intracranial, 31, 5, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_arteriovenouscsf_flow_spinal_intracranial, 31, 6, 10, 5);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_arteriovenouscsf_flow_spinal_intracranial, 31, 11, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_arteriovenous_volume_spinal_intracranial, 41, 0, 10, 5);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_arteriovenous_volume_spinal_intracranial, 41, 5, 10, 1);
    MRI__grid_spinal_intracranial->addWidget(MRI__plot_arteriovenouscsf_volume_spinal_intracranial, 41, 6, 10, 5);
    MRI__grid_spinal_intracranial->addLayout(MRI__vbox_arteriovenouscsf_volume_spinal_intracranial, 41, 11, 10, 1);

    //VBox
    MRI__vbox_arterial_spinal_intracranial->addWidget(MRI__label_arterial_phase_shift_spinal_intracranial);
    MRI__vbox_venous_spinal_intracranial->addWidget(MRI__label_venous_phase_shift_spinal_intracranial);
    MRI__vbox_csf_spinal_intracranial->addWidget(MRI__label_csf_phase_shift_spinal_intracranial);
    MRI__vbox_arteriovenous_flow_spinal_intracranial->addWidget(MRI__label_arteriovenous_flow_phase_shift_spinal_intracranial);
    MRI__vbox_arteriovenouscsf_flow_spinal_intracranial->addWidget(MRI__label_arteriovenouscsf_flow_phase_shift_spinal_intracranial);
    MRI__vbox_arteriovenous_volume_spinal_intracranial->addWidget(MRI__label_arteriovenous_volume_phase_shift_spinal_intracranial);
    MRI__vbox_arteriovenouscsf_volume_spinal_intracranial->addWidget(MRI__label_arteriovenouscsf_volume_phase_shift_spinal_intracranial);

    //HBox
    MRI__hbox_button_spinal_intracranial->addWidget(MRI__button_plot_00_spinal_intracranial);
    MRI__hbox_button_spinal_intracranial->addWidget(MRI__button_menu_ncycles_spinal_intracranial);
    MRI__hbox_button_spinal_intracranial->addWidget(MRI__button_legend_spinal_intracranial);
    MRI__hbox_button_spinal_intracranial->addWidget(MRI__button_plot_all_spinal_intracranial);
    MRI__hbox_button_spinal_intracranial->addWidget(MRI__button_show_up_venous_spinal_intracranial);

    //Plot
    MRI__plot_arterial_spinal_intracranial->addGraph();
    MRI__plot_arterial_spinal_intracranial->addGraph();
    MRI__plot_arterial_spinal_intracranial->addGraph();
    MRI__plot_arterial_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_venous_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_csf_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenous_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->addGraph();
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->addGraph();

    //Button
    MRI__button_plot_00_spinal_intracranial->setText("Plot (0,0)");
    MRI__button_plot_00_spinal_intracranial->setCheckable(true);
    MRI__button_menu_ncycles_spinal_intracranial->setText("Number of cycles");
    MRI__button_menu_ncycles_spinal_intracranial->setMenu(MRI__menu_ncycles_spinal_intracranial);
    MRI__button_legend_spinal_intracranial->setText("Legend");
    MRI__button_legend_spinal_intracranial->setCheckable(true);
    MRI__button_plot_all_spinal_intracranial->setText("Plot all");
    MRI__button_plot_all_spinal_intracranial->setCheckable(true);
    MRI__button_show_up_venous_spinal_intracranial->setText("Show up");
    MRI__button_show_up_venous_spinal_intracranial->setCheckable(true);
}

void MainWindow::MRI__init_sig_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Button
    connect(MRI__button_plot_00_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_arterial_spinal_intracranial()));
    connect(MRI__button_plot_00_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_spinal_intracranial()));
    connect(MRI__menu_ncycles_spinal_intracranial, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_ncycles_spinal_intracranial(QAction*)));
    connect(MRI__button_legend_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_legend_spinal_intracranial()));
    connect(MRI__button_plot_all_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_spinal_intracranial()));
    connect(MRI__button_plot_all_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_csf_spinal_intracranial()));
    connect(MRI__button_show_up_venous_spinal_intracranial, SIGNAL(clicked(bool)), this, SLOT(MRI__do_plot_venous_spinal_intracranial()));
}

void MainWindow::MRI__init_css_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPen RedPen;
    RedPen.setColor(QColor(Qt::red));
    QPen RedPen2 = QPen(RedPen);
    RedPen2.setWidth(2);
    QPen RedDotPen = QPen(RedPen);
    RedDotPen.setStyle(Qt::DashLine);
    QPen RedDotPen2 = QPen(RedDotPen);
    RedDotPen2.setWidth(2);

    QPen BluePen;
    BluePen.setColor(QColor(Qt::blue));
    QPen BluePen2 = QPen(BluePen);
    BluePen2.setWidth(2);
    QPen BlueDotPen = QPen(BluePen);
    BlueDotPen.setStyle(Qt::DashLine);
    QPen BlueDotPen2 = QPen(BlueDotPen);
    BlueDotPen2.setWidth(2);
    QPen BlueDashDotPen = QPen(BluePen);
    BlueDashDotPen.setStyle(Qt::DashDotLine);
    QPen BlueDashDotPen2 = QPen(BlueDashDotPen);
    BlueDashDotPen2.setWidth(2);

    QPen GreenPen;
    GreenPen.setColor(QColor(Qt::green));
    QPen GreenPen2 = QPen(GreenPen);
    GreenPen2.setWidth(2);
    QPen GreenDotPen = QPen(GreenPen);
    GreenDotPen.setStyle(Qt::DashLine);
    QPen GreenDotPen2 = QPen(GreenDotPen);
    GreenDotPen2.setWidth(2);
    QPen GreenDashDotPen = QPen(GreenPen);
    GreenDashDotPen.setStyle(Qt::DashDotLine);
    QPen GreenDashDotPen2 = QPen(GreenDashDotPen);
    GreenDashDotPen2.setWidth(2);

    QPen CyanPen;
    CyanPen.setColor(QColor(Qt::darkCyan));
    QPen CyanPen2 = QPen(CyanPen);
    CyanPen2.setWidth(2);
    QPen CyanDotPen = QPen(CyanPen);
    CyanDotPen.setStyle(Qt::DashLine);
    QPen CyanDotPen2 = QPen(CyanDotPen);
    CyanDotPen2.setWidth(2);

    QPen YellowPen;
    YellowPen.setColor(QColor(Qt::darkYellow));
    QPen YellowPen2 = QPen(YellowPen);
    YellowPen2.setWidth(2);
    QPen YellowDotPen = QPen(YellowPen);
    YellowDotPen.setStyle(Qt::DashLine);
    QPen YellowDotPen2 = QPen(YellowDotPen);
    YellowDotPen2.setWidth(2);

    //Plot
    MRI__plot_arterial_spinal_intracranial->graph(0)->setPen(RedPen);
    MRI__plot_arterial_spinal_intracranial->graph(0)->setName("Arterial spinal");
    MRI__plot_arterial_spinal_intracranial->graph(1)->setPen(RedPen2);
    MRI__plot_arterial_spinal_intracranial->graph(1)->setName("Arterial intracranial");
    MRI__plot_arterial_spinal_intracranial->graph(2)->setPen(RedDotPen);
    MRI__plot_arterial_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_arterial_spinal_intracranial->graph(3)->setPen(RedDotPen2);
    MRI__plot_arterial_spinal_intracranial->graph(3)->setName("Max intracranial");

    MRI__plot_venous_spinal_intracranial->graph(0)->setPen(BluePen);
    MRI__plot_venous_spinal_intracranial->graph(0)->setName("Venous spinal");
    MRI__plot_venous_spinal_intracranial->graph(1)->setPen(BluePen2);
    MRI__plot_venous_spinal_intracranial->graph(1)->setName("Venous intracranial");
    MRI__plot_venous_spinal_intracranial->graph(2)->setPen(BlueDotPen);
    MRI__plot_venous_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_venous_spinal_intracranial->graph(3)->setPen(BlueDotPen2);
    MRI__plot_venous_spinal_intracranial->graph(3)->setName("Max intracranial");
    MRI__plot_venous_spinal_intracranial->graph(4)->setPen(BlueDashDotPen);
    MRI__plot_venous_spinal_intracranial->graph(4)->setName("Venous spinal (not corrected)");
    MRI__plot_venous_spinal_intracranial->graph(5)->setPen(BlueDashDotPen2);
    MRI__plot_venous_spinal_intracranial->graph(5)->setName("Venous intracranial (not corrected)");

    MRI__plot_csf_spinal_intracranial->graph(0)->setPen(GreenPen);
    MRI__plot_csf_spinal_intracranial->graph(0)->setName("CSF spinal");
    MRI__plot_csf_spinal_intracranial->graph(1)->setPen(GreenPen2);
    MRI__plot_csf_spinal_intracranial->graph(1)->setName("CSF intracranial");
    MRI__plot_csf_spinal_intracranial->graph(2)->setPen(GreenDotPen);
    MRI__plot_csf_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_csf_spinal_intracranial->graph(3)->setPen(GreenDotPen2);
    MRI__plot_csf_spinal_intracranial->graph(3)->setName("Max intracranial");
    MRI__plot_csf_spinal_intracranial->graph(4)->setPen(GreenDashDotPen);
    MRI__plot_csf_spinal_intracranial->graph(4)->setName("CSF spinal (not corrected)");
    MRI__plot_csf_spinal_intracranial->graph(5)->setPen(GreenDashDotPen2);
    MRI__plot_csf_spinal_intracranial->graph(5)->setName("CSF intracranial (not corrected)");

    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(0)->setName("AV flow spinal");
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(1)->setPen(CyanPen2);
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(1)->setName("AV flow intracranial");
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(2)->setPen(CyanDotPen);
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(3)->setPen(CyanDotPen2);
    MRI__plot_arteriovenous_flow_spinal_intracranial->graph(3)->setName("Max intracranial");

    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(0)->setName("AV volume spinal");
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(1)->setPen(CyanPen2);
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(1)->setName("AV volume intracranial");
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(2)->setPen(CyanDotPen);
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(3)->setPen(CyanDotPen2);
    MRI__plot_arteriovenous_volume_spinal_intracranial->graph(3)->setName("Max intracranial");

    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(0)->setName("AVCSF flow spinal");
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(1)->setPen(YellowPen2);
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(1)->setName("AVCSF flow intracranial");
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(2)->setPen(YellowDotPen);
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(3)->setPen(YellowDotPen2);
    MRI__plot_arteriovenouscsf_flow_spinal_intracranial->graph(3)->setName("Max intracranial");

    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(0)->setName("AVCSF volume spinal");
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(1)->setPen(YellowPen2);
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(1)->setName("AVCSF volume intracranial");
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(2)->setPen(YellowDotPen);
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(2)->setName("Max spinal");
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(3)->setPen(YellowDotPen2);
    MRI__plot_arteriovenouscsf_volume_spinal_intracranial->graph(3)->setName("Max intracranial");
}

bool MainWindow::MRI__do_plot_arterial_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_arterial_spinal_x->count();
    unsigned int nyS = MRI__vector_arterial_spinal_y->count();

    unsigned int nxI = MRI__vector_arterial_intracranial_x->count();
    unsigned int nyI = MRI__vector_arterial_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;

        if (MRI__int_ncycles_spinal_intracranial > 1){
            double maxx = max(MRI__vector_arterial_spinal_x, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR1");
                return res;
            }

            QVector<double> TMP__arterial_x, TMP__arterial_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nxS;
                TMP__arterial_x.append(MRI__vector_arterial_spinal_x->at(i%nxS) + current_cycle*maxx);
                TMP__arterial_y.append(MRI__vector_arterial_spinal_y->at(i%nyS));
            }

            res = plot(MRI__plot_arterial_spinal_intracranial, 0, &TMP__arterial_x, &TMP__arterial_y);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_arterial_spinal_intracranial, 0, MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y);
            if (!res){
                statusbar_show_warning("Arterial spinal plot error - ERR3");
                return res;
            }
        }
        if (MRI__button_plot_00_spinal_intracranial->isChecked()){
            MRI__plot_arterial_spinal_intracranial->yAxis->setRangeLower(0.);
            MRI__plot_arterial_spinal_intracranial->replot();
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;

        if (MRI__int_ncycles_spinal_intracranial > 1){
            double maxx = max(MRI__vector_arterial_intracranial_x, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR4");
                return res;
            }

            QVector<double> TMP__arterial_x, TMP__arterial_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nxI;
                TMP__arterial_x.append(MRI__vector_arterial_intracranial_x->at(i%nxI) + current_cycle*maxx);
                TMP__arterial_y.append(MRI__vector_arterial_intracranial_y->at(i%nyI));
            }

            res = plot(MRI__plot_arterial_spinal_intracranial, 1, &TMP__arterial_x, &TMP__arterial_y);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR5");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_arterial_spinal_intracranial, 1, MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR6");
                return res;
            }
        }
        if ((nxS == nyS) && (nxS != 0)){
            double minyS = min(MRI__vector_arterial_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR7");
                return res;
            }
            double maxyS = max(MRI__vector_arterial_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR8");
                return res;
            }
            double minyI = min(MRI__vector_arterial_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR9");
                return res;
            }
            double maxyI = max(MRI__vector_arterial_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arterial spinal intracranial plot error - ERR10");
                return res;
            }
            MRI__plot_arterial_spinal_intracranial->yAxis->setRange(min(minyS, minyI), max(maxyS, maxyI));
        }
        if (MRI__button_plot_00_spinal_intracranial->isChecked()){
            MRI__plot_arterial_spinal_intracranial->yAxis->setRangeLower(0.);
            MRI__plot_arterial_spinal_intracranial->replot();
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        max(MRI__vector_arterial_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Arterial spinal intracranial plot error - ERR11");
            return res;
        }

        int posI;
        max(MRI__vector_arterial_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Arterial spinal intracranial plot error - ERR12");
            return res;
        }

        double minx = min(MRI__vector_arterial_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arterial spinal intracranial plot error - ERR13");
            return res;
        }

        double maxx = max(MRI__vector_arterial_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arterial spinal intracranial plot error - ERR14");
            return res;
        }

        double dphi = MRI__vector_arterial_spinal_x->at(posI) - MRI__vector_arterial_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_arterial_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_arterial_spinal_x->at(posS));
        maxS_x.append(MRI__vector_arterial_spinal_x->at(posS));
        maxS_y.append(MRI__plot_arterial_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_arterial_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arterial_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("Arterial spinalintracranial  plot error - ERR15");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_arterial_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_arterial_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_arterial_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_arterial_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arterial_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("Arterial spinal intracranial plot error - ERR16");
            return res;
        }
    }
    return true;
}

bool MainWindow::MRI__do_plot_venous_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_venous_spinal_x->count();
    unsigned int nyS = MRI__vector_venous_corrected_spinal_y->count();

    unsigned int nxI = MRI__vector_venous_intracranial_x->count();
    unsigned int nyI = MRI__vector_venous_corrected_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;
        if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
            QVector<double> TMP__venous_x, TMP__venous_y;
            if (MRI__int_ncycles_spinal_intracranial > 1){
                double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR1");
                    return res;
                }

                for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nxS;
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nxS) + current_cycle*maxx);
                    TMP__venous_y.append(-MRI__vector_venous_corrected_spinal_y->at(i%nyS));
                }
            }
            else{
                for (unsigned int i = 0; i < nxS; i++){
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i));
                    TMP__venous_y.append(-MRI__vector_venous_corrected_spinal_y->at(i));
                }
            }

            res = plot(MRI__plot_venous_spinal_intracranial, 0, &TMP__venous_x, &TMP__venous_y);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR2");
                return res;
            }
        }
        else{
            if (MRI__int_ncycles_spinal_intracranial > 1){
                double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR3");
                    return res;
                }

                QVector<double> TMP__venous_x, TMP__venous_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nxS;
                    TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nxS) + current_cycle*maxx);
                    TMP__venous_y.append(MRI__vector_venous_corrected_spinal_y->at(i%nyS));
                }

                res = plot(MRI__plot_venous_spinal_intracranial, 0, &TMP__venous_x, &TMP__venous_y);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR4");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_venous_spinal_intracranial, 0, MRI__vector_venous_spinal_x, MRI__vector_venous_corrected_spinal_y);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR5");
                    return res;
                }
            }
        }

        if (MRI__button_plot_all_spinal_intracranial->isChecked()){
            nyS = MRI__vector_venous_spinal_y->count();
            if (nxS == nyS){
                if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                    QVector<double> TMP__venous_x, TMP__venous_y;
                    if (MRI__int_ncycles_spinal_intracranial > 1){
                        double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR6");
                            return res;
                        }

                        for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                            int current_cycle = 0;
                            if (i != 0) current_cycle = (double)i/(double)nxS;
                            TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nxS) + current_cycle*maxx);
                            TMP__venous_y.append(-MRI__vector_venous_spinal_y->at(i%nyS));
                        }
                    }
                    else{
                        for (unsigned int i = 0; i < nxS; i++){
                            TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i));
                            TMP__venous_y.append(-MRI__vector_venous_spinal_y->at(i));
                        }
                    }

                    res = plot(MRI__plot_venous_spinal_intracranial, 4, &TMP__venous_x, &TMP__venous_y, false);
                    if (!res){
                        statusbar_show_warning("Venous spinal intracranial plot error - ERR7");
                        return res;
                    }
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(-max(max(MRI__vector_venous_spinal_y), max(MRI__vector_venous_corrected_spinal_y)), -min(min(MRI__vector_venous_spinal_y), min(MRI__vector_venous_corrected_spinal_y)));
                }
                else{
                    if (MRI__int_ncycles_spinal_intracranial > 1){
                        QVector<double> TMP__venous_x, TMP__venous_y;

                        double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR8");
                            return res;
                        }

                        for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                            int current_cycle = 0;
                            if (i != 0) current_cycle = (double)i/(double)nxS;
                            TMP__venous_x.append(MRI__vector_venous_spinal_x->at(i%nxS) + current_cycle*maxx);
                            TMP__venous_y.append(MRI__vector_venous_spinal_y->at(i%nyS));
                        }

                        res = plot(MRI__plot_venous_spinal_intracranial, 4, &TMP__venous_x, &TMP__venous_y, false);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR9");
                            return res;
                        }
                    }
                    else{
                        res = plot(MRI__plot_venous_spinal_intracranial, 4, MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y, false);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR10");
                            return res;
                        }
                    }
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(min(min(MRI__vector_venous_spinal_y), min(MRI__vector_venous_corrected_spinal_y)), max(max(MRI__vector_venous_spinal_y), max(MRI__vector_venous_corrected_spinal_y)));
                }
            }
        }
        else{
            MRI__plot_venous_spinal_intracranial->graph(4)->clearData();
        }

        if (MRI__button_plot_00_spinal_intracranial->isChecked()){
            if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                MRI__plot_venous_spinal_intracranial->yAxis->setRangeLower(0.);
            }
            else{
                MRI__plot_venous_spinal_intracranial->yAxis->setRangeUpper(0.);
            }
        }

        MRI__plot_venous_spinal_intracranial->replot();
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;
        if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
            QVector<double> TMP__venous_x, TMP__venous_y;
            if (MRI__int_ncycles_spinal_intracranial > 1){
                double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR11");
                    return res;
                }

                for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nxI;
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nxI) + current_cycle*maxx);
                    TMP__venous_y.append(-MRI__vector_venous_corrected_intracranial_y->at(i%nyI));
                }
            }
            else{
                for (unsigned int i = 0; i < nxI; i++){
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i));
                    TMP__venous_y.append(-MRI__vector_venous_corrected_intracranial_y->at(i));
                }
            }

            res = plot(MRI__plot_venous_spinal_intracranial, 1, &TMP__venous_x, &TMP__venous_y);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR12");
                return res;
            }
        }
        else{
            if (MRI__int_ncycles_spinal_intracranial > 1){
                double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal plot error - ERR13");
                    return res;
                }

                QVector<double> TMP__venous_x, TMP__venous_y;
                for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                    int current_cycle = 0;
                    if (i != 0) current_cycle = (double)i/(double)nxI;
                    TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nxI) + current_cycle*maxx);
                    TMP__venous_y.append(MRI__vector_venous_corrected_intracranial_y->at(i%nyI));
                }

                res = plot(MRI__plot_venous_spinal_intracranial, 1, &TMP__venous_x, &TMP__venous_y);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR14");
                    return res;
                }
            }
            else{
                res = plot(MRI__plot_venous_spinal_intracranial, 1, MRI__vector_venous_intracranial_x, MRI__vector_venous_corrected_intracranial_y);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR15");
                    return res;
                }
            }
        }

        if (MRI__button_plot_all_spinal_intracranial->isChecked()){
            nyI = MRI__vector_venous_intracranial_y->count();
            if (nxI == nyI){
                if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                    QVector<double> TMP__venous_x, TMP__venous_y;
                    if (MRI__int_ncycles_spinal_intracranial > 1){
                        double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR16");
                            return res;
                        }

                        for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                            int current_cycle = 0;
                            if (i != 0) current_cycle = (double)i/(double)nxI;
                            TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nxI) + current_cycle*maxx);
                            TMP__venous_y.append(-MRI__vector_venous_intracranial_y->at(i%nyI));
                        }
                    }
                    else{
                        for (unsigned int i = 0; i < nxS; i++){
                            TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i));
                            TMP__venous_y.append(-MRI__vector_venous_intracranial_y->at(i));
                        }
                    }

                    res = plot(MRI__plot_venous_spinal_intracranial,5, &TMP__venous_x, &TMP__venous_y, false);
                    if (!res){
                        statusbar_show_warning("Venous spinal intracranial plot error - ERR17");
                        return res;
                    }
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(-max(max(MRI__vector_venous_intracranial_y), max(MRI__vector_venous_corrected_intracranial_y)), -min(min(MRI__vector_venous_intracranial_y), min(MRI__vector_venous_corrected_intracranial_y)));
                }
                else{
                    if (MRI__int_ncycles_spinal_intracranial > 1){
                        QVector<double> TMP__venous_x, TMP__venous_y;

                        double maxx = max(MRI__vector_venous_intracranial_x, NULL, &res);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR18");
                            return res;
                        }

                        for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                            int current_cycle = 0;
                            if (i != 0) current_cycle = (double)i/(double)nxI;
                            TMP__venous_x.append(MRI__vector_venous_intracranial_x->at(i%nxI) + current_cycle*maxx);
                            TMP__venous_y.append(MRI__vector_venous_intracranial_y->at(i%nyI));
                        }

                        res = plot(MRI__plot_venous_spinal_intracranial, 5, &TMP__venous_x, &TMP__venous_y, false);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR19");
                            return res;
                        }
                    }
                    else{
                        res = plot(MRI__plot_venous_spinal_intracranial, 5, MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y, false);
                        if (!res){
                            statusbar_show_warning("Venous spinal intracranial plot error - ERR20");
                            return res;
                        }
                    }
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(min(min(MRI__vector_venous_intracranial_y), min(MRI__vector_venous_corrected_intracranial_y)), max(max(MRI__vector_venous_intracranial_y), max(MRI__vector_venous_corrected_intracranial_y)));
                }
            }
        }
        else{
            MRI__plot_venous_spinal_intracranial->graph(5)->clearData();
        }

        if ((nxS == nyS) && (nxS != 0)){
            double minySC = min(MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR21");
                return res;
            }
            double maxySC = max(MRI__vector_venous_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR22");
                return res;
            }
            double minyIC = min(MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR23");
                return res;
            }
            double maxyIC = max(MRI__vector_venous_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Venous spinal intracranial plot error - ERR24");
                return res;
            }
            if (MRI__button_plot_all_spinal_intracranial->isChecked()){
                double minyS = min(MRI__vector_venous_spinal_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR25");
                    return res;
                }
                double maxyS = max(MRI__vector_venous_spinal_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR26");
                    return res;
                }
                double minyI = min(MRI__vector_venous_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR27");
                    return res;
                }
                double maxyI = max(MRI__vector_venous_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("Venous spinal intracranial plot error - ERR28");
                    return res;
                }
                if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(-max(maxyI, max(maxyS, max(maxySC, maxyIC))), -min(minyI, min(minyS, min(minySC, minyIC))));
                }
                else{
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(min(minyI, min(minyS, min(minySC, minyIC))), max(maxyI, max(maxyS, max(maxySC, maxyIC))));
                }
            }
            else{
                if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(-max(maxySC, maxyIC), -min(minySC, minyIC));
                }
                else{
                    MRI__plot_venous_spinal_intracranial->yAxis->setRange(min(minySC, minyIC), max(maxySC, maxyIC));
                }
            }
        }

        if (MRI__button_plot_00_spinal_intracranial->isChecked()){
            if (MRI__button_show_up_venous_spinal_intracranial->isChecked()){
                MRI__plot_venous_spinal_intracranial->yAxis->setRangeLower(0.);
            }
            else{
                MRI__plot_venous_spinal_intracranial->yAxis->setRangeUpper(0.);
            }
        }

        MRI__plot_venous_spinal_intracranial->replot();
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        min(MRI__vector_venous_corrected_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Venous spinal intracranial plot error - ERR29");
            return res;
        }

        int posI;
        min(MRI__vector_venous_corrected_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Venous spinal intracranial plot error - ERR30");
            return res;
        }

        double minx = min(MRI__vector_venous_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Venous spinal intracranial plot error - ERR31");
            return res;
        }

        double maxx = max(MRI__vector_venous_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Venous spinal intracranial plot error - ERR35");
            return res;
        }

        double dphi = MRI__vector_venous_spinal_x->at(posI) - MRI__vector_venous_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_venous_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_venous_spinal_x->at(posS));
        maxS_x.append(MRI__vector_venous_spinal_x->at(posS));
        maxS_y.append(MRI__plot_venous_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_venous_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_venous_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("Venous spinalintracranial  plot error - ERR36");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_venous_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_venous_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_venous_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_venous_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_venous_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("Venous spinal intracranial plot error - ERR37");
            return res;
        }
    }

    return true;
}

bool MainWindow::MRI__do_plot_csf_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_csf_spinal_x->count();
    unsigned int nyS = MRI__vector_csf_corrected_spinal_y->count();

    unsigned int nxI = MRI__vector_csf_intracranial_x->count();
    unsigned int nyI = MRI__vector_csf_corrected_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;

        if (MRI__int_ncycles_spinal_intracranial > 1){
            double maxx = max(MRI__vector_csf_spinal_x, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal plot error - ERR1");
                return res;
            }

            QVector<double> TMP__csf_x, TMP__csf_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nxS;
                TMP__csf_x.append(MRI__vector_csf_spinal_x->at(i%nxS) + current_cycle*maxx);
                TMP__csf_y.append(MRI__vector_csf_corrected_spinal_y->at(i%nyS));
            }

            res = plot(MRI__plot_csf_spinal_intracranial, 0, &TMP__csf_x, &TMP__csf_y);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR2");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_csf_spinal_intracranial, 0, MRI__vector_csf_spinal_x, MRI__vector_csf_corrected_spinal_y);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR3");
                return res;
            }
        }

        if (MRI__button_plot_all_spinal_intracranial->isChecked()){
            nyS = MRI__vector_csf_spinal_y->count();
            if (nxS == nyS){
                if (MRI__int_ncycles_spinal_intracranial > 1){
                    QVector<double> TMP__csf_x, TMP__csf_y;

                    double maxx = max(MRI__vector_csf_spinal_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR4");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxS; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nxS;
                        TMP__csf_x.append(MRI__vector_csf_spinal_x->at(i%nxS) + current_cycle*maxx);
                        TMP__csf_y.append(MRI__vector_csf_spinal_y->at(i%nyS));
                    }

                    res = plot(MRI__plot_csf_spinal_intracranial, 4, &TMP__csf_x, &TMP__csf_y, false);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR5");
                        return res;
                    }
                }
                else{
                    res = plot(MRI__plot_csf_spinal_intracranial, 4, MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y, false);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR6");
                        return res;
                    }
                }
                MRI__plot_csf_spinal_intracranial->yAxis->setRange(min(min(MRI__vector_csf_spinal_y), min(MRI__vector_csf_corrected_spinal_y)), max(max(MRI__vector_csf_spinal_y), max(MRI__vector_csf_corrected_spinal_y)));
            }
        }
        else{
            MRI__plot_csf_spinal_intracranial->graph(4)->clearData();
            MRI__plot_csf_spinal_intracranial->replot();
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;

        if (MRI__int_ncycles_spinal_intracranial > 1){
            double maxx = max(MRI__vector_csf_intracranial_x, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal plot error - ERR7");
                return res;
            }

            QVector<double> TMP__csf_x, TMP__csf_y;
            for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                int current_cycle = 0;
                if (i != 0) current_cycle = (double)i/(double)nxI;
                TMP__csf_x.append(MRI__vector_csf_intracranial_x->at(i%nxI) + current_cycle*maxx);
                TMP__csf_y.append(MRI__vector_csf_corrected_intracranial_y->at(i%nyI));
            }

            res = plot(MRI__plot_csf_spinal_intracranial, 1, &TMP__csf_x, &TMP__csf_y);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR8");
                return res;
            }
        }
        else{
            res = plot(MRI__plot_csf_spinal_intracranial, 1, MRI__vector_csf_intracranial_x, MRI__vector_csf_corrected_intracranial_y);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR9");
                return res;
            }
        }

        if (MRI__button_plot_all_spinal_intracranial->isChecked()){
            nyI = MRI__vector_csf_intracranial_y->count();
            if (nxI == nyI){
                if (MRI__int_ncycles_spinal_intracranial > 1){
                    QVector<double> TMP__csf_x, TMP__csf_y;

                    double maxx = max(MRI__vector_csf_intracranial_x, NULL, &res);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR10");
                        return res;
                    }

                    for (unsigned int i = 0; i < MRI__int_ncycles_spinal_intracranial*nxI; i++){
                        int current_cycle = 0;
                        if (i != 0) current_cycle = (double)i/(double)nxI;
                        TMP__csf_x.append(MRI__vector_csf_intracranial_x->at(i%nxI) + current_cycle*maxx);
                        TMP__csf_y.append(MRI__vector_csf_intracranial_y->at(i%nyI));
                    }

                    res = plot(MRI__plot_csf_spinal_intracranial, 5, &TMP__csf_x, &TMP__csf_y, false);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR11");
                        return res;
                    }
                }
                else{
                    res = plot(MRI__plot_csf_spinal_intracranial, 5, MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y, false);
                    if (!res){
                        statusbar_show_warning("CSF spinal intracranial plot error - ERR12");
                        return res;
                    }
                }
                MRI__plot_csf_spinal_intracranial->yAxis->setRange(min(min(MRI__vector_csf_intracranial_y), min(MRI__vector_csf_corrected_intracranial_y)), max(max(MRI__vector_csf_intracranial_y), max(MRI__vector_csf_corrected_intracranial_y)));
            }
        }
        else{
            MRI__plot_csf_spinal_intracranial->graph(5)->clearData();
            MRI__plot_csf_spinal_intracranial->replot();
        }

        if ((nxS == nyS) && (nxS != 0)){
            double minySC = min(MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR13");
                return res;
            }
            double maxySC = max(MRI__vector_csf_corrected_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR14");
                return res;
            }
            double minyIC = min(MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR15");
                return res;
            }
            double maxyIC = max(MRI__vector_csf_corrected_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("CSF spinal intracranial plot error - ERR16");
                return res;
            }
            if (MRI__button_plot_all_spinal_intracranial->isChecked()){
                double minyS = min(MRI__vector_csf_spinal_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF spinal intracranial plot error - ERR17");
                    return res;
                }
                double maxyS = max(MRI__vector_csf_spinal_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF spinal intracranial plot error - ERR18");
                    return res;
                }
                double minyI = min(MRI__vector_csf_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF spinal intracranial plot error - ERR19");
                    return res;
                }
                double maxyI = max(MRI__vector_csf_intracranial_y, NULL, &res);
                if (!res){
                    statusbar_show_warning("CSF spinal intracranial plot error - ERR20");
                    return res;
                }

                MRI__plot_csf_spinal_intracranial->yAxis->setRange(min(minyI, min(minyS, min(minySC, minyIC))), max(maxyI, max(maxyS, max(maxySC, maxyIC))));
            }
            else{
                MRI__plot_csf_spinal_intracranial->yAxis->setRange(min(minySC, minyIC), max(maxySC, maxyIC));
            }
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        min(MRI__vector_csf_corrected_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("CSF spinal intracranial plot error - ERR21");
            return res;
        }

        int posI;
        min(MRI__vector_csf_corrected_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("CSF spinal intracranial plot error - ERR22");
            return res;
        }

        double minx = min(MRI__vector_csf_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("CSF spinal intracranial plot error - ERR23");
            return res;
        }

        double maxx = max(MRI__vector_csf_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("CSF spinal intracranial plot error - ERR24");
            return res;
        }

        double dphi = MRI__vector_csf_spinal_x->at(posI) - MRI__vector_csf_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_csf_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_csf_spinal_x->at(posS));
        maxS_x.append(MRI__vector_csf_spinal_x->at(posS));
        maxS_y.append(MRI__plot_csf_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_csf_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_csf_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("CSF spinalintracranial  plot error - ERR25");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_csf_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_csf_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_csf_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_csf_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_csf_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("CSF spinal intracranial plot error - ERR26");
            return res;
        }
    }

    return true;
}

bool MainWindow::MRI__do_plot_arteriovenous_flow_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_arteriovenous_flow_spinal_x->count();
    unsigned int nyS = MRI__vector_arteriovenous_flow_spinal_y->count();

    unsigned int nxI = MRI__vector_arteriovenous_flow_intracranial_x->count();
    unsigned int nyI = MRI__vector_arteriovenous_flow_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenous_flow_spinal_intracranial, 0, MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR1");
            return res;
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenous_flow_spinal_intracranial, 1, MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR2");
            return res;
        }
        if ((nxS == nyS) && (nxS != 0)){
            double minyS = min(MRI__vector_arteriovenous_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous flow spinal plot error - ERR3");
                return res;
            }
            double maxyS = max(MRI__vector_arteriovenous_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous flow spinal plot error - ERR4");
                return res;
            }
            double minyI = min(MRI__vector_arteriovenous_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous flow spinal plot error - ERR5");
                return res;
            }
            double maxyI = max(MRI__vector_arteriovenous_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous flow spinal plot error - ERR6");
                return res;
            }
            MRI__plot_arteriovenous_flow_spinal_intracranial->yAxis->setRange(min(minyS, minyI), max(maxyS, maxyI));
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        max(MRI__vector_arteriovenous_flow_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR7");
            return res;
        }

        int posI;
        max(MRI__vector_arteriovenous_flow_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR8");
            return res;
        }

        double minx = min(MRI__vector_arteriovenous_flow_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR9");
            return res;
        }

        double maxx = max(MRI__vector_arteriovenous_flow_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal plot error - ERR10");
            return res;
        }

        double dphi = MRI__vector_arteriovenous_flow_spinal_x->at(posI) - MRI__vector_arteriovenous_flow_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_arteriovenous_flow_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_arteriovenous_flow_spinal_x->at(posS));
        maxS_x.append(MRI__vector_arteriovenous_flow_spinal_x->at(posS));
        maxS_y.append(MRI__plot_arteriovenous_flow_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_arteriovenous_flow_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenous_flow_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinalintracranial  plot error - ERR11");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_arteriovenous_flow_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_arteriovenous_flow_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_arteriovenous_flow_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_arteriovenous_flow_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenous_flow_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("Arteriovenous flow spinal intracranial plot error - ERR12");
            return res;
        }
    }
    return true;
}

bool MainWindow::MRI__do_plot_arteriovenous_volume_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_arteriovenous_volume_spinal_x->count();
    unsigned int nyS = MRI__vector_arteriovenous_volume_spinal_y->count();

    unsigned int nxI = MRI__vector_arteriovenous_volume_intracranial_x->count();
    unsigned int nyI = MRI__vector_arteriovenous_volume_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenous_volume_spinal_intracranial, 0, MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR1");
            return res;
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenous_volume_spinal_intracranial, 1, MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR2");
            return res;
        }
        if ((nxS == nyS) && (nxS != 0)){
            double minyS = min(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous volume spinal plot error - ERR3");
                return res;
            }
            double maxyS = max(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous volume spinal plot error - ERR4");
                return res;
            }
            double minyI = min(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous volume spinal plot error - ERR5");
                return res;
            }
            double maxyI = max(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenous volume spinal plot error - ERR6");
                return res;
            }
            MRI__plot_arteriovenous_volume_spinal_intracranial->yAxis->setRange(min(minyS, minyI), max(maxyS, maxyI));
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        max(MRI__vector_arteriovenous_volume_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR7");
            return res;
        }

        int posI;
        max(MRI__vector_arteriovenous_volume_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR8");
            return res;
        }

        double minx = min(MRI__vector_arteriovenous_volume_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR9");
            return res;
        }

        double maxx = max(MRI__vector_arteriovenous_volume_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal plot error - ERR10");
            return res;
        }

        double dphi = MRI__vector_arteriovenous_volume_spinal_x->at(posI) - MRI__vector_arteriovenous_volume_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_arteriovenous_volume_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_arteriovenous_volume_spinal_x->at(posS));
        maxS_x.append(MRI__vector_arteriovenous_volume_spinal_x->at(posS));
        maxS_y.append(MRI__plot_arteriovenous_volume_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_arteriovenous_volume_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenous_volume_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinalintracranial  plot error - ERR11");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_arteriovenous_volume_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_arteriovenous_volume_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_arteriovenous_volume_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_arteriovenous_volume_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenous_volume_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("Arteriovenous volume spinal intracranial plot error - ERR12");
            return res;
        }
    }
    return true;
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_flow_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_arteriovenouscsf_flow_spinal_x->count();
    unsigned int nyS = MRI__vector_arteriovenouscsf_flow_spinal_y->count();

    unsigned int nxI = MRI__vector_arteriovenouscsf_flow_intracranial_x->count();
    unsigned int nyI = MRI__vector_arteriovenouscsf_flow_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenouscsf_flow_spinal_intracranial, 0, MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR1");
            return res;
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenouscsf_flow_spinal_intracranial, 1, MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR2");
            return res;
        }
        if ((nxS == nyS) && (nxS != 0)){
            double minyS = min(MRI__vector_arteriovenouscsf_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR3");
                return res;
            }
            double maxyS = max(MRI__vector_arteriovenouscsf_flow_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR4");
                return res;
            }
            double minyI = min(MRI__vector_arteriovenouscsf_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR5");
                return res;
            }
            double maxyI = max(MRI__vector_arteriovenouscsf_flow_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR6");
                return res;
            }
            MRI__plot_arteriovenouscsf_flow_spinal_intracranial->yAxis->setRange(min(minyS, minyI), max(maxyS, maxyI));
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        max(MRI__vector_arteriovenouscsf_flow_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR7");
            return res;
        }

        int posI;
        max(MRI__vector_arteriovenouscsf_flow_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR8");
            return res;
        }

        double minx = min(MRI__vector_arteriovenouscsf_flow_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR9");
            return res;
        }

        double maxx = max(MRI__vector_arteriovenouscsf_flow_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf flow spinal plot error - ERR10");
            return res;
        }

        double dphi = MRI__vector_arteriovenouscsf_flow_spinal_x->at(posI) - MRI__vector_arteriovenouscsf_flow_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_arteriovenouscsf_flow_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_arteriovenouscsf_flow_spinal_x->at(posS));
        maxS_x.append(MRI__vector_arteriovenouscsf_flow_spinal_x->at(posS));
        maxS_y.append(MRI__plot_arteriovenouscsf_flow_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_arteriovenouscsf_flow_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenouscsf_flow_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF flow spinalintracranial  plot error - ERR11");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_arteriovenouscsf_flow_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_arteriovenouscsf_flow_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_arteriovenouscsf_flow_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_arteriovenouscsf_flow_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenouscsf_flow_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF flow spinal intracranial plot error - ERR12");
            return res;
        }
    }
    return true;
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_volume_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nxS = MRI__vector_arteriovenouscsf_volume_spinal_x->count();
    unsigned int nyS = MRI__vector_arteriovenouscsf_volume_spinal_y->count();

    unsigned int nxI = MRI__vector_arteriovenouscsf_volume_intracranial_x->count();
    unsigned int nyI = MRI__vector_arteriovenouscsf_volume_intracranial_y->count();

    if ((nxS == nyS) && (nxS != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenouscsf_volume_spinal_intracranial, 0, MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR1");
            return res;
        }
    }
    if ((nxI == nyI) && (nxI != 0)){
        bool res;
        res = plot(MRI__plot_arteriovenouscsf_volume_spinal_intracranial, 1, MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR2");
            return res;
        }
        if ((nxS == nyS) && (nxS != 0)){
            double minyS = min(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR3");
                return res;
            }
            double maxyS = max(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR4");
                return res;
            }
            double minyI = min(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR5");
                return res;
            }
            double maxyI = max(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR6");
                return res;
            }
            MRI__plot_arteriovenouscsf_volume_spinal_intracranial->yAxis->setRange(min(minyS, minyI), max(maxyS, maxyI));
        }
    }
    if ((nxS == nyS) && (nxS == nxI) && (nxI == nyI) && (nxS != 0)){
        bool res;

        int posS;
        max(MRI__vector_arteriovenouscsf_volume_spinal_y, &posS, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR7");
            return res;
        }

        int posI;
        max(MRI__vector_arteriovenouscsf_volume_intracranial_y, &posI, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR8");
            return res;
        }

        double minx = min(MRI__vector_arteriovenouscsf_volume_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR9");
            return res;
        }

        double maxx = max(MRI__vector_arteriovenouscsf_volume_spinal_x, NULL, &res);
        if (!res){
            statusbar_show_warning("Arteriovenouscsf volume spinal plot error - ERR10");
            return res;
        }

        double dphi = MRI__vector_arteriovenouscsf_volume_spinal_x->at(posI) - MRI__vector_arteriovenouscsf_volume_spinal_x->at(posS);
        double dphiPC = (dphi / (maxx - minx)) * 100.;

        MRI__label_arteriovenouscsf_volume_phase_shift_spinal_intracranial->setText("<b>Phase shift</b> = " + QString::number(dphi) + "s (" + QString::number(dphiPC) + "%)");

        QVector<double> maxS_x, maxS_y;
        maxS_x.append(MRI__vector_arteriovenouscsf_volume_spinal_x->at(posS));
        maxS_x.append(MRI__vector_arteriovenouscsf_volume_spinal_x->at(posS));
        maxS_y.append(MRI__plot_arteriovenouscsf_volume_spinal_intracranial->yAxis->range().lower);
        maxS_y.append(MRI__plot_arteriovenouscsf_volume_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenouscsf_volume_spinal_intracranial, 2, &maxS_x, &maxS_y, false);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF volume spinalintracranial  plot error - ERR11");
            return res;
        }

        QVector<double> maxI_x, maxI_y;
        maxI_x.append(MRI__vector_arteriovenouscsf_volume_intracranial_x->at(posI));
        maxI_x.append(MRI__vector_arteriovenouscsf_volume_intracranial_x->at(posI));
        maxI_y.append(MRI__plot_arteriovenouscsf_volume_spinal_intracranial->yAxis->range().lower);
        maxI_y.append(MRI__plot_arteriovenouscsf_volume_spinal_intracranial->yAxis->range().upper);

        res = plot(MRI__plot_arteriovenouscsf_volume_spinal_intracranial, 3, &maxI_x, &maxI_y, false);
        if (!res){
            statusbar_show_warning("ArteriovenousCSF volume spinal intracranial plot error - ERR12");
            return res;
        }
    }
    return true;
}

bool MainWindow::MRI__do_ncycles_spinal_intracranial(QAction *action){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString action_txt = action->text();
    bool res;
    int ncycles_spinal_intracranial = action_txt.toInt(&res);
    if (!res){
        for (int i = 0; i < 3; i++) MRI__menu_ncycles_spinal_intracranial->actions().at(i)->setChecked(false);
        statusbar_show_warning("Select number of cycles error - ERR1");
        return false;
    }
    else{
        for (int i = 0; i < 3; i++){
            if (i != (ncycles_spinal_intracranial-1)) MRI__menu_ncycles_spinal_intracranial->actions().at(i)->setChecked(false);
        }
        MRI__int_ncycles_spinal_intracranial = ncycles_spinal_intracranial;

        res = MRI__do_plot_arterial_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR2");
            return res;
        }
        res = MRI__do_plot_venous_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR3");
            return res;
        }
        res = MRI__do_plot_csf_spinal_intracranial();
        if (!res){
            statusbar_show_warning("Select number of cycles error - ERR4");
            return res;
        }

        statusbar_show_message("Select number of cycles done");
        return res;
    }
}

bool MainWindow::MRI__do_legend_spinal_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__button_legend_spinal_intracranial->isChecked()){
        MRI__plot_arterial_spinal_intracranial->legend->setVisible(true);
        MRI__plot_venous_spinal_intracranial->legend->setVisible(true);
        MRI__plot_csf_spinal_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenous_flow_spinal_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenous_volume_spinal_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_flow_spinal_intracranial->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_volume_spinal_intracranial->legend->setVisible(true);
    }
    else{
        MRI__plot_arterial_spinal_intracranial->legend->setVisible(false);
        MRI__plot_venous_spinal_intracranial->legend->setVisible(false);
        MRI__plot_csf_spinal_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenous_flow_spinal_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenous_volume_spinal_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_flow_spinal_intracranial->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_volume_spinal_intracranial->legend->setVisible(false);
    }

    bool res = MRI__do_plot_arterial_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR1");
        return res;
    }

    res = MRI__do_plot_venous_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR2");
        return res;
    }

    res = MRI__do_plot_csf_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR3");
        return res;
    }

    res = MRI__do_plot_arteriovenous_flow_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR4");
        return res;
    }

    res = MRI__do_plot_arteriovenous_volume_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR5");
        return res;
    }

    res = MRI__do_plot_arteriovenouscsf_flow_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR6");
        return res;
    }

    res = MRI__do_plot_arteriovenouscsf_volume_spinal_intracranial();
    if (!res){
        statusbar_show_warning("Legend error - ERR7");
        return res;
    }

    statusbar_show_message("Legend done");
    return res;
}


