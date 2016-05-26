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

#include "dialogsettings.h"

void DialogSettings::init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Grid
    grid = new QGridLayout(this);

    //Label
    label_FLOW_dir = new QLabel(this);
    label_PROLIPHYC_dir = new QLabel(this);
    label_results_dir = new QLabel(this);
    label_npi = new QLabel(this);

    //LineEdit
    lineedit_FLOW_dir = new QLineEdit(this);
    lineedit_PROLIPHYC_dir = new QLineEdit(this);
    lineedit_results_dir = new QLineEdit(this);

    //Button
    button_FLOW_dir = new QPushButton(this);
    button_PROLIPHYC_dir = new QPushButton(this);
    button_results_dir = new QPushButton(this);
    //...
    button_valid = new QPushButton(this);
    button_cancel = new QPushButton(this);

    //SpinBox
    spinbox_npi = new QSpinBox(this);
}

void DialogSettings::init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Dialog
    setModal(true);
    setLayout(grid);

    //Grid
    grid->addWidget(label_FLOW_dir, 0, 0, 1, 1);
    grid->addWidget(lineedit_FLOW_dir, 0, 1, 1, 1);
    grid->addWidget(button_FLOW_dir, 0, 2, 1, 1);

    grid->addWidget(label_PROLIPHYC_dir, 1, 0, 1, 1);
    grid->addWidget(lineedit_PROLIPHYC_dir, 1, 1, 1, 1);
    grid->addWidget(button_PROLIPHYC_dir, 1, 2, 1, 1);

    grid->addWidget(label_results_dir, 2, 0, 1, 1);
    grid->addWidget(lineedit_results_dir, 2, 1, 1, 1);
    grid->addWidget(button_results_dir, 2, 2, 1, 1);

    grid->addWidget(label_npi, 3, 0, 1, 2);
    grid->addWidget(spinbox_npi, 3, 2, 1, 2);

    //...

    grid->addWidget(button_valid, 100, 0, 1, 2);
    grid->addWidget(button_cancel, 100, 2, 1, 1);

    //Label
    label_FLOW_dir->setText("FLOW directory");
    label_PROLIPHYC_dir->setText("PROLIPHYC directory");
    label_results_dir->setText("Results directory");
    label_npi->setText("Number of interpolation points");

    //LineEdit
    lineedit_FLOW_dir->setToolTip("FLOW directory");
    lineedit_PROLIPHYC_dir->setToolTip("PROLIPHYC directory");
    lineedit_results_dir->setToolTip("Results directory");

    //Button
    button_FLOW_dir->setIcon(QIcon("img/dir.png"));
    button_FLOW_dir->setToolTip("Select directory");
    button_PROLIPHYC_dir->setIcon(QIcon("img/dir.png"));
    button_PROLIPHYC_dir->setToolTip("Select directory");
    button_results_dir->setIcon(QIcon("img/dir.png"));
    button_results_dir->setToolTip("Select directory");
    //...
    button_valid->setText("Apply");
    button_cancel->setText("Cancel");

    //SpinBox
    spinbox_npi->setRange(32, 1e6);
    spinbox_npi->setValue(100);
}

void DialogSettings::init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

void DialogSettings::init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Button
    connect(button_FLOW_dir, SIGNAL(clicked(bool)), this, SLOT(do_FLOW_dir()));
    connect(button_PROLIPHYC_dir, SIGNAL(clicked(bool)), this, SLOT(do_PROLIPHYC_dir()));
    connect(button_results_dir, SIGNAL(clicked(bool)), this, SLOT(do_results_dir()));
    connect(button_valid, SIGNAL(clicked(bool)), this, SLOT(do_valid()));
    connect(button_cancel, SIGNAL(clicked(bool)), this, SLOT(do_cancel()));
}

DialogSettings::DialogSettings(QWidget *parent) : QDialog(parent)
{
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    init_var();
    init_win();
    init_sig();
    init_css();

    do_load_parameters();
}

void DialogSettings::do_load_parameters(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res;
    QString TMP__FLOW_dir = GetFlowDir(&res);
    if (res){
        lineedit_FLOW_dir->setText(TMP__FLOW_dir);
    }
    else{
        lineedit_FLOW_dir->setText("");
    }

    QString TMP__PROLIPHYC_dir = GetProliphycDir(&res);
    if (res){
        lineedit_PROLIPHYC_dir->setText(TMP__PROLIPHYC_dir);
    }
    else{
        lineedit_PROLIPHYC_dir->setText("");
    }

    QString TMP__results_dir = GetResultsDir(&res);
    if (res){
        lineedit_results_dir->setText(TMP__results_dir);
    }
    else{
        QDir results_dir = QDir("./");
        res = results_dir.mkdir("results");
        lineedit_results_dir->setText(results_dir.absolutePath() + "/results");
        SetResultsDir(results_dir.absolutePath() + "/results");
    }

    unsigned int npi = GetNpi(&res);
    if (res){
        spinbox_npi->setValue(npi);
    }
    else{
        spinbox_npi->setValue(100); //DEFAULT VALUE
    }
}

void DialogSettings::do_FLOW_dir(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString TMP__FLOW_dir = QFileDialog::getExistingDirectory(this, "Select the FLOW directory");
    if (!TMP__FLOW_dir.isEmpty()){
        lineedit_FLOW_dir->setText(TMP__FLOW_dir);
    }
}

void DialogSettings::do_PROLIPHYC_dir(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString TMP__PROLIPHYC_dir = QFileDialog::getExistingDirectory(this, "Select the PROLIPHYC directory");
    if (!TMP__PROLIPHYC_dir.isEmpty()){
        lineedit_PROLIPHYC_dir->setText(TMP__PROLIPHYC_dir);
    }
}

void DialogSettings::do_results_dir(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString TMP__results_dir = QFileDialog::getExistingDirectory(this, "Select the results directory");
    if (!TMP__results_dir.isEmpty()){
        lineedit_results_dir->setText(TMP__results_dir);
    }
}

void DialogSettings::do_valid(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool res = SetFlowDir(lineedit_FLOW_dir->text());
    res = SetProliphycDir(lineedit_PROLIPHYC_dir->text());
    res = SetResultsDir(lineedit_results_dir->text());
    if (!res){
        return;
    }

    res = SetNpi(spinbox_npi->value());
    if (!res){
        return;
    }

    accept();
}

void DialogSettings::do_cancel(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    reject();
}


