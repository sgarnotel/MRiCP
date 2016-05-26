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

void MainWindow::MRI__init_var_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_arterial_all = new QMenu;
    MRI__menu_venous_all = new QMenu;
    MRI__menu_csf_all = new QMenu;
    MRI__menu_undefined_all = new QMenu;

    //VBox
    MRI__vbox_arterial_all = new QVBoxLayout;
    MRI__vbox_venous_all = new QVBoxLayout;
    MRI__vbox_csf_all = new QVBoxLayout;
    MRI__vbox_undefined_all = new QVBoxLayout;

    MRI__vbox_image_arterial_all = new QVBoxLayout;
    MRI__vbox_image_venous_all = new QVBoxLayout;
    MRI__vbox_image_csf_all = new QVBoxLayout;
    MRI__vbox_image_undefined_all = new QVBoxLayout;

    //HBox
    MRI__hbox_arterial_all = new QHBoxLayout;
    MRI__hbox_venous_all = new QHBoxLayout;
    MRI__hbox_csf_all = new QHBoxLayout;
    MRI__hbox_undefined_all = new QHBoxLayout;

    //Plot
    MRI__plot_arterial_all = new QCustomPlot;
    MRI__plot_venous_all = new QCustomPlot;
    MRI__plot_csf_all = new QCustomPlot;
    MRI__plot_undefined_all = new QCustomPlot;

    //Label
    MRI__label_arterial_heart_rate_all = new QLabel;
    MRI__label_arterial_min_all = new QLabel;
    MRI__label_arterial_max_all = new QLabel;
    MRI__label_arterial_mean_all = new QLabel;
    MRI__label_arterial_amplitude_all = new QLabel;
    MRI__label_arterial_stroke_volume_all = new QLabel;
    MRI__label_venous_heart_rate_all = new QLabel;
    MRI__label_venous_min_all = new QLabel;
    MRI__label_venous_max_all = new QLabel;
    MRI__label_venous_mean_all = new QLabel;
    MRI__label_venous_amplitude_all = new QLabel;
    MRI__label_venous_stroke_volume_all = new QLabel;
    MRI__label_csf_heart_rate_all = new QLabel;
    MRI__label_csf_min_all = new QLabel;
    MRI__label_csf_max_all = new QLabel;
    MRI__label_csf_mean_all = new QLabel;
    MRI__label_csf_amplitude_all = new QLabel;
    MRI__label_csf_stroke_volume_all = new QLabel;
    MRI__label_undefined_heart_rate_all = new QLabel;
    MRI__label_undefined_min_all = new QLabel;
    MRI__label_undefined_max_all = new QLabel;
    MRI__label_undefined_mean_all = new QLabel;
    MRI__label_undefined_amplitude_all = new QLabel;
    MRI__label_undefined_stroke_volume_all = new QLabel;

    MRI__label_image_arterial_all = new QLabel;
    MRI__label_image_venous_all = new QLabel;
    MRI__label_image_csf_all = new QLabel;
    MRI__label_image_undefined_all = new QLabel;

    //Vector
    MRI__vector_arteries_images_all = NULL;
    MRI__vector_arteries_all_x = NULL;
    MRI__vector_arteries_all_y = NULL;
    MRI__vector_veins_images_all = NULL;
    MRI__vector_veins_all_x = NULL;
    MRI__vector_veins_all_y = NULL;
    MRI__vector_csfs_images_all = NULL;
    MRI__vector_csfs_all_x = NULL;
    MRI__vector_csfs_all_y = NULL;
    MRI__vector_undefines_images_all = NULL;
    MRI__vector_undefines_all_x = NULL;
    MRI__vector_undefines_all_y = NULL;

    //Button
    MRI__button_arterial_all = new QPushButton;
    MRI__button_venous_all = new QPushButton;
    MRI__button_csf_all = new QPushButton;
    MRI__button_undefined_all = new QPushButton;
}

void MainWindow::MRI__init_win_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    MRI__menu_arterial_all->setTitle("Arteries");
    MRI__menu_venous_all->setTitle("Veins");
    MRI__menu_csf_all->setTitle("CSF");

    //Grid
    MRI__grid_all->addLayout(MRI__hbox_arterial_all, 0, 0, 1, 10);
    MRI__grid_all->addWidget(MRI__plot_arterial_all, 1, 0, 10, 10);
    MRI__grid_all->addLayout(MRI__vbox_arterial_all, 1, 10, 10, 1);
    MRI__grid_all->addLayout(MRI__vbox_image_arterial_all, 1, 11, 10, 1);
    MRI__grid_all->addLayout(MRI__hbox_venous_all, 11, 0, 1, 10);
    MRI__grid_all->addWidget(MRI__plot_venous_all, 12, 0, 10, 10);
    MRI__grid_all->addLayout(MRI__vbox_venous_all, 12, 10, 10, 1);
    MRI__grid_all->addLayout(MRI__vbox_image_venous_all, 12, 11, 10, 1);
    MRI__grid_all->addLayout(MRI__hbox_csf_all, 22, 0, 1, 10);
    MRI__grid_all->addWidget(MRI__plot_csf_all, 23, 0, 10, 10);
    MRI__grid_all->addLayout(MRI__vbox_csf_all, 23, 10, 10, 1);
    MRI__grid_all->addLayout(MRI__vbox_image_csf_all, 23, 11, 10, 1);
    MRI__grid_all->addLayout(MRI__hbox_undefined_all, 33, 0, 1, 10);
    MRI__grid_all->addWidget(MRI__plot_undefined_all, 34, 0, 10, 10);
    MRI__grid_all->addLayout(MRI__vbox_undefined_all, 34, 10, 10, 1);
    MRI__grid_all->addLayout(MRI__vbox_image_undefined_all, 34, 11, 10, 1);

    //VBox
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_heart_rate_all);
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_min_all);
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_max_all);
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_mean_all);
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_amplitude_all);
    MRI__vbox_arterial_all->addWidget(MRI__label_arterial_stroke_volume_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_heart_rate_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_min_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_max_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_mean_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_amplitude_all);
    MRI__vbox_venous_all->addWidget(MRI__label_venous_stroke_volume_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_heart_rate_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_min_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_max_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_mean_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_amplitude_all);
    MRI__vbox_csf_all->addWidget(MRI__label_csf_stroke_volume_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_heart_rate_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_min_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_max_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_mean_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_amplitude_all);
    MRI__vbox_undefined_all->addWidget(MRI__label_undefined_stroke_volume_all);

    MRI__vbox_image_arterial_all->addWidget(MRI__label_image_arterial_all);
    MRI__vbox_image_venous_all->addWidget(MRI__label_image_venous_all);
    MRI__vbox_image_csf_all->addWidget(MRI__label_image_csf_all);
    MRI__vbox_image_undefined_all->addWidget(MRI__label_image_undefined_all);

    //HBox
    MRI__hbox_arterial_all->addWidget(MRI__button_arterial_all);
    MRI__hbox_venous_all->addWidget(MRI__button_venous_all);
    MRI__hbox_csf_all->addWidget(MRI__button_csf_all);
    MRI__hbox_undefined_all->addWidget(MRI__button_undefined_all);

    //Button
    MRI__button_arterial_all->setText("Arteries");
    MRI__button_arterial_all->setMenu(MRI__menu_arterial_all);
    MRI__button_venous_all->setText("Veins");
    MRI__button_venous_all->setMenu(MRI__menu_venous_all);
    MRI__button_csf_all->setText("CSF");
    MRI__button_csf_all->setMenu(MRI__menu_csf_all);
    MRI__button_undefined_all->setText("Undefines");
    MRI__button_undefined_all->setMenu(MRI__menu_undefined_all);
}

void MainWindow::MRI__init_sig_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    connect(MRI__menu_arterial_all, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_plot_arterial_all()));
    connect(MRI__menu_venous_all, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_plot_venous_all()));
    connect(MRI__menu_csf_all, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_plot_csf_all()));
    connect(MRI__menu_undefined_all, SIGNAL(triggered(QAction*)), this, SLOT(MRI__do_plot_undefined_all()));
}

void MainWindow::MRI__init_css_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //
}

bool MainWindow::MRI__do_plot_all(QMenu *Menu, QCustomPlot *Plot,
                                  QVector<double> **VectorX, QVector<double> **VectorY,
                                  bool (MainWindow::*PrintFunction)(int), bool (MainWindow::*ImageFunction)(int),
                                  QString StatusText){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int NMenu = Menu->actions().size();

    unsigned int K = 0;
    unsigned int CurrentK = 0;

    double MinX, MaxX, MinY, MaxY;

    for (unsigned int i = 0; i < NMenu; i++){
        Plot->graph(i)->clearData();

        if (Menu->actions().at(i)->isChecked()){
            unsigned int NX = VectorX[i]->size();
            unsigned int NY = VectorY[i]->size();

            if ((NX == NY) && (NX != 0)){
                bool Res = plot(Plot, i, VectorX[i], VectorY[i]);
                if (!Res){
                    statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR2 - " + QString::number(i));
                    return Res;
                }

                if (K == 0){
                    MinX = min(VectorX[i], NULL, &Res);
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR3 - " + QString::number(i));
                        return Res;
                    }

                    MaxX = max(VectorX[i], NULL, &Res);
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR4 - " + QString::number(i));
                        return Res;
                    }

                    MinY = min(VectorY[i], NULL, &Res);
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR5 - " + QString::number(i));
                        return Res;
                    }

                    MaxY = max(VectorY[i], NULL, &Res);
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR6 - " + QString::number(i));
                        return Res;
                    }

                    CurrentK = i;
                    K++;
                }
                else{
                    MinX = min(MinX, min(VectorX[i], NULL, &Res));
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR7 - " + QString::number(i));
                        return Res;
                    }

                    MaxX = max(MaxX, max(VectorX[i], NULL, &Res));
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR8 - " + QString::number(i));
                        return Res;
                    }

                    MinY = min(MinY, min(VectorY[i], NULL, &Res));
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR9 - " + QString::number(i));
                        return Res;
                    }

                    MaxY = max(MaxY, max(VectorY[i], NULL, &Res));
                    if (!Res){
                        statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR10 - " + QString::number(i));
                        return Res;
                    }

                    K++;
                }
            }
            else{
                statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR1 - " + QString::number(i));
                return false;
            }
        }
    }

    if (K != 0){
        Plot->xAxis->setRange(MinX, MaxX);
        Plot->yAxis->setRange(MinY, MaxY);
        Plot->replot();
    }

    Menu->show();

    if (K == 1){
        bool Res = (this->*PrintFunction)(CurrentK);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR11");
            return Res;
        }

        Res = (this->*ImageFunction)(CurrentK);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR12");
            return Res;
        }
    }
    else{
        bool Res = (this->*PrintFunction)(-1);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR11");
            return Res;
        }

        Res = (this->*ImageFunction)(-1);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " plot error - ERR12");
            return Res;
        }
    }

    statusbar_show_message("MRI ALL - " + StatusText + " plotted");
    return true;
}

bool MainWindow::MRI__do_plot_arterial_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_plot_all(MRI__menu_arterial_all, MRI__plot_arterial_all,
                            MRI__vector_arteries_all_x, MRI__vector_arteries_all_y,
                            &MainWindow::MRI__do_print_arterial_all, &MainWindow::MRI__do_image_arterial_all,
                            "Arterial");
}

bool MainWindow::MRI__do_plot_venous_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_plot_all(MRI__menu_venous_all, MRI__plot_venous_all,
                            MRI__vector_veins_all_x, MRI__vector_veins_all_y,
                            &MainWindow::MRI__do_print_venous_all, &MainWindow::MRI__do_image_venous_all,
                            "Venous");
}

bool MainWindow::MRI__do_plot_csf_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_plot_all(MRI__menu_csf_all, MRI__plot_csf_all,
                            MRI__vector_csfs_all_x, MRI__vector_csfs_all_y,
                            &MainWindow::MRI__do_print_csf_all, &MainWindow::MRI__do_image_csf_all,
                            "CSF");
}

bool MainWindow::MRI__do_plot_undefined_all(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_plot_all(MRI__menu_undefined_all, MRI__plot_undefined_all,
                            MRI__vector_undefines_all_x, MRI__vector_undefines_all_y,
                            &MainWindow::MRI__do_print_undefined_all, &MainWindow::MRI__do_image_undefined_all,
                            "Undefined");
}

bool MainWindow::MRI__do_print_all(QLabel *LabelHeartRate, QLabel *LabelMin, QLabel *LabelMax, QLabel *LabelMean, QLabel *LabelAmplitude, QLabel *LabelStrokeVolume,
                                   QVector<double> *VectorX, QVector<double> *VectorY,
                                   QString StatusText,
                                   int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (k == -1){   //Clear data
        LabelHeartRate->clear();
        LabelMin->clear();
        LabelMax->clear();
        LabelMean->clear();
        LabelAmplitude->clear();
        LabelStrokeVolume->clear();

        statusbar_show_message("MRI ALL - " + StatusText + " data cleaned");
        return true;
    }

    //Print data
    unsigned int NX = VectorX->size();
    unsigned int NY = VectorY->size();

    if ((NX == NY) && (NX != 0)){
        bool Res;

        double MinX = min(VectorX, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR2");
            return Res;
        }

        double MaxX = max(VectorX, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR3");
            return Res;
        }

        double MinY = min(VectorY, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR4");
            return Res;
        }

        double MaxY = max(VectorY, NULL, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR5");
            return Res;
        }

        double MeanY = mean(VectorY, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR6");
            return Res;
        }

        double StrokeVolume = stroke_volume(VectorX, VectorY, &Res);
        if (!Res){
            statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR7");
            return Res;
        }

        double HeartRate = 60. / (MaxX - MinX);
        double Amplitude = MaxY - MinY;

        LabelHeartRate->setText("<b>Heart rate</b> = " + QString::number(HeartRate) + " bpm");
        LabelMin->setText("<b>Min flow</b> = " + QString::number(MinY) + " mm^3/s");
        LabelMax->setText("<b>Max flow</b> = " + QString::number(MaxY) + " mm^3/s");
        LabelMean->setText("<b>Mean flow</b> = " + QString::number(MeanY) + " mm^3/s");
        LabelAmplitude->setText("<b>Flow amplitude</b> = " + QString::number(Amplitude) + " mm^3/s");
        LabelStrokeVolume->setText("<b>Stroke volume</b> = " + QString::number(StrokeVolume) + " mm^3");

        statusbar_show_message("MRI ALL - " + StatusText + " data printed");
        return Res;
    }
    else{
        statusbar_show_warning("MRI ALL - " + StatusText + " print data error - ERR1");
        return false;
    }
}

bool MainWindow::MRI__do_print_arterial_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_print_all(MRI__label_arterial_heart_rate_all, MRI__label_arterial_min_all, MRI__label_arterial_max_all, MRI__label_arterial_mean_all, MRI__label_arterial_amplitude_all, MRI__label_arterial_stroke_volume_all,
                             MRI__vector_arteries_all_x[k], MRI__vector_arteries_all_y[k],
                             "Arterial",
                             k);
}

bool MainWindow::MRI__do_print_venous_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_print_all(MRI__label_venous_heart_rate_all, MRI__label_venous_min_all, MRI__label_venous_max_all, MRI__label_venous_mean_all, MRI__label_venous_amplitude_all, MRI__label_venous_stroke_volume_all,
                             MRI__vector_veins_all_x[k], MRI__vector_veins_all_y[k],
                             "Venous",
                             k);
}

bool MainWindow::MRI__do_print_csf_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_print_all(MRI__label_csf_heart_rate_all, MRI__label_csf_min_all, MRI__label_csf_max_all, MRI__label_csf_mean_all, MRI__label_csf_amplitude_all, MRI__label_csf_stroke_volume_all,
                             MRI__vector_csfs_all_x[k], MRI__vector_csfs_all_y[k],
                             "CSF",
                             k);
}

bool MainWindow::MRI__do_print_undefined_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_print_all(MRI__label_undefined_heart_rate_all, MRI__label_undefined_min_all, MRI__label_undefined_max_all, MRI__label_undefined_mean_all, MRI__label_undefined_amplitude_all, MRI__label_undefined_stroke_volume_all,
                             MRI__vector_undefines_all_x[k], MRI__vector_undefines_all_y[k],
                             "Undefined",
                             k);
}

bool MainWindow::MRI__do_image_all(QLabel *Label, QVector<QString> *Vector, QString StatusText, int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (k == -1){   //Clear image
        Label->clear();
        statusbar_show_message("MRI ALL - " + StatusText + " image cleaned");
        return true;
    }

    //Display image
    int nV = Vector->size();
    if (k >= nV){
        statusbar_show_warning("MRI ALL - " + StatusText + " image display error - ERR1");
        return false;
    }
    else{
        QPixmap Image = QPixmap(Vector->at(k));
        if (!Image.isNull()){
            Label->setPixmap(Image);

            statusbar_show_message("MRI ALL - " + StatusText + " image displayed");
            return true;
        }
        else{
            statusbar_show_warning("MRI ALL - " + StatusText + " image display error - ERR2");
            return false;
        }
    }
}

bool MainWindow::MRI__do_image_arterial_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_image_all(MRI__label_image_arterial_all, MRI__vector_arteries_images_all, "Arterial", k);
}

bool MainWindow::MRI__do_image_venous_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_image_all(MRI__label_image_venous_all, MRI__vector_veins_images_all, "Venous", k);
}

bool MainWindow::MRI__do_image_csf_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_image_all(MRI__label_image_csf_all, MRI__vector_csfs_images_all, "CSF", k);
}

bool MainWindow::MRI__do_image_undefined_all(int k){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    return MRI__do_image_all(MRI__label_image_undefined_all, MRI__vector_undefines_images_all, "Undefined", k);
}


