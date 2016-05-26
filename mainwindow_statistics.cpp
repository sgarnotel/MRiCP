/****************************************************************************
**  This is a part of MRiCP                                                **
**  Copyright (C) 2016  Simon Garnotel                                     **
**                                                                         **
**  This program is free software: you can redistribute it and/or modify   **
**  it under the terms of the GNU General Public License as published by   **
**  the Free Software Foundation, either version 3 of the License, or      **
**  (at your option) any later version.                                    **
**                                                                         **
**  This program is distributed in the hope that it will be useful,        **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of         **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
**  GNU General Public License for more details.                           **
**                                                                         **
**  You should have received a copy of the GNU General Public License      **
**  along with this program.  If not, see <http://www.gnu.org/licenses/>.  **
**                                                                         **
** **************************************************************************
**                                                                         **
** Author: Simon Garnotel                                                  **
** Contact: simon.garnotel@gmail.com                                       **
** Date: 05/2016                                                           **
** Version: 1.0                                                            **
****************************************************************************/

#include "mainwindow.h"

#define NDATA   20

//TODO

void MainWindow::STATISTICS__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    STATISTICS__vbox_load = new QVBoxLayout;

    //HBox
    STATISTICS__hbox_x = new QHBoxLayout;
    STATISTICS__hbox_y = new QHBoxLayout;
    STATISTICS__hbox_tools = new QHBoxLayout;

    //Plot
    STATISTICS__plot = new QCustomPlot;

    //List
    STATISTICS__list_load = new QListWidget;

    //Label
    STATISTICS__label_x = new QLabel;
    STATISTICS__label_y = new QLabel;
    STATISTICS__label_weight_x = new QLabel;
    STATISTICS__label_weight_y = new QLabel;

    //ComboBox
    STATISTICS__combobox_x = new QComboBox;
    STATISTICS__combobox_y = new QComboBox;
    STATISTICS__combobox_weight_x = new QComboBox;
    STATISTICS__combobox_weight_y = new QComboBox;

    //Button
    STATISTICS__button_load = new QPushButton;
    STATISTICS__button_make_group = new QPushButton;
    STATISTICS__button_remove = new QPushButton;
    STATISTICS__button_regression = new QPushButton;
    STATISTICS__button_clustering = new QPushButton;
    STATISTICS__button_export = new QPushButton;

    //Vector
    STATISTICS__vector_data = new QVector<double>*[NDATA];
    for (unsigned int i = 0; i < (unsigned int)NDATA; i++){
        STATISTICS__vector_data[i] = new QVector<double>;
    }

    //Int
    STATISTICS__int_group = 0;
}

void MainWindow::STATISTICS__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    STATISTICS__vbox_load->addWidget(STATISTICS__button_load);
    STATISTICS__vbox_load->addWidget(STATISTICS__button_make_group);
    STATISTICS__vbox_load->addWidget(STATISTICS__button_remove);
    STATISTICS__vbox_load->addWidget(STATISTICS__list_load);

    //HBox
    STATISTICS__hbox_x->addWidget(STATISTICS__label_x);
    STATISTICS__hbox_x->addWidget(STATISTICS__combobox_x);
    STATISTICS__hbox_x->addWidget(STATISTICS__label_weight_x);
    STATISTICS__hbox_x->addWidget(STATISTICS__combobox_weight_x);
    STATISTICS__hbox_y->addWidget(STATISTICS__label_y);
    STATISTICS__hbox_y->addWidget(STATISTICS__combobox_y);
    STATISTICS__hbox_y->addWidget(STATISTICS__label_weight_y);
    STATISTICS__hbox_y->addWidget(STATISTICS__combobox_weight_y);
    STATISTICS__hbox_tools->addWidget(STATISTICS__button_regression);
    STATISTICS__hbox_tools->addWidget(STATISTICS__button_clustering);
    STATISTICS__hbox_tools->addWidget(STATISTICS__button_export);

    //Plot
    STATISTICS__plot->addGraph();

    //List
    STATISTICS__list_load->setSelectionMode(QListWidget::MultiSelection);

    //Label
    STATISTICS__label_x->setText("x: ");
    STATISTICS__label_y->setText("y: ");
    STATISTICS__label_weight_x->setText("Weight x: ");
    STATISTICS__label_weight_y->setText("Weight y: ");

    //ComboBox
    STATISTICS__combobox_weight_x->addItem("None");
    STATISTICS__combobox_weight_y->addItem("None");

    //Button
    STATISTICS__button_load->setIcon(QIcon("img/dir.png"));
    STATISTICS__button_load->setToolTip("Load");
    STATISTICS__button_make_group->setText("Group");
    STATISTICS__button_remove->setText("Remove");
    STATISTICS__button_regression->setText("Regression");
    STATISTICS__button_clustering->setText("Clustering");
    STATISTICS__button_export->setText("Export to CSV");
}

void MainWindow::STATISTICS__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //List
    connect(STATISTICS__list_load, SIGNAL(itemSelectionChanged()), this, SLOT(STATISTICS__do_plot()));

    //ComboBox
    connect(STATISTICS__combobox_x, SIGNAL(currentIndexChanged(int)), this, SLOT(STATISTICS__do_plot()));
    connect(STATISTICS__combobox_y, SIGNAL(currentIndexChanged(int)), this, SLOT(STATISTICS__do_plot()));
    connect(STATISTICS__combobox_weight_x, SIGNAL(currentIndexChanged(int)), this, SLOT(STATISTICS__do_plot()));
    connect(STATISTICS__combobox_weight_y, SIGNAL(currentIndexChanged(int)), this, SLOT(STATISTICS__do_plot()));

    //Button
    connect(STATISTICS__button_load, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_load()));
    connect(STATISTICS__button_make_group, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_make_group()));
    connect(STATISTICS__button_remove, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_remove()));
    connect(STATISTICS__button_regression, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_regression()));
    connect(STATISTICS__button_clustering, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_clustering()));
    connect(STATISTICS__button_export, SIGNAL(clicked(bool)), this, SLOT(STATISTICS__do_export()));
}

void MainWindow::STATISTICS__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Plot
    STATISTICS__plot->graph(0)->setPen(QPen(Qt::blue));
    STATISTICS__plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    STATISTICS__plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
}

bool MainWindow::STATISTICS__do_load(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
    bool Res;

    QString Dir = QFileDialog::getExistingDirectory(this, "Select the Results directory", GetResultsDir(&Res));

    QDir CurrentDir = QDir(Dir);
    QStringList FileList = CurrentDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (int i = 0; i < FileList.count(); i++){
        STATISTICS__list_load->addItem(FileList.at(i));
        //TODO load data
        QVector<double> Results;
        Res = LoadICPResults(Dir + "/" + FileList.at(i) + "/ICP", &Results);
        if (Res){
            for (unsigned int j = 0; j < 12; j++){
                STATISTICS__vector_data[j]->append(Results.at(j));
            }
        }
        Res = LoadComplianceResults(Dir + "/" + FileList.at(i) + "/COMPLIANCE", &Results);
        if (Res){
            for (unsigned int j = 0; j < 8; j++){
                STATISTICS__vector_data[j+12]->append(Results.at(j));
            }
        }
    }

    QStringList Items;
    Items.append("ICP basal -- Cardical cycle");
    Items.append("ICP basal -- Heart rate");
    Items.append("ICP basal -- Min");
    Items.append("ICP basal -- Max");
    Items.append("ICP basal -- Mean");
    Items.append("ICP basal -- Amplitude");
    Items.append("ICP plateau -- Cardical cycle");
    Items.append("ICP plateau -- Heart rate");
    Items.append("ICP plateau -- Min");
    Items.append("ICP plateau -- Max");
    Items.append("ICP plateau -- Mean");
    Items.append("ICP plateau -- Amplitude");
    Items.append("COMPLIANCE -- AV spinal / ICP basal");
    Items.append("COMPLIANCE -- AV spinal / ICP plateau");
    Items.append("COMPLIANCE -- AVCSF spinal / ICP basal");
    Items.append("COMPLIANCE -- AVCSF spinal / ICP plateau");
    Items.append("COMPLIANCE -- AV intracranial / ICP basal");
    Items.append("COMPLIANCE -- AV intracranial / ICP plateau");
    Items.append("COMPLIANCE -- AVCSF intracranial / ICP basal");
    Items.append("COMPLIANCE -- AVCSF intracranial / ICP plateau");

    STATISTICS__do_combobox(Items);

    return Res;
}

void MainWindow::STATISTICS__do_combobox(const QStringList Items){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    unsigned int NItems = Items.count();
    for (unsigned int i = 0; i < NItems; i++){
        STATISTICS__combobox_x->addItem(Items.at(i));
        STATISTICS__combobox_y->addItem(Items.at(i));
        STATISTICS__combobox_weight_x->addItem(Items.at(i));
        STATISTICS__combobox_weight_y->addItem(Items.at(i));
    }
}

bool MainWindow::STATISTICS__do_make_group(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;
    STATISTICS__int_group++;

    unsigned int NList = STATISTICS__list_load->count();

    for (unsigned int i = 0; i < NList; i++){
        if (STATISTICS__list_load->item(i)->isSelected()){
            STATISTICS__list_load->item(i)->setText("Group" + QString::number(STATISTICS__int_group) + " - " + STATISTICS__list_load->item(i)->text());
        }
    }

    STATISTICS__list_load->clearSelection();

    Res = true;

    return Res;
}

bool MainWindow::STATISTICS__do_remove(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;

    STATISTICS__list_load->clear();

    //TODO clear data

    Res = true;
    return Res;
}

bool MainWindow::STATISTICS__do_plot(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    STATISTICS__plot->graph(0)->clearData();

    int SelectedItemX = STATISTICS__combobox_x->currentIndex();
    int SelectedItemY = STATISTICS__combobox_y->currentIndex();

    if ((SelectedItemX != -1) && (SelectedItemY != -1)){
        unsigned int NDataX = STATISTICS__vector_data[SelectedItemX]->count();
        unsigned int NDataY = STATISTICS__vector_data[SelectedItemY]->count();

        if ((NDataX == NDataY) && (NDataX != 0)){
            bool Res;

            Res = plot(STATISTICS__plot, 0, STATISTICS__vector_data[SelectedItemX], STATISTICS__vector_data[SelectedItemY]);
            if (!Res){
                //TODO
                return Res;
            }
            else{
                return Res;
            }

            //TODO
        }
        else{
            //TODO
            return false;
        }
    }
    else{
        //TODO
        return false;
    }
}

bool MainWindow::STATISTICS__do_regression(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //TODO

    return true;
}

bool MainWindow::STATISTICS__do_clustering(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //TODO

    return true;
}

bool MainWindow::STATISTICS__do_export(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //TODO

    return true;
}


