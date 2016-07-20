#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <fftw3.h>

#include <iostream>
using namespace std;

#include <QMainWindow>

//FOR MAC OS
#include <QApplication>
#include <QDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QListWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QRadioButton>
//END FOR MAC OS

#include "TextDef.h"
#include "TextDef__Error.h"


#include "qcustomplot.h"
#include "coord.h"


#define SLIDER_DOUBLE       1000


//****************//
//***PROTOTYPES***//
//***************//


//function.cpp
QVector<double> *Coord2QVector(Coord *in);
double min(double *x, int n);
double max(double *x, int n);
double min(QVector<double> x);
double max(QVector<double> x);
double mean(Coord coord, char type);
double mean(QVector<double> x);
bool fourier(Coord *coord_fourier, Coord coord_selected);
bool fourier_test(Coord *coord_fourier, Coord coord_selected);
bool ifft(Coord *coord_ifft, Coord coord_selected, int min_threshold, int max_threshold);
void detect_peaks(Coord coord, Coord *peaks, double threshold);
void mean_icp(Coord coord, Coord peaks, Coord *mean, Coord *SD);
void adjust(Coord *coord, Coord *SD, string type);
void normalize(Coord *coord, Coord *SD);
double av_conservation(Coord arterial, Coord venous);

void arteriovenous_flow(Coord *arteriovenous, Coord arterial, Coord venous);
void arteriovenous_volume(Coord *arteriovenous, Coord arterial, Coord venous);

void icvc_flow(Coord *icvc, Coord arterial_x, Coord venous, Coord csf);
void icvc_volume(Coord *icvc, Coord arterial_x, Coord venous, Coord csf);

void extend(Coord *out, int npi);
Coord *smooth(Coord signal);
double *test_detect_systole(Coord signal, int delay);
Coord *detect_systole(Coord signal, int delay, double threshold);

double stroke_volume(Coord coord);
double stroke_volume_csf(Coord coord);

Coord *compliance_continuous(Coord volume, Coord pressure, int width);
bool filter(Coord *signal, int threshold);
double linear_regression(QVector<double> x, QVector<double> y, double *a, double *b);
bool remove_processed_file(QString file_name);

bool IsFlowAnalysisPatientDir(QString dir);
int GetFlowAnalysisNumFiles(QString dir);

bool unity_convert_flow(QVector<double> *xy, QString flow_unity, QString time_unity);
void unity_convert_flow_data(double *min, double *max, double *mean, double *sv, QString flow_unity, QString volume_unity);
bool unity_convert_volume(QVector<double> *xy, QString volume_unity, QString time_unity);
void unity_convert_volume_data(double *min, double *max, double *mean, QString volume_unity);


//InOut.cpp
bool load_data_proliphyc(QString file_name, Coord *coord);
bool load_data(QString file_name, Coord *coord);
bool load_sup_data(QString file_name, string *string_list1, string *string_list2, int n);

bool save_data(QString file_name, Coord *coord, Coord *coord_SD=NULL);
bool save_sup_data(QString file_name,
                   string *string_list1, string *string_list2, int n);

bool save_csv(QString file_name, QString title1, QString title2, QVector<string> name, QVector<double> x, QVector<double> y, QVector<double> reg=QVector<double>(), QVector<double> clust=QVector<double>());
bool save_rtf(QString file_name, QStringList patient_informations, QStringList data);


/*PARAMETERS*/
bool get_directories(QStringList *directories);
QString get_Flow_directory();
QString get_Data_directory();
QString get_Results_directory();
bool get_unities(string *unities);
bool get_npi(int *npi);
bool get_coeffs(double *coeffs);

bool set_directories(QStringList *directories);
bool set_unities(string *unities);
bool set_npi(int npi);
bool set_coeffs(double *coeffs);

/*INFORMATIONS*/
QString get_exam_number(QString patient_dir, bool *res=NULL);
QString get_exam_date(QString patient_dir, bool *res=NULL);
QString get_patient_date(QString patient_dir, bool *res=NULL);
QString get_patient_age(QString patient_dir, bool *res=NULL);
QString get_patient_sexe(QString patient_dir, bool *res=NULL);

/*FILE NAMES*/
QString get_MRI_source(QString patient_dir, bool *res=NULL);
QString get_MRI_arterial_cervical_source(QString patient_dir, bool *res=NULL);
QString get_MRI_venous_cervical_source(QString patient_dir, bool *res=NULL);
QString get_MRI_csf_cervical_source(QString patient_dir, bool *res=NULL);
QString get_MRI_arterial_cerebral_source(QString patient_dir, bool *res=NULL);
QString get_MRI_venous_cerebral_source(QString patient_dir, bool *res=NULL);
QString get_MRI_csf_cerebral_source(QString patient_dir, bool *res=NULL);
QString get_ICP_source(QString patient_dir, bool *res=NULL);
QString get_EPI_source(QString patient_dir, bool *res=NULL);
QString get_EPI_arterial_cervical_source(QString patient_dir, bool *res=NULL);
QString get_EPI_venous_cervical_source(QString patient_dir, bool *res=NULL);
QString get_EPI_csf_cervical_source(QString patient_dir, bool *res=NULL);
QString get_EPI_arterial_cerebral_source(QString patient_dir, bool *res=NULL);
QString get_EPI_venous_cerebral_source(QString patient_dir, bool *res=NULL);
QString get_EPI_csf_cerebral_source(QString patient_dir, bool *res=NULL);

void set_MRI_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_arterial_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_venous_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_csf_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_arterial_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_venous_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_csf_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);
void set_ICP_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_arterial_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_venous_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_csf_cervical_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_arterial_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_venous_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_csf_cerebral_source(QString patient_dir, QString txt, bool *res=NULL);


/*QUALITY*/
QString get_MRI_arterial_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_MRI_venous_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_MRI_csf_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_MRI_arterial_cerebral_quality_source(QString patient_dir, bool *res=NULL);
QString get_MRI_venous_cerebral_quality_source(QString patient_dir, bool *res=NULL);
QString get_MRI_csf_cerebral_quality_source(QString patient_dir, bool *res=NULL);

QString get_MRI_arterial_other_quality_source(QString patient_dir, int l, bool *res=NULL);
QString get_MRI_venous_other_quality_source(QString patient_dir, int l, bool *res=NULL);
QString get_MRI_csf_other_quality_source(QString patient_dir, int l, bool *res=NULL);

QString get_ICP_quality_source(QString patient_dir, bool *res=NULL);

QString get_EPI_arterial_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_venous_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_csf_cervical_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_arterial_cerebral_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_venous_cerebral_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_csf_cerebral_quality_source(QString patient_dir, bool *res=NULL);
/*QString get_EPI_arterial_others_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_venous_others_quality_source(QString patient_dir, bool *res=NULL);
QString get_EPI_csf_others_quality_source(QString patient_dir, bool *res=NULL);*/

QString get_EPI_arterial_other_quality_source(QString patient_dir, int l, bool *res=NULL);
QString get_EPI_venous_other_quality_source(QString patient_dir, int l, bool *res=NULL);
QString get_EPI_csf_other_quality_source(QString patient_dir, int l, bool *res=NULL);

void set_MRI_arterial_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_venous_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_csf_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_arterial_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_venous_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_MRI_csf_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);

void set_MRI_arterial_other_quality_source(QString patient_dir, int l, QString txt, bool *res=NULL);
void set_MRI_venous_other_quality_source(QString patient_dir, int l, QString txt, bool *res=NULL);
void set_MRI_csf_other_quality_source(QString patient_dir, int l, QString txt, bool *res=NULL);

void set_ICP_quality_source(QString patient_dir, QString txt, bool *res=NULL);

void set_EPI_arterial_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_venous_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_csf_cervical_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_arterial_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_venous_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_csf_cerebral_quality_source(QString patient_dir, QString txt, bool *res=NULL);
/*void set_EPI_arterial_others_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_venous_others_quality_source(QString patient_dir, QString txt, bool *res=NULL);
void set_EPI_csf_others_quality_source(QString patient_dir, QString txt, bool *res=NULL);*/






QStringList *get_MRI_arterial_files(QString patient_dir);
QStringList *get_MRI_venous_files(QString patient_dir);
QStringList *get_MRI_csf_files(QString patient_dir);

QStringList *get_EPI_arterial_files(QString patient_dir);
QStringList *get_EPI_venous_files(QString patient_dir);
QStringList *get_EPI_csf_files(QString patient_dir);







int *clustering(int PTS, double *a, double *b, int K);

//************//
//************//


#endif // HEADERS_HPP


