#include "mainwindow.h"

/*!
 * \brief MainWindow::do_user_help
 *
 * Open the User help (PDF document)
 *
 * LINUX/MAC/WINDOWS
 */
void MainWindow::do_user_help(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

#ifdef LINUX_OS
    QString command = "evince " + QString(DOC_DIR) + "Flow_eXplorer.pdf &";
#endif
#ifdef MAC_OS
    QString command = "open " + QString(DOC_DIR) + "Flow_eXplorer.pdf &";
#endif
#ifdef WIN_OS
    QString command = "start " + QString(DOC_DIR) + "Flow_eXplorer.pdf &";
#endif
    int res = system(command.toStdString().c_str());
    if (res){
        status_error(HELP_ERROR_001);
    }
}

/*!
 * \brief MainWindow::do_programmer_help
 *
 * Open the programmer help (Doxygen html page)
 *
 * LINUX/MAC/WINDOWS
 */
void MainWindow::do_programmer_help(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

#ifdef LINUX_OS
    #ifdef FR
        QString command = "xdg-open " + QString(DOC_DIR) + "French/html/index.html";
    #else
        #ifdef EN
            QString command = "xdg-open " + QString(DOC_DIR) + "English/html/index.html";
        #endif
    #endif
#endif
#ifdef MAC_OS
    #ifdef FR
        QString command = "open " + QString(DOC_DIR) + "French/html/index.html";
    #else
        #ifdef EN
            QString command = "open " + QString(DOC_DIR) + "English/html/index.html";
        #endif
    #endif
#endif
#ifdef WIN_OS
    #ifdef FR
        QString command = "xdg-open " + QString(DOC_DIR) + "French/html/index.html";    //TODO win command
    #else
        #ifdef EN
            QString command = "xdg-open " + QString(DOC_DIR) + "English/html/index.html";   //TODO win command
        #endif
    #endif
#endif
    int res = system(command.toStdString().c_str());
    if (res){
        status_error(HELP_ERROR_002);
    }
}

/*!
 * \brief MainWindow::do_about
 */
void MainWindow::do_about(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    DialogAbout *dialog = new DialogAbout(this);
    dialog->exec();
}


