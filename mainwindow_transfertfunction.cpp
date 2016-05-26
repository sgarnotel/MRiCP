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

void MainWindow::TRANSFERTFUNCTION__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    TRANSFERTFUNCTION__vbox_arteriovenous_spinal = new QVBoxLayout;
    TRANSFERTFUNCTION__vbox_arteriovenouscsf_spinal = new QVBoxLayout;
    TRANSFERTFUNCTION__vbox_arteriovenous_intracranial = new QVBoxLayout;
    TRANSFERTFUNCTION__vbox_arteriovenouscsf_intracranial = new QVBoxLayout;
    TRANSFERTFUNCTION__vbox_icp_basal = new QVBoxLayout;
    TRANSFERTFUNCTION__vbox_icp_plateau = new QVBoxLayout;

    //HBox
    TRANSFERTFUNCTION__hbox_arteriovenous_spinal = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_arteriovenouscsf_spinal = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_arteriovenous_intracranial = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_arteriovenouscsf_intracranial = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_icp_basal = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_icp_plateau = new QHBoxLayout;
    TRANSFERTFUNCTION__hbox_transfert_function = new QHBoxLayout;

    //Plot
    TRANSFERTFUNCTION__plot_arteriovenous_spinal = new QCustomPlot;
    TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal = new QCustomPlot;
    TRANSFERTFUNCTION__plot_arteriovenous_intracranial = new QCustomPlot;
    TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial = new QCustomPlot;
    TRANSFERTFUNCTION__plot_icp_basal = new QCustomPlot;
    TRANSFERTFUNCTION__plot_icp_plateau = new QCustomPlot;
    TRANSFERTFUNCTION__plot_transfert_function = new QCustomPlot;

    //Label
    TRANSFERTFUNCTION__label_arteriovenous_spinal = new QLabel;
    TRANSFERTFUNCTION__label_arteriovenouscsf_spinal = new QLabel;
    TRANSFERTFUNCTION__label_arteriovenous_intracranial = new QLabel;
    TRANSFERTFUNCTION__label_arteriovenouscsf_intracranial = new QLabel;
    TRANSFERTFUNCTION__label_icp_basal = new QLabel;
    TRANSFERTFUNCTION__label_icp_plateau = new QLabel;
    TRANSFERTFUNCTION__label_transfert_function = new QLabel;

    //RadioButton
    TRANSFERTFUNCTION__radiobutton_group_volume = new QButtonGroup;
    TRANSFERTFUNCTION__radiobutton_group_pressure = new QButtonGroup;
    TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal = new QRadioButton;
    TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal = new QRadioButton;
    TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial = new QRadioButton;
    TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial = new QRadioButton;
    TRANSFERTFUNCTION__radiobutton_icp_basal = new QRadioButton;
    TRANSFERTFUNCTION__radiobutton_icp_plateau = new QRadioButton;

    //Button
    TRANSFERTFUNCTION__button_transfert_function = new QPushButton;

    //Vector
    TRANSFERTFUNCTION__vector_transfert_function_x = new QVector<double>;
    TRANSFERTFUNCTION__vector_transfert_function_y = new QVector<double>;
}

void MainWindow::TRANSFERTFUNCTION__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    TRANSFERTFUNCTION__vbox_arteriovenous_spinal->addWidget(TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal);
    TRANSFERTFUNCTION__vbox_arteriovenouscsf_spinal->addWidget(TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal);
    TRANSFERTFUNCTION__vbox_arteriovenous_intracranial->addWidget(TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial);
    TRANSFERTFUNCTION__vbox_arteriovenouscsf_intracranial->addWidget(TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial);
    TRANSFERTFUNCTION__vbox_icp_basal->addWidget(TRANSFERTFUNCTION__radiobutton_icp_basal);
    TRANSFERTFUNCTION__vbox_icp_plateau->addWidget(TRANSFERTFUNCTION__radiobutton_icp_plateau);

    //HBox
    TRANSFERTFUNCTION__hbox_arteriovenous_spinal->addWidget(TRANSFERTFUNCTION__label_arteriovenous_spinal);
    TRANSFERTFUNCTION__hbox_arteriovenouscsf_spinal->addWidget(TRANSFERTFUNCTION__label_arteriovenouscsf_spinal);
    TRANSFERTFUNCTION__hbox_arteriovenous_intracranial->addWidget(TRANSFERTFUNCTION__label_arteriovenous_intracranial);
    TRANSFERTFUNCTION__hbox_arteriovenouscsf_intracranial->addWidget(TRANSFERTFUNCTION__label_arteriovenouscsf_intracranial);
    TRANSFERTFUNCTION__hbox_icp_basal->addWidget(TRANSFERTFUNCTION__label_icp_basal);
    TRANSFERTFUNCTION__hbox_icp_plateau->addWidget(TRANSFERTFUNCTION__label_icp_plateau);
    TRANSFERTFUNCTION__hbox_transfert_function->addWidget(TRANSFERTFUNCTION__button_transfert_function);
    TRANSFERTFUNCTION__hbox_transfert_function->addWidget(TRANSFERTFUNCTION__label_transfert_function);

    //Plot
    TRANSFERTFUNCTION__plot_arteriovenous_spinal->addGraph();
    TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal->addGraph();
    TRANSFERTFUNCTION__plot_arteriovenous_intracranial->addGraph();
    TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial->addGraph();
    TRANSFERTFUNCTION__plot_icp_basal->addGraph();
    TRANSFERTFUNCTION__plot_icp_plateau->addGraph();
    TRANSFERTFUNCTION__plot_transfert_function->addGraph();

    //Label
    TRANSFERTFUNCTION__label_arteriovenous_spinal->setText("AV Spinal");
    TRANSFERTFUNCTION__label_arteriovenouscsf_spinal->setText("AVCSF Spinal");
    TRANSFERTFUNCTION__label_arteriovenous_intracranial->setText("AV Intracranial");
    TRANSFERTFUNCTION__label_arteriovenouscsf_intracranial->setText("AVCSF Intracranial");
    TRANSFERTFUNCTION__label_icp_basal->setText("ICP Basal");
    TRANSFERTFUNCTION__label_icp_plateau->setText("ICP Plateau");

    //RadioButton
    TRANSFERTFUNCTION__radiobutton_group_volume->addButton(TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal);
    TRANSFERTFUNCTION__radiobutton_group_volume->addButton(TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal);
    TRANSFERTFUNCTION__radiobutton_group_volume->addButton(TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial);
    TRANSFERTFUNCTION__radiobutton_group_volume->addButton(TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial);
    TRANSFERTFUNCTION__radiobutton_group_pressure->addButton(TRANSFERTFUNCTION__radiobutton_icp_basal);
    TRANSFERTFUNCTION__radiobutton_group_pressure->addButton(TRANSFERTFUNCTION__radiobutton_icp_plateau);
    TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal->setText("AV Spinal");
    TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal->setText("AVCSF Spinal");
    TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial->setText("AV Intracranial");
    TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial->setText("AVCSF Intracranial");
    TRANSFERTFUNCTION__radiobutton_icp_basal->setText("ICP Basal");
    TRANSFERTFUNCTION__radiobutton_icp_plateau->setText("ICP Plateau");

    //Button
    TRANSFERTFUNCTION__button_transfert_function->setText("TRANSFERTFUNCTION");
}

void MainWindow::TRANSFERTFUNCTION__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Button
    connect(TRANSFERTFUNCTION__button_transfert_function, SIGNAL(clicked(bool)), this, SLOT(TRANSFERTFUNCTION__do_transfert_function()));
}

void MainWindow::TRANSFERTFUNCTION__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    TRANSFERTFUNCTION__plot_arteriovenous_spinal->graph(0)->setPen(QPen(Qt::darkCyan));
    TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal->graph(0)->setPen(QPen(Qt::darkYellow));
    TRANSFERTFUNCTION__plot_arteriovenous_intracranial->graph(0)->setPen(QPen(Qt::darkCyan));
    TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial->graph(0)->setPen(QPen(Qt::darkYellow));
}

bool MainWindow::TRANSFERTFUNCTION__load(const QString DirName){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<int> Selection;

    QString TransfertFunctionDirName = DirName + "/TRANSFERTFUNCTION";

    Res = LoadTransfertFunction(TransfertFunctionDirName, &Selection);
    if (!Res){
        statusbar_show_warning("TRANSFERTFUNCTION - Load error - ERR1");
        return Res;
    }

    if (Selection.count() == 0) return true;

    int selected_volume = Selection.at(0);
    int selected_pressure = Selection.at(1);
    if (selected_volume == 0){
        TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal->setChecked(true);
    }
    else if (selected_volume == 1){
        TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal->setChecked(true);
    }
    else if (selected_volume == 2){
        TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial->setChecked(true);
    }
    else if (selected_volume == 3){
        TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial->setChecked(true);
    }
    if (selected_pressure == 0){
        TRANSFERTFUNCTION__radiobutton_icp_basal->setChecked(true);
    }
    else if (selected_pressure == 1){
        TRANSFERTFUNCTION__radiobutton_icp_plateau->setChecked(true);
    }
    Res = TRANSFERTFUNCTION__do_transfert_function();
    if (!Res){
        statusbar_show_warning("TRANSFERTFUNCTION - Load error - ERR2");
        return Res;
    }

    statusbar_show_message("TRANSFERTFUNCTION - Loaded");
    return Res;
}

bool MainWindow::TRANSFERTFUNCTION__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<int> Selection;
    int selected_volume = -1;
    int selected_pressure = -1;
    if (TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal->isChecked()){
        selected_volume = 0;
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal->isChecked()){
        selected_volume = 1;
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial->isChecked()){
        selected_volume = 2;
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial->isChecked()){
        selected_volume = 3;
    }
    if (TRANSFERTFUNCTION__radiobutton_icp_basal->isChecked()){
        selected_pressure = 0;
    }
    else if (TRANSFERTFUNCTION__radiobutton_icp_plateau->isChecked()){
        selected_pressure = 1;
    }
    Selection.append(selected_volume);
    Selection.append(selected_pressure);

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

    QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/TRANSFERTFUNCTION";
    if (!Res){
        statusbar_show_warning("TRANSFERTFUNCTION - Save error - ERR2");
        return Res;
    }

    Res = SaveTransfertFunction(DirName, Selection);
    if (!Res){
        statusbar_show_warning("TRANSFERTFUNCTION - Save error - ERR3");
        return Res;
    }

    statusbar_show_message("TRANSFERTFUNCTION - Transfert function saved");
    return Res;
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_arteriovenous_volume_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenous_volume_spinal_x->count();
    unsigned int ny = MRI__vector_arteriovenous_volume_spinal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_arteriovenous_spinal, 0, MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Arteriovenous spinal plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - Arteriovenous spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - Arteriovenous spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenouscsf_volume_spinal_x->count();
    unsigned int ny = MRI__vector_arteriovenouscsf_volume_spinal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal, 0, MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - ArteriovenousCSF spinal plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - ArteriovenousCSF spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - ArteriovenousCSF spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_arteriovenous_volume_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenous_volume_intracranial_x->count();
    unsigned int ny = MRI__vector_arteriovenous_volume_intracranial_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_arteriovenous_intracranial, 0, MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Arteriovenous intracranial plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - Arteriovenous intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - Arteriovenous intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_arteriovenouscsf_volume_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenouscsf_volume_intracranial_x->count();
    unsigned int ny = MRI__vector_arteriovenouscsf_volume_intracranial_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial, 0, MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - ArteriovenousCSF intracranial plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - ArteriovenousCSF intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - ArteriovenousCSF intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_icp_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_basal_x->count();
    unsigned int ny = ICP__vector_mean_basal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_icp_basal, 0, ICP__vector_mean_basal_x, ICP__vector_mean_basal_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - ICP basal plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - ICP basal plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - ICP basal plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_icp_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_plateau_x->count();
    unsigned int ny = ICP__vector_mean_plateau_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_icp_plateau, 0, ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - ICP plateau plot error - ERR2");
            return res;
        }

        statusbar_show_message("TRANSFERTFUNCTION - ICP plateau plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - ICP plateau plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_plot_transfert_function(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = TRANSFERTFUNCTION__vector_transfert_function_x->count();
    unsigned int ny = TRANSFERTFUNCTION__vector_transfert_function_x->count();

    if ((nx == ny) && (nx != 0)){
        bool res = plot(TRANSFERTFUNCTION__plot_transfert_function, 0, TRANSFERTFUNCTION__vector_transfert_function_x, TRANSFERTFUNCTION__vector_transfert_function_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Transfert function plot error - ERR2");
        }

        statusbar_show_message("TRANSFERTFUNCTION - Transfert function plotted");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - transfert function plot error - ERR1");
        return false;
    }
}

bool MainWindow::TRANSFERTFUNCTION__do_transfert_function(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    TRANSFERTFUNCTION__vector_transfert_function_x->clear();
    TRANSFERTFUNCTION__vector_transfert_function_y->clear();

    int selected_volume = -1;
    int selected_pressure = -1;

    QVector<double> *volume_x, *volume_y;
    QVector<double> *pressure_x, *pressure_y;

    if (TRANSFERTFUNCTION__radiobutton_arteriovenous_spinal->isChecked()){
        selected_volume = 0;
        volume_x = new QVector<double>(*MRI__vector_arteriovenous_volume_spinal_x);
        volume_y = new QVector<double>(*MRI__vector_arteriovenous_volume_spinal_y);
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_spinal->isChecked()){
        selected_volume = 1;
        volume_x = new QVector<double>(*MRI__vector_arteriovenouscsf_volume_spinal_x);
        volume_y = new QVector<double>(*MRI__vector_arteriovenouscsf_volume_spinal_y);
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenous_intracranial->isChecked()){
        selected_volume = 2;
        volume_x = new QVector<double>(*MRI__vector_arteriovenous_volume_intracranial_x);
        volume_y = new QVector<double>(*MRI__vector_arteriovenous_volume_intracranial_y);
    }
    else if (TRANSFERTFUNCTION__radiobutton_arteriovenouscsf_intracranial->isChecked()){
        selected_volume = 3;
        volume_x = new QVector<double>(*MRI__vector_arteriovenouscsf_volume_intracranial_x);
        volume_y = new QVector<double>(*MRI__vector_arteriovenouscsf_volume_intracranial_y);
    }

    if (TRANSFERTFUNCTION__radiobutton_icp_basal->isChecked()){
        selected_pressure = 0;
        pressure_x = new QVector<double>(*ICP__vector_mean_basal_x);
        pressure_y = new QVector<double>(*ICP__vector_mean_basal_y);
    }
    else if (TRANSFERTFUNCTION__radiobutton_icp_plateau->isChecked()){
        selected_pressure = 1;
        pressure_x = new QVector<double>(*ICP__vector_mean_plateau_x);
        pressure_y = new QVector<double>(*ICP__vector_mean_plateau_y);
    }

    if ((selected_volume != -1) && (selected_pressure != -1)){
        bool res;

        unsigned int npi = GetNpi(&res);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Transfert function error - ERR2");
            return res;
        }

        extend(volume_x, volume_y, npi, &res);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Transfert function error - ERR3");
            return res;
        }

        res = transfert_function(TRANSFERTFUNCTION__vector_transfert_function_x, TRANSFERTFUNCTION__vector_transfert_function_y, volume_x, volume_y, pressure_x, pressure_y);
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Transfert function error - ERR4");
            return res;
        }

        unsigned int nf = TRANSFERTFUNCTION__vector_transfert_function_y->count();

        double sample = 1. / (pressure_x->at(1) - pressure_x->at(0)) / pressure_x->count();
        for (unsigned int i = 0; i < nf; i++){
            TRANSFERTFUNCTION__vector_transfert_function_x->replace(i, i*sample);
        }

        res = TRANSFERTFUNCTION__do_plot_transfert_function();
        if (!res){
            statusbar_show_warning("TRANSFERTFUNCTION - Transfert function error - ERR5");
            return false;
        }

        statusbar_show_message("TRANSFERTFUNCTION - Transfert function done");
        return res;
    }
    else{
        statusbar_show_warning("TRANSFERTFUNCTION - Transfert function error - ERR1");
        return false;
    }
}


