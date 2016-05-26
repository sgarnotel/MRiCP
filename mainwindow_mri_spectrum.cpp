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

void MainWindow::MRI__init_var_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //HBox
    MRI__hbox_arterial_spectrum = new QHBoxLayout;
    MRI__hbox_venous_spectrum = new QHBoxLayout;
    MRI__hbox_csf_spectrum = new QHBoxLayout;
    MRI__hbox_arteriovenous_flow_spectrum = new QHBoxLayout;
    MRI__hbox_arteriovenous_volume_spectrum = new QHBoxLayout;
    MRI__hbox_arteriovenouscsf_flow_spectrum = new QHBoxLayout;
    MRI__hbox_arteriovenouscsf_volume_spectrum = new QHBoxLayout;

    //Plot
    MRI__plot_arterial_spectrum = new QCustomPlot;
    MRI__plot_venous_spectrum = new QCustomPlot;
    MRI__plot_csf_spectrum = new QCustomPlot;
    MRI__plot_arteriovenous_flow_spectrum = new QCustomPlot;
    MRI__plot_arteriovenous_volume_spectrum = new QCustomPlot;
    MRI__plot_arteriovenouscsf_flow_spectrum = new QCustomPlot;
    MRI__plot_arteriovenouscsf_volume_spectrum = new QCustomPlot;

    //Label
    MRI__label_arterial_spectrum = new QLabel;
    MRI__label_venous_spectrum = new QLabel;
    MRI__label_csf_spectrum = new QLabel;
    MRI__label_arteriovenous_flow_spectrum = new QLabel;
    MRI__label_arteriovenous_volume_spectrum = new QLabel;
    MRI__label_arteriovenouscsf_flow_spectrum = new QLabel;
    MRI__label_arteriovenouscsf_volume_spectrum = new QLabel;

    //SpinBox
    MRI__doublespinbox_arterial_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arterial_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_venous_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_venous_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_csf_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_csf_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenous_flow_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenous_flow_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenous_volume_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenous_volume_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum = new QDoubleSpinBox;
    MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum = new QDoubleSpinBox;

    //Button
    MRI__button_legend_spectrum = new QPushButton;

    //Vector
    MRI__vector_arterial_spinal_spectrum_x = new QVector<double>;
    MRI__vector_arterial_spinal_spectrum_y = new QVector<double>;
    MRI__vector_venous_spinal_spectrum_x = new QVector<double>;
    MRI__vector_venous_spinal_spectrum_y = new QVector<double>;
    MRI__vector_csf_spinal_spectrum_x = new QVector<double>;
    MRI__vector_csf_spinal_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenous_flow_spinal_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenous_flow_spinal_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenous_volume_spinal_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenous_volume_spinal_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_spinal_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_spinal_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_spinal_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_spinal_spectrum_y = new QVector<double>;
    MRI__vector_arterial_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_arterial_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_venous_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_venous_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_csf_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_csf_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenous_flow_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenous_flow_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenous_volume_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenous_volume_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_y = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_x = new QVector<double>;
    MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_y = new QVector<double>;
}

void MainWindow::MRI__init_win_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Grid
    MRI__grid_spectrum->addLayout(MRI__hbox_arterial_spectrum, 0, 0, 1, 10);
    MRI__grid_spectrum->addWidget(MRI__plot_arterial_spectrum, 1, 0, 10, 10);
    MRI__grid_spectrum->addLayout(MRI__hbox_venous_spectrum, 11, 0, 1, 10);
    MRI__grid_spectrum->addWidget(MRI__plot_venous_spectrum, 12, 0, 10, 10);
    MRI__grid_spectrum->addLayout(MRI__hbox_csf_spectrum, 22, 0, 1, 10);
    MRI__grid_spectrum->addWidget(MRI__plot_csf_spectrum, 23, 0, 10, 10);
    MRI__grid_spectrum->addLayout(MRI__hbox_arteriovenous_flow_spectrum, 33, 0, 1, 5);
    MRI__grid_spectrum->addWidget(MRI__plot_arteriovenous_flow_spectrum, 34, 0, 10, 5);
    MRI__grid_spectrum->addLayout(MRI__hbox_arteriovenous_volume_spectrum, 44, 0, 1, 5);
    MRI__grid_spectrum->addWidget(MRI__plot_arteriovenous_volume_spectrum, 45, 0, 10, 5);
    MRI__grid_spectrum->addLayout(MRI__hbox_arteriovenouscsf_flow_spectrum, 33, 5, 1, 5);
    MRI__grid_spectrum->addWidget(MRI__plot_arteriovenouscsf_flow_spectrum, 34, 5, 10, 5);
    MRI__grid_spectrum->addLayout(MRI__hbox_arteriovenouscsf_volume_spectrum, 44, 5, 1, 5);
    MRI__grid_spectrum->addWidget(MRI__plot_arteriovenouscsf_volume_spectrum, 45, 5, 10, 5);

    //HBox
    MRI__hbox_arterial_spectrum->addWidget(MRI__button_legend_spectrum);
    MRI__hbox_arterial_spectrum->addWidget(MRI__label_arterial_spectrum);
    MRI__hbox_arterial_spectrum->addWidget(MRI__doublespinbox_arterial_down_spectrum);
    MRI__hbox_arterial_spectrum->addWidget(MRI__doublespinbox_arterial_up_spectrum);

    MRI__hbox_venous_spectrum->addWidget(MRI__label_venous_spectrum);
    MRI__hbox_venous_spectrum->addWidget(MRI__doublespinbox_venous_down_spectrum);
    MRI__hbox_venous_spectrum->addWidget(MRI__doublespinbox_venous_up_spectrum);

    MRI__hbox_csf_spectrum->addWidget(MRI__label_csf_spectrum);
    MRI__hbox_csf_spectrum->addWidget(MRI__doublespinbox_csf_down_spectrum);
    MRI__hbox_csf_spectrum->addWidget(MRI__doublespinbox_csf_up_spectrum);

    MRI__hbox_arteriovenous_flow_spectrum->addWidget(MRI__label_arteriovenous_flow_spectrum);
    MRI__hbox_arteriovenous_flow_spectrum->addWidget(MRI__doublespinbox_arteriovenous_flow_down_spectrum);
    MRI__hbox_arteriovenous_flow_spectrum->addWidget(MRI__doublespinbox_arteriovenous_flow_up_spectrum);

    MRI__hbox_arteriovenous_volume_spectrum->addWidget(MRI__label_arteriovenous_volume_spectrum);
    MRI__hbox_arteriovenous_volume_spectrum->addWidget(MRI__doublespinbox_arteriovenous_volume_down_spectrum);
    MRI__hbox_arteriovenous_volume_spectrum->addWidget(MRI__doublespinbox_arteriovenous_volume_up_spectrum);

    MRI__hbox_arteriovenouscsf_flow_spectrum->addWidget(MRI__label_arteriovenouscsf_flow_spectrum);
    MRI__hbox_arteriovenouscsf_flow_spectrum->addWidget(MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum);
    MRI__hbox_arteriovenouscsf_flow_spectrum->addWidget(MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum);

    MRI__hbox_arteriovenouscsf_volume_spectrum->addWidget(MRI__label_arteriovenouscsf_volume_spectrum);
    MRI__hbox_arteriovenouscsf_volume_spectrum->addWidget(MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum);
    MRI__hbox_arteriovenouscsf_volume_spectrum->addWidget(MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum);

    //Plot
    MRI__plot_arterial_spectrum->addGraph();
    MRI__plot_arterial_spectrum->addGraph();
    MRI__plot_venous_spectrum->addGraph();
    MRI__plot_venous_spectrum->addGraph();
    MRI__plot_csf_spectrum->addGraph();
    MRI__plot_csf_spectrum->addGraph();
    MRI__plot_arteriovenous_flow_spectrum->addGraph();
    MRI__plot_arteriovenous_flow_spectrum->addGraph();
    MRI__plot_arteriovenous_volume_spectrum->addGraph();
    MRI__plot_arteriovenous_volume_spectrum->addGraph();
    MRI__plot_arteriovenouscsf_flow_spectrum->addGraph();
    MRI__plot_arteriovenouscsf_flow_spectrum->addGraph();
    MRI__plot_arteriovenouscsf_volume_spectrum->addGraph();
    MRI__plot_arteriovenouscsf_volume_spectrum->addGraph();

    //Label
    MRI__label_arterial_spectrum->setText("Frequency range:");
    MRI__label_venous_spectrum->setText("Frequency range:");
    MRI__label_csf_spectrum->setText("Frequency range:");
    MRI__label_arteriovenous_flow_spectrum->setText("Frequency range:");
    MRI__label_arteriovenous_volume_spectrum->setText("Frequency range:");
    MRI__label_arteriovenouscsf_flow_spectrum->setText("Frequency range:");
    MRI__label_arteriovenouscsf_volume_spectrum->setText("Frequency range:");

    //SpinBox
    MRI__doublespinbox_arterial_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arterial_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_arterial_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arterial_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_venous_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_venous_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_venous_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_venous_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_csf_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_csf_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_csf_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_csf_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_arteriovenous_flow_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenous_flow_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_arteriovenous_flow_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenous_flow_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_arteriovenous_volume_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenous_volume_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_arteriovenous_volume_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenous_volume_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum->setToolTip("Up");
    MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum->setToolTip("Down");
    MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum->setRange(0., 0.);
    MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum->setToolTip("Up");

    //Button
    MRI__button_legend_spectrum->setText("Legend");
    MRI__button_legend_spectrum->setCheckable(true);
}

void MainWindow::MRI__init_sig_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    //SpinBox
    connect(MRI__doublespinbox_arterial_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arterial_spectrum()));
    connect(MRI__doublespinbox_arterial_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arterial_spectrum()));
    connect(MRI__doublespinbox_venous_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_venous_spectrum()));
    connect(MRI__doublespinbox_venous_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_venous_spectrum()));
    connect(MRI__doublespinbox_csf_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_csf_spectrum()));
    connect(MRI__doublespinbox_csf_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_csf_spectrum()));
    connect(MRI__doublespinbox_arteriovenous_flow_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenous_flow_spectrum()));
    connect(MRI__doublespinbox_arteriovenous_flow_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenous_flow_spectrum()));
    connect(MRI__doublespinbox_arteriovenous_volume_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenous_volume_spectrum()));
    connect(MRI__doublespinbox_arteriovenous_volume_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenous_volume_spectrum()));
    connect(MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenouscsf_flow_spectrum()));
    connect(MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenouscsf_flow_spectrum()));
    connect(MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenouscsf_volume_spectrum()));
    connect(MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum, SIGNAL(valueChanged(double)), this, SLOT(MRI__do_plot_arteriovenouscsf_volume_spectrum()));

    //Button
    connect(MRI__button_legend_spectrum, SIGNAL(clicked(bool)), this, SLOT(MRI__do_legend_spectrum()));
}

void MainWindow::MRI__init_css_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPen RedPen;
    RedPen.setColor(Qt::red);
    QPen RedPen2 = QPen(RedPen);
    RedPen2.setWidth(2);

    QPen BluePen;
    BluePen.setColor(Qt::blue);
    QPen BluePen2 = QPen(BluePen);
    BluePen2.setWidth(2);

    QPen GreenPen;
    GreenPen.setColor(Qt::green);
    QPen GreenPen2 = QPen(GreenPen);
    GreenPen2.setWidth(2);

    QPen CyanPen;
    CyanPen.setColor(Qt::darkCyan);
    QPen CyanPen2 = QPen(CyanPen);
    CyanPen2.setWidth(2);

    QPen YellowPen;
    YellowPen.setColor(Qt::darkYellow);
    QPen YellowPen2 = QPen(YellowPen);
    YellowPen2.setWidth(2);

    //PLot
    MRI__plot_arterial_spectrum->graph(0)->setPen(RedPen);
    MRI__plot_arterial_spectrum->graph(0)->setName("Arterial spinal");
    MRI__plot_arterial_spectrum->graph(1)->setPen(RedPen2);
    MRI__plot_arterial_spectrum->graph(1)->setName("Arterial intracranial");

    MRI__plot_venous_spectrum->graph(0)->setPen(BluePen);
    MRI__plot_venous_spectrum->graph(0)->setName("Venous spinal");
    MRI__plot_venous_spectrum->graph(1)->setPen(BluePen2);
    MRI__plot_venous_spectrum->graph(1)->setName("Venous intracranial");

    MRI__plot_csf_spectrum->graph(0)->setPen(GreenPen);
    MRI__plot_csf_spectrum->graph(0)->setName("CSF spinal");
    MRI__plot_csf_spectrum->graph(1)->setPen(GreenPen2);
    MRI__plot_csf_spectrum->graph(1)->setName("CSF intracranial");

    MRI__plot_arteriovenous_flow_spectrum->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_flow_spectrum->graph(0)->setName("Arteriovenous spinal");
    MRI__plot_arteriovenous_flow_spectrum->graph(1)->setPen(CyanPen2);
    MRI__plot_arteriovenous_flow_spectrum->graph(1)->setName("Arteriovenous intracranial");

    MRI__plot_arteriovenous_volume_spectrum->graph(0)->setPen(CyanPen);
    MRI__plot_arteriovenous_volume_spectrum->graph(0)->setName("Arteriovenous spinal");
    MRI__plot_arteriovenous_volume_spectrum->graph(1)->setPen(CyanPen2);
    MRI__plot_arteriovenous_volume_spectrum->graph(1)->setName("Arteriovenous intracranial");

    MRI__plot_arteriovenouscsf_flow_spectrum->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_flow_spectrum->graph(0)->setName("ArteriovenousCSF spinal");
    MRI__plot_arteriovenouscsf_flow_spectrum->graph(1)->setPen(YellowPen2);
    MRI__plot_arteriovenouscsf_flow_spectrum->graph(1)->setName("ArteriovenousCSF intracranial");

    MRI__plot_arteriovenouscsf_volume_spectrum->graph(0)->setPen(YellowPen);
    MRI__plot_arteriovenouscsf_volume_spectrum->graph(0)->setName("ArteriovenousCSF spinal");
    MRI__plot_arteriovenouscsf_volume_spectrum->graph(1)->setPen(YellowPen2);
    MRI__plot_arteriovenouscsf_volume_spectrum->graph(1)->setName("ArteriovenousCSF intracranial");
}

bool MainWindow::DoSpectrum(QVector<double> *SpectrumX, QVector<double> *SpectrumY,
                const QVector<double> *X, const QVector<double> *Y,
                const QVector<double> *SpectrumXO,
                QDoubleSpinBox *Down, QDoubleSpinBox *Up,
                bool (MainWindow::*PlotFunction)(),
                const QString StatusText){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Clear
    SpectrumX->clear();
    SpectrumY->clear();

    //Verify X and Y size
    unsigned int Nx = X->count();
    unsigned int Ny = Y->count();

    if ((Nx == Ny) && (Nx != 0)){
        bool Res;

        //Compute Spectrum Y
        FFT(SpectrumY, Y, &Res);
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR2");
            return Res;
        }

        //Verify Spectrum size
        unsigned int Nf = SpectrumY->count();
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR3");
            return Res;
        }

        //Compute Frequency X
        double Sample = 1. / (X->at(1) - X->at(0)) / Nx;
        for (unsigned int i = 0; i < Nf; i++){
                SpectrumX->append((double)i*Sample);
        }

        //DoubleSpinBox Range and Value
        double MinX = min(SpectrumX, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR4");
            return Res;
        }
        double MaxX = max(SpectrumX, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR5");
            return Res;
        }

        if (SpectrumXO->count() > 0){
            bool UnusedRes;
            double MinXO = min(SpectrumXO, NULL, &UnusedRes);
            if (UnusedRes){
                MinX = min(MinX, MinXO);
            }
            double MaxXO = max(SpectrumXO, NULL, &UnusedRes);
            if (UnusedRes){
                MaxX = max(MaxX, MaxXO);
            }
        }

        Down->setRange(MinX, MaxX);
        Down->setValue(MinX);
        Up->setRange(MinX, MaxX);
        Up->setValue(MaxX);

        //Plot Spectrum
        Res = (this->*PlotFunction)();
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR6");
            return Res;
        }

        statusbar_show_message("MRI SPECTRUM - " + StatusText + " spectrum done");
        return Res;
    }
    else{
        statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum error - ERR1");
        return false;
    }
}

bool MainWindow::PlotSpectrum(const QVector<double> *XS, const QVector<double> *YS,
                const QVector<double> *XI, const QVector<double> *YI,
                const QDoubleSpinBox *Down, const QDoubleSpinBox *Up,
                QCustomPlot *Plot,
                const QString StatusText){

    //Clear
    Plot->graph(0)->clearData();
    Plot->graph(1)->clearData();

    //Verify XS, YS, XI and YI size
    unsigned int NxS = XS->count();
    unsigned int NyS = YS->count();
    unsigned int NxI = XI->count();
    unsigned int NyI = YI->count();

    //For Range
    double MinYS, MaxYS;
    double MinYI, MaxYI;

    //Plot (XS, YS)
    if ((NxS == NyS) && (NxS != 0)){
        double DownValue = Down->value();
        double UpValue = Up->value();

        QVector<double> TMP__XS, TMP__YS;
        for (unsigned int i = 0; i < NxS; i++){
            if (XS->at(i) >= DownValue && XS->at(i) <= UpValue){
                TMP__XS.append(XS->at(i));
                TMP__YS.append(YS->at(i));
            }
        }

        bool Res = plot(Plot, 0, &TMP__XS, &TMP__YS);
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum plot error - ERR1");
            return Res;
        }

        MinYS = Plot->yAxis->range().lower;
        MaxYS = Plot->yAxis->range().upper;
    }
    //Plot (XI, YI)
    if ((NxI == NyI) && (NxI != 0)){
        double DownValue = Down->value();
        double UpValue = Up->value();

        QVector<double> TMP__XI, TMP__YI;
        for (unsigned int i = 0; i < NxI; i++){
            if (XI->at(i) >= DownValue && XI->at(i) <= UpValue){
                TMP__XI.append(XI->at(i));
                TMP__YI.append(YI->at(i));
            }
        }

        bool Res = plot(Plot, 1, &TMP__XI, &TMP__YI);
        if (!Res){
            statusbar_show_warning("MRI SPECTRUM - " + StatusText + " spectrum plot error - ERR2");
            return Res;
        }

        MinYI = Plot->yAxis->range().lower;
        MaxYI = Plot->yAxis->range().upper;
    }
    //Ajust Range
    if ((NxS == NyS) && (NxS != 0) && (NxI == NxS) && (NyI == NxS)){
        Plot->yAxis->setRange(min(MinYS, MinYI), max(MaxYS, MaxYI));
        Plot->replot();
    }

    statusbar_show_message("MRI SPECTRUM - " + StatusText + " spectrum plotted");
    return true;
}

bool MainWindow::MRI__do_arterial_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arterial_spinal_spectrum_x, MRI__vector_arterial_spinal_spectrum_y,
                      MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y,
                      MRI__vector_arterial_intracranial_spectrum_x,
                      MRI__doublespinbox_arterial_down_spectrum, MRI__doublespinbox_arterial_up_spectrum,
                      &MainWindow::MRI__do_plot_arterial_spectrum,
                      "Arterial spinal");
}

bool MainWindow::MRI__do_venous_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_venous_spinal_spectrum_x, MRI__vector_venous_spinal_spectrum_y,
                      MRI__vector_venous_spinal_x, MRI__vector_venous_corrected_spinal_y,
                      MRI__vector_venous_intracranial_spectrum_x,
                      MRI__doublespinbox_venous_down_spectrum, MRI__doublespinbox_venous_up_spectrum,
                      &MainWindow::MRI__do_plot_venous_spectrum,
                      "Venous spinal");
}

bool MainWindow::MRI__do_csf_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_csf_spinal_spectrum_x, MRI__vector_csf_spinal_spectrum_y,
                      MRI__vector_csf_spinal_x, MRI__vector_csf_corrected_spinal_y,
                      MRI__vector_csf_intracranial_spectrum_x,
                      MRI__doublespinbox_csf_down_spectrum, MRI__doublespinbox_csf_up_spectrum,
                      &MainWindow::MRI__do_plot_csf_spectrum,
                      "CSF spinal");
}

bool MainWindow::MRI__do_arteriovenous_flow_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenous_flow_spinal_spectrum_x, MRI__vector_arteriovenous_flow_spinal_spectrum_y,
                      MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y,
                      MRI__vector_arteriovenous_flow_intracranial_spectrum_x,
                      MRI__doublespinbox_arteriovenous_flow_down_spectrum, MRI__doublespinbox_arteriovenous_flow_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenous_flow_spectrum,
                      "Arteriovenous flow spinal");
}

bool MainWindow::MRI__do_arteriovenous_volume_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenous_volume_spinal_spectrum_x, MRI__vector_arteriovenous_volume_spinal_spectrum_y,
                      MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y,
                      MRI__vector_arteriovenous_volume_intracranial_spectrum_x,
                      MRI__doublespinbox_arteriovenous_volume_down_spectrum, MRI__doublespinbox_arteriovenous_volume_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenous_volume_spectrum,
                      "Arteriovenous volume spinal");
}

bool MainWindow::MRI__do_arteriovenouscsf_flow_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenouscsf_flow_spinal_spectrum_x, MRI__vector_arteriovenouscsf_flow_spinal_spectrum_y,
                      MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y,
                      MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_x,
                      MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum, MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenouscsf_flow_spectrum,
                      "ArteriovenousCSF flow spinal");
}

bool MainWindow::MRI__do_arteriovenouscsf_volume_spinal_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenouscsf_volume_spinal_spectrum_x, MRI__vector_arteriovenouscsf_volume_spinal_spectrum_y,
                      MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y,
                      MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_x,
                      MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum, MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenouscsf_volume_spectrum,
                      "ArteriovenousCSF volume spinal");
}

bool MainWindow::MRI__do_arterial_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arterial_intracranial_spectrum_x, MRI__vector_arterial_intracranial_spectrum_y,
                      MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y,
                      MRI__vector_arterial_spinal_spectrum_x,
                      MRI__doublespinbox_arterial_down_spectrum, MRI__doublespinbox_arterial_up_spectrum,
                      &MainWindow::MRI__do_plot_arterial_spectrum,
                      "Arterial intracranial");
}

bool MainWindow::MRI__do_venous_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_venous_intracranial_spectrum_x, MRI__vector_venous_intracranial_spectrum_y,
                      MRI__vector_venous_intracranial_x, MRI__vector_venous_corrected_intracranial_y,
                      MRI__vector_venous_spinal_spectrum_x,
                      MRI__doublespinbox_venous_down_spectrum, MRI__doublespinbox_venous_up_spectrum,
                      &MainWindow::MRI__do_plot_venous_spectrum,
                      "Venous intracranial");
}

bool MainWindow::MRI__do_csf_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_csf_intracranial_spectrum_x, MRI__vector_csf_intracranial_spectrum_y,
                      MRI__vector_csf_intracranial_x, MRI__vector_csf_corrected_intracranial_y,
                      MRI__vector_csf_spinal_spectrum_x,
                      MRI__doublespinbox_csf_down_spectrum, MRI__doublespinbox_csf_up_spectrum,
                      &MainWindow::MRI__do_plot_csf_spectrum,
                      "CSF intracranial");
}

bool MainWindow::MRI__do_arteriovenous_flow_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenous_flow_intracranial_spectrum_x, MRI__vector_arteriovenous_flow_intracranial_spectrum_y,
                      MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y,
                      MRI__vector_arteriovenous_flow_spinal_spectrum_x,
                      MRI__doublespinbox_arteriovenous_flow_down_spectrum, MRI__doublespinbox_arteriovenous_flow_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenous_flow_spectrum,
                      "Arteriovenous flow intracranial");
}

bool MainWindow::MRI__do_arteriovenous_volume_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenous_volume_intracranial_spectrum_x, MRI__vector_arteriovenous_volume_intracranial_spectrum_y,
                      MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y,
                      MRI__vector_arteriovenous_volume_spinal_spectrum_x,
                      MRI__doublespinbox_arteriovenous_volume_down_spectrum, MRI__doublespinbox_arteriovenous_volume_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenous_volume_spectrum,
                      "Arteriovenous volume intracranial");
}

bool MainWindow::MRI__do_arteriovenouscsf_flow_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_x, MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_y,
                      MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y,
                      MRI__vector_arteriovenouscsf_flow_spinal_spectrum_x,
                      MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum, MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenouscsf_flow_spectrum,
                      "ArteriovenousCSF flow intracranial");
}

bool MainWindow::MRI__do_arteriovenouscsf_volume_intracranial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return DoSpectrum(MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_x, MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_y,
                      MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y,
                      MRI__vector_arteriovenouscsf_volume_spinal_spectrum_x,
                      MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum, MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum,
                      &MainWindow::MRI__do_plot_arteriovenouscsf_volume_spectrum,
                      "ArteriovenousCSF volume intracranial");
}

bool MainWindow::MRI__do_plot_arterial_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_arterial_spinal_spectrum_x, MRI__vector_arterial_spinal_spectrum_y,
                        MRI__vector_arterial_intracranial_spectrum_x, MRI__vector_arterial_intracranial_spectrum_y,
                        MRI__doublespinbox_arterial_down_spectrum, MRI__doublespinbox_arterial_up_spectrum,
                        MRI__plot_arterial_spectrum,
                        "Arterial");
}

bool MainWindow::MRI__do_plot_venous_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_venous_spinal_spectrum_x, MRI__vector_venous_spinal_spectrum_y,
                        MRI__vector_venous_intracranial_spectrum_x, MRI__vector_venous_intracranial_spectrum_y,
                        MRI__doublespinbox_venous_down_spectrum, MRI__doublespinbox_venous_up_spectrum,
                        MRI__plot_venous_spectrum,
                        "Venous");
}

bool MainWindow::MRI__do_plot_csf_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_csf_spinal_spectrum_x, MRI__vector_csf_spinal_spectrum_y,
                        MRI__vector_csf_intracranial_spectrum_x, MRI__vector_csf_intracranial_spectrum_y,
                        MRI__doublespinbox_csf_down_spectrum, MRI__doublespinbox_csf_up_spectrum,
                        MRI__plot_csf_spectrum,
                        "CSF");
}

bool MainWindow::MRI__do_plot_arteriovenous_flow_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_arteriovenous_flow_spinal_spectrum_x, MRI__vector_arteriovenous_flow_spinal_spectrum_y,
                        MRI__vector_arteriovenous_flow_intracranial_spectrum_x, MRI__vector_arteriovenous_flow_intracranial_spectrum_y,
                        MRI__doublespinbox_arteriovenous_flow_down_spectrum, MRI__doublespinbox_arteriovenous_flow_up_spectrum,
                        MRI__plot_arteriovenous_flow_spectrum,
                        "Arteriovenous flow");
}

bool MainWindow::MRI__do_plot_arteriovenous_volume_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_arteriovenous_volume_spinal_spectrum_x, MRI__vector_arteriovenous_volume_spinal_spectrum_y,
                        MRI__vector_arteriovenous_volume_intracranial_spectrum_x, MRI__vector_arteriovenous_volume_intracranial_spectrum_y,
                        MRI__doublespinbox_arteriovenous_volume_down_spectrum, MRI__doublespinbox_arteriovenous_volume_up_spectrum,
                        MRI__plot_arteriovenous_volume_spectrum,
                        "Arteriovenous volume");
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_flow_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_arteriovenouscsf_flow_spinal_spectrum_x, MRI__vector_arteriovenouscsf_flow_spinal_spectrum_y,
                        MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_x, MRI__vector_arteriovenouscsf_flow_intracranial_spectrum_y,
                        MRI__doublespinbox_arteriovenouscsf_flow_down_spectrum, MRI__doublespinbox_arteriovenouscsf_flow_up_spectrum,
                        MRI__plot_arteriovenouscsf_flow_spectrum,
                        "ArteriovenousCSF flow");
}

bool MainWindow::MRI__do_plot_arteriovenouscsf_volume_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return PlotSpectrum(MRI__vector_arteriovenouscsf_volume_spinal_spectrum_x, MRI__vector_arteriovenouscsf_volume_spinal_spectrum_y,
                        MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_x, MRI__vector_arteriovenouscsf_volume_intracranial_spectrum_y,
                        MRI__doublespinbox_arteriovenouscsf_volume_down_spectrum, MRI__doublespinbox_arteriovenouscsf_volume_up_spectrum,
                        MRI__plot_arteriovenouscsf_volume_spectrum,
                        "ArteriovenousCSF volume");
}

bool MainWindow::MRI__do_legend_spectrum(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (MRI__button_legend_spectrum->isChecked()){
        MRI__plot_arterial_spectrum->legend->setVisible(true);
        MRI__plot_venous_spectrum->legend->setVisible(true);
        MRI__plot_csf_spectrum->legend->setVisible(true);
        MRI__plot_arteriovenous_flow_spectrum->legend->setVisible(true);
        MRI__plot_arteriovenous_volume_spectrum->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_flow_spectrum->legend->setVisible(true);
        MRI__plot_arteriovenouscsf_volume_spectrum->legend->setVisible(true);
    }
    else{
        MRI__plot_arterial_spectrum->legend->setVisible(false);
        MRI__plot_venous_spectrum->legend->setVisible(false);
        MRI__plot_csf_spectrum->legend->setVisible(false);
        MRI__plot_arteriovenous_flow_spectrum->legend->setVisible(false);
        MRI__plot_arteriovenous_volume_spectrum->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_flow_spectrum->legend->setVisible(false);
        MRI__plot_arteriovenouscsf_volume_spectrum->legend->setVisible(false);
    }

    MRI__plot_arterial_spectrum->replot();
    MRI__plot_venous_spectrum->replot();
    MRI__plot_csf_spectrum->replot();
    MRI__plot_arteriovenous_flow_spectrum->replot();
    MRI__plot_arteriovenous_volume_spectrum->replot();
    MRI__plot_arteriovenouscsf_flow_spectrum->replot();
    MRI__plot_arteriovenouscsf_volume_spectrum->replot();

    statusbar_show_message("MRI SPECTRUM - Legend done");
    return true;
}


