#include "mainwindow.h"


/*!
 * \brief MainWindow::init_EPI_var
 *
 * Initialisation of MainWindow (EPI part) variables
 */
void MainWindow::init_EPI_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    EPI_tab = new QTabWidget(this);

    //Widget
    EPI_tab_widget = new QWidget(this);

    //Grid
    EPI_grid = new QGridLayout;

    EPI_grid_header = new QGridLayout;
    EPI_grid_signal = new QGridLayout;
    EPI_grid_fourier = new QGridLayout;
    EPI_grid_ifft = new QGridLayout;
    EPI_grid_peaks = new QGridLayout;
    EPI_grid_labels = new QGridLayout;
    EPI_grid_buttons = new QGridLayout;

    //Menu
    EPI_menu = new QMenu(this);

    //Plots
    EPI_plot_signal = new QCustomPlot;
    EPI_plot_select = new QCustomPlot;
    EPI_plot_fourier = new QCustomPlot;
    EPI_plot_ifft = new QCustomPlot;
    EPI_plot_mean = new QCustomPlot;

    //Sliders
    EPI_slider_min_signal = new QSlider(this);
    EPI_slider_max_signal = new QSlider(this);
    EPI_slider_min_fourier = new QSlider(this);
    EPI_slider_max_fourier = new QSlider(this);
    EPI_slider_min_ifft = new QSlider(this);
    EPI_slider_max_ifft = new QSlider(this);
    EPI_slider_threshold = new QSlider(this);

    //Boxes
    EPI_box_select_signal = new QComboBox(this);
    EPI_box_quality = new QComboBox(this);
    EPI_box_min_signal = new QDoubleSpinBox(this);
    EPI_box_max_signal = new QDoubleSpinBox(this);
    EPI_box_min_fourier = new QSpinBox(this);
    EPI_box_max_fourier = new QSpinBox(this);
    EPI_box_min_ifft = new QSpinBox(this);
    EPI_box_max_ifft = new QSpinBox(this);
    EPI_box_threshold = new QDoubleSpinBox(this);
    EPI_box_adjust = new QComboBox(this);

    //Buttons
    EPI_button_fourier = new QPushButton(this);
    EPI_button_ifft = new QPushButton(this);
    EPI_button_peaks = new QPushButton(this);
    EPI_button_mean = new QPushButton(this);
    EPI_button_adjust = new QPushButton(this);
    EPI_button_normalize = new QPushButton(this);
    EPI_button_save = new QPushButton(this);

    //Labels
    EPI_label_cycle = new QLabel(this);
    EPI_label_heartrate = new QLabel(this);
    EPI_label_min = new QLabel(this);
    EPI_label_max = new QLabel(this);
    EPI_label_mean = new QLabel(this);
    EPI_label_gradient = new QLabel(this);

    //String
    EPI_arterial_files_cervical = new QStringList;
    EPI_venous_files_cervical = new QStringList;
    EPI_CSF_files_cervical = new QStringList;
    EPI_arterial_files_cerebral = new QStringList;
    EPI_venous_files_cerebral = new QStringList;
    EPI_CSF_files_cerebral = new QStringList;
    EPI_arterial_files_other = new QStringList;
    EPI_venous_files_other = new QStringList;
    EPI_csf_files_other = new QStringList;

    //Int
    EPI_current_pos = -1;

    EPI_min_fourier = 0;
    EPI_max_fourier = 0;
    EPI_min_ifft = 0;
    EPI_max_ifft = 0;

    EPI_number_arterial = 0;
    EPI_number_venous = 0;
    EPI_number_csf = 0;

    EPI_quality_arterial_cervical = QUALITY5;
    EPI_quality_venous_cervical = QUALITY5;
    EPI_quality_csf_cervical = QUALITY5;
    EPI_quality_arterial_cerebral = QUALITY5;
    EPI_quality_venous_cerebral = QUALITY5;
    EPI_quality_csf_cerebral = QUALITY5;

    EPI_quality_arterial_other = NULL;
    EPI_quality_venous_other = NULL;
    EPI_quality_csf_other = NULL;

    EPI_quality = NULL;

    //Double
    EPI_min_signal = 0.;
    EPI_max_signal = 0.;
    EPI_threshold = 0.;

    //Coord
    /*EPI_coord_arterial_cervical = new Coord;
    EPI_coord_arterial_cerebral = new Coord;
    EPI_coord_venous_cervical = new Coord;
    EPI_coord_venous_cerebral = new Coord;
    EPI_coord_csf_cervical = new Coord;
    EPI_coord_csf_cerebral = new Coord;*/
    EPI_coord_select = new Coord;
    EPI_coord_fourier = new Coord;
    EPI_coord_ifft = new Coord;
    EPI_coord_peaks = new Coord;
    EPI_coord_mean = new Coord;
    EPI_coord_SD = new Coord;
}

/*!
 * \brief MainWindow::init_EPI_win
 *
 * Initialisation of MainWindow (EPI part) window
 */
void MainWindow::init_EPI_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Buttons
    EPI_button_fourier->setText(MAINWINDOW_EPI_FOURIER);
    EPI_button_ifft->setText(MAINWINDOW_EPI_IFFT);
    EPI_button_peaks->setText(MAINWINDOW_EPI_PEAKS);
    EPI_button_mean->setText(MAINWINDOW_EPI_MEAN);

    EPI_button_adjust->setIcon(QIcon(IMG_ADJUST));
    EPI_button_adjust->setIconSize(QSize(20, 20));
    EPI_button_adjust->setToolTip(MAINWINDOW_EPI_ADJUST);
    EPI_button_normalize->setIcon(QIcon(IMG_NORMALIZE));
    EPI_button_normalize->setIconSize(QSize(20, 20));
    EPI_button_normalize->setToolTip(MAINWINDOW_EPI_NORMALIZE);
    EPI_button_save->setIcon(QIcon(IMG_SAVE));
    EPI_button_save->setIconSize(QSize(20, 20));
    EPI_button_save->setToolTip(MAINWINDOW_EPI_SAVE);

    //Boxes
    /*EPI_box_quality->addItem(QIcon(IMG_GREEN), "OK");
    EPI_box_quality->addItem(QIcon(IMG_RED), "Bad");
    EPI_box_quality->addItem(QIcon(IMG_BLACK), "Unusable");*/   //TODO
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM1);
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM2);
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM3);
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM4);
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM5);
    EPI_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM6);
#ifdef QT5
    EPI_box_adjust->setCurrentText(MAINWINDOW_ADJUST_ITEM1);
#endif

    //Sliders
    EPI_slider_min_signal->setOrientation(Qt::Horizontal);
    EPI_slider_max_signal->setOrientation(Qt::Horizontal);
    EPI_slider_min_fourier->setOrientation(Qt::Horizontal);
    EPI_slider_max_fourier->setOrientation(Qt::Horizontal);
    EPI_slider_min_ifft->setOrientation(Qt::Horizontal);
    EPI_slider_max_ifft->setOrientation(Qt::Horizontal);
    EPI_slider_threshold->setOrientation(Qt::Horizontal);

    //Plots
    EPI_plot_signal->addGraph();    //Signal
    EPI_plot_signal->addGraph();    //Min Bound
    EPI_plot_signal->addGraph();    //Max Bound
    EPI_plot_signal->addGraph();    //MinMaxFont
    EPI_plot_signal->addGraph();    //MinMaxFont
    EPI_plot_select->addGraph();    //Select
    EPI_plot_fourier->addGraph();   //Fourier spectrum
    EPI_plot_fourier->addGraph();   //IFFT min
    EPI_plot_fourier->addGraph();   //IFFT max
    EPI_plot_fourier->addGraph();   //MinMaxFont
    EPI_plot_ifft->addGraph();      //IFFT
    EPI_plot_ifft->addGraph();      //Threshold
    EPI_plot_ifft->addGraph();      //Peaks
    EPI_plot_mean->addGraph();      //Mean

    //Grid
    EPI_grid_signal->addWidget(EPI_box_select_signal, 0, 0, 1, 2);
    EPI_grid_signal->addWidget(EPI_box_min_signal, 1, 0, 1, 1);
    EPI_grid_signal->addWidget(EPI_box_max_signal, 1, 1, 1, 1);
    EPI_grid_signal->addWidget(EPI_slider_min_signal, 2, 0, 1, 1);
    EPI_grid_signal->addWidget(EPI_slider_max_signal, 2, 1, 1, 1);
    EPI_grid_signal->addWidget(EPI_box_quality, 1, 2, 2, 1);

    EPI_grid_fourier->addWidget(EPI_button_fourier, 0, 0, 2, 1);
    EPI_grid_fourier->addWidget(EPI_box_min_fourier, 0, 1, 1, 1);
    EPI_grid_fourier->addWidget(EPI_box_max_fourier, 0, 2, 1, 1);
    EPI_grid_fourier->addWidget(EPI_slider_min_fourier, 1, 1, 1, 1);
    EPI_grid_fourier->addWidget(EPI_slider_max_fourier, 1, 2, 1, 1);

    EPI_grid_ifft->addWidget(EPI_box_min_ifft, 0, 0, 1, 1);
    EPI_grid_ifft->addWidget(EPI_box_max_ifft, 0, 1, 1, 1);
    EPI_grid_ifft->addWidget(EPI_slider_min_ifft, 1, 0, 1, 1);
    EPI_grid_ifft->addWidget(EPI_slider_max_ifft, 1, 1, 1, 1);
    EPI_grid_ifft->addWidget(EPI_button_ifft, 0, 2, 2, 1);

    EPI_grid_peaks->addWidget(EPI_box_threshold, 0, 0, 1, 1);
    EPI_grid_peaks->addWidget(EPI_button_peaks, 0, 1, 1, 1);
    EPI_grid_peaks->addWidget(EPI_button_mean, 0, 2, 1, 1);
    EPI_grid_peaks->addWidget(EPI_slider_threshold, 1, 0, 1, 1);

    EPI_grid_labels->addWidget(EPI_label_cycle);
    EPI_grid_labels->addWidget(EPI_label_heartrate);
    EPI_grid_labels->addWidget(EPI_label_min);
    EPI_grid_labels->addWidget(EPI_label_max);
    EPI_grid_labels->addWidget(EPI_label_mean);
    EPI_grid_labels->addWidget(EPI_label_gradient);

    EPI_grid_buttons->addWidget(EPI_button_adjust, 0, 0, 1, 1);
    EPI_grid_buttons->addWidget(EPI_box_adjust, 0, 1, 1, 1);
    EPI_grid_buttons->addWidget(EPI_button_normalize, 0, 2, 1, 1);
    EPI_grid_buttons->addWidget(EPI_button_save, 0, 3, 1, 1);

    EPI_grid->addLayout(EPI_grid_header, 0, 0, 2, 30);
    EPI_grid->addLayout(EPI_grid_signal, 0, 30, 2, 70);
    EPI_grid->addWidget(EPI_plot_signal, 2, 0, 10, 100);
    EPI_grid->addWidget(EPI_plot_select, 12, 0, 10, 100);
    EPI_grid->addLayout(EPI_grid_fourier, 22, 0, 2, 100);
    EPI_grid->addWidget(EPI_plot_fourier, 24, 0, 10, 100);
    EPI_grid->addLayout(EPI_grid_ifft, 34, 0, 2, 100);
    EPI_grid->addWidget(EPI_plot_ifft, 36, 0, 10, 100);

    EPI_grid->addLayout(EPI_grid_peaks, 46, 0, 2, 100);
    EPI_grid->addLayout(EPI_grid_labels, 48, 0, 10, 1);
    EPI_grid->addWidget(EPI_plot_mean, 48, 1, 10, 99);
    EPI_grid->addLayout(EPI_grid_buttons, 58, 0, 1, 100);

    //Widget
    EPI_tab_widget->setLayout(EPI_grid);

    //Tab
    EPI_tab->addTab(EPI_tab_widget, "EPI -- Beta version");
}

/*!
 * \brief MainWindow::init_EPI_sig
 *
 * Initialisation of MainWindow (EPI part) signals
 */
void MainWindow::init_EPI_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Sliders
    connect(EPI_slider_min_signal, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_min_signal(int)));
    connect(EPI_slider_max_signal, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_max_signal(int)));
    connect(EPI_slider_min_fourier, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_min_fourier(int)));
    connect(EPI_slider_max_fourier, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_max_fourier(int)));
    connect(EPI_slider_min_ifft, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_min_ifft(int)));
    connect(EPI_slider_max_ifft, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_max_ifft(int)));
    connect(EPI_slider_threshold, SIGNAL(valueChanged(int)), this, SLOT(move_EPI_threshold(int)));

    //Boxes
    connect(EPI_box_select_signal, SIGNAL(currentIndexChanged(int)), this, SLOT(plot_EPI_signal_curve(int)));
    connect(EPI_box_min_signal, SIGNAL(valueChanged(double)), this, SLOT(choose_EPI_min_signal(double)));
    connect(EPI_box_max_signal, SIGNAL(valueChanged(double)), this, SLOT(choose_EPI_max_signal(double)));
    connect(EPI_box_min_fourier, SIGNAL(valueChanged(int)), this, SLOT(choose_EPI_min_fourier(int)));
    connect(EPI_box_max_fourier, SIGNAL(valueChanged(int)), this, SLOT(choose_EPI_max_fourier(int)));
    connect(EPI_box_min_ifft, SIGNAL(valueChanged(int)), this, SLOT(choose_EPI_min_ifft(int)));
    connect(EPI_box_max_ifft, SIGNAL(valueChanged(int)), this, SLOT(choose_EPI_max_ifft(int)));
    connect(EPI_box_threshold, SIGNAL(valueChanged(double)), this, SLOT(choose_EPI_threshold(double)));

    //Buttons
    connect(EPI_button_fourier, SIGNAL(clicked()), this, SLOT(do_EPI_fourier()));
    connect(EPI_button_ifft, SIGNAL(clicked()), this, SLOT(do_EPI_ifft()));
    connect(EPI_button_peaks, SIGNAL(clicked()), this, SLOT(do_EPI_peaks()));
    connect(EPI_button_mean, SIGNAL(clicked()), this, SLOT(do_EPI_mean()));
    connect(EPI_button_adjust, SIGNAL(clicked()), this, SLOT(do_EPI_adjust()));
    connect(EPI_button_normalize, SIGNAL(clicked()), this, SLOT(do_EPI_normalize()));
    connect(EPI_button_save, SIGNAL(clicked()), this, SLOT(do_EPI_save()));
}

/*!
 * \brief MainWindow::init_EPI_css
 *
 Initialisation of MainWindow (EPI part) style sheet
 */
void MainWindow::init_EPI_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    EPI_tab->setStyleSheet(CSS_TAB);
#ifdef QT5
    EPI_tab->tabBar()->setStyleSheet(CSS_TABBAR);
    EPI_tab->tabBar()->setFocusPolicy(Qt::NoFocus);
#endif

    //Widget
    EPI_tab_widget->setStyleSheet(CSS_WIDGET);

    //Plots
    EPI_plot_signal->graph(0)->setPen(QPen(Qt::blue));
    EPI_plot_signal->graph(1)->setPen(QPen(Qt::red));
    EPI_plot_signal->graph(2)->setPen(QPen(Qt::red));
    EPI_plot_signal->graph(3)->setPen(QPen(Qt::red));
    EPI_plot_signal->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    EPI_plot_signal->graph(4)->setPen(QPen(Qt::red));
    EPI_plot_signal->graph(4)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    EPI_plot_select->graph(0)->setPen(QPen(Qt::blue));
    EPI_plot_fourier->graph(0)->setPen(QPen(Qt::blue));
    EPI_plot_fourier->graph(0)->setBrush(QBrush(QPixmap(CSS_GRAPH_BRUSH_B)));
    EPI_plot_fourier->graph(1)->setPen(QPen(Qt::red));
    EPI_plot_fourier->graph(2)->setPen(QPen(Qt::red));
    EPI_plot_fourier->graph(3)->setPen(QPen(Qt::red));
    EPI_plot_fourier->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    EPI_plot_ifft->graph(0)->setPen(QPen(Qt::blue));
    EPI_plot_ifft->graph(1)->setPen(QPen(Qt::red));
    EPI_plot_ifft->graph(2)->setPen(QPen(Qt::red));
    EPI_plot_ifft->graph(2)->setLineStyle(QCPGraph::lsNone);
    EPI_plot_ifft->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    EPI_plot_mean->graph(0)->setPen(QPen(Qt::blue));
    EPI_plot_mean->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot));
    EPI_plot_mean->graph(0)->setErrorType(QCPGraph::etValue);

    //Sliders
    EPI_slider_min_signal->setStyleSheet(CSS_SLIDER);
    EPI_slider_max_signal->setStyleSheet(CSS_SLIDER);
    EPI_slider_min_fourier->setStyleSheet(CSS_SLIDER);
    EPI_slider_max_fourier->setStyleSheet(CSS_SLIDER);
    EPI_slider_min_ifft->setStyleSheet(CSS_SLIDER);
    EPI_slider_max_ifft->setStyleSheet(CSS_SLIDER);
    EPI_slider_threshold->setStyleSheet(CSS_SLIDER);

    //Boxes
    EPI_box_quality->setStyleSheet(CSS_COMBOBOX);
    EPI_box_min_signal->setStyleSheet(CSS_DSPINBOX);
    EPI_box_max_signal->setStyleSheet(CSS_DSPINBOX);
    EPI_box_min_fourier->setStyleSheet(CSS_SPINBOX);
    EPI_box_max_fourier->setStyleSheet(CSS_SPINBOX);
    EPI_box_min_ifft->setStyleSheet(CSS_SPINBOX);
    EPI_box_max_ifft->setStyleSheet(CSS_SPINBOX);
    EPI_box_threshold->setStyleSheet(CSS_DSPINBOX);
    EPI_box_adjust->setStyleSheet(CSS_COMBOBOX);

    //Buttons
    EPI_button_fourier->setStyleSheet(CSS_BUTTON);
    EPI_button_ifft->setStyleSheet(CSS_BUTTON);
    EPI_button_peaks->setStyleSheet(CSS_BUTTON);
    EPI_button_mean->setStyleSheet(CSS_BUTTON);
    EPI_button_adjust->setStyleSheet(CSS_BUTTON);
    EPI_button_normalize->setStyleSheet(CSS_BUTTON);
    EPI_button_save->setStyleSheet(CSS_BUTTON);

    //Labels
    EPI_label_cycle->setStyleSheet(CSS_LABEL_GLOBAL);
    EPI_label_heartrate->setStyleSheet(CSS_LABEL_GLOBAL);
    EPI_label_min->setStyleSheet(CSS_LABEL_GLOBAL);
    EPI_label_max->setStyleSheet(CSS_LABEL_GLOBAL);
    EPI_label_mean->setStyleSheet(CSS_LABEL_GLOBAL);
    EPI_label_gradient->setStyleSheet(CSS_LABEL_GLOBAL);
}

//**********//
//***PLOT***//
//**********//
/*!
 * \brief MainWindow::plot_EPI_signal_curve
 * \param pos
 */
void MainWindow::plot_EPI_signal_curve(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    clear_EPI();

    if (EPI_box_select_signal->count() > 0){
        EPI_current_pos = pos;

        //Data
        int n = EPI_coords[pos]->size();

        if (n > 0){
            //Convert Coord to QVector
            QVector<double> x, y;
            for (int i = 0; i < n; i++){
                x.append(EPI_coords[pos]->coord(i, XCOORD));
                y.append(EPI_coords[pos]->coord(i, YCOORD));
            }

            //Plot
            EPI_plot_signal->graph(0)->setData(x, y);
            EPI_plot_signal->xAxis->setRange(min(x), max(x));
            EPI_plot_signal->yAxis->setRange(min(y), max(y));

            EPI_plot_signal->replot();

            //Slider
            double xmin = min(x);
            double xmax = max(x);
            EPI_slider_min_signal->setRange(xmin, xmax);
            EPI_slider_max_signal->setRange(xmin, xmax);

            //Boxes
            EPI_box_min_signal->setRange(xmin, xmax);
            EPI_box_max_signal->setRange(xmin, xmax);
            EPI_box_min_signal->setValue(xmin);
            EPI_box_max_signal->setValue(xmax);
        }
        else{
            status_error("No EPI signal curve to plot");
        }
    }
}

/*!
 * \brief MainWindow::plot_EPI_signal_min
 */
void MainWindow::plot_EPI_signal_min(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = EPI_coords[EPI_current_pos]->size();
    if (n > 0){
        double min_signal = min(EPI_coords[EPI_current_pos]->coords(XCOORD), n);
        double max_signal = max(EPI_coords[EPI_current_pos]->coords(XCOORD), n);

        if (EPI_min_signal >= min_signal && EPI_min_signal <= max_signal && EPI_min_signal < EPI_max_signal){
            //Create QVector
            QVector<double> x, y;
            x.append(EPI_min_signal);
            x.append(EPI_min_signal);
            y.append(EPI_plot_signal->yAxis->range().lower);
            y.append(EPI_plot_signal->yAxis->range().upper);

            //Plot
            EPI_plot_signal->graph(1)->setData(x, y);

            plot_EPI_signal_font();
        }
        else{
            status_error("Bad value for EPI min");
        }
    }
    else{
        status_error("No EPI signal curve");
    }
}

/*!
 * \brief MainWindow::plot_EPI_signal_max
 */
void MainWindow::plot_EPI_signal_max(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(EPI_max_signal);
    x.append(EPI_max_signal);
    y.append(EPI_plot_signal->yAxis->range().lower);
    y.append(EPI_plot_signal->yAxis->range().upper);

    //Plot
    EPI_plot_signal->graph(2)->setData(x, y);

    plot_EPI_signal_font();
}

/*!
 * \brief MainWindow::plot_EPI_signal_font
 */
void MainWindow::plot_EPI_signal_font(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x1, y1;
    x1.append(EPI_min_signal);
    x1.append(EPI_max_signal);
    y1.append(EPI_plot_signal->yAxis->range().upper);
    y1.append(EPI_plot_signal->yAxis->range().upper);
    QVector<double> x2, y2;
    x2.append(EPI_min_signal);
    x2.append(EPI_max_signal);
    y2.append(EPI_plot_signal->yAxis->range().lower);
    y2.append(EPI_plot_signal->yAxis->range().lower);

    //Plot
    EPI_plot_signal->graph(3)->setData(x1, y1);
    EPI_plot_signal->graph(4)->setData(x2, y2);
    EPI_plot_signal->replot();
}

/*!
 * \brief MainWindow::plot_EPI_select_curve
 */
void MainWindow::plot_EPI_select_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_min_signal < EPI_max_signal){
        //Extract selection
        int n = EPI_coords[EPI_current_pos]->size();
        int n_min = 0, n_max = n;
        for (int i = 0; i < n; i++){
            if (EPI_coords[EPI_current_pos]->coord(i,XCOORD) < EPI_min_signal){
                n_min = i;
            }
            if (EPI_coords[EPI_current_pos]->coord(i, XCOORD) >= EPI_max_signal){
                n_max = i;
                break;
            }
        }

        //Create QVector and Coord
        EPI_coord_select->set_size(n_max-n_min);
        QVector<double> x, y;
        for (int i = n_min; i < n_max; i++){
            double x_val = EPI_coords[EPI_current_pos]->coord(i, XCOORD);
            double y_val = EPI_coords[EPI_current_pos]->coord(i, YCOORD);
            x.append(x_val);
            y.append(y_val);
            EPI_coord_select->set_coord(x_val, i-n_min, XCOORD);
            EPI_coord_select->set_coord(y_val, i-n_min, YCOORD);
        }

        //Plot
        EPI_plot_select->graph(0)->setData(x, y);
        EPI_plot_select->xAxis->setRange(min(x), max(x));
        EPI_plot_select->yAxis->setRange(min(y), max(y));
        EPI_plot_select->replot();
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::plot_EPI_fourier_curve
 */
void MainWindow::plot_EPI_fourier_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_min_fourier < EPI_max_fourier){
        //Create QVector
        QVector<double> x, y;
        for (int i = EPI_min_fourier; i < EPI_max_fourier; i++){
            x.append(EPI_coord_fourier->coord(i, XCOORD));
            y.append(EPI_coord_fourier->coord(i, YCOORD));
        }

        //Plot
        EPI_plot_fourier->graph(0)->setData(x, y);
        EPI_plot_fourier->xAxis->setRange(min(x), max(x));
        EPI_plot_fourier->yAxis->setRange(min(y), max(y));
        EPI_plot_fourier->replot();
    }
}

/*!
 * \brief MainWindow::plot_EPI_ifft_min
 */
void MainWindow::plot_EPI_ifft_min(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(EPI_min_ifft);
    x.append(EPI_min_ifft);
    y.append(EPI_plot_fourier->yAxis->range().lower);
    y.append(EPI_plot_fourier->yAxis->range().upper);

    //Plot
    EPI_plot_fourier->graph(1)->setData(x, y);

    plot_EPI_fourier_font();
}

/*!
 * \brief MainWindow::plot_EPI_ifft_max
 */
void MainWindow::plot_EPI_ifft_max(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(EPI_max_ifft);
    x.append(EPI_max_ifft);
    y.append(EPI_plot_fourier->yAxis->range().lower);
    y.append(EPI_plot_fourier->yAxis->range().upper);

    //Plot
    EPI_plot_fourier->graph(2)->setData(x, y);

    plot_EPI_fourier_font();
}

/*!
 * \brief MainWindow::plot_fourier_font
 */
void MainWindow::plot_EPI_fourier_font(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(EPI_min_ifft);
    x.append(EPI_max_ifft);
    y.append(EPI_plot_fourier->yAxis->range().upper);
    y.append(EPI_plot_fourier->yAxis->range().upper);

    //PLot
    EPI_plot_fourier->graph(3)->setData(x, y);
    EPI_plot_fourier->replot();
}

/*!
 * \brief MainWindow::plot_EPI_ifft_curve
 */
void MainWindow::plot_EPI_ifft_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = EPI_coord_ifft->size();

    //Convert coord to QVector
    QVector<double> x, y;
    for (int i = 0; i < n; i++){
        x.append(EPI_coord_ifft->coord(i, XCOORD));
        y.append(EPI_coord_ifft->coord(i, YCOORD));
    }

    //Plot
    EPI_plot_ifft->graph(0)->setData(x, y);
    EPI_plot_ifft->xAxis->setRange(min(x), max(x));
    EPI_plot_ifft->yAxis->setRange(min(y), max(y));
    EPI_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_EPI_threshold
 */
void MainWindow::plot_EPI_threshold(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(EPI_plot_ifft->xAxis->range().lower);
    x.append(EPI_plot_ifft->xAxis->range().upper);
    y.append(EPI_threshold);
    y.append(EPI_threshold);

    //Plot
    EPI_plot_ifft->graph(1)->setData(x, y);
    EPI_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_EPI_peaks
 */
void MainWindow::plot_EPI_peaks(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = EPI_coord_peaks->size();

    //Create QVector
    QVector<double> x, y;
    for (int i = 0; i < n; i++){
        x.append(EPI_coord_peaks->coord(i, XCOORD));
        y.append(EPI_coord_peaks->coord(i, YCOORD));
    }

    //Plot
    EPI_plot_ifft->graph(2)->setData(x, y);
    EPI_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_EPI_mean_curve
 */
void MainWindow::plot_EPI_mean_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = EPI_coord_mean->size();

    //Create QVector
    QVector<double> x, y, yErr;
    for (int i = 0; i < n; i++){
        x.append(EPI_coord_mean->coord(i, XCOORD));
        y.append(EPI_coord_mean->coord(i, YCOORD));
        yErr.append(EPI_coord_SD->coord(i, YCOORD));
    }

    //Special QVector for range
    QVector<double> y1, y2;
    for (int i = 0; i < n; i++){
        y1.append(EPI_coord_mean->coord(i, YCOORD) + EPI_coord_SD->coord(i, YCOORD));
        y2.append(EPI_coord_mean->coord(i, YCOORD) - EPI_coord_SD->coord(i, YCOORD));
    }

    //Plot
    EPI_plot_mean->graph(0)->setDataValueError(x, y, yErr);
    EPI_plot_mean->xAxis->setRange(min(x), max(x));
    EPI_plot_mean->yAxis->setRange(min(min(y1), min(y2)), max(max(y1), max(y2)));
    EPI_plot_mean->replot();
}
//**********//
//**********//


//************//
//***SLIDER***//
//************//
/*!
 * \brief MainWindow::move_EPI_min_signal
 * \param pos
 */
void MainWindow::move_EPI_min_signal(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_signal = pos / (double)SLIDER_DOUBLE;

    //Box update
    EPI_box_min_signal->blockSignals(true);
    EPI_box_min_signal->setValue(EPI_min_signal);
    EPI_box_min_signal->blockSignals(false);

    //Plot
    plot_EPI_signal_min();
    plot_EPI_select_curve();
}

/*!
 * \brief MainWindow::move_EPI_max_signal
 * \param pos
 */
void MainWindow::move_EPI_max_signal(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_signal = pos / (double)SLIDER_DOUBLE;

    //Box update
    EPI_box_max_signal->blockSignals(true);
    EPI_box_max_signal->setValue(EPI_max_signal);
    EPI_box_max_signal->blockSignals(false);

    //Plot
    plot_EPI_signal_max();
    plot_EPI_select_curve();
}

/*!
 * \brief MainWindow::move_EPI_min_fourier
 * \param pos
 */
void MainWindow::move_EPI_min_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_fourier = pos;

    //Box update
    EPI_box_min_fourier->blockSignals(true);
    EPI_box_min_fourier->setValue(pos);
    EPI_box_min_fourier->blockSignals(false);

    //Plot
    plot_EPI_fourier_curve();

    update_EPI_ifft_range();
}

/*!
 * \brief MainWindow::move_EPI_max_fourier
 * \param pos
 */
void MainWindow::move_EPI_max_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_fourier = pos;

    //Box update
    EPI_box_max_fourier->blockSignals(true);
    EPI_box_max_fourier->setValue(pos);
    EPI_box_max_fourier->blockSignals(false);

    //PLot
    plot_EPI_fourier_curve();

    update_EPI_ifft_range();
}

/*!
 * \brief MainWindow::move_EPI_min_ifft
 * \param pos
 */
void MainWindow::move_EPI_min_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_ifft = pos;

    //Box update
    EPI_box_min_ifft->blockSignals(true);
    EPI_box_min_ifft->setValue(pos);
    EPI_box_min_ifft->blockSignals(false);

    //Plot
    plot_EPI_ifft_min();
}

/*!
 * \brief MainWindow::move_EPI_max_ifft
 * \param pos
 */
void MainWindow::move_EPI_max_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_ifft = pos;

    //Box update
    EPI_box_max_ifft->blockSignals(true);
    EPI_box_max_ifft->setValue(pos);
    EPI_box_max_ifft->blockSignals(false);

    //Plot
    plot_EPI_ifft_max();
}

/*!
 * \brief MainWindow::move_EPI_threshold
 * \param pos
 */
void MainWindow::move_EPI_threshold(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_threshold = pos / (double)SLIDER_DOUBLE;

    //Box update
    EPI_box_threshold->blockSignals(true);
    EPI_box_threshold->setValue(EPI_threshold);
    EPI_box_threshold->blockSignals(false);

    //Plot
    plot_EPI_threshold();
}

/*!
 * \brief MainWindow::update_EPI_ifft_range
 */
void MainWindow::update_EPI_ifft_range(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Sliders update
    EPI_slider_min_ifft->blockSignals(true);
    EPI_slider_min_ifft->setRange(EPI_min_fourier, EPI_max_fourier);
    EPI_slider_min_ifft->blockSignals(false);

    EPI_slider_max_ifft->blockSignals(true);
    EPI_slider_max_ifft->setRange(EPI_min_fourier, EPI_max_fourier);
    EPI_slider_max_ifft->blockSignals(false);

    //Boxes update
    EPI_box_min_ifft->blockSignals(true);
    EPI_box_min_ifft->setRange(EPI_min_fourier, EPI_max_fourier);
    EPI_box_min_ifft->blockSignals(false);

    EPI_box_max_ifft->blockSignals(true);
    EPI_box_max_ifft->setRange(EPI_min_fourier, EPI_max_fourier);
    EPI_box_max_ifft->blockSignals(false);
}
//************//
//************//


//*********//
//***BOX***//
//*********//
/*!
 * \brief MainWindow::choose_EPI_min_signal
 * \param pos
 */
void MainWindow::choose_EPI_min_signal(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_signal = pos;

    //Slider update
    EPI_slider_min_signal->blockSignals(true);
    EPI_slider_min_signal->setValue(pos * (double)SLIDER_DOUBLE);
    EPI_slider_min_signal->blockSignals(false);

    //Plot
    plot_EPI_signal_min();
    plot_EPI_select_curve();
}

/*!
 * \brief MainWindow::choose_EPI_max_signal
 * \param pos
 */
void MainWindow::choose_EPI_max_signal(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_signal = pos;

    //Slider update
    EPI_slider_max_signal->blockSignals(true);
    EPI_slider_max_signal->setValue(pos * (double)SLIDER_DOUBLE);
    EPI_slider_max_signal->blockSignals(false);

    //Plot
    plot_EPI_signal_max();
    plot_EPI_select_curve();
}

/*!
 * \brief MainWindow::choose_EPI_min_fourier
 * \param pos
 */
void MainWindow::choose_EPI_min_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_fourier = pos;

    //Slider update
    EPI_slider_min_fourier->blockSignals(true);
    EPI_slider_min_fourier->setValue(pos);
    EPI_slider_min_fourier->blockSignals(false);

    //Plot
    plot_EPI_fourier_curve();

    update_EPI_ifft_range();
}

/*!
 * \brief MainWindow::choose_EPI_max_fourier
 * \param pos
 */
void MainWindow::choose_EPI_max_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_fourier = pos;

    //Slider update
    EPI_slider_max_fourier->blockSignals(true);
    EPI_slider_max_fourier->setValue(pos);
    EPI_slider_max_fourier->blockSignals(false);

    //Plot
    plot_EPI_fourier_curve();

    update_EPI_ifft_range();
}

/*!
 * \brief MainWindow::choose_EPI_min_ifft
 * \param pos
 */
void MainWindow::choose_EPI_min_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_min_ifft = pos;

    //Slider update
    EPI_slider_min_ifft->blockSignals(true);
    EPI_slider_min_ifft->setValue(pos);
    EPI_slider_min_ifft->blockSignals(false);

    //Plot
    plot_EPI_ifft_min();
}

/*!
 * \brief MainWindow::choose_EPI_max_ifft
 * \param pos
 */
void MainWindow::choose_EPI_max_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_max_ifft = pos;

    //Slider update
    EPI_slider_max_ifft->blockSignals(true);
    EPI_slider_max_ifft->setValue(pos);
    EPI_slider_max_ifft->blockSignals(false);

    //Plot
    plot_EPI_ifft_max();
}

/*!
 * \brief MainWindow::choose_EPI_threshold
 * \param pos
 */
void MainWindow::choose_EPI_threshold(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    EPI_threshold = pos;

    //Slider update
    EPI_slider_threshold->blockSignals(true);
    EPI_slider_threshold->setValue(pos * (double)SLIDER_DOUBLE);
    EPI_slider_threshold->blockSignals(false);

    //Plot
    plot_EPI_threshold();
}
//*********//
//*********//

//************//
//***BUTTON***//
//************//
/*!
 * \brief MainWindow::do_EPI_fourier
 */
void MainWindow::do_EPI_fourier(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_select->size() != 0){
        //Fourier
        bool res = fourier(EPI_coord_fourier, *EPI_coord_select);

        if (res){
            //Min-Max
            int xmin = (int)EPI_coord_fourier->coord(0, XCOORD);
            int xmax = (int)EPI_coord_fourier->coord(EPI_coord_fourier->size()-1, XCOORD);

            //Sliders
            EPI_slider_min_fourier->setRange(xmin, xmax);
            EPI_slider_max_fourier->setRange(xmin, xmax);

            //Boxes
            EPI_box_min_fourier->setRange(xmin, xmax);
            EPI_box_max_fourier->setRange(xmin, xmax);

            EPI_box_min_fourier->setValue(xmax*EPI_coeff_fourier_min);
            EPI_box_max_fourier->setValue(xmax*EPI_coeff_fourier_max);

            //Plot
            plot_EPI_fourier_curve();

            //Sliders
            EPI_slider_min_ifft->setRange(1, xmax*EPI_coeff_fourier_max);
            EPI_slider_max_ifft->setRange(1, xmax*EPI_coeff_fourier_max);

            //Boxes
            EPI_box_min_ifft->setRange(1, xmax*EPI_coeff_fourier_max);
            EPI_box_max_ifft->setRange(1, xmax*EPI_coeff_fourier_max);
            EPI_box_min_ifft->setValue(xmax*EPI_coeff_ifft_min);
            EPI_box_max_ifft->setValue(xmax*EPI_coeff_ifft_max);

            //Status
            status_info("");
        }
        else{
            status_error("");
        }
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_ifft
 */
void MainWindow::do_EPI_ifft(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_select->size() != 0){
        bool res = ifft(EPI_coord_ifft, *EPI_coord_select, EPI_min_ifft, EPI_max_ifft);

        if(res){
            //Plot
            plot_EPI_ifft_curve();

            //Min-Max
            double ymin = min(EPI_coord_ifft->coords(YCOORD), EPI_coord_ifft->size());
            double ymax = max(EPI_coord_ifft->coords(YCOORD), EPI_coord_ifft->size());

            //Slider
            EPI_slider_threshold->setRange(ymin * (double)SLIDER_DOUBLE, ymax * (double)SLIDER_DOUBLE);

            //Box
            EPI_box_threshold->setRange(ymin, ymax);
            EPI_box_threshold->setValue((ymin+ymax)/2.);

            //Status
            status_info("");
        }
        else{
            status_error("");
        }
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_peaks
 */
void MainWindow::do_EPI_peaks(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_ifft->size() != 0){
        //Peaks detection
        detect_peaks(*EPI_coord_ifft, EPI_coord_peaks, EPI_threshold);

        //Plot
        plot_EPI_peaks();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_mean
 */
void MainWindow::do_EPI_mean(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_select->size() != 0 && EPI_coord_peaks->size() != 0){
        //Mean
        mean_icp(*EPI_coord_select, *EPI_coord_peaks, EPI_coord_mean, EPI_coord_SD);

        //Print
        double cycle = max(EPI_coord_mean->coords(XCOORD), EPI_coord_mean->size());
        double heartrate = 60./cycle;
        double pmin = min(EPI_coord_mean->coords(YCOORD), EPI_coord_mean->size());
        double pmax = max(EPI_coord_mean->coords(YCOORD), EPI_coord_mean->size());
        double pmean = mean(*EPI_coord_mean, YCOORD);
        double gradp = pmax - pmin;

        EPI_label_cycle->setText(MAINWINDOW_EPI_CC + QString::number(cycle) + UNITY_S);
        EPI_label_heartrate->setText(MAINWINDOW_EPI_HR + QString::number(heartrate) + UNITY_BPM);
        EPI_label_min->setText(MAINWINDOW_EPI_MIN_S + QString::number(pmin) + UNITY_MMHG);
        EPI_label_max->setText(MAINWINDOW_EPI_MAX_S + QString::number(pmax) + UNITY_MMHG);
        EPI_label_mean->setText(MAINWINDOW_EPI_MEAN_S + QString::number(pmean) + UNITY_MMHG);
        EPI_label_gradient->setText(MAINWINDOW_EPI_GRAD_S + QString::number(gradp) + UNITY_MMHG);

        //Plot
        plot_EPI_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_adjust
 */
void MainWindow::do_EPI_adjust(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_mean->size() != 0 && EPI_coord_SD->size() != 0){
        //Adjust
        adjust(EPI_coord_mean, EPI_coord_SD, EPI_box_adjust->currentText().toLower().toStdString());

        //Plot
        plot_EPI_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_normalize
 */
void MainWindow::do_EPI_normalize(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_mean->size() != 0 && EPI_coord_SD->size() != 0){
        //Normalize
        normalize(EPI_coord_mean, EPI_coord_SD);

        //Plot
        plot_EPI_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_EPI_save
 */
void MainWindow::do_EPI_save(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (EPI_coord_mean->size() != 0 && EPI_coord_SD->size() != 0){
        QString file_name = current_dir + "/" + "EPI__processed_"+EPI_box_select_signal->currentText()+".dat";

        if (!file_name.isEmpty()){
            //Save
            bool res = save_data(file_name, EPI_coord_mean, EPI_coord_SD);

            if (!res){
                    status_error("");
            }
            else{
                int n = EPI_DATA_LENGHT;
                string *string_list1 = new string[n];
                string *string_list2 = new string[n];

                string_list1[0] = EPI_DATA_ITEM01;  string_list2[0] = "";
                string_list1[1] = EPI_DATA_ITEM02;  string_list2[1] = "";
                string_list1[2] = EPI_DATA_ITEM03;  string_list2[2] = "";
                string_list1[3] = EPI_DATA_ITEM04;  string_list2[3] = "";
                string_list1[4] = EPI_DATA_ITEM05;  string_list2[4] = "";
                string_list1[5] = EPI_DATA_ITEM06;  string_list2[5] = "";
                string_list1[6] = EPI_DATA_ITEM07;  string_list2[6] = "";
                string_list1[7] = EPI_DATA_ITEM08;  string_list2[7] = "";
                string_list1[8] = EPI_DATA_ITEM09;  string_list2[8] = "";
                string_list1[9] = EPI_DATA_ITEM10;  string_list2[9] = "";

                file_name.remove(".dat");
                file_name.append("__data.dat");
                res = save_sup_data(file_name, string_list1, string_list2, n);
                delete[] string_list1;
                delete[] string_list2;
            }
        }
        else{
            status_error("");
        }
    }
    else{
        status_error("");
    }
}
//************//
//************//

//************//
//***OTHERS***//
//************//
/*!
 * \brief MainWindow::save_EPI
 */
void MainWindow::save_EPI(){
    //
}

/*!
 * \brief MainWindow::clear_EPI
 */
void MainWindow::clear_EPI(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    EPI_coord_fourier->clear();
    EPI_coord_ifft->clear();
    EPI_coord_peaks->clear();
    EPI_coord_mean->clear();
    EPI_coord_SD->clear();

    EPI_plot_signal->graph(0)->clearData();
    EPI_plot_signal->graph(1)->clearData();
    EPI_plot_signal->graph(2)->clearData();
    EPI_plot_signal->graph(3)->clearData();
    EPI_plot_signal->graph(4)->clearData();
    EPI_plot_signal->replot();

    EPI_plot_select->graph(0)->clearData();
    EPI_plot_select->replot();

    EPI_plot_fourier->graph(0)->clearData();
    EPI_plot_fourier->graph(1)->clearData();
    EPI_plot_fourier->graph(2)->clearData();
    EPI_plot_fourier->graph(3)->clearData();
    EPI_plot_fourier->replot();

    EPI_plot_ifft->graph(0)->clearData();
    EPI_plot_ifft->graph(1)->clearData();
    EPI_plot_ifft->graph(2)->clearData();
    EPI_plot_ifft->replot();

    EPI_plot_mean->graph(0)->clearData();
    EPI_plot_mean->replot();

    EPI_label_cycle->clear();
    EPI_label_heartrate->clear();
    EPI_label_min->clear();
    EPI_label_max->clear();
    EPI_label_mean->clear();
    EPI_label_gradient->clear();
}
