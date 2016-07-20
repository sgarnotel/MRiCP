#include "mainwindow.h"


/*!
 * \brief MainWindow::init_STAT_var
 *
 * Initialisation of MainWindow (STAT part) variables
 */
void MainWindow::init_STAT_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Actions
    action_stats = new QAction(QIcon(IMG_STATISTICS), MAINWINDOW_ACTION_STATS, this);

    //ToolBar
    toolbar_stats = new QToolBar(MAINWINDOW_STATS_TOOLBAR);

    //Labels
    label_stats = new QLabel(this);
}

/*!
 * \brief MainWindow::init_STAT_win
 *
 * Initialisation of MainWindow (STAT part) window
 */
void MainWindow::init_STAT_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Toolbar
    toolbar_stats->addWidget(label_stats);
    toolbar_stats->addAction(action_stats);
    toolbar_stats->addSeparator();
    toolbar_stats->setMovable(false);
    toolbar_stats->setIconSize(QSize(IMG_TOOLBAR_SIZE, IMG_TOOLBAR_SIZE));
    addToolBar(Qt::TopToolBarArea, toolbar_stats);

    //Labels
    label_stats->setText(MAINWINDOW_STATS);
}

/*!
 * \brief MainWindow::init_STAT_sig
 *
 * Initialisation of MainWindow (STAT part) signals
 */
void MainWindow::init_STAT_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(action_stats, SIGNAL(triggered()), this, SLOT(stats()));
}

/*!
 * \brief MainWindow::init_STAT_css
 *
 * Initialisation of MainWindow (STAT part) style sheet
 */
void MainWindow::init_STAT_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Toolbar
    toolbar_stats->setStyleSheet(CSS_TOOLBAR);

    //Labels
    label_stats->setStyleSheet(CSS_LABEL_GLOBAL);
}

/*!
 * \brief MainWindow::stats
 *
 * Launch DialogStats
 */
void MainWindow::stats(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    DialogStats *dialog = new DialogStats;
    dialog->show();

    //dialog->deleteLater();
}


