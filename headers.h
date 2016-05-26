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

#ifndef HEADERS_H
#define HEADERS_H

#define DEBUG   1

//C++ Standard
#include <iostream>

//Qt
#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>

//External libraries
#include "qcustomplot.h"

#include <fftw3.h>

//Functions
unsigned int age(QDate current_date, QDate birth_date, bool *res=NULL);
double min(const double a, const double b);
double max (const double a, const double b);
double min(const QVector<double> *v, int *pos=NULL, bool *res=NULL);
double max(const QVector<double> *v, int *pos=NULL, bool *res=NULL);
double mean(const QVector<double> *v, bool *res=NULL);
bool plot(QCustomPlot *plot, const unsigned int n_graph, const QVector<double> *x, const QVector<double> *y, const bool range=true);
bool plot_with_errorbar(QCustomPlot *plot, const unsigned int n_graph, const QVector<double> *x, const QVector<double> *y, const QVector<double> *err, const bool range=true);
void FFT(QVector<double> *fourier, const QVector<double> *signal, bool *res=NULL);
int detect_max(const QVector<double> *v, bool *res=NULL);
void FFTIFFT(QVector<double> *IFFT_x, QVector<double> *IFFT_y, const QVector<double> *signal_x, const QVector<double> *signal_y, const unsigned int min, const unsigned int max, bool *res=NULL);
void detect_peaks(QVector<double> *peak_x, QVector<double> *peak_y, const QVector<double> *signal_x, const QVector<double> *signal_y, const double threshold, bool *res=NULL);
void mean_icp(QVector<double> *mean_x, QVector<double> *mean_y,
              QVector<double> *sd_y,
              const QVector<double> *signal_x, const QVector<double> *signal_y,
              const QVector<double> *peak_x,
              bool *res=NULL);
void move_curve(int n, QVector<double> *y, QVector<double> *yerr=NULL, bool *res=NULL);

void extend(QVector<double> *inout_x, QVector<double> *inout_y, const unsigned int npi, bool *res=NULL);
double stroke_volume(const QVector<double> *x, const QVector<double> *y, bool *res=NULL);
bool detect_systole_check(const QVector<double> *x, const QVector<double> *y, double *threshold);
bool detect_systole(const QVector<double> *x, const QVector<double> *y, const double threshold, QVector<double> *systole_x, QVector<double> *systole_y);
void move_curve(double val, QVector<double> *x, QVector<double> *y, QVector<double> *yerr, int *pos, bool *res);
bool venous_correction(const QVector<double> *A, const QVector<double> *V, QVector<double> *nV, double *correction=NULL);
bool csf_correction(const QVector<double> *C, QVector<double> *nC, double *correction=NULL);
bool arteriovenous_flow(const QVector<double> *Ax, const QVector<double> *Ay, const QVector<double> *Vy, QVector<double> *AVx, QVector<double> *AVy);
bool arteriovenous_volume(const QVector<double> *AVfx, const QVector<double> *AVfy, QVector<double> *AVvx, QVector<double> *AVvy);
bool arteriovenouscsf_flow(const QVector<double> *Ax, const QVector<double> *Ay, const QVector<double> *Vy, const QVector<double> *CSFy, QVector<double> *AVCSFx, QVector<double> *AVCSFy);
bool arteriovenouscsf_volume(const QVector<double> *AVCSFfx, const QVector<double> *AVCSFfy, QVector<double> *AVCSFvx, QVector<double> *AVCSFvy);
bool smooth(QVector<double> *v);
bool transfert_function(QVector<double> *TFx, QVector<double> *TFy, const QVector<double> *Vx, const QVector<double> *Vy, const QVector<double> *Px, const QVector<double> *Py);

//IO
bool AppendPathology(QString Pathology);
QStringList GetPathologies(bool *Res);
bool load_ICMP_csv(QWidget *parent, QVector<double> *x, QVector<double> *y, QString *patient_name=NULL);
QVector<double> **load_FLOW_files(QWidget *parent, QStringList *names, QVector<int> *sizes, QString *patient_name, QStringList *informations, QStringList *images, bool *res);

bool SavePatient(const QString DirName,
                 const QVector<QString> Globalinformations,
                 const QVector<QString> MRIInformations,
                 const QVector<QString> ICPInformations,
                 const QVector<QString> EPIInformations
                 );
bool LoadPatient(const QString DirName,
                 QVector<QString> *Globalinformations,
                 QVector<QString> *MRIInformations,
                 QVector<QString> *ICPInformations,
                 QVector<QString> *EPIInformations
                 );
bool SaveMRI(const QString DirName,
             const QVector<double> SystoleThreshold, const QVector<int> Quality, const QVector<int> Move,
             const QVector<double> *Arterial_x, const QVector<double> *Arterial_y, const QVector<double> ArterialResults,
             const QVector<double> *Venous_x, const QVector<double> *Venous_y, const QVector<double> VenousResults,
             const QVector<double> *CSF_x, const QVector<double> *CSF_y, const QVector<double> CSFResults,
             const QVector<double> *AVFlow_x, const QVector<double> *AVFlow_y, const QVector<double> AVFlowResults,
             const QVector<double> *AVVolume_x, const QVector<double> *AVVolume_y, const QVector<double> AVVolumeResults,
             const QVector<double> *AVCSFFlow_x, const QVector<double> *AVCSFFlow_y, const QVector<double> AVCSFFlowResults,
             const QVector<double> *AVCSFVolume_x, const QVector<double> *AVCSFVolume_y, const QVector<double> AVCSFVolumeResults
             );
bool SaveMRI2(const QString DirName,
              const QVector<QString> *ArteriesImages,
              QVector<double> **Arteries_x, QVector<double> **Arteries_y, const QVector<QString> ArteriesNames,
              const QVector<QString> *VeinsImages,
              QVector<double> **Veins_x, QVector<double> **Veins_y, const QVector<QString> VeinsNames,
              const QVector<QString> *CSFsImages,
              QVector<double> **CSFs_x, QVector<double> **CSFs_y, const QVector<QString> CSFsNames,
              const QVector<QString> *UndefinesImages,
              QVector<double> **Undefines_x, QVector<double> **Undefines_y, const QVector<QString> UndefinesNames
              );
bool LoadMRI(const QString DirName,
             QVector<double> *SystoleThreshold, QVector<int> *Quality, QVector<int> *Move,
             QVector<double> *Arterial_x, QVector<double> *Arterial_y, QVector<double> *ArterialResults,
             QVector<double> *Venous_x, QVector<double> *Venous_y, QVector<double> *VenousResults,
             QVector<double> *CSF_x, QVector<double> *CSF_y, QVector<double> *CSFResults,
             QVector<double> *AVFlow_x, QVector<double> *AVFlow_y, QVector<double> *AVFlowResults,
             QVector<double> *AVVolume_x, QVector<double> *AVVolume_y, QVector<double> *AVVolumeResults,
             QVector<double> *AVCSFFlow_x, QVector<double> *AVCSFFlow_y, QVector<double> *AVCSFFlowResults,
             QVector<double> *AVCSFVolume_x, QVector<double> *AVCSFVolume_y, QVector<double> *AVCSFVolumeResults
             );
bool LoadMRI2_1(const QString DirName, QVector<QString> *ArteriesImages,
              QVector<QString> *ArteriesNames, QVector<QString> *VeinsImages,
              QVector<QString> *VeinsNames, QVector<QString> *CSFsImages,
              QVector<QString> *CSFsNames, QVector<QString> *UndefinesImages,
              QVector<QString> *UndefinesNames
              );
bool LoadMRI2_2(const QString DirName,
              QVector<double> **Arteries_x, QVector<double> **Arteries_y, const QVector<QString> ArteriesNames,
              QVector<double> **Veins_x, QVector<double> **Veins_y, const QVector<QString> VeinsNames,
              QVector<double> **CSFs_x, QVector<double> **CSFs_y, const QVector<QString> CSFsNames,
              QVector<double> **Undefines_x, QVector<double> **Undefines_y, const QVector<QString> UndefinesNames
              );
bool SaveICP(const QString DirName,
             const QVector<double> *Signal_x, const QVector<double> *Signal_y, const QVector<double> Selection, const QVector<int> Quality,
             const QVector<double> *SelectionBasal_x, const QVector<double> *SelectionBasal_y, const QVector<double> *SelectionPlateau_x, const QVector<double> *SelectionPlateau_y, const QVector<double> FFTRange,
             const QVector<double> *FFTSpectrumBasal_x, const QVector<double> *FFTSpectrumBasal_y, const QVector<double> *FFTSpectrumPlateau_x, const QVector<double> *FFTSpectrumPlateau_y, const QVector<double> FFTROI,
             const QVector<double> *IFFTBasal_x, const QVector<double> *IFFTBasal_y, const QVector<double> *IFFTPlateau_x,const  QVector<double> *IFFTPlateau_y, const QVector<double> Threshold, const QVector<double> *PeaksBasal_x, const QVector<double> *PeaksBasal_y, const QVector<double> *PeaksPlateau_x, const QVector<double> *PeaksPlateau_y,
             const QVector<double> *MeanBasal_x, const QVector<double> *MeanBasal_y, const QVector<double> *MeanPlateau_x,const  QVector<double> *MeanPlateau_y, const QVector<int> IsAdjusted, const QVector<double> Results
             );
bool LoadICP(const QString DirName,
             QVector<double> *Signal_x, QVector<double> *Signal_y, QVector<double> *Selection, QVector<int> *Quality,
             QVector<double> *SelectionBasal_x, QVector<double> *SelectionBasal_y, QVector<double> *SelectionPlateau_x, QVector<double> *SelectionPlateau_y, QVector<double> *FFTRange,
             QVector<double> *FFTSpectrumBasal_x, QVector<double> *FFTSpectrumBasal_y, QVector<double> *FFTSpectrumPlateau_x, QVector<double> *FFTSpectrumPlateau_y, QVector<double> *FFTROI,
             QVector<double> *IFFTBasal_x, QVector<double> *IFFTBasal_y, QVector<double> *IFFTPlateau_x, QVector<double> *IFFTPlateau_y, QVector<double> *Threshold, QVector<double> *PeaksBasal_x, QVector<double> *PeaksBasal_y, QVector<double> *PeaksPlateau_x, QVector<double> *PeaksPlateau_y,
             QVector<double> *MeanBasal_x, QVector<double> *MeanBasal_y, QVector<double> *MeanPlateau_x, QVector<double> *MeanPlateau_y, QVector<int> *IsAdjusted, QVector<double> *Results
             );
bool LoadICPResults(const QString DirName, QVector<double> *Results);
bool SaveCompliance(const QString DirName, const QVector<int> Selection, const QVector<double> ComplianceResults);
bool LoadCompliance(const QString DirName, QVector<int> *Selection, QVector<double> *ComplianceResults);
bool LoadComplianceResults(const QString DirName, QVector<double> *Results);
bool SaveTransfertFunction(const QString DirName, const QVector<int> Selection);
bool LoadTransfertFunction(const QString DirName, QVector<int> *Selection);
bool SaveCSV(QString FileName, QVector<double> *X, QVector<double> *Y);

//Settings
QString GetFlowDir(bool *Res);
QString GetProliphycDir(bool *Res);
QString GetResultsDir(bool *Res);
bool SetFlowDir(QString FlowDir);
bool SetProliphycDir(QString ProliphycDir);
bool SetResultsDir(QString ResultsDir);
unsigned int GetNpi(bool *Res);
bool SetNpi(unsigned int Npi);

#endif // HEADERS_H


