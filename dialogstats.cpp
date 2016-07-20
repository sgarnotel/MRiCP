#include "dialogstats.h"

//TODO lot of things
//probably don't work

/*!
 * \brief DialogStats::init_var
 *
 * Initialisation of DialogStats variables
 */
void DialogStats::init_var()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Grid
    grid = new QGridLayout;

    grid_button = new QGridLayout;
    grid_labels = new QGridLayout;
    grid_list = new QGridLayout;
    grid_box = new QGridLayout;
    grid_button2 = new QGridLayout;

    //List
    loaded_list = new QListWidget(this);

    //Plot
    plot_xy = new QCustomPlot(this);

    //Button
    button_load = new QPushButton(this);
    button_clear = new QPushButton(this);
    button_plot = new QPushButton(this);
    button_zoom = new QPushButton(this);
    button_regression = new QPushButton(this);
    button_clustering = new QPushButton(this);
    button_export2csv = new QPushButton(this);
    button_close = new QPushButton(this);

    //Labels
    label_x = new QLabel(this);
    label_x_weight = new QLabel(this);
    label_y = new QLabel(this);
    label_y_weight = new QLabel(this);
    label_n = new QLabel(this);
    label_corr_coeff = new QLabel(this);
    label_formula = new QLabel(this);

    //ComboBox
    box_x = new QComboBox(this);
    box_x_weight = new QComboBox(this);
    box_y = new QComboBox(this);
    box_y_weight = new QComboBox(this);
}

/*!
 * \brief DialogStats::init_win
 *
 * Initialisation of DialogStats window
 */
void DialogStats::init_win()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Window
    setModal(false);

    //ComboBox
    box_x->addItem(DIALOG_STATS_ITEM00);
    box_x->insertSeparator(1);
    box_x->addItem(DIALOG_STATS_ITEM01);
    box_x->addItem(DIALOG_STATS_ITEM02);
    box_x->insertSeparator(3+1);
    box_x->addItem(DIALOG_STATS_ITEM03);
    box_x->addItem(DIALOG_STATS_ITEM04);
    box_x->addItem(DIALOG_STATS_ITEM05);
    box_x->addItem(DIALOG_STATS_ITEM06);
    box_x->addItem(DIALOG_STATS_ITEM07);
    box_x->insertSeparator(8+2);
    box_x->addItem(DIALOG_STATS_ITEM08);
    box_x->addItem(DIALOG_STATS_ITEM09);
    box_x->addItem(DIALOG_STATS_ITEM10);
    box_x->addItem(DIALOG_STATS_ITEM11);
    box_x->addItem(DIALOG_STATS_ITEM12);
    box_x->insertSeparator(13+3);
    box_x->addItem(DIALOG_STATS_ITEM13);
    box_x->addItem(DIALOG_STATS_ITEM14);
    box_x->addItem(DIALOG_STATS_ITEM15);
    box_x->addItem(DIALOG_STATS_ITEM16);
    box_x->addItem(DIALOG_STATS_ITEM17);
    box_x->addItem(DIALOG_STATS_ITEM18);
    box_x->insertSeparator(19+4);
    box_x->addItem(DIALOG_STATS_ITEM19);
    box_x->addItem(DIALOG_STATS_ITEM20);
    box_x->insertSeparator(21+5);
    box_x->addItem(DIALOG_STATS_ITEM21);
    box_x->addItem(DIALOG_STATS_ITEM22);
    box_x->addItem(DIALOG_STATS_ITEM23);
    box_x->addItem(DIALOG_STATS_ITEM24);
    box_x->addItem(DIALOG_STATS_ITEM25);
    box_x->insertSeparator(26+6);
    box_x->addItem(DIALOG_STATS_ITEM26);
    box_x->addItem(DIALOG_STATS_ITEM27);
    box_x->addItem(DIALOG_STATS_ITEM28);
    box_x->addItem(DIALOG_STATS_ITEM29);
    box_x->addItem(DIALOG_STATS_ITEM30);
    box_x->addItem(DIALOG_STATS_ITEM31);
    box_x->insertSeparator(32+7);
    box_x->addItem(DIALOG_STATS_ITEM32);
    box_x->insertSeparator(33+8);
    box_x->addItem(DIALOG_STATS_ITEM33);
    box_x->addItem(DIALOG_STATS_ITEM34);
    box_x->addItem(DIALOG_STATS_ITEM35);
    box_x->addItem(DIALOG_STATS_ITEM36);
    box_x->addItem(DIALOG_STATS_ITEM37);
    box_x->insertSeparator(38+9);
    box_x->addItem(DIALOG_STATS_ITEM38);
    box_x->addItem(DIALOG_STATS_ITEM39);
    box_x->addItem(DIALOG_STATS_ITEM40);
    box_x->addItem(DIALOG_STATS_ITEM41);
    box_x->insertSeparator(42+10);
    box_x->addItem(DIALOG_STATS_ITEM42);
    box_x->addItem(DIALOG_STATS_ITEM43);
    box_x->addItem(DIALOG_STATS_ITEM44);
    box_x->addItem(DIALOG_STATS_ITEM45);
    box_x->addItem(DIALOG_STATS_ITEM46);
    box_x->insertSeparator(47+11);
    box_x->addItem(DIALOG_STATS_ITEM47);
    box_x->addItem(DIALOG_STATS_ITEM48);
    box_x->addItem(DIALOG_STATS_ITEM49);
    box_x->addItem(DIALOG_STATS_ITEM50);
    box_x->insertSeparator(51+12);
    box_x->addItem(DIALOG_STATS_ITEM51);
    box_x->addItem(DIALOG_STATS_ITEM52);
    box_x->insertSeparator(53+13);
    box_x->addItem(DIALOG_STATS_ITEM53);
    box_x->addItem(DIALOG_STATS_ITEM54);
    box_x->addItem(DIALOG_STATS_ITEM55);
    box_x->addItem(DIALOG_STATS_ITEM56);
    box_x->addItem(DIALOG_STATS_ITEM57);
    box_x->insertSeparator(58+14);
    box_x->addItem(DIALOG_STATS_ITEM58);
    box_x->addItem(DIALOG_STATS_ITEM59);
    box_x->addItem(DIALOG_STATS_ITEM60);
    box_x->addItem(DIALOG_STATS_ITEM61);
    box_x->addItem(DIALOG_STATS_ITEM62);
    box_x->insertSeparator(63+15);
    box_x->addItem(DIALOG_STATS_ITEM63);
    box_x->addItem(DIALOG_STATS_ITEM64);
    box_x->addItem(DIALOG_STATS_ITEM65);
    box_x->addItem(DIALOG_STATS_ITEM66);
    box_x->addItem(DIALOG_STATS_ITEM67);
    box_x->addItem(DIALOG_STATS_ITEM68);
    box_x->insertSeparator(69+16);
    box_x->addItem(DIALOG_STATS_ITEM69);
    box_x->addItem(DIALOG_STATS_ITEM70);
    box_x->insertSeparator(71+17);
    box_x->addItem(DIALOG_STATS_ITEM71);
    box_x->addItem(DIALOG_STATS_ITEM72);
    box_x->addItem(DIALOG_STATS_ITEM73);
    box_x->addItem(DIALOG_STATS_ITEM74);
    box_x->addItem(DIALOG_STATS_ITEM75);
    box_x->insertSeparator(76+18);
    box_x->addItem(DIALOG_STATS_ITEM76);
    box_x->addItem(DIALOG_STATS_ITEM77);
    box_x->addItem(DIALOG_STATS_ITEM78);
    box_x->addItem(DIALOG_STATS_ITEM79);
    box_x->addItem(DIALOG_STATS_ITEM80);
    box_x->addItem(DIALOG_STATS_ITEM81);
    box_x->insertSeparator(82+19);
    box_x->addItem(DIALOG_STATS_ITEM82);
    box_x->insertSeparator(83+20);
    box_x->addItem(DIALOG_STATS_ITEM83);
    box_x->addItem(DIALOG_STATS_ITEM84);
    box_x->addItem(DIALOG_STATS_ITEM85);
    box_x->addItem(DIALOG_STATS_ITEM86);
    box_x->addItem(DIALOG_STATS_ITEM87);
    box_x->insertSeparator(88+21);
    box_x->addItem(DIALOG_STATS_ITEM88);
    box_x->addItem(DIALOG_STATS_ITEM89);
    box_x->addItem(DIALOG_STATS_ITEM90);
    box_x->addItem(DIALOG_STATS_ITEM91);
    box_x->insertSeparator(92+22);
    box_x->addItem(DIALOG_STATS_ITEM92);
    box_x->addItem(DIALOG_STATS_ITEM93);
    box_x->addItem(DIALOG_STATS_ITEM94);
    box_x->addItem(DIALOG_STATS_ITEM95);
    box_x->addItem(DIALOG_STATS_ITEM96);
    box_x->insertSeparator(97+23);
    box_x->addItem(DIALOG_STATS_ITEM97);
    box_x->addItem(DIALOG_STATS_ITEM98);
    box_x->addItem(DIALOG_STATS_ITEM99);
    box_x->addItem(DIALOG_STATS_ITEM100);
    box_x->insertSeparator(101+24);
    box_x->addItem(DIALOG_STATS_ITEM101);
    box_x->addItem(DIALOG_STATS_ITEM102);
    box_x->addItem(DIALOG_STATS_ITEM103);
    box_x->addItem(DIALOG_STATS_ITEM104);
    box_x->insertSeparator(105+25);
    box_x->addItem(DIALOG_STATS_ITEM105);
    box_x->addItem(DIALOG_STATS_ITEM106);
    box_x->addItem(DIALOG_STATS_ITEM107);
    box_x->addItem(DIALOG_STATS_ITEM108);
    box_x->insertSeparator(109+26);
    box_x->addItem(DIALOG_STATS_ITEM109);
    box_x->addItem(DIALOG_STATS_ITEM110);
    box_x->addItem(DIALOG_STATS_ITEM111);
    box_x->addItem(DIALOG_STATS_ITEM112);
    box_x->insertSeparator(112+27);
    box_x->addItem(DIALOG_STATS_ITEM113);
    box_x->addItem(DIALOG_STATS_ITEM114);
    box_x->addItem(DIALOG_STATS_ITEM115);
    box_x->addItem(DIALOG_STATS_ITEM116);
    box_x->insertSeparator(116+28);
    box_x->addItem(DIALOG_STATS_ITEM117);
    box_x->addItem(DIALOG_STATS_ITEM118);
    box_x->addItem(DIALOG_STATS_ITEM119);
    box_x->addItem(DIALOG_STATS_ITEM120);
    box_x->insertSeparator(121+29);
    box_x->addItem(DIALOG_STATS_ITEM121);
    box_x->addItem(DIALOG_STATS_ITEM122);
    box_x->addItem(DIALOG_STATS_ITEM123);
    box_x->addItem(DIALOG_STATS_ITEM124);
    box_x->insertSeparator(125+30);
    box_x->addItem(DIALOG_STATS_ITEM125);
    box_x->addItem(DIALOG_STATS_ITEM126);
    box_x->addItem(DIALOG_STATS_ITEM127);
    box_x->addItem(DIALOG_STATS_ITEM128);
    box_x->insertSeparator(129+31);
    box_x->addItem(DIALOG_STATS_ITEM129);
    box_x->addItem(DIALOG_STATS_ITEM130);
    box_x->addItem(DIALOG_STATS_ITEM131);
    box_x->addItem(DIALOG_STATS_ITEM132);
    box_x->insertSeparator(133+32);
    box_x->addItem(DIALOG_STATS_ITEM133);
    box_x->addItem(DIALOG_STATS_ITEM134);
    box_x->addItem(DIALOG_STATS_ITEM135);
    box_x->addItem(DIALOG_STATS_ITEM136);
    box_x->insertSeparator(137+33);
    box_x->addItem(DIALOG_STATS_ITEM137);
    box_x->addItem(DIALOG_STATS_ITEM138);
    box_x->addItem(DIALOG_STATS_ITEM139);
    box_x->addItem(DIALOG_STATS_ITEM140);

    box_x_weight->addItem(DIALOG_STATS_ITEM999);
    box_x_weight->insertSeparator(1);
    box_x_weight->addItem(DIALOG_STATS_ITEM01);
    box_x_weight->addItem(DIALOG_STATS_ITEM02);
    box_x_weight->insertSeparator(5);
    box_x_weight->addItem(DIALOG_STATS_ITEM51);
    box_x_weight->addItem(DIALOG_STATS_ITEM52);
    box_x_weight->insertSeparator(8);
    box_x_weight->addItem(DIALOG_STATS_ITEM19);
    box_x_weight->addItem(DIALOG_STATS_ITEM20);
    box_x_weight->insertSeparator(11);
    box_x_weight->addItem(DIALOG_STATS_ITEM69);
    box_x_weight->addItem(DIALOG_STATS_ITEM70);

    box_y->addItem(DIALOG_STATS_ITEM00);
    box_y->insertSeparator(1);
    box_y->addItem(DIALOG_STATS_ITEM01);
    box_y->addItem(DIALOG_STATS_ITEM02);
    box_y->insertSeparator(3+1);
    box_y->addItem(DIALOG_STATS_ITEM03);
    box_y->addItem(DIALOG_STATS_ITEM04);
    box_y->addItem(DIALOG_STATS_ITEM05);
    box_y->addItem(DIALOG_STATS_ITEM06);
    box_y->addItem(DIALOG_STATS_ITEM07);
    box_y->insertSeparator(8+2);
    box_y->addItem(DIALOG_STATS_ITEM08);
    box_y->addItem(DIALOG_STATS_ITEM09);
    box_y->addItem(DIALOG_STATS_ITEM10);
    box_y->addItem(DIALOG_STATS_ITEM11);
    box_y->addItem(DIALOG_STATS_ITEM12);
    box_y->insertSeparator(13+3);
    box_y->addItem(DIALOG_STATS_ITEM13);
    box_y->addItem(DIALOG_STATS_ITEM14);
    box_y->addItem(DIALOG_STATS_ITEM15);
    box_y->addItem(DIALOG_STATS_ITEM16);
    box_y->addItem(DIALOG_STATS_ITEM17);
    box_y->addItem(DIALOG_STATS_ITEM18);
    box_y->insertSeparator(19+4);
    box_y->addItem(DIALOG_STATS_ITEM19);
    box_y->addItem(DIALOG_STATS_ITEM20);
    box_y->insertSeparator(21+5);
    box_y->addItem(DIALOG_STATS_ITEM21);
    box_y->addItem(DIALOG_STATS_ITEM22);
    box_y->addItem(DIALOG_STATS_ITEM23);
    box_y->addItem(DIALOG_STATS_ITEM24);
    box_y->addItem(DIALOG_STATS_ITEM25);
    box_y->insertSeparator(26+6);
    box_y->addItem(DIALOG_STATS_ITEM26);
    box_y->addItem(DIALOG_STATS_ITEM27);
    box_y->addItem(DIALOG_STATS_ITEM28);
    box_y->addItem(DIALOG_STATS_ITEM29);
    box_y->addItem(DIALOG_STATS_ITEM30);
    box_y->addItem(DIALOG_STATS_ITEM31);
    box_y->insertSeparator(32+7);
    box_y->addItem(DIALOG_STATS_ITEM32);
    box_y->insertSeparator(33+8);
    box_y->addItem(DIALOG_STATS_ITEM33);
    box_y->addItem(DIALOG_STATS_ITEM34);
    box_y->addItem(DIALOG_STATS_ITEM35);
    box_y->addItem(DIALOG_STATS_ITEM36);
    box_y->addItem(DIALOG_STATS_ITEM37);
    box_y->insertSeparator(38+9);
    box_y->addItem(DIALOG_STATS_ITEM38);
    box_y->addItem(DIALOG_STATS_ITEM39);
    box_y->addItem(DIALOG_STATS_ITEM40);
    box_y->addItem(DIALOG_STATS_ITEM41);
    box_y->insertSeparator(42+10);
    box_y->addItem(DIALOG_STATS_ITEM42);
    box_y->addItem(DIALOG_STATS_ITEM43);
    box_y->addItem(DIALOG_STATS_ITEM44);
    box_y->addItem(DIALOG_STATS_ITEM45);
    box_y->addItem(DIALOG_STATS_ITEM46);
    box_y->insertSeparator(47+11);
    box_y->addItem(DIALOG_STATS_ITEM47);
    box_y->addItem(DIALOG_STATS_ITEM48);
    box_y->addItem(DIALOG_STATS_ITEM49);
    box_y->addItem(DIALOG_STATS_ITEM50);
    box_y->insertSeparator(51+12);
    box_y->addItem(DIALOG_STATS_ITEM51);
    box_y->addItem(DIALOG_STATS_ITEM52);
    box_y->insertSeparator(53+13);
    box_y->addItem(DIALOG_STATS_ITEM53);
    box_y->addItem(DIALOG_STATS_ITEM54);
    box_y->addItem(DIALOG_STATS_ITEM55);
    box_y->addItem(DIALOG_STATS_ITEM56);
    box_y->addItem(DIALOG_STATS_ITEM57);
    box_y->insertSeparator(58+14);
    box_y->addItem(DIALOG_STATS_ITEM58);
    box_y->addItem(DIALOG_STATS_ITEM59);
    box_y->addItem(DIALOG_STATS_ITEM60);
    box_y->addItem(DIALOG_STATS_ITEM61);
    box_y->addItem(DIALOG_STATS_ITEM62);
    box_y->insertSeparator(63+15);
    box_y->addItem(DIALOG_STATS_ITEM63);
    box_y->addItem(DIALOG_STATS_ITEM64);
    box_y->addItem(DIALOG_STATS_ITEM65);
    box_y->addItem(DIALOG_STATS_ITEM66);
    box_y->addItem(DIALOG_STATS_ITEM67);
    box_y->addItem(DIALOG_STATS_ITEM68);
    box_y->insertSeparator(69+16);
    box_y->addItem(DIALOG_STATS_ITEM69);
    box_y->addItem(DIALOG_STATS_ITEM70);
    box_y->insertSeparator(71+17);
    box_y->addItem(DIALOG_STATS_ITEM71);
    box_y->addItem(DIALOG_STATS_ITEM72);
    box_y->addItem(DIALOG_STATS_ITEM73);
    box_y->addItem(DIALOG_STATS_ITEM74);
    box_y->addItem(DIALOG_STATS_ITEM75);
    box_y->insertSeparator(76+18);
    box_y->addItem(DIALOG_STATS_ITEM76);
    box_y->addItem(DIALOG_STATS_ITEM77);
    box_y->addItem(DIALOG_STATS_ITEM78);
    box_y->addItem(DIALOG_STATS_ITEM79);
    box_y->addItem(DIALOG_STATS_ITEM80);
    box_y->addItem(DIALOG_STATS_ITEM81);
    box_y->insertSeparator(82+19);
    box_y->addItem(DIALOG_STATS_ITEM82);
    box_y->insertSeparator(83+20);
    box_y->addItem(DIALOG_STATS_ITEM83);
    box_y->addItem(DIALOG_STATS_ITEM84);
    box_y->addItem(DIALOG_STATS_ITEM85);
    box_y->addItem(DIALOG_STATS_ITEM86);
    box_y->addItem(DIALOG_STATS_ITEM87);
    box_y->insertSeparator(88+21);
    box_y->addItem(DIALOG_STATS_ITEM88);
    box_y->addItem(DIALOG_STATS_ITEM89);
    box_y->addItem(DIALOG_STATS_ITEM90);
    box_y->addItem(DIALOG_STATS_ITEM91);
    box_y->insertSeparator(92+22);
    box_y->addItem(DIALOG_STATS_ITEM92);
    box_y->addItem(DIALOG_STATS_ITEM93);
    box_y->addItem(DIALOG_STATS_ITEM94);
    box_y->addItem(DIALOG_STATS_ITEM95);
    box_y->addItem(DIALOG_STATS_ITEM96);
    box_y->insertSeparator(97+23);
    box_y->addItem(DIALOG_STATS_ITEM97);
    box_y->addItem(DIALOG_STATS_ITEM98);
    box_y->addItem(DIALOG_STATS_ITEM99);
    box_y->addItem(DIALOG_STATS_ITEM100);
    box_y->insertSeparator(101+24);
    box_y->addItem(DIALOG_STATS_ITEM101);
    box_y->addItem(DIALOG_STATS_ITEM102);
    box_y->addItem(DIALOG_STATS_ITEM103);
    box_y->addItem(DIALOG_STATS_ITEM104);
    box_y->insertSeparator(105+25);
    box_y->addItem(DIALOG_STATS_ITEM105);
    box_y->addItem(DIALOG_STATS_ITEM106);
    box_y->addItem(DIALOG_STATS_ITEM107);
    box_y->addItem(DIALOG_STATS_ITEM108);
    box_y->insertSeparator(109+26);
    box_y->addItem(DIALOG_STATS_ITEM109);
    box_y->addItem(DIALOG_STATS_ITEM110);
    box_y->addItem(DIALOG_STATS_ITEM111);
    box_y->addItem(DIALOG_STATS_ITEM112);
    box_y->insertSeparator(112+27);
    box_y->addItem(DIALOG_STATS_ITEM113);
    box_y->addItem(DIALOG_STATS_ITEM114);
    box_y->addItem(DIALOG_STATS_ITEM115);
    box_y->addItem(DIALOG_STATS_ITEM116);
    box_y->insertSeparator(116+28);
    box_y->addItem(DIALOG_STATS_ITEM117);
    box_y->addItem(DIALOG_STATS_ITEM118);
    box_y->addItem(DIALOG_STATS_ITEM119);
    box_y->addItem(DIALOG_STATS_ITEM120);
    box_y->insertSeparator(121+29);
    box_y->addItem(DIALOG_STATS_ITEM121);
    box_y->addItem(DIALOG_STATS_ITEM122);
    box_y->addItem(DIALOG_STATS_ITEM123);
    box_y->addItem(DIALOG_STATS_ITEM124);
    box_y->insertSeparator(125+30);
    box_y->addItem(DIALOG_STATS_ITEM125);
    box_y->addItem(DIALOG_STATS_ITEM126);
    box_y->addItem(DIALOG_STATS_ITEM127);
    box_y->addItem(DIALOG_STATS_ITEM128);
    box_y->insertSeparator(129+31);
    box_y->addItem(DIALOG_STATS_ITEM129);
    box_y->addItem(DIALOG_STATS_ITEM130);
    box_y->addItem(DIALOG_STATS_ITEM131);
    box_y->addItem(DIALOG_STATS_ITEM132);
    box_y->insertSeparator(133+32);
    box_y->addItem(DIALOG_STATS_ITEM133);
    box_y->addItem(DIALOG_STATS_ITEM134);
    box_y->addItem(DIALOG_STATS_ITEM135);
    box_y->addItem(DIALOG_STATS_ITEM136);
    box_y->insertSeparator(137+33);
    box_y->addItem(DIALOG_STATS_ITEM137);
    box_y->addItem(DIALOG_STATS_ITEM138);
    box_y->addItem(DIALOG_STATS_ITEM139);
    box_y->addItem(DIALOG_STATS_ITEM140);

    box_y_weight->addItem(DIALOG_STATS_ITEM999);
    box_y_weight->insertSeparator(1);
    box_y_weight->addItem(DIALOG_STATS_ITEM01);
    box_y_weight->addItem(DIALOG_STATS_ITEM02);
    box_y_weight->insertSeparator(5);
    box_y_weight->addItem(DIALOG_STATS_ITEM51);
    box_y_weight->addItem(DIALOG_STATS_ITEM52);
    box_y_weight->insertSeparator(8);
    box_y_weight->addItem(DIALOG_STATS_ITEM19);
    box_y_weight->addItem(DIALOG_STATS_ITEM20);
    box_y_weight->insertSeparator(11);
    box_y_weight->addItem(DIALOG_STATS_ITEM69);
    box_y_weight->addItem(DIALOG_STATS_ITEM70);

    //Button
    button_load->setText(DIALOG_STATS_LOAD);
    button_clear->setText(DIALOG_STATS_CLEAR);
    button_plot->setText(DIALOG_STATS_PLOT);
    button_zoom->setText("Zoom");
    button_regression->setText(DIALOG_STATS_REG);
    button_clustering->setText(DIALOG_STATS_CLUST);
    button_export2csv->setText(DIALOG_STATS_CSV);
    button_close->setText(DIALOG_STATS_CLOSE);

    //Label
    label_x->setText(DIALOG_STATS_X);
    label_x_weight->setText(DIALOG_STATS_WEIGHT);
    label_y->setText(DIALOG_STATS_Y);
    label_y_weight->setText(DIALOG_STATS_WEIGHT);

    //Plot
    plot_xy->addGraph();        //xy
    plot_xy->addGraph();        //regression
    plot_xy->addGraph();        //highlight
    for (int i = 0; i < (int)DIALOG_STATS_NB_CLUSTERING; i++){
        plot_xy->addGraph();    //clustering
    }

    //List
    loaded_list->setMaximumWidth(0.2*this->width());
    loaded_list->setSelectionMode(QAbstractItemView::MultiSelection);

    //Grid
    setLayout(grid);

    grid_button->addWidget(button_load, 0, 0, 1, 1);
    grid_button->addWidget(button_clear, 0, 1, 1, 1);
    grid_button->addWidget(button_plot, 0, 2, 1, 1);
    grid_button->addWidget(button_regression, 0, 3, 1, 1);
    grid_button->addWidget(button_clustering, 0, 4, 1, 1);

    grid_labels->addWidget(label_n, 0, 0, 1, 1, Qt::AlignCenter);
    grid_labels->addWidget(label_corr_coeff, 0, 1, 1, 1, Qt::AlignCenter);
    grid_labels->addWidget(label_formula, 0, 2, 1, 1, Qt::AlignCenter);

    grid_list->addWidget(loaded_list, 0, 0, 1, 1);

    grid_box->addWidget(button_zoom, 0, 0, 1, 1);
    grid_box->addWidget(label_x, 0, 1, 1, 1, Qt::AlignRight);
    grid_box->addWidget(box_x, 0, 2, 1, 1, Qt::AlignLeft);
    grid_box->addWidget(label_x_weight, 0, 3, 1, 1, Qt::AlignRight);
    grid_box->addWidget(box_x_weight, 0, 4, 1, 1, Qt::AlignLeft);

    grid_box->addWidget(label_y, 1, 1, 1, 1, Qt::AlignRight);
    grid_box->addWidget(box_y, 1, 2, 1, 1, Qt::AlignLeft);
    grid_box->addWidget(label_y_weight, 1, 3, 1, 1, Qt::AlignRight);
    grid_box->addWidget(box_y_weight, 1, 4, 1, 1, Qt::AlignLeft);

    grid_box->addWidget(button_export2csv, 0, 5, 2, 1);

    grid_button2->addWidget(button_close, 0, 0, 1, 1);

    grid->addLayout(grid_button, 0, 0, 1, 12);
    grid->addLayout(grid_labels, 1, 0, 1, 12);
    grid->addLayout(grid_box, 2, 0, 1, 12);
    grid->addLayout(grid_list, 3, 0, 10, 2);
    grid->addWidget(plot_xy, 3, 2, 10, 10);
    grid->addLayout(grid_button2, 13, 0, 1, 12);
}

/*!
 * \brief DialogStats::init_sig
 *
 * Initialisation of DialogStats signals
 */
void DialogStats::init_sig()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Connect
    connect(button_load, SIGNAL(clicked()), this, SLOT(load()));
    connect(button_clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(button_plot, SIGNAL(clicked()), this, SLOT(pre_plot()));
    connect(button_zoom, SIGNAL(clicked()), this, SLOT(zoom()));
    connect(button_regression, SIGNAL(clicked()), this, SLOT(regression()));
    connect(button_clustering, SIGNAL(clicked()), this, SLOT(do_clustering()));
    connect(button_export2csv, SIGNAL(clicked()), this, SLOT(export2csv()));
    connect(button_close, SIGNAL(clicked()), this, SLOT(quit()));

    connect(loaded_list, SIGNAL(itemSelectionChanged()), this, SLOT(list_select()));

    connect(plot_xy, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(get_patient(QMouseEvent*)));
}

/*!
 * \brief DialogStats::init_css
 *
 * Initialisation of DialogStats style sheet
 */
void DialogStats::init_css()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    setWindowTitle(DIALOG_STATS_TITLE);

    //Style
    setStyleSheet(CSS_DIALOG);

    box_x->setStyleSheet(CSS_COMBOBOX);
    box_x_weight->setStyleSheet(CSS_COMBOBOX);
    box_y->setStyleSheet(CSS_COMBOBOX);
    box_y_weight->setStyleSheet(CSS_COMBOBOX);

    button_load->setStyleSheet(CSS_BUTTON);
    button_clear->setStyleSheet(CSS_BUTTON);
    button_plot->setStyleSheet(CSS_BUTTON);
    button_regression->setStyleSheet(CSS_BUTTON);
    button_clustering->setStyleSheet(CSS_BUTTON);
    button_export2csv->setStyleSheet(CSS_BUTTON);
    button_close->setStyleSheet(CSS_BUTTON);

    label_x->setStyleSheet(CSS_LABEL_GLOBAL);
    label_x_weight->setStyleSheet(CSS_LABEL_GLOBAL);
    label_y->setStyleSheet(CSS_LABEL_GLOBAL);
    label_y_weight->setStyleSheet(CSS_LABEL_GLOBAL);
    label_n->setStyleSheet(CSS_LABEL_GLOBAL);
    label_corr_coeff->setStyleSheet(CSS_LABEL_GLOBAL);
    label_formula->setStyleSheet(CSS_LABEL_GLOBAL);

    //Plot
    plot_xy->graph(0)->setPen(QPen(Qt::blue));
    plot_xy->graph(0)->setLineStyle(QCPGraph::lsNone);
    plot_xy->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
    plot_xy->graph(1)->setPen(QPen(Qt::red));
    plot_xy->graph(2)->setPen(QPen(Qt::blue));
    plot_xy->graph(2)->setLineStyle(QCPGraph::lsNone);
    plot_xy->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 8));

    int n_color = 16;
    QPen *pens = new QPen[n_color];
    pens[0] = QPen(Qt::red);
    pens[1] = QPen(Qt::green);
    pens[2] = QPen(Qt::blue);
    pens[3] = QPen(Qt::darkGray);
    pens[4] = QPen(Qt::darkRed);
    pens[5] = QPen(Qt::darkGreen);
    pens[6] = QPen(Qt::darkBlue);
    pens[7] = QPen(Qt::lightGray);
    pens[8] = QPen(Qt::cyan);
    pens[9] = QPen(Qt::magenta);
    pens[10] = QPen(Qt::yellow);
    pens[11] = QPen(Qt::gray);
    pens[12] = QPen(Qt::darkCyan);
    pens[13] = QPen(Qt::darkMagenta);
    pens[14] = QPen(Qt::darkYellow);
    pens[15] = QPen(Qt::darkGray);

    for (int i = 0; i < (int)DIALOG_STATS_NB_CLUSTERING; i++){
        plot_xy->graph(3+i)->setPen(pens[i%n_color]);
        plot_xy->graph(3+i)->setLineStyle(QCPGraph::lsNone);
        plot_xy->graph(3+i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCrossSquare, 15));
    }
}

/*!
 * \brief DialogStats::DialogStats
 * \param parent
 *
 * DialogStats
 */
DialogStats::DialogStats(QWidget *parent) :
    QDialog(parent)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    init_var();
    init_win();
    init_sig();
    init_css();
}

/*!
 * \brief DialogStats::load
 *
 * Load data for statistical analysis
 */
void DialogStats::load()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    QString dir = QFileDialog::getExistingDirectory(this, DIALOG_STATS_LOAD_TXT, get_Results_directory());

    if (!dir.isEmpty()){
#ifdef LINUX_OS
        QString command = "ls " +  dir + " > " + QString(SYSTEM_DIR) + "ls.dat";
#endif
#ifdef MAC_OS
        QString command = "ls " +  dir + " > " + QString(SYSTEM_DIR) + "ls.dat";
#endif
#ifdef WIN_OS
        dir.replace("/", "\\");
        QString command = "dir /B /A:D " +  dir + " > " + QString(SYSTEM_DIR) + "ls.dat";
#endif

        int res = system(command.toStdString().c_str());

        if (res != 0){
            cout << "DialogStats::load() -- UBUNTU - ls fail" << endl;
        }

        QStringList patients;
        QFile file(QString::fromStdString(SYSTEM_DIR) + "ls.dat");
        int nb_lines = 0;
        if (file.open(QIODevice::ReadOnly)){
            while(!file.atEnd()){
                QString tmp = file.readLine();
                tmp.remove("\n").remove("\r");
                if (!tmp.contains(".csv") && !tmp.contains(".rtf")){
                    patients.append(tmp);
                    nb_lines++;
                }
            }
            file.close();
        }

        //Clear
        names.clear();
        id.clear();

        arterial_cervical_qualities.clear();
        venous_cervical_qualities.clear();
        csf_cervical_qualities.clear();
        arterial_cerebral_qualities.clear();
        venous_cerebral_qualities.clear();
        csf_cerebral_qualities.clear();
        ICP_qualities.clear();

        arterial_cervical_mean_cycles.clear();
        arterial_cervical_heart_rates.clear();

        arterial_cervical_mins.clear();
        arterial_cervical_maxs.clear();
        arterial_cervical_means.clear();
        arterial_cervical_grads.clear();
        arterial_cervical_strokes.clear();

        venous_cervical_mins.clear();
        venous_cervical_maxs.clear();
        venous_cervical_means.clear();
        venous_cervical_grads.clear();
        venous_cervical_strokes.clear();

        alphas_cervical.clear();
        venous_corr_cervical_mins.clear();
        venous_corr_cervical_maxs.clear();
        venous_corr_cervical_means.clear();
        venous_corr_cervical_grads.clear();
        venous_corr_cervical_strokes.clear();

        csf_cervical_mean_cycles.clear();
        csf_cervical_heart_rates.clear();

        csf_cervical_mins.clear();
        csf_cervical_maxs.clear();
        csf_cervical_means.clear();
        csf_cervical_grads.clear();
        csf_cervical_strokes.clear();

        mean_csfs_cervical.clear();
        csf_corr_cervical_mins.clear();
        csf_corr_cervical_maxs.clear();
        csf_corr_cervical_means.clear();
        csf_corr_cervical_grads.clear();
        csf_corr_cervical_strokes.clear();

        AV_ICVC_ratio_cervical.clear();

        arteriovenous_flow_cervical_mins.clear();
        arteriovenous_flow_cervical_maxs.clear();
        arteriovenous_flow_cervical_means.clear();
        arteriovenous_flow_cervical_grads.clear();
        arteriovenous_flow_cervical_strokes.clear();

        arteriovenous_volume_cervical_mins.clear();
        arteriovenous_volume_cervical_maxs.clear();
        arteriovenous_volume_cervical_means.clear();
        arteriovenous_volume_cervical_grads.clear();

        icvc_flow_cervical_mins.clear();
        icvc_flow_cervical_maxs.clear();
        icvc_flow_cervical_means.clear();
        icvc_flow_cervical_grads.clear();
        icvc_flow_cervical_strokes.clear();

        icvc_volume_cervical_mins.clear();
        icvc_volume_cervical_maxs.clear();
        icvc_volume_cervical_means.clear();
        icvc_volume_cervical_grads.clear();

        arterial_cerebral_heart_rates.clear();
        arterial_cerebral_heart_rates.clear();

        arterial_cerebral_mins.clear();
        arterial_cerebral_maxs.clear();
        arterial_cerebral_means.clear();
        arterial_cerebral_grads.clear();
        arterial_cerebral_strokes.clear();

        venous_cerebral_mins.clear();
        venous_cerebral_maxs.clear();
        venous_cerebral_means.clear();
        venous_cerebral_grads.clear();
        venous_cerebral_strokes.clear();

        alphas_cerebral.clear();
        venous_corr_cerebral_mins.clear();
        venous_corr_cerebral_maxs.clear();
        venous_corr_cerebral_means.clear();
        venous_corr_cerebral_grads.clear();
        venous_corr_cerebral_strokes.clear();

        csf_cerebral_mean_cycles.clear();
        csf_cerebral_heart_rates.clear();

        csf_cerebral_mins.clear();
        csf_cerebral_maxs.clear();
        csf_cerebral_means.clear();
        csf_cerebral_grads.clear();
        csf_cerebral_strokes.clear();

        mean_csfs_cerebral.clear();
        csf_corr_cerebral_mins.clear();
        csf_corr_cerebral_maxs.clear();
        csf_corr_cerebral_means.clear();
        csf_corr_cerebral_grads.clear();
        csf_corr_cerebral_strokes.clear();

        AV_ICVC_ratio_cerebral.clear();

        arteriovenous_flow_cerebral_mins.clear();
        arteriovenous_flow_cerebral_maxs.clear();
        arteriovenous_flow_cerebral_means.clear();
        arteriovenous_flow_cerebral_grads.clear();
        arteriovenous_flow_cerebral_strokes.clear();

        arteriovenous_volume_cerebral_mins.clear();
        arteriovenous_volume_cerebral_maxs.clear();
        arteriovenous_volume_cerebral_means.clear();
        arteriovenous_volume_cerebral_grads.clear();

        icvc_flow_cerebral_mins.clear();
        icvc_flow_cerebral_maxs.clear();
        icvc_flow_cerebral_means.clear();
        icvc_flow_cerebral_grads.clear();
        icvc_flow_cerebral_strokes.clear();

        icvc_volume_cerebral_mins.clear();
        icvc_volume_cerebral_maxs.clear();
        icvc_volume_cerebral_means.clear();
        icvc_volume_cerebral_grads.clear();

        icp_mins.clear();
        icp_maxs.clear();
        icp_means.clear();
        icp_grads.clear();

        compliance_AV_global_cervical.clear();
        compliance_ICVC_global_cervical.clear();
        compliance_AV_global_cerebral.clear();
        compliance_ICVC_global_cerebral.clear();

        compliance_AV_mins_cervical_parted.clear();
        compliance_AV_maxs_cervical_parted.clear();
        compliance_AV_means_cervical_parted.clear();
        compliance_AV_grads_cervical_parted.clear();

        compliance_AV_mins_cervical_continuous.clear();
        compliance_AV_maxs_cervical_continuous.clear();
        compliance_AV_means_cervical_continuous.clear();
        compliance_AV_grads_cervical_continuous.clear();

        compliance_ICVC_mins_cervical_parted.clear();
        compliance_ICVC_maxs_cervical_parted.clear();
        compliance_ICVC_means_cervical_parted.clear();
        compliance_ICVC_grads_cervical_parted.clear();

        compliance_ICVC_mins_cervical_continuous.clear();
        compliance_ICVC_maxs_cervical_continuous.clear();
        compliance_ICVC_means_cervical_continuous.clear();
        compliance_ICVC_grads_cervical_continuous.clear();

        compliance_AV_mins_cerebral_parted.clear();
        compliance_AV_maxs_cerebral_parted.clear();
        compliance_AV_means_cerebral_parted.clear();
        compliance_AV_grads_cerebral_parted.clear();

        compliance_AV_mins_cerebral_continuous.clear();
        compliance_AV_maxs_cerebral_continuous.clear();
        compliance_AV_means_cerebral_continuous.clear();
        compliance_AV_grads_cerebral_continuous.clear();

        compliance_ICVC_mins_cerebral_parted.clear();
        compliance_ICVC_maxs_cerebral_parted.clear();
        compliance_ICVC_means_cerebral_parted.clear();
        compliance_ICVC_grads_cerebral_parted.clear();

        compliance_ICVC_mins_cerebral_continuous.clear();
        compliance_ICVC_maxs_cerebral_continuous.clear();
        compliance_ICVC_means_cerebral_continuous.clear();
        compliance_ICVC_grads_cerebral_continuous.clear();

        for (int i = 0; i < patients.count(); i++){
            id.append(i);

            QString current_name = patients.at(i);
            current_name.remove("\r").remove("\n");

            names.append(current_name);
            loaded_list->addItem(current_name);

            //MRI QUALITY
            {
                if (DEBUG > 10) cout << "load()::MRI QUALITY" << endl;

                int n = MRI_QUALITY_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_QUALITY_FILE_CC, list1, list2, n);

                if (res){
                    arterial_cervical_qualities.append(QString::fromStdString(list2[1]).toDouble());
                    venous_cervical_qualities.append(QString::fromStdString(list2[2]).toDouble());
                    csf_cervical_qualities.append(QString::fromStdString(list2[3]).toDouble());
                    arterial_cerebral_qualities.append(QString::fromStdString(list2[5]).toDouble());
                    venous_cerebral_qualities.append(QString::fromStdString(list2[6]).toDouble());
                    csf_cerebral_qualities.append(QString::fromStdString(list2[7]).toDouble());
                }
                else{
                    arterial_cervical_qualities.append(0.);
                    venous_cervical_qualities.append(0.);
                    csf_cervical_qualities.append(0.);
                    arterial_cerebral_qualities.append(0.);
                    venous_cerebral_qualities.append(0.);
                    csf_cerebral_qualities.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ICP QUALITY
            {
                if (DEBUG > 10) cout << "load()::ICP QUALITY" << endl;

                int n = ICP_QUALITY_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + ICP_QUALITY_FILE, list1, list2, n);

                if (res){
                    ICP_qualities.append(QString::fromStdString(list2[0]).toDouble());
                }
                else{
                    ICP_qualities.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ARTERIAL CERVICAL
            {
                if (DEBUG > 10) cout << "load()::ARTERIAL CERVICAL" << endl;

                int n = MRI_ARTERIAL_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ARTERIAL_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    arterial_cervical_heart_rates.append(QString::fromStdString(list2[3]).toDouble());
                    double mean_cycle = 60. / arterial_cervical_heart_rates.at(i);
                    arterial_cervical_mean_cycles.append(mean_cycle);
                    arterial_cervical_mins.append(QString::fromStdString(list2[4]).toDouble());
                    arterial_cervical_maxs.append(QString::fromStdString(list2[5]).toDouble());
                    arterial_cervical_means.append(QString::fromStdString(list2[6]).toDouble());
                    arterial_cervical_grads.append(QString::fromStdString(list2[7]).toDouble());
                    arterial_cervical_strokes.append(QString::fromStdString(list2[8]).toDouble());
                }
                else{
                    arterial_cervical_heart_rates.append(0.);
                    arterial_cervical_mean_cycles.append(0.);
                    arterial_cervical_mins.append(0.);
                    arterial_cervical_maxs.append(0.);
                    arterial_cervical_means.append(0.);
                    arterial_cervical_grads.append(0.);
                    arterial_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //VENOUS CERVICAL
            {
                if (DEBUG > 10) cout << "load()::VENOUS CERVICAL" << endl;

                int n = MRI_VENOUS_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    venous_cervical_mins.append(QString::fromStdString(list2[1]).toDouble());
                    venous_cervical_maxs.append(QString::fromStdString(list2[2]).toDouble());
                    venous_cervical_means.append(QString::fromStdString(list2[3]).toDouble());
                    venous_cervical_grads.append(QString::fromStdString(list2[4]).toDouble());
                    venous_cervical_strokes.append(QString::fromStdString(list2[5]).toDouble());
                }
                else{
                    venous_cervical_mins.append(0.);
                    venous_cervical_maxs.append(0.);
                    venous_cervical_means.append(0.);
                    venous_cervical_grads.append(0.);
                    venous_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //VENOUS CORR CERVICAL
            {
                if (DEBUG > 10) cout << "load()::VENOUS CORR CERVICAL" << endl;

                int n = MRI_VENOUS_CORR_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_VENOUS_CERVICAL_FILE_COR_DAT, list1, list2, n);

                if (res){
                    alphas_cervical.append(QString::fromStdString(list2[0]).toDouble());
                    venous_corr_cervical_mins.append(QString::fromStdString(list2[2]).toDouble());
                    venous_corr_cervical_maxs.append(QString::fromStdString(list2[3]).toDouble());
                    venous_corr_cervical_means.append(QString::fromStdString(list2[4]).toDouble());
                    venous_corr_cervical_grads.append(QString::fromStdString(list2[5]).toDouble());
                    venous_corr_cervical_strokes.append(QString::fromStdString(list2[6]).toDouble());
                }
                else{
                    alphas_cervical.append(0.);
                    venous_corr_cervical_mins.append(0.);
                    venous_corr_cervical_maxs.append(0.);
                    venous_corr_cervical_means.append(0.);
                    venous_corr_cervical_grads.append(0.);
                    venous_corr_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //CSF CERVICAL
            {
                if (DEBUG > 10) cout << "load()::CSF CERVICAL" << endl;

                int n = MRI_CSF_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    csf_cervical_heart_rates.append(QString::fromStdString(list2[1]).toDouble());
                    double mean_cycle = 60. / csf_cervical_heart_rates.at(i);
                    csf_cervical_mean_cycles.append(mean_cycle);
                    csf_cervical_mins.append(QString::fromStdString(list2[2]).toDouble());
                    csf_cervical_maxs.append(QString::fromStdString(list2[3]).toDouble());
                    csf_cervical_means.append(QString::fromStdString(list2[4]).toDouble());
                    csf_cervical_grads.append(QString::fromStdString(list2[5]).toDouble());
                    csf_cervical_strokes.append(QString::fromStdString(list2[6]).toDouble());
                }
                else{
                    csf_cervical_heart_rates.append(0.);
                    csf_cervical_mean_cycles.append(0.);
                    csf_cervical_mins.append(0.);
                    csf_cervical_maxs.append(0.);
                    csf_cervical_means.append(0.);
                    csf_cervical_grads.append(0.);
                    csf_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //CSF CORR CERVICAL
            {
                if (DEBUG > 10) cout << "load()::CSF CORR CERVICAL" << endl;

                int n = MRI_CSF_CORR_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_CSF_CERVICAL_FILE_COR_DAT, list1, list2, n);

                if (res){
                    mean_csfs_cervical.append(QString::fromStdString(list2[0]).toDouble());
                    csf_corr_cervical_mins.append(QString::fromStdString(list2[3]).toDouble());
                    csf_corr_cervical_maxs.append(QString::fromStdString(list2[4]).toDouble());
                    csf_corr_cervical_means.append(QString::fromStdString(list2[5]).toDouble());
                    csf_corr_cervical_grads.append(QString::fromStdString(list2[6]).toDouble());
                    csf_corr_cervical_strokes.append(QString::fromStdString(list2[7]).toDouble());
                }
                else{
                    mean_csfs_cervical.append(0.);
                    csf_corr_cervical_mins.append(0.);
                    csf_corr_cervical_maxs.append(0.);
                    csf_corr_cervical_means.append(0.);
                    csf_corr_cervical_grads.append(0.);
                    csf_corr_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //AV CERVICAL FLOW
            {
                if (DEBUG > 10) cout << "load()::AV CERVICAL FLOW" << endl;

                int n = MRI_AV_DATA_LENGTH+1;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_AV_FLOW_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    arteriovenous_flow_cervical_mins.append(QString::fromStdString(list2[0]).toDouble());
                    arteriovenous_flow_cervical_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    arteriovenous_flow_cervical_means.append(QString::fromStdString(list2[2]).toDouble());
                    arteriovenous_flow_cervical_grads.append(QString::fromStdString(list2[3]).toDouble());
                    arteriovenous_flow_cervical_strokes.append(QString::fromStdString(list2[4]).toDouble());
                    AV_ICVC_ratio_cervical.append(QString::fromStdString(list2[5]).toDouble());
                }
                else{
                    arteriovenous_flow_cervical_mins.append(0.);
                    arteriovenous_flow_cervical_maxs.append(0.);
                    arteriovenous_flow_cervical_means.append(0.);
                    arteriovenous_flow_cervical_grads.append(0.);
                    arteriovenous_flow_cervical_strokes.append(0.);
                    AV_ICVC_ratio_cervical.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //AV CERVICAL VOLUME
            {
                if (DEBUG > 10) cout << "load()::AV CERVICAL VOLUME" << endl;

                int n = MRI_AV_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_AV_VOLUME_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    arteriovenous_volume_cervical_mins.append(QString::fromStdString(list2[0]).toDouble());
                    arteriovenous_volume_cervical_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    arteriovenous_volume_cervical_means.append(QString::fromStdString(list2[2]).toDouble());
                    arteriovenous_volume_cervical_grads.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    arteriovenous_volume_cervical_mins.append(0.);
                    arteriovenous_volume_cervical_maxs.append(0.);
                    arteriovenous_volume_cervical_means.append(0.);
                    arteriovenous_volume_cervical_grads.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ICVC CERVICAL FLOW
            {
                if (DEBUG > 10) cout << "load()::ICVC CERVICAL FLOW" << endl;

                int n = MRI_ICVC_DATA_LENGTH+1;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ICVC_FLOW_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    icvc_flow_cervical_mins.append(QString::fromStdString(list2[0]).toDouble());
                    icvc_flow_cervical_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    icvc_flow_cervical_means.append(QString::fromStdString(list2[2]).toDouble());
                    icvc_flow_cervical_grads.append(QString::fromStdString(list2[3]).toDouble());
                    icvc_flow_cervical_strokes.append(QString::fromStdString(list2[4]).toDouble());
                    if (AV_ICVC_ratio_cervical.at(i) == 0.){
                        AV_ICVC_ratio_cervical.replace(i, QString::fromStdString(list2[5]).toDouble());
                    }
                }
                else{
                    icvc_flow_cervical_mins.append(0.);
                    icvc_flow_cervical_maxs.append(0.);
                    icvc_flow_cervical_means.append(0.);
                    icvc_flow_cervical_grads.append(0.);
                    icvc_flow_cervical_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ICVC CERVICAL VOLUME
            {
                if (DEBUG > 10) cout << "load()::ICVC CERVICAL VOLUME" << endl;

                int n = MRI_ICVC_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ICVC_VOLUME_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    icvc_volume_cervical_mins.append(QString::fromStdString(list2[0]).toDouble());
                    icvc_volume_cervical_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    icvc_volume_cervical_means.append(QString::fromStdString(list2[2]).toDouble());
                    icvc_volume_cervical_grads.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    icvc_volume_cervical_mins.append(0.);
                    icvc_volume_cervical_maxs.append(0.);
                    icvc_volume_cervical_means.append(0.);
                    icvc_volume_cervical_grads.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ARTERIAL CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::ARTERIAL CEREBRAL" << endl;

                int n = MRI_ARTERIAL_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ARTERIAL_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    arterial_cerebral_heart_rates.append(QString::fromStdString(list2[3]).toDouble());
                    double mean_cycle = 60. / arterial_cerebral_heart_rates.at(i);
                    arterial_cerebral_mean_cycles.append(mean_cycle);
                    arterial_cerebral_mins.append(QString::fromStdString(list2[4]).toDouble());
                    arterial_cerebral_maxs.append(QString::fromStdString(list2[5]).toDouble());
                    arterial_cerebral_means.append(QString::fromStdString(list2[6]).toDouble());
                    arterial_cerebral_grads.append(QString::fromStdString(list2[7]).toDouble());
                    arterial_cerebral_strokes.append(QString::fromStdString(list2[8]).toDouble());
                }
                else{
                    arterial_cerebral_heart_rates.append(0.);
                    arterial_cerebral_mean_cycles.append(0.);
                    arterial_cerebral_mins.append(0.);
                    arterial_cerebral_maxs.append(0.);
                    arterial_cerebral_means.append(0.);
                    arterial_cerebral_grads.append(0.);
                    arterial_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //VENOUS CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::VENOUS CEREBRAL" << endl;

                int n = MRI_VENOUS_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    venous_cerebral_mins.append(QString::fromStdString(list2[1]).toDouble());
                    venous_cerebral_maxs.append(QString::fromStdString(list2[2]).toDouble());
                    venous_cerebral_means.append(QString::fromStdString(list2[3]).toDouble());
                    venous_cerebral_grads.append(QString::fromStdString(list2[4]).toDouble());
                    venous_cerebral_strokes.append(QString::fromStdString(list2[5]).toDouble());
                }
                else{
                    venous_cerebral_mins.append(0.);
                    venous_cerebral_maxs.append(0.);
                    venous_cerebral_means.append(0.);
                    venous_cerebral_grads.append(0.);
                    venous_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //VENOUS CORR CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::VENOUS CORR CEREBRAL" << endl;

                int n = MRI_VENOUS_CORR_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_VENOUS_CEREBRAL_FILE_COR_DAT, list1, list2, n);

                if (res){
                    alphas_cerebral.append(QString::fromStdString(list2[0]).toDouble());
                    venous_corr_cerebral_mins.append(QString::fromStdString(list2[2]).toDouble());
                    venous_corr_cerebral_maxs.append(QString::fromStdString(list2[3]).toDouble());
                    venous_corr_cerebral_means.append(QString::fromStdString(list2[4]).toDouble());
                    venous_corr_cerebral_grads.append(QString::fromStdString(list2[5]).toDouble());
                    venous_corr_cerebral_strokes.append(QString::fromStdString(list2[6]).toDouble());
                }
                else{
                    alphas_cerebral.append(0.);
                    venous_corr_cerebral_mins.append(0.);
                    venous_corr_cerebral_maxs.append(0.);
                    venous_corr_cerebral_means.append(0.);
                    venous_corr_cerebral_grads.append(0.);
                    venous_corr_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //CSF CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::CSF CEREBRAL" << endl;

                int n = MRI_CSF_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    csf_cerebral_heart_rates.append(QString::fromStdString(list2[1]).toDouble());
                    double mean_cycle = 60. / csf_cervical_heart_rates.at(i);
                    csf_cerebral_mean_cycles.append(mean_cycle);
                    csf_cerebral_mins.append(QString::fromStdString(list2[2]).toDouble());
                    csf_cerebral_maxs.append(QString::fromStdString(list2[3]).toDouble());
                    csf_cerebral_means.append(QString::fromStdString(list2[4]).toDouble());
                    csf_cerebral_grads.append(QString::fromStdString(list2[5]).toDouble());
                    csf_cerebral_strokes.append(QString::fromStdString(list2[6]).toDouble());
                }
                else{
                    csf_cerebral_heart_rates.append(0.);
                    csf_cerebral_mean_cycles.append(0.);
                    csf_cerebral_mins.append(0.);
                    csf_cerebral_maxs.append(0.);
                    csf_cerebral_means.append(0.);
                    csf_cerebral_grads.append(0.);
                    csf_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //CSF CORR CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::CSF CORR CEREBRAL" << endl;

                int n = MRI_CSF_CORR_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_CSF_CEREBRAL_FILE_COR_DAT, list1, list2, n);

                if (res){
                    mean_csfs_cerebral.append(QString::fromStdString(list2[0]).toDouble());
                    csf_corr_cerebral_mins.append(QString::fromStdString(list2[3]).toDouble());
                    csf_corr_cerebral_maxs.append(QString::fromStdString(list2[4]).toDouble());
                    csf_corr_cerebral_means.append(QString::fromStdString(list2[5]).toDouble());
                    csf_corr_cerebral_grads.append(QString::fromStdString(list2[6]).toDouble());
                    csf_corr_cerebral_strokes.append(QString::fromStdString(list2[7]).toDouble());
                    //cout << list2[7] << endl;
                }
                else{
                    mean_csfs_cerebral.append(0.);
                    csf_corr_cerebral_mins.append(0.);
                    csf_corr_cerebral_maxs.append(0.);
                    csf_corr_cerebral_means.append(0.);
                    csf_corr_cerebral_grads.append(0.);
                    csf_corr_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //AV CEREBRAL FLOW
            {
                if (DEBUG > 10) cout << "load()::AV CEREBRAL FLOW" << endl;

                int n = MRI_AV_DATA_LENGTH+1;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_AV_FLOW_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    arteriovenous_flow_cerebral_mins.append(QString::fromStdString(list2[0]).toDouble());
                    arteriovenous_flow_cerebral_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    arteriovenous_flow_cerebral_means.append(QString::fromStdString(list2[2]).toDouble());
                    arteriovenous_flow_cerebral_grads.append(QString::fromStdString(list2[3]).toDouble());
                    arteriovenous_flow_cerebral_strokes.append(QString::fromStdString(list2[4]).toDouble());
                    AV_ICVC_ratio_cerebral.append(QString::fromStdString(list2[5]).toDouble());
                }
                else{
                    arteriovenous_flow_cerebral_mins.append(0.);
                    arteriovenous_flow_cerebral_maxs.append(0.);
                    arteriovenous_flow_cerebral_means.append(0.);
                    arteriovenous_flow_cerebral_grads.append(0.);
                    arteriovenous_flow_cerebral_strokes.append(0.);
                    AV_ICVC_ratio_cerebral.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //AV CEREBRAL VOLUME
            {
                if (DEBUG > 10) cout << "load()::AV CEREBRAL VOLUME" << endl;

                int n = MRI_AV_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_AV_VOLUME_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    arteriovenous_volume_cerebral_mins.append(QString::fromStdString(list2[0]).toDouble());
                    arteriovenous_volume_cerebral_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    arteriovenous_volume_cerebral_means.append(QString::fromStdString(list2[2]).toDouble());
                    arteriovenous_volume_cerebral_grads.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    arteriovenous_volume_cerebral_mins.append(0.);
                    arteriovenous_volume_cerebral_maxs.append(0.);
                    arteriovenous_volume_cerebral_means.append(0.);
                    arteriovenous_volume_cerebral_grads.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ICVC CEREBRAL FLOW
            {
                if (DEBUG > 10) cout << "load()::ICVC CEREBRAL FLOW" << endl;

                int n = MRI_ICVC_DATA_LENGTH+1;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ICVC_FLOW_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    icvc_flow_cerebral_mins.append(QString::fromStdString(list2[0]).toDouble());
                    icvc_flow_cerebral_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    icvc_flow_cerebral_means.append(QString::fromStdString(list2[2]).toDouble());
                    icvc_flow_cerebral_grads.append(QString::fromStdString(list2[3]).toDouble());
                    icvc_flow_cerebral_strokes.append(QString::fromStdString(list2[4]).toDouble());
                    if (AV_ICVC_ratio_cerebral.at(i) == 0.) AV_ICVC_ratio_cerebral.append(QString::fromStdString(list2[5]).toDouble());
                }
                else{
                    icvc_flow_cerebral_mins.append(0.);
                    icvc_flow_cerebral_maxs.append(0.);
                    icvc_flow_cerebral_means.append(0.);
                    icvc_flow_cerebral_grads.append(0.);
                    icvc_flow_cerebral_strokes.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //ICVC CEREBRAL VOLUME
            {
                if (DEBUG > 10) cout << "load()::ICVC CEREBRAL VOLUME" << endl;

                int n = MRI_ICVC_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + MRI_ICVC_VOLUME_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    icvc_volume_cerebral_mins.append(QString::fromStdString(list2[0]).toDouble());
                    icvc_volume_cerebral_maxs.append(QString::fromStdString(list2[1]).toDouble());
                    icvc_volume_cerebral_means.append(QString::fromStdString(list2[2]).toDouble());
                    icvc_volume_cerebral_grads.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    icvc_volume_cerebral_mins.append(0.);
                    icvc_volume_cerebral_maxs.append(0.);
                    icvc_volume_cerebral_means.append(0.);
                    icvc_volume_cerebral_grads.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }


            //ICP
            {
                if (DEBUG > 10) cout << "load()::ICP" << endl;

                int n = ICP_DATA_LENGHT;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + ICP_FILE_DAT, list1, list2, n);

                if (res){
                    icp_mins.append(QString::fromStdString(list2[1]).toDouble());
                    icp_maxs.append(QString::fromStdString(list2[2]).toDouble());
                    icp_means.append(QString::fromStdString(list2[3]).toDouble());
                    icp_grads.append(QString::fromStdString(list2[4]).toDouble());
                }
                else{
                    icp_mins.append(0.);
                    icp_maxs.append(0.);
                    icp_means.append(0.);
                    icp_grads.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }


            //COMPLIANCE GLOBAL AV CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE GLOBAL AV CERVICAL" << endl;

                int n = COMPLIANCE_G_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_AV_CERVICAL_FILE_DAT, list1, list2, n);

                if (!res){
                    res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_AV_CERVICAL_FILE_DAT_BIS, list1, list2, n);
                }

                if (res){
                    compliance_AV_global_cervical.append(QString::fromStdString(list2[0]).toDouble());
                }
                else{
                    compliance_AV_global_cervical.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE GLOBAL AV CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE GLOBAL AV CEREBRAL" << endl;

                int n = COMPLIANCE_G_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_AV_CEREBRAL_FILE_DAT, list1, list2, n);

                if (!res){
                    res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_AV_CEREBRAL_FILE_DAT_BIS, list1, list2, n);
                }

                if (res){
                    compliance_AV_global_cerebral.append(QString::fromStdString(list2[0]).toDouble());
                }
                else{
                    compliance_AV_global_cerebral.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE GLOBAL ICVC CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE GLOBAL ICVC CERVICAL" << endl;

                int n = COMPLIANCE_G_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_ICVC_CERVICAL_FILE_DAT, list1, list2, n);

                if (!res){
                    res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_ICVC_CERVICAL_FILE_DAT_BIS, list1, list2, n);
                }

                if (res){
                    compliance_ICVC_global_cervical.append(QString::fromStdString(list2[0]).toDouble());
                }
                else{
                    compliance_ICVC_global_cervical.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE GLOBAL ICVC CEREBRAL
            {
                if (DEBUG > 10) cout << "load():COMPLIANCE GLOBAL ICVC CEREBRAL" << endl;

                int n = COMPLIANCE_G_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_ICVC_CEREBRAL_FILE_DAT, list1, list2, n);

                if (!res){
                    res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_G_ICVC_CEREBRAL_FILE_DAT_BIS, list1, list2, n);
                }

                if (res){
                    compliance_ICVC_global_cerebral.append(QString::fromStdString(list2[0]).toDouble());
                }
                else{
                    compliance_ICVC_global_cerebral.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE PARTED AV CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE PARTED AV CERVICAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_AV_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_AV_mins_cervical_parted.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_AV_maxs_cervical_parted.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_AV_means_cervical_parted.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_AV_grads_cervical_parted.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_AV_mins_cervical_parted.append(0.);
                    compliance_AV_maxs_cervical_parted.append(0.);
                    compliance_AV_means_cervical_parted.append(0.);
                    compliance_AV_grads_cervical_parted.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE PARTED AV CEREBRAL
            {
                if (DEBUG > 10) cout << "COMPLIANCE PARTED AV CEREBRAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_AV_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_AV_mins_cerebral_parted.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_AV_maxs_cerebral_parted.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_AV_means_cerebral_parted.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_AV_grads_cerebral_parted.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_AV_mins_cerebral_parted.append(0.);
                    compliance_AV_maxs_cerebral_parted.append(0.);
                    compliance_AV_means_cerebral_parted.append(0.);
                    compliance_AV_grads_cerebral_parted.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE PARTED ICVC CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE PARTED ICVC CERVICAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_ICVC_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_ICVC_mins_cervical_parted.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_ICVC_maxs_cervical_parted.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_ICVC_means_cervical_parted.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_ICVC_grads_cervical_parted.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_ICVC_mins_cervical_parted.append(0.);
                    compliance_ICVC_maxs_cervical_parted.append(0.);
                    compliance_ICVC_means_cervical_parted.append(0.);
                    compliance_ICVC_grads_cervical_parted.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE PARTED ICVC CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE PARTED ICVC CEREBRAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_ICVC_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_ICVC_mins_cerebral_parted.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_ICVC_maxs_cerebral_parted.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_ICVC_means_cerebral_parted.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_ICVC_grads_cerebral_parted.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_ICVC_mins_cerebral_parted.append(0.);
                    compliance_ICVC_maxs_cerebral_parted.append(0.);
                    compliance_ICVC_means_cerebral_parted.append(0.);
                    compliance_ICVC_grads_cerebral_parted.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE CONTINUOUS AV CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE CONTINUOUS AV CERVICAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_C_AV_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_AV_mins_cervical_continuous.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_AV_maxs_cervical_continuous.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_AV_means_cervical_continuous.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_AV_grads_cervical_continuous.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_AV_mins_cervical_continuous.append(0.);
                    compliance_AV_maxs_cervical_continuous.append(0.);
                    compliance_AV_means_cervical_continuous.append(0.);
                    compliance_AV_grads_cervical_continuous.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE CONTINUOUS AV CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE CONTINUOUS AV CEREBRAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_C_AV_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_AV_mins_cerebral_continuous.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_AV_maxs_cerebral_continuous.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_AV_means_cerebral_continuous.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_AV_grads_cerebral_continuous.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_AV_mins_cerebral_continuous.append(0.);
                    compliance_AV_maxs_cerebral_continuous.append(0.);
                    compliance_AV_means_cerebral_continuous.append(0.);
                    compliance_AV_grads_cerebral_continuous.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE CONTINUOUS ICVC CERVICAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE CONTINUOUS ICVC CERVICAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_C_ICVC_CERVICAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_ICVC_mins_cervical_continuous.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_ICVC_maxs_cervical_continuous.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_ICVC_means_cervical_continuous.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_ICVC_grads_cervical_continuous.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_ICVC_mins_cervical_continuous.append(0.);
                    compliance_ICVC_maxs_cervical_continuous.append(0.);
                    compliance_ICVC_means_cervical_continuous.append(0.);
                    compliance_ICVC_grads_cervical_continuous.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }

            //COMPLIANCE CONTINUOUS ICVC CEREBRAL
            {
                if (DEBUG > 10) cout << "load()::COMPLIANCE CONTINUOUS ICVC CEREBRAL" << endl;

                int n = COMPLIANCE_DATA_LENGTH;

                string *list1 = new string[n];
                string *list2 = new string[n];

                bool res = load_sup_data(dir + DIR_SEPARATOR + patients.at(i) + DIR_SEPARATOR + COMPLIANCE_C_ICVC_CEREBRAL_FILE_DAT, list1, list2, n);

                if (res){
                    compliance_ICVC_mins_cerebral_continuous.append(QString::fromStdString(list2[0]).toDouble());
                    compliance_ICVC_maxs_cerebral_continuous.append(QString::fromStdString(list2[1]).toDouble());
                    compliance_ICVC_means_cerebral_continuous.append(QString::fromStdString(list2[2]).toDouble());
                    compliance_ICVC_grads_cerebral_continuous.append(QString::fromStdString(list2[3]).toDouble());
                }
                else{
                    compliance_ICVC_mins_cerebral_continuous.append(0.);
                    compliance_ICVC_maxs_cerebral_continuous.append(0.);
                    compliance_ICVC_means_cerebral_continuous.append(0.);
                    compliance_ICVC_grads_cerebral_continuous.append(0.);
                }

                delete[] list1;
                delete[] list2;
            }
        }

        label_n->setText(DIALOG_STATS_NFILES + QString::number(nb_lines));
    }
}

/*!
 * \brief DialogStats::clear
 *
 * Clear all data and plots
 */
void DialogStats::clear()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    loaded_list->clear();

    current_x.clear();
    current_y.clear();

    highlight_name.clear();
    highlight_x.clear();
    highlight_y.clear();

    names.clear();
    id.clear();

    arterial_cervical_qualities.clear();
    venous_cervical_qualities.clear();
    csf_cervical_qualities.clear();
    arterial_cerebral_qualities.clear();
    venous_cerebral_qualities.clear();
    csf_cerebral_qualities.clear();
    ICP_qualities.clear();

    arterial_cervical_mean_cycles.clear();
    arterial_cervical_heart_rates.clear();

    arterial_cervical_mins.clear();
    arterial_cervical_maxs.clear();
    arterial_cervical_means.clear();
    arterial_cervical_grads.clear();
    arterial_cervical_strokes.clear();

    venous_cervical_mins.clear();
    venous_cervical_maxs.clear();
    venous_cervical_means.clear();
    venous_cervical_grads.clear();
    venous_cervical_strokes.clear();

    alphas_cervical.clear();
    venous_corr_cervical_mins.clear();
    venous_corr_cervical_maxs.clear();
    venous_corr_cervical_means.clear();
    venous_corr_cervical_grads.clear();
    venous_corr_cervical_strokes.clear();

    csf_cervical_mean_cycles.clear();
    csf_cervical_heart_rates.clear();

    csf_cervical_mins.clear();
    csf_cervical_maxs.clear();
    csf_cervical_means.clear();
    csf_cervical_grads.clear();
    csf_cervical_strokes.clear();

    mean_csfs_cervical.clear();
    csf_corr_cervical_mins.clear();
    csf_corr_cervical_maxs.clear();
    csf_corr_cervical_means.clear();
    csf_corr_cervical_grads.clear();
    csf_corr_cervical_strokes.clear();

    AV_ICVC_ratio_cervical.clear();

    arteriovenous_flow_cervical_mins.clear();
    arteriovenous_flow_cervical_maxs.clear();
    arteriovenous_flow_cervical_means.clear();
    arteriovenous_flow_cervical_grads.clear();
    arteriovenous_flow_cervical_strokes.clear();

    arteriovenous_volume_cervical_mins.clear();
    arteriovenous_volume_cervical_maxs.clear();
    arteriovenous_volume_cervical_means.clear();
    arteriovenous_volume_cervical_grads.clear();

    icvc_flow_cervical_mins.clear();
    icvc_flow_cervical_maxs.clear();
    icvc_flow_cervical_means.clear();
    icvc_flow_cervical_grads.clear();
    icvc_flow_cervical_strokes.clear();

    icvc_volume_cervical_mins.clear();
    icvc_volume_cervical_maxs.clear();
    icvc_volume_cervical_means.clear();
    icvc_volume_cervical_grads.clear();

    arterial_cerebral_heart_rates.clear();
    arterial_cerebral_heart_rates.clear();

    arterial_cerebral_mins.clear();
    arterial_cerebral_maxs.clear();
    arterial_cerebral_means.clear();
    arterial_cerebral_grads.clear();
    arterial_cerebral_strokes.clear();

    venous_cerebral_mins.clear();
    venous_cerebral_maxs.clear();
    venous_cerebral_means.clear();
    venous_cerebral_grads.clear();
    venous_cerebral_strokes.clear();

    alphas_cerebral.clear();
    venous_corr_cerebral_mins.clear();
    venous_corr_cerebral_maxs.clear();
    venous_corr_cerebral_means.clear();
    venous_corr_cerebral_grads.clear();
    venous_corr_cerebral_strokes.clear();

    csf_cerebral_mean_cycles.clear();
    csf_cerebral_heart_rates.clear();

    csf_cerebral_mins.clear();
    csf_cerebral_maxs.clear();
    csf_cerebral_means.clear();
    csf_cerebral_grads.clear();
    csf_cerebral_strokes.clear();

    mean_csfs_cerebral.clear();
    csf_corr_cerebral_mins.clear();
    csf_corr_cerebral_maxs.clear();
    csf_corr_cerebral_means.clear();
    csf_corr_cerebral_grads.clear();
    csf_corr_cerebral_strokes.clear();

    AV_ICVC_ratio_cerebral.clear();

    arteriovenous_flow_cerebral_mins.clear();
    arteriovenous_flow_cerebral_maxs.clear();
    arteriovenous_flow_cerebral_means.clear();
    arteriovenous_flow_cerebral_grads.clear();
    arteriovenous_flow_cerebral_strokes.clear();

    arteriovenous_volume_cerebral_mins.clear();
    arteriovenous_volume_cerebral_maxs.clear();
    arteriovenous_volume_cerebral_means.clear();
    arteriovenous_volume_cerebral_grads.clear();

    icvc_flow_cerebral_mins.clear();
    icvc_flow_cerebral_maxs.clear();
    icvc_flow_cerebral_means.clear();
    icvc_flow_cerebral_grads.clear();
    icvc_flow_cerebral_strokes.clear();

    icvc_volume_cerebral_mins.clear();
    icvc_volume_cerebral_maxs.clear();
    icvc_volume_cerebral_means.clear();
    icvc_volume_cerebral_grads.clear();

    icp_mins.clear();
    icp_maxs.clear();
    icp_means.clear();
    icp_grads.clear();

    compliance_AV_global_cervical.clear();
    compliance_ICVC_global_cervical.clear();
    compliance_AV_global_cerebral.clear();
    compliance_ICVC_global_cerebral.clear();

    compliance_AV_mins_cervical_parted.clear();
    compliance_AV_maxs_cervical_parted.clear();
    compliance_AV_means_cervical_parted.clear();
    compliance_AV_grads_cervical_parted.clear();

    compliance_AV_mins_cervical_continuous.clear();
    compliance_AV_maxs_cervical_continuous.clear();
    compliance_AV_means_cervical_continuous.clear();
    compliance_AV_grads_cervical_continuous.clear();

    compliance_ICVC_mins_cervical_parted.clear();
    compliance_ICVC_maxs_cervical_parted.clear();
    compliance_ICVC_means_cervical_parted.clear();
    compliance_ICVC_grads_cervical_parted.clear();

    compliance_ICVC_mins_cervical_continuous.clear();
    compliance_ICVC_maxs_cervical_continuous.clear();
    compliance_ICVC_means_cervical_continuous.clear();
    compliance_ICVC_grads_cervical_continuous.clear();

    compliance_AV_mins_cerebral_parted.clear();
    compliance_AV_maxs_cerebral_parted.clear();
    compliance_AV_means_cerebral_parted.clear();
    compliance_AV_grads_cerebral_parted.clear();

    compliance_AV_mins_cerebral_continuous.clear();
    compliance_AV_maxs_cerebral_continuous.clear();
    compliance_AV_means_cerebral_continuous.clear();
    compliance_AV_grads_cerebral_continuous.clear();

    compliance_ICVC_mins_cerebral_parted.clear();
    compliance_ICVC_maxs_cerebral_parted.clear();
    compliance_ICVC_means_cerebral_parted.clear();
    compliance_ICVC_grads_cerebral_parted.clear();

    compliance_ICVC_mins_cerebral_continuous.clear();
    compliance_ICVC_maxs_cerebral_continuous.clear();
    compliance_ICVC_means_cerebral_continuous.clear();
    compliance_ICVC_grads_cerebral_continuous.clear();

    label_n->clear();
    label_corr_coeff->clear();
    label_formula->clear();

    plot_xy->graph(0)->clearData();
    plot_xy->graph(1)->clearData();
    plot_xy->graph(2)->clearData();
    for (int i = 0; i < (int)DIALOG_STATS_NB_CLUSTERING; i++){
        plot_xy->graph(3+i)->clearData();
    }
    plot_xy->replot();
}

/*!
 * \brief DialogStats::pre_plot
 *
 * Prepare to plot
 */
void DialogStats::pre_plot()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int *x_quality = new int[loaded_list->count()];
    int *y_quality = new int[loaded_list->count()];
    for (int i = 0; i < loaded_list->count(); i++){
        x_quality[i] = 5;
        y_quality[i] = 5;
    }

    current_x.clear();
    current_y.clear();

    highlight_x.clear();
    highlight_y.clear();

    plot_xy->graph(1)->clearData();
    for (int i = 0; i < (int)DIALOG_STATS_NB_CLUSTERING; i++){
        plot_xy->graph(3+i)->clearData();
    }

    if (box_x->currentText().compare(DIALOG_STATS_ITEM00) == 0){
        current_x = QVector<double>(id);
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM01) == 0){
        current_x = QVector<double>(arterial_cervical_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM02) == 0){
        current_x = QVector<double>(arterial_cervical_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM03) == 0){
        current_x = QVector<double>(arterial_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM04) == 0){
        current_x = QVector<double>(arterial_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM05) == 0){
        current_x = QVector<double>(arterial_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM06) == 0){
        current_x = QVector<double>(arterial_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM07) == 0){
        current_x = QVector<double>(arterial_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM08) == 0){
        current_x = QVector<double>(venous_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM09) == 0){
        current_x = QVector<double>(venous_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM10) == 0){
        current_x = QVector<double>(venous_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM11) == 0){
        current_x = QVector<double>(venous_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM12) == 0){
        current_x = QVector<double>(venous_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM13) == 0){
        current_x = QVector<double>(alphas_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM14) == 0){
        current_x = QVector<double>(venous_corr_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM15) == 0){
        current_x = QVector<double>(venous_corr_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM16) == 0){
        current_x = QVector<double>(venous_corr_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM17) == 0){
        current_x = QVector<double>(venous_corr_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM18) == 0){
        current_x = QVector<double>(venous_corr_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM19) == 0){
        current_x = QVector<double>(csf_cervical_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM20) == 0){
        current_x = QVector<double>(csf_cervical_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM21) == 0){
        current_x = QVector<double>(csf_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM22) == 0){
        current_x = QVector<double>(csf_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM23) == 0){
        current_x = QVector<double>(csf_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM24) == 0){
        current_x = QVector<double>(csf_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM25) == 0){
        current_x = QVector<double>(csf_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM26) == 0){
        current_x = QVector<double>(mean_csfs_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM27) == 0){
        current_x = QVector<double>(csf_corr_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM28) == 0){
        current_x = QVector<double>(csf_corr_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM29) == 0){
        current_x = QVector<double>(csf_corr_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM30) == 0){
        current_x = QVector<double>(csf_corr_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM31) == 0){
        current_x = QVector<double>(csf_corr_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM32) == 0){
        current_x = QVector<double>(AV_ICVC_ratio_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM33) == 0){
        current_x = QVector<double>(arteriovenous_flow_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM34) == 0){
        current_x = QVector<double>(arteriovenous_flow_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM35) == 0){
        current_x = QVector<double>(arteriovenous_flow_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM36) == 0){
        current_x = QVector<double>(arteriovenous_flow_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM37) == 0){
        current_x = QVector<double>(arteriovenous_flow_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM38) == 0){
        current_x = QVector<double>(arteriovenous_volume_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM39) == 0){
        current_x = QVector<double>(arteriovenous_volume_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM40) == 0){
        current_x = QVector<double>(arteriovenous_volume_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM41) == 0){
        current_x = QVector<double>(arteriovenous_volume_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM42) == 0){
        current_x = QVector<double>(icvc_flow_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM43) == 0){
        current_x = QVector<double>(icvc_flow_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM44) == 0){
        current_x = QVector<double>(icvc_flow_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM45) == 0){
        current_x = QVector<double>(icvc_flow_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM46) == 0){
        current_x = QVector<double>(icvc_flow_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM47) == 0){
        current_x = QVector<double>(icvc_volume_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM48) == 0){
        current_x = QVector<double>(icvc_volume_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM49) == 0){
        current_x = QVector<double>(icvc_volume_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM50) == 0){
        current_x = QVector<double>(icvc_volume_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM51) == 0){
        current_x = QVector<double>(arterial_cerebral_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM52) == 0){
        current_x = QVector<double>(arterial_cerebral_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM53) == 0){
        current_x = QVector<double>(arterial_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM54) == 0){
        current_x = QVector<double>(arterial_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM55) == 0){
        current_x = QVector<double>(arterial_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM56) == 0){
        current_x = QVector<double>(arterial_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM57) == 0){
        current_x = QVector<double>(arterial_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM58) == 0){
        current_x = QVector<double>(venous_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM59) == 0){
        current_x = QVector<double>(venous_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM60) == 0){
        current_x = QVector<double>(venous_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM61) == 0){
        current_x = QVector<double>(venous_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM62) == 0){
        current_x = QVector<double>(venous_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM63) == 0){
        current_x = QVector<double>(alphas_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM64) == 0){
        current_x = QVector<double>(venous_corr_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM65) == 0){
        current_x = QVector<double>(venous_corr_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM66) == 0){
        current_x = QVector<double>(venous_corr_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM67) == 0){
        current_x = QVector<double>(venous_corr_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM68) == 0){
        current_x = QVector<double>(venous_corr_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM69) == 0){
        current_x = QVector<double>(csf_cerebral_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM70) == 0){
        current_x = QVector<double>(csf_cerebral_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM71) == 0){
        current_x = QVector<double>(csf_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM72) == 0){
        current_x = QVector<double>(csf_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM73) == 0){
        current_x = QVector<double>(csf_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM74) == 0){
        current_x = QVector<double>(csf_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM75) == 0){
        current_x = QVector<double>(csf_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM76) == 0){
        current_x = QVector<double>(mean_csfs_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM77) == 0){
        current_x = QVector<double>(csf_corr_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM78) == 0){
        current_x = QVector<double>(csf_corr_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM79) == 0){
        current_x = QVector<double>(csf_corr_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM80) == 0){
        current_x = QVector<double>(csf_corr_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM81) == 0){
        current_x = QVector<double>(csf_corr_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM82) == 0){
        current_x = QVector<double>(AV_ICVC_ratio_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM83) == 0){
        current_x = QVector<double>(arteriovenous_flow_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM84) == 0){
        current_x = QVector<double>(arteriovenous_flow_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM85) == 0){
        current_x = QVector<double>(arteriovenous_flow_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM86) == 0){
        current_x = QVector<double>(arteriovenous_flow_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM87) == 0){
        current_x = QVector<double>(arteriovenous_flow_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM88) == 0){
        current_x = QVector<double>(arteriovenous_volume_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM89) == 0){
        current_x = QVector<double>(arteriovenous_volume_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM90) == 0){
        current_x = QVector<double>(arteriovenous_volume_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM91) == 0){
        current_x = QVector<double>(arteriovenous_volume_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM92) == 0){
        current_x = QVector<double>(icvc_flow_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM93) == 0){
        current_x = QVector<double>(icvc_flow_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM94) == 0){
        current_x = QVector<double>(icvc_flow_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM95) == 0){
        current_x = QVector<double>(icvc_flow_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM96) == 0){
        current_x = QVector<double>(icvc_flow_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM97) == 0){
        current_x = QVector<double>(icvc_volume_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM98) == 0){
        current_x = QVector<double>(icvc_volume_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM99) == 0){
        current_x = QVector<double>(icvc_volume_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM100) == 0){
        current_x = QVector<double>(icvc_volume_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM101) == 0){
        current_x = QVector<double>(icp_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM102) == 0){
        current_x = QVector<double>(icp_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM103) == 0){
        current_x = QVector<double>(icp_means);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM104) == 0){
        current_x = QVector<double>(icp_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM105) == 0){
        current_x = QVector<double>(compliance_AV_global_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM106) == 0){
        current_x = QVector<double>(compliance_ICVC_global_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM107) == 0){
        current_x = QVector<double>(compliance_AV_global_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM108) == 0){
        current_x = QVector<double>(compliance_ICVC_global_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM109) == 0){
        current_x = QVector<double>(compliance_AV_mins_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM110) == 0){
        current_x = QVector<double>(compliance_AV_maxs_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM111) == 0){
        current_x = QVector<double>(compliance_AV_means_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM112) == 0){
        current_x = QVector<double>(compliance_AV_grads_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM113) == 0){
        current_x = QVector<double>(compliance_AV_mins_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM114) == 0){
        current_x = QVector<double>(compliance_AV_maxs_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM115) == 0){
        current_x = QVector<double>(compliance_AV_means_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM116) == 0){
        current_x = QVector<double>(compliance_AV_grads_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM117) == 0){
        current_x = QVector<double>(compliance_ICVC_mins_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM118) == 0){
        current_x = QVector<double>(compliance_ICVC_maxs_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM119) == 0){
        current_x = QVector<double>(compliance_ICVC_means_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM120) == 0){
        current_x = QVector<double>(compliance_ICVC_grads_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM121) == 0){
        current_x = QVector<double>(compliance_ICVC_mins_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM122) == 0){
        current_x = QVector<double>(compliance_ICVC_maxs_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM123) == 0){
        current_x = QVector<double>(compliance_ICVC_means_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM124) == 0){
        current_x = QVector<double>(compliance_ICVC_grads_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cervical_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM125) == 0){
        current_x = QVector<double>(compliance_AV_mins_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM126) == 0){
        current_x = QVector<double>(compliance_AV_maxs_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM127) == 0){
        current_x = QVector<double>(compliance_AV_means_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM128) == 0){
        current_x = QVector<double>(compliance_AV_grads_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM129) == 0){
        current_x = QVector<double>(compliance_AV_mins_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM130) == 0){
        current_x = QVector<double>(compliance_AV_maxs_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM131) == 0){
        current_x = QVector<double>(compliance_AV_means_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM132) == 0){
        current_x = QVector<double>(compliance_AV_grads_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM133) == 0){
        current_x = QVector<double>(compliance_ICVC_mins_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM134) == 0){
        current_x = QVector<double>(compliance_ICVC_maxs_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM135) == 0){
        current_x = QVector<double>(compliance_ICVC_means_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM136) == 0){
        current_x = QVector<double>(compliance_ICVC_grads_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM137) == 0){
        current_x = QVector<double>(compliance_ICVC_mins_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM138) == 0){
        current_x = QVector<double>(compliance_ICVC_maxs_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM139) == 0){
        current_x = QVector<double>(compliance_ICVC_means_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_x->currentText().compare(DIALOG_STATS_ITEM140) == 0){
        current_x = QVector<double>(compliance_ICVC_grads_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            x_quality[i] = qMin(x_quality[i], arterial_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], venous_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], csf_cerebral_qualities.at(i));
            x_quality[i] = qMin(x_quality[i], ICP_qualities.at(i));
        }
    }

    if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM01) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*arterial_cervical_mean_cycles.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM02) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*arterial_cervical_heart_rates.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM51) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*arterial_cerebral_mean_cycles.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM52) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*arterial_cerebral_heart_rates.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM19) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*csf_cervical_mean_cycles.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM20) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*csf_cervical_heart_rates.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM69) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*csf_cerebral_mean_cycles.at(i));
        }
    }
    else if (box_x_weight->currentText().compare(DIALOG_STATS_ITEM70) == 0){
        int n = current_x.size();
        for (int i = 0; i < n; i++){
            current_x.replace(i, current_x.at(i)*csf_cerebral_heart_rates.at(i));
        }
    }


    if (box_y->currentText().compare(DIALOG_STATS_ITEM00) == 0){
        current_y = QVector<double>(id);
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM01) == 0){
        current_y = QVector<double>(arterial_cervical_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM02) == 0){
        current_y = QVector<double>(arterial_cervical_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM03) == 0){
        current_y = QVector<double>(arterial_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM04) == 0){
        current_y = QVector<double>(arterial_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM05) == 0){
        current_y = QVector<double>(arterial_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM06) == 0){
        current_y = QVector<double>(arterial_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM07) == 0){
        current_y = QVector<double>(arterial_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM08) == 0){
        current_y = QVector<double>(venous_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM09) == 0){
        current_y = QVector<double>(venous_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM10) == 0){
        current_y = QVector<double>(venous_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM11) == 0){
        current_y = QVector<double>(venous_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM12) == 0){
        current_y = QVector<double>(venous_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM13) == 0){
        current_y = QVector<double>(alphas_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM14) == 0){
        current_y = QVector<double>(venous_corr_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM15) == 0){
        current_y = QVector<double>(venous_corr_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM16) == 0){
        current_y = QVector<double>(venous_corr_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM17) == 0){
        current_y = QVector<double>(venous_corr_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM18) == 0){
        current_y = QVector<double>(venous_corr_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM19) == 0){
        current_y = QVector<double>(csf_cervical_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM20) == 0){
        current_y = QVector<double>(csf_cervical_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM21) == 0){
        current_y = QVector<double>(csf_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM22) == 0){
        current_y = QVector<double>(csf_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM23) == 0){
        current_y = QVector<double>(csf_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM24) == 0){
        current_y = QVector<double>(csf_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM25) == 0){
        current_y = QVector<double>(csf_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM26) == 0){
        current_y = QVector<double>(mean_csfs_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM27) == 0){
        current_y = QVector<double>(csf_corr_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM28) == 0){
        current_y = QVector<double>(csf_corr_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM29) == 0){
        current_y = QVector<double>(csf_corr_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM30) == 0){
        current_y = QVector<double>(csf_corr_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM31) == 0){
        current_y = QVector<double>(csf_corr_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM32) == 0){
        current_y = QVector<double>(AV_ICVC_ratio_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM33) == 0){
        current_y = QVector<double>(arteriovenous_flow_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM34) == 0){
        current_y = QVector<double>(arteriovenous_flow_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM35) == 0){
        current_y = QVector<double>(arteriovenous_flow_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM36) == 0){
        current_y = QVector<double>(arteriovenous_flow_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM37) == 0){
        current_y = QVector<double>(arteriovenous_flow_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM38) == 0){
        current_y = QVector<double>(arteriovenous_volume_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM39) == 0){
        current_y = QVector<double>(arteriovenous_volume_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM40) == 0){
        current_y = QVector<double>(arteriovenous_volume_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM41) == 0){
        current_y = QVector<double>(arteriovenous_volume_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM42) == 0){
        current_y = QVector<double>(icvc_flow_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM43) == 0){
        current_y = QVector<double>(icvc_flow_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM44) == 0){
        current_y = QVector<double>(icvc_flow_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM45) == 0){
        current_y = QVector<double>(icvc_flow_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM46) == 0){
        current_y = QVector<double>(icvc_flow_cervical_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM47) == 0){
        current_y = QVector<double>(icvc_volume_cervical_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM48) == 0){
        current_y = QVector<double>(icvc_volume_cervical_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM49) == 0){
        current_y = QVector<double>(icvc_volume_cervical_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM50) == 0){
        current_y = QVector<double>(icvc_volume_cervical_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM51) == 0){
        current_y = QVector<double>(arterial_cerebral_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM52) == 0){
        current_y = QVector<double>(arterial_cerebral_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM53) == 0){
        current_y = QVector<double>(arterial_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM54) == 0){
        current_y = QVector<double>(arterial_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM55) == 0){
        current_y = QVector<double>(arterial_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM56) == 0){
        current_y = QVector<double>(arterial_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM57) == 0){
        current_y = QVector<double>(arterial_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM58) == 0){
        current_y = QVector<double>(venous_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM59) == 0){
        current_y = QVector<double>(venous_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM60) == 0){
        current_y = QVector<double>(venous_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM61) == 0){
        current_y = QVector<double>(venous_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM62) == 0){
        current_y = QVector<double>(venous_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM63) == 0){
        current_y = QVector<double>(alphas_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM64) == 0){
        current_y = QVector<double>(venous_corr_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM65) == 0){
        current_y = QVector<double>(venous_corr_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM66) == 0){
        current_y = QVector<double>(venous_corr_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM67) == 0){
        current_y = QVector<double>(venous_corr_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM68) == 0){
        current_y = QVector<double>(venous_corr_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM69) == 0){
        current_y = QVector<double>(csf_cerebral_mean_cycles);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM70) == 0){
        current_y = QVector<double>(csf_cerebral_heart_rates);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM71) == 0){
        current_y = QVector<double>(csf_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM72) == 0){
        current_y = QVector<double>(csf_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM73) == 0){
        current_y = QVector<double>(csf_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM74) == 0){
        current_y = QVector<double>(csf_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM75) == 0){
        current_y = QVector<double>(csf_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM76) == 0){
        current_y = QVector<double>(mean_csfs_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM77) == 0){
        current_y = QVector<double>(csf_corr_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM78) == 0){
        current_y = QVector<double>(csf_corr_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM79) == 0){
        current_y = QVector<double>(csf_corr_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM80) == 0){
        current_y = QVector<double>(csf_corr_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM81) == 0){
        current_y = QVector<double>(csf_corr_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM82) == 0){
        current_y = QVector<double>(AV_ICVC_ratio_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM83) == 0){
        current_y = QVector<double>(arteriovenous_flow_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM84) == 0){
        current_y = QVector<double>(arteriovenous_flow_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM85) == 0){
        current_y = QVector<double>(arteriovenous_flow_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM86) == 0){
        current_y = QVector<double>(arteriovenous_flow_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM87) == 0){
        current_y = QVector<double>(arteriovenous_flow_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM88) == 0){
        current_y = QVector<double>(arteriovenous_volume_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM89) == 0){
        current_y = QVector<double>(arteriovenous_volume_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM90) == 0){
        current_y = QVector<double>(arteriovenous_volume_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM91) == 0){
        current_y = QVector<double>(arteriovenous_volume_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM92) == 0){
        current_y = QVector<double>(icvc_flow_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM93) == 0){
        current_y = QVector<double>(icvc_flow_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM94) == 0){
        current_y = QVector<double>(icvc_flow_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM95) == 0){
        current_y = QVector<double>(icvc_flow_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM96) == 0){
        current_y = QVector<double>(icvc_flow_cerebral_strokes);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM97) == 0){
        current_y = QVector<double>(icvc_volume_cerebral_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM98) == 0){
        current_y = QVector<double>(icvc_volume_cerebral_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM99) == 0){
        current_y = QVector<double>(icvc_volume_cerebral_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM100) == 0){
        current_y = QVector<double>(icvc_volume_cerebral_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM101) == 0){
        current_y = QVector<double>(icp_mins);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM102) == 0){
        current_y = QVector<double>(icp_maxs);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM103) == 0){
        current_y = QVector<double>(icp_means);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM104) == 0){
        current_y = QVector<double>(icp_grads);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM105) == 0){
        current_y = QVector<double>(compliance_AV_global_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM106) == 0){
        current_y = QVector<double>(compliance_ICVC_global_cervical);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM107) == 0){
        current_y = QVector<double>(compliance_AV_global_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM108) == 0){
        current_y = QVector<double>(compliance_ICVC_global_cerebral);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM109) == 0){
        current_y = QVector<double>(compliance_AV_mins_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM110) == 0){
        current_y = QVector<double>(compliance_AV_maxs_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM111) == 0){
        current_y = QVector<double>(compliance_AV_means_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM112) == 0){
        current_y = QVector<double>(compliance_AV_grads_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM113) == 0){
        current_y = QVector<double>(compliance_AV_mins_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM114) == 0){
        current_y = QVector<double>(compliance_AV_maxs_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM115) == 0){
        current_y = QVector<double>(compliance_AV_means_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM116) == 0){
        current_y = QVector<double>(compliance_AV_grads_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM117) == 0){
        current_y = QVector<double>(compliance_ICVC_mins_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM118) == 0){
        current_y = QVector<double>(compliance_ICVC_maxs_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM119) == 0){
        current_y = QVector<double>(compliance_ICVC_means_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM120) == 0){
        current_y = QVector<double>(compliance_ICVC_grads_cervical_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM121) == 0){
        current_y = QVector<double>(compliance_ICVC_mins_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM122) == 0){
        current_y = QVector<double>(compliance_ICVC_maxs_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM123) == 0){
        current_y = QVector<double>(compliance_ICVC_means_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM124) == 0){
        current_y = QVector<double>(compliance_ICVC_grads_cervical_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cervical_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM125) == 0){
        current_y = QVector<double>(compliance_AV_mins_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM126) == 0){
        current_y = QVector<double>(compliance_AV_maxs_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM127) == 0){
        current_y = QVector<double>(compliance_AV_means_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM128) == 0){
        current_y = QVector<double>(compliance_AV_grads_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM129) == 0){
        current_y = QVector<double>(compliance_AV_mins_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM130) == 0){
        current_y = QVector<double>(compliance_AV_maxs_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM131) == 0){
        current_y = QVector<double>(compliance_AV_means_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM132) == 0){
        current_y = QVector<double>(compliance_AV_grads_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM133) == 0){
        current_y = QVector<double>(compliance_ICVC_mins_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM134) == 0){
        current_y = QVector<double>(compliance_ICVC_maxs_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM135) == 0){
        current_y = QVector<double>(compliance_ICVC_means_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM136) == 0){
        current_y = QVector<double>(compliance_ICVC_grads_cerebral_parted);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM137) == 0){
        current_y = QVector<double>(compliance_ICVC_mins_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM138) == 0){
        current_y = QVector<double>(compliance_ICVC_maxs_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM139) == 0){
        current_y = QVector<double>(compliance_ICVC_means_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }
    else if (box_y->currentText().compare(DIALOG_STATS_ITEM140) == 0){
        current_y = QVector<double>(compliance_ICVC_grads_cerebral_continuous);
        for (int i = 0; i < loaded_list->count(); i++){
            y_quality[i] = qMin(y_quality[i], arterial_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], venous_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], csf_cerebral_qualities.at(i));
            y_quality[i] = qMin(y_quality[i], ICP_qualities.at(i));
        }
    }

    if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM01) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*arterial_cervical_mean_cycles.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM02) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*arterial_cervical_heart_rates.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM51) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*arterial_cerebral_mean_cycles.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM52) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*arterial_cerebral_heart_rates.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM19) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*csf_cervical_mean_cycles.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM20) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*csf_cervical_heart_rates.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM69) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*csf_cerebral_mean_cycles.at(i));
        }
    }
    else if (box_y_weight->currentText().compare(DIALOG_STATS_ITEM70) == 0){
        int n = current_y.size();
        for (int i = 0; i < n; i++){
            current_y.replace(i, current_y.at(i)*csf_cerebral_heart_rates.at(i));
        }
    }

    for (int i = 0; i < loaded_list->count(); i++){
        int quality = qMin(x_quality[i], y_quality[i]);
        if (quality == 5){
            loaded_list->item(i)->setTextColor(QColor(Qt::darkGreen));
        }
        else if (quality > 1){
            loaded_list->item(i)->setTextColor(QColor(Qt::darkRed));
        }
        else{
            loaded_list->item(i)->setTextColor(QColor(Qt::darkGray));
        }
        loaded_list->item(i)->setToolTip("x quality = " + QString::number(x_quality[i]) + ", y quality = " + QString::number(y_quality[i]));
    }

    delete[] x_quality;
    delete[] y_quality;

    plot_xy_curve(current_x, current_y);
}

/*!
 * \brief DialogStats::plot_xy_curve
 * \param x Vector x
 * \param y Vector y
 *
 * Plot the xy curve
 */
void DialogStats::plot_xy_curve(QVector<double> x, QVector<double> y)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Plot
    plot_xy->graph(0)->setData(x, y);

    //Range
    double minx = min(x), maxx = max(x), miny = min(y), maxy = max(y);

    if (minx == 0){
        minx = -0.1*maxx;
    }
    if (maxx == 0){
        maxx = -0.1*minx;
    }
    if (miny == 0){
        miny = -0.1*maxy;
    }
    if (maxy == 0){
        maxy = -0.1*miny;
    }

    plot_xy->xAxis->setRange(minx - 0.1*qAbs(minx), maxx + 0.1*qAbs(maxx));
    plot_xy->yAxis->setRange(miny - 0.1*qAbs(miny), maxy + 0.1*qAbs(maxy));

    //Display
    plot_xy->replot();

    //Update selection
    list_select();
}

/*!
 * \brief DialogStats::plot_regression_curve
 * \param x Vector x
 * \param y Vector y
 *
 * Plot the regression curve
 */
void DialogStats::plot_regression_curve(QVector<double> x, QVector<double> y)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //Plot
    plot_xy->graph(1)->setData(x, y);

    //(no range)

    //Display
    plot_xy->replot();
}

void DialogStats::closeEvent(QCloseEvent *)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    this->deleteLater();
}

/*!
 * \brief DialogStats::quit
 *
 * Close DialogStats
 */
void DialogStats::quit()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    this->deleteLater();

    accept();
}

/*!
 * \brief DialogStats::regression
 *
 * Regression calculus
 */
void DialogStats::regression()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res;
    QStringList choice;
    choice.append(DIALOG_STATS_REG1);
    choice.append(DIALOG_STATS_REG2);
    choice.append(DIALOG_STATS_REG3);
    QString item = QInputDialog::getItem(this, DIALOG_STATS_REG_TIT, DIALOG_STATS_REG_TXT, choice, 0, false, &res);

    if (res){
        if (item.compare(DIALOG_STATS_REG1) == 0){
            //Linear
            reg.clear();
            reg_csv.clear();

            double a, b;
            double corr_coeff = linear_regression(highlight_x, highlight_y, &a, &b);

            QVector<double> x;
            double minx = min(highlight_x), maxx = max(highlight_x);
            minx = minx - 0.1*qAbs(minx);
            maxx = maxx + 0.1*qAbs(maxx);
            for (int i = 0; i < 1000; i++){
                x.append(minx + (maxx-minx)*(i/999.));
            }

            for (int i = 0; i < x.size(); i++){
                reg.append(a * x.at(i) + b);
            }

            label_corr_coeff->setText(DIALOG_STATS_CCOEFF + QString::number(corr_coeff));
            label_formula->setText("y = "+QString::number(a)+"x + "+QString::number(b));

            plot_regression_curve(x, reg);

            for (int i = 0; i < highlight_x.size(); i++){
                reg_csv.append(a * highlight_x.at(i) + b);
            }
        }
        else if (item.compare(DIALOG_STATS_REG2) == 0){
            //Exponential
            reg.clear();
            reg_csv.clear();

            QVector<double> z, t;
            for (int i = 0; i < highlight_x.size(); i++){
                z.append(log(highlight_x.at(i)));
                t.append(log(highlight_y.at(i)));
            }

            double a, b;
            double corr_coeff = linear_regression(z, t, &a, &b);

            double c, gamma;
            c = exp(b);
            gamma = a;

            QVector<double> x;
            double minx = min(highlight_x), maxx = max(highlight_x);
            minx = minx - 0.1*qAbs(minx);
            maxx = maxx + 0.1*qAbs(maxx);
            for (int i = 0; i < 1000; i++){
                x.append(minx + (maxx-minx)*(i/999.));
            }

            for (int i = 0; i < x.size(); i++){
                reg.append(c * qPow(x.at(i), gamma));
            }

            label_corr_coeff->setText(DIALOG_STATS_CCOEFF + QString::number(corr_coeff));
            label_formula->setText("y = "+QString::number(c)+"x^"+QString::number(gamma));

            plot_regression_curve(x, reg);

            for (int i = 0; i < highlight_x.size(); i++){
                reg_csv.append(c * qPow(highlight_x.at(i), gamma));
            }
        }
        else if (item.compare(DIALOG_STATS_REG3) == 0){
            //Logistic
            reg.clear();
            reg_csv.clear();

            double gamma = QInputDialog::getDouble(this, DIALOG_STATS_GAMMA_TIT, DIALOG_STATS_GAMMA_TXT, 0.001, -100., 100., 5);

            QVector<double> t, z;
            for (int i = 0; i < highlight_x.size(); i++){
                t.append(exp(-gamma * highlight_x.at(i)));
                z.append(1. / highlight_y.at(i));
            }

            double a, b;
            double corr_coeff = linear_regression(t, z, &a, &b);

            QVector<double> x;
            double minx = min(highlight_x), maxx = max(highlight_x);
            minx = minx - 0.1*qAbs(minx);
            maxx = maxx + 0.1*qAbs(maxx);

            for (int i = 0; i < 1000; i++){
                x.append(minx + (maxx-minx)*(i/999.));
            }

            for (int i = 0; i < x.size(); i++){
                reg.append( 1. / (b + a*exp(-gamma*x.at(i))) );
            }

            label_corr_coeff->setText(DIALOG_STATS_CCOEFF + QString::number(corr_coeff));
            label_formula->setText("y = 1/( " + QString::number(a) + " exp(-gamma x) + " + QString::number(b) + ")");

            plot_regression_curve(x, reg);

            for (int i = 0; i < highlight_x.size(); i++){
                reg_csv.append( 1. / (b + a*exp(-gamma*highlight_x.at(i))) );
            }
        }
    }
}

/*!
 * \brief DialogStats::clustering
 *
 * Clustering calculus
 */
void DialogStats::do_clustering()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    bool res;
    int num = QInputDialog::getInt(this, "K-means", "Number of groups", 2, 2, (int)DIALOG_STATS_NB_CLUSTERING, 1, &res);

    /*  //TEST
    for (int i = 0; i < k; i++){
        for (int j = i*highlight_x.size()/k; j < (i+1)*highlight_x.size()/k; j++){
            x[i].append(highlight_x.at(j));
            y[i].append(highlight_y.at(j));
        }
    }*/

    /*double eps = 1.e-3;
    int itermax = 1e6;*/

    if (res){
        int n = highlight_x.size();

        if (n == 0) return;

        double *a = new double[n];
        double *b = new double[n];

        for (int i = 0; i < n; i++){
            a[i] = highlight_x.at(i);
            b[i] = highlight_y.at(i);
        }

        int *group = clustering(n, a, b, num);
        clust.clear();
        clust.resize(n);

        for (int i = 0; i < n; i++){
            clust.replace(i, group[i]+1);
        }

        for (int i = 0; i < n; i++){
            cout << group[i] << endl;
        }

        QVector<double> *x = new QVector<double>[num];
        QVector<double> *y = new QVector<double>[num];

        for (int i = 0; i < num; i++){
            for (int j = 0; j < n; j++){
                if (group[j] == i){
                    x[i].append(a[j]);
                    y[i].append(b[j]);
                }
            }
        }


        delete[] a;
        delete[] b;
        delete[] group;


        plot_clustering(x, y, num);

        /*clust.clear();

        int k = num;
        int n = highlight_x.size();

        clust.resize(n);

        double minx = min(highlight_x);
        double maxx = max(highlight_x);
        double miny = min(highlight_y);
        double maxy = max(highlight_y);

        QVector<double> *x = new QVector<double>[k];
        QVector<double> *y = new QVector<double>[k];

        double **S = new double*[k];
        for (int i = 0; i < k; i++){
            S[i] = new double[n];
            for (int j = 0; j < n; j++){
                S[i][j] = -1;
            }
        }

        qsrand(QTime::currentTime().msec());
        double **means = new double*[k];
        for (int i = 0; i < k; i++){
            means[i] = new double[2];
            means[i][0] = minx + (qrand()/RAND_MAX-1)*maxx;
            means[i][1] = miny + (qrand()/RAND_MAX-1)*maxy;
        }
        double **means1 = new double*[k];
        for (int i = 0; i < k; i++){
            means1[i] = new double[2];
        }

        bool resume = false;
        int iter = 0;
        while(!resume && iter < itermax){
            //Means save
            for (int i = 0; i < k; i++){
                means1[i][0] = means[i][0];
                means1[i][1] = means[i][1];
            }

            //S
            for (int i = 0; i < k; i++){
                for (int j = 0; j < n; j++){
                    bool ok = true;
                    double Smin =  sqrt(qPow(highlight_x.at(j)-means[i][0], 2) + qPow(highlight_y.at(j)-means[i][1], 2));

                    for (int l = 0; l < k; l++){
                        double Smin2 =  sqrt(qPow(highlight_x.at(j)-means[l][0], 2) + qPow(highlight_y.at(j)-means[l][1], 2));
                        if (Smin2 < Smin){
                            ok = false;
                        }
                    }

                    if (ok){
                        S[i][j] = j;
                    }
                    else{
                        S[i][j] = -1;
                    }
                }
            }

            //Means
            for (int i = 0; i < k; i++){
                int number = 0;
                means[i][0] = 0.;
                means[i][1] = 0.;
                for (int j = 0; j < n; j++){
                    if (S[i][j] != -1){
                        means[i][0] += highlight_x.at(i);
                        means[i][1] += highlight_y.at(i);
                        number++;
                    }
                }
                means[i][0] = means[i][0] / number;
                means[i][1] = means[i][1] / number;
            }

            //Convergence index
            double meansum = 0.;
            for (int i = 0; i < k; i++){
                meansum += sqrt(qPow(means[i][0] - means1[i][0], 2) + qPow(means[i][1] - means1[i][1], 2));
            }
            meansum = meansum / k;

            if (meansum < eps){
                resume = true;
            }

            iter++;
        }
        //cout << "Clustering end at " << iter << endl;
        //cout << "Iter max = " << itermax << endl;

        //Classes
        for (int i = 0; i < k; i++){
            for (int j = 0; j < n; j++){
                if (S[i][j] != -1){
                    x[i].append(highlight_x.at(S[i][j]));
                    y[i].append(highlight_y.at(S[i][j]));
                    clust.replace(j, (i+1));
                }
            }
        }


        plot_clustering(x, y, k);

        //Delete
        /*for (int i = 0; i < k; i++){
            delete[] S[i];
            delete[] means[i];
            delete[] means1[i];
        }
        delete[] S;
        delete[] means;
        delete[] means1;*/
    }
}

/*!
 * \brief DialogStats::plot_clustering
 * \param x Vector x
 * \param y Vector y
 * \param k Number of cluster
 *
 * Plot the clustered data
 */
void DialogStats::plot_clustering(QVector<double> *x, QVector<double> *y, int k)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    for (int i = 0; i < (int)DIALOG_STATS_NB_CLUSTERING; i++){
        plot_xy->graph(3+i)->clearData();
    }

    if (k > 0){
        for (int i = 0; i < k; i++){
            if (x[i].size() > 0){
                plot_xy->graph(i+3)->setData(x[i], y[i]);
            }
        }
    }

    plot_xy->replot();
}

/*!
 * \brief DialogStats::list_select
 *
 * Define selected patients
 */
void DialogStats::list_select()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n = loaded_list->count();

    highlight_name.clear();
    highlight_x.clear();
    highlight_y.clear();
    for (int i = 0; i < n; i++){
        if (loaded_list->item(i)->isSelected()){
            for (int j = 0; j < names.size(); j++){
                if (loaded_list->item(i)->text().compare(names.at(j)) == 0){
                    highlight_name.append(names.at(j).toStdString());
                    highlight_x.append(current_x.at(j));
                    highlight_y.append(current_y.at(j));
                }
            }
        }
    }

    plot_hightlight(highlight_x, highlight_y);
}

/*!
 * \brief DialogStats::plot_hightlight
 * \param x Vector x
 * \param y Vector y
 *
 * Plot selected patients
 */
void DialogStats::plot_hightlight(QVector<double> x, QVector<double> y)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (x.size() > 0){
        //Plot
        plot_xy->graph(2)->setData(x, y);

        plot_xy->replot();
    }
    else{
        plot_xy->graph(2)->clearData();

        plot_xy->replot();
    }
}

void DialogStats::zoom(){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    if (highlight_x.size() > 0){
        double minx = min(highlight_x);
        double maxx = max(highlight_x);
        double miny = min(highlight_y);
        double maxy = max(highlight_y);

        if (minx == 0){
            minx = -0.1*maxx;
        }
        if (maxx == 0){
            maxx = -0.1*minx;
        }
        if (miny == 0){
            miny = -0.1*maxy;
        }
        if (maxy == 0){
            maxy = -0.1*miny;
        }

        plot_xy->xAxis->setRange(minx - 0.1*qAbs(minx), maxx + 0.1*qAbs(maxx));
        plot_xy->yAxis->setRange(miny - 0.1*qAbs(miny), maxy + 0.1*qAbs(maxy));

        plot_xy->replot();
    }
    else if (current_x.size() > 0){
        double minx = min(current_x);
        double maxx = max(current_x);
        double miny = min(current_y);
        double maxy = max(current_y);

        if (minx == 0){
            minx = -0.1*maxx;
        }
        if (maxx == 0){
            maxx = -0.1*minx;
        }
        if (miny == 0){
            miny = -0.1*maxy;
        }
        if (maxy == 0){
            maxy = -0.1*miny;
        }

        plot_xy->xAxis->setRange(minx - 0.1*qAbs(minx), maxx + 0.1*qAbs(maxx));
        plot_xy->yAxis->setRange(miny - 0.1*qAbs(miny), maxy + 0.1*qAbs(maxy));

        plot_xy->replot();
    }
}

/*!
 * \brief DialogStats::export2csv
 *
 * Export to CSV (MS Excel, Oo Calc)
 */
void DialogStats::export2csv()
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    int n1 = highlight_x.size();
    int n2 = highlight_y.size();

    if (n1 > 0 && n2 > 0 && n1 == n2){
        QString file_name = QFileDialog::getSaveFileName(this, get_Results_directory(), get_Results_directory() + box_x->currentText() + "--" + box_y->currentText() + ".csv", DIALOG_STATS_EXPORT);

        if (!file_name.isEmpty()){
            if (reg_csv.size() > 0){
                    if (clust.size() > 0){
                        save_csv(file_name, box_x->currentText(), box_y->currentText(), highlight_name, highlight_x, highlight_y, reg_csv, clust);
                    }
                    else{
                        save_csv(file_name, box_x->currentText(), box_y->currentText(), highlight_name, highlight_x, highlight_y, reg_csv);
                    }
            }
            else{
                if (clust.size() > 0){
                    save_csv(file_name, box_x->currentText(), box_y->currentText(), highlight_name, highlight_x, highlight_y, QVector<double>(), clust);
                }
                else{
                    save_csv(file_name, box_x->currentText(), box_y->currentText(), highlight_name, highlight_x, highlight_y);
                }
            }
        }
    }
}

void DialogStats::get_patient(QMouseEvent *m_event){
    double x = plot_xy->xAxis->pixelToCoord(m_event->x());
    double y = plot_xy->yAxis->pixelToCoord(m_event->y());

    int n = current_x.size();
    if (n > 0){
        double maxx = max(current_x);
        double maxy = max(current_y);
        double epsx = 1.e-2*maxx;
        double epsy = 1.e-2*maxy;
        for (int i = 0; i < n; i++){
            if (qAbs(current_x.at(i) - x) < epsx && qAbs(current_y.at(i) - y) < epsy){
                if (loaded_list->item(i)->isSelected()){
                    loaded_list->item(i)->setSelected(false);
                }
                else{
                    loaded_list->item(i)->setSelected(true);
                }
            }
        }
    }
}

void DialogStats::resizeEvent(QResizeEvent *){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    loaded_list->setMaximumWidth(0.2*this->width());
}
