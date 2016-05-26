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

void MainWindow::init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    menu_file = menuBar()->addMenu("File");
    menu_modules = menuBar()->addMenu("Modules");
    menu_actions = menuBar()->addMenu("Actions");
    menu_edit = menuBar()->addMenu("Edit");
    menu_help = menuBar()->addMenu("Help");

    menu_file_load = new QMenu;

    //Action
    action_file_load_PATIENT = new QAction(this);
    action_file_load_MRI = new QAction(this);
    action_file_load_ICP = new QAction(this);
    action_file_load_EPI = new QAction(this);
    action_file_save_PATIENT = new QAction(this);
    action_file_quit = new QAction(this);

    action_module_PATIENT = new QAction(this);
    action_module_MRI = new QAction(this);
    action_module_ICP = new QAction(this);
    action_module_EPI = new QAction(this);
    action_module_COMPLIANCE = new QAction(this);
    action_module_TRANSFERTFUNCTION = new QAction(this);
    action_module_STATISTICS = new QAction(this);

    action_action_import_Flow_eXplorer = new QAction(this);
    action_action_export_data = new QAction(this);
    action_action_export_report = new QAction(this);

    action_edit_settings = new QAction(this);

    action_help_user = new QAction(this);
    action_help_about_Qt = new QAction(this);
    action_help_about_MRiCP = new QAction(this);

    //Toolbar
    toolbar_file = new QToolBar(this);
    toolbar_module = new QToolBar(this);
    toolbar_edit = new QToolBar(this);
    toolbar_help = new QToolBar(this);

    //Statusbar
    statusbar = statusBar();

    //ScrollArea
    scrollarea_PATIENT = new QScrollArea;
    scrollarea_MRI = new QScrollArea;
    scrollarea_ICP = new QScrollArea;
    scrollarea_EPI = new QScrollArea;
    scrollarea_COMPLIANCE = new QScrollArea;
    scrollarea_TRANSFERTFUNCTION = new QScrollArea;
    scrollarea_STATISTICS = new QScrollArea;

    //Widget
    stacked_widget = new QStackedWidget;

    central_widget_PATIENT = new QWidget;
    central_widget_MRI = new QWidget;
    central_widget_ICP = new QWidget;
    central_widget_EPI = new QWidget;
    central_widget_COMPLIANCE = new QWidget;
    central_widget_TRANSFERTFUNCTION = new QWidget;
    central_widget_STATISTICS = new QWidget;

    scrollwidget_PATIENT = new QWidget;
    scrollwidget_MRI = new QWidget;
    scrollwidget_ICP = new QWidget;
    scrollwidget_EPI = new QWidget;
    scrollwidget_COMPLIANCE = new QWidget;
    scrollwidget_TRANSFERTFUNCTION = new QWidget;
    scrollwidget_STATISTICS = new QWidget;

    //Grid
    grid_PATIENT = new QGridLayout;
    grid_MRI = new QGridLayout;
    grid_ICP = new QGridLayout;
    grid_EPI = new QGridLayout;
    grid_COMPLIANCE = new QGridLayout;
    grid_TRANSFERTFUNCTION = new QGridLayout;
    grid_STATISTICS = new QGridLayout;

    //VBox
    vbox_PATIENT = new QVBoxLayout;
    vbox_MRI = new QVBoxLayout;
    vbox_ICP = new QVBoxLayout;
    vbox_EPI = new QVBoxLayout;
    vbox_COMPLIANCE = new QVBoxLayout;
    vbox_TRANSFERTFUNCTION = new QVBoxLayout;
    vbox_STATISTICS = new QVBoxLayout;
}

void MainWindow::init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Menu
    menu_file->addAction(action_file_load_PATIENT);
    menu_file->addAction(action_file_save_PATIENT);
    menu_file->addSeparator();
    menu_file->addMenu(menu_file_load);
    menu_file->addSeparator();
    menu_file->addAction(action_file_quit);

    menu_modules->addAction(action_module_PATIENT);
    menu_modules->addAction(action_module_MRI);
    menu_modules->addAction(action_module_ICP);
    menu_modules->addAction(action_module_EPI);
    menu_modules->addAction(action_module_COMPLIANCE);
    menu_modules->addAction(action_module_TRANSFERTFUNCTION);
    menu_modules->addAction(action_module_STATISTICS);

    menu_actions->addAction(action_action_import_Flow_eXplorer);
    menu_actions->addSeparator();
    menu_actions->addAction(action_action_export_data);
    menu_actions->addAction(action_action_export_report);

    menu_edit->addAction(action_edit_settings);

    menu_help->addAction(action_help_user);
    menu_help->addSeparator();
    menu_help->addAction(action_help_about_Qt);
    menu_help->addAction(action_help_about_MRiCP);

    menu_file_load->setTitle("Load");
    menu_file_load->setIcon(QIcon("img/dir.png"));
    menu_file_load->addAction(action_file_load_MRI);
    menu_file_load->addAction(action_file_load_ICP);
    menu_file_load->addAction(action_file_load_EPI);

    //Action
    action_file_load_PATIENT->setText("Load Patient");
    action_file_load_PATIENT->setIcon(QIcon("img/dir.png"));
    action_file_load_MRI->setText("Load MRI");
    action_file_load_MRI->setIcon(QIcon("img/dir.png"));
    action_file_load_ICP->setText("Load ICP");
    action_file_load_ICP->setIcon(QIcon("img/dir.png"));
    action_file_load_EPI->setText("Load EPI");
    action_file_load_EPI->setIcon(QIcon("img/dir.png"));
    action_file_load_EPI->setDisabled(true);
    action_file_save_PATIENT->setText("Save Patient");
    action_file_save_PATIENT->setIcon(QIcon("img/save.png"));
    action_file_quit->setText("Quit");
    action_file_quit->setIcon(QIcon("img/quit.png"));

    action_module_PATIENT->setText("Patient");
    action_module_MRI->setText("MRI");
    action_module_ICP->setText("ICP");
    action_module_EPI->setText("EPI");
    action_module_EPI->setDisabled(true);
    action_module_COMPLIANCE->setText("Compliance");
    action_module_TRANSFERTFUNCTION->setText("Transfert Function");
    action_module_STATISTICS->setText("Statistics");

    action_action_import_Flow_eXplorer->setText("Import from Flow eXplorer");
    action_action_export_data->setText("Export data");
    action_action_export_report->setText("Export report");

    action_edit_settings->setText("Settings");
    action_edit_settings->setIcon(QIcon("img/settings.png"));

    action_help_user->setText("User help");
    action_help_user->setIcon(QIcon("img/user.png"));
    action_help_about_Qt->setText("About Qt");
    action_help_about_Qt->setIcon(QIcon("img/qt.png"));
    action_help_about_MRiCP->setText("About MRiCP");
    action_help_about_MRiCP->setIcon(QIcon("img/MRiCP.png"));

    //Toolbar
    toolbar_file->addAction(action_file_load_PATIENT);
    toolbar_file->addAction(action_file_save_PATIENT);
    toolbar_file->setMovable(false);
    addToolBar(Qt::TopToolBarArea, toolbar_file);

    toolbar_module->addAction(action_module_PATIENT);
    toolbar_module->addAction(action_module_MRI);
    toolbar_module->addAction(action_module_ICP);
    toolbar_module->addAction(action_module_EPI);
    toolbar_module->addAction(action_module_COMPLIANCE);
    toolbar_module->addAction(action_module_TRANSFERTFUNCTION);
    toolbar_module->addAction(action_module_STATISTICS);
    toolbar_module->setMovable(false);
    addToolBar(Qt::TopToolBarArea, toolbar_module);

    toolbar_edit->setMovable(false);
    addToolBar(Qt::TopToolBarArea, toolbar_edit);

    toolbar_help->setMovable(false);
    addToolBar(Qt::TopToolBarArea, toolbar_help);

    //ScrollArea
    scrollarea_PATIENT->setLayout(grid_PATIENT);
    scrollarea_PATIENT->setWidgetResizable(true);
    scrollarea_PATIENT->setWidget(scrollwidget_PATIENT);
    scrollarea_MRI->setLayout(grid_MRI);
    scrollarea_MRI->setWidgetResizable(true);
    scrollarea_MRI->setWidget(scrollwidget_MRI);
    scrollarea_ICP->setLayout(grid_ICP);
    scrollarea_ICP->setWidgetResizable(true);
    scrollarea_ICP->setWidget(scrollwidget_ICP);
    scrollarea_EPI->setLayout(grid_EPI);
    scrollarea_EPI->setWidgetResizable(true);
    scrollarea_EPI->setWidget(scrollwidget_EPI);
    scrollarea_COMPLIANCE->setLayout(grid_COMPLIANCE);
    scrollarea_COMPLIANCE->setWidgetResizable(true);
    scrollarea_COMPLIANCE->setWidget(scrollwidget_COMPLIANCE);
    scrollarea_TRANSFERTFUNCTION->setLayout(grid_TRANSFERTFUNCTION);
    scrollarea_TRANSFERTFUNCTION->setWidgetResizable(true);
    scrollarea_TRANSFERTFUNCTION->setWidget(scrollwidget_TRANSFERTFUNCTION);
    scrollarea_STATISTICS->setLayout(grid_STATISTICS);
    scrollarea_STATISTICS->setWidgetResizable(true);
    scrollarea_STATISTICS->setWidget(scrollwidget_STATISTICS);

    //Widget
    setCentralWidget(stacked_widget);

    stacked_widget->addWidget(central_widget_PATIENT);
    stacked_widget->addWidget(central_widget_MRI);
    stacked_widget->addWidget(central_widget_ICP);
    stacked_widget->addWidget(central_widget_EPI);
    stacked_widget->addWidget(central_widget_COMPLIANCE);
    stacked_widget->addWidget(central_widget_TRANSFERTFUNCTION);
    stacked_widget->addWidget(central_widget_STATISTICS);

    central_widget_PATIENT->setLayout(vbox_PATIENT);
    central_widget_MRI->setLayout(vbox_MRI);
    central_widget_ICP->setLayout(vbox_ICP);
    central_widget_EPI->setLayout(vbox_EPI);
    central_widget_COMPLIANCE->setLayout(vbox_COMPLIANCE);
    central_widget_TRANSFERTFUNCTION->setLayout(vbox_TRANSFERTFUNCTION);
    central_widget_STATISTICS->setLayout(vbox_STATISTICS);

    scrollwidget_PATIENT->setLayout(grid_PATIENT);
    scrollwidget_MRI->setLayout(grid_MRI);
    scrollwidget_ICP->setLayout(grid_ICP);
    scrollwidget_EPI->setLayout(grid_EPI);
    scrollwidget_COMPLIANCE->setLayout(grid_COMPLIANCE);
    scrollwidget_TRANSFERTFUNCTION->setLayout(grid_TRANSFERTFUNCTION);
    scrollwidget_STATISTICS->setLayout(grid_STATISTICS);

    //Grid
    grid_PATIENT->addWidget(PATIENT__label_name, 0, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__lineedit_name, 0, 1, 1, 2);
    grid_PATIENT->addWidget(PATIENT__label_birth_date, 1, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__calendar_birth_date, 1, 1, 1, 10);
    grid_PATIENT->addWidget(PATIENT__lineedit_birth_date, 2, 1, 1, 2);
    grid_PATIENT->addWidget(PATIENT__label_age, 3, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__spinbox_age, 3, 1, 1, 2);
    grid_PATIENT->addWidget(PATIENT__label_sexe, 4, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__radiobutton_sexe_M, 4, 1, 1, 1);
    grid_PATIENT->addWidget(PATIENT__radiobutton_sexe_F, 4, 2, 1, 1);
    grid_PATIENT->addWidget(PATIENT__label_pathology, 5, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__combobox_pathology, 5, 1, 1, 1);
    grid_PATIENT->addWidget(PATIENT__button_pathology, 5, 2, 1, 1);
    grid_PATIENT->addWidget(PATIENT__label_MRI, 6, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__textedit_MRI, 6, 1, 1, 10);
    grid_PATIENT->addWidget(PATIENT__label_ICP, 7, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__textedit_ICP, 7, 1, 1, 10);
    grid_PATIENT->addWidget(PATIENT__label_EPI, 8, 0, 1, 1);
    grid_PATIENT->addWidget(PATIENT__textedit_EPI, 8, 1, 1, 10);

    grid_MRI->addWidget(MRI__tab);

    grid_ICP->addWidget(ICP__plot_signal, 0, 0, 10, 10);
    grid_ICP->addLayout(ICP__vbox_signal, 0, 10, 4, 2);
    grid_ICP->addLayout(ICP__hbox_signal, 10, 0, 1, 12);

    grid_ICP->addWidget(ICP__button_show_basal, 20, 0, 1, 6);
    grid_ICP->addWidget(ICP__scrollarea_basal, 21, 0, 1, 6);
    grid_ICP->addWidget(ICP__button_show_plateau, 20, 6, 1, 6);
    grid_ICP->addWidget(ICP__scrollarea_plateau, 21, 6, 1, 6);

    grid_ICP->addWidget(ICP__button_auto, 30, 0, 1, 6);
    grid_ICP->addWidget(ICP__button_adjust_basal, 30, 6, 1, 3);
    grid_ICP->addWidget(ICP__button_adjust_plateau, 30, 9, 1, 3);

    grid_ICP->addWidget(ICP__plot_mean_basal, 40, 0, 10, 5);
    grid_ICP->addLayout(ICP__vbox_mean_basal, 40, 5, 10, 1);
    grid_ICP->addWidget(ICP__plot_mean_plateau, 40, 6, 10, 5);
    grid_ICP->addLayout(ICP__vbox_mean_plateau, 40, 11, 10, 1);

    //grid_EPI

    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_arteriovenous_spinal, 0, 0, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_arteriovenous_spinal, 1, 0, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_arteriovenous_spinal, 0, 10, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_arteriovenouscsf_spinal, 11, 0, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_arteriovenouscsf_spinal, 12, 0, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_arteriovenouscsf_spinal, 11, 10, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_arteriovenous_intracranial, 22, 0, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_arteriovenous_intracranial, 23, 0, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_arteriovenous_intracranial, 22, 10, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_arteriovenouscsf_intracranial, 33, 0, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_arteriovenouscsf_intracranial, 34, 0, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_arteriovenouscsf_intracranial, 33, 10, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_icp_basal, 11, 12, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_icp_basal, 11, 13, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_icp_basal, 12, 13, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__vbox_icp_plateau, 22, 12, 11, 1);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_icp_plateau, 22, 13, 1, 10);
    grid_COMPLIANCE->addWidget(COMPLIANCE__plot_icp_plateau, 23, 13, 10, 10);
    grid_COMPLIANCE->addLayout(COMPLIANCE__hbox_compliance, 44, 0, 1, 23);

    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_arteriovenous_spinal, 0, 0, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_arteriovenous_spinal, 1, 0, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_arteriovenous_spinal, 0, 10, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_arteriovenouscsf_spinal, 11, 0, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_arteriovenouscsf_spinal, 12, 0, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_arteriovenouscsf_spinal, 11, 10, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_arteriovenous_intracranial, 22, 0, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_arteriovenous_intracranial, 23, 0, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_arteriovenous_intracranial, 22, 10, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_arteriovenouscsf_intracranial, 33, 0, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_arteriovenouscsf_intracranial, 34, 0, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_arteriovenouscsf_intracranial, 33, 10, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_icp_basal, 11, 12, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_icp_basal, 11, 13, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_icp_basal, 12, 13, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__vbox_icp_plateau, 22, 12, 11, 1);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_icp_plateau, 22, 13, 1, 10);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_icp_plateau, 23, 13, 10, 10);
    grid_TRANSFERTFUNCTION->addLayout(TRANSFERTFUNCTION__hbox_transfert_function, 44, 0, 1, 23);
    grid_TRANSFERTFUNCTION->addWidget(TRANSFERTFUNCTION__plot_transfert_function, 45, 0, 10, 23);

    grid_STATISTICS->addLayout(STATISTICS__vbox_load, 0, 0, 13, 1);
    grid_STATISTICS->addLayout(STATISTICS__hbox_x, 0, 1, 1, 10);
    grid_STATISTICS->addLayout(STATISTICS__hbox_y, 1, 1, 1, 10);
    grid_STATISTICS->addLayout(STATISTICS__hbox_tools, 2, 1, 1, 10);
    grid_STATISTICS->addWidget(STATISTICS__plot, 3, 1, 10, 10);

    //VBox
    vbox_PATIENT->addWidget(scrollarea_PATIENT);
    vbox_MRI->addWidget(scrollarea_MRI);
    vbox_ICP->addWidget(scrollarea_ICP);
    vbox_EPI->addWidget(scrollarea_EPI);
    vbox_COMPLIANCE->addWidget(scrollarea_COMPLIANCE);
    vbox_TRANSFERTFUNCTION->addWidget(scrollarea_TRANSFERTFUNCTION);
    vbox_STATISTICS->addWidget(scrollarea_STATISTICS);
}

void MainWindow::init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Action
    connect(action_file_load_PATIENT, SIGNAL(triggered(bool)), this, SLOT(PATIENT__load()));
    connect(action_file_load_MRI, SIGNAL(triggered(bool)), this, SLOT(MRI__load()));
    connect(action_file_load_ICP, SIGNAL(triggered(bool)), this, SLOT(ICP__load()));
    connect(action_file_load_EPI, SIGNAL(triggered(bool)), this, SLOT(EPI__load()));
    connect(action_file_save_PATIENT, SIGNAL(triggered(bool)), this, SLOT(PATIENT__save()));
    connect(action_file_quit, SIGNAL(triggered(bool)), this, SLOT(quit()));

    connect(action_module_PATIENT, SIGNAL(triggered(bool)), this, SLOT(module_PATIENT()));
    connect(action_module_MRI, SIGNAL(triggered(bool)), this, SLOT(module_MRI()));
    connect(action_module_ICP, SIGNAL(triggered(bool)), this, SLOT(module_ICP()));
    connect(action_module_EPI, SIGNAL(triggered(bool)), this, SLOT(module_EPI()));
    connect(action_module_COMPLIANCE, SIGNAL(triggered(bool)), this, SLOT(module_COMPLIANCE()));
    connect(action_module_TRANSFERTFUNCTION, SIGNAL(triggered(bool)), this, SLOT(module_TRANSFERTFUNCTION()));
    connect(action_module_STATISTICS, SIGNAL(triggered(bool)), this, SLOT(module_STATISTICS()));

    connect(action_action_import_Flow_eXplorer, SIGNAL(triggered(bool)), this, SLOT(action_import_Flow_eXplorer()));
    connect(action_action_export_data, SIGNAL(triggered(bool)), this, SLOT(action_export_data()));
    connect(action_action_export_report, SIGNAL(triggered(bool)), this, SLOT(action_export_report()));

    connect(action_edit_settings, SIGNAL(triggered(bool)), this, SLOT(settings()));

    connect(action_help_about_Qt, SIGNAL(triggered(bool)), this, SLOT(aboutQt()));
    connect(action_help_about_MRiCP, SIGNAL(triggered(bool)), this, SLOT(aboutMRiCP()));
}

void MainWindow::init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Window
    this->setWindowTitle("MRiCP -- Version 1.0");
    this->setWindowIcon(QIcon("img/MRiCP.png"));
    this->setWindowIconText("MRiCP");
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    init_var();
    PATIENT__init_var();
    MRI__init_var();
    ICP__init_var();
    EPI__init_var();
    COMPLIANCE__init_var();
    TRANSFERTFUNCTION__init_var();
    STATISTICS__init_var();

    init_win();
    PATIENT__init_win();
    MRI__init_win();
    ICP__init_win();
    EPI__init_win();
    COMPLIANCE__init_win();
    TRANSFERTFUNCTION__init_win();
    STATISTICS__init_win();

    init_sig();
    PATIENT__init_sig();
    MRI__init_sig();
    ICP__init_sig();
    EPI__init_sig();
    COMPLIANCE__init_sig();
    TRANSFERTFUNCTION__init_sig();
    STATISTICS__init_sig();

    init_css();
    PATIENT__init_css();
    MRI__init_css();
    ICP__init_css();
    EPI__init_css();
    COMPLIANCE__init_css();
    TRANSFERTFUNCTION__init_css();
    STATISTICS__init_css();
}

void MainWindow::module_PATIENT(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(0);
}

void MainWindow::module_MRI(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(1);
}

void MainWindow::module_ICP(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(2);
}

void MainWindow::module_EPI(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(3);
}

void MainWindow::module_COMPLIANCE(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(4);
}

void MainWindow::module_TRANSFERTFUNCTION(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(5);
}

void MainWindow::module_STATISTICS(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    stacked_widget->setCurrentIndex(6);
}

bool MainWindow::action_import_Flow_eXplorer(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    DialogImportFloweXplorer *dialog = new DialogImportFloweXplorer(this);
    dialog->exec();

    return true;
}

bool MainWindow::action_export_data(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString *DirName = new QString;
    QStringList *DataList = new QStringList;
    DialogExportData *dialog = new DialogExportData(DirName, DataList);
    int Result = dialog->exec();

    if (Result == QDialog::Accepted){
        if (DataList->isEmpty()){
            statusbar_show_warning("Export data error - ERR2");
            return false;
        }
        else{
            unsigned int NData = DataList->count();
            for (unsigned int i = 0; i < NData; i++){
                std::cout << DataList->at(i).toStdString() << std::endl;
                //TODO savecsv
            }
            return true;
        }
    }
    else{
        statusbar_show_warning("Export data error - ERR1");
        return false;
    }
}

bool MainWindow::action_export_report(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //TODO

    return true;
}

void MainWindow::settings(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    DialogSettings *dialog = new DialogSettings(this);
    int res = dialog->exec();
    if (res == QDialog::Accepted){
        //
    }
}

void MainWindow::statusbar_show_message(QString message){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPalette pal = statusbar->palette();
    pal.setColor(QPalette::WindowText, Qt::blue);
    statusbar->setPalette(QPalette(pal));
    statusbar->showMessage(message, 5000);
    //std::cout << message.toStdString() << std::endl;
}

void MainWindow::statusbar_show_warning(QString message){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPalette pal = statusbar->palette();
    pal.setColor(QPalette::WindowText, Qt::red);
    statusbar->setPalette(QPalette(pal));
    statusbar->showMessage(message, 5000);
    std::cerr << "WARNING: " << message.toStdString() << std::endl;
}

void MainWindow::statusbar_show_critical(QString message){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QPalette pal = statusbar->palette();
    pal.setColor(QPalette::Window, Qt::black);
    pal.setColor(QPalette::WindowText, Qt::blue);
    statusbar->setPalette(QPalette(pal));
    statusbar->showMessage(message, 5000);
    std::cerr << "CRITICAL: " << message.toStdString() << std::endl;
}

void MainWindow::aboutQt(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::aboutMRiCP(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString Text = "";  //TODO
    QMessageBox::about(this, "About MRiCP", Text);
}

void MainWindow::quit(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    qApp->quit();
}

void MainWindow::resizeEvent(QResizeEvent *){
    //STATISTICS
    STATISTICS__list_load->setMaximumWidth(this->width()/5.);
}


