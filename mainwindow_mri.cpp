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

void MainWindow::MRI__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Tab
    MRI__tab = new QTabWidget;

    //Widget
    MRI__widget_tab_spinal = new QWidget;
    MRI__widget_tab_intracranial = new QWidget;
    MRI__widget_tab_spinal_intracranial = new QWidget;
    MRI__widget_tab_spectrum = new QWidget;
    MRI__widget_tab_all = new QWidget;

    //Grid
    MRI__grid_spinal = new QGridLayout;
    MRI__grid_intracranial = new QGridLayout;
    MRI__grid_spinal_intracranial = new QGridLayout;
    MRI__grid_spectrum = new QGridLayout;
    MRI__grid_all = new QGridLayout;


    MRI__init_var_spinal();
    MRI__init_var_intracranial();
    MRI__init_var_spinal_intracranial();
    MRI__init_var_spectrum();
    MRI__init_var_all();
}

void MainWindow::MRI__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Tab
    MRI__tab->addTab(MRI__widget_tab_spinal, "Spinal");
    MRI__tab->addTab(MRI__widget_tab_intracranial, "Intracranial");
    MRI__tab->addTab(MRI__widget_tab_spinal_intracranial, "Spinal/Intracranial");
    MRI__tab->addTab(MRI__widget_tab_spectrum, "Spectrum");
    MRI__tab->addTab(MRI__widget_tab_all, "All");

    //Widget
    MRI__widget_tab_spinal->setLayout(MRI__grid_spinal);
    MRI__widget_tab_intracranial->setLayout(MRI__grid_intracranial);
    MRI__widget_tab_spinal_intracranial->setLayout(MRI__grid_spinal_intracranial);
    MRI__widget_tab_spectrum->setLayout(MRI__grid_spectrum);
    MRI__widget_tab_all->setLayout(MRI__grid_all);


    MRI__init_win_spinal();
    MRI__init_win_intracranial();
    MRI__init_win_spinal_intracranial();
    MRI__init_win_spectrum();
    MRI__init_win_all();
}

void MainWindow::MRI__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__init_sig_spinal();
    MRI__init_sig_intracranial();
    MRI__init_sig_spinal_intracranial();
    MRI__init_sig_spectrum();
    MRI__init_sig_all();
}

void MainWindow::MRI__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    MRI__init_css_spinal();
    MRI__init_css_intracranial();
    MRI__init_css_spinal_intracranial();
    MRI__init_css_spectrum();
    MRI__init_css_all();
}

bool MainWindow::MRI__load(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //TODO verify after loading, and modifiy if necessary

    if (MRI__vector_arteries_images_all != NULL) delete[] MRI__vector_arteries_images_all; MRI__vector_arteries_images_all = NULL;
    if (MRI__vector_arteries_all_x != NULL) delete[] MRI__vector_arteries_all_x; MRI__vector_arteries_all_x = NULL;
    if (MRI__vector_arteries_all_y != NULL) delete[] MRI__vector_arteries_all_y; MRI__vector_arteries_all_y = NULL;
    if (MRI__vector_veins_images_all != NULL) delete[] MRI__vector_veins_images_all; MRI__vector_veins_images_all = NULL;
    if (MRI__vector_veins_all_x != NULL) delete[] MRI__vector_veins_all_x; MRI__vector_veins_all_x = NULL;
    if (MRI__vector_veins_all_y != NULL) delete[] MRI__vector_veins_all_y; MRI__vector_veins_all_y = NULL;
    if (MRI__vector_csfs_images_all != NULL) delete[] MRI__vector_csfs_images_all; MRI__vector_csfs_images_all = NULL;
    if (MRI__vector_csfs_all_x != NULL) delete[] MRI__vector_csfs_all_x; MRI__vector_csfs_all_x = NULL;
    if (MRI__vector_csfs_all_y != NULL) delete[] MRI__vector_csfs_all_y; MRI__vector_csfs_all_y = NULL;
    if (MRI__vector_undefines_images_all != NULL) delete[] MRI__vector_undefines_images_all; MRI__vector_undefines_images_all = NULL;
    if (MRI__vector_undefines_all_x != NULL) delete[] MRI__vector_undefines_all_x; MRI__vector_undefines_all_x = NULL;
    if (MRI__vector_undefines_all_y != NULL) delete[] MRI__vector_undefines_all_y; MRI__vector_undefines_all_y = NULL;

    MRI__vector_arterial_spinal_x->clear();
    MRI__vector_arterial_spinal_y->clear();
    MRI__vector_arterial_systole_spinal_x->clear();
    MRI__vector_venous_spinal_x->clear();
    MRI__vector_venous_spinal_y->clear();
    MRI__vector_venous_corrected_spinal_y->clear();
    MRI__vector_csf_spinal_x->clear();
    MRI__vector_csf_spinal_y->clear();
    MRI__vector_csf_corrected_spinal_y->clear();

    MRI__vector_arterial_intracranial_x->clear();
    MRI__vector_arterial_intracranial_y->clear();
    MRI__vector_arterial_systole_intracranial_x->clear();
    MRI__vector_venous_intracranial_x->clear();
    MRI__vector_venous_intracranial_y->clear();
    MRI__vector_venous_corrected_intracranial_y->clear();
    MRI__vector_csf_intracranial_x->clear();
    MRI__vector_csf_intracranial_y->clear();
    MRI__vector_csf_corrected_intracranial_y->clear();

    MRI__menu_arterial_all->clear();
    MRI__menu_venous_all->clear();
    MRI__menu_csf_all->clear();
    MRI__menu_undefined_all->clear();

    MRI__plot_arterial_all->clearGraphs();
    MRI__plot_csf_all->clearGraphs();
    MRI__plot_venous_all->clearGraphs();
    MRI__plot_undefined_all->clearGraphs();

    PATIENT__textedit_MRI->clear();

    //Load flows
    QStringList *names = new QStringList;
    QVector<int> *sizes = new QVector<int>;
    QString patient_name;
    QStringList *informations = new QStringList;
    QStringList *images = new QStringList;
    bool res;

    QVector<double> **flows = load_FLOW_files(this, names, sizes, &patient_name, informations, images, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR1");
        return res;
    }

    //Print informations
    PATIENT__textedit_MRI->append("Patient: " + patient_name);
    for (unsigned int i = 0; i < (unsigned)informations->count(); i++){
        PATIENT__textedit_MRI->append(informations->at(i));
    }

    //Get location (arterial spinal, ...)
    unsigned int n = sizes->count();
    if (n == 0){
        statusbar_show_warning("MRI - Load MRI error - ERR2");
        return false;
    }

    QStringList **location = new QStringList*[2];
    location[0] = new QStringList;
    location[1] = new QStringList;
    DialogFLOWLocation *dialog = new DialogFLOWLocation(names, location, this);
    if (dialog->result() == QDialog::Accepted){
        int result = dialog->exec();
        if (result == QDialog::Rejected){
            statusbar_show_warning("MRI - Load MRI error - ERR4");
            return false;
        }
    }
    else{
        statusbar_show_warning("MRI - Load MRI error - ERR3");
        return false;
    }

    //Count every location
    unsigned int n_arterial_spinal = 0;
    unsigned int n_venous_spinal = 0;
    unsigned int n_csf_spinal = 0;
    unsigned int n_arterial_intracranial = 0;
    unsigned int n_venous_intracranial = 0;
    unsigned int n_csf_intracranial = 0;
    unsigned int n_undefine = 0;

    for (unsigned int i = 0; i < n; i++){
        if (location[1]->at(i).contains("ArterialSpinal")){
            n_arterial_spinal++;
        }
        else if (location[1]->at(i).contains("VenousSpinal")){
            n_venous_spinal++;
        }
        else if (location[1]->at(i).contains("CsfSpinal")){
            n_csf_spinal++;
        }
        else if (location[1]->at(i).contains("ArterialIntracranial")){
            n_arterial_intracranial++;
        }
        else if (location[1]->at(i).contains("VenousIntracranial")){
            n_venous_intracranial++;
        }
        else if (location[1]->at(i).contains("CsfIntracranial")){
            n_csf_intracranial++;
        }
        else if (location[1]->at(i).contains("Undefine")){
            n_undefine++;
        }
    }

    //Create vector
    if (n_arterial_spinal != 0 || n_arterial_intracranial != 0){
        MRI__vector_arteries_images_all = new QVector<QString>[n_arterial_spinal + n_arterial_intracranial];
        MRI__vector_arteries_all_x = new QVector<double>*[n_arterial_spinal + n_arterial_intracranial];
        MRI__vector_arteries_all_y = new QVector<double>*[n_arterial_spinal + n_arterial_intracranial];
        for (unsigned int i = 0; i < n_arterial_spinal + n_arterial_intracranial; i++){
            MRI__vector_arteries_all_x[i] = new QVector<double>;
            MRI__vector_arteries_all_y[i] = new QVector<double>;
        }
    }
    if (n_venous_spinal != 0 || n_venous_intracranial != 0){
        MRI__vector_veins_images_all = new QVector<QString>[n_venous_spinal + n_venous_intracranial];
        MRI__vector_veins_all_x = new QVector<double>*[n_venous_spinal + n_venous_intracranial];
        MRI__vector_veins_all_y = new QVector<double>*[n_venous_spinal + n_venous_intracranial];
        for (unsigned int i = 0; i < n_venous_spinal + n_venous_intracranial; i++){
            MRI__vector_veins_all_x[i] = new QVector<double>;
            MRI__vector_veins_all_y[i] = new QVector<double>;
        }
    }
    if (n_csf_spinal != 0 || n_csf_intracranial != 0){
        MRI__vector_csfs_images_all = new QVector<QString>[n_csf_spinal + n_csf_intracranial];
        MRI__vector_csfs_all_x = new QVector<double>*[n_csf_spinal + n_csf_intracranial];
        MRI__vector_csfs_all_y = new QVector<double>*[n_csf_spinal + n_csf_intracranial];
        for (unsigned int i = 0; i < n_csf_spinal + n_csf_intracranial; i++){
            MRI__vector_csfs_all_x[i] = new QVector<double>;
            MRI__vector_csfs_all_y[i] = new QVector<double>;
        }
    }
    if (n_undefine != 0){
        MRI__vector_undefines_images_all = new QVector<QString>[n_undefine];
        MRI__vector_undefines_all_x = new QVector<double>*[n_undefine];
        MRI__vector_undefines_all_y = new QVector<double>*[n_undefine];
        for (unsigned int i = 0; i < n_undefine; i++){
            MRI__vector_undefines_all_x[i] = new QVector<double>;
            MRI__vector_undefines_all_y[i] = new QVector<double>;
        }
    }

    //Fill vector
    unsigned int k_arterial_spinal = 0;
    unsigned int k_venous_spinal = 0;
    unsigned int k_csf_spinal = 0;
    unsigned int k_arterial_intracranial = 0;
    unsigned int k_venous_intracranial = 0;
    unsigned int k_csf_intracranial = 0;
    unsigned int k_undefine = 0;
    for (unsigned int i = 0; i < n; i++){
        unsigned int current_n = sizes->at(i);
        if (location[1]->at(i).contains("ArterialSpinal")){
            if (k_arterial_spinal == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_arterial_spinal_x->append(flows[i]->at(j+current_n));
                    MRI__vector_arterial_spinal_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_arterial_spinal_y->replace(j, MRI__vector_arterial_spinal_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_arteries_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_arteries_all_x[k_arterial_spinal+k_arterial_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_arteries_all_y[k_arterial_spinal+k_arterial_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_arterial_all->addAction(action);
                MRI__plot_arterial_all->addGraph();
            }
            k_arterial_spinal++;
        }
        else if (location[1]->at(i).contains("VenousSpinal")){
            if (k_venous_spinal == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_venous_spinal_x->append(flows[i]->at(j+current_n));
                    MRI__vector_venous_spinal_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_venous_spinal_y->replace(j, MRI__vector_venous_spinal_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_veins_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_veins_all_x[k_venous_spinal+k_venous_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_veins_all_y[k_venous_spinal+k_venous_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_venous_all->addAction(action);
                MRI__plot_venous_all->addGraph();
            }
            k_venous_spinal++;
        }
        else if (location[1]->at(i).contains("CsfSpinal")){
            if (k_csf_spinal == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_csf_spinal_x->append(flows[i]->at(j+current_n));
                    MRI__vector_csf_spinal_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_csf_spinal_y->replace(j, MRI__vector_csf_spinal_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_csfs_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_csfs_all_x[k_csf_spinal+k_csf_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_csfs_all_y[k_csf_spinal+k_csf_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_csf_all->addAction(action);
                MRI__plot_csf_all->addGraph();
            }
            k_csf_spinal++;
        }

        else if (location[1]->at(i).contains("ArterialIntracranial")){
            if (k_arterial_intracranial == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_arterial_intracranial_x->append(flows[i]->at(j+current_n));
                    MRI__vector_arterial_intracranial_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_arterial_intracranial_y->replace(j, MRI__vector_arterial_intracranial_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_arteries_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_arteries_all_x[k_arterial_spinal+k_arterial_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_arteries_all_y[k_arterial_spinal+k_arterial_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_arterial_all->addAction(action);
                MRI__plot_arterial_all->addGraph();
            }
            k_arterial_intracranial++;
        }
        else if (location[1]->at(i).contains("VenousIntracranial")){
            if (k_venous_intracranial == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_venous_intracranial_x->append(flows[i]->at(j+current_n));
                    MRI__vector_venous_intracranial_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_venous_intracranial_y->replace(j, MRI__vector_venous_intracranial_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_veins_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_veins_all_x[k_venous_spinal+k_venous_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_veins_all_y[k_venous_spinal+k_venous_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_venous_all->addAction(action);
                MRI__plot_venous_all->addGraph();
            }
            k_venous_intracranial++;
        }
        else if (location[1]->at(i).contains("CsfIntracranial")){
            if (k_csf_intracranial == 0){
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_csf_intracranial_x->append(flows[i]->at(j+current_n));
                    MRI__vector_csf_intracranial_y->append(flows[i]->at(j));
                }
            }
            else{
                for (unsigned int j = 0; j < current_n; j++){
                    MRI__vector_csf_intracranial_y->replace(j, MRI__vector_csf_intracranial_y->at(j) + flows[i]->at(j));
                }
            }
            MRI__vector_csfs_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_csfs_all_x[k_csf_spinal+k_csf_intracranial]->append(flows[i]->at(j+current_n));
                MRI__vector_csfs_all_y[k_csf_spinal+k_csf_intracranial]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_csf_all->addAction(action);
                MRI__plot_csf_all->addGraph();
            }
            k_csf_intracranial++;
        }
        else if (location[1]->at(i).contains("Undefine")){
            MRI__vector_undefines_images_all->append(images->at(i));
            for (unsigned int j = 0; j < current_n; j++){
                MRI__vector_undefines_all_x[k_undefine]->append(flows[i]->at(j+current_n));
                MRI__vector_undefines_all_y[k_undefine]->append(flows[i]->at(j));
            }
            {
                QAction *action = new QAction(names->at(i), this);
                action->setCheckable(true);
                MRI__menu_undefined_all->addAction(action);
                MRI__plot_undefined_all->addGraph();
            }
            k_undefine++;
        }
    }

    delete[] flows;
    delete[] location;

    unsigned int npi = GetNpi(&res);
    extend(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR4");
        return res;
    }
    extend(MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR5");
        return res;
    }
    extend(MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR6");
        return res;
    }
    extend(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR7");
        return res;
    }
    extend(MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR8");
        return res;
    }
    extend(MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y, npi, &res);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR9");
        return res;
    }


    //TODO verify here if flow have a good shape

    res = MRI__do_plot_arterial_spinal();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR10");
        return res;
    }
    res = MRI__do_plot_venous_spinal();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR11");
        return res;
    }
    res = MRI__do_plot_csf_spinal();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR12");
        return res;
    }

    res = MRI__do_plot_arterial_intracranial();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR13");
        return res;
    }
    res = MRI__do_plot_venous_intracranial();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR14");
        return res;
    }
    res = MRI__do_plot_csf_intracranial();
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR15");
        return res;
    }

    double threshold;
    res = detect_systole_check(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, &threshold);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR16");
        return res;
    }
    MRI__doublespinbox_systole_threshold_spinal->setRange(0., 2.*threshold);
    MRI__doublespinbox_systole_threshold_spinal->setValue(threshold);

    res = detect_systole_check(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, &threshold);
    if (!res){
        statusbar_show_warning("MRI - Load MRI error - ERR17");
    }
    MRI__doublespinbox_systole_threshold_intracranial->setRange(0., 2.*threshold);
    MRI__doublespinbox_systole_threshold_intracranial->setValue(threshold);

    statusbar_show_message("MRI - Load MRI done");
    return res;
}

bool MainWindow::MRI__load(const QString DirName){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    QVector<double> SystoleThreshold;
    QVector<int> Quality;
    QVector<int> Move;
    QVector<double> ArterialResults;
    QVector<double> VenousResults;
    QVector<double> CSFResults;
    QVector<double> AVFlowResults;
    QVector<double> AVVolumeResults;
    QVector<double> AVCSFFlowResults;
    QVector<double> AVCSFVolumeResults;

    QString MRIDirName = DirName + "/MRI";

    //SPINAL
    {
        QString MRISpinalDirName = MRIDirName + "/spinal";

        Res = LoadMRI(MRISpinalDirName,
                      &SystoleThreshold, &Quality, &Move,
                      MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, &ArterialResults,
                      MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y, &VenousResults,
                      MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y, &CSFResults,
                      MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y, &AVFlowResults,
                      MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y, &AVVolumeResults,
                      MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y, &AVCSFFlowResults,
                      MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y, &AVCSFVolumeResults
                      );
        if (Res){
            Res = MRI__do_plot_arterial_spinal();
            if (Res){
                double threshold;
                Res = detect_systole_check(MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, &threshold);
                if (!Res){
                    statusbar_show_warning("MRI - Load MRI error - ERR3");
                }
                MRI__doublespinbox_systole_threshold_spinal->setRange(0., 2.*threshold);
                MRI__doublespinbox_systole_threshold_spinal->setValue(SystoleThreshold.at(0));
            }
            else{
                statusbar_show_warning("MRI - Load error - ERR2");
            }

            Res = MRI__do_plot_venous_spinal();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR4");
            }

            Res = MRI__do_plot_csf_spinal();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR5");
            }

            Res = MRI__do_arteriovenous_auto_spinal();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR6");
            }

            Res = MRI__do_arteriovenouscsf_auto_spinal();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR7");
            }
        }
        else{
            statusbar_show_warning("MRI - Load error - ERR1");
        }
    }

    //INTRACRANIAL
    {
        QString MRIIntracranialDirName = MRIDirName + "/intracranial";

        Res = LoadMRI(MRIIntracranialDirName,
                      &SystoleThreshold, &Quality, &Move,
                      MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, &ArterialResults,
                      MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y, &VenousResults,
                      MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y, &CSFResults,
                      MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y, &AVFlowResults,
                      MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y, &AVVolumeResults,
                      MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y, &AVCSFFlowResults,
                      MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y, &AVCSFVolumeResults
                      );
        if (Res){
            Res = MRI__do_plot_arterial_intracranial();
            if (Res){
                double threshold;
                Res = detect_systole_check(MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, &threshold);
                if (!Res){
                    statusbar_show_warning("MRI - Load MRI error - ERR10");
                }
                MRI__doublespinbox_systole_threshold_intracranial->setRange(0., 2.*threshold);
                MRI__doublespinbox_systole_threshold_intracranial->setValue(SystoleThreshold.at(0));
            }
            else{
                statusbar_show_warning("MRI - Load error - ERR9");
            }

            Res = MRI__do_plot_venous_intracranial();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR11");
            }

            Res = MRI__do_plot_csf_intracranial();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR12");
            }

            Res = MRI__do_arteriovenous_auto_intracranial();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR13");
            }

            Res = MRI__do_arteriovenouscsf_auto_intracranial();
            if (!Res){
                statusbar_show_warning("MRI - Load error - ERR14");
            }
        }
        else{
            statusbar_show_warning("MRI - Load error - ERR8");
        }
    }

    //ALL
    {
        if (MRI__vector_arteries_all_x != NULL){
            delete[] MRI__vector_arteries_all_x;
            MRI__vector_arteries_all_x = NULL;
        }
        if (MRI__vector_arteries_all_y != NULL){
            delete[] MRI__vector_arteries_all_y;
            MRI__vector_arteries_all_y = NULL;
        }
        if (MRI__vector_veins_all_x != NULL){
            delete[] MRI__vector_veins_all_x;
            MRI__vector_veins_all_x = NULL;
        }
        if (MRI__vector_veins_all_y != NULL){
            delete[] MRI__vector_veins_all_y;
            MRI__vector_veins_all_y = NULL;
        }
        if (MRI__vector_csfs_all_x != NULL){
            delete[] MRI__vector_csfs_all_x;
            MRI__vector_csfs_all_x = NULL;
        }
        if (MRI__vector_csfs_all_y != NULL){
            delete[] MRI__vector_csfs_all_y;
            MRI__vector_csfs_all_y = NULL;
        }
        if (MRI__vector_undefines_all_x != NULL){
            delete[] MRI__vector_undefines_all_x;
            MRI__vector_undefines_all_x = NULL;
        }
        if (MRI__vector_undefines_all_y != NULL){
            delete[] MRI__vector_undefines_all_y;
            MRI__vector_undefines_all_y = NULL;
        }

        MRI__plot_arterial_all->clearGraphs();
        MRI__plot_venous_all->clearGraphs();
        MRI__plot_csf_all->clearGraphs();
        MRI__plot_undefined_all->clearGraphs();

        MRI__menu_arterial_all->clear();
        MRI__menu_csf_all->clear();
        MRI__menu_venous_all->clear();
        MRI__menu_undefined_all->clear();

        QVector<QString> ArteriesImages;
        QVector<QString> ArteriesNames;
        QVector<QString> VeinsImages;
        QVector<QString> VeinsNames;
        QVector<QString> CSFsImages;
        QVector<QString> CSFsNames;
        QVector<QString> UndefinesImages;
        QVector<QString> UndefinesNames;

        QString MRIAllDirName = MRIDirName + "/all";

        Res = LoadMRI2_1(MRIAllDirName,
                         &ArteriesImages,
                         &ArteriesNames,
                         &VeinsImages,
                         &VeinsNames,
                         &CSFsImages,
                         &CSFsNames,
                         &UndefinesImages,
                         &UndefinesNames);
        if (!Res){
            statusbar_show_warning("MRI - Load error - ERR15");
        }

        unsigned int NArteries = ArteriesNames.count();
        unsigned int NVeins = VeinsNames.count();
        unsigned int NCSFs = CSFsNames.count();
        unsigned int NUndefines = UndefinesNames.count();

        if (NArteries != 0){
            MRI__vector_arteries_images_all = new QVector<QString>[NArteries];
            MRI__vector_arteries_all_x = new QVector<double>*[NArteries];
            MRI__vector_arteries_all_y = new QVector<double>*[NArteries];
            for (unsigned int i = 0; i < NArteries; i++){
                MRI__vector_arteries_images_all->append(MRIAllDirName + "/" + ArteriesImages.at(i));
                MRI__vector_arteries_all_x[i] = new QVector<double>;
                MRI__vector_arteries_all_y[i] = new QVector<double>;
                MRI__plot_arterial_all->addGraph();
                {
                    QAction *action = new QAction(ArteriesNames.at(i), this);
                    action->setCheckable(true);
                    MRI__menu_arterial_all->addAction(action);
                }
            }
        }
        if (NVeins != 0){
            MRI__vector_veins_images_all = new QVector<QString>[NVeins];
            MRI__vector_veins_all_x = new QVector<double>*[NVeins];
            MRI__vector_veins_all_y = new QVector<double>*[NVeins];
            for (unsigned int i = 0; i < NVeins; i++){
                MRI__vector_veins_images_all->append(MRIAllDirName + "/" + VeinsImages.at(i));
                MRI__vector_veins_all_x[i] = new QVector<double>;
                MRI__vector_veins_all_y[i] = new QVector<double>;
                MRI__plot_venous_all->addGraph();
                {
                    QAction *action = new QAction(VeinsNames.at(i), this);
                    action->setCheckable(true);
                    MRI__menu_venous_all->addAction(action);
                }
            }
        }
        if (NCSFs != 0){
            MRI__vector_csfs_images_all = new QVector<QString>[NCSFs];
            MRI__vector_csfs_all_x = new QVector<double>*[NCSFs];
            MRI__vector_csfs_all_y = new QVector<double>*[NCSFs];
            for (unsigned int i = 0; i < NCSFs; i++){
                MRI__vector_csfs_images_all->append(MRIAllDirName + "/" + CSFsImages.at(i));
                MRI__vector_csfs_all_x[i] = new QVector<double>;
                MRI__vector_csfs_all_y[i] = new QVector<double>;
                MRI__plot_csf_all->addGraph();
                {
                    QAction *action = new QAction(CSFsNames.at(i), this);
                    action->setCheckable(true);
                    MRI__menu_csf_all->addAction(action);
                }
            }
        }
        if (NUndefines != 0){
            MRI__vector_undefines_images_all = new QVector<QString>[NUndefines];
            MRI__vector_undefines_all_x = new QVector<double>*[NUndefines];
            MRI__vector_undefines_all_y = new QVector<double>*[NUndefines];
            for (unsigned int i = 0; i < NArteries; i++){
                MRI__vector_undefines_images_all->append(MRIAllDirName + "/" + UndefinesImages.at(i));
                MRI__vector_undefines_all_x[i] = new QVector<double>;
                MRI__vector_undefines_all_y[i] = new QVector<double>;
                MRI__plot_undefined_all->addGraph();
                {
                    QAction *action = new QAction(UndefinesNames.at(i), this);
                    action->setCheckable(true);
                    MRI__menu_undefined_all->addAction(action);
                }
            }
        }

        Res = LoadMRI2_2(MRIAllDirName,
                         MRI__vector_arteries_all_x, MRI__vector_arteries_all_y, ArteriesNames,
                         MRI__vector_veins_all_x, MRI__vector_veins_all_y, VeinsNames,
                         MRI__vector_csfs_all_x, MRI__vector_csfs_all_y, CSFsNames,
                         MRI__vector_undefines_all_x, MRI__vector_undefines_all_y, UndefinesNames
                         );
        if (!Res){
            statusbar_show_warning("MRI - Load error - ERR16");
        }
    }

    statusbar_show_message("MRI - Loaded");
    return true;
}

bool MainWindow::MRI__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    //SPINAL
    {
        //Trick to calculate flow and volume data if they have not been viewed
        if (MRI__combobox_flow_volume_arteriovenous_spinal->currentIndex() == 0){
            MRI__combobox_flow_volume_arteriovenous_spinal->setCurrentIndex(1);
            MRI__combobox_flow_volume_arteriovenous_spinal->setCurrentIndex(0);
        }
        else{
            MRI__combobox_flow_volume_arteriovenous_spinal->setCurrentIndex(0);
            MRI__combobox_flow_volume_arteriovenous_spinal->setCurrentIndex(1);
        }
        if (MRI__combobox_flow_volume_arteriovenouscsf_spinal->currentIndex() == 0){
            MRI__combobox_flow_volume_arteriovenouscsf_spinal->setCurrentIndex(1);
            MRI__combobox_flow_volume_arteriovenouscsf_spinal->setCurrentIndex(0);
        }
        else{
            MRI__combobox_flow_volume_arteriovenouscsf_spinal->setCurrentIndex(0);
            MRI__combobox_flow_volume_arteriovenouscsf_spinal->setCurrentIndex(1);
        }
        //End

        QVector<double> SystoleThreshold;
        SystoleThreshold.append(MRI__doublespinbox_systole_threshold_spinal->value());

        QVector<int> Quality;
        Quality.append(MRI__spinbox_arterial_quality_spinal->value());
        Quality.append(MRI__spinbox_venous_quality_spinal->value());
        Quality.append(MRI__spinbox_csf_quality_spinal->value());

        QVector<int> Move;
        Move.append(MRI__int_arterial_move_spinal);
        Move.append(MRI__int_venous_move_spinal);
        Move.append(MRI__int_csf_move_spinal);

        QVector<double> ArterialResults;
        ArterialResults.append(MRI__double_arterial_heart_rate_spinal);
        ArterialResults.append(MRI__double_arterial_min_spinal);
        ArterialResults.append(MRI__double_arterial_max_spinal);
        ArterialResults.append(MRI__double_arterial_mean_spinal);
        ArterialResults.append(MRI__double_arterial_amplitude_spinal);
        ArterialResults.append(MRI__double_arterial_stroke_volume_spinal);

        QVector<double> VenousResults;
        VenousResults.append(MRI__double_venous_min_spinal);
        VenousResults.append(MRI__double_venous_max_spinal);
        VenousResults.append(MRI__double_venous_mean_spinal);
        VenousResults.append(MRI__double_venous_amplitude_spinal);
        VenousResults.append(MRI__double_venous_stroke_volume_spinal);
        VenousResults.append(MRI__double_venous_corrected_min_spinal);
        VenousResults.append(MRI__double_venous_corrected_max_spinal);
        VenousResults.append(MRI__double_venous_corrected_mean_spinal);
        VenousResults.append(MRI__double_venous_corrected_amplitude_spinal);
        VenousResults.append(MRI__double_venous_corrected_stroke_volume_spinal);

        QVector<double> CSFResults;
        CSFResults.append(MRI__double_csf_heart_rate_spinal);
        CSFResults.append(MRI__double_csf_min_spinal);
        CSFResults.append(MRI__double_csf_max_spinal);
        CSFResults.append(MRI__double_csf_mean_spinal);
        CSFResults.append(MRI__double_csf_amplitude_spinal);
        CSFResults.append(MRI__double_csf_stroke_volume_spinal);
        CSFResults.append(MRI__double_csf_corrected_min_spinal);
        CSFResults.append(MRI__double_csf_corrected_max_spinal);
        CSFResults.append(MRI__double_csf_corrected_mean_spinal);
        CSFResults.append(MRI__double_csf_corrected_amplitude_spinal);
        CSFResults.append(MRI__double_csf_corrected_stroke_volume_spinal);

        QVector<double> AVFlowResults;
        AVFlowResults.append(MRI__double_arteriovenous_flow_min_spinal);
        AVFlowResults.append(MRI__double_arteriovenous_flow_max_spinal);
        AVFlowResults.append(MRI__double_arteriovenous_flow_mean_spinal);
        AVFlowResults.append(MRI__double_arteriovenous_flow_amplitude_spinal);
        AVFlowResults.append(MRI__double_arteriovenous_flow_stroke_volume_spinal);

        QVector<double>AVVolumeResults;
        AVVolumeResults.append(MRI__double_arteriovenous_volume_min_spinal);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_max_spinal);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_mean_spinal);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_amplitude_spinal);

        QVector<double> AVCSFFlowResults;
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_min_spinal);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_max_spinal);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_mean_spinal);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_amplitude_spinal);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_stroke_volume_spinal);

        QVector<double> AVCSFVolumeResults;
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_min_spinal);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_max_spinal);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_mean_spinal);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_amplitude_spinal);

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

            DirName.append("/MRI");
            ResultsDir.setPath(DirName);
            if (!ResultsDir.exists()){
                Res = ResultsDir.mkdir(DirName);
                if (!Res)return false;
            }
        }

        QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/MRI/spinal/";
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR1");
            return Res;
        }

        Res = SaveMRI(DirName,
                      SystoleThreshold, Quality, Move,
                      MRI__vector_arterial_spinal_x, MRI__vector_arterial_spinal_y, ArterialResults,
                      MRI__vector_venous_spinal_x, MRI__vector_venous_spinal_y, VenousResults,
                      MRI__vector_csf_spinal_x, MRI__vector_csf_spinal_y, CSFResults,
                      MRI__vector_arteriovenous_flow_spinal_x, MRI__vector_arteriovenous_flow_spinal_y, AVFlowResults,
                      MRI__vector_arteriovenous_volume_spinal_x, MRI__vector_arteriovenous_volume_spinal_y, AVVolumeResults,
                      MRI__vector_arteriovenouscsf_flow_spinal_x, MRI__vector_arteriovenouscsf_flow_spinal_y, AVCSFFlowResults,
                      MRI__vector_arteriovenouscsf_volume_spinal_x, MRI__vector_arteriovenouscsf_volume_spinal_y, AVCSFVolumeResults
                      );
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR2");
        }
    }

    //INTRACRANIAL
    {
        //Trick to calculate flow and volume data if they do not have been viewed
        if (MRI__combobox_flow_volume_arteriovenous_intracranial->currentIndex() == 0){
            MRI__combobox_flow_volume_arteriovenous_intracranial->setCurrentIndex(1);
            MRI__combobox_flow_volume_arteriovenous_intracranial->setCurrentIndex(0);
        }
        else{
            MRI__combobox_flow_volume_arteriovenous_intracranial->setCurrentIndex(0);
            MRI__combobox_flow_volume_arteriovenous_intracranial->setCurrentIndex(1);
        }
        if (MRI__combobox_flow_volume_arteriovenouscsf_intracranial->currentIndex() == 0){
            MRI__combobox_flow_volume_arteriovenouscsf_intracranial->setCurrentIndex(1);
            MRI__combobox_flow_volume_arteriovenouscsf_intracranial->setCurrentIndex(0);
        }
        else{
            MRI__combobox_flow_volume_arteriovenouscsf_intracranial->setCurrentIndex(0);
            MRI__combobox_flow_volume_arteriovenouscsf_intracranial->setCurrentIndex(1);
        }
        //End

        QVector<double> SystoleThreshold;
        SystoleThreshold.append(MRI__doublespinbox_systole_threshold_intracranial->value());

        QVector<int> Quality;
        Quality.append(MRI__spinbox_arterial_quality_intracranial->value());
        Quality.append(MRI__spinbox_venous_quality_intracranial->value());
        Quality.append(MRI__spinbox_csf_quality_intracranial->value());

        QVector<int> Move;
        Move.append(MRI__int_arterial_move_intracranial);
        Move.append(MRI__int_venous_move_intracranial);
        Move.append(MRI__int_csf_move_intracranial);

        QVector<double> ArterialResults;
        ArterialResults.append(MRI__double_arterial_heart_rate_intracranial);
        ArterialResults.append(MRI__double_arterial_min_intracranial);
        ArterialResults.append(MRI__double_arterial_max_intracranial);
        ArterialResults.append(MRI__double_arterial_mean_intracranial);
        ArterialResults.append(MRI__double_arterial_amplitude_intracranial);
        ArterialResults.append(MRI__double_arterial_stroke_volume_intracranial);

        QVector<double> VenousResults;
        VenousResults.append(MRI__double_venous_min_intracranial);
        VenousResults.append(MRI__double_venous_max_intracranial);
        VenousResults.append(MRI__double_venous_mean_intracranial);
        VenousResults.append(MRI__double_venous_amplitude_intracranial);
        VenousResults.append(MRI__double_venous_stroke_volume_intracranial);
        VenousResults.append(MRI__double_venous_corrected_min_intracranial);
        VenousResults.append(MRI__double_venous_corrected_max_intracranial);
        VenousResults.append(MRI__double_venous_corrected_mean_intracranial);
        VenousResults.append(MRI__double_venous_corrected_amplitude_intracranial);
        VenousResults.append(MRI__double_venous_corrected_stroke_volume_intracranial);

        QVector<double> CSFResults;
        CSFResults.append(MRI__double_csf_heart_rate_intracranial);
        CSFResults.append(MRI__double_csf_min_intracranial);
        CSFResults.append(MRI__double_csf_max_intracranial);
        CSFResults.append(MRI__double_csf_mean_intracranial);
        CSFResults.append(MRI__double_csf_amplitude_intracranial);
        CSFResults.append(MRI__double_csf_stroke_volume_intracranial);
        CSFResults.append(MRI__double_csf_corrected_min_intracranial);
        CSFResults.append(MRI__double_csf_corrected_max_intracranial);
        CSFResults.append(MRI__double_csf_corrected_mean_intracranial);
        CSFResults.append(MRI__double_csf_corrected_amplitude_intracranial);
        CSFResults.append(MRI__double_csf_corrected_stroke_volume_intracranial);

        QVector<double> AVFlowResults;
        AVFlowResults.append(MRI__double_arteriovenous_flow_min_intracranial);
        AVFlowResults.append(MRI__double_arteriovenous_flow_max_intracranial);
        AVFlowResults.append(MRI__double_arteriovenous_flow_mean_intracranial);
        AVFlowResults.append(MRI__double_arteriovenous_flow_amplitude_intracranial);
        AVFlowResults.append(MRI__double_arteriovenous_flow_stroke_volume_intracranial);

        QVector<double>AVVolumeResults;
        AVVolumeResults.append(MRI__double_arteriovenous_volume_min_intracranial);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_max_intracranial);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_mean_intracranial);
        AVVolumeResults.append(MRI__double_arteriovenous_volume_amplitude_intracranial);

        QVector<double> AVCSFFlowResults;
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_min_intracranial);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_max_intracranial);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_mean_intracranial);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_amplitude_intracranial);
        AVCSFFlowResults.append(MRI__double_arteriovenouscsf_flow_stroke_volume_intracranial);

        QVector<double> AVCSFVolumeResults;
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_min_intracranial);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_max_intracranial);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_mean_intracranial);
        AVCSFVolumeResults.append(MRI__double_arteriovenouscsf_volume_amplitude_intracranial);

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

            DirName.append("/MRI");
            ResultsDir.setPath(DirName);
            if (!ResultsDir.exists()){
                Res = ResultsDir.mkdir(DirName);
                if (!Res)return false;
            }
        }

        QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/MRI/intracranial/";
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR3");
            return Res;
        }

        Res = SaveMRI(DirName,
                      SystoleThreshold, Quality, Move,
                      MRI__vector_arterial_intracranial_x, MRI__vector_arterial_intracranial_y, ArterialResults,
                      MRI__vector_venous_intracranial_x, MRI__vector_venous_intracranial_y, VenousResults,
                      MRI__vector_csf_intracranial_x, MRI__vector_csf_intracranial_y, CSFResults,
                      MRI__vector_arteriovenous_flow_intracranial_x, MRI__vector_arteriovenous_flow_intracranial_y, AVFlowResults,
                      MRI__vector_arteriovenous_volume_intracranial_x, MRI__vector_arteriovenous_volume_intracranial_y, AVVolumeResults,
                      MRI__vector_arteriovenouscsf_flow_intracranial_x, MRI__vector_arteriovenouscsf_flow_intracranial_y, AVCSFFlowResults,
                      MRI__vector_arteriovenouscsf_volume_intracranial_x, MRI__vector_arteriovenouscsf_volume_intracranial_y, AVCSFVolumeResults
                      );
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR4");
        }
    }

    //ALL
    {
        unsigned int NArteries = MRI__menu_arterial_all->actions().count();
        unsigned int NVeins = MRI__menu_venous_all->actions().count();
        unsigned int NCSFs = MRI__menu_csf_all->actions().count();
        unsigned int NUndefines = MRI__menu_undefined_all->actions().count();

        QVector<QString> ArteriesNames;
        QVector<QString> VeinsNames;
        QVector<QString> CSFsNames;
        QVector<QString> UndefinesNames;

        for (unsigned int i = 0; i < NArteries; i++){
            ArteriesNames.append(MRI__menu_arterial_all->actions().at(i)->text());
        }
        for (unsigned int i = 0; i < NVeins; i++){
            VeinsNames.append(MRI__menu_venous_all->actions().at(i)->text());
        }
        for (unsigned int i = 0; i < NCSFs; i++){
            CSFsNames.append(MRI__menu_csf_all->actions().at(i)->text());
        }
        for (unsigned int i = 0; i < NUndefines; i++){
            UndefinesNames.append(MRI__menu_undefined_all->actions().at(i)->text());
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

            DirName.append("/MRI");
            ResultsDir.setPath(DirName);
            if (!ResultsDir.exists()){
                Res = ResultsDir.mkdir(DirName);
                if (!Res)return false;
            }
        }

        QString DirName = GetResultsDir(&Res) + "/" + PatientName + "/MRI/all/";
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR5");
            return Res;
        }

        Res = SaveMRI2(DirName,
                       MRI__vector_arteries_images_all,
                       MRI__vector_arteries_all_x, MRI__vector_arteries_all_y, ArteriesNames,
                       MRI__vector_veins_images_all,
                       MRI__vector_veins_all_x, MRI__vector_veins_all_y, VeinsNames,
                       MRI__vector_csfs_images_all,
                       MRI__vector_csfs_all_x, MRI__vector_csfs_all_y, CSFsNames,
                       MRI__vector_undefines_images_all,
                       MRI__vector_undefines_all_x, MRI__vector_undefines_all_y, UndefinesNames
                       );
        if (!Res){
            statusbar_show_warning("MRI - Save error - ERR6");
            return Res;
        }
    }

    statusbar_show_message("MRI - Saved");
    return true;
}


