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

#ifndef DIALOGFLOWLOCATION_H
#define DIALOGFLOWLOCATION_H

#include "headers.h"

class DialogFLOWLocation : public QDialog
{
    Q_OBJECT
public:
    DialogFLOWLocation(QStringList *names, QStringList **location, QWidget *parent = 0);

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void do_valid();
    void do_cancel();

    void do_auto_location();
    void do_location();

    void closeEvent(QCloseEvent *);

private:
    //Grid
    QGridLayout *grid;

    //Label
    QLabel *label_arterial_spinal;
    QLabel *label_venous_spinal;
    QLabel *label_csf_spinal;
    QLabel *label_arterial_intracranial;
    QLabel *label_venous_intracranial;
    QLabel *label_csf_intracranial;

    //CheckBox
    QButtonGroup **buttongroup_checkbox;
    QCheckBox **checkbox_arterial_spinal;
    QCheckBox **checkbox_venous_spinal;
    QCheckBox **checkbox_csf_spinal;
    QCheckBox **checkbox_arterial_intracranial;
    QCheckBox **checkbox_venous_intracranial;
    QCheckBox **checkbox_csf_intracranial;

    //Button
    QPushButton *button_valid;
    QPushButton *button_cancel;

    //StringList
    QStringList *names;

    QStringList **location;

    //Int
    unsigned int uint_nb_names;
};

#endif // DIALOGFLOWLOCATION_H
