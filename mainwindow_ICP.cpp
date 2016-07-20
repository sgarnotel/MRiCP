#include "mainwindow.h"


/*!
 * \brief MainWindow::init_ICP_var
 */
void MainWindow::init_ICP_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    ICP_tab = new QTabWidget(this);

    //Widget
    ICP_tab_widget = new QWidget(this);

    //Grid
    ICP_grid = new QGridLayout;
    ICP_grid_header = new QGridLayout;
    ICP_grid_signal = new QGridLayout;
    ICP_grid_fourier = new QGridLayout;
    ICP_grid_ifft = new QGridLayout;
    ICP_grid_peaks = new QGridLayout;
    ICP_grid_labels = new QGridLayout;
    ICP_grid_buttons = new QGridLayout;

    //Plots
    ICP_plot_signal = new QCustomPlot;
    ICP_plot_select = new QCustomPlot;
    ICP_plot_fourier = new QCustomPlot;
    ICP_plot_ifft = new QCustomPlot;
    ICP_plot_mean = new QCustomPlot;

    //Sliders
    ICP_slider_min_signal = new QSlider(this);
    ICP_slider_max_signal = new QSlider(this);
    ICP_slider_min_fourier = new QSlider(this);
    ICP_slider_max_fourier = new QSlider(this);
    ICP_slider_min_ifft = new QSlider(this);
    ICP_slider_max_ifft = new QSlider(this);
    ICP_slider_threshold = new QSlider(this);

    //Boxes
    ICP_box_min_signal = new QDoubleSpinBox(this);
    ICP_box_max_signal = new QDoubleSpinBox(this);
    ICP_box_min_fourier = new QSpinBox(this);
    ICP_box_max_fourier = new QSpinBox(this);
    ICP_box_min_ifft = new QSpinBox(this);
    ICP_box_max_ifft = new QSpinBox(this);
    ICP_box_threshold = new QDoubleSpinBox(this);
    ICP_box_adjust = new QComboBox(this);

    //Buttons
    ICP_button_quality = new QPushButton(this);
    ICP_button_fourier = new QPushButton(this);
    ICP_button_ifft = new QPushButton(this);
    ICP_button_peaks = new QPushButton(this);
    ICP_button_mean = new QPushButton(this);
    ICP_button_adjust = new QPushButton(this);
    ICP_button_normalize = new QPushButton(this);
    ICP_button_save = new QPushButton(this);

    //Labels
    ICP_label_cycle = new QLabel(this);
    ICP_label_heartrate = new QLabel(this);
    ICP_label_min = new QLabel(this);
    ICP_label_max = new QLabel(this);
    ICP_label_mean = new QLabel(this);
    ICP_label_gradient = new QLabel(this);

    //Int
    ICP_min_fourier = 0;
    ICP_max_fourier = 0;
    ICP_min_ifft = 0;
    ICP_max_ifft = 0;

    //Double
    ICP_min_signal = 0.;
    ICP_max_signal = 0.;
    ICP_threshold = 0.;

    //Coord
    ICP_coord_signal = new Coord;
    ICP_coord_select = new Coord;
    ICP_coord_fourier = new Coord;
    ICP_coord_ifft = new Coord;
    ICP_coord_peaks = new Coord;
    ICP_coord_mean = new Coord;
    ICP_coord_SD = new Coord;
}

/*!
 * \brief MainWindow::init_ICP_win
 */
void MainWindow::init_ICP_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Buttons
    ICP_button_quality->setText(MAINWINDOW_ICP_QUALITY);

    ICP_button_fourier->setText(MAINWINDOW_ICP_FOURIER);
    ICP_button_ifft->setText(MAINWINDOW_ICP_IFFT);
    ICP_button_peaks->setText(MAINWINDOW_ICP_PEAKS);
    ICP_button_mean->setText(MAINWINDOW_ICP_MEAN);

    ICP_button_adjust->setIcon(QIcon(IMG_ADJUST));
    ICP_button_adjust->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    ICP_button_adjust->setToolTip(MAINWINDOW_ICP_ADJUST);
    ICP_button_normalize->setIcon(QIcon(IMG_NORMALIZE));
    ICP_button_normalize->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    ICP_button_normalize->setToolTip(MAINWINDOW_ICP_NORMALIZE);
    ICP_button_save->setIcon(QIcon(IMG_SAVE));
    ICP_button_save->setIconSize(QSize(IMG_BUTTON_SIZE, IMG_BUTTON_SIZE));
    ICP_button_save->setToolTip(MAINWINDOW_ICP_SAVE);

    //Boxes
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM1);
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM2);
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM3);
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM4);
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM5);
    ICP_box_adjust->addItem(MAINWINDOW_ADJUST_ITEM6);
#ifdef QT5
    ICP_box_adjust->setCurrentText(MAINWINDOW_ADJUST_ITEM1);
#endif

    //Sliders
    ICP_slider_min_signal->setOrientation(Qt::Horizontal);
    ICP_slider_max_signal->setOrientation(Qt::Horizontal);
    ICP_slider_min_fourier->setOrientation(Qt::Horizontal);
    ICP_slider_max_fourier->setOrientation(Qt::Horizontal);
    ICP_slider_min_ifft->setOrientation(Qt::Horizontal);
    ICP_slider_max_ifft->setOrientation(Qt::Horizontal);
    ICP_slider_threshold->setOrientation(Qt::Horizontal);

    //Plots
    ICP_plot_signal->addGraph();    //Signal
    ICP_plot_signal->addGraph();    //Min Bound
    ICP_plot_signal->addGraph();    //Max Bound
    ICP_plot_signal->addGraph();    //MinMaxFont
    ICP_plot_signal->addGraph();    //MinMaxFont
    ICP_plot_select->addGraph();    //Select
    ICP_plot_fourier->addGraph();   //Fourier spectrum
    ICP_plot_fourier->addGraph();   //IFFT min
    ICP_plot_fourier->addGraph();   //IFFT max
    ICP_plot_fourier->addGraph();   //MinMaxFont
    ICP_plot_ifft->addGraph();      //IFFT
    ICP_plot_ifft->addGraph();      //Threshold
    ICP_plot_ifft->addGraph();      //Peaks
    ICP_plot_mean->addGraph();      //Mean

    //Grid
    ICP_grid_signal->addWidget(ICP_box_min_signal, 0, 0, 1, 1);
    ICP_grid_signal->addWidget(ICP_box_max_signal, 0, 1, 1, 1);
    ICP_grid_signal->addWidget(ICP_slider_min_signal, 1, 0, 1, 1);
    ICP_grid_signal->addWidget(ICP_slider_max_signal, 1, 1, 1, 1);
    ICP_grid_signal->addWidget(ICP_button_quality, 0, 2, 2, 1);

    ICP_grid_fourier->addWidget(ICP_button_fourier, 0, 0, 2, 1);
    ICP_grid_fourier->addWidget(ICP_box_min_fourier, 0, 1, 1, 1);
    ICP_grid_fourier->addWidget(ICP_box_max_fourier, 0, 2, 1, 1);
    ICP_grid_fourier->addWidget(ICP_slider_min_fourier, 1, 1, 1, 1);
    ICP_grid_fourier->addWidget(ICP_slider_max_fourier, 1, 2, 1, 1);

    ICP_grid_ifft->addWidget(ICP_box_min_ifft, 0, 0, 1, 1);
    ICP_grid_ifft->addWidget(ICP_box_max_ifft, 0, 1, 1, 1);
    ICP_grid_ifft->addWidget(ICP_slider_min_ifft, 1, 0, 1, 1);
    ICP_grid_ifft->addWidget(ICP_slider_max_ifft, 1, 1, 1, 1);
    ICP_grid_ifft->addWidget(ICP_button_ifft, 0, 2, 2, 1);

    ICP_grid_peaks->addWidget(ICP_box_threshold, 0, 0, 1, 1);
    ICP_grid_peaks->addWidget(ICP_button_peaks, 0, 1, 1, 1);
    ICP_grid_peaks->addWidget(ICP_button_mean, 0, 2, 1, 1);
    ICP_grid_peaks->addWidget(ICP_slider_threshold, 1, 0, 1, 1);

    ICP_grid_labels->addWidget(ICP_label_cycle);
    ICP_grid_labels->addWidget(ICP_label_heartrate);
    ICP_grid_labels->addWidget(ICP_label_min);
    ICP_grid_labels->addWidget(ICP_label_max);
    ICP_grid_labels->addWidget(ICP_label_mean);
    ICP_grid_labels->addWidget(ICP_label_gradient);

    ICP_grid_buttons->addWidget(ICP_button_adjust, 0, 0, 1, 1);
    ICP_grid_buttons->addWidget(ICP_box_adjust, 0, 1, 1, 1);
    ICP_grid_buttons->addWidget(ICP_button_normalize, 0, 2, 1, 1);
    ICP_grid_buttons->addWidget(ICP_button_save, 0, 3, 1, 1);

    ICP_grid->addLayout(ICP_grid_header, 0, 0, 2, 30);
    ICP_grid->addLayout(ICP_grid_signal, 0, 30, 2, 70);
    ICP_grid->addWidget(ICP_plot_signal, 2, 0, 10, 100);
    ICP_grid->addWidget(ICP_plot_select, 12, 0, 10, 100);
    ICP_grid->addLayout(ICP_grid_fourier, 22, 0, 2, 100);
    ICP_grid->addWidget(ICP_plot_fourier, 24, 0, 10, 100);
    ICP_grid->addLayout(ICP_grid_ifft, 34, 0, 2, 100);
    ICP_grid->addWidget(ICP_plot_ifft, 36, 0, 10, 100);

    ICP_grid->addLayout(ICP_grid_peaks, 46, 0, 2, 100);
    ICP_grid->addLayout(ICP_grid_labels, 48, 0, 10, 1);
    ICP_grid->addWidget(ICP_plot_mean, 48, 1, 10, 99);
    ICP_grid->addLayout(ICP_grid_buttons, 58, 0, 1, 100);

    //Widget
    ICP_tab_widget->setLayout(ICP_grid);

    //Tab
    ICP_tab->addTab(ICP_tab_widget, "ICP");
}

/*!
 * \brief MainWindow::init_ICP_sig
 */
void MainWindow::init_ICP_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Sliders
    connect(ICP_slider_min_signal, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_min_signal(int)));
    connect(ICP_slider_max_signal, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_max_signal(int)));
    connect(ICP_slider_min_fourier, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_min_fourier(int)));
    connect(ICP_slider_max_fourier, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_max_fourier(int)));
    connect(ICP_slider_min_ifft, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_min_ifft(int)));
    connect(ICP_slider_max_ifft, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_max_ifft(int)));
    connect(ICP_slider_threshold, SIGNAL(valueChanged(int)), this, SLOT(move_ICP_threshold(int)));

    //Boxes
    connect(ICP_box_min_signal, SIGNAL(valueChanged(double)), this, SLOT(choose_ICP_min_signal(double)));
    connect(ICP_box_max_signal, SIGNAL(valueChanged(double)), this, SLOT(choose_ICP_max_signal(double)));
    connect(ICP_box_min_fourier, SIGNAL(valueChanged(int)), this, SLOT(choose_ICP_min_fourier(int)));
    connect(ICP_box_max_fourier, SIGNAL(valueChanged(int)), this, SLOT(choose_ICP_max_fourier(int)));
    connect(ICP_box_min_ifft, SIGNAL(valueChanged(int)), this, SLOT(choose_ICP_min_ifft(int)));
    connect(ICP_box_max_ifft, SIGNAL(valueChanged(int)), this, SLOT(choose_ICP_max_ifft(int)));
    connect(ICP_box_threshold, SIGNAL(valueChanged(double)), this, SLOT(choose_ICP_threshold(double)));

    //Buttons
    connect(ICP_button_quality, SIGNAL(clicked()), this, SLOT(do_ICP_quality()));
    connect(ICP_button_fourier, SIGNAL(clicked()), this, SLOT(do_ICP_fourier()));
    connect(ICP_button_ifft, SIGNAL(clicked()), this, SLOT(do_ICP_ifft()));
    connect(ICP_button_peaks, SIGNAL(clicked()), this, SLOT(do_ICP_peaks()));
    connect(ICP_button_mean, SIGNAL(clicked()), this, SLOT(do_ICP_mean()));
    connect(ICP_button_adjust, SIGNAL(clicked()), this, SLOT(do_ICP_adjust()));
    connect(ICP_button_normalize, SIGNAL(clicked()), this, SLOT(do_ICP_normalize()));
    connect(ICP_button_save, SIGNAL(clicked()), this, SLOT(do_ICP_save()));
}

/*!
 * \brief MainWindow::init_ICP_css
 */
void MainWindow::init_ICP_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    ICP_tab->setStyleSheet(CSS_TAB);
#ifdef QT5
    ICP_tab->tabBar()->setStyleSheet(CSS_TABBAR);
    ICP_tab->tabBar()->setFocusPolicy(Qt::NoFocus);
#endif

    //Widget
    ICP_tab_widget->setStyleSheet(CSS_WIDGET);

    //Plots
    ICP_plot_signal->graph(0)->setPen(QPen(Qt::blue));
    ICP_plot_signal->graph(1)->setPen(QPen(Qt::red));
    ICP_plot_signal->graph(2)->setPen(QPen(Qt::red));
    ICP_plot_signal->graph(3)->setPen(QPen(Qt::red));
    ICP_plot_signal->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    ICP_plot_signal->graph(4)->setPen(QPen(Qt::red));
    ICP_plot_signal->graph(4)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    ICP_plot_select->graph(0)->setPen(QPen(Qt::blue));
    ICP_plot_fourier->graph(0)->setPen(QPen(Qt::blue));
    ICP_plot_fourier->graph(0)->setBrush(QBrush(QPixmap(CSS_GRAPH_BRUSH_B)));
    ICP_plot_fourier->graph(1)->setPen(QPen(Qt::red));
    ICP_plot_fourier->graph(2)->setPen(QPen(Qt::red));
    ICP_plot_fourier->graph(3)->setPen(QPen(Qt::red));
    ICP_plot_fourier->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    ICP_plot_ifft->graph(0)->setPen(QPen(Qt::blue));
    ICP_plot_ifft->graph(1)->setPen(QPen(Qt::red));
    ICP_plot_ifft->graph(2)->setPen(QPen(Qt::red));
    ICP_plot_ifft->graph(2)->setLineStyle(QCPGraph::lsNone);
    ICP_plot_ifft->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    ICP_plot_mean->graph(0)->setPen(QPen(Qt::blue));
    ICP_plot_mean->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDot));
    ICP_plot_mean->graph(0)->setErrorType(QCPGraph::etValue);

    //Sliders
    ICP_slider_min_signal->setStyleSheet(CSS_SLIDER);
    ICP_slider_max_signal->setStyleSheet(CSS_SLIDER);
    ICP_slider_min_fourier->setStyleSheet(CSS_SLIDER);
    ICP_slider_max_fourier->setStyleSheet(CSS_SLIDER);
    ICP_slider_min_ifft->setStyleSheet(CSS_SLIDER);
    ICP_slider_max_ifft->setStyleSheet(CSS_SLIDER);
    ICP_slider_threshold->setStyleSheet(CSS_SLIDER);

    //Boxes
    ICP_box_min_signal->setStyleSheet(CSS_DSPINBOX);
    ICP_box_max_signal->setStyleSheet(CSS_DSPINBOX);
    ICP_box_min_fourier->setStyleSheet(CSS_SPINBOX);
    ICP_box_max_fourier->setStyleSheet(CSS_SPINBOX);
    ICP_box_min_ifft->setStyleSheet(CSS_SPINBOX);
    ICP_box_max_ifft->setStyleSheet(CSS_SPINBOX);
    ICP_box_threshold->setStyleSheet(CSS_DSPINBOX);
    ICP_box_adjust->setStyleSheet(CSS_COMBOBOX);

    //Buttons
    ICP_button_quality->setStyleSheet(CSS_BUTTON);
    ICP_button_fourier->setStyleSheet(CSS_BUTTON);
    ICP_button_ifft->setStyleSheet(CSS_BUTTON);
    ICP_button_peaks->setStyleSheet(CSS_BUTTON);
    ICP_button_mean->setStyleSheet(CSS_BUTTON);
    ICP_button_adjust->setStyleSheet(CSS_BUTTON);
    ICP_button_normalize->setStyleSheet(CSS_BUTTON);
    ICP_button_save->setStyleSheet(CSS_BUTTON);

    //Labels
    ICP_label_cycle->setStyleSheet(CSS_LABEL_GLOBAL);
    ICP_label_heartrate->setStyleSheet(CSS_LABEL_GLOBAL);
    ICP_label_min->setStyleSheet(CSS_LABEL_GLOBAL);
    ICP_label_max->setStyleSheet(CSS_LABEL_GLOBAL);
    ICP_label_mean->setStyleSheet(CSS_LABEL_GLOBAL);
    ICP_label_gradient->setStyleSheet(CSS_LABEL_GLOBAL);
}

//**********//
//***PLOT***//
//**********//
/*!
 * \brief MainWindow::plot_ICP_signal_curve
 */
void MainWindow::plot_ICP_signal_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = ICP_coord_signal->size();

    if (n > 0){
        //Convert Coord to QVector
        QVector<double> x, y;
        for (int i = 0; i < n; i++){
            x.append(ICP_coord_signal->coord(i, XCOORD));
            y.append(ICP_coord_signal->coord(i, YCOORD));
        }

        //Plot
        ICP_plot_signal->graph(0)->setData(x, y);
        ICP_plot_signal->xAxis->setRange(min(x), max(x));
        ICP_plot_signal->yAxis->setRange(min(y), max(y));

        ICP_plot_signal->replot();

        //Slider
        double xmin = min(x);
        double xmax = max(x);
        ICP_slider_min_signal->setRange(xmin, xmax);
        ICP_slider_max_signal->setRange(xmin, xmax);

        //Boxes
        ICP_box_min_signal->setRange(xmin, xmax);
        ICP_box_max_signal->setRange(xmin, xmax);
        ICP_box_min_signal->setValue(xmin);
        ICP_box_max_signal->setValue(xmax);
    }
    else{
        status_error(ICP_ERROR_001);
    }
}

/*!
 * \brief MainWindow::plot_ICP_signal_min
 */
void MainWindow::plot_ICP_signal_min(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = ICP_coord_signal->size();
    if (n > 0){
        double min_signal = min(ICP_coord_signal->coords(XCOORD), n);
        double max_signal = max(ICP_coord_signal->coords(XCOORD), n);

        if (ICP_min_signal >= min_signal && ICP_min_signal <= max_signal && ICP_min_signal < ICP_max_signal){
            //Create QVector
            QVector<double> x, y;
            x.append(ICP_min_signal);
            x.append(ICP_min_signal);
            y.append(ICP_plot_signal->yAxis->range().lower);
            y.append(ICP_plot_signal->yAxis->range().upper);

            //Plot
            ICP_plot_signal->graph(1)->setData(x, y);

            plot_ICP_signal_font();
        }
        else{
            status_error(ICP_ERROR_002);
        }
    }
    else{
        status_error(ICP_ERROR_001);
    }
}

/*!
 * \brief MainWindow::plot_ICP_signal_max
 */
void MainWindow::plot_ICP_signal_max(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(ICP_max_signal);
    x.append(ICP_max_signal);
    y.append(ICP_plot_signal->yAxis->range().lower);
    y.append(ICP_plot_signal->yAxis->range().upper);

    //Plot
    ICP_plot_signal->graph(2)->setData(x, y);

    plot_ICP_signal_font();
}

/*!
 * \brief MainWindow::plot_ICP_signal_font
 */
void MainWindow::plot_ICP_signal_font(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x1, y1;
    x1.append(ICP_min_signal);
    x1.append(ICP_max_signal);
    y1.append(ICP_plot_signal->yAxis->range().upper);
    y1.append(ICP_plot_signal->yAxis->range().upper);
    QVector<double> x2, y2;
    x2.append(ICP_min_signal);
    x2.append(ICP_max_signal);
    y2.append(ICP_plot_signal->yAxis->range().lower);
    y2.append(ICP_plot_signal->yAxis->range().lower);

    //Plot
    ICP_plot_signal->graph(3)->setData(x1, y1);
    ICP_plot_signal->graph(4)->setData(x2, y2);
    ICP_plot_signal->replot();
}

/*!
 * \brief MainWindow::plot_ICP_select_curve
 */
void MainWindow::plot_ICP_select_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_min_signal < ICP_max_signal){
        //Extract selection
        int n = ICP_coord_signal->size();
        int n_min = 0, n_max = n;
        for (int i = 0; i < n; i++){
            if (ICP_coord_signal->coord(i,XCOORD) < ICP_min_signal){
                n_min = i;
            }
            if (ICP_coord_signal->coord(i, XCOORD) >= ICP_max_signal){
                n_max = i;
                break;
            }
        }

        //Create QVector and Coord
        ICP_coord_select->set_size(n_max-n_min);
        QVector<double> x, y;
        for (int i = n_min; i < n_max; i++){
            double x_val = ICP_coord_signal->coord(i, XCOORD);
            double y_val = ICP_coord_signal->coord(i, YCOORD);
            x.append(x_val);
            y.append(y_val);
            ICP_coord_select->set_coord(x_val, i-n_min, XCOORD);
            ICP_coord_select->set_coord(y_val, i-n_min, YCOORD);
        }

        //Plot
        ICP_plot_select->graph(0)->setData(x, y);
        ICP_plot_select->xAxis->setRange(min(x), max(x));
        ICP_plot_select->yAxis->setRange(min(y), max(y));
        ICP_plot_select->replot();
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::plot_ICP_fourier_curve
 */
void MainWindow::plot_ICP_fourier_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_min_fourier < ICP_max_fourier){
        //Create QVector
        QVector<double> x, y;
        double sample = 1. / (ICP_coord_select->coord(1, XCOORD) - ICP_coord_select->coord(0, XCOORD)) / ICP_coord_select->size();   //bug correction 08/09/2015
        for (int i = ICP_min_fourier; i < ICP_max_fourier; i++){
            x.append(ICP_coord_fourier->coord(i, XCOORD) * sample);
            y.append(ICP_coord_fourier->coord(i, YCOORD));
        }

        //Plot
        ICP_plot_fourier->graph(0)->setData(x, y);
        ICP_plot_fourier->xAxis->setRange(min(x), max(x));
        ICP_plot_fourier->yAxis->setRange(min(y), max(y));
        ICP_plot_fourier->replot();
    }
}

/*!
 * \brief MainWindow::plot_ICP_ifft_min
 */
void MainWindow::plot_ICP_ifft_min(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    double sample = 1. / (ICP_coord_select->coord(1, XCOORD) - ICP_coord_select->coord(0, XCOORD)) / ICP_coord_select->size();   //bug correction 08/09/2015
    x.append(sample*ICP_min_ifft);
    x.append(sample*ICP_min_ifft);
    y.append(ICP_plot_fourier->yAxis->range().lower);
    y.append(ICP_plot_fourier->yAxis->range().upper);

    //Plot
    ICP_plot_fourier->graph(1)->setData(x, y);

    plot_ICP_fourier_font();
}

/*!
 * \brief MainWindow::plot_ICP_ifft_max
 */
void MainWindow::plot_ICP_ifft_max(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    double sample = 1. / (ICP_coord_select->coord(1, XCOORD) - ICP_coord_select->coord(0, XCOORD)) / ICP_coord_select->size();   //bug correction 08/09/2015
    x.append(sample*ICP_max_ifft);
    x.append(sample*ICP_max_ifft);
    y.append(ICP_plot_fourier->yAxis->range().lower);
    y.append(ICP_plot_fourier->yAxis->range().upper);

    //Plot
    ICP_plot_fourier->graph(2)->setData(x, y);

    plot_ICP_fourier_font();
}

/*!
 * \brief MainWindow::plot_fourier_font
 */
void MainWindow::plot_ICP_fourier_font(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    double sample = 1. / (ICP_coord_select->coord(1, XCOORD) - ICP_coord_select->coord(0, XCOORD)) / ICP_coord_select->size();   //bug correction 08/09/2015
    x.append(sample*ICP_min_ifft);
    x.append(sample*ICP_max_ifft);
    y.append(ICP_plot_fourier->yAxis->range().upper);
    y.append(ICP_plot_fourier->yAxis->range().upper);

    //PLot
    ICP_plot_fourier->graph(3)->setData(x, y);
    ICP_plot_fourier->replot();
}

/*!
 * \brief MainWindow::plot_ICP_ifft_curve
 */
void MainWindow::plot_ICP_ifft_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = ICP_coord_ifft->size();

    //Convert coord to QVector
    QVector<double> x, y;
    for (int i = 0; i < n; i++){
        x.append(ICP_coord_ifft->coord(i, XCOORD));
        y.append(ICP_coord_ifft->coord(i, YCOORD));
    }

    //Plot
    ICP_plot_ifft->graph(0)->setData(x, y);
    ICP_plot_ifft->xAxis->setRange(min(x), max(x));
    ICP_plot_ifft->yAxis->setRange(min(y), max(y));
    ICP_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_ICP_threshold
 */
void MainWindow::plot_ICP_threshold(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y;
    x.append(ICP_plot_ifft->xAxis->range().lower);
    x.append(ICP_plot_ifft->xAxis->range().upper);
    y.append(ICP_threshold);
    y.append(ICP_threshold);

    //Plot
    ICP_plot_ifft->graph(1)->setData(x, y);
    ICP_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_ICP_peaks
 */
void MainWindow::plot_ICP_peaks(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = ICP_coord_peaks->size();

    //Create QVector
    QVector<double> x, y;
    for (int i = 0; i < n; i++){
        x.append(ICP_coord_peaks->coord(i, XCOORD));
        y.append(ICP_coord_peaks->coord(i, YCOORD));
    }

    //Plot
    ICP_plot_ifft->graph(2)->setData(x, y);
    ICP_plot_ifft->replot();
}

/*!
 * \brief MainWindow::plot_ICP_mean_curve
 */
void MainWindow::plot_ICP_mean_curve(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Data
    int n = ICP_coord_mean->size();
    int n2 = ICP_coord_SD->size();

    if (n > 0 && n2 > 0 && n == n2){
        //Create QVector
        QVector<double> x, y, yErr;
        for (int i = 0; i < n; i++){
            x.append(ICP_coord_mean->coord(i, XCOORD));
            y.append(ICP_coord_mean->coord(i, YCOORD));
            yErr.append(ICP_coord_SD->coord(i, YCOORD));
        }

        //Special QVector for range
        QVector<double> y1, y2;
        for (int i = 0; i < n; i++){
            y1.append(ICP_coord_mean->coord(i, YCOORD) + ICP_coord_SD->coord(i, YCOORD));
            y2.append(ICP_coord_mean->coord(i, YCOORD) - ICP_coord_SD->coord(i, YCOORD));
        }

        //Plot
        ICP_plot_mean->graph(0)->setDataValueError(x, y, yErr);
        ICP_plot_mean->xAxis->setRange(min(x), max(x));
        ICP_plot_mean->yAxis->setRange(min(min(y1), min(y2)), max(max(y1), max(y2)));
        ICP_plot_mean->replot();
    }
}
//**********//
//**********//


//************//
//***SLIDER***//
//************//
/*!
 * \brief MainWindow::move_ICP_min_signal
 * \param pos
 */
void MainWindow::move_ICP_min_signal(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_signal = pos / (double)SLIDER_DOUBLE;

    //Box update
    ICP_box_min_signal->blockSignals(true);
    ICP_box_min_signal->setValue(ICP_min_signal);
    ICP_box_min_signal->blockSignals(false);

    //Plot
    plot_ICP_signal_min();
    plot_ICP_select_curve();
}

/*!
 * \brief MainWindow::move_ICP_max_signal
 * \param pos
 */
void MainWindow::move_ICP_max_signal(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_signal = pos / (double)SLIDER_DOUBLE;

    //Box update
    ICP_box_max_signal->blockSignals(true);
    ICP_box_max_signal->setValue(ICP_max_signal);
    ICP_box_max_signal->blockSignals(false);

    //Plot
    plot_ICP_signal_max();
    plot_ICP_select_curve();
}

/*!
 * \brief MainWindow::move_ICP_min_fourier
 * \param pos
 */
void MainWindow::move_ICP_min_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_fourier = pos;

    //Box update
    ICP_box_min_fourier->blockSignals(true);
    ICP_box_min_fourier->setValue(pos);
    ICP_box_min_fourier->blockSignals(false);

    //Plot
    plot_ICP_fourier_curve();

    update_ICP_ifft_range();
}

/*!
 * \brief MainWindow::move_ICP_max_fourier
 * \param pos
 */
void MainWindow::move_ICP_max_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_fourier = pos;

    //Box update
    ICP_box_max_fourier->blockSignals(true);
    ICP_box_max_fourier->setValue(pos);
    ICP_box_max_fourier->blockSignals(false);

    //PLot
    plot_ICP_fourier_curve();

    update_ICP_ifft_range();
}

/*!
 * \brief MainWindow::move_ICP_min_ifft
 * \param pos
 */
void MainWindow::move_ICP_min_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_ifft = pos;

    //Box update
    ICP_box_min_ifft->blockSignals(true);
    ICP_box_min_ifft->setValue(pos);
    ICP_box_min_ifft->blockSignals(false);

    //Plot
    plot_ICP_ifft_min();
}

/*!
 * \brief MainWindow::move_ICP_max_ifft
 * \param pos
 */
void MainWindow::move_ICP_max_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_ifft = pos;

    //Box update
    ICP_box_max_ifft->blockSignals(true);
    ICP_box_max_ifft->setValue(pos);
    ICP_box_max_ifft->blockSignals(false);

    //Plot
    plot_ICP_ifft_max();
}

/*!
 * \brief MainWindow::move_ICP_threshold
 * \param pos
 */
void MainWindow::move_ICP_threshold(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_threshold = pos / (double)SLIDER_DOUBLE;

    //Box update
    ICP_box_threshold->blockSignals(true);
    ICP_box_threshold->setValue(ICP_threshold);
    ICP_box_threshold->blockSignals(false);

    //Plot
    plot_ICP_threshold();
}

/*!
 * \brief MainWindow::update_ICP_ifft_range
 */
void MainWindow::update_ICP_ifft_range(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Sliders update
    ICP_slider_min_ifft->blockSignals(true);
    ICP_slider_min_ifft->setRange(ICP_min_fourier, ICP_max_fourier);
    ICP_slider_min_ifft->blockSignals(false);

    ICP_slider_max_ifft->blockSignals(true);
    ICP_slider_max_ifft->setRange(ICP_min_fourier, ICP_max_fourier);
    ICP_slider_max_ifft->blockSignals(false);

    //Boxes update
    ICP_box_min_ifft->blockSignals(true);
    ICP_box_min_ifft->setRange(ICP_min_fourier, ICP_max_fourier);
    ICP_box_min_ifft->blockSignals(false);

    ICP_box_max_ifft->blockSignals(true);
    ICP_box_max_ifft->setRange(ICP_min_fourier, ICP_max_fourier);
    ICP_box_max_ifft->blockSignals(false);
}
//************//
//************//


//*********//
//***BOX***//
//*********//
/*!
 * \brief MainWindow::choose_ICP_min_signal
 * \param pos
 */
void MainWindow::choose_ICP_min_signal(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_signal = pos;

    //Slider update
    ICP_slider_min_signal->blockSignals(true);
    ICP_slider_min_signal->setValue(pos * (double)SLIDER_DOUBLE);
    ICP_slider_min_signal->blockSignals(false);

    //Plot
    plot_ICP_signal_min();
    plot_ICP_select_curve();
}

/*!
 * \brief MainWindow::choose_ICP_max_signal
 * \param pos
 */
void MainWindow::choose_ICP_max_signal(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_signal = pos;

    //Slider update
    ICP_slider_max_signal->blockSignals(true);
    ICP_slider_max_signal->setValue(pos * (double)SLIDER_DOUBLE);
    ICP_slider_max_signal->blockSignals(false);

    //Plot
    plot_ICP_signal_max();
    plot_ICP_select_curve();
}

/*!
 * \brief MainWindow::choose_ICP_min_fourier
 * \param pos
 */
void MainWindow::choose_ICP_min_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_fourier = pos;

    //Slider update
    ICP_slider_min_fourier->blockSignals(true);
    ICP_slider_min_fourier->setValue(pos);
    ICP_slider_min_fourier->blockSignals(false);

    //Plot
    plot_ICP_fourier_curve();

    update_ICP_ifft_range();
}

/*!
 * \brief MainWindow::choose_ICP_max_fourier
 * \param pos
 */
void MainWindow::choose_ICP_max_fourier(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_fourier = pos;

    //Slider update
    ICP_slider_max_fourier->blockSignals(true);
    ICP_slider_max_fourier->setValue(pos);
    ICP_slider_max_fourier->blockSignals(false);

    //Plot
    plot_ICP_fourier_curve();

    update_ICP_ifft_range();
}

/*!
 * \brief MainWindow::choose_ICP_min_ifft
 * \param pos
 */
void MainWindow::choose_ICP_min_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_min_ifft = pos;

    //Slider update
    ICP_slider_min_ifft->blockSignals(true);
    ICP_slider_min_ifft->setValue(pos);
    ICP_slider_min_ifft->blockSignals(false);

    //Plot
    plot_ICP_ifft_min();
}

/*!
 * \brief MainWindow::choose_ICP_max_ifft
 * \param pos
 */
void MainWindow::choose_ICP_max_ifft(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_max_ifft = pos;

    //Slider update
    ICP_slider_max_ifft->blockSignals(true);
    ICP_slider_max_ifft->setValue(pos);
    ICP_slider_max_ifft->blockSignals(false);

    //Plot
    plot_ICP_ifft_max();
}

/*!
 * \brief MainWindow::choose_ICP_threshold
 * \param pos
 */
void MainWindow::choose_ICP_threshold(double pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Value update
    ICP_threshold = pos;

    //Slider update
    ICP_slider_threshold->blockSignals(true);
    ICP_slider_threshold->setValue(pos * (double)SLIDER_DOUBLE);
    ICP_slider_threshold->blockSignals(false);

    //Plot
    plot_ICP_threshold();
}
//*********//
//*********//

//************//
//***BUTTON***//
//************//
/*!
 * \brief MainWindow::do_ICP_quality
 */
void MainWindow::do_ICP_quality(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (!current_dir.isEmpty()){
        DialogQuality *dialog = new DialogQuality(current_dir, DIALOG_QUALITY_PARAM4, NULL, NULL, this);
        int res = dialog->exec();
        if (res == QDialog::Accepted){
            ICP_quality = get_ICP_quality_source(current_dir).toInt();
        }
        delete dialog;
    }
}

/*!
 * \brief MainWindow::do_ICP_fourier
 */
void MainWindow::do_ICP_fourier(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_select->size() > 0){
        //Fourier
        bool res = fourier(ICP_coord_fourier, *ICP_coord_select);

        if (res){
            //Min-Max
            int xmin = (int)ICP_coord_fourier->coord(0, XCOORD);
            int xmax = (int)ICP_coord_fourier->coord(ICP_coord_fourier->size()-1, XCOORD)+1000;

            //Sliders
            ICP_slider_min_fourier->setRange(xmin, xmax);
            ICP_slider_max_fourier->setRange(xmin, xmax);

            //Boxes
            ICP_box_min_fourier->setRange(xmin, xmax);
            ICP_box_max_fourier->setRange(xmin, xmax);

            ICP_box_min_fourier->setValue(xmax*ICP_coeff_fourier_min);
            ICP_box_max_fourier->setValue(xmax*ICP_coeff_fourier_max);

            //Plot
            plot_ICP_fourier_curve();

            //Sliders
            ICP_slider_min_ifft->setRange(1, xmax*ICP_coeff_fourier_max);
            ICP_slider_max_ifft->setRange(1, xmax*ICP_coeff_fourier_max);

            //Boxes
            ICP_box_min_ifft->setRange(1, xmax*ICP_coeff_fourier_max);
            ICP_box_max_ifft->setRange(1, xmax*ICP_coeff_fourier_max);
            ICP_box_min_ifft->setValue(xmax*ICP_coeff_ifft_min);
            ICP_box_max_ifft->setValue(xmax*ICP_coeff_ifft_max);

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
 * \brief MainWindow::do_ICP_ifft
 */
void MainWindow::do_ICP_ifft(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_select->size() != 0){
        bool res = ifft(ICP_coord_ifft, *ICP_coord_select, ICP_min_ifft, ICP_max_ifft);

        if(res){
            //Plot
            plot_ICP_ifft_curve();

            //Min-Max
            double ymin = min(ICP_coord_ifft->coords(YCOORD), ICP_coord_ifft->size());
            double ymax = max(ICP_coord_ifft->coords(YCOORD), ICP_coord_ifft->size());

            //Slider
            ICP_slider_threshold->setRange(ymin * (double)SLIDER_DOUBLE, ymax * (double)SLIDER_DOUBLE);

            //Box
            ICP_box_threshold->setRange(ymin, ymax);
            ICP_box_threshold->setValue((ymin+ymax)/2.);

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
 * \brief MainWindow::do_ICP_peaks
 */
void MainWindow::do_ICP_peaks(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_ifft->size() != 0){
        //Peaks detection
        detect_peaks(*ICP_coord_ifft, ICP_coord_peaks, ICP_threshold);

        //Plot
        plot_ICP_peaks();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_ICP_mean
 */
void MainWindow::do_ICP_mean(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_select->size() != 0 && ICP_coord_peaks->size() != 0){
        //Mean
        mean_icp(*ICP_coord_select, *ICP_coord_peaks, ICP_coord_mean, ICP_coord_SD);

        //Print
        double cycle = max(ICP_coord_mean->coords(XCOORD), ICP_coord_mean->size());
        double heartrate = 60./cycle;
        double pmin = min(ICP_coord_mean->coords(YCOORD), ICP_coord_mean->size());
        double pmax = max(ICP_coord_mean->coords(YCOORD), ICP_coord_mean->size());
        double pmean = mean(*ICP_coord_mean, YCOORD);
        double gradp = pmax - pmin;

        ICP_label_cycle->setText(MAINWINDOW_ICP_CC + QString::number(cycle) + UNITY_S);
        ICP_label_heartrate->setText(MAINWINDOW_ICP_HR + QString::number(heartrate) + UNITY_BPM);
        ICP_label_min->setText(MAINWINDOW_ICP_MIN_P + QString::number(pmin) + UNITY_MMHG);
        ICP_label_max->setText(MAINWINDOW_ICP_MAX_P + QString::number(pmax) + UNITY_MMHG);
        ICP_label_mean->setText(MAINWINDOW_ICP_MEAN_P + QString::number(pmean) + UNITY_MMHG);
        ICP_label_gradient->setText(MAINWINDOW_ICP_GRAD_P + QString::number(gradp) + UNITY_MMHG);

        //Plot
        plot_ICP_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_ICP_adjust
 */
void MainWindow::do_ICP_adjust(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_mean->size() != 0 && ICP_coord_SD->size() != 0){
        //Adjust
        adjust(ICP_coord_mean, ICP_coord_SD, ICP_box_adjust->currentText().toLower().toStdString());

        //Plot
        plot_ICP_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_ICP_normalize
 */
void MainWindow::do_ICP_normalize(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_mean->size() != 0 && ICP_coord_SD->size() != 0){
        //Normalize
        normalize(ICP_coord_mean, ICP_coord_SD);

        //Plot
        plot_ICP_mean_curve();

        //Status
        status_info("");
    }
    else{
        status_error("");
    }
}

/*!
 * \brief MainWindow::do_ICP_save
 */
void MainWindow::do_ICP_save(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (ICP_coord_mean->size() != 0 && ICP_coord_SD->size() != 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR + ICP_FILE_PRO;
        QString file_name_dat = current_dir + DIR_SEPARATOR + ICP_FILE_DAT;

        if (!file_name_pro.isEmpty()){
            //Save
            bool res = save_data(file_name_pro, ICP_coord_mean, ICP_coord_SD);
            if (!res){
                    //TODO
            }

            int n = ICP_DATA_LENGHT;
            string *string_list1 = new string[n];
            string *string_list2 = new string[n];

            string_list1[0] = ICP_DATA_ITEM01;  string_list2[0] = ICP_label_heartrate->text().remove(MAINWINDOW_ICP_HR).remove(UNITY_BPM).toStdString();
            string_list1[1] = ICP_DATA_ITEM02;  string_list2[1] = ICP_label_min->text().remove(MAINWINDOW_ICP_MIN_P).remove(UNITY_MMHG).toStdString();
            string_list1[2] = ICP_DATA_ITEM03;  string_list2[2] = ICP_label_max->text().remove(MAINWINDOW_ICP_MAX_P).remove(UNITY_MMHG).toStdString();
            string_list1[3] = ICP_DATA_ITEM04;  string_list2[3] = ICP_label_mean->text().remove(MAINWINDOW_ICP_MEAN_P).remove(UNITY_MMHG).toStdString();
            string_list1[4] = ICP_DATA_ITEM05;  string_list2[4] = ICP_label_gradient->text().remove(MAINWINDOW_ICP_GRAD_P).remove(UNITY_MMHG).toStdString();
            string_list1[5] = ICP_DATA_ITEM06;  string_list2[5] = QString::number(ICP_box_min_signal->value()).toStdString();
            string_list1[6] = ICP_DATA_ITEM07;  string_list2[6] = QString::number(ICP_box_max_signal->value()).toStdString();
            string_list1[7] = ICP_DATA_ITEM08;  string_list2[7] = QString::number(ICP_box_min_ifft->value()).toStdString();
            string_list1[8] = ICP_DATA_ITEM09;  string_list2[8] = QString::number(ICP_box_max_ifft->value()).toStdString();
            string_list1[9] = ICP_DATA_ITEM10;  string_list2[9] = QString::number(ICP_box_threshold->value()).toStdString();

            res = save_sup_data(file_name_dat, string_list1, string_list2, n);

            delete[] string_list1;
            delete[] string_list2;

            if (!res){
                //TODO
            }
        }
        else{
            //TODO
        }
    }
    else{
        //TODO
    }
}
//************//
//************//




//***********//
//***OTHER***//
//***********//
/*!
 * \brief MainWindow::save_ICP
 */
void MainWindow::save_ICP(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    do_ICP_save();
}

/*!
 * \brief MainWindow::clear_ICP
 */
void MainWindow::clear_ICP(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    ICP_coord_fourier->clear();
    ICP_coord_ifft->clear();
    ICP_coord_peaks->clear();
    ICP_coord_mean->clear();
    ICP_coord_SD->clear();

    ICP_plot_signal->graph(0)->clearData();
    ICP_plot_signal->graph(1)->clearData();
    ICP_plot_signal->graph(2)->clearData();
    ICP_plot_signal->graph(3)->clearData();
    ICP_plot_signal->graph(4)->clearData();
    ICP_plot_signal->replot();

    ICP_plot_select->graph(0)->clearData();
    ICP_plot_select->replot();

    ICP_plot_fourier->graph(0)->clearData();
    ICP_plot_fourier->graph(1)->clearData();
    ICP_plot_fourier->graph(2)->clearData();
    ICP_plot_fourier->graph(3)->clearData();
    ICP_plot_fourier->replot();

    ICP_plot_ifft->graph(0)->clearData();
    ICP_plot_ifft->graph(1)->clearData();
    ICP_plot_ifft->graph(2)->clearData();
    ICP_plot_ifft->replot();

    ICP_plot_mean->graph(0)->clearData();
    ICP_plot_mean->replot();

    ICP_label_cycle->clear();
    ICP_label_heartrate->clear();
    ICP_label_min->clear();
    ICP_label_max->clear();
    ICP_label_mean->clear();
    ICP_label_gradient->clear();
}
//***********//
//***********//


