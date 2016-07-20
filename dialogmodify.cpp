#include "dialogmodify.h"

/*!
 * \brief DialogModify::init_var
 */
void DialogModify::init_var(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Tab
    tab = new QTabWidget(this);

    //Widget
    tab_cervical_cerebral = new QWidget(this);
    tab_other = new QWidget(this);

    //Grid
    grid = new QGridLayout(this);
    grid_cervical_cerebral = new QGridLayout(tab_cervical_cerebral);
    grid_other = new QGridLayout(tab_other);

    //Plot
    plot_arterial_cervical = new QCustomPlot(this);
    plot_venous_cervical = new QCustomPlot(this);
    plot_CSF_cervical = new QCustomPlot(this);

    plot_arterial_cerebral = new QCustomPlot(this);
    plot_venous_cerebral = new QCustomPlot(this);
    plot_CSF_cerebral = new QCustomPlot(this);

    plot_arterial_other = new QCustomPlot(this);
    plot_venous_other = new QCustomPlot(this);
    plot_CSF_other = new QCustomPlot(this);

    //Label
    label_cervical = new QLabel(this);
    label_cerebral = new QLabel(this);

    label_value_arterial_cervical = new QLabel(this);
    label_value_venous_cervical = new QLabel(this);
    label_value_CSF_cervical = new QLabel(this);

    label_value_arterial_cerebral = new QLabel(this);
    label_value_venous_cerebral = new QLabel(this);
    label_value_CSF_cerebral = new QLabel(this);

    label_value_arterial_other = new QLabel(this);
    label_value_venous_other = new QLabel(this);
    label_value_CSF_other = new QLabel(this);

    //SpinBox
    box_value_arterial_cervical = new QDoubleSpinBox(this);
    box_value_venous_cervical = new QDoubleSpinBox(this);
    box_value_CSF_cervical = new QDoubleSpinBox(this);

    box_value_arterial_cerebral = new QDoubleSpinBox(this);
    box_value_venous_cerebral = new QDoubleSpinBox(this);
    box_value_CSF_cerebral = new QDoubleSpinBox(this);

    box_value_arterial_other = new QDoubleSpinBox(this);
    box_value_venous_other = new QDoubleSpinBox(this);
    box_value_CSF_other = new QDoubleSpinBox(this);

    //Button
    button_modify_arterial_cervical = new QPushButton(this);
    button_modify_venous_cervical = new QPushButton(this);
    button_modify_CSF_cervical = new QPushButton(this);
    button_auto_modify_arterial_cervical = new QPushButton(this);
    button_auto_modify_venous_cervical = new QPushButton(this);
    button_auto_modify_CSF_cervical = new QPushButton(this);

    button_modify_arterial_cerebral = new QPushButton(this);
    button_modify_venous_cerebral = new QPushButton(this);
    button_modify_CSF_cerebral = new QPushButton(this);
    button_auto_modify_arterial_cerebral = new QPushButton(this);
    button_auto_modify_venous_cerebral = new QPushButton(this);
    button_auto_modify_CSF_cerebral = new QPushButton(this);

    button_modify_arterial_other = new QPushButton(this);
    button_modify_venous_other = new QPushButton(this);
    button_modify_CSF_other = new QPushButton(this);
    button_auto_modify_arterial_other = new QPushButton(this);
    button_auto_modify_venous_other = new QPushButton(this);
    button_auto_modify_CSF_other = new QPushButton(this);
    button_auto_modify_all_arterial_other = new QPushButton(this);
    button_auto_modify_all_venous_other = new QPushButton(this);
    button_auto_modify_all_CSF_other = new QPushButton(this);
    button_choice_arterial = new QPushButton(this);
    button_choice_venous = new QPushButton(this);
    button_choice_CSF = new QPushButton(this);

    button_modify = new QPushButton(this);
    button_cancel = new QPushButton(this);

    //Menu
    menu_choice_arterial = new QMenu(this);
    menu_choice_venous = new QMenu(this);
    menu_choice_CSF = new QMenu(this);

    //CheckBox
    check_venous_cervical = new QCheckBox(this);
    check_CSF_cervical = new QCheckBox(this);

    check_arterial_cerebral = new QCheckBox(this);
    check_venous_cerebral = new QCheckBox(this);
    check_CSF_cerebral = new QCheckBox(this);

    check_venous_other = new QCheckBox(this);
    check_CSF_other = new QCheckBox(this);

    //Coord
    coord_arterial_cervical = new Coord;
    coord_venous_cervical = new Coord;
    coord_CSF_cervical = new Coord;

    coord_arterial_cerebral = new Coord;
    coord_venous_cerebral = new Coord;
    coord_CSF_cerebral = new Coord;

    coords_arterial = NULL;
    coords_venous = NULL;
    coords_CSF = NULL;

    //String
    dir = EMPTY_STRING;

    //Int
    point_arterial_cervical = -1;
    point_venous_cervical = -1;
    point_CSF_cervical = -1;

    point_arterial_cerebral = -1;
    point_venous_cerebral = -1;
    point_CSF_cerebral = -1;

    n_arterial = 0;
    n_venous = 0;
    n_CSF = 0;

    curve_arterial_other = -1;
    point_arterial_other = -1;
    curve_venous_other = -1;
    point_venous_other = -1;
    curve_CSF_other = -1;
    point_CSF_other = -1;

    arterial_cervical_modified = 0;
    venous_cervical_modified = 0;
    CSF_cervical_modified = 0;

    arterial_cerebral_modified = 0;
    venous_cerebral_modified = 0;
    CSF_cerebral_modified = 0;

    arterial_other_modified = 0;
    venous_other_modified = 0;
    CSF_other_modified = 0;
}

/*!
 * \brief DialogModify::init_win
 */
void DialogModify::init_win(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Dialog
    setModal(true);
    setLayout(grid);
    setWindowFlags(this->windowFlags() | Qt::WindowMinMaxButtonsHint);

    //Tab
    tab->addTab(tab_cervical_cerebral, "Cervical/Cerebral");
    tab->addTab(tab_other, "Other");

    //Grid
    tab_cervical_cerebral->setLayout(grid_cervical_cerebral);
    tab_other->setLayout(grid_other);

    //Plot
    plot_arterial_cervical->addGraph();
    plot_venous_cervical->addGraph();
    plot_CSF_cervical->addGraph();

    plot_arterial_cerebral->addGraph();
    plot_venous_cerebral->addGraph();
    plot_CSF_cerebral->addGraph();

    //other: later

    //Label
    label_cervical->setText("Cervical");
    label_cerebral->setText("Cerebral");

    label_value_arterial_cervical->setText("Value");
    label_value_venous_cervical->setText("Value");
    label_value_CSF_cervical->setText("Value");

    label_value_arterial_cerebral->setText("Value");
    label_value_venous_cerebral->setText("Value");
    label_value_CSF_cerebral->setText("Value");

    //SpinBox
    box_value_arterial_cervical->setRange(-1e10, 1e10);
    box_value_venous_cervical->setRange(-1e10, 1e10);
    box_value_CSF_cervical->setRange(-1e10, 1e10);

    box_value_arterial_cerebral->setRange(-1e10, 1e10);
    box_value_venous_cerebral->setRange(-1e10, 1e10);
    box_value_CSF_cerebral->setRange(-1e10, 1e10);

    box_value_arterial_other->setRange(-1e10, 1e10);
    box_value_venous_other->setRange(-1e10, 1e10);
    box_value_CSF_other->setRange(-1e10, 1e10);

    //Button
    button_modify_arterial_cervical->setText("Modify value");
    button_modify_venous_cervical->setText("Modify value");
    button_modify_CSF_cervical->setText("Modify value");
    button_auto_modify_arterial_cervical->setText("Auto modify value");
    button_auto_modify_venous_cervical->setText("Auto modify value");
    button_auto_modify_CSF_cervical->setText("Auto modify value");

    button_modify_arterial_cerebral->setText("Modify value");
    button_modify_venous_cerebral->setText("Modify value");
    button_modify_CSF_cerebral->setText("Modify value");
    button_auto_modify_arterial_cerebral->setText("Auto modify value");
    button_auto_modify_venous_cerebral->setText("Auto modify value");
    button_auto_modify_CSF_cerebral->setText("Auto modify value");

    button_modify_arterial_other->setText("Modify value");
    button_modify_venous_other->setText("Modify value");
    button_modify_CSF_other->setText("Modify value");
    button_auto_modify_arterial_other->setText("Auto modify value");
    button_auto_modify_venous_other->setText("Auto modify value");
    button_auto_modify_CSF_other->setText("Auto modify value");
    button_auto_modify_all_arterial_other->setText("Auto modify all value");
    button_auto_modify_all_venous_other->setText("Auto modify all value");
    button_auto_modify_all_CSF_other->setText("Auto modify all value");
    button_choice_arterial->setMenu(menu_choice_arterial);
    button_choice_venous->setMenu(menu_choice_venous);
    button_choice_CSF->setMenu(menu_choice_CSF);

    button_modify->setText("Modify");
    button_cancel->setText("Cancel");

    //Menu
    menu_choice_arterial->setTitle("Arterial");
    menu_choice_venous->setTitle("Venous");
    menu_choice_CSF->setTitle("CSF");

    //CheckBox
    check_venous_cervical->setText("Apply here (auto)");
    check_CSF_cervical->setText("Apply here (auto)");

    check_arterial_cerebral->setText("Apply here (auto)");
    check_venous_cerebral->setText("Apply here (auto)");
    check_CSF_cerebral->setText("Apply here (auto)");

    check_venous_other->setText("Apply here (all auto)");
    check_CSF_other->setText("Apply here (all auto)");

    check_venous_cervical->setChecked(true);
    check_CSF_cervical->setChecked(true);

    check_arterial_cerebral->setChecked(true);
    check_venous_cerebral->setChecked(true);
    check_CSF_cerebral->setChecked(true);

    check_venous_other->setChecked(true);
    check_CSF_other->setChecked(true);

    //Grid
    grid->addWidget(tab, 0, 0, 10, 10);

    grid->addWidget(button_cancel, 10, 0, 1, 5);
    grid->addWidget(button_modify, 10, 5, 1, 5);


    grid_cervical_cerebral->addWidget(label_cervical, 0, 0, 1, 14, Qt::AlignCenter);
    grid_cervical_cerebral->addWidget(label_cerebral, 0, 16, 1, 14, Qt::AlignCenter);

    grid_cervical_cerebral->addWidget(plot_arterial_cervical, 10, 0, 10, 10);
    grid_cervical_cerebral->addWidget(label_value_arterial_cervical, 10, 10, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_arterial_cervical, 11, 10, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_arterial_cervical, 10, 11, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_arterial_cervical, 12, 10, 1, 2);

    grid_cervical_cerebral->addWidget(plot_venous_cervical, 20, 0, 10, 10);
    grid_cervical_cerebral->addWidget(check_venous_cervical, 20, 10, 1, 1);
    grid_cervical_cerebral->addWidget(label_value_venous_cervical, 21, 10, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_venous_cervical, 22, 10, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_venous_cervical, 21, 11, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_venous_cervical, 23, 10, 1, 2);

    grid_cervical_cerebral->addWidget(plot_CSF_cervical, 30, 0, 10, 10);
    grid_cervical_cerebral->addWidget(check_CSF_cervical, 30, 10, 1, 1);
    grid_cervical_cerebral->addWidget(label_value_CSF_cervical, 31, 10, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_CSF_cervical, 32, 10, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_CSF_cervical, 31, 11, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_CSF_cervical, 33, 10, 1, 2);

    grid_cervical_cerebral->addWidget(plot_arterial_cerebral, 10, 15, 10, 10);
    grid_cervical_cerebral->addWidget(check_arterial_cerebral, 10, 25, 1, 1);
    grid_cervical_cerebral->addWidget(label_value_arterial_cerebral, 11, 25, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_arterial_cerebral, 12, 25, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_arterial_cerebral, 11, 26, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_arterial_cerebral, 13, 25, 1, 2);

    grid_cervical_cerebral->addWidget(plot_venous_cerebral, 20, 15, 10, 10);
    grid_cervical_cerebral->addWidget(check_venous_cerebral, 20, 25, 1, 1);
    grid_cervical_cerebral->addWidget(label_value_venous_cerebral, 21, 25, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_venous_cerebral, 22, 25, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_venous_cerebral, 21, 26, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_venous_cerebral, 23, 25, 1, 2);

    grid_cervical_cerebral->addWidget(plot_CSF_cerebral, 30, 15, 10, 10);
    grid_cervical_cerebral->addWidget(check_CSF_cerebral, 30, 25, 1, 1);
    grid_cervical_cerebral->addWidget(label_value_CSF_cerebral, 31, 25, 1, 1);
    grid_cervical_cerebral->addWidget(box_value_CSF_cerebral, 32, 25, 1, 1);
    grid_cervical_cerebral->addWidget(button_modify_CSF_cerebral, 31, 26, 2, 1);
    grid_cervical_cerebral->addWidget(button_auto_modify_CSF_cerebral, 33, 25, 1, 2);


    grid_other->addWidget(plot_arterial_other, 10, 0, 10, 10);
    grid_other->addWidget(button_choice_arterial, 10, 10, 1, 5);
    grid_other->addWidget(label_value_arterial_other, 11, 10, 1, 5);
    grid_other->addWidget(box_value_arterial_other, 12, 10, 1, 3);
    grid_other->addWidget(button_modify_arterial_other, 12, 13, 1, 2);
    grid_other->addWidget(button_auto_modify_arterial_other, 13, 10, 1, 5);
    grid_other->addWidget(button_auto_modify_all_arterial_other, 14, 10, 1, 5);

    grid_other->addWidget(plot_venous_other, 20, 0, 10, 10);
    grid_other->addWidget(button_choice_venous, 20, 10, 1, 5);
    grid_other->addWidget(check_venous_other, 21, 10, 1, 1);
    grid_other->addWidget(label_value_venous_other, 21, 11, 1, 4);
    grid_other->addWidget(box_value_venous_other, 22, 10, 1, 3);
    grid_other->addWidget(button_modify_venous_other, 22, 13, 1, 2);
    grid_other->addWidget(button_auto_modify_venous_other, 23, 10, 1, 5);
    grid_other->addWidget(button_auto_modify_all_venous_other, 24, 10, 1, 5);

    grid_other->addWidget(plot_CSF_other, 30, 0, 10, 10);
    grid_other->addWidget(button_choice_CSF, 30, 10, 1, 5);
    grid_other->addWidget(check_CSF_other, 31, 10, 1, 1);
    grid_other->addWidget(label_value_CSF_other, 31, 11, 1, 4);
    grid_other->addWidget(box_value_CSF_other, 32, 10, 1, 3);
    grid_other->addWidget(button_modify_CSF_other, 32, 13, 1, 2);
    grid_other->addWidget(button_auto_modify_CSF_other, 33, 10, 1, 5);
    grid_other->addWidget(button_auto_modify_all_CSF_other, 34, 10, 1, 5);
}

/*!
 * \brief DialogModify::init_sig
 */
void DialogModify::init_sig(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    connect(plot_arterial_cervical, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_arterial_cervical(QMouseEvent*)));
    connect(plot_venous_cervical, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_venous_cervical(QMouseEvent*)));
    connect(plot_CSF_cervical, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_CSF_cervical(QMouseEvent*)));

    connect(plot_arterial_cerebral, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_arterial_cerebral(QMouseEvent*)));
    connect(plot_venous_cerebral, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_venous_cerebral(QMouseEvent*)));
    connect(plot_CSF_cerebral, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_CSF_cerebral(QMouseEvent*)));

    connect(plot_arterial_other, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_arterial_other(QMouseEvent*)));
    connect(plot_venous_other, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_venous_other(QMouseEvent*)));
    connect(plot_CSF_other, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_point_CSF_other(QMouseEvent*)));

    connect(button_modify_arterial_cervical, SIGNAL(clicked()), this, SLOT(modify_arterial_cervical()));
    connect(button_modify_venous_cervical, SIGNAL(clicked()), this, SLOT(modify_venous_cervical()));
    connect(button_modify_CSF_cervical, SIGNAL(clicked()), this, SLOT(modify_CSF_cervical()));

    connect(button_modify_arterial_cerebral, SIGNAL(clicked()), this, SLOT(modify_arterial_cerebral()));
    connect(button_modify_venous_cerebral, SIGNAL(clicked()), this, SLOT(modify_venous_cerebral()));
    connect(button_modify_CSF_cerebral, SIGNAL(clicked()), this, SLOT(modify_CSF_cerebral()));

    connect(button_modify_arterial_other, SIGNAL(clicked()), this, SLOT(modify_arterial_other()));
    connect(button_modify_venous_other, SIGNAL(clicked()), this, SLOT(modify_venous_other()));
    connect(button_modify_CSF_other, SIGNAL(clicked()), this, SLOT(modify_CSF_other()));

    connect(button_auto_modify_arterial_cervical, SIGNAL(clicked()), this, SLOT(auto_modify_arterial_cervical()));
    connect(button_auto_modify_venous_cervical, SIGNAL(clicked()), this, SLOT(auto_modify_venous_cervical()));
    connect(button_auto_modify_CSF_cervical, SIGNAL(clicked()), this, SLOT(auto_modify_CSF_cervical()));

    connect(button_auto_modify_arterial_cerebral, SIGNAL(clicked()), this, SLOT(auto_modify_arterial_cerebral()));
    connect(button_auto_modify_venous_cerebral, SIGNAL(clicked()), this, SLOT(auto_modify_venous_cerebral()));
    connect(button_auto_modify_CSF_cerebral, SIGNAL(clicked()), this, SLOT(auto_modify_CSF_cerebral()));

    connect(button_auto_modify_arterial_other, SIGNAL(clicked()), this, SLOT(auto_modify_arterial_other()));
    connect(button_auto_modify_venous_other, SIGNAL(clicked()), this, SLOT(auto_modify_venous_other()));
    connect(button_auto_modify_CSF_other, SIGNAL(clicked()), this, SLOT(auto_modify_CSF_other()));

    connect(button_auto_modify_all_arterial_other, SIGNAL(clicked()), this, SLOT(auto_modify_all_arterial_other()));
    connect(button_auto_modify_all_venous_other, SIGNAL(clicked()), this, SLOT(auto_modify_all_venous_other()));
    connect(button_auto_modify_all_CSF_other, SIGNAL(clicked()), this, SLOT(auto_modify_all_CSF_other()));

    for (int i = 0; i < n_arterial; i++){
        connect(menu_choice_arterial->actions().at(i), SIGNAL(triggered()), this, SLOT(do_plot_arterial_other()));
    }
    for (int i = 0; i < n_venous; i++){
        connect(menu_choice_venous->actions().at(i), SIGNAL(triggered()), this, SLOT(do_plot_venous_other()));
    }
    for (int i = 0; i < n_CSF; i++){
        connect(menu_choice_CSF->actions().at(i), SIGNAL(triggered()), this, SLOT(do_plot_CSF_other()));
    }

    connect(button_cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(button_modify, SIGNAL(clicked()), this, SLOT(modify()));
}

/*!
 * \brief DialogModify::init_css
 */
void DialogModify::init_css(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Dialog
    setStyleSheet(CSS_DIALOG);

    //Plot
    QPen reddotpen;
    reddotpen.setColor(Qt::red);
    reddotpen.setStyle(Qt::DashLine);
    QPen bluedotpen;
    bluedotpen.setColor(Qt::blue);
    bluedotpen.setStyle(Qt::DashLine);
    QPen greendotpen;
    greendotpen.setColor(Qt::green);
    greendotpen.setStyle(Qt::DashLine);

    plot_arterial_cervical->graph(0)->setPen(reddotpen);
    plot_arterial_cervical->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    plot_venous_cervical->graph(0)->setPen(bluedotpen);
    plot_venous_cervical->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    plot_CSF_cervical->graph(0)->setPen(greendotpen);
    plot_CSF_cervical->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    plot_arterial_cerebral->graph(0)->setPen(reddotpen);
    plot_arterial_cerebral->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    plot_venous_cerebral->graph(0)->setPen(bluedotpen);
    plot_venous_cerebral->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    plot_CSF_cerebral->graph(0)->setPen(greendotpen);
    plot_CSF_cerebral->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    for (int i = 0; i < n_arterial; i++){
        plot_arterial_other->graph(i)->setPen(reddotpen);
        plot_arterial_other->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    }

    for (int i = 0; i < n_venous; i++){
        plot_venous_other->graph(i)->setPen(bluedotpen);
        plot_venous_other->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    }

    for (int i = 0; i < n_CSF; i++){
        plot_CSF_other->graph(i)->setPen(greendotpen);
        plot_CSF_other->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));
    }
}

/*!
 * \brief DialogModify::DialogModify
 * \param parent
 */
DialogModify::DialogModify(QString current_dir,
                           Coord *EXT__coord_arterial_cervical,
                           Coord *EXT__coord_venous_cervical,
                           Coord *EXT__coord_CSF_cervical,
                           Coord *EXT__coord_arterial_cerebral,
                           Coord *EXT__coord_venous_cerebral,
                           Coord *EXT__coord_CSF_cerebral,
                           Coord **EXT__coords_arterial,
                           Coord **EXT__coords_venous,
                           Coord **EXT__coords_CSF,
                           QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();

    dir = current_dir;
    load_MRI_data();

    init_sig();
    init_css();

    EXT_coord_arterial_cervical = EXT__coord_arterial_cervical;
    EXT_coord_venous_cervical = EXT__coord_venous_cervical;
    EXT_coord_CSF_cervical = EXT__coord_CSF_cervical;

    EXT_coord_arterial_cerebral = EXT__coord_arterial_cerebral;
    EXT_coord_venous_cerebral = EXT__coord_venous_cerebral;
    EXT_coord_CSF_cerebral = EXT__coord_CSF_cerebral;

    EXT_coords_arterial = EXT__coords_arterial;
    EXT_coords_venous = EXT__coords_venous;
    EXT_coords_CSF = EXT__coords_CSF;
}

/*!
 * \brief DialogModify::load_MRI_data
 */
void DialogModify::load_MRI_data(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //CERVICAL
    {   //ARTERIAL
        bool res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE, coord_arterial_cervical);

        if (res){
            do_plot_arterial_cervical();
        }
    }
    {   //VENOUS
        bool res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE, coord_venous_cervical);

        if (res){
            do_plot_venous_cervical();
        }
    }
    {   //CSF
        bool res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE, coord_CSF_cervical);

        if (res){
            do_plot_CSF_cervical();
        }
    }
    //CEREBRAL
    {   //ARTERIAL
        bool res = load_data(dir + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE, coord_arterial_cerebral);

        if (res){
            do_plot_arterial_cerebral();
        }
    }
    {   //VENOUS
        bool res = load_data(dir + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE, coord_venous_cerebral);

        if (res){
            do_plot_venous_cerebral();
        }
    }
    {   //CSF
        bool res = load_data(dir + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE, coord_CSF_cerebral);

        if (res){
            do_plot_CSF_cerebral();
        }
    }
    //OTHER
    {   //ARTERIAL
        QStringList *arterial_files = get_MRI_arterial_files(dir);
        n_arterial = arterial_files->size();

        coords_arterial = new Coord*[n_arterial];
        for (int i = 0; i < n_arterial; i++){
            plot_arterial_other->addGraph();
            QAction *action = new QAction(arterial_files->at(i), this);
            action->setCheckable(true);
            action->setChecked(true);
            menu_choice_arterial->addAction(action);
            coords_arterial[i] = new Coord;
            load_data(dir + DIR_SEPARATOR + arterial_files->at(i), coords_arterial[i]);
        }
        do_plot_arterial_other();
    }
    {   //VENOUS
        QStringList *venous_files = get_MRI_venous_files(dir);
        n_venous = venous_files->size();

        coords_venous = new Coord*[n_venous];
        for (int i = 0; i < n_venous; i++){
            plot_venous_other->addGraph();
            QAction *action = new QAction(venous_files->at(i), this);
            action->setCheckable(true);
            action->setChecked(true);
            menu_choice_venous->addAction(action);
            coords_venous[i] = new Coord;
            load_data(dir + DIR_SEPARATOR + venous_files->at(i), coords_venous[i]);
        }
        do_plot_venous_other();
    }
    {   //CSF
        QStringList *CSF_files = get_MRI_csf_files(dir);
        n_CSF = CSF_files->size();

        coords_CSF = new Coord*[n_CSF];
        for (int i = 0; i < n_CSF; i++){
            plot_CSF_other->addGraph();
            QAction *action = new QAction(CSF_files->at(i), this);
            action->setCheckable(true);
            action->setChecked(true);
            menu_choice_CSF->addAction(action);
            coords_CSF[i] = new Coord;
            load_data(dir + DIR_SEPARATOR + CSF_files->at(i), coords_CSF[i]);
        }
        do_plot_CSF_other();
    }
}


/*!
 * \brief DialogModify::do_plot_arterial_cervical
 */
void DialogModify::do_plot_arterial_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_arterial_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_arterial_cervical);
        plot_arterial_cervical->graph(0)->setData(xy[0], xy[1]);
        plot_arterial_cervical->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_arterial_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_arterial_cervical->replot();
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::do_plot_venous_cervical
 */
void DialogModify::do_plot_venous_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_venous_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_venous_cervical);
        plot_venous_cervical->graph(0)->setData(xy[0], xy[1]);
        plot_venous_cervical->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_venous_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_venous_cervical->replot();
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::do_plot_CSF_cervical
 */
void DialogModify::do_plot_CSF_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_CSF_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_CSF_cervical);
        plot_CSF_cervical->graph(0)->setData(xy[0], xy[1]);
        plot_CSF_cervical->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_CSF_cervical->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_CSF_cervical->replot();
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::do_plot_arterial_cerebral
 */
void DialogModify::do_plot_arterial_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_arterial_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_arterial_cerebral);
        plot_arterial_cerebral->graph(0)->setData(xy[0], xy[1]);
        plot_arterial_cerebral->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_arterial_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_arterial_cerebral->replot();
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::do_plot_venous_cerebral
 */
void DialogModify::do_plot_venous_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_venous_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_venous_cerebral);
        plot_venous_cerebral->graph(0)->setData(xy[0], xy[1]);
        plot_venous_cerebral->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_venous_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_venous_cerebral->replot();
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::do_plot_CSF_cerebral
 */
void DialogModify::do_plot_CSF_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_CSF_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_CSF_cerebral);
        plot_CSF_cerebral->graph(0)->setData(xy[0], xy[1]);
        plot_CSF_cerebral->xAxis->setRange(min(xy[0]), max(xy[0]));
        plot_CSF_cerebral->yAxis->setRange(min(xy[1]), max(xy[1]));
        plot_CSF_cerebral->replot();
        delete[] xy;
    }
}

void DialogModify::do_plot_arterial_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (n_arterial > 0){
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        int k = 0;
        for (int i = 0; i < n_arterial; i++){
            if (menu_choice_arterial->actions().at(i)->isChecked()){
                QVector<double> *xy = Coord2QVector(coords_arterial[i]);
                plot_arterial_other->graph(i)->setData(xy[0], xy[1]);
                if (k == 0){
                    minx = min(xy[0]); maxx = max(xy[0]);
                    miny = min(xy[1]); maxy = max(xy[1]);
                }
                else{
                    minx = min(minx, min(xy[0])); maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1])); maxy = max(maxy, max(xy[1]));
                }
                k++;
                delete[] xy;
            }
            else{
                plot_arterial_other->graph(i)->clearData();
            }
        }
        plot_arterial_other->xAxis->setRange(minx, maxx);
        plot_arterial_other->yAxis->setRange(miny, maxy);
        plot_arterial_other->replot();
    }
}

void DialogModify::do_plot_venous_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (n_venous > 0){
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        int k = 0;
        for (int i = 0; i < n_venous; i++){
            if (menu_choice_venous->actions().at(i)->isChecked()){
                QVector<double> *xy = Coord2QVector(coords_venous[i]);
                plot_venous_other->graph(i)->setData(xy[0], xy[1]);
                if (k == 0){
                    minx = min(xy[0]); maxx = max(xy[0]);
                    miny = min(xy[1]); maxy = max(xy[1]);
                }
                else{
                    minx = min(minx, min(xy[0])); maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1])); maxy = max(maxy, max(xy[1]));
                }
                k++;
                delete[] xy;
            }
            else{
                plot_venous_other->graph(i)->clearData();
            }
        }
        plot_venous_other->xAxis->setRange(minx, maxx);
        plot_venous_other->yAxis->setRange(miny, maxy);
        plot_venous_other->replot();
    }
}

void DialogModify::do_plot_CSF_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (n_CSF > 0){
        double minx = 0., maxx = 0.;
        double miny = 0., maxy = 0.;

        int k = 0;
        for (int i = 0; i < n_CSF; i++){
            if (menu_choice_CSF->actions().at(i)->isChecked()){
                QVector<double> *xy = Coord2QVector(coords_CSF[i]);
                plot_CSF_other->graph(i)->setData(xy[0], xy[1]);
                if (k == 0){
                    minx = min(xy[0]); maxx = max(xy[0]);
                    miny = min(xy[1]); maxy = max(xy[1]);
                }
                else{
                    minx = min(minx, min(xy[0])); maxx = max(maxx, max(xy[0]));
                    miny = min(miny, min(xy[1])); maxy = max(maxy, max(xy[1]));
                }
                k++;
                delete[] xy;
            }
            else{
                plot_CSF_other->graph(i)->clearData();
            }
        }
        plot_CSF_other->xAxis->setRange(minx, maxx);
        plot_CSF_other->yAxis->setRange(miny, maxy);
        plot_CSF_other->replot();
    }
}


/*!
 * \brief DialogModify::get_point_arterial_cervical
 * \param m_event
 */
void DialogModify::get_point_arterial_cervical(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_arterial_cervical->xAxis->pixelToCoord(m_event->x());

    int n = coord_arterial_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_arterial_cervical);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_arterial_cervical = i;
                box_value_arterial_cervical->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::get_point_venous_cervical
 * \param m_event
 */
void DialogModify::get_point_venous_cervical(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_venous_cervical->xAxis->pixelToCoord(m_event->x());

    int n = coord_venous_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_venous_cervical);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_venous_cervical = i;
                box_value_venous_cervical->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::get_point_CSF_cervical
 * \param m_event
 */
void DialogModify::get_point_CSF_cervical(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_CSF_cervical->xAxis->pixelToCoord(m_event->x());

    int n = coord_CSF_cervical->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_CSF_cervical);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_CSF_cervical = i;
                box_value_CSF_cervical->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::get_point_arterial_cerebral
 * \param m_event
 */
void DialogModify::get_point_arterial_cerebral(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_arterial_cerebral->xAxis->pixelToCoord(m_event->x());

    int n = coord_arterial_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_arterial_cerebral);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_arterial_cerebral = i;
                box_value_arterial_cerebral->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::get_point_venous_cerebral
 * \param m_event
 */
void DialogModify::get_point_venous_cerebral(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_venous_cerebral->xAxis->pixelToCoord(m_event->x());

    int n = coord_venous_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_venous_cerebral);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_venous_cerebral = i;
                box_value_venous_cerebral->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

/*!
 * \brief DialogModify::get_point_CSF_cerebral
 * \param m_event
 */
void DialogModify::get_point_CSF_cerebral(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_CSF_cerebral->xAxis->pixelToCoord(m_event->x());

    int n = coord_CSF_cerebral->size();

    if (n > 0){
        QVector<double> *xy = Coord2QVector(coord_CSF_cerebral);
        double maxx = max(xy[0]);
        double eps = maxx / 100.;
        for (int i = 0; i < n; i++){
            if(qAbs(xy[0].at(i) - x) < eps){
                point_CSF_cerebral = i;
                box_value_CSF_cerebral->setValue(xy[1].at(i));
                break;
            }
        }
        delete[] xy;
    }
}

void DialogModify::get_point_arterial_other(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_arterial_other->xAxis->pixelToCoord(m_event->x());
    double y = plot_arterial_other->yAxis->pixelToCoord(m_event->y());

    if (n_arterial > 0){
        int n = coords_arterial[0]->size();

        QVector<double> **xy = new QVector<double>*[n_arterial];
        for (int i = 0; i < n_arterial; i++){
            xy[i] = Coord2QVector(coords_arterial[i]);
        }

        double **distx = new double*[n_arterial];
        for (int i = 0; i < n_arterial; i++){
            distx[i] = new double[n];
        }
        double **disty = new double*[n_arterial];
        for (int i = 0; i < n_arterial; i++){
            disty[i] = new double[n];
        }
        for (int i = 0; i < n_arterial; i++){
            for (int j = 0; j < n; j++){
                distx[i][j] = qAbs(xy[i][0][j]-x);
                disty[i][j] = qAbs(xy[i][1][j]-y);
            }
        }

        double minx = distx[0][0];
        point_arterial_other = 0;
        for (int i = 0; i < n_arterial; i++){
            for (int j = 0; j < n; j++){
                if (distx[i][j] < minx){
                    minx = distx[i][j];
                    point_arterial_other = j;
                }
            }
        }

        double miny = disty[0][0];
        curve_arterial_other = 0;
        for (int i = 0; i < n_arterial; i++){
            if (disty[i][point_arterial_other] < miny){
                miny = disty[i][point_arterial_other];
                curve_arterial_other = i;
            }
        }

        box_value_arterial_other->setValue(xy[curve_arterial_other][1][point_arterial_other]);

        for (int i = 0; i < n_arterial; i++){
            delete[] distx[i];
            delete[] disty[i];
        }
        delete[] distx;
        delete[] disty;
        for (int i = 0; i < n_arterial; i++){
            delete[] xy[i];
        }
        delete[] xy;
    }
}

void DialogModify::get_point_venous_other(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_venous_other->xAxis->pixelToCoord(m_event->x());
    double y = plot_venous_other->yAxis->pixelToCoord(m_event->y());

    if (n_venous > 0){
        int n = coords_venous[0]->size();

        QVector<double> **xy = new QVector<double>*[n_venous];
        for (int i = 0; i < n_venous; i++){
            xy[i] = Coord2QVector(coords_venous[i]);
        }

        double **distx = new double*[n_venous];
        for (int i = 0; i < n_venous; i++){
            distx[i] = new double[n];
        }
        double **disty = new double*[n_venous];
        for (int i = 0; i < n_venous; i++){
            disty[i] = new double[n];
        }
        for (int i = 0; i < n_venous; i++){
            for (int j = 0; j < n; j++){
                distx[i][j] = qAbs(xy[i][0][j]-x);
                disty[i][j] = qAbs(xy[i][1][j]-y);
            }
        }

        double minx = distx[0][0];
        point_venous_other = 0;
        for (int i = 0; i < n_venous; i++){
            for (int j = 0; j < n; j++){
                if (distx[i][j] < minx){
                    minx = distx[i][j];
                    point_venous_other = j;
                }
            }
        }

        double miny = disty[0][0];
        curve_venous_other = 0;
        for (int i = 0; i < n_venous; i++){
            if (disty[i][point_venous_other] < miny){
                miny = disty[i][point_venous_other];
                curve_venous_other = i;
            }
        }

        box_value_venous_other->setValue(xy[curve_venous_other][1][point_venous_other]);

        for (int i = 0; i < n_venous; i++){
            delete[] distx[i];
            delete[] disty[i];
        }
        delete[] distx;
        delete[] disty;
        for (int i = 0; i < n_venous; i++){
            delete[] xy[i];
        }
        delete[] xy;
    }
}

void DialogModify::get_point_CSF_other(QMouseEvent *m_event){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    double x = plot_CSF_other->xAxis->pixelToCoord(m_event->x());
    double y = plot_CSF_other->yAxis->pixelToCoord(m_event->y());

    if (n_CSF > 0){
        int n = coords_CSF[0]->size();

        QVector<double> **xy = new QVector<double>*[n_CSF];
        for (int i = 0; i < n_CSF; i++){
            xy[i] = Coord2QVector(coords_CSF[i]);
        }

        double **distx = new double*[n_CSF];
        for (int i = 0; i < n_CSF; i++){
            distx[i] = new double[n];
        }
        double **disty = new double*[n_CSF];
        for (int i = 0; i < n_CSF; i++){
            disty[i] = new double[n];
        }
        for (int i = 0; i < n_CSF; i++){
            for (int j = 0; j < n; j++){
                distx[i][j] = qAbs(xy[i][0][j]-x);
                disty[i][j] = qAbs(xy[i][1][j]-y);
            }
        }

        double minx = distx[0][0];
        point_CSF_other = 0;
        for (int i = 0; i < n_CSF; i++){
            for (int j = 0; j < n; j++){
                if (distx[i][j] < minx){
                    minx = distx[i][j];
                    point_CSF_other = j;
                }
            }
        }

        double miny = disty[0][0];
        curve_CSF_other = 0;
        for (int i = 0; i < n_CSF; i++){
            if (disty[i][point_CSF_other] < miny){
                miny = disty[i][point_CSF_other];
                curve_CSF_other = i;
            }
        }

        box_value_CSF_other->setValue(xy[curve_CSF_other][1][point_CSF_other]);

        for (int i = 0; i < n_CSF; i++){
            delete[] distx[i];
            delete[] disty[i];
        }
        delete[] distx;
        delete[] disty;
        for (int i = 0; i < n_CSF; i++){
            delete[] xy[i];
        }
        delete[] xy;
    }
}


/*!
 * \brief DialogModify::modify_arterial_cervical
 */
void DialogModify::modify_arterial_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_arterial_cervical->size();

    if (n > 0){
        if (point_arterial_cervical != -1){
            arterial_cervical_modified = 1;

            coord_arterial_cervical->set_coord(box_value_arterial_cervical->value(), point_arterial_cervical, YCOORD);
            do_plot_arterial_cervical();
        }
    }
}

/*!
 * \brief DialogModify::modify_venous_cervical
 */
void DialogModify::modify_venous_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_venous_cervical->size();

    if (n > 0){
        if (point_venous_cervical != -1){
            venous_cervical_modified = 1;

            coord_venous_cervical->set_coord(box_value_venous_cervical->value(), point_venous_cervical, YCOORD);
            do_plot_venous_cervical();
        }
    }
}

/*!
 * \brief DialogModify::modify_CSF_cervical
 */
void DialogModify::modify_CSF_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_CSF_cervical->size();

    if (n > 0){
        if (point_CSF_cervical != -1){
            CSF_cervical_modified = 1;

            coord_CSF_cervical->set_coord(box_value_CSF_cervical->value(), point_CSF_cervical, YCOORD);
            do_plot_CSF_cervical();
        }
    }
}

/*!
 * \brief DialogModify::modify_arterial_cerebral
 */
void DialogModify::modify_arterial_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_arterial_cerebral->size();

    if (n > 0){
        if (point_arterial_cerebral != -1){
            arterial_cerebral_modified = 1;

            coord_arterial_cerebral->set_coord(box_value_arterial_cerebral->value(), point_arterial_cerebral, YCOORD);
            do_plot_arterial_cerebral();
        }
    }
}

/*!
 * \brief DialogModify::modify_venous_cerebral
 */
void DialogModify::modify_venous_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_venous_cerebral->size();

    if (n > 0){
        if (point_venous_cerebral != -1){
            venous_cerebral_modified = 1;

            coord_venous_cerebral->set_coord(box_value_venous_cerebral->value(), point_venous_cerebral, YCOORD);
            do_plot_venous_cerebral();
        }
    }
}

/*!
 * \brief DialogModify::modify_CSF_cerebral
 */
void DialogModify::modify_CSF_cerebral(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_CSF_cerebral->size();

    if (n > 0){
        if (point_CSF_cerebral != -1){
            CSF_cerebral_modified = 1;

            coord_CSF_cerebral->set_coord(box_value_CSF_cerebral->value(), point_CSF_cerebral, YCOORD);
            do_plot_CSF_cerebral();
        }
    }
}

void DialogModify::modify_arterial_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (point_arterial_other > -1 && curve_arterial_other > -1){
        arterial_other_modified = 1;

        coords_arterial[curve_arterial_other]->set_coord(box_value_arterial_other->value(), point_arterial_other, YCOORD);
        do_plot_arterial_other();
    }
}

void DialogModify::modify_venous_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (point_venous_other > -1 && curve_venous_other > -1){
        venous_other_modified = 1;

        coords_venous[curve_venous_other]->set_coord(box_value_venous_other->value(), point_venous_other, YCOORD);
        do_plot_venous_other();
    }
}

void DialogModify::modify_CSF_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (point_CSF_other > -1 && curve_CSF_other > -1){
        CSF_other_modified = 1;

        coords_CSF[curve_CSF_other]->set_coord(box_value_CSF_other->value(), point_CSF_other, YCOORD);
        do_plot_CSF_other();
    }
}


/*!
 * \brief DialogModify::auto_modify_arterial_cervical
 */
void DialogModify::auto_modify_arterial_cervical(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = coord_arterial_cervical->size();

    if (n > 0){
        if (point_arterial_cervical != -1){
            arterial_cervical_modified = 1;

            int point_np1 = point_arterial_cervical + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = point_arterial_cervical - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_arterial_cervical->coord(point_np1, YCOORD) + coord_arterial_cervical->coord(point_nm1, YCOORD))/2.;
            coord_arterial_cervical->set_coord(val, point_arterial_cervical, YCOORD);
            box_value_arterial_cervical->setValue(val);
            do_plot_arterial_cervical();
        }

        if (check_venous_cervical->isChecked()){
            auto_modify_venous_cervical(point_arterial_cervical);
        }
        if (check_CSF_cervical->isChecked()){
            auto_modify_CSF_cervical(point_arterial_cervical);
        }
        if (check_arterial_cerebral->isChecked()){
            auto_modify_arterial_cerebral(point_arterial_cervical);
        }
        if (check_venous_cerebral->isChecked()){
            auto_modify_venous_cerebral(point_arterial_cervical);
        }
        if (check_CSF_cerebral->isChecked()){
            auto_modify_CSF_cerebral(point_arterial_cervical);
        }
    }
}

/*!
 * \brief DialogModify::auto_modify_venous_cervical
 */
void DialogModify::auto_modify_venous_cervical(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_venous_cervical;
    }

    int n = coord_venous_cervical->size();

    if (n > 0){
        if (pos != -1){
            venous_cervical_modified = 1;

            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_venous_cervical->coord(point_np1, YCOORD) + coord_venous_cervical->coord(point_nm1, YCOORD))/2.;
            coord_venous_cervical->set_coord(val, pos, YCOORD);
            box_value_venous_cervical->setValue(val);
            do_plot_venous_cervical();
        }
    }
}

/*!
 * \brief DialogModify::auto_modify_CSF_cervical
 */
void DialogModify::auto_modify_CSF_cervical(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_CSF_cervical;
    }

    int n = coord_CSF_cervical->size();

    if (n > 0){
        if (pos != -1){
            CSF_cervical_modified = 1;

            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_CSF_cervical->coord(point_np1, YCOORD) + coord_CSF_cervical->coord(point_nm1, YCOORD))/2.;
            coord_CSF_cervical->set_coord(val, pos, YCOORD);
            box_value_CSF_cervical->setValue(val);
            do_plot_CSF_cervical();
        }
    }
}

/*!
 * \brief DialogModify::auto_modify_arterial_cerebral
 */
void DialogModify::auto_modify_arterial_cerebral(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_arterial_cerebral;
    }

    int n = coord_arterial_cerebral->size();

    if (n > 0){
        if (pos != -1){
            arterial_cerebral_modified = 1;

            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_arterial_cerebral->coord(point_np1, YCOORD) + coord_arterial_cerebral->coord(point_nm1, YCOORD))/2.;
            coord_arterial_cerebral->set_coord(val, pos, YCOORD);
            box_value_arterial_cerebral->setValue(val);
            do_plot_arterial_cerebral();
        }
    }
}

/*!
 * \brief DialogModify::auto_modify_venous_cerebral
 */
void DialogModify::auto_modify_venous_cerebral(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_venous_cerebral;
    }

    int n = coord_venous_cerebral->size();

    if (n > 0){
        if (pos != -1){
            venous_cerebral_modified = 1;

            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_venous_cerebral->coord(point_np1, YCOORD) + coord_venous_cerebral->coord(point_nm1, YCOORD))/2.;
            coord_venous_cerebral->set_coord(val, pos, YCOORD);
            box_value_venous_cerebral->setValue(val);
            do_plot_venous_cerebral();
        }
    }
}

/*!
 * \brief DialogModify::auto_modify_CSF_cerebral
 */
void DialogModify::auto_modify_CSF_cerebral(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_CSF_cerebral;
    }

    int n = coord_CSF_cerebral->size();

    if (n > 0){
        if (pos != -1){
            CSF_cerebral_modified = 1;

            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coord_CSF_cerebral->coord(point_np1, YCOORD) + coord_CSF_cerebral->coord(point_nm1, YCOORD))/2.;
            coord_CSF_cerebral->set_coord(val, pos, YCOORD);
            box_value_CSF_cerebral->setValue(val);
            do_plot_CSF_cerebral();
        }
    }
}

void DialogModify::auto_modify_arterial_other(int curve){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (curve == -1){
        curve = curve_arterial_other;
    }

    if (n_arterial > 0){
        if (point_arterial_other != -1 && curve != -1){
            arterial_other_modified = 1;

            int n = coords_arterial[curve]->size();
            int point_np1 = point_arterial_other + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = point_arterial_other - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coords_arterial[curve]->coord(point_np1, YCOORD) + coords_arterial[curve]->coord(point_nm1, YCOORD))/2.;
            coords_arterial[curve]->set_coord(val, point_arterial_other, YCOORD);
            box_value_arterial_other->setValue(val);
            do_plot_arterial_other();
        }
    }
}

void DialogModify::auto_modify_venous_other(int pos, int curve){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_venous_other;
    }

    if (curve == -1){
        curve = curve_venous_other;
    }

    if (n_venous > 0){
        if (pos != -1 && curve != -1){
            venous_other_modified = 1;

            int n = coords_venous[curve]->size();
            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coords_venous[curve]->coord(point_np1, YCOORD) + coords_venous[curve]->coord(point_nm1, YCOORD))/2.;
            coords_venous[curve]->set_coord(val, pos, YCOORD);
            box_value_venous_other->setValue(val);
            do_plot_venous_other();
        }
    }
}

void DialogModify::auto_modify_CSF_other(int pos, int curve){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_CSF_other;
    }

    if (curve == -1){
        curve = curve_CSF_other;
    }

    if (n_CSF > 0){
        if (pos != -1 && curve != -1){
            CSF_other_modified = 1;

            int n = coords_CSF[curve]->size();
            int point_np1 = pos + 1;
            if (point_np1 == n){
                point_np1 = 0;
            }
            int point_nm1 = pos - 1;
            if (point_nm1 == -1){
                point_nm1 = n-1;
            }

            double val = (coords_CSF[curve]->coord(point_np1, YCOORD) + coords_CSF[curve]->coord(point_nm1, YCOORD))/2.;
            coords_CSF[curve]->set_coord(val, pos, YCOORD);
            box_value_CSF_other->setValue(val);
            do_plot_CSF_other();
        }
    }
}

void DialogModify::auto_modify_all_arterial_other(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (n_arterial > 0){
        if (point_arterial_other != -1){
            for (int i = 0; i < n_arterial; i++){
                auto_modify_arterial_other(i);
            }
        }
        if (check_venous_other->isChecked()){
            auto_modify_all_venous_other(point_arterial_other);
        }
        if (check_CSF_other->isChecked()){
            auto_modify_all_CSF_other(point_arterial_other);
        }
    }
}

void DialogModify::auto_modify_all_venous_other(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_venous_other;
    }

    if (n_venous > 0){
        if (pos != -1){
            for (int i = 0; i < n_venous; i++){
                auto_modify_venous_other(pos, i);
            }
        }
    }
}

void DialogModify::auto_modify_all_CSF_other(int pos){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (pos == -1){
        pos = point_CSF_other;
    }

    if (n_CSF > 0){
        if (pos != -1){
            for (int i = 0; i < n_CSF; i++){
                auto_modify_CSF_other(pos, i);
            }
        }
    }
}


/*!
 * \brief DialogModify::modify
 */
void DialogModify::modify(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int npi = 0;
    bool res = get_npi(&npi);

    if (res){
        //CERVICAL
        if (arterial_cervical_modified == 1){   //ARTERIAL
            int n = coord_arterial_cervical->size();

            if (n > 0){
                extend(coord_arterial_cervical, npi);

                EXT_coord_arterial_cervical->clear();
                EXT_coord_arterial_cervical->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_arterial_cervical->set_coord(coord_arterial_cervical->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_arterial_cervical->set_coord(coord_arterial_cervical->coord(i, YCOORD), i, YCOORD);
                }
            }
        }
        if (venous_cervical_modified == 1){   //VENOUS
            int n = coord_venous_cervical->size();

            if (n > 0){
                extend(coord_venous_cervical, npi);

                EXT_coord_venous_cervical->clear();
                EXT_coord_venous_cervical->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_venous_cervical->set_coord(coord_venous_cervical->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_venous_cervical->set_coord(coord_venous_cervical->coord(i, YCOORD), i, YCOORD);
                }
            }
        }
        if (CSF_cervical_modified == 1){   //CSF
            int n = coord_CSF_cervical->size();

            if (n > 0){
                extend(coord_CSF_cervical, npi);

                EXT_coord_CSF_cervical->clear();
                EXT_coord_CSF_cervical->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_CSF_cervical->set_coord(coord_CSF_cervical->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_CSF_cervical->set_coord(coord_CSF_cervical->coord(i, YCOORD), i, YCOORD);
                }
            }
        }
        //CEREBRAL
        if (arterial_cerebral_modified == 1){   //ARTERIAL
            int n = coord_arterial_cerebral->size();

            if (n > 0){
                extend(coord_arterial_cerebral, npi);

                EXT_coord_arterial_cerebral->clear();
                EXT_coord_arterial_cerebral->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_arterial_cerebral->set_coord(coord_arterial_cerebral->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_arterial_cerebral->set_coord(coord_arterial_cerebral->coord(i, YCOORD), i, YCOORD);
                }
            }
        }
        if (venous_cerebral_modified == 1){   //VENOUS
            int n = coord_venous_cerebral->size();

            if (n > 0){
                extend(coord_venous_cerebral, npi);

                EXT_coord_venous_cerebral->clear();
                EXT_coord_venous_cerebral->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_venous_cerebral->set_coord(coord_venous_cerebral->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_venous_cerebral->set_coord(coord_venous_cerebral->coord(i, YCOORD), i, YCOORD);
                }
            }
        }
        if (CSF_cerebral_modified == 1){   //CSF
            int n = coord_CSF_cerebral->size();

            if (n > 0){
                extend(coord_CSF_cerebral, npi);

                EXT_coord_CSF_cerebral->clear();
                EXT_coord_CSF_cerebral->set_size(npi);
                for (int i = 0; i < npi; i++){
                    EXT_coord_CSF_cerebral->set_coord(coord_CSF_cerebral->coord(i, XCOORD), i, XCOORD);
                    EXT_coord_CSF_cerebral->set_coord(coord_CSF_cerebral->coord(i, YCOORD), i, YCOORD);
                }
            }
        }

        //OTHER
        if (arterial_other_modified == 1){   //ARTERIAL
            for (int i = 0; i < n_arterial; i++){
                int n = coords_arterial[i]->size();

                if (n > 0){
                    extend(coords_arterial[i], npi);

                    EXT_coords_arterial[i]->clear();
                    EXT_coords_arterial[i]->set_size(npi);
                    for (int j = 0; j < npi; j++){
                        EXT_coords_arterial[i]->set_coord(coords_arterial[i]->coord(j, XCOORD), j, XCOORD);
                        EXT_coords_arterial[i]->set_coord(coords_arterial[i]->coord(j, YCOORD), j, YCOORD);
                    }
                }
            }
        }
        if (venous_other_modified == 1){   //VENOUS
            for (int i = 0; i < n_venous; i++){
                int n = coords_venous[i]->size();

                if (n > 0){
                    extend(coords_venous[i], npi);

                    EXT_coords_venous[i]->clear();
                    EXT_coords_venous[i]->set_size(npi);
                    for (int j = 0; j < npi; j++){
                        EXT_coords_venous[i]->set_coord(coords_venous[i]->coord(j, XCOORD), j, XCOORD);
                        EXT_coords_venous[i]->set_coord(coords_venous[i]->coord(j, YCOORD), j, YCOORD);
                    }
                }
            }
        }
        if (CSF_other_modified == 1){   //CSF
            for (int i = 0; i < n_CSF; i++){
                int n = coords_CSF[i]->size();

                if (n > 0){
                    extend(coords_CSF[i], npi);

                    EXT_coords_CSF[i]->clear();
                    EXT_coords_CSF[i]->set_size(npi);
                    for (int j = 0; j < npi; j++){
                        EXT_coords_CSF[i]->set_coord(coords_CSF[i]->coord(j, XCOORD), j, XCOORD);
                        EXT_coords_CSF[i]->set_coord(coords_CSF[i]->coord(j, YCOORD), j, YCOORD);
                    }
                }
            }
        }

        //Clear
        if (coords_arterial != NULL){
            delete coords_arterial;
        }
        if (coords_venous != NULL){
            delete coords_venous;
        }
        if (coords_CSF != NULL){
            delete coords_CSF;
        }

        accept();
    }
    else{
        reject();
    }
}

/*!
 * \brief DialogModify::cancel
 */
void DialogModify::cancel(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Clear
    if (coords_arterial != NULL){
        delete coords_arterial;
    }
    if (coords_venous != NULL){
        delete coords_venous;
    }
    if (coords_CSF != NULL){
        delete coords_CSF;
    }

    reject();
}


