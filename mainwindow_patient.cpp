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

void MainWindow::PATIENT__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Label
    PATIENT__label_name = new QLabel;
    PATIENT__label_birth_date = new QLabel;
    PATIENT__label_age = new QLabel;
    PATIENT__label_sexe = new QLabel;
    PATIENT__label_pathology = new QLabel;
    PATIENT__label_MRI = new QLabel;
    PATIENT__label_ICP = new QLabel;
    PATIENT__label_EPI = new QLabel;

    //Text
    PATIENT__lineedit_name = new QLineEdit;
    PATIENT__lineedit_birth_date = new QLineEdit;

    PATIENT__textedit_MRI = new QTextEdit;
    PATIENT__textedit_ICP = new QTextEdit;
    PATIENT__textedit_EPI = new QTextEdit;

    //SpinBox
    PATIENT__spinbox_age = new QSpinBox;

    //ComboBox
    PATIENT__combobox_pathology = new QComboBox;

    //Calendar
    PATIENT__calendar_birth_date = new QCalendarWidget;

    //RadioButton
    PATIENT__radiobutton_group = new QButtonGroup;
    PATIENT__radiobutton_sexe_M = new QRadioButton;
    PATIENT__radiobutton_sexe_F = new QRadioButton;

    //Button
    PATIENT__button_pathology = new QPushButton;
}

void MainWindow::PATIENT__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Label
    PATIENT__label_name->setText("<b>Patient name</b>");
    PATIENT__label_birth_date->setText("<b>Birth date</b>");
    PATIENT__label_age->setText("<b>Age</b>");
    PATIENT__label_sexe->setText("<b>Sexe</b>");
    PATIENT__label_pathology->setText("<b>Pathology</b>");
    PATIENT__label_MRI->setText("<b>MRI informations</b>");
    PATIENT__label_ICP->setText("<b>ICP informations</b>");
    PATIENT__label_EPI->setText("<b>EPI informations</b>");

    //SpinBox
    PATIENT__spinbox_age->setRange(0, 150);

    //ComboBox
    bool Res;
    QStringList pathologies = GetPathologies(&Res);
    if (Res) PATIENT__combobox_pathology->addItems(pathologies);

    //RadioButton
    PATIENT__radiobutton_group->addButton(PATIENT__radiobutton_sexe_M);
    PATIENT__radiobutton_group->addButton(PATIENT__radiobutton_sexe_F);
    PATIENT__radiobutton_sexe_M->setText("Male");
    PATIENT__radiobutton_sexe_F->setText("Female");

    //Button
    PATIENT__button_pathology->setIcon(QIcon("img/add.png"));
    PATIENT__button_pathology->setToolTip("Add pathology");
}

void MainWindow::PATIENT__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Text
    connect(PATIENT__lineedit_birth_date, SIGNAL(textChanged(QString)), this, SLOT(PATIENT__do_lineedit_birth_date(QString)));

    //Calendar
    connect(PATIENT__calendar_birth_date, SIGNAL(clicked(QDate)), this, SLOT(PATIENT__do_calendar_birth_date(QDate)));

    //Button
    connect(PATIENT__button_pathology, SIGNAL(clicked(bool)), this, SLOT(PATIENT__do_add_pathology()));
}

void MainWindow::PATIENT__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

void MainWindow::PATIENT__do_calendar_birth_date(QDate date){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString date_str = date.toString("dd/MM/yyyy");
    PATIENT__lineedit_birth_date->setText(date_str);

    bool res;
    unsigned int current_age = age(QDate().currentDate(), date, &res);
    if (res){
        PATIENT__spinbox_age->setValue(current_age);
    }
}

bool MainWindow::PATIENT__do_lineedit_birth_date(QString date_str){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QDate date = QDate::fromString(date_str, "dd/MM/yyyy");
    if (date.isValid()){
        PATIENT__calendar_birth_date->setSelectedDate(date);
        return true;
    }
    else{
        return false;
    }
}

bool MainWindow::PATIENT__load(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;
    QString DirName = QFileDialog::getExistingDirectory(this, "Select a PATIENT folder", GetResultsDir(&Res));
    if (!Res || DirName.isEmpty()){
        statusbar_show_warning("PATIENT - Load error - ERR1");
        return false;
    }

    QVector<QString> GlobalInformations;
    QVector<QString> MRIIinformations;
    QVector<QString> ICPInformations;
    QVector<QString> EPIInformations;

    Res = LoadPatient(DirName, &GlobalInformations, &MRIIinformations, &ICPInformations, &EPIInformations);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR1");
        return Res;
    }

    PATIENT__lineedit_name->setText(GlobalInformations.at(0));
    PATIENT__lineedit_birth_date->setText(GlobalInformations.at(1));
    PATIENT__spinbox_age->setValue(GlobalInformations.at(2).toInt(&Res));
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR2");
        return Res;
    }
    QString Sexe = GlobalInformations.at(3);
    if (Sexe == "Male"){
        PATIENT__radiobutton_sexe_M->setChecked(true);
    }
    if (Sexe == "Female"){
        PATIENT__radiobutton_sexe_F->setChecked(true);
    }
    PATIENT__combobox_pathology->setCurrentText(GlobalInformations.at(4));

    PATIENT__textedit_MRI->setText(MRIIinformations.at(0));
    PATIENT__textedit_ICP->setText(ICPInformations.at(0));
    PATIENT__textedit_EPI->setText(EPIInformations.at(0));

    Res = MRI__load(DirName);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR3");
    }

    Res = ICP__load(DirName);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR4");
    }

    Res = EPI__load(DirName);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR5");
    }

    Res = COMPLIANCE__load(DirName);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR6");
    }

    Res = TRANSFERTFUNCTION__load(DirName);
    if (!Res){
        statusbar_show_warning("PATIENT - Load error - ERR7");
    }

    statusbar_show_message("PATIENT - Loaded");
    return Res;
}

bool MainWindow::PATIENT__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QVector<QString> GlobalInformations;
    GlobalInformations.append(PATIENT__lineedit_name->text());
    GlobalInformations.append(PATIENT__lineedit_birth_date->text());
    GlobalInformations.append(QString::number(PATIENT__spinbox_age->value()));
    QString Sexe = "";
    if (PATIENT__radiobutton_sexe_M->isChecked()) Sexe = "Male";
    if (PATIENT__radiobutton_sexe_F->isChecked()) Sexe = "Female";
    GlobalInformations.append(Sexe);
    GlobalInformations.append(PATIENT__combobox_pathology->currentText());

    QVector<QString> MRIInformations;
    MRIInformations.append(PATIENT__textedit_MRI->toPlainText());

    QVector<QString> ICPInformations;
    ICPInformations.append(PATIENT__textedit_ICP->toPlainText());

    QVector<QString> EPIInformations;
    EPIInformations.append(PATIENT__textedit_EPI->toPlainText());

    bool Res;
    QString PatientName = PATIENT__lineedit_name->text();
    if (PatientName.isEmpty()){
        QMessageBox::warning(this, "Save error", "Patient name is not defined.<br/>Define it first.");
        return false;
    }

    QString DirName = GetResultsDir(&Res) + "/" + PatientName;
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR1");
        return Res;
    }

    Res = SavePatient(DirName,
                      GlobalInformations,
                      MRIInformations,
                      ICPInformations,
                      EPIInformations
                      );
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR2");
        return Res;
    }

    std::cout << "ok patient" << std::endl;

    Res = MRI__save();
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR3");
        return Res;
    }

    std::cout << "ok mri" << std::endl;

    Res = ICP__save();
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR4");
    }

    Res = EPI__save();
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR5");
    }

    Res = COMPLIANCE__save();
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR6");
    }

    Res = TRANSFERTFUNCTION__save();
    if (!Res){
        statusbar_show_warning("PATIENT - Save error - ERR7");
    }

    statusbar_show_message("PATIENT - Saved");
    return Res;
}

bool MainWindow::PATIENT__do_add_pathology(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    QString pathology = QInputDialog::getText(this, "Add pathology", "Enter a pathology name");
    if (pathology.isEmpty()){
        statusbar_show_warning("PATIENT - Add pathology - ERR1");
        return false;
    }
    else{
        PATIENT__combobox_pathology->addItem(pathology);
        bool Res = AppendPathology(pathology);
        if (!Res){
            statusbar_show_warning("PATIENT - Add pathology - ERR2");
            return Res;
        }

        statusbar_show_message("PATIENT - Pathology added");
        return Res;
    }
}


