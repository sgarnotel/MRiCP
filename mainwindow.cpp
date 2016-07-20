#include "mainwindow.h"

/*!
 * \brief MainWindow::init_var
 *
 * Initialisation of variables
 */
void MainWindow::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //************//
    //***GLOBAL***//
    //************//
    //Central
    central = new QWidget;
    setCentralWidget(central);

    //Menu
    menu_file = menuBar()->addMenu(MAINWINDOW_FILE_MENU);
    menu_edit = menuBar()->addMenu(MAINWINDOW_EDIT_MENU);
    menu_view = menuBar()->addMenu(MAINWINDOW_VIEW_MENU);
    menu_help = menuBar()->addMenu(MAINWINDOW_HELP_MENU);

    //Actions
    action_quit = new QAction(QIcon(IMG_QUIT), MAINWINDOW_ACTION_QUIT, this);
    action_settings = new QAction(QIcon(IMG_SETTINGS), MAINWINDOW_ACTION_SETTINGS, this);

    action_new_patient = new QAction(QIcon(IMG_ADD), MAINWINDOW_ACTION_NEW_PATIENT, this);
    action_load_patient = new QAction(QIcon(IMG_LOAD), MAINWINDOW_ACTION_LOAD_PATIENT, this);
    action_modify_patient = new QAction(QIcon(IMG_MODIFY), MAINWINDOW_ACTION_MODIFY_PATIENT, this);
    action_delete_patient = new QAction(QIcon(IMG_DELETE), MAINWINDOW_ACTION_DELETE_PATIENT, this);
    action_export_patient = new QAction(QIcon(IMG_EXPORT), "Export Patient", this);

    action_hide_MRI = new QAction(QIcon(IMG_HIDE), MAINWINDOW_ACTION_HIDE_MRI, this);
    action_restore_MRI = new QAction(QIcon(IMG_REST), MAINWINDOW_ACTION_REST_MRI, this);
    action_restore_MRI->setEnabled(false);
    action_hide_ICP = new QAction(QIcon(IMG_HIDE), MAINWINDOW_ACTION_HIDE_ICP, this);
    action_restore_ICP = new QAction(QIcon(IMG_REST), MAINWINDOW_ACTION_REST_ICP, this);
    action_restore_ICP->setEnabled(false);
    action_hide_EPI = new QAction(QIcon(IMG_HIDE), MAINWINDOW_ACTION_HIDE_EPI, this);
    action_restore_EPI = new QAction(QIcon(IMG_REST), MAINWINDOW_ACTION_REST_EPI, this);
    action_restore_EPI->setEnabled(false);

    action_user_help = new QAction(QIcon(IMG_HELP), MAINWINDOW_ACTION_USER_HELP, this);
    action_programmer_help = new QAction(QIcon(IMG_HELP), MAINWINDOW_ACTION_PROG_HELP, this);
    action_about = new QAction(QIcon(IMG_ICON), "About", this);

    //ToolBar
    toolbar = new QToolBar(MAINWINDOW_GLOBAL_TOOLBAR);

    //Scroll Area
    scroll_area = new QScrollArea(this);

    //Widget
    scroll_widget = new QWidget(this);

    //VBox
    scroll_vbox = new QVBoxLayout;

    //Grid
    grid = new QGridLayout;
    grid_all = new QGridLayout;

    //Labels
    label_title = new QLabel(this);
    label_patient = new QLabel(this);
    label_patient_name = new QLabel(this);
    label_space1 = new QLabel(this);
    label_space2 = new QLabel(this);
    label_statusbar_img = new QLabel(this);
    label_statusbar_txt = new QLabel(this);

    //StatusBar
    statusbar = statusBar();

    //Buttons
    button_save_MRI = new QPushButton(this);
    button_save_ICP = new QPushButton(this);
    button_save_EPI = new QPushButton(this);
    button_save_all = new QPushButton(this);
    button_clear_MRI = new QPushButton(this);
    button_clear_ICP = new QPushButton(this);
    button_clear_EPI = new QPushButton(this);
    button_clear_all = new QPushButton(this);

    //Int
    npi = 0;
    PCMRI_length = 0;

    //String
    current_dir = EMPTY_STRING;
    exam_number = EMPTY_STRING;
    exam_date = EMPTY_STRING;
    patient_age = EMPTY_STRING;
    patient_sexe = EMPTY_STRING;
    patient_date = EMPTY_STRING;

    MRI_time_unity = EMPTY_STRING;
    MRI_flow_unity = EMPTY_STRING;
    MRI_volume_unity = EMPTY_STRING;
    ICP_time_unity = EMPTY_STRING;
    ICP_pressure_unity = EMPTY_STRING;

    //Double
    MRI_EPI_coeff_systole_threshold = 0.;
    MRI_EPI_coeff_systole_delay = 0.;
    ICP_coeff_fourier_min = 0.;
    ICP_coeff_fourier_max = 0.;
    ICP_coeff_ifft_min = 0.;
    ICP_coeff_ifft_max = 0.;
    EPI_coeff_fourier_min = 0.;
    EPI_coeff_fourier_max = 0.;
    EPI_coeff_ifft_min = 0.;
    EPI_coeff_ifft_max = 0.;
    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
    init_MRI_var();
    //*********//
    //*********//


    //*********//
    //***ICP***//
    //*********//
    init_ICP_var();
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    init_EPI_var();
    //*********//
    //*********//


    //*************//
    //***COMPARE***//
    //*************//
    init_COMP_var();
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    init_STAT_var();
    //***********//
    //***********//
}

/*!
 * \brief MainWindow::init_win
 *
 * Initialisation of window
 */
void MainWindow::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //************//
    //***GLOBAL***//
    //************//
    //Menu
    menu_file->addSeparator();
    menu_file->addAction(action_new_patient);
    menu_file->addAction(action_load_patient);
    menu_file->addAction(action_modify_patient);
    menu_file->addAction(action_delete_patient);
    menu_file->addAction(action_export_patient);
    menu_file->addSeparator();
    menu_file->addAction(action_compare);
    menu_file->addSeparator();
    menu_file->addAction(action_stats);
    menu_file->addSeparator();
    menu_file->addAction(action_quit);

    menu_edit->addAction(action_settings);

    menu_view->addAction(action_hide_MRI);
    menu_view->addAction(action_restore_MRI);
    menu_view->addAction(action_hide_ICP);
    menu_view->addAction(action_restore_ICP);
    menu_view->addAction(action_hide_EPI);
    menu_view->addAction(action_restore_EPI);

    menu_help->addAction(action_user_help);
    menu_help->addAction(action_programmer_help);
    menu_help->addAction(action_about);

    //ToolBar
    toolbar->addAction(action_quit);
    toolbar->addAction(action_settings);
    toolbar->addSeparator();
    toolbar->addWidget(label_title);
    toolbar->addSeparator();
    toolbar->addWidget(label_patient);
    toolbar->addAction(action_new_patient);
    toolbar->addAction(action_load_patient);
    toolbar->addAction(action_modify_patient);
    toolbar->addAction(action_delete_patient);
    toolbar->addAction(action_export_patient);
    toolbar->addSeparator();
    toolbar->setMovable(false);
    toolbar->setIconSize(QSize(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));
    addToolBar(Qt::TopToolBarArea, toolbar);

    //Grid
    grid->addLayout(grid_all, 0, 0, 2, 300);
    grid->addWidget(MRI_tab, 2, 0, 100, 100);
    grid->addWidget(label_space1, 2, 100, 100, 1);
    grid->addWidget(ICP_tab, 2, 101, 100, 100);
    grid->addWidget(label_space2, 2, 201, 100, 1);
    grid->addWidget(EPI_tab, 2, 202, 100, 100);

    grid_all->addWidget(label_patient_name, 0, 0, Qt::AlignCenter);
    grid_all->addWidget(button_save_MRI, 0, 2);
    grid_all->addWidget(button_save_ICP, 0, 3);
    grid_all->addWidget(button_save_EPI, 0, 4);
    grid_all->addWidget(button_save_all, 0, 5);
    grid_all->addWidget(button_clear_MRI, 0, 6);
    grid_all->addWidget(button_clear_ICP, 0, 7);
    grid_all->addWidget(button_clear_EPI, 0, 8);
    grid_all->addWidget(button_clear_all, 0, 9);

    //Labels
    label_title->setText(MAINWINDOW_TITLE);
    label_patient->setText(MAINWINDOW_PATIENT);
    label_statusbar_img->setPixmap(QPixmap(IMG_STATUSBAR_GREEN).scaled(IMG_STATUSBAR_SIZE, IMG_STATUSBAR_SIZE));
    label_statusbar_txt->setText(MAINWINDOW_READY);

    //StatusBar
    statusbar->addPermanentWidget(label_statusbar_img);
    statusbar->addPermanentWidget(label_statusbar_txt);

    //Buttons
    button_save_MRI->setIcon(QIcon(IMG_SAVE));
    button_save_MRI->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_save_MRI->setToolTip(MAINWINDOW_SAVE_MRI);
    button_save_MRI->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_save_ICP->setIcon(QIcon(IMG_SAVE));
    button_save_ICP->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_save_ICP->setToolTip(MAINWINDOW_SAVE_ICP);
    button_save_ICP->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_save_EPI->setIcon(QIcon(IMG_SAVE));
    button_save_EPI->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_save_EPI->setToolTip(MAINWINDOW_SAVE_EPI);
    button_save_EPI->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_save_all->setIcon(QIcon(IMG_SAVE));
    button_save_all->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_save_all->setToolTip(MAINWINDOW_SAVE_ALL);
    button_save_all->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_clear_MRI->setIcon(QIcon(IMG_CLEAR));
    button_clear_MRI->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_clear_MRI->setToolTip(MAINWINDOW_CLEAR_MRI);
    button_clear_MRI->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_clear_ICP->setIcon(QIcon(IMG_CLEAR));
    button_clear_ICP->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_clear_ICP->setToolTip(MAINWINDOW_CLEAR_ICP);
    button_clear_ICP->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_clear_EPI->setIcon(QIcon(IMG_CLEAR));
    button_clear_EPI->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_clear_EPI->setToolTip(MAINWINDOW_CLEAR_EPI);
    button_clear_EPI->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    button_clear_all->setIcon(QIcon(IMG_CLEAR));
    button_clear_all->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    button_clear_all->setToolTip(MAINWINDOW_CLEAR_ALL);
    button_clear_all->setMaximumSize(QSize(IMG_BUTTON_SIZE+5, IMG_BUTTON_SIZE+5));
    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
    init_MRI_win();
    //*********//
    //*********//


    //*********//
    //***ICP***//
    //*********//
    init_ICP_win();
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    init_EPI_win();
    //*********//
    //*********//


    //*************//
    //***COMPARE***//
    //*************//
    init_COMP_win();
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    init_STAT_win();
    //***********//
    //***********//

    //Widget
    scroll_widget->setLayout(grid);

    //ScrollArea
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(scroll_widget);

    //VBox
    scroll_vbox->addWidget(scroll_area);
    central->setLayout(scroll_vbox);
}

/*!
 * \brief MainWindow::init_sig
 */
void MainWindow::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //************//
    //***GLOBAL***//
    //************//
    connect(action_quit, SIGNAL(triggered()), this, SLOT(quit_win()));
    connect(action_settings, SIGNAL(triggered()), this, SLOT(settings()));

    connect(action_load_patient, SIGNAL(triggered()), this, SLOT(load_patient()));
    connect(action_new_patient, SIGNAL(triggered()), this, SLOT(new_patient()));
    connect(action_modify_patient, SIGNAL(triggered()), this, SLOT(modify_patient()));
    connect(action_delete_patient, SIGNAL(triggered()), this, SLOT(delete_patient()));
    connect(action_export_patient, SIGNAL(triggered()), this, SLOT(export_patient()));

    connect(action_hide_MRI, SIGNAL(triggered()), this, SLOT(hide_MRI()));
    connect(action_restore_MRI, SIGNAL(triggered()), this, SLOT(restore_MRI()));
    connect(action_hide_ICP, SIGNAL(triggered()), this, SLOT(hide_ICP()));
    connect(action_restore_ICP, SIGNAL(triggered()), this, SLOT(restore_ICP()));
    connect(action_hide_EPI, SIGNAL(triggered()), this, SLOT(hide_EPI()));
    connect(action_restore_EPI, SIGNAL(triggered()), this, SLOT(restore_EPI()));

    connect(action_user_help, SIGNAL(triggered()), this, SLOT(do_user_help()));
    connect(action_programmer_help, SIGNAL(triggered()), this, SLOT(do_programmer_help()));
    connect(action_about, SIGNAL(triggered()), this, SLOT(do_about()));

    connect(button_save_MRI, SIGNAL(clicked()), this, SLOT(save_MRI()));
    connect(button_save_ICP, SIGNAL(clicked()), this, SLOT(save_ICP()));
    connect(button_save_EPI, SIGNAL(clicked()), this, SLOT(save_EPI()));
    connect(button_save_all, SIGNAL(clicked()), this, SLOT(save_all()));

    connect(button_clear_MRI, SIGNAL(clicked()), this, SLOT(clear_MRI()));
    connect(button_clear_ICP, SIGNAL(clicked()), this, SLOT(clear_ICP()));
    connect(button_clear_EPI, SIGNAL(clicked()), this, SLOT(clear_EPI()));
    connect(button_clear_all, SIGNAL(clicked()), this, SLOT(clear_all()));
    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
#ifdef QT5
    connect(MRI_tab->tabBar(), SIGNAL(currentChanged(int)), this, SLOT(update_tab(int)));
#endif
    init_MRI_sig();
    //*********//
    //*********//


    //*********//
    //***ICP***//
    //*********//
    init_ICP_sig();
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    init_EPI_sig();
    //*********//
    //*********//


    //*************//
    //***COMPARE***//
    //*************//
    init_COMP_sig();
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    init_STAT_sig();
    //***********//
    //***********//
}

/*!
 * \brief MainWindow::init_css
 */
void MainWindow::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //************//
    //***GLOBAL***//
    //************//
    //Window
    setWindowTitle(MAINWINDOW_TITLE);
    setWindowIcon(QIcon(IMG_ICON));
    setStyleSheet(CSS_MAINWINDOW);

    //Menu
    menuBar()->setStyleSheet(CSS_MENUBAR);
    menu_file->setStyleSheet(CSS_MENU);
    menu_edit->setStyleSheet(CSS_MENU);
    menu_view->setStyleSheet(CSS_MENU);

    //Toolbar
    toolbar->setStyleSheet(CSS_TOOLBAR);

    //Labels
    label_title->setStyleSheet(CSS_LABEL_TITLE);
    label_patient->setStyleSheet(CSS_LABEL_GLOBAL);
    label_patient_name->setStyleSheet(CSS_LABEL_BIG);
    label_space1->setStyleSheet(CSS_LABEL_SPACE);
    label_space2->setStyleSheet(CSS_LABEL_SPACE);
    label_statusbar_txt->setStyleSheet(CSS_LABEL_GLOBAL);

    //StatusBar
    statusbar->setStyleSheet(CSS_STATUSBAR);

    //Buttons
    button_clear_MRI->setStyleSheet(CSS_BUTTON);
    button_clear_ICP->setStyleSheet(CSS_BUTTON);
    button_clear_EPI->setStyleSheet(CSS_BUTTON);
    button_clear_all->setStyleSheet(CSS_BUTTON);

    //Widget
    scroll_widget->setStyleSheet(CSS_WIDGET);

    //ScrollArea
    scroll_area->setStyleSheet(CSS_SCROLL_AREA);
    //************//
    //************//


    //*********//
    //***MRI***//
    //*********//
    init_MRI_css();
    //*********//
    //*********//


    //*********//
    //***ICP***//
    //*********//
    init_ICP_css();
    //*********//
    //*********//


    //*********//
    //***EPI***//
    //*********//
    init_EPI_css();
    //*********//
    //*********//


    //*************//
    //***COMPARE***//
    //*************//
    init_COMP_css();
    //*************//
    //*************//


    //***********//
    //***STATS***//
    //***********//
    init_STAT_css();
    //***********//
    //***********//
}

/*!
 * \brief MainWindow::init_set
 */
void MainWindow::init_set(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Int
    bool res = get_npi(&npi);

    //String
    string *unities = new string[UNITY_LENGTH];
    res = get_unities(unities);
    if (res){
        MRI_time_unity = QString::fromStdString(unities[0]);
        MRI_flow_unity = QString::fromStdString(unities[1]);
        MRI_volume_unity = QString::fromStdString(unities[2]);
        ICP_time_unity = QString::fromStdString(unities[3]);
        ICP_pressure_unity = QString::fromStdString(unities[4]);
    }
    delete[] unities;

    //Double
    double *coeffs = new double[COEFFS_LENGTH];
    res = get_coeffs(coeffs);
    if (res){
        PCMRI_length = (int)coeffs[0];
        MRI_EPI_coeff_systole_threshold = coeffs[1];
        MRI_EPI_coeff_systole_delay = coeffs[2];
        ICP_coeff_fourier_min = coeffs[3];
        ICP_coeff_fourier_max = coeffs[4];
        ICP_coeff_ifft_min = coeffs[5];
        ICP_coeff_ifft_max = coeffs[6];
        EPI_coeff_fourier_min = coeffs[3];
        EPI_coeff_fourier_max = coeffs[4];
        EPI_coeff_ifft_min = coeffs[5];
        EPI_coeff_ifft_max = coeffs[6];
    }
    delete[] coeffs;
}

/*!
 * \brief MainWindow::MainWindow
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();

    init_set();

    init_win();
    init_sig();
    init_css();

    hide_ICP();     //TODO
    hide_EPI();     //TODO
}

/*!
 * \brief MainWindow::quit_win
 *
 * Quit the application
 */
void MainWindow::quit_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    qApp->quit();
}

/*!
 * \brief MainWindow::settings
 *
 * Open settings window
 */
void MainWindow::settings(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    DialogSettings *dialog = new DialogSettings;
    int res = dialog->exec();
    if (res == QDialog::Accepted){
        clear_all();
        init_set();

        if (!current_dir.isEmpty()){
            load_patient(current_dir);
        }
    }
    delete dialog;
}

/*!
 * \brief MainWindow::load_patient
 */
void MainWindow::load_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    load_patient(EMPTY_STRING);
}

/*!
 * \brief MainWindow::load_patient
 * \param dir
 */
void MainWindow::load_patient(QString dir){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (dir.isEmpty()){
        dir = QFileDialog::getExistingDirectory(this, MAINWINDOW_LOAD_PATIENT, get_Results_directory());
    }
#ifdef WIN_OS
    dir.replace(UNIX_DIR_SEPARATOR, WINDOWS_DIR_SEPARATOR);
#endif

    if (!dir.isEmpty()){
        clear_all();

        //Directory
        current_dir = QString(dir);

        //Informations
        exam_number = get_exam_number(current_dir);
        exam_date = get_exam_date(current_dir);
        patient_date = get_patient_date(current_dir);
        patient_age = get_patient_age(current_dir);
        patient_sexe = get_patient_sexe(current_dir);

        //All
        {
            MRI_arterial_files_other = get_MRI_arterial_files(current_dir);

            MRI_number_arterial = MRI_arterial_files_other->size();

            for (int i = 0; i < MRI_number_arterial; i++){
                QAction *action_arterial = new QAction(MRI_arterial_files_other->at(i), this);
                action_arterial->setCheckable(true);
                MRI_arterial_menu->addAction(action_arterial);
            }
            {
                QAction *action_arterial_plus_venous = new QAction("+ venous", this);
                action_arterial_plus_venous->setCheckable(true);
                QAction *action_arterial_plus_csf = new QAction("+ CSF", this);
                action_arterial_plus_csf->setCheckable(true);

                MRI_arterial_menu->addAction(action_arterial_plus_venous);
                MRI_arterial_menu->addAction(action_arterial_plus_csf);
            }

            MRI_coords_arterial_other = new Coord*[MRI_arterial_files_other->size()];
            for (int i = 0; i < MRI_arterial_files_other->size(); i++){
                MRI_coords_arterial_other[i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + MRI_arterial_files_other->at(i), MRI_coords_arterial_other[i]);
            }

            MRI_quality_arterial_other = new int[MRI_arterial_files_other->size()];
            for (int i = 0; i < MRI_arterial_files_other->size(); i++){
                MRI_quality_arterial_other[i] = get_MRI_arterial_other_quality_source(current_dir, i).toInt();
            }

            MRI_venous_files_other = get_MRI_venous_files(current_dir);

            MRI_number_venous = MRI_venous_files_other->size();

            for (int i = 0; i < MRI_number_venous; i++){
                QAction *action_venous = new QAction(MRI_venous_files_other->at(i), this);
                action_venous->setCheckable(true);
                MRI_venous_menu->addAction(action_venous);
            }
            {
                QAction *action_venous_plus_arterial = new QAction("+ arterial", this);
                action_venous_plus_arterial->setCheckable(true);
                QAction *action_venous_plus_csf = new QAction("+ CSF", this);
                action_venous_plus_csf->setCheckable(true);

                MRI_venous_menu->addAction(action_venous_plus_arterial);
                MRI_venous_menu->addAction(action_venous_plus_csf);
            }

            MRI_coords_venous_other = new Coord*[MRI_venous_files_other->size()];
            for (int i = 0; i < MRI_venous_files_other->size(); i++){
                MRI_coords_venous_other[i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + MRI_venous_files_other->at(i), MRI_coords_venous_other[i]);
            }

            MRI_quality_venous_other = new int[MRI_venous_files_other->size()];
            for (int i = 0; i < MRI_venous_files_other->size(); i++){
                MRI_quality_venous_other[i] = get_MRI_venous_other_quality_source(current_dir, i).toInt();
            }

            MRI_csf_files_other = get_MRI_csf_files(current_dir);

            MRI_number_csf = MRI_csf_files_other->size();

            for (int i = 0; i < MRI_number_csf; i++){
                QAction *action_csf = new QAction(MRI_csf_files_other->at(i), this);
                action_csf->setCheckable(true);
                MRI_csf_menu->addAction(action_csf);
            }
            {
                QAction *action_csf_plus_arterial = new QAction("+ arterial", this);
                action_csf_plus_arterial->setCheckable(true);
                QAction *action_csf_plus_venous = new QAction("+ venous", this);
                action_csf_plus_venous->setCheckable(true);

                MRI_csf_menu->addAction(action_csf_plus_arterial);
                MRI_csf_menu->addAction(action_csf_plus_venous);
            }

            MRI_coords_csf_other = new Coord*[MRI_csf_files_other->size()];
            for (int i = 0; i < MRI_csf_files_other->size(); i++){
                MRI_coords_csf_other[i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + MRI_csf_files_other->at(i), MRI_coords_csf_other[i]);
            }

            MRI_quality_csf_other = new int[MRI_csf_files_other->size()];
            for (int i = 0; i < MRI_csf_files_other->size(); i++){
                MRI_quality_csf_other[i] = get_MRI_csf_other_quality_source(current_dir, i).toInt();
            }

            for (int i = 0; i < MRI_arterial_menu->actions().count(); i++){
                connect(MRI_arterial_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_arterial_others()));
                connect(MRI_arterial_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_venous_others()));
                connect(MRI_arterial_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_csf_others()));
                connect(MRI_arterial_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(do_MRI_menu_arterial_others_visible()));
            }
            for (int i = 0; i < MRI_venous_menu->actions().count(); i++){
                connect(MRI_venous_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_arterial_others()));
                connect(MRI_venous_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_venous_others()));
                connect(MRI_venous_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_csf_others()));
                connect(MRI_venous_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(do_MRI_menu_venous_others_visible()));
            }
            for (int i = 0; i < MRI_csf_menu->actions().count(); i++){
                connect(MRI_csf_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_arterial_others()));
                connect(MRI_csf_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_venous_others()));
                connect(MRI_csf_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(plot_MRI_csf_others()));
                connect(MRI_csf_menu->actions().at(i), SIGNAL(triggered()), this, SLOT(do_MRI_menu_csf_others_visible()));
            }
        }

        {
            EPI_box_select_signal->clear();

            EPI_arterial_files_other = get_EPI_arterial_files(current_dir);
            EPI_number_arterial = EPI_arterial_files_other->size();

            EPI_venous_files_other = get_EPI_venous_files(current_dir);
            EPI_number_venous = EPI_venous_files_other->size();

            EPI_csf_files_other = get_EPI_csf_files(current_dir);
            EPI_number_csf = EPI_csf_files_other->size();

            EPI_coords = new Coord*[EPI_number_arterial+EPI_number_venous+EPI_number_csf];
            EPI_quality = new int[EPI_arterial_files_other->size()];

            for (int i = 0; i < EPI_number_arterial; i++){
                EPI_coords[i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + EPI_arterial_files_other->at(i), EPI_coords[i]);
                EPI_box_select_signal->addItem(EPI_arterial_files_other->at(i));
            }
            for (int i = 0; i < EPI_number_arterial; i++){
                EPI_quality[i] = get_EPI_arterial_other_quality_source(current_dir, i).toInt();
            }

            for (int i = 0; i < EPI_number_venous; i++){
                EPI_coords[EPI_number_arterial+i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + EPI_venous_files_other->at(i), EPI_coords[EPI_number_arterial+i]);
                EPI_box_select_signal->addItem(EPI_venous_files_other->at(i));
            }
            for (int i = 0; i < EPI_number_venous; i++){
                EPI_quality[EPI_number_arterial+i] = get_EPI_venous_other_quality_source(current_dir, i).toInt();
            }

            for (int i = 0; i < EPI_number_csf; i++){
                EPI_coords[EPI_number_arterial+EPI_number_venous+i] = new Coord;
                load_data(current_dir + DIR_SEPARATOR + EPI_csf_files_other->at(i), EPI_coords[EPI_number_arterial+EPI_number_venous+i]);
                EPI_box_select_signal->addItem(EPI_csf_files_other->at(i));
            }
            for (int i = 0; i < EPI_number_csf; i++){
                EPI_quality[EPI_number_arterial+EPI_number_venous+i] = get_EPI_csf_other_quality_source(current_dir, i).toInt();
            }
        }

        //Patient name
        {
            QString patient_name = QString(dir);
            int pos = patient_name.indexOf(DIR_SEPARATOR);
            while (pos != -1){
                patient_name.remove(0, pos+1);
                pos = patient_name.indexOf(DIR_SEPARATOR);
            }

            patient_name.remove(exam_number);
            patient_name.remove(patient_date);
            patient_name.replace("_", " ");

            label_patient_name->setText("Patient : " + patient_name + ", Examen : " + exam_number + "\nDate examen : " + exam_date + ", Age : " + patient_age + ", Sexe : " + patient_sexe + ", Date de naissance : " + patient_date);
        }

        //Files
        MRI_arterial_files_cervical->append(get_MRI_arterial_cervical_source(current_dir));
        MRI_venous_files_cervical->append(get_MRI_venous_cervical_source(current_dir));
        MRI_CSF_files_cervical->append(get_MRI_csf_cervical_source(current_dir));
        MRI_arterial_files_cerebral->append(get_MRI_arterial_cerebral_source(current_dir));
        MRI_venous_files_cerebral->append(get_MRI_venous_cerebral_source(current_dir));
        MRI_CSF_files_cerebral->append(get_MRI_csf_cerebral_source(current_dir));

        EPI_arterial_files_cervical->append(get_EPI_arterial_cervical_source(current_dir));
        EPI_venous_files_cervical->append(get_EPI_venous_cervical_source(current_dir));
        EPI_CSF_files_cervical->append(get_EPI_csf_cervical_source(current_dir));
        EPI_arterial_files_cerebral->append(get_EPI_arterial_cerebral_source(current_dir));
        EPI_venous_files_cerebral->append(get_EPI_venous_cerebral_source(current_dir));
        EPI_CSF_files_cerebral->append(get_EPI_csf_cerebral_source(current_dir));

        //Quality
        MRI_quality_arterial_cervical = get_MRI_arterial_cervical_quality_source(current_dir).toInt();
        MRI_quality_venous_cervical = get_MRI_venous_cervical_quality_source(current_dir).toInt();
        MRI_quality_csf_cervical = get_MRI_csf_cervical_quality_source(current_dir).toInt();
        MRI_quality_arterial_cerebral = get_MRI_arterial_cerebral_quality_source(current_dir).toInt();
        MRI_quality_venous_cerebral = get_MRI_venous_cerebral_quality_source(current_dir).toInt();
        MRI_quality_csf_cerebral = get_MRI_csf_cerebral_quality_source(current_dir).toInt();

        EPI_quality_arterial_cervical = get_EPI_arterial_cervical_quality_source(current_dir).toInt();
        EPI_quality_venous_cervical = get_EPI_venous_cervical_quality_source(current_dir).toInt();
        EPI_quality_csf_cervical = get_EPI_csf_cervical_quality_source(current_dir).toInt();
        EPI_quality_arterial_cerebral = get_EPI_arterial_cerebral_quality_source(current_dir).toInt();
        EPI_quality_venous_cerebral = get_EPI_venous_cerebral_quality_source(current_dir).toInt();
        EPI_quality_csf_cerebral = get_EPI_csf_cerebral_quality_source(current_dir).toInt();

        //MRI data
        int n_arterial = MRI_ARTERIAL_DATA_LENGTH;
        string *arterial_cervical_list = new string[n_arterial];
        string *arterial_cerebral_list = new string[n_arterial];
        int arterial_cervical_tune = 0;
        int arterial_cerebral_tune = 0;
        int n_venous = MRI_VENOUS_DATA_LENGTH;
        string *venous_cervical_list = new string[n_venous];
        string *venous_cerebral_list = new string[n_venous];
        int venous_cervical_tune = 0;
        int venous_cerebral_tune = 0;
        int n_csf = MRI_CSF_DATA_LENGTH;
        string *csf_cervical_list = new string[n_csf];
        string *csf_cerebral_list = new string[n_csf];
        int csf_cervical_tune = 0;
        int csf_cerebral_tune = 0;
        //ICP data
        int n_ICP = ICP_DATA_LENGHT;
        string *ICP_list = new string[n_ICP];
        int ICP_tune = 0;

        //MRI Cervical
        bool res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE_PRO, MRI_coord_arterial_cervical);
        if (res){
            string *list = new string[n_arterial];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE_DAT, list, arterial_cervical_list, n_arterial);
            if (res){
                arterial_cervical_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE, MRI_coord_arterial_cervical);
        }

        res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_PRO, MRI_coord_venous_cervical);
        if (res){
            string *list = new string[n_venous];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_DAT, list, venous_cervical_list, n_venous);
            if (res){
                venous_cervical_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE, MRI_coord_venous_cervical);
        }

        res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_PRO, MRI_coord_csf_cervical);
        if (res){
            string *list = new string[n_csf];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_DAT, list, csf_cervical_list, n_csf);
            if (res){
                csf_cervical_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE, MRI_coord_csf_cervical);
        }

        //MRI Cerebral
        res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE_PRO, MRI_coord_arterial_cerebral);
        if (res){
            string *list = new string[n_arterial];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE_DAT, list, arterial_cerebral_list, n_arterial);
            if (res){
                arterial_cerebral_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE, MRI_coord_arterial_cerebral);
        }

        res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_PRO, MRI_coord_venous_cerebral);
        if (res){
            string *list = new string[n_venous];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_DAT, list, venous_cerebral_list, n_venous);
            if (res){
                venous_cerebral_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE, MRI_coord_venous_cerebral);
        }

        res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_PRO, MRI_coord_csf_cerebral);
        if (res){
            string *list = new string[n_csf];
            res = load_sup_data(dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_DAT, list, csf_cerebral_list, n_csf);
            if (res){
                csf_cerebral_tune = 1;
            }
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE, MRI_coord_csf_cerebral);
        }

        //ICP
        res = load_data(dir + DIR_SEPARATOR + ICP_FILE, ICP_coord_signal);
        {
            string *list = new string[n_ICP];
            res = load_sup_data(dir + DIR_SEPARATOR + ICP_FILE_DAT, list, ICP_list, n_ICP);
            if (res){
                ICP_tune = 1;
            }
            delete[] list;
        }

#if 0
        //EPI Cervical
        res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CERVICAL_FILE_PRO, EPI_coord_arterial_cervical);
        if (res){
            string *list = new string[n_arterial];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CERVICAL_FILE_DAT, list, arterial_cervical_list, n_arterial);
            /*if (res){
                arterial_cervical_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_ARTERIAL_CERVICAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CERVICAL_FILE, EPI_coord_arterial_cervical);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_ARTERIAL_CERVICAL_FILE);
            }*/
        }

        res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CERVICAL_FILE_PRO, EPI_coord_venous_cervical);
        if (res){
            string *list = new string[n_venous];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_VENOUS_CERVICAL_FILE_DAT, list, venous_cervical_list, n_venous);
            /*if (res){
                venous_cervical_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_VENOUS_CERVICAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CERVICAL_FILE, EPI_coord_venous_cervical);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_VENOUS_CERVICAL_FILE);
            }*/
        }

        res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CERVICAL_FILE_PRO, EPI_coord_csf_cervical);
        if (res){
            string *list = new string[n_csf];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_CSF_CERVICAL_FILE_DAT, list, csf_cervical_list, n_csf);
            /*if (res){
                csf_cervical_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_CSF_CERVICAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CERVICAL_FILE, EPI_coord_csf_cervical);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_CSF_CERVICAL_FILE);
            }*/
        }

        //EPI Cerebral
        res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CEREBRAL_FILE_PRO, EPI_coord_arterial_cerebral);
        if (res){
            string *list = new string[n_arterial];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CEREBRAL_FILE_DAT, list, arterial_cerebral_list, n_arterial);
            /*if (res){
                arterial_cerebral_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_ARTERIAL_CEREBRAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CEREBRAL_FILE, EPI_coord_arterial_cerebral);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_ARTERIAL_CEREBRAL_FILE);
            }*/
        }

        res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CEREBRAL_FILE_PRO, EPI_coord_venous_cerebral);
        if (res){
            string *list = new string[n_venous];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_VENOUS_CEREBRAL_FILE_DAT, list, venous_cerebral_list, n_venous);
            /*if (res){
                venous_cerebral_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_VENOUS_CEREBRAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CEREBRAL_FILE, EPI_coord_venous_cerebral);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_VENOUS_CEREBRAL_FILE);
            }*/
        }

        res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CEREBRAL_FILE_PRO, EPI_coord_csf_cerebral);
        if (res){
            string *list = new string[n_csf];
            res = load_sup_data(dir + DIR_SEPARATOR + EPI_CSF_CEREBRAL_FILE_DAT, list, csf_cerebral_list, n_csf);
            /*if (res){
                csf_cerebral_tune = 1;
            }*/
            //EPI_box_select_signal->addItem(EPI_CSF_CEREBRAL_FILE_PRO);
            delete[] list;
        }
        else{
            res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CEREBRAL_FILE, EPI_coord_csf_cerebral);
            /*if (res){
                EPI_box_select_signal->addItem(EPI_CSF_CEREBRAL_FILE);
            }*/
        }

        res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CERVICAL_FILE, EPI_coord_arterial_cervical);
        res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CERVICAL_FILE, EPI_coord_venous_cervical);
        res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CERVICAL_FILE, EPI_coord_csf_cervical);
        res = load_data(dir + DIR_SEPARATOR + EPI_ARTERIAL_CEREBRAL_FILE, EPI_coord_arterial_cerebral);
        res = load_data(dir + DIR_SEPARATOR + EPI_VENOUS_CEREBRAL_FILE, EPI_coord_venous_cerebral);
        res = load_data(dir + DIR_SEPARATOR + EPI_CSF_CEREBRAL_FILE, EPI_coord_csf_cerebral);
#endif

        //Extend
        extend(MRI_coord_arterial_cervical, npi);
        extend(MRI_coord_venous_cervical, npi);
        extend(MRI_coord_csf_cervical, npi);
        extend(MRI_coord_arterial_cerebral, npi);
        extend(MRI_coord_venous_cerebral, npi);
        extend(MRI_coord_csf_cerebral, npi);

        //Plot
        plot_MRI_cervical();
        plot_MRI_cerebral();
        plot_MRI_others();
        plot_ICP_signal_curve();
        if (EPI_box_select_signal->count() > 0){
            plot_EPI_signal_curve(0);
        }

        //Tune
        if (arterial_cervical_tune){
            MRI_box_systole_threshold_cervical->setValue(QString::fromStdString(arterial_cervical_list[0]).toDouble());
            MRI_box_systole_delay_cervical->setValue(QString::fromStdString(arterial_cervical_list[1]).toDouble());
            do_MRI_systole_detect_cervical();

            MRI_box_arterial_move_cervical->setValue(QString::fromStdString(arterial_cervical_list[2]).toInt());
        }
        if (venous_cervical_tune){
            MRI_box_venous_move_cervical->setValue(QString::fromStdString(venous_cervical_list[0]).toInt());
        }
        if (csf_cervical_tune){
            MRI_box_csf_move_cervical->setValue(QString::fromStdString(csf_cervical_list[0]).toInt());
        }
        if (arterial_cervical_tune && venous_cervical_tune && csf_cervical_tune){
            do_MRI_AV_auto_cervical();
            do_MRI_ICVC_auto_cervical();
        }

        if (arterial_cerebral_tune){
            MRI_box_systole_threshold_cerebral->setValue(QString::fromStdString(arterial_cerebral_list[0]).toDouble());
            MRI_box_systole_delay_cerebral->setValue(QString::fromStdString(arterial_cerebral_list[1]).toDouble());
            do_MRI_systole_detect_cerebral();

            MRI_box_arterial_move_cerebral->setValue(QString::fromStdString(arterial_cerebral_list[2]).toInt());
        }
        if (venous_cerebral_tune){
            MRI_box_venous_move_cerebral->setValue(QString::fromStdString(venous_cerebral_list[0]).toInt());
        }
        if (csf_cerebral_tune){
            MRI_box_csf_move_cerebral->setValue(QString::fromStdString(csf_cerebral_list[0]).toInt());
        }
        if (arterial_cerebral_tune && venous_cerebral_tune && csf_cerebral_tune){
            do_MRI_AV_auto_cerebral();
            do_MRI_ICVC_auto_cerebral();
        }

        if (ICP_tune){
            ICP_min_signal = QString::fromStdString(ICP_list[5]).toDouble();
            ICP_box_min_signal->setRange(0., ICP_coord_signal->coord(ICP_coord_signal->size()-1, XCOORD));
            ICP_box_min_signal->setValue(ICP_min_signal);
            ICP_slider_min_signal->setRange(0., ICP_coord_signal->coord(ICP_coord_signal->size()-1, XCOORD)*SLIDER_DOUBLE);
            ICP_slider_min_signal->setValue(ICP_min_signal*SLIDER_DOUBLE);

            ICP_max_signal = QString::fromStdString(ICP_list[6]).toDouble();
            ICP_box_max_signal->setRange(0., ICP_coord_signal->coord(ICP_coord_signal->size()-1, XCOORD));
            ICP_box_max_signal->setValue(ICP_max_signal);
            ICP_slider_max_signal->setRange(0., ICP_coord_signal->coord(ICP_coord_signal->size()-1, XCOORD)*SLIDER_DOUBLE);
            ICP_slider_max_signal->setValue(ICP_max_signal*SLIDER_DOUBLE);

            do_ICP_fourier();

            ICP_box_min_ifft->setValue(QString::fromStdString(ICP_list[7]).toInt());
            ICP_box_max_ifft->setValue(QString::fromStdString(ICP_list[8]).toInt());

            do_ICP_ifft();

            ICP_box_threshold->setValue(QString::fromStdString(ICP_list[9]).toDouble());

            do_ICP_peaks();
            do_ICP_mean();
        }

        //Box
        {
            MRI_box_systole_delay_cervical->setRange(1, npi);
            MRI_box_systole_delay_cervical->setValue((int)max(MRI_EPI_coeff_systole_delay*npi, 1.));
            double *range = test_detect_systole(*MRI_coord_arterial_cervical, MRI_EPI_coeff_systole_delay*npi);
            MRI_box_systole_threshold_cervical->setRange(range[0], range[1]);
            MRI_box_systole_threshold_cervical->setValue(range[1]*MRI_EPI_coeff_systole_threshold);
        }

        //Box
        {
            MRI_box_systole_delay_cerebral->setRange(0., npi);
            MRI_box_systole_delay_cerebral->setValue((int)max(MRI_EPI_coeff_systole_delay*npi, 1.));
            double *range = test_detect_systole(*MRI_coord_arterial_cerebral, MRI_EPI_coeff_systole_delay*npi);
            MRI_box_systole_threshold_cerebral->setRange(range[0], range[1]);
            MRI_box_systole_threshold_cerebral->setValue(range[1]*MRI_EPI_coeff_systole_threshold);
        }

        plot_MRI_cervical_cerebral();
        plot_MRI_spectrum();
    }
}

/*!
 * \brief MainWindow::new_patient
 */
void MainWindow::new_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    DialogNew *dialog = new DialogNew(this);
    dialog->exec();
    delete dialog;
}

/*!
 * \brief MainWindow::modify_patient
 */
void MainWindow::modify_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){
        DialogModify *dialog = new DialogModify(current_dir,
                                                MRI_coord_arterial_cervical, MRI_coord_venous_cervical, MRI_coord_csf_cervical,
                                                MRI_coord_arterial_cerebral, MRI_coord_venous_cerebral, MRI_coord_csf_cerebral,
                                                MRI_coords_arterial_other, MRI_coords_venous_other, MRI_coords_csf_other,
                                                this);
        int res = dialog->exec();
        if (res == QDialog::Accepted){
            cout << "ok" << endl;
            plot_MRI_cervical();
            plot_MRI_cerebral();
            plot_MRI_others();
        }
        delete dialog;
    }
}

/*!
 * \brief MainWindow::delete_patient
 */
void MainWindow::delete_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    DialogDelete *dialog = new DialogDelete(this);
    int res = dialog->exec();
    if (res == QDialog::Accepted){
        //
    }
    delete dialog;
}

/*!
 * \brief MainWindow::status_error
 * \param txt
 *
 * Display txt in the statusbar, with red cross
 */
void MainWindow::status_error(QString txt){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_statusbar_txt->setText(txt);
    label_statusbar_img->setPixmap(QPixmap(IMG_STATUSBAR_RED).scaled(IMG_STATUSBAR_SIZE, IMG_STATUSBAR_SIZE));
}

/*!
 * \brief MainWindow::status_info
 * \param txt
 *
 * Display txt in the statusbar, with green OK
 */
void MainWindow::status_info(QString txt){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    cout << txt.toStdString() << endl;
    label_statusbar_txt->setText(txt);
    label_statusbar_img->setPixmap(QPixmap(IMG_STATUSBAR_GREEN).scaled(IMG_STATUSBAR_SIZE, IMG_STATUSBAR_SIZE));
}

/*!
 * \brief MainWindow::save_all
 */
void MainWindow::save_all(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    save_MRI();
    save_ICP();
    save_EPI();
}

/*!
 * \brief MainWindow::clear_all
 */
void MainWindow::clear_all(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    label_patient_name->clear();

    clear_MRI();
    clear_ICP();
    clear_EPI();
}

/*!
 * \brief MainWindow::hide_ICP
 *
 * Hide the ICP grid
 */
void MainWindow::hide_ICP(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_ICP->setEnabled(true);
    action_hide_ICP->setEnabled(false);

    //Tab
    ICP_tab->setHidden(true);

    //Widget
    ICP_tab_widget->setHidden(true);

    //Grid
    grid->removeWidget(label_space1);
    grid->removeWidget(label_space2);
    grid->removeWidget(ICP_tab);

    if (action_hide_MRI->isEnabled() && action_hide_EPI->isEnabled()){
        label_space2->setHidden(true);

        grid->removeWidget(MRI_tab);
        grid->removeWidget(EPI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (action_hide_MRI->isEnabled() && !action_hide_EPI->isEnabled()){
        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->removeWidget(MRI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_MRI->isEnabled() && action_hide_EPI->isEnabled()){
        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->removeWidget(EPI_tab);

        grid->addWidget(EPI_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_MRI->isEnabled() && !action_hide_EPI->isEnabled()){
        label_space1->setHidden(true);
        label_space2->setHidden(true);
    }
}

/*!
 * \brief MainWindow::restore_ICP
 *
 * Restore the ICP grid
 */
void MainWindow::restore_ICP(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_ICP->setEnabled(false);
    action_hide_ICP->setEnabled(true);

    //Tab
    ICP_tab->setHidden(false);

    //Widget
    ICP_tab_widget->setHidden(false);

    //Grid
    if (action_hide_MRI->isEnabled() && action_hide_EPI->isEnabled()){
        label_space2->setHidden(false);

        grid->removeWidget(label_space1);
        grid->removeWidget(MRI_tab);
        grid->removeWidget(EPI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 100);
        grid->addWidget(label_space1, 2, 100, 100, 1);
        grid->addWidget(ICP_tab, 2, 101, 100, 100);
        grid->addWidget(label_space2, 2, 201, 100, 1);
        grid->addWidget(EPI_tab, 2, 202, 100, 100);
    }
    else if (action_hide_MRI->isEnabled() && !action_hide_EPI->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(MRI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(ICP_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_MRI->isEnabled() && action_hide_EPI->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(EPI_tab);

        grid->addWidget(ICP_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_MRI->isEnabled() && !action_hide_EPI->isEnabled()){
        grid->addWidget(ICP_tab, 2, 0, 100, 300);
    }
}

/*!
 * \brief MainWindow::hide_MRI
 *
 * Hide the MRI grid
 */
void MainWindow::hide_MRI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_MRI->setEnabled(true);
    action_hide_MRI->setEnabled(false);

    //Tab
    MRI_tab->setHidden(true);

    //Widget
    MRI_tab_cervical->setHidden(true);
    MRI_tab_cerebral->setHidden(true);

    //Grid
    grid->removeWidget(label_space1);
    grid->removeWidget(label_space2);
    grid->removeWidget(MRI_tab);

    if (action_hide_ICP->isEnabled() && action_hide_EPI->isEnabled()){
        label_space2->setHidden(true);

        grid->removeWidget(ICP_tab);
        grid->removeWidget(EPI_tab);

        grid->addWidget(ICP_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (action_hide_ICP->isEnabled() && !action_hide_EPI->isEnabled()){
        grid->removeWidget(ICP_tab);

        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->addWidget(ICP_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_ICP->isEnabled() && action_hide_EPI->isEnabled()){
        grid->removeWidget(EPI_tab);

        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->addWidget(EPI_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_ICP->isEnabled() && !action_hide_EPI->isEnabled()){
        label_space1->setHidden(true);
        label_space2->setHidden(true);
    }
}

/*!
 * \brief MainWindow::restore_MRI
 *
 * Restore the MRI grid
 */
void MainWindow::restore_MRI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_MRI->setEnabled(false);
    action_hide_MRI->setEnabled(true);

    //Tab
    MRI_tab->setHidden(false);

    //Widget
    MRI_tab_cervical->setHidden(false);
    MRI_tab_cerebral->setHidden(false);

    //Grid
    if (action_hide_ICP->isEnabled() && action_hide_EPI->isEnabled()){
        label_space2->setHidden(false);

        grid->removeWidget(label_space1);
        grid->removeWidget(ICP_tab);
        grid->removeWidget(EPI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 100);
        grid->addWidget(label_space1, 2, 100, 100, 1);
        grid->addWidget(ICP_tab, 2, 101, 100, 100);
        grid->addWidget(label_space2, 2, 201, 100, 1);
        grid->addWidget(EPI_tab, 2, 202, 100, 100);
    }
    else if (action_hide_ICP->isEnabled() && !action_hide_EPI->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(ICP_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(ICP_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_ICP->isEnabled() && action_hide_EPI->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(EPI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_ICP->isEnabled() && !action_hide_EPI->isEnabled()){
        grid->addWidget(MRI_tab, 2, 0, 100, 300);
    }
}

/*!
 * \brief MainWindow::hide_EPI
 */
void MainWindow::hide_EPI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_EPI->setEnabled(true);
    action_hide_EPI->setEnabled(false);

    //Tab
    EPI_tab->setHidden(true);

    //Widget
    EPI_tab_widget->setHidden(true);

    //Grid
    grid->removeWidget(label_space1);
    grid->removeWidget(label_space2);
    grid->removeWidget(EPI_tab);

    if (action_hide_MRI->isEnabled() && action_hide_ICP->isEnabled()){
        label_space2->setHidden(true);

        grid->removeWidget(MRI_tab);
        grid->removeWidget(ICP_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(ICP_tab, 2, 151, 100, 149);
    }
    else if (action_hide_MRI->isEnabled() && !action_hide_ICP->isEnabled()){
        grid->removeWidget(MRI_tab);

        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->addWidget(MRI_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_MRI->isEnabled() && action_hide_ICP->isEnabled()){
        grid->removeWidget(ICP_tab);

        label_space1->setHidden(true);
        label_space2->setHidden(true);

        grid->addWidget(ICP_tab, 2, 0, 100, 300);
    }
    else if (!action_hide_MRI->isEnabled() && !action_hide_ICP->isEnabled()){
        label_space1->setHidden(true);
        label_space2->setHidden(true);
    }
}

/*!
 * \brief MainWindow::restore_EPI
 */
void MainWindow::restore_EPI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    action_restore_EPI->setEnabled(false);
    action_hide_EPI->setEnabled(true);

    //Tab
    EPI_tab->setHidden(false);

    //Widget
    EPI_tab_widget->setHidden(false);

    //Grid
    if (action_hide_MRI->isEnabled() && action_hide_ICP->isEnabled()){
        label_space2->setHidden(false);

        grid->removeWidget(label_space1);
        grid->removeWidget(MRI_tab);
        grid->removeWidget(ICP_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 100);
        grid->addWidget(label_space1, 2, 100, 100, 1);
        grid->addWidget(ICP_tab, 2, 101, 100, 100);
        grid->addWidget(label_space2, 2, 201, 100, 1);
        grid->addWidget(EPI_tab, 2, 202, 100, 100);
    }
    else if (action_hide_MRI->isEnabled() && !action_hide_ICP->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(MRI_tab);

        grid->addWidget(MRI_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_MRI->isEnabled() && action_hide_ICP->isEnabled()){
        label_space1->setHidden(false);

        grid->removeWidget(ICP_tab);

        grid->addWidget(ICP_tab, 2, 0, 100, 149);
        grid->addWidget(label_space1, 2, 149, 100, 2);
        grid->addWidget(EPI_tab, 2, 151, 100, 149);
    }
    else if (!action_hide_MRI->isEnabled() && !action_hide_ICP->isEnabled()){
        grid->addWidget(EPI_tab, 2, 0, 100, 300);
    }
}

/*!
 * \brief MainWindow::closeEvent
 */
void MainWindow::closeEvent(QCloseEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;
}

/*!
 * \brief MainWindow::resizeEvent
 */
void MainWindow::resizeEvent(QResizeEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;
}


void MainWindow::export_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){
        QStringList patient_list;
        QStringList data_list;

        QString patient_name = QString(current_dir);
        int pos = patient_name.indexOf(DIR_SEPARATOR);
        while (pos != -1){
            patient_name.remove(0, pos+1);
            pos = patient_name.indexOf(DIR_SEPARATOR);
        }

        int pos_aqueduc = -1;
        int pos_v3stomie = -1;
        int pos_v4 = -1;
        int pos_c2c3 = -1;
        int pos_citerprep = -1;
        for (int i = 0; i < MRI_csf_files_other->count(); i++){
            if (MRI_csf_files_other->at(i).compare("aqueduc.txt") == 0){
                pos_aqueduc = i;
            }
            if (MRI_csf_files_other->at(i).compare("v3_stomi.txt") == 0){
                pos_v3stomie = i;
            }
            if (MRI_csf_files_other->at(i).compare("v4.txt") == 0){
                pos_v4 = i;
            }
            if (MRI_csf_files_other->at(i).compare("c2_c3.txt") == 0){
                pos_c2c3 = i;
            }
            if (MRI_csf_files_other->at(i).compare("citer-prep.txt") == 0){
                pos_citerprep = i;
            }
        }

        patient_name.remove(exam_number);
        patient_name.remove(patient_date);
        patient_name.replace("_", " ");

        patient_list.append(patient_name);
        patient_list.append(exam_date);
        patient_list.append(patient_date);
        patient_list.append(patient_age);

        if (pos_aqueduc != -1){
            double sv = stroke_volume_csf(*MRI_coords_csf_other[pos_aqueduc]);
            data_list.append(QString::number(sv));
        }
        else{
            data_list.append("");
        }
        if (pos_v3stomie != -1){
            double sv = stroke_volume_csf(*MRI_coords_csf_other[pos_v3stomie]);
            data_list.append(QString::number(sv));
        }
        else{
            data_list.append("");
        }
        if (pos_v4  != -1){
            double sv = stroke_volume_csf(*MRI_coords_csf_other[pos_v4]);
            data_list.append(QString::number(sv));
        }
        else{
            data_list.append("");
        }
        if (pos_c2c3 != -1){
            double sv = stroke_volume_csf(*MRI_coords_csf_other[pos_c2c3]);
            data_list.append(QString::number(sv));
        }
        else{
            data_list.append("");
        }
        if (pos_citerprep != -1){
            double sv = stroke_volume_csf(*MRI_coords_csf_other[pos_citerprep]);
            data_list.append(QString::number(sv));
        }
        else{
            data_list.append("");
        }
        {
            QVector<double> *arterial = Coord2QVector(MRI_coord_arterial_cerebral);

            unity_convert_flow(arterial, UNITY_ML_MIN, UNITY_MIN);
            double mean_arterial = mean(arterial[1]);
            data_list.append(QString::number(mean_arterial));
        }
        {
            QVector<double> *arterial = Coord2QVector(MRI_coord_arterial_cervical);

            unity_convert_flow(arterial, UNITY_ML_MIN, UNITY_MIN);
            double mean_arterial = mean(arterial[1]);
            data_list.append(QString::number(mean_arterial));
        }
        {
            double sv = stroke_volume(*MRI_coord_AV_flow_cerebral);
            data_list.append(QString::number(sv));
        }
        {
            double sv = stroke_volume(*MRI_coord_AV_flow_cervical);
            data_list.append(QString::number(sv));
        }
        {
            double sv = stroke_volume(*MRI_coord_ICVC_flow_cerebral);
            data_list.append(QString::number(sv));
        }
        {
            double sv = stroke_volume(*MRI_coord_ICVC_flow_cervical);
            data_list.append(QString::number(sv));
        }

        bool res = save_rtf(current_dir + DIR_SEPARATOR + "report.rtf", patient_list, data_list);

        if (!res){
            QMessageBox::critical(this, "", "");
        }
    }
}

void MainWindow::update_tab(int pos){
    if (pos == 0){
        plot_MRI_cervical();
    }
    else if (pos == 1){
        plot_MRI_cerebral();
    }
    else if (pos == 2){
        plot_MRI_cervical_cerebral();
    }
    else if (pos == 3){
        plot_MRI_spectrum();
    }
}
