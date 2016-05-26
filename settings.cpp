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

#include "headers.h"

QString GetDir(QString FileName, bool *Res){
    QFile File(FileName);
    if (File.open(QIODevice::ReadOnly)){
        QString Dir = File.readLine();
        File.close();
        (*Res) = true;
        return Dir;
    }
    else{
        (*Res) = false;
        return "";
    }
}

bool SetDir(QString FileName, QString Dir){
    QFile File(FileName);
    if (File.open(QIODevice::WriteOnly)){
        File.write(Dir.toStdString().c_str());
        File.close();
        return true;
    }
    else{
        return false;
    }
}

QString GetFlowDir(bool *Res){
    QString FlowDir = GetDir("system/flow_directory.dat", Res);
    if (!(*Res)){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Flow directory not defined" << std::endl;
    }
    return FlowDir;
}

QString GetProliphycDir(bool *Res){
    QString ProliphycDir = GetDir("system/proliphyc_directory.dat", Res);
    if (!(*Res)){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Proliphyc directory not defined" << std::endl;
    }
    return ProliphycDir;
}

QString GetResultsDir(bool *Res){
    QString ResultsDir = GetDir("system/results_directory.dat", Res);
    if (!(*Res)){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Results directory not defined" << std::endl;
    }
    return ResultsDir;
}

bool SetFlowDir(QString FlowDir){
    bool Res = SetDir("system/flow_directory.dat", FlowDir);
    if (!Res){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Flow directory not writted" << std::endl;
    }
    return Res;
}

bool SetProliphycDir(QString ProliphycDir){
    bool Res = SetDir("system/proliphyc_directory.dat", ProliphycDir);
    if (!Res){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Proliphyc directory not writted" << std::endl;
    }
    return Res;
}

bool SetResultsDir(QString ResultsDir){
    bool Res = SetDir("system/results_directory.dat", ResultsDir);
    if (!Res){
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Results directory not writted" << std::endl;
    }
    return Res;
}

unsigned int GetNpi(bool *Res){
    QFile File("system/npi.dat");
    if (File.open(QIODevice::ReadOnly)){
        QString Line = File.readLine();
        File.close();
        int Npi = Line.toInt(Res);
        if (*Res){
            return (unsigned int) Npi;
        }
        else{
            return 0;
        }
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Npi not defined" << std::endl;
        (*Res) = false;
        return 0;
    }
}

bool SetNpi(unsigned int Npi){
    QFile File("system/npi.dat");
    if (File.open(QIODevice::WriteOnly)){
        File.write(QString::number(Npi).toStdString().c_str());
        File.close();
        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Npi not writted" << std::endl;
        return false;
    }
}


