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

#ifndef DIALOGEXPORTDATA_H
#define DIALOGEXPORTDATA_H

#include "headers.h"

class DialogExportData : public QDialog
{
    Q_OBJECT
public:
    DialogExportData(QString *DirName, QStringList *DataList, QWidget *parent = 0);

private slots:
    void SaveDirectory();
    void Valid();
    void Cancel();

private:
    //Method
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();

    virtual void closeEvent(QCloseEvent *);

    void CloseAndDelete();

    //VBox
    QVBoxLayout *VBox;

    //HBox
    QHBoxLayout *HBox;

    //Frame
    QFrame *FrameSaveDirectory;
    QFrame *FrameArterial;
    QFrame *FrameVenous;
    QFrame *FrameCSF;
    QFrame *FrameICP;

    //Grid
    QGridLayout *GridSaveDirectory;
    QGridLayout *GridArterial;
    QGridLayout *GridVenous;
    QGridLayout *GridCSF;
    QGridLayout *GridICP;

    //Label
    QLabel *LabelSaveDirectory;
    QLabel *LabelArterial;
    QLabel *LabelVenous;
    QLabel *LabelCSF;
    QLabel *LabelICP;

    //LineEdit
    QLineEdit *LineEditSaveDirectory;

    //PushButton
    QPushButton *PushButtonSaveDirectory;
    QPushButton *PushButtonValid;
    QPushButton *PushButtonCancel;

    //CheckBox
    QCheckBox *CheckBoxArterialSpinal;
    QCheckBox *CheckBoxArterialIntracranial;
    QCheckBox *CheckBoxVenousSpinal;
    QCheckBox *CheckBoxVenousCorrectedSpinal;
    QCheckBox *CheckBoxVenousIntracranial;
    QCheckBox *CheckBoxVenousCorrectedIntracranial;
    QCheckBox *CheckBoxCSFSpinal;
    QCheckBox *CheckBoxCSFCorrectedSpinal;
    QCheckBox *CheckBoxCSFIntracranial;
    QCheckBox *CheckBoxCSFCorrectedIntracranial;
    QCheckBox *CheckBoxICPBasal;
    QCheckBox *CheckBoxICPPlateau;

    //String
    QStringList *LOCAL__DataList;
    QString *LOCAL__DirName;
};

#endif // DIALOGEXPORTDATA_H
