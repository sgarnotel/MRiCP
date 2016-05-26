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

#include "dialogexportdata.h"

void DialogExportData::InitVar(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //VBox
    VBox = new QVBoxLayout(this);

    //HBox
    HBox = new QHBoxLayout(VBox->widget());

    //Frame
    FrameSaveDirectory = new QFrame(this);
    FrameArterial = new QFrame(this);
    FrameVenous = new QFrame(this);
    FrameCSF = new QFrame(this);
    FrameICP = new QFrame(this);

    //Grid
    GridSaveDirectory = new QGridLayout(FrameSaveDirectory);
    GridArterial = new QGridLayout(FrameArterial);
    GridVenous = new QGridLayout(FrameVenous);
    GridCSF = new QGridLayout(FrameCSF);
    GridICP = new QGridLayout(FrameICP);

    //Label
    LabelSaveDirectory = new QLabel(GridSaveDirectory->widget());
    LabelArterial = new QLabel(GridArterial->widget());
    LabelVenous = new QLabel(GridVenous->widget());
    LabelCSF = new QLabel(GridCSF->widget());
    LabelICP = new QLabel(GridICP->widget());

    //LineEdit
    LineEditSaveDirectory = new QLineEdit(GridSaveDirectory->widget());

    //PushButton
    PushButtonSaveDirectory = new QPushButton(GridSaveDirectory->widget());
    PushButtonValid = new QPushButton(HBox->widget());
    PushButtonCancel = new QPushButton(HBox->widget());

    //CheckBox
    CheckBoxArterialSpinal = new QCheckBox(GridArterial->widget());
    CheckBoxArterialIntracranial = new QCheckBox(GridArterial->widget());
    CheckBoxVenousSpinal = new QCheckBox(GridVenous->widget());
    CheckBoxVenousCorrectedSpinal = new QCheckBox(GridVenous->widget());
    CheckBoxVenousIntracranial = new QCheckBox(GridVenous->widget());
    CheckBoxVenousCorrectedIntracranial = new QCheckBox(GridVenous->widget());
    CheckBoxCSFSpinal = new QCheckBox(GridCSF->widget());
    CheckBoxCSFCorrectedSpinal = new QCheckBox(GridCSF->widget());
    CheckBoxCSFIntracranial = new QCheckBox(GridCSF->widget());
    CheckBoxCSFCorrectedIntracranial = new QCheckBox(GridCSF->widget());
    CheckBoxICPBasal = new QCheckBox(GridICP->widget());
    CheckBoxICPPlateau = new QCheckBox(GridICP->widget());
}

void DialogExportData::InitWin(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Dialog
    setLayout(VBox);

    //VBox
    VBox->addWidget(FrameSaveDirectory);
    VBox->addWidget(FrameArterial);
    VBox->addWidget(FrameVenous);
    VBox->addWidget(FrameCSF);
    VBox->addWidget(FrameICP);
    VBox->addLayout(HBox);

    //HBox
    HBox->addWidget(PushButtonValid);
    HBox->addWidget(PushButtonCancel);

    //Frame
    FrameSaveDirectory->setLayout(GridSaveDirectory);
    FrameArterial->setLayout(GridArterial);
    FrameVenous->setLayout(GridVenous);
    FrameCSF->setLayout(GridCSF);
    FrameICP->setLayout(GridICP);

    //Grid
    GridSaveDirectory->addWidget(LabelSaveDirectory, 0, 0, 1, 1);
    GridSaveDirectory->addWidget(LineEditSaveDirectory, 0, 1, 1, 1);
    GridSaveDirectory->addWidget(PushButtonSaveDirectory, 0, 2, 1, 1);

    GridArterial->addWidget(LabelArterial, 0, 0, 1, 2);
    GridArterial->addWidget(CheckBoxArterialSpinal, 1, 0, 1, 1);
    GridArterial->addWidget(CheckBoxArterialIntracranial, 1, 1, 1, 1);

    GridVenous->addWidget(LabelVenous, 0, 0, 1, 2);
    GridVenous->addWidget(CheckBoxVenousSpinal, 1, 0, 1, 1);
    GridVenous->addWidget(CheckBoxVenousIntracranial, 1, 1, 1, 1);
    GridVenous->addWidget(CheckBoxVenousCorrectedSpinal, 2, 0, 1, 1);
    GridVenous->addWidget(CheckBoxVenousCorrectedIntracranial, 2, 1, 1, 1);

    GridCSF->addWidget(LabelCSF, 0, 0, 1, 2);
    GridCSF->addWidget(CheckBoxCSFSpinal, 1, 0, 1, 1);
    GridCSF->addWidget(CheckBoxCSFIntracranial, 1, 1, 1, 1);
    GridCSF->addWidget(CheckBoxCSFCorrectedSpinal, 2, 0, 1, 1);
    GridCSF->addWidget(CheckBoxCSFCorrectedIntracranial, 2, 1, 1, 1);

    GridICP->addWidget(LabelICP, 0, 0, 1, 2);
    GridICP->addWidget(CheckBoxICPBasal, 1, 0, 1, 1);
    GridICP->addWidget(CheckBoxICPPlateau, 1, 1, 1, 1);

    //Label
    LabelSaveDirectory->setText("Save directory");
    LabelArterial->setText("<b>Arterial</b>");
    LabelVenous->setText("<b>Venous</b>");
    LabelCSF->setText("<b>CSF</b>");
    LabelICP->setText("<b>ICP</b>");

    //LineEdit
    //nothing to do

    //PushButton
    PushButtonSaveDirectory->setIcon(QIcon("img/dir.png"));
    PushButtonSaveDirectory->setToolTip("Select directory");
    PushButtonValid->setText("Valid");
    PushButtonCancel->setText("Cancel");

    //CheckBox
    CheckBoxArterialSpinal->setText("Arterial spinal");
    CheckBoxArterialIntracranial->setText("Arterial intracranial");
    CheckBoxVenousSpinal->setText("Venous spinal");
    CheckBoxVenousCorrectedSpinal->setText("Venous corrected spinal");
    CheckBoxVenousIntracranial->setText("Venous intracranial");
    CheckBoxVenousCorrectedIntracranial->setText("Venous corrected intracranial");
    CheckBoxCSFSpinal->setText("CSF spinal");
    CheckBoxCSFCorrectedSpinal->setText("CSF corrected spinal");
    CheckBoxCSFIntracranial->setText("CSF intracranial");
    CheckBoxCSFCorrectedIntracranial->setText("CSF corrected intracranial");
    CheckBoxICPBasal->setText("ICP basal");
    CheckBoxICPPlateau->setText("ICP plateau");
}

void DialogExportData::InitSig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //PushButton
    connect(PushButtonSaveDirectory, SIGNAL(clicked(bool)), this, SLOT(SaveDirectory()));
    connect(PushButtonValid, SIGNAL(clicked(bool)), this, SLOT(Valid()));
    connect(PushButtonCancel, SIGNAL(clicked(bool)), this, SLOT(Cancel()));
}

void DialogExportData::InitCss(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //Dialog
    this->setWindowTitle("Export data");

    //Frame
    FrameSaveDirectory->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FrameSaveDirectory->setLineWidth(1);
    FrameSaveDirectory->setMidLineWidth(0);
    FrameArterial->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FrameArterial->setLineWidth(1);
    FrameArterial->setMidLineWidth(0);
    FrameVenous->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FrameVenous->setLineWidth(1);
    FrameVenous->setMidLineWidth(0);
    FrameCSF->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FrameCSF->setLineWidth(1);
    FrameCSF->setMidLineWidth(0);
    FrameICP->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    FrameICP->setLineWidth(1);
    FrameICP->setMidLineWidth(0);
}

DialogExportData::DialogExportData(QString *DirName, QStringList *DataList, QWidget *parent) : QDialog(parent)
{
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    LOCAL__DirName = DirName;
    LOCAL__DataList = DataList;

    InitVar();
    InitWin();
    InitSig();
    InitCss();
}

void DialogExportData::SaveDirectory(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    bool Res;
    QString SaveDirectory = QFileDialog::getExistingDirectory(this, "Select save directory", GetResultsDir(&Res));
    LineEditSaveDirectory->setText(SaveDirectory);
}

void DialogExportData::Valid(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    if (LineEditSaveDirectory->text().isEmpty()){
        QMessageBox::warning(this, "Error", "Save directory is not defined");
        return;
    }

    LOCAL__DirName->clear();
    LOCAL__DirName->append(LineEditSaveDirectory->text());

    LOCAL__DataList->clear();
    if (CheckBoxArterialSpinal->isChecked()){
        LOCAL__DataList->append(CheckBoxArterialSpinal->text());
    }
    if (CheckBoxArterialIntracranial->isChecked()){
        LOCAL__DataList->append(CheckBoxArterialIntracranial->text());
    }
    if (CheckBoxVenousSpinal->isChecked()){
        LOCAL__DataList->append(CheckBoxVenousSpinal->text());
    }
    if (CheckBoxVenousCorrectedSpinal->isChecked()){
        LOCAL__DataList->append(CheckBoxVenousCorrectedSpinal->text());
    }
    if (CheckBoxVenousIntracranial->isChecked()){
        LOCAL__DataList->append(CheckBoxVenousIntracranial->text());
    }
    if (CheckBoxVenousCorrectedIntracranial->isChecked()){
        LOCAL__DataList->append(CheckBoxVenousCorrectedIntracranial->text());
    }
    if (CheckBoxCSFSpinal->isChecked()){
        LOCAL__DataList->append(CheckBoxCSFSpinal->text());
    }
    if (CheckBoxCSFCorrectedSpinal->isChecked()){
        LOCAL__DataList->append(CheckBoxCSFCorrectedSpinal->text());
    }
    if (CheckBoxCSFIntracranial->isChecked()){
        LOCAL__DataList->append(CheckBoxCSFIntracranial->text());
    }
    if (CheckBoxCSFCorrectedIntracranial->isChecked()){
        LOCAL__DataList->append(CheckBoxCSFCorrectedIntracranial->text());
    }
    if (CheckBoxICPBasal->isChecked()){
        LOCAL__DataList->append(CheckBoxICPBasal->text());
    }
    if (CheckBoxICPPlateau->isChecked()){
        LOCAL__DataList->append(CheckBoxICPPlateau->text());
    }

    CloseAndDelete();
    accept();
}

void DialogExportData::Cancel(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    CloseAndDelete();
    reject();
}

void DialogExportData::closeEvent(QCloseEvent *){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    CloseAndDelete();
}

void DialogExportData::CloseAndDelete(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    //CheckBox
    CheckBoxArterialSpinal->deleteLater();
    CheckBoxArterialIntracranial->deleteLater();
    CheckBoxVenousSpinal->deleteLater();
    CheckBoxVenousCorrectedSpinal->deleteLater();
    CheckBoxVenousIntracranial->deleteLater();
    CheckBoxVenousCorrectedIntracranial->deleteLater();
    CheckBoxCSFSpinal->deleteLater();
    CheckBoxCSFCorrectedSpinal->deleteLater();
    CheckBoxCSFIntracranial->deleteLater();
    CheckBoxCSFCorrectedIntracranial->deleteLater();
    CheckBoxICPBasal->deleteLater();
    CheckBoxICPPlateau->deleteLater();

    //PushButton
    PushButtonSaveDirectory->deleteLater();
    PushButtonValid->deleteLater();
    PushButtonCancel->deleteLater();

    //LineEdit
    LineEditSaveDirectory->deleteLater();

    //Label
    LabelSaveDirectory->deleteLater();
    LabelArterial->deleteLater();
    LabelVenous->deleteLater();
    LabelCSF->deleteLater();
    LabelICP->deleteLater();

    //Grid
    GridSaveDirectory->deleteLater();
    GridArterial->deleteLater();
    GridVenous->deleteLater();
    GridCSF->deleteLater();
    GridICP->deleteLater();

    //Frame
    FrameSaveDirectory->deleteLater();
    FrameArterial->deleteLater();
    FrameVenous->deleteLater();
    FrameCSF->deleteLater();
    FrameICP->deleteLater();

    //HBox
    HBox->deleteLater();

    //VBox
    VBox->deleteLater();
}


