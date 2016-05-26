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

#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include "headers.h"

class DialogSettings : public QDialog
{
    Q_OBJECT
public:
    DialogSettings(QWidget *parent = 0);

private slots:
    void init_var();
    void init_win();
    void init_sig();
    void init_css();

    void do_load_parameters();

    void do_FLOW_dir();
    void do_PROLIPHYC_dir();
    void do_results_dir();

    void do_valid();
    void do_cancel();

private:
    //Grid
    QGridLayout *grid;

    //Label
    QLabel *label_FLOW_dir;
    QLabel *label_PROLIPHYC_dir;
    QLabel *label_results_dir;
    QLabel *label_npi;

    //LineEdit
    QLineEdit *lineedit_FLOW_dir;
    QLineEdit *lineedit_PROLIPHYC_dir;
    QLineEdit *lineedit_results_dir;

    //Button
    QPushButton *button_FLOW_dir;
    QPushButton *button_PROLIPHYC_dir;
    QPushButton *button_results_dir;
    //...
    QPushButton *button_valid;
    QPushButton *button_cancel;

    //SpinBox
    QSpinBox *spinbox_npi;
};

#endif // DIALOGSETTINGS_H
