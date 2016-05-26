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

#include "dialogflowlocation.h"

void DialogFLOWLocation::init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Grid
    grid = new QGridLayout;

    //Label
    label_arterial_spinal = new QLabel;
    label_venous_spinal = new QLabel;
    label_csf_spinal = new QLabel;
    label_arterial_intracranial = new QLabel;
    label_venous_intracranial = new QLabel;
    label_csf_intracranial = new QLabel;

    //CheckBox
    buttongroup_checkbox = new QButtonGroup*[uint_nb_names];
    checkbox_arterial_spinal = new QCheckBox*[uint_nb_names];
    checkbox_venous_spinal = new QCheckBox*[uint_nb_names];
    checkbox_csf_spinal = new QCheckBox*[uint_nb_names];
    checkbox_arterial_intracranial = new QCheckBox*[uint_nb_names];
    checkbox_venous_intracranial = new QCheckBox*[uint_nb_names];
    checkbox_csf_intracranial = new QCheckBox*[uint_nb_names];

    for (unsigned int i = 0; i < uint_nb_names; i++){
        buttongroup_checkbox[i] = new QButtonGroup;
        buttongroup_checkbox[i]->setExclusive(false);   //TODO ???
        checkbox_arterial_spinal[i] = new QCheckBox;
        checkbox_venous_spinal[i] = new QCheckBox;
        checkbox_csf_spinal[i] = new QCheckBox;
        checkbox_arterial_intracranial[i] = new QCheckBox;
        checkbox_venous_intracranial[i] = new QCheckBox;
        checkbox_csf_intracranial[i] = new QCheckBox;
        buttongroup_checkbox[i]->addButton(checkbox_arterial_spinal[i]);
        buttongroup_checkbox[i]->addButton(checkbox_venous_spinal[i]);
        buttongroup_checkbox[i]->addButton(checkbox_csf_spinal[i]);
        buttongroup_checkbox[i]->addButton(checkbox_arterial_intracranial[i]);
        buttongroup_checkbox[i]->addButton(checkbox_venous_intracranial[i]);
        buttongroup_checkbox[i]->addButton(checkbox_csf_intracranial[i]);
    }

    //Button
    button_valid = new QPushButton;
    button_cancel = new QPushButton;
}

void DialogFLOWLocation::init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Dialog
    setLayout(grid);

    //Grid
    grid->addWidget(label_arterial_spinal, 0, 0, 1, 1);
    grid->addWidget(label_venous_spinal, 0, 1, 1, 1);
    grid->addWidget(label_csf_spinal, 0, 2, 1, 1);
    grid->addWidget(label_arterial_intracranial, 0, 3, 1, 1);
    grid->addWidget(label_venous_intracranial, 0, 4, 1, 1);
    grid->addWidget(label_csf_intracranial, 0, 5, 1, 1);

    for (unsigned int i = 0; i < uint_nb_names; i++){
        if (!names->at(i).contains("general-informations")){
            grid->addWidget(checkbox_arterial_spinal[i], i+1, 0, 1, 1);
            grid->addWidget(checkbox_venous_spinal[i], i+1, 1, 1, 1);
            grid->addWidget(checkbox_csf_spinal[i], i+1, 2, 1, 1);
            grid->addWidget(checkbox_arterial_intracranial[i], i+1, 3, 1, 1);
            grid->addWidget(checkbox_venous_intracranial[i], i+1, 4, 1, 1);
            grid->addWidget(checkbox_csf_intracranial[i], i+1, 5, 1, 1);
        }
    }

    grid->addWidget(button_valid, uint_nb_names+2, 0, 1, 3);
    grid->addWidget(button_cancel, uint_nb_names+2, 3, 1, 3);

    //Label
    label_arterial_spinal->setText("<b>Arterial Spinal</b>");
    label_venous_spinal->setText("<b>Venous Spinal</b>");
    label_csf_spinal->setText("<b>CSF Spinal</b>");
    label_arterial_intracranial->setText("<b>Arterial Intracranial</b>");
    label_venous_intracranial->setText("<b>Venous Intracranial</b>");
    label_csf_intracranial->setText("<b>CSF Intracranial</b>");

    //CheckBox
    int TMP__delay = 0;
    for (unsigned int i = 0; i < uint_nb_names; i++){
        QString name = names->at(i);
        checkbox_arterial_spinal[i-TMP__delay]->setText(name);
        checkbox_venous_spinal[i-TMP__delay]->setText(name);
        checkbox_csf_spinal[i-TMP__delay]->setText(name);
        checkbox_arterial_intracranial[i-TMP__delay]->setText(name);
        checkbox_venous_intracranial[i-TMP__delay]->setText(name);
        checkbox_csf_intracranial[i-TMP__delay]->setText(name);
    }

    //Button
    button_valid->setText("Valid");
    button_cancel->setText("Cancel");
}

void DialogFLOWLocation::init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    connect(button_valid, SIGNAL(clicked(bool)), this, SLOT(do_valid()));
    connect(button_cancel, SIGNAL(clicked(bool)), this, SLOT(do_cancel()));
}

void DialogFLOWLocation::init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //
}

DialogFLOWLocation::DialogFLOWLocation(QStringList *EXT__names, QStringList **EXT__location, QWidget *parent) : QDialog(parent) {
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    names = EXT__names;
    location = EXT__location;
    uint_nb_names = names->count();

    if (uint_nb_names != 0){
        init_var();
        init_win();
        init_sig();
        init_css();
        do_auto_location();
        accept();
    }
    else{
        reject();
    }
}

void DialogFLOWLocation::do_valid(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    do_location();

    accept();
}

void DialogFLOWLocation::do_cancel(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //CheckBox
    delete[] buttongroup_checkbox;
    delete[] checkbox_arterial_spinal;
    delete[] checkbox_venous_spinal;
    delete[] checkbox_csf_spinal;
    delete[] checkbox_arterial_intracranial;
    delete[] checkbox_venous_intracranial;
    delete[] checkbox_csf_intracranial;

    reject();
}

void DialogFLOWLocation::do_auto_location(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    for (unsigned int i = 0; i < uint_nb_names; i++){
        if (checkbox_arterial_spinal[i]->text().compare("cid_cervi.txt") == 0
                || checkbox_arterial_spinal[i]->text().compare("cig_cervi.txt") == 0
                || checkbox_arterial_spinal[i]->text().compare("verteb-d.txt") == 0
                || checkbox_arterial_spinal[i]->text().compare("verteb-g.txt") == 0
                ){
            checkbox_arterial_spinal[i]->setChecked(true);
        }
        if (checkbox_venous_spinal[i]->text().compare("jugul-d.txt") == 0
                || checkbox_venous_spinal[i]->text().compare("jugul-g.txt") == 0
                ){
            checkbox_venous_spinal[i]->setChecked(true);
        }
        if (checkbox_csf_spinal[i]->text().compare("c2_c3.txt") == 0){
            checkbox_csf_spinal[i]->setChecked(true);
        }
        if (checkbox_arterial_intracranial[i]->text().compare("cid_cereb.txt") == 0
                || checkbox_arterial_intracranial[i]->text().compare("cig_cereb.txt") == 0
                || checkbox_arterial_intracranial[i]->text().compare("tb.txt") == 0
                ){
            checkbox_arterial_intracranial[i]->setChecked(true);
        }
        if (checkbox_venous_intracranial[i]->text().compare("sinus-d.txt") == 0
                || checkbox_venous_intracranial[i]->text().compare("sinus-s.txt") == 0
                ){
            checkbox_venous_intracranial[i]->setChecked(true);
        }
        if (checkbox_csf_intracranial[i]->text().compare("aqueduc.txt") == 0){
            checkbox_csf_intracranial[i]->setChecked(true);
        }
    }
}

void DialogFLOWLocation::do_location(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    for (unsigned int i = 0; i < uint_nb_names; i++){
        if (checkbox_arterial_spinal[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("ArterialSpinal");
        }
        else if (checkbox_venous_spinal[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("VenousSpinal");
        }
        else if (checkbox_csf_spinal[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("CsfSpinal");
        }
        else if (checkbox_arterial_intracranial[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("ArterialIntracranial");
        }
        else if (checkbox_venous_intracranial[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("VenousIntracranial");
        }
        else if (checkbox_csf_intracranial[i]->isChecked()){
            location[0]->append(names->at(i));
            location[1]->append("CsfIntracranial");
        }
        else if (names->at(i).contains("general-informations")){
            location[0]->append(names->at(i));
            location[1]->append("Informations");
        }
        else{
            location[0]->append(names->at(i));
            location[1]->append("Undefine");
        }
    }
}

void DialogFLOWLocation::closeEvent(QCloseEvent *){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //CheckBox
    delete[] buttongroup_checkbox;
    delete[] checkbox_arterial_spinal;
    delete[] checkbox_venous_spinal;
    delete[] checkbox_csf_spinal;
    delete[] checkbox_arterial_intracranial;
    delete[] checkbox_venous_intracranial;
    delete[] checkbox_csf_intracranial;
}


