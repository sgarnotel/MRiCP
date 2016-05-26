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

void MainWindow::COMPLIANCE__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    COMPLIANCE__vbox_arteriovenous_spinal = new QVBoxLayout;
    COMPLIANCE__vbox_arteriovenouscsf_spinal = new QVBoxLayout;
    COMPLIANCE__vbox_arteriovenous_intracranial = new QVBoxLayout;
    COMPLIANCE__vbox_arteriovenouscsf_intracranial = new QVBoxLayout;
    COMPLIANCE__vbox_icp_basal = new QVBoxLayout;
    COMPLIANCE__vbox_icp_plateau = new QVBoxLayout;

    //HBox
    COMPLIANCE__hbox_arteriovenous_spinal = new QHBoxLayout;
    COMPLIANCE__hbox_arteriovenouscsf_spinal = new QHBoxLayout;
    COMPLIANCE__hbox_arteriovenous_intracranial = new QHBoxLayout;
    COMPLIANCE__hbox_arteriovenouscsf_intracranial = new QHBoxLayout;
    COMPLIANCE__hbox_icp_basal = new QHBoxLayout;
    COMPLIANCE__hbox_icp_plateau = new QHBoxLayout;
    COMPLIANCE__hbox_compliance = new QHBoxLayout;

    //Plot
    COMPLIANCE__plot_arteriovenous_spinal = new QCustomPlot;
    COMPLIANCE__plot_arteriovenouscsf_spinal = new QCustomPlot;
    COMPLIANCE__plot_arteriovenous_intracranial = new QCustomPlot;
    COMPLIANCE__plot_arteriovenouscsf_intracranial = new QCustomPlot;
    COMPLIANCE__plot_icp_basal = new QCustomPlot;
    COMPLIANCE__plot_icp_plateau = new QCustomPlot;

    //Label
    COMPLIANCE__label_arteriovenous_spinal = new QLabel;
    COMPLIANCE__label_arteriovenouscsf_spinal = new QLabel;
    COMPLIANCE__label_arteriovenous_intracranial = new QLabel;
    COMPLIANCE__label_arteriovenouscsf_intracranial = new QLabel;
    COMPLIANCE__label_icp_basal = new QLabel;
    COMPLIANCE__label_icp_plateau = new QLabel;
    COMPLIANCE__label_compliance = new QLabel;

    //RadioButton
    COMPLIANCE__radiobutton_group_volume = new QButtonGroup;
    COMPLIANCE__radiobutton_group_pressure = new QButtonGroup;
    COMPLIANCE__radiobutton_arteriovenous_spinal = new QRadioButton;
    COMPLIANCE__radiobutton_arteriovenouscsf_spinal = new QRadioButton;
    COMPLIANCE__radiobutton_arteriovenous_intracranial = new QRadioButton;
    COMPLIANCE__radiobutton_arteriovenouscsf_intracranial = new QRadioButton;
    COMPLIANCE__radiobutton_icp_basal = new QRadioButton;
    COMPLIANCE__radiobutton_icp_plateau = new QRadioButton;

    //Button
    COMPLIANCE__button_compliance = new QPushButton;

    //Double
    COMPLIANCE__double_compliance = 0;
}

void MainWindow::COMPLIANCE__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    COMPLIANCE__vbox_arteriovenous_spinal->addWidget(COMPLIANCE__radiobutton_arteriovenous_spinal);
    COMPLIANCE__vbox_arteriovenouscsf_spinal->addWidget(COMPLIANCE__radiobutton_arteriovenouscsf_spinal);
    COMPLIANCE__vbox_arteriovenous_intracranial->addWidget(COMPLIANCE__radiobutton_arteriovenous_intracranial);
    COMPLIANCE__vbox_arteriovenouscsf_intracranial->addWidget(COMPLIANCE__radiobutton_arteriovenouscsf_intracranial);
    COMPLIANCE__vbox_icp_basal->addWidget(COMPLIANCE__radiobutton_icp_basal);
    COMPLIANCE__vbox_icp_plateau->addWidget(COMPLIANCE__radiobutton_icp_plateau);

    //HBox
    COMPLIANCE__hbox_arteriovenous_spinal->addWidget(COMPLIANCE__label_arteriovenous_spinal);
    COMPLIANCE__hbox_arteriovenouscsf_spinal->addWidget(COMPLIANCE__label_arteriovenouscsf_spinal);
    COMPLIANCE__hbox_arteriovenous_intracranial->addWidget(COMPLIANCE__label_arteriovenous_intracranial);
    COMPLIANCE__hbox_arteriovenouscsf_intracranial->addWidget(COMPLIANCE__label_arteriovenouscsf_intracranial);
    COMPLIANCE__hbox_icp_basal->addWidget(COMPLIANCE__label_icp_basal);
    COMPLIANCE__hbox_icp_plateau->addWidget(COMPLIANCE__label_icp_plateau);
    COMPLIANCE__hbox_compliance->addWidget(COMPLIANCE__button_compliance);
    COMPLIANCE__hbox_compliance->addWidget(COMPLIANCE__label_compliance);

    //Plot
    COMPLIANCE__plot_arteriovenous_spinal->addGraph();
    COMPLIANCE__plot_arteriovenouscsf_spinal->addGraph();
    COMPLIANCE__plot_arteriovenous_intracranial->addGraph();
    COMPLIANCE__plot_arteriovenouscsf_intracranial->addGraph();
    COMPLIANCE__plot_icp_basal->addGraph();
    COMPLIANCE__plot_icp_plateau->addGraph();

    //Label
    COMPLIANCE__label_arteriovenous_spinal->setText("AV Spinal");
    COMPLIANCE__label_arteriovenouscsf_spinal->setText("AVCSF Spinal");
    COMPLIANCE__label_arteriovenous_intracranial->setText("AV Intracranial");
    COMPLIANCE__label_arteriovenouscsf_intracranial->setText("AVCSF Intracranial");
    COMPLIANCE__label_icp_basal->setText("ICP Basal");
    COMPLIANCE__label_icp_plateau->setText("ICP Plateau");

    //RadioButton
    COMPLIANCE__radiobutton_group_volume->addButton(COMPLIANCE__radiobutton_arteriovenous_spinal);
    COMPLIANCE__radiobutton_group_volume->addButton(COMPLIANCE__radiobutton_arteriovenouscsf_spinal);
    COMPLIANCE__radiobutton_group_volume->addButton(COMPLIANCE__radiobutton_arteriovenous_intracranial);
    COMPLIANCE__radiobutton_group_volume->addButton(COMPLIANCE__radiobutton_arteriovenouscsf_intracranial);
    COMPLIANCE__radiobutton_group_pressure->addButton(COMPLIANCE__radiobutton_icp_basal);
    COMPLIANCE__radiobutton_group_pressure->addButton(COMPLIANCE__radiobutton_icp_plateau);
    COMPLIANCE__radiobutton_arteriovenous_spinal->setText("AV Spinal");
    COMPLIANCE__radiobutton_arteriovenouscsf_spinal->setText("AVCSF Spinal");
    COMPLIANCE__radiobutton_arteriovenous_intracranial->setText("AV Intracranial");
    COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->setText("AVCSF Intracranial");
    COMPLIANCE__radiobutton_icp_basal->setText("ICP Basal");
    COMPLIANCE__radiobutton_icp_plateau->setText("ICP Plateau");

    //Button
    COMPLIANCE__button_compliance->setText("Compliance");
}

void MainWindow::COMPLIANCE__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Button
    connect(COMPLIANCE__button_compliance, SIGNAL(clicked(bool)), this, SLOT(COMPLIANCE__do_compliance()));
}

void MainWindow::COMPLIANCE__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    COMPLIANCE__plot_arteriovenous_spinal->graph(0)->setPen(QPen(Qt::darkCyan));
    COMPLIANCE__plot_arteriovenouscsf_spinal->graph(0)->setPen(QPen(Qt::darkYellow));
    COMPLIANCE__plot_arteriovenous_intracranial->graph(0)->setPen(QPen(Qt::darkCyan));
    COMPLIANCE__plot_arteriovenouscsf_intracranial->graph(0)->setPen(QPen(Qt::darkYellow));
}

bool MainWindow::COMPLIANCE__load(const QString DirName){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<int> Selection;
    QVector<double> ComplianceResults;

    QString ComplianceDirName = DirName + "/COMPLIANCE";

    Res = LoadCompliance(ComplianceDirName, &Selection, &ComplianceResults);
    if (!Res){
        statusbar_show_warning("COMPLIANCE - Load error - ERR1");
        return Res;
    }

    if (Selection.count() == 0) return Res;

    int selected_volume = Selection.at(0);
    int selected_pressure = Selection.at(1);
    if (selected_volume == 0){
        COMPLIANCE__radiobutton_arteriovenous_spinal->setChecked(true);
    }
    else if (selected_volume == 1){
        COMPLIANCE__radiobutton_arteriovenouscsf_spinal->setChecked(true);
    }
    else if (selected_volume == 2){
        COMPLIANCE__radiobutton_arteriovenous_intracranial->setChecked(true);
    }
    else if (selected_volume == 3){
        COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->setChecked(true);
    }
    if (selected_pressure == 0){
        COMPLIANCE__radiobutton_icp_basal->setChecked(true);
    }
    else if (selected_pressure == 1){
        COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
    }
    Res = COMPLIANCE__do_compliance();
    if (!Res){
        statusbar_show_warning("COMPLIANCE - Load error - ERR2");
        return Res;
    }

    statusbar_show_message("COMPLIANCE - Loaded");
    return Res;
}

bool MainWindow::COMPLIANCE__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<int> Selection;
    int selected_volume = -1;
    int selected_pressure = -1;
    if (COMPLIANCE__radiobutton_arteriovenous_spinal->isChecked()){
        selected_volume = 0;
    }
    else if (COMPLIANCE__radiobutton_arteriovenouscsf_spinal->isChecked()){
        selected_volume = 1;
    }
    else if (COMPLIANCE__radiobutton_arteriovenous_intracranial->isChecked()){
        selected_volume = 2;
    }
    else if (COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->isChecked()){
        selected_volume = 3;
    }
    if (COMPLIANCE__radiobutton_icp_basal->isChecked()){
        selected_pressure = 0;
    }
    else if (COMPLIANCE__radiobutton_icp_plateau->isChecked()){
        selected_pressure = 1;
    }
    Selection.append(selected_volume);
    Selection.append(selected_pressure);

    QVector<double> ComplianceResults;
    {
        COMPLIANCE__radiobutton_arteriovenous_spinal->setChecked(true);
        COMPLIANCE__radiobutton_icp_basal->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_arteriovenouscsf_spinal->setChecked(true);
        COMPLIANCE__radiobutton_icp_basal->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_arteriovenous_intracranial->setChecked(true);
        COMPLIANCE__radiobutton_icp_basal->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->setChecked(true);
        COMPLIANCE__radiobutton_icp_basal->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            ComplianceResults.append(0.);
        }
        else{
            ComplianceResults.append(COMPLIANCE__double_compliance);
        }

        if (selected_volume == 0){
            COMPLIANCE__radiobutton_arteriovenous_spinal->setChecked(true);
        }
        else if (selected_volume == 1){
            COMPLIANCE__radiobutton_arteriovenouscsf_spinal->setChecked(true);
        }
        else if (selected_volume == 2){
            COMPLIANCE__radiobutton_arteriovenous_intracranial->setChecked(true);
        }
        else if (selected_volume == 3){
            COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->setChecked(true);
        }
        if (selected_pressure == 0){
            COMPLIANCE__radiobutton_icp_basal->setChecked(true);
        }
        else if (selected_pressure == 1){
            COMPLIANCE__radiobutton_icp_plateau->setChecked(true);
        }
        Res = COMPLIANCE__do_compliance();
        if (!Res){
            statusbar_show_warning("COMPLIANCE - Save error - ERR1");
            return Res;
        }
    }

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

    QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/COMPLIANCE";
    if (!Res){
        statusbar_show_warning("COMPLIANCE - Save error - ERR2");
        return Res;
    }

    Res = SaveCompliance(DirName, Selection, ComplianceResults);
    if (!Res){
        statusbar_show_warning("COMPLIANCE - Save error - ERR3");
        return Res;
    }

    statusbar_show_message("COMPLIANCE - Compliance saved");
    return Res;
}

bool MainWindow::COMPLIANCE__do_plot_arteriovenous_volume_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenous_volume_spinal_x->count();
    unsigned int ny = MRI__vector_arteriovenous_volume_spinal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_arteriovenous_spinal, 0, MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - Arteriovenous spinal plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - Arteriovenous spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - Arteriovenous spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_plot_arteriovenouscsf_volume_spinal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenouscsf_volume_spinal_x->count();
    unsigned int ny = MRI__vector_arteriovenouscsf_volume_spinal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_arteriovenouscsf_spinal, 0, MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - ArteriovenousCSF spinal plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - ArteriovenousCSF spinal plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - ArteriovenousCSF spinal plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_plot_arteriovenous_volume_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenous_volume_intracranial_x->count();
    unsigned int ny = MRI__vector_arteriovenous_volume_intracranial_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_arteriovenous_intracranial, 0, MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - Arteriovenous intracranial plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - Arteriovenous intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - Arteriovenous intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_plot_arteriovenouscsf_volume_intracranial(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = MRI__vector_arteriovenouscsf_volume_intracranial_x->count();
    unsigned int ny = MRI__vector_arteriovenouscsf_volume_intracranial_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_arteriovenouscsf_intracranial, 0, MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - ArteriovenousCSF intracranial plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - ArteriovenousCSF intracranial plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - ArteriovenousCSF intracranial plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_plot_icp_basal(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_basal_x->count();
    unsigned int ny = ICP__vector_mean_basal_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_icp_basal, 0, ICP__vector_mean_basal_x, ICP__vector_mean_basal_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - ICP basal plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - ICP basal plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - ICP basal plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_plot_icp_plateau(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int nx = ICP__vector_mean_plateau_x->count();
    unsigned int ny = ICP__vector_mean_plateau_y->count();

    if ((nx = ny) && (nx != 0)){
        bool res = plot(COMPLIANCE__plot_icp_plateau, 0, ICP__vector_mean_plateau_x, ICP__vector_mean_plateau_y);
        if (!res){
            statusbar_show_warning("COMPLIANCE - ICP plateau plot error - ERR2");
            return res;
        }

        statusbar_show_message("COMPLIANCE - ICP plateau plotted");
        return res;
    }
    else{
        statusbar_show_warning("COMPLIANCE - ICP plateau plot error - ERR1");
        return false;
    }
}

bool MainWindow::COMPLIANCE__do_compliance(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    int selected_volume = -1;
    int selected_pressure = -1;

    if (COMPLIANCE__radiobutton_arteriovenous_spinal->isChecked()){
        selected_volume = 0;
    }
    else if (COMPLIANCE__radiobutton_arteriovenouscsf_spinal->isChecked()){
        selected_volume = 1;
    }
    else if (COMPLIANCE__radiobutton_arteriovenous_intracranial->isChecked()){
        selected_volume = 2;
    }
    else if (COMPLIANCE__radiobutton_arteriovenouscsf_intracranial->isChecked()){
        selected_volume = 3;
    }

    if (COMPLIANCE__radiobutton_icp_basal->isChecked()){
        selected_pressure = 0;
    }
    else if (COMPLIANCE__radiobutton_icp_plateau->isChecked()){
        selected_pressure = 1;
    }

    if ((selected_volume != -1) && (selected_pressure != -1)){
        bool res;

        double volume_amplitude = 0.;
        double pressure_amplitude = 0.;

        double miny, maxy;
        if (selected_volume == 0){
            miny = min(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR2-1");
                return res;
            }
            maxy = max(MRI__vector_arteriovenous_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR3-1");
                return res;
            }
        }
        else if (selected_volume == 1){
            miny = min(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR2-2");
                return res;
            }
            maxy = max(MRI__vector_arteriovenouscsf_volume_spinal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR3-2");
                return res;
            }
        }
        else if (selected_volume == 2){
            miny = min(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR2-3");
                return res;
            }
            maxy = max(MRI__vector_arteriovenous_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR3-3");
                return res;
            }
        }
        else if (selected_volume == 3){
            miny = min(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR2-4");
                return res;
            }
            maxy = max(MRI__vector_arteriovenouscsf_volume_intracranial_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR3-4");
                return res;
            }
        }
        else{
            statusbar_show_warning("COMPLIANCE - Compliance error - ERR4");
            return false;
        }
        volume_amplitude = maxy - miny;

        if (selected_pressure == 0){
            miny = min(ICP__vector_mean_basal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR5-1");
                return res;
            }
            maxy = max(ICP__vector_mean_basal_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR6-1");
                return res;
            }
        }
        else if (selected_pressure == 1){
            miny = min(ICP__vector_mean_plateau_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR5-1");
                return res;
            }
            maxy = max(ICP__vector_mean_plateau_y, NULL, &res);
            if (!res){
                statusbar_show_warning("COMPLIANCE - Compliance error - ERR6-1");
                return res;
            }
        }
        else{
            statusbar_show_warning("COMPLIANCE - Compliance error - ERR7");
            return false;
        }
        pressure_amplitude = maxy - miny;

        if (pressure_amplitude == 0.){
            statusbar_show_warning("COMPLIANCE - Compliance error - ERR8");
            return false;
        }

        COMPLIANCE__double_compliance = volume_amplitude / pressure_amplitude;
        COMPLIANCE__label_compliance->setText("<b>Compliance</b> = " + QString::number(COMPLIANCE__double_compliance) + " mm^3/mmHg");

        statusbar_show_message("COMPLIANCE - Compliance done");
    }
    else{
        statusbar_show_warning("COMPLIANCE - Compliance error - ERR1");
    }

    return true;
}


