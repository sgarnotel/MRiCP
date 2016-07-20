#include "mainwindow.h"

/*!
 * \brief MainWindow::init_COMP_var
 *
 * Initialisation of MainWindow (COMP part) variables
 */
void MainWindow::init_COMP_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Actions
    action_compare = new QAction(QIcon(IMG_COMPARE), MAINWINDOW_ACTION_COMPARE, this);

    //ToolBar
    toolbar_compare = new QToolBar(MAINWINDOW_COMPARE_TOOLBAR);

    //Labels
    label_compare = new QLabel(this);
}

/*!
 * \brief MainWindow::init_COMP_win
 *
 * Initialisation of MainWindow (COMP part) window
 */
void MainWindow::init_COMP_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //ToolBar
    toolbar_compare->addWidget(label_compare);
    toolbar_compare->addAction(action_compare);
    toolbar_compare->addSeparator();
    toolbar_compare->setMovable(false);
    toolbar_compare->setIconSize(QSize(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));
    addToolBar(Qt::TopToolBarArea, toolbar_compare);

    //Labels
    label_compare->setText(MAINWINDOW_COMPARE);
}

/*!
 * \brief MainWindow::init_COMP_sig
 *
 * Initialisation of MainWindow (COMP part) signals
 */
void MainWindow::init_COMP_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(action_compare, SIGNAL(triggered()), this, SLOT(compare()));
}

/*!
 * \brief MainWindow::init_COMP_css
 *
 * Initialisation of MainWindow (COMP part) style sheet
 */
void MainWindow::init_COMP_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Toolbar
    toolbar_compare->setStyleSheet(CSS_TOOLBAR);

    //labels
    label_compare->setStyleSheet(CSS_LABEL_GLOBAL);
}

/*!
 * \brief MainWindow::compare
 *
 * Launch DialogCOmpare with a selected curve
 */
void MainWindow::compare(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = MRI_coord_AV_volume_cervical->size();
    int n2 = MRI_coord_AV_volume_cerebral->size();
    int n3 = MRI_coord_ICVC_volume_cervical->size();
    int n4 = MRI_coord_ICVC_volume_cerebral->size();

    QStringList item_list;
    if (n1 > 0) item_list.append(MAINWINDOW_COMPARE_AV_CERV);
    if (n2 > 0) item_list.append(MAINWINDOW_COMPARE_ICVC_CERV);
    if (n3 > 0) item_list.append(MAINWINDOW_COMPARE_AV_CERE);
    if (n4 > 0) item_list.append(MAINWINDOW_COMPARE_ICVC_CERE);

    if (item_list.size() > 0){
        bool res;
        QString type = QInputDialog::getItem(this, MAINWINDOW_COMPARE_CHOOSE, MAINWINDOW_COMPARE_SELECT, item_list, 0, false, &res);
        if (res){
            int n = ICP_coord_mean->size();
            if (n > 0){
                if (type.compare(MAINWINDOW_COMPARE_AV_CERV) == 0){
                    if (n1 > 0 && n1 == n){
                        status_info(MAINWINDOW_COMPARE_OK);

                        DialogCompare dialog(current_dir, MAINWINDOW_COMPARE_AV_CERV, MRI_coord_AV_volume_cervical, ICP_coord_mean);
                        dialog.exec();
                    }
                    else{
                        status_error(COMPARE_ERROR_004);
                    }
                }
                else if (type.compare(MAINWINDOW_COMPARE_ICVC_CERV) == 0){
                    if (n2 > 0 && n2 == n){
                        status_info(MAINWINDOW_COMPARE_OK);

                        DialogCompare dialog(current_dir, MAINWINDOW_COMPARE_ICVC_CERV, MRI_coord_ICVC_volume_cervical, ICP_coord_mean);
                        dialog.exec();
                    }
                    else{
                        status_error(COMPARE_ERROR_004);
                    }
                }
                else if (type.compare(MAINWINDOW_COMPARE_AV_CERE) == 0){
                    if (n3 > 0 && n3 == n){
                        status_info(MAINWINDOW_COMPARE_OK);

                        DialogCompare dialog(current_dir, MAINWINDOW_COMPARE_AV_CERE, MRI_coord_AV_volume_cerebral, ICP_coord_mean);
                        dialog.exec();
                    }
                    else{
                        status_error(COMPARE_ERROR_004);
                    }
                }
                else if (type.compare(MAINWINDOW_COMPARE_ICVC_CERE) == 0){
                    if (n4 > 0 && n4 == n){
                        status_info(MAINWINDOW_COMPARE_OK);

                        DialogCompare dialog(current_dir, MAINWINDOW_COMPARE_ICVC_CERE, MRI_coord_ICVC_volume_cerebral, ICP_coord_mean);
                        dialog.exec();
                    }
                    else{
                        status_error(COMPARE_ERROR_004);
                    }
                }
                else{
                    status_error(COMPARE_ERROR_004);
                }
            }
            else{
                status_error(COMPARE_ERROR_003);
            }
        }
        else{
            status_error(COMPARE_ERROR_002);
        }
    }
    else{
        status_error(COMPARE_ERROR_001);
    }
}


