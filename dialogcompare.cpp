#include "dialogcompare.h"

/*!
 * \brief DialogCompare::init_var
 *
 * Initialisation of DialogCompare variables
 */
void DialogCompare::init_var()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    //VBox
    vbox_volume_move = new QVBoxLayout;
    vbox_pressure_move = new QVBoxLayout;
    vbox_compliance_labels = new QVBoxLayout;
    vbox_compliance_cont_labels = new QVBoxLayout;

    //HBox
    hbox_compliance_buttons = new QHBoxLayout;
    hbox_compliance_cont_buttons = new QHBoxLayout;

    //Plot
    plot_volume = new QCustomPlot(this);
    plot_pressure = new QCustomPlot(this);
    plot_compliance = new QCustomPlot(this);
    plot_compliance_cont = new QCustomPlot(this);

    //Coord
    coord_volume = new Coord;
    coord_pressure = new Coord;
    coord_compliance = new Coord;
    coord_compliance_cont = new Coord;

    //Button
    button_move_volume_right = new QPushButton(this);
    button_move_volume_left = new QPushButton(this);
    button_move_pressure_right = new QPushButton(this);
    button_move_pressure_left = new QPushButton(this);
    button_smooth_compliance = new QPushButton(this);
    button_save_compliance = new QPushButton(this);
    button_filter_compliance_cont = new QPushButton(this);
    button_save_compliance_cont = new QPushButton(this);
    button_compliance = new QPushButton(this);
    button_close = new QPushButton(this);

    //Slider
    slider_first_bound = new QSlider(this);
    slider_second_bound = new QSlider(this);

    //SpinBox
    box_compliance_delay = new QSpinBox(this);
    box_compliance_filter = new QSpinBox(this);

    //Label
    label_compliance_global = new QLabel(this);

    label_compliance_delay = new QLabel(this);
    label_compliance_filter = new QLabel(this);

    label_compliance_min = new QLabel(this);
    label_compliance_max = new QLabel(this);
    label_compliance_mean = new QLabel(this);
    label_compliance_gradient = new QLabel(this);

    label_compliance_cont_min = new QLabel(this);
    label_compliance_cont_max = new QLabel(this);
    label_compliance_cont_mean = new QLabel(this);
    label_compliance_cont_gradient = new QLabel(this);

    //Double
    global_compliance = 0.;
    first_bound = 0.;
    second_bound = 0.;
}

/*!
 * \brief DialogCompare::init_win
 *
 * Initialisation of DialogCompare window
 */
void DialogCompare::init_win()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Double
    int max_x = max(coord_volume->coords(XCOORD), coord_volume->size());
    first_bound = max_x * DIALOG_COMPARE_BOUND1;
    second_bound = max_x * DIALOG_COMPARE_BOUND2;

    //Label
    label_compliance_delay->setText(DIALOG_COMPARE_DELAY_L);
    label_compliance_filter->setText(DIALOG_COMPARE_FILTER_L);

    //SpinBox
    int npi;
    bool res = get_npi(&npi);
    if (res){
        box_compliance_delay->setRange(0, npi);
        box_compliance_delay->setValue(10);
    }
    box_compliance_filter->setRange(0, 100);
    box_compliance_filter->setValue(10);

    //Slider
    slider_first_bound->setOrientation(Qt::Horizontal);
    slider_second_bound->setOrientation(Qt::Horizontal);

    slider_first_bound->setRange(min(coord_volume->coords(XCOORD), coord_volume->size())*SLIDER_DOUBLE, max(coord_volume->coords(XCOORD), coord_volume->size())*SLIDER_DOUBLE);
    slider_second_bound->setRange(min(coord_volume->coords(XCOORD), coord_volume->size())*SLIDER_DOUBLE, max(coord_volume->coords(XCOORD), coord_volume->size())*SLIDER_DOUBLE);

    slider_first_bound->setValue(first_bound*SLIDER_DOUBLE);
    slider_second_bound->setValue(second_bound*SLIDER_DOUBLE);

    //Button
    button_smooth_compliance->setText(DIALOG_COMPARE_SMOOTH);
    button_save_compliance->setText(DIALOG_COMPARE_SAVE);
    button_filter_compliance_cont->setText(DIALOG_COMPARE_FILTER);
    button_save_compliance_cont->setText(DIALOG_COMPARE_SAVE_CONT);
    button_compliance->setText(DIALOG_COMPARE_COMPLIANCE);
    button_close->setText(DIALOG_COMPARE_CLOSE);
    button_move_volume_right->setIcon(QIcon(IMG_RIGHT_ARROW));
    button_move_volume_left->setIcon(QIcon(IMG_LEFT_ARROW));
    button_move_pressure_right->setIcon(QIcon(IMG_RIGHT_ARROW));
    button_move_pressure_left->setIcon(QIcon(IMG_LEFT_ARROW));

    //Plot
    plot_volume->addGraph();            //volume
    plot_volume->addGraph();            //First bound
    plot_volume->addGraph();            //Second bound
    plot_volume->addGraph();            //Font1
    plot_volume->addGraph();            //Font2
    plot_volume->addGraph();            //Font3
    plot_pressure->addGraph();          //pressure
    plot_pressure->addGraph();          //First bound
    plot_pressure->addGraph();          //Second bound
    plot_pressure->addGraph();          //Font1
    plot_pressure->addGraph();          //Font2
    plot_pressure->addGraph();          //Font3
    plot_compliance->addGraph();        //compliance
    plot_compliance_cont->addGraph();   //compliance

    //VBox
    vbox_volume_move->addWidget(button_move_volume_right);
    vbox_volume_move->addWidget(button_move_volume_left);

    vbox_pressure_move->addWidget(button_move_pressure_right);
    vbox_pressure_move->addWidget(button_move_pressure_left);

    vbox_compliance_labels->addWidget(label_compliance_min);
    vbox_compliance_labels->addWidget(label_compliance_max);
    vbox_compliance_labels->addWidget(label_compliance_mean);
    vbox_compliance_labels->addWidget(label_compliance_gradient);
    vbox_compliance_labels->addWidget(button_save_compliance);

    vbox_compliance_cont_labels->addWidget(label_compliance_cont_min);
    vbox_compliance_cont_labels->addWidget(label_compliance_cont_max);
    vbox_compliance_cont_labels->addWidget(label_compliance_cont_mean);
    vbox_compliance_cont_labels->addWidget(label_compliance_cont_gradient);
    vbox_compliance_cont_labels->addWidget(button_save_compliance_cont);

    //HBox
    hbox_compliance_buttons->addWidget(button_compliance);
    hbox_compliance_buttons->addWidget(label_compliance_global);
    hbox_compliance_buttons->addWidget(button_smooth_compliance);

    hbox_compliance_cont_buttons->addWidget(label_compliance_delay);
    hbox_compliance_cont_buttons->addWidget(box_compliance_delay);
    hbox_compliance_cont_buttons->addWidget(label_compliance_filter);
    hbox_compliance_cont_buttons->addWidget(box_compliance_filter);
    hbox_compliance_cont_buttons->addWidget(button_filter_compliance_cont);

    //Grid
    setLayout(grid);

    grid->addWidget(slider_first_bound, 0, 0, 1, 3);
    grid->addWidget(slider_second_bound, 0, 3, 1, 3);
    grid->addWidget(plot_volume, 1, 0, 10, 10);
    grid->addLayout(vbox_volume_move, 1, 10, 10, 1);
    grid->addWidget(plot_pressure, 11, 0, 10, 10);
    grid->addLayout(vbox_pressure_move, 11, 10, 10, 1);
    grid->addLayout(hbox_compliance_buttons, 21, 0, 1, 11);
    grid->addWidget(plot_compliance, 22, 0, 10, 10);
    grid->addLayout(vbox_compliance_labels, 22, 10, 10, 1);
    grid->addLayout(hbox_compliance_cont_buttons, 32, 0, 1, 11);
    grid->addWidget(plot_compliance_cont, 33, 0, 10, 10);
    grid->addLayout(vbox_compliance_cont_labels, 33, 10, 10, 1);
    grid->addWidget(button_close, 100, 0, 2, 2);

    //Display
    plot_volume_curve();
    plot_pressure_curve();

    plot_first_bound(first_bound*SLIDER_DOUBLE);
    plot_second_bound(second_bound*SLIDER_DOUBLE);
}

/*!
 * \brief DialogCompare::init_sig
 *
 * Initialisation of DialogCompare signals
 */
void DialogCompare::init_sig()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Signals
    connect(button_move_volume_right, SIGNAL(clicked()), this, SLOT(do_move_volume_right()));
    connect(button_move_volume_left, SIGNAL(clicked()), this, SLOT(do_move_volume_left()));
    connect(button_move_pressure_right, SIGNAL(clicked()), this, SLOT(do_move_pressure_right()));
    connect(button_move_pressure_left, SIGNAL(clicked()), this, SLOT(do_move_pressure_left()));

    connect(button_smooth_compliance, SIGNAL(clicked()), this, SLOT(do_smooth_compliance()));
    connect(button_save_compliance, SIGNAL(clicked()), this, SLOT(do_save_compliance()));

    connect(button_filter_compliance_cont, SIGNAL(clicked()), this, SLOT(do_filter()));
    connect(button_save_compliance_cont, SIGNAL(clicked()), this, SLOT(do_save_compliance_cont()));

    connect(button_compliance, SIGNAL(clicked()), this, SLOT(do_compliance()));

    connect(button_close, SIGNAL(clicked()), this, SLOT(do_quit()));

    connect(slider_first_bound, SIGNAL(valueChanged(int)), this, SLOT(plot_first_bound(int)));
    connect(slider_second_bound, SIGNAL(valueChanged(int)), this, SLOT(plot_second_bound(int)));
}

/*!
 * \brief DialogCompare::init_css
 *
 * Initialisation of DialogCompare style sheet
 */
void DialogCompare::init_css()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    setWindowTitle(DIALOG_COMPARE_TITLE);

    //Style
    plot_volume->plotLayout()->insertRow(0);
    QCPPlotTitle *title_volume = new QCPPlotTitle(plot_volume, DIALOG_COMPARE_VOLUME);
    title_volume->setFont(QFont(DIALOG_COMPARE_FONT, DIALOG_COMPARE_FONT_SIZE));
    plot_volume->plotLayout()->addElement(0, 0, title_volume);
    plot_volume->graph(1)->setPen(QPen(Qt::red));
    plot_volume->graph(2)->setPen(QPen(Qt::green));
    plot_volume->graph(3)->setPen(QPen(Qt::red));
    plot_volume->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    plot_volume->graph(4)->setPen(QPen(Qt::green));
    plot_volume->graph(4)->setBrush(QPixmap(CSS_GRAPH_BRUSH_G));
    plot_volume->graph(5)->setPen(QPen(Qt::magenta));
    plot_volume->graph(5)->setBrush(QPixmap(CSS_GRAPH_BRUSH_M));

    plot_pressure->plotLayout()->insertRow(0);
    QCPPlotTitle *title_pressure = new QCPPlotTitle(plot_pressure, DIALOG_COMPARE_PRESSURE);
    title_pressure->setFont(QFont(DIALOG_COMPARE_FONT, DIALOG_COMPARE_FONT_SIZE));
    plot_pressure->plotLayout()->addElement(0, 0, title_pressure);
    plot_pressure->graph(1)->setPen(QPen(Qt::red));
    plot_pressure->graph(2)->setPen(QPen(Qt::green));
    plot_pressure->graph(3)->setPen(QPen(Qt::red));
    plot_pressure->graph(3)->setBrush(QPixmap(CSS_GRAPH_BRUSH_R));
    plot_pressure->graph(4)->setPen(QPen(Qt::green));
    plot_pressure->graph(4)->setBrush(QPixmap(CSS_GRAPH_BRUSH_G));
    plot_pressure->graph(5)->setPen(QPen(Qt::magenta));
    plot_pressure->graph(5)->setBrush(QPixmap(CSS_GRAPH_BRUSH_M));

    setStyleSheet(CSS_DIALOG);

    button_move_volume_right->setStyleSheet(CSS_BUTTON);
    button_move_volume_left->setStyleSheet(CSS_BUTTON);
    button_move_pressure_right->setStyleSheet(CSS_BUTTON);
    button_move_pressure_left->setStyleSheet(CSS_BUTTON);
    button_compliance->setStyleSheet(CSS_BUTTON);
    button_filter_compliance_cont->setStyleSheet(CSS_BUTTON);
    button_smooth_compliance->setStyleSheet(CSS_BUTTON);
    button_save_compliance->setStyleSheet(CSS_BUTTON);
    button_save_compliance_cont->setStyleSheet(CSS_BUTTON);
    button_close->setStyleSheet(CSS_BUTTON);

    slider_first_bound->setStyleSheet(CSS_SLIDER);
    slider_second_bound->setStyleSheet(CSS_SLIDER);

    box_compliance_delay->setStyleSheet(CSS_SPINBOX);
    box_compliance_filter->setStyleSheet(CSS_SPINBOX);

    label_compliance_global->setStyleSheet(CSS_LABEL_GLOBAL);

    label_compliance_delay->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_filter->setStyleSheet(CSS_LABEL_GLOBAL);

    label_compliance_min->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_max->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_mean->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_gradient->setStyleSheet(CSS_LABEL_GLOBAL);

    label_compliance_cont_min->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_cont_max->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_cont_mean->setStyleSheet(CSS_LABEL_GLOBAL);
    label_compliance_cont_gradient->setStyleSheet(CSS_LABEL_GLOBAL);
}

/*!
 * \brief DialogCompare::DialogCompare
 * \param current_dir Patient directory
 * \param current_flow Flow description
 * \param volume Volume curve
 * \param pressure Pressure curve
 * \param parent
 *
 * DialogCompare
 */
DialogCompare::DialogCompare(QString current_dir, QString current_flow,
                             Coord *volume, Coord *pressure,
                             QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();

    //String copy
    this->current_dir = QString(current_dir);
    this->current_flow = QString(current_flow);

    //Coord copy
    {
        coord_volume->set_size(volume->size());
        coord_pressure->set_size(pressure->size());

        double *x_norm = new double[volume->size()];
        for (int i = 0; i < volume->size(); i++){
            x_norm[i] = i/(volume->size()-1.);
        }

        coord_volume->set_coords(x_norm, volume->coords(YCOORD));
        coord_pressure->set_coords(x_norm, pressure->coords(YCOORD));

        delete[] x_norm;
    }

    init_win();
    init_sig();
    init_css();
}

/*!
 * \brief DialogCompare::plot_volume_curve
 *
 * Plot the volume curve
 */
void DialogCompare::plot_volume_curve()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_volume->size();

    if (n > 0){
        //Convert Coord to QVector
        QVector<double> x, y;
        for (int i = 0; i < n; i++){
            x.append(coord_volume->coord(i, XCOORD));
            y.append(coord_volume->coord(i, YCOORD));
        }

        //Plot
        plot_volume->graph(0)->setData(x, y);
        plot_volume->xAxis->setRange(min(x), max(x));
        plot_volume->yAxis->setRange(min(y), max(y));
        plot_volume->replot();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_001_N, COMP_DIAL_ERROR_001);
    }
}

/*!
 * \brief DialogCompare::plot_pressure_curve
 *
 * Plot the pressure curve
 */
void DialogCompare::plot_pressure_curve()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_pressure->size();

    if (n > 0){
        //Convert Coord to QVector
        QVector<double> x, y;
        for (int i = 0; i < n; i++){
            x.append(coord_pressure->coord(i, XCOORD));
            y.append(coord_pressure->coord(i, YCOORD));
        }

        //Plot
        plot_pressure->graph(0)->setData(x, y);
        plot_pressure->xAxis->setRange(min(x), max(x));
        plot_pressure->yAxis->setRange(min(y), max(y));
        plot_pressure->replot();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_002_N, COMP_DIAL_ERROR_002);
    }
}

/*!
 * \brief DialogCompare::plot_compliance_curve
 *
 * Plot the parted compliance curve
 */
void DialogCompare::plot_compliance_curve()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_compliance->size();

    if (n > 0){
        //Convert Coord to QVector
        QVector<double> x, y;
        for (int i = 0; i < n; i++){
            x.append(coord_compliance->coord(i, XCOORD));
            y.append(coord_compliance->coord(i, YCOORD));
        }

        //Plot
        plot_compliance->graph(0)->setData(x, y);
        plot_compliance->xAxis->setRange(min(x), max(x));
        plot_compliance->yAxis->setRange(min(y), max(y));
        plot_compliance->replot();

        //Print
        double ymin = min(y);
        double ymax = max(y);
        double ymean = mean(y);
        double ygradient = ymax - ymin;

        label_compliance_min->setText(QString::fromStdString(DIALOG_COMPARE_C_MIN) + QString::number(ymin));
        label_compliance_max->setText(QString::fromStdString(DIALOG_COMPARE_C_MAX) + QString::number(ymax));
        label_compliance_mean->setText(QString::fromStdString(DIALOG_COMPARE_C_MEAN) + QString::number(ymean));
        label_compliance_gradient->setText(QString::fromStdString(DIALOG_COMPARE_C_GRAD) + QString::number(ygradient));
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_003_N, COMP_DIAL_ERROR_003);
    }
}

/*!
 * \brief DialogCompare::plot_compliance_cont_curve
 *
 * Plot the continuous compliance curve
 */
void DialogCompare::plot_compliance_cont_curve()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_compliance_cont->size();

    if (n > 0){
        //Convert Coord to QVector
        QVector<double> x, y;
        for (int i = 0; i < n; i++){
            x.append(coord_compliance_cont->coord(i, XCOORD));
            y.append(coord_compliance_cont->coord(i, YCOORD));
        }

        //Plot
        plot_compliance_cont->graph(0)->setData(x, y);
        plot_compliance_cont->xAxis->setRange(min(x), max(x));
        plot_compliance_cont->yAxis->setRange(min(y), max(y));
        plot_compliance_cont->replot();

        //Print
        double ymin = min(y);
        double ymax = max(y);
        double ymean = mean(y);
        double ygradient = ymax - ymin;

        label_compliance_cont_min->setText(QString::fromStdString(DIALOG_COMPARE_CC_MIN) + QString::number(ymin));
        label_compliance_cont_max->setText(QString::fromStdString(DIALOG_COMPARE_CC_MAX) + QString::number(ymax));
        label_compliance_cont_mean->setText(QString::fromStdString(DIALOG_COMPARE_CC_MEAN) + QString::number(ymean));
        label_compliance_cont_gradient->setText(QString::fromStdString(DIALOG_COMPARE_CC_GRAD) + QString::number(ygradient));
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_004_N, COMP_DIAL_ERROR_004);
    }
}

/*!
 * \brief DialogCompare::plot_first_bound
 * \param pos Bound position
 *
 * Plot the first bound
 */
void DialogCompare::plot_first_bound(int pos)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    first_bound = pos/(double)SLIDER_DOUBLE;

    //QVector
    QVector<double> x, y;

    x.append(pos/(double)SLIDER_DOUBLE);
    y.append(min(coord_volume->coords(YCOORD), coord_volume->size()));

    x.append(pos/(double)SLIDER_DOUBLE);
    y.append(max(coord_volume->coords(YCOORD), coord_volume->size()));

    //Plot
    plot_volume->graph(1)->setData(x, y);

    plot_pressure->graph(1)->setData(x, y);

    plot_first_font();
    plot_second_font();
}

/*!
 * \brief DialogCompare::plot_second_bound
 * \param pos Bounbd position
 *
 * Plot the second bound
 */
void DialogCompare::plot_second_bound(int pos)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    second_bound = pos/(double)SLIDER_DOUBLE;

    //QVector
    QVector<double> x, y;

    x.append(pos/(double)SLIDER_DOUBLE);
    y.append(min(coord_volume->coords(YCOORD), coord_volume->size()));

    x.append(pos/(double)SLIDER_DOUBLE);
    y.append(max(coord_volume->coords(YCOORD), coord_volume->size()));

    //Plot
    plot_volume->graph(2)->setData(x, y);

    plot_pressure->graph(2)->setData(x, y);

    plot_second_font();
    plot_third_font();
}

/*!
 * \brief DialogCompare::plot_first_font
 *
 * Plot the font before the first bound
 */
void DialogCompare::plot_first_font()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Create QVector
    QVector<double> x, y, y2;
    x.append(0.);
    x.append(first_bound);
    y.append(plot_volume->yAxis->range().upper);
    y.append(plot_volume->yAxis->range().upper);
    y2.append(plot_pressure->yAxis->range().upper);
    y2.append(plot_pressure->yAxis->range().upper);

    //Plot
    plot_volume->graph(3)->setData(x, y);
    plot_volume->replot();

    plot_pressure->graph(3)->setData(x, y2);
    plot_pressure->replot();

}

/*!
 * \brief DialogCompare::plot_second_font
 *
 * Plot the font between first and second bounds
 */
void DialogCompare::plot_second_font()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (second_bound > first_bound){
        //Create QVector
        QVector<double> x, y, y2;
        x.append(first_bound);
        x.append(second_bound);
        y.append(plot_volume->yAxis->range().upper);
        y.append(plot_volume->yAxis->range().upper);
        y2.append(plot_pressure->yAxis->range().upper);
        y2.append(plot_pressure->yAxis->range().upper);

        //Plot
        plot_volume->graph(4)->setData(x, y);
        plot_volume->replot();

        plot_pressure->graph(4)->setData(x, y2);
        plot_pressure->replot();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_005_N, COMP_DIAL_ERROR_005);
    }
}

/*!
 * \brief DialogCompare::plot_third_font
 *
 * Plot the font after the second bound
 */
void DialogCompare::plot_third_font()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (second_bound > first_bound){
        //Create QVector
        QVector<double> x, y, y2;
        x.append(second_bound);
        x.append(max(coord_pressure->coords(YCOORD), coord_pressure->size()));
        y.append(plot_volume->yAxis->range().upper);
        y.append(plot_volume->yAxis->range().upper);
        y2.append(plot_pressure->yAxis->range().upper);
        y2.append(plot_pressure->yAxis->range().upper);

        //Plot
        plot_volume->graph(5)->setData(x, y);
        plot_volume->replot();

        plot_pressure->graph(5)->setData(x, y2);
        plot_pressure->replot();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_005_N, COMP_DIAL_ERROR_005);
    }
}

/*!
 * \brief DialogCompare::do_compliance
 *
 * Global, parted and continuous compliance calculus
 */
void DialogCompare::do_compliance()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Compliance calculs
    //Compliance = dV / dP

    {
        int n = coord_volume->size();

        double Vmin = min(coord_volume->coords(YCOORD), n);
        double Vmax = max(coord_volume->coords(YCOORD), n);
        double dV = Vmax - Vmin;

        double Pmin = min(coord_pressure->coords(YCOORD), n);
        double Pmax = max(coord_pressure->coords(YCOORD), n);
        double dP = Pmax - Pmin;

        global_compliance = dV / dP;

        label_compliance_global->setText(QString::fromStdString(DIALOG_COMPARE_C_GLOBAL) + QString::number(global_compliance));
    }

    {
        int n = coord_volume->size();

        coord_compliance->set_size(n);

        double dV = 0.;
        double dP = 0.;

        int i = 0;
        int pos1 = 0, pos2 = 0;
        double V0 = coord_volume->coord(i, YCOORD);
        double P0 = coord_pressure->coord(i, YCOORD);
        double V1 = 0., V2 = 0., V3 = 0.;
        double P1 = 0., P2 = 0., P3 = 0.;

        while(slider_first_bound->value()/(double)SLIDER_DOUBLE > coord_volume->coord(i, XCOORD)){
            pos1 = i;
            V1 = coord_volume->coord(i, YCOORD);
            P1 = coord_pressure->coord(i, YCOORD);
            i++;
        }

        while(slider_second_bound->value()/(double)SLIDER_DOUBLE > coord_volume->coord(i, XCOORD)){
            pos2 = i;
            V2 = coord_volume->coord(i, YCOORD);
            P2 = coord_pressure->coord(i, YCOORD);
            i++;
        }

        dV = V1 - V0;
        dP = P1 - P0;
        double C1 = dV/dP;

        dV = V2 - V1;
        dP = P2 - P1;
        double C2 = dV/dP;

        dV = V3 - V2;
        dP = P3 - P2;
        double C3 = dV/dP;

        for (int i = 0; i < n; i++){
            coord_compliance->set_coord(coord_volume->coord(i, XCOORD), i, XCOORD);
            if (i < pos1){
                coord_compliance->set_coord(C1, i, YCOORD);
            }
            else if (i >= pos1 && i < pos2){
                coord_compliance->set_coord(C2, i, YCOORD);
            }
            else{
                coord_compliance->set_coord(C3, i, YCOORD);
            }
        }

        //Plot
        plot_compliance_curve();
    }

    {
        //Calculus
        coord_compliance_cont = compliance_continuous(*coord_volume, *coord_pressure, box_compliance_delay->value());

        //Plot
        plot_compliance_cont_curve();
    }
}

/*!
 * \brief DialogCompare::do_filter
 *
 * Filter the continuous compliance curve
 */
void DialogCompare::do_filter(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    filter(coord_compliance_cont, box_compliance_filter->value());

    plot_compliance_cont_curve();
}

/*!
 * \brief DialogCompare::do_smooth_compliance
 *
 * Smooth parted compliance curve
 */
void DialogCompare::do_smooth_compliance()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_compliance->size();

    if (n > 0){
        //Smooth
        coord_compliance = smooth(*coord_compliance);

        //Plot
        plot_compliance_curve();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_003_N, COMP_DIAL_ERROR_003);
    }
}

/*!
 * \brief DialogCompare::do_move_volume_right
 *
 * Move volume curve right
 */
void DialogCompare::do_move_volume_right()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_volume->size();

    if (n > 0){
        double volume_end = coord_volume->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            coord_volume->set_coord(coord_volume->coord(i-1, YCOORD), i, YCOORD);
        }
        coord_volume->set_coord(volume_end, 0, YCOORD);

        plot_volume_curve();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_001_N, COMP_DIAL_ERROR_001);
    }
}

/*!
 * \brief DialogCompare::do_move_volume_left
 *
 * Move volume curve left
 */
void DialogCompare::do_move_volume_left()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_volume->size();

    if (n != 0){
        double volume_begin = coord_volume->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            coord_volume->set_coord(coord_volume->coord(i+1, YCOORD), i, YCOORD);
        }
        coord_volume->set_coord(volume_begin, n-1, YCOORD);

        plot_volume_curve();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_001_N, COMP_DIAL_ERROR_001);
    }
}

/*!
 * \brief DialogCompare::do_move_pressure_right
 *
 * Move pressure curve right
 */
void DialogCompare::do_move_pressure_right()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_pressure->size();

    if (n != 0){
        double pressure_end = coord_pressure->coord(n-1, YCOORD);
        for (int i = n-1; i >= 0; i--){
            coord_pressure->set_coord(coord_pressure->coord(i-1, YCOORD), i, YCOORD);
        }
        coord_pressure->set_coord(pressure_end, 0, YCOORD);

        plot_pressure_curve();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_002_N, COMP_DIAL_ERROR_002);
    }
}

/*!
 * \brief DialogCompare::do_move_pressure_left
 *
 * Move pressure curve left
 */
void DialogCompare::do_move_pressure_left()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_pressure->size();

    if (n != 0){
        double pressure_begin = coord_pressure->coord(0, YCOORD);
        for (int i = 0; i < n-1; i++){
            coord_pressure->set_coord(coord_pressure->coord(i+1, YCOORD), i, YCOORD);
        }
        coord_pressure->set_coord(pressure_begin, n-1, YCOORD);

        plot_pressure_curve();
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_002_N, COMP_DIAL_ERROR_002);
    }
}

/*!
 * \brief DialogCompare::do_save_compliance
 *
 * Save global and parted compliances
 */
void DialogCompare::do_save_compliance()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_compliance->size();
    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR;

        QString file_name_dat = QString(file_name_pro);
        QString file_name_dat2 = QString(file_name_pro);

        if (current_flow.compare(MAINWINDOW_COMPARE_AV_CERV) == 0){
            file_name_pro += COMPLIANCE_AV_CERVICAL_FILE;
            file_name_dat += COMPLIANCE_AV_CERVICAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_AV_CERVICAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_ICVC_CERV) == 0){
            file_name_pro += COMPLIANCE_ICVC_CERVICAL_FILE;
            file_name_dat += COMPLIANCE_ICVC_CERVICAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_ICVC_CERVICAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_AV_CERE) == 0){
            file_name_pro += COMPLIANCE_AV_CEREBRAL_FILE;
            file_name_dat += COMPLIANCE_AV_CEREBRAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_AV_CEREBRAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_ICVC_CERE) == 0){
            file_name_pro += COMPLIANCE_ICVC_CEREBRAL_FILE;
            file_name_dat += COMPLIANCE_ICVC_CEREBRAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_ICVC_CEREBRAL_FILE_DAT;
        }

        if (!file_name_pro.isEmpty()){
            //DATA
            bool res = save_data(file_name_pro, coord_compliance, NULL);

            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_006_N, COMP_DIAL_ERROR_006);
            }

            //SUP DATA
            n = COMPLIANCE_DATA_LENGTH;
            string *list1 = new string[n];
            string *list2 = new string[n];

            list1[0] = COMPLIANCE_DATA_ITEM01;      list2[0] = label_compliance_min->text().remove(DIALOG_COMPARE_C_MIN).toStdString();
            list1[1] = COMPLIANCE_DATA_ITEM02;      list2[1] = label_compliance_max->text().remove(DIALOG_COMPARE_C_MAX).toStdString();
            list1[2] = COMPLIANCE_DATA_ITEM03;      list2[2] = label_compliance_mean->text().remove(DIALOG_COMPARE_C_MEAN).toStdString();
            list1[3] = COMPLIANCE_DATA_ITEM04;      list2[3] = label_compliance_gradient->text().remove(DIALOG_COMPARE_C_GRAD).toStdString();

            res = save_sup_data(file_name_dat, list1, list2, n);

            delete[] list1;
            delete[] list2;

            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_007_N, COMP_DIAL_ERROR_007);
            }

            n = COMPLIANCE_G_DATA_LENGTH;
            string *list_bis1 = new string[n];
            string *list_bis2 = new string[n];

            list_bis1[0] = COMPLIANCE_G_DATA_ITEM01;    list_bis2[0] = label_compliance_global->text().remove(DIALOG_COMPARE_C_GLOBAL).toStdString();

            res = save_sup_data(file_name_dat2, list_bis1, list_bis2, n);

            delete[] list_bis1;
            delete[] list_bis2;

            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_008_N, COMP_DIAL_ERROR_008);
            }
        }
        else{
            QMessageBox::critical(this, COMP_DIAL_ERROR_009_N, COMP_DIAL_ERROR_009);
        }
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_003_N, COMP_DIAL_ERROR_003);
    }
}

/*!
 * \brief DialogCompare::do_save_compliance_cont
 *
 * Save global and continuous compliances
 */
void DialogCompare::do_save_compliance_cont()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_compliance_cont->size();

    if (n > 0){
        QString file_name_pro = current_dir + DIR_SEPARATOR;

        QString file_name_dat = QString(file_name_pro);
        QString file_name_dat2 = QString(file_name_pro);
        if (current_flow.compare(MAINWINDOW_COMPARE_AV_CERV) == 0){
            file_name_pro += COMPLIANCE_C_AV_CERVICAL_FILE;
            file_name_dat += COMPLIANCE_C_AV_CERVICAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_AV_CERVICAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_ICVC_CERV) == 0){
            file_name_pro += COMPLIANCE_C_ICVC_CERVICAL_FILE;
            file_name_dat += COMPLIANCE_C_ICVC_CERVICAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_ICVC_CERVICAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_AV_CERE) == 0){
            file_name_pro += COMPLIANCE_C_AV_CEREBRAL_FILE;
            file_name_dat += COMPLIANCE_C_AV_CEREBRAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_AV_CEREBRAL_FILE_DAT;
        }
        else if (current_flow.compare(MAINWINDOW_COMPARE_ICVC_CERE) == 0){
            file_name_pro += COMPLIANCE_C_ICVC_CEREBRAL_FILE;
            file_name_dat += COMPLIANCE_C_ICVC_CEREBRAL_FILE_DAT;
            file_name_dat2 += COMPLIANCE_G_ICVC_CEREBRAL_FILE_DAT;
        }

        if (!file_name_pro.isEmpty()){
            //DATA
            bool res = save_data(file_name_pro, coord_compliance_cont, NULL);
            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_006_N, COMP_DIAL_ERROR_006);
            }

            //SUP DATA
            n = COMPLIANCE_DATA_LENGTH;
            string *list1 = new string[n];
            string *list2 = new string[n];

            list1[0] = COMPLIANCE_DATA_ITEM01;  list2[0] = label_compliance_cont_min->text().remove(DIALOG_COMPARE_CC_MIN).toStdString();
            list1[1] = COMPLIANCE_DATA_ITEM02;  list2[1] = label_compliance_cont_max->text().remove(DIALOG_COMPARE_CC_MAX).toStdString();
            list1[2] = COMPLIANCE_DATA_ITEM03;  list2[2] = label_compliance_cont_mean->text().remove(DIALOG_COMPARE_CC_MEAN).toStdString();
            list1[3] = COMPLIANCE_DATA_ITEM04;  list2[3] = label_compliance_cont_gradient->text().remove(DIALOG_COMPARE_CC_GRAD).toStdString();

            res = save_sup_data(file_name_dat, list1, list2, n);

            delete[] list1;
            delete[] list2;

            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_007_N, COMP_DIAL_ERROR_007);
            }

            n = COMPLIANCE_G_DATA_LENGTH;
            string *list_bis1 = new string[n];
            string *list_bis2 = new string[n];

            list_bis1[0] = COMPLIANCE_G_DATA_ITEM01;    list_bis2[0] = label_compliance_global->text().remove(DIALOG_COMPARE_C_GLOBAL).toStdString();

            res = save_sup_data(file_name_dat2, list_bis1, list_bis2, n);

            delete[] list_bis1;
            delete[] list_bis2;

            if (!res){
                QMessageBox::critical(this, COMP_DIAL_ERROR_008_N, COMP_DIAL_ERROR_008);
            }
        }
        else{
            QMessageBox::critical(this, COMP_DIAL_ERROR_009_N, COMP_DIAL_ERROR_009);
        }
    }
    else{
        QMessageBox::critical(this, COMP_DIAL_ERROR_004_N, COMP_DIAL_ERROR_004);
    }
}

/*!
 * \brief DialogCompare::do_quit
 *
 * Quit DialogCompare
 */
void DialogCompare::do_quit()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    accept();
}

/*!
 * \brief DialogCompare::closeEvent
 *
 * REIMPLEMENTED Quit DialogCompare by red-cross click
 */
void DialogCompare::closeEvent(QCloseEvent *)
{
    if (DEBUG) cout << Q_FUNC_INFO << " -- REIMPLEMENTED" << endl;
}


