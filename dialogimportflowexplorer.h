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

#ifndef DIALOGIMPORTFLOWEXPLORER_H
#define DIALOGIMPORTFLOWEXPLORER_H

#include "headers.h"

class DialogImportFloweXplorer : public QDialog
{
    Q_OBJECT
public:
    DialogImportFloweXplorer(QWidget *parent = 0);

private slots:
    bool DoFloweXplorerDir();
    bool DoLoad();
    bool DoImport();

private:
    //Method
    void InitVar();
    void InitWin();
    void InitSig();
    void InitCss();

    bool CreatePatient(QString Directory, QString Patient);

    //Grid
    QGridLayout *Grid;

    //Label
    QLabel *LabelFloweXplorerDir;

    //LineEdit
    QLineEdit *LineEditFloweXplorerDir;

    //List
    QListWidget *ListPatients;

    //PushButton
    QPushButton *PushButtonFloweXplorerDir;
    QPushButton *PushButtonLoad;
    QPushButton *PushButtonImport;

    //String
    QString StringFloweXplorerDir;
};

#endif // DIALOGIMPORTFLOWEXPLORER_H


