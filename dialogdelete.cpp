#include "dialogdelete.h"

/*!
 * \brief DialogDelete::init_var
 *
 * Initilisation of DialogDelete variables
 */
void DialogDelete::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    //List
    patient_list = new QListWidget(this);

    //Button
    button_load = new QPushButton(this);
    button_delete = new QPushButton(this);
    button_quit = new QPushButton(this);

    //String
    dir = EMPTY_STRING;
}

/*!
 * \brief DialogDelete::init_win
 *
 * Initialisation of DialogDelete window
 */
void DialogDelete::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Window
    setWindowTitle(DIALOG_DELETE_TITLE);

    //Button
    button_load->setText(DIALOG_DELETE_LOAD);
    button_delete->setText(DIALOG_DELETE_DELETE);
    button_quit->setText(DIALOG_DELETE_QUIT);

    //List
    patient_list->setSelectionMode(QAbstractItemView::MultiSelection);

    //Grid
    setLayout(grid);

    grid->addWidget(button_load);
    grid->addWidget(patient_list);
    grid->addWidget(button_delete);
    grid->addWidget(button_quit);
}

/*!
 * \brief DialogDelete::init_sig
 *
 * Initialisation of DialogDelete signals
 */
void DialogDelete::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(button_load, SIGNAL(clicked()), this, SLOT(load_patients()));
    connect(button_delete, SIGNAL(clicked()), this, SLOT(delete_patient()));
    connect(button_quit, SIGNAL(clicked()), this, SLOT(quit()));
}

/*!
 * \brief DialogDelete::init_css
 *
 * Initialisation of DialogDelete style sheet
 */
void DialogDelete::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    setStyleSheet(CSS_DIALOG);

    //Button
    button_load->setStyleSheet(CSS_BUTTON);
    button_delete->setStyleSheet(CSS_BUTTON);
    button_quit->setStyleSheet(CSS_BUTTON);
}

/*!
 * \brief DialogDelete::DialogDelete
 * \param parent
 *
 * DialogDelete
 */
DialogDelete::DialogDelete(QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();
}

/*!
 * \brief DialogDelete::load_patients
 *
 * Load patients's list
 *
 * This function is only for connect to button_load. Refer to load_patients(QString dir_tmp)
 */
void DialogDelete::load_patients(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    load_patients(EMPTY_STRING);
}

/*!
 * \brief DialogDelete::load_patients
 * \param dir_tmp Patients' directory
 *
 * Load patients' list
 *
 * LINUX/MACOS/WINDOWS
 */
void DialogDelete::load_patients(QString dir_tmp){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (dir_tmp.isEmpty()){
        dir_tmp = QFileDialog::getExistingDirectory(this, DIALOG_DELETE_PATIENT_TXT, GLOBAL_DIR);
    }

    if (!dir_tmp.isEmpty()){
        dir = QString(dir_tmp);
        //Count and check
#ifdef LINUX_OS
        QString command = "ls " + dir + " > " + QString(SYSTEM_DIR) + QString(DIALOG_DELETE_PATIENT_FILE);
#endif
#ifdef MAC_OS
        QString command = "ls " + dir + " > " + QString(SYSTEM_DIR) + QString(DIALOG_DELETE_PATIENT_FILE);
#endif
#ifdef WIN_OS
        dir.replace(UNIX_DIR_SEPARATOR, WINDOWS_DIR_SEPARATOR);
        QString command = "dir /B /A:D " + dir + " > " + QString(SYSTEM_DIR) + QString(DIALOG_DELETE_PATIENT_FILE);
#endif

        int res = system(command.toStdString().c_str());

        if (res){
            QMessageBox::critical(this, DELETE_ERROR_001_N, DELETE_ERROR_001);
        }

        QFile file(QString(SYSTEM_DIR) + QString(DIALOG_DELETE_PATIENT_FILE));
        if (file.open(QIODevice::ReadOnly)){
            while(!file.atEnd()){
                QString tmp = file.readLine();
                tmp.remove(UNIX_NEW_LINE).remove(WINDOWS_NEW_LINE);
                if (!tmp.contains(CSV_EXTENSION)){
                    patient_list->addItem(tmp);
                }
            }
            file.close();
        }
        else{
            QMessageBox::critical(this, DELETE_ERROR_001_N, DELETE_ERROR_001);
        }
    }
}

/*!
 * \brief DialogDelete::delete_patient
 *
 * Delete selected patient(s)
 *
 * LINUX/MACOS/WINDOWS
 */
void DialogDelete::delete_patient(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = patient_list->count();
    for (int i = 0; i < n; i++){
        if (patient_list->item(i)->isSelected()){
#ifdef LINUX_OS
            QString command = "rm -r " + dir + DIR_SEPARATOR + patient_list->item(i)->text();
#endif
#ifdef MAC_OS
            QString command = "rm -r " + dir + DIR_SEPARATOR + patient_list->item(i)->text();
#endif
#ifdef WIN_OS
            QString command = "rmdir /S /Q " + dir + DIR_SEPARATOR + patient_list->item(i)->text();
#endif

            int res = system(command.toStdString().c_str());

            if (res){
                QMessageBox::critical(this, DELETE_ERROR_002_N, DELETE_ERROR_002);
            }
        }
    }

    update();
}

/*!
 * \brief DialogDelete::update
 *
 * Update patients' list
 */
void DialogDelete::update(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    patient_list->clear();

    load_patients(dir);
}

/*!
 * \brief DialogDelete::quit
 *
 * Quit DialogDelete
 */
void DialogDelete::quit(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    accept();
}

/*!
 * \brief DialogDelete::closeEvent
 *
 * REIMPLEMENTED Quit DialogDelete by red-cross click
 */
void DialogDelete::closeEvent(QCloseEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;
}


