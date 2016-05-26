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

void MainWindow::EPI__init_var(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

void MainWindow::EPI__init_win(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

void MainWindow::EPI__init_sig(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

void MainWindow::EPI__init_css(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif
}

bool MainWindow::EPI__load(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    std::cerr << Q_FUNC_INFO << std::endl;

    return true;
}

bool MainWindow::EPI__load(const QString DirName){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    std::cerr << Q_FUNC_INFO << std::endl;
    std::cerr << DirName.toStdString() << std::endl;

    return true;
}

bool MainWindow::EPI__save(){
#if DEBUG
    std::cout << Q_FUNC_INFO << std::endl;
#endif

    std::cerr << Q_FUNC_INFO << std::endl;

    return true;
}


