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

unsigned int age(QDate current_date, QDate birth_date, bool *res){
    if (current_date.isValid() && birth_date.isValid()){
        unsigned int age = 0;

        int current_year = current_date.year();
        int current_month = current_date.month();
        int current_day = current_date.day();

        int BD_year = birth_date.year();
        int BD_month = birth_date.month();
        int BD_day = birth_date.day();

        if (current_year < BD_year){
            if (res != NULL) (*res) = false;
            return 0;
        }
        if (current_year == BD_year){
            if (current_month < BD_month){
                if (res != NULL) (*res) = false;
                return 0;
            }
            else if (current_month == BD_month){
                if (current_day < BD_day){
                    if (res != NULL) (*res) = false;
                    return 0;
                }
                else{
                    age = 0;
                }
            }
            else{
                age = 0;
            }
        }
        if (current_year > BD_year){
            if (current_month < BD_month){
                age = current_year - BD_year - 1;
            }
            else if (current_month == BD_month){
                if (current_day < BD_day){
                    age = current_year - BD_year - 1;
                }
                else if (current_day == BD_day){
                    age = current_year - BD_year;
                }
                else{
                    age = current_year - BD_year;
                }
            }
            else{
                age = current_year - BD_year;
            }
        }

        return age;
    }
    else{
        if (res != NULL) (*res) = false;
        return 0;
    }
}

double min(const double a, const double b){
    if (a > b){
        return b;
    }
    else{
        return a;
    }
}

double max (const double a, const double b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

double min(const QVector<double> *v, int *pos, bool *res){
    unsigned int n = v->count();
    if (n != 0){
        double min = v->at(0);
        if (pos != NULL) (*pos) = 0;
        for (unsigned int i =1; i < n; i++){
            if (min > v->at(i)){
                min = v->at(i);
                if (pos != NULL) (*pos) = i;
            }
        }
        if (res != NULL) (*res) = true;
        return min;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null size" << std::endl;
        if (pos != NULL) (*pos) = -1;
        if (res != NULL) (*res) = false;
        return 0.;
    }
}

double max(const QVector<double> *v, int *pos, bool *res){
    unsigned int n = v->count();
    if (n != 0){
        double max = v->at(0);
        if (pos != NULL) (*pos) = 0;
        for (unsigned int i =1; i < n; i++){
            if (max < v->at(i)){
                max = v->at(i);
                if (pos != NULL) (*pos) = i;
            }
        }
        if (res != NULL) (*res) = true;
        return max;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null size" << std::endl;
        if (pos != NULL) (*pos) = -1;
        if (res != NULL) (*res) = false;
        return 0.;
    }
}

double mean(const QVector<double> *v, bool *res){
    unsigned int n = v->count();
    if (n != 0){
        double mean = v->at(0);
        for (unsigned int i = 1; i < n; i++){
            mean += v->at(i);
        }
        mean = mean / (double)n;
        if (res != NULL) (*res) = true;
        return mean;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null size" << std::endl;
        if (res != NULL) (*res) = false;
        return -1;
    }
}

bool plot(QCustomPlot *plot, const unsigned int n_graph, const QVector<double> *x, const QVector<double> *y, const bool range){
    bool res = true;
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx != ny) || (nx == 0) || (ny == 0)){
        plot->graph(n_graph)->clearData();
        res = false;
    }
    else{
        plot->graph(n_graph)->setData(*x, *y);
        if (range){
            plot->xAxis->setRange(min(x), max(x));
            plot->yAxis->setRange(min(y), max(y));
        }
    }

    plot->replot();

    return res;
}

bool plot_with_errorbar(QCustomPlot *plot, const unsigned int n_graph, const QVector<double> *x, const QVector<double> *y, const QVector<double> *err, const bool range){
    bool res = true;
    unsigned int nx = x->count();
    unsigned int ny = y->count();
    unsigned int nerr = err->count();

    if ((nx != ny) || (nx == 0) || (ny == 0)){
        plot->graph(n_graph)->clearData();
        res = false;
    }
    else{
        if (nerr != 0){
            plot->graph(n_graph)->setDataValueError(*x, *y, *err);
            if (range){
                plot->xAxis->setRange(min(x), max(x));

                QVector<double> rangemin, rangemax;
                for (unsigned int i = 0; i < ny; i++){
                    rangemin.append(y->at(i) - err->at(i));
                    rangemax.append(y->at(i) + err->at(i));
                }
                plot->yAxis->setRange(min(min(&rangemin), min(&rangemax)), max(max(&rangemin), max(&rangemax)));
            }
        }
        else{
            plot->graph(n_graph)->setData(*x, *y);
            if (range){
                plot->xAxis->setRange(min(x), max(x));
                plot->yAxis->setRange(min(y), max(y));
            }
        }
    }

    plot->replot();

    return res;
}

void FFT(QVector<double> *FFT, const QVector<double> *signal, bool *res){
    unsigned int n = signal->count();

    if (n != 0){
        unsigned int nf = n/2 + 1;

        double *in;
        fftw_complex *out;
        fftw_plan p;

        in = (double*)malloc(n*sizeof(double));
        for (unsigned int i = 0; i < n; i++) in[i] = signal->at(i);

        out = (fftw_complex*)fftw_malloc(nf*sizeof(fftw_complex));
        p = fftw_plan_dft_r2c_1d(n, in, out, FFTW_ESTIMATE);
        fftw_execute(p);

        //Fourier spectrum
        for (unsigned int i = 0; i < nf; i++){
            double y_val = qSqrt(((out[i])[0])*((out[i])[0]) + ((out[i])[1])*((out[i])[1]));
            FFT->append(y_val);
        }

        //Delete
        fftw_destroy_plan(p);
        free(in);
        fftw_free(out);

        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

int detect_max(const QVector<double> *v, bool *res){
    unsigned int n = v->count();
    if (n != 0){
        int pos = 0;
        double max = v->at(pos);
        for (unsigned int i = 0; i < n; i++){
            if (max < v->at(i)){
                max = v->at(i);
                pos = (int)i;
            }
        }
        if (res != NULL) (*res) = true;
        return pos;
    }
    else{
        if (res != NULL) (*res) = false;
        return -1;
    }
}

void FFTIFFT(QVector<double> *IFFT_x, QVector<double> *IFFT_y, const QVector<double> *signal_x, const QVector<double> *signal_y, const unsigned int min, const unsigned int max, bool *res){
    unsigned int n = signal_y->count();

    if (n != 0){
        unsigned int nf = n/2+1;

        //FFT
        double *fft_in;
        fftw_complex *fft_out;
        fftw_plan fft_p;

        fft_in = (double*)malloc(n*sizeof(double));
        for (unsigned int i = 0; i < n; i++){
            fft_in[i] = signal_y->at(i);
        }
        fft_out = (fftw_complex*) fftw_malloc(nf*sizeof(fftw_complex));

        fft_p = fftw_plan_dft_r2c_1d(n, fft_in, fft_out, FFTW_ESTIMATE);
        fftw_execute(fft_p);

        //Harmonics select
        fftw_complex *ifft_in;
        double *ifft_out;
        fftw_plan ifft_p;

        ifft_in = (fftw_complex*) fftw_malloc(nf*sizeof(fftw_complex));
        for (unsigned int i = 0; i < nf; i++){
            if (i > min && i < max){
                (ifft_in[i])[0] = (fft_out[i])[0];
                (ifft_in[i])[1] = (fft_out[i])[1];
            }
            else{
                (ifft_in[i])[0] = 0.;
                (ifft_in[i])[1] = 0.;
            }
        }
        ifft_out = (double*)malloc(n*sizeof(double));

        //IFFT
        ifft_p = fftw_plan_dft_c2r_1d(n, ifft_in, ifft_out, FFTW_ESTIMATE);
        fftw_execute(ifft_p);

        for (unsigned int i = 0; i < n; i++){
            IFFT_x->append(signal_x->at(i));
            IFFT_y->append(ifft_out[i]/n);
        }

        //Delete
        fftw_destroy_plan(fft_p);
        fftw_destroy_plan(ifft_p);
        free(fft_in);
        free(ifft_out);
        fftw_free(fft_out);
        fftw_free(ifft_in);

        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

void detect_peaks(QVector<double> *peak_x, QVector<double> *peak_y, const QVector<double> *signal_x, const QVector<double> *signal_y, const double threshold, bool *res){
    unsigned int n = signal_x->count();
    if (n != 0){
        for (unsigned int i = 0; i < n; i++){
            if (signal_y->at(i) > threshold){
                while(signal_y->at(i) > threshold && i < n-1){
                    if (i != 0){
                        if (signal_y->at(i-1) < signal_y->at(i) && signal_y->at(i) > signal_y->at(i+1)){
                            peak_x->append(signal_x->at(i));
                            peak_y->append(signal_y->at(i));
                        }
                    }
                    i++;
                }
            }
        }
        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

unsigned int positive_modulo(const int a, const unsigned int b){
    int TMP__mod = a;
    while (TMP__mod < 0){
        TMP__mod += b;
    }
    unsigned int mod = TMP__mod;
    while (mod >= b){
        mod -= b;
    }
    return mod;
}

void extend(QVector<double> *out_x, QVector<double> *out_y, const QVector<double> *in_x, const QVector<double> *in_y, const unsigned int npi, bool *res){
    out_x->clear();
    out_y->clear();
    unsigned int nx = in_x->count();
    unsigned int ny = in_y->count();
    if ((nx == ny) && (nx != 0)){
        double xmin = min(in_x);
        double xmax = max(in_x);
        for (unsigned int i = 0; i < npi; i++){
            //x
            out_x->append(xmin + ((double)i/(double)(npi-1))*(xmax-xmin));
            //y
            unsigned int pos = 0;
            while (out_x->at(i) > in_x->at(pos)){
                pos++;
            }
            out_y->append(
                        in_y->at(positive_modulo(pos-1, nx))
                        + ((in_y->at(positive_modulo(pos, nx)) - in_y->at(positive_modulo(pos-1, nx)))
                        * ( out_x->at(i) - in_x->at(positive_modulo(pos-1, nx))))
                        / (in_x->at(positive_modulo(pos, nx)) - in_x->at(positive_modulo(pos-1, nx))));
        }
        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

void extend(QVector<double> *inout_x, QVector<double> *inout_y, const unsigned int npi, bool *res){
    unsigned int nx = inout_x->count();
    unsigned int ny = inout_y->count();

    if ((nx == ny) && (nx != 0)){
        QVector<double> *in_x = new QVector<double>;
        QVector<double> *in_y = new QVector<double>;

        for (unsigned int i = 0; i < nx; i++){
            in_x->append(inout_x->at(i));
            in_y->append(inout_y->at(i));
        }

        extend(inout_x, inout_y, in_x, in_y, npi, res);

        delete in_x;
        delete in_y;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

void mean_icp(QVector<double> *mean_x, QVector<double> *mean_y,
              QVector<double> *sd_y,
              const QVector<double> *signal_x, const QVector<double> *signal_y,
              const QVector<double> *peak_x,
              bool *res){
    unsigned int n = signal_x->count();
    unsigned int np = peak_x->count();

    if ((n != 0) && (np > 1)){
        //peaks positions
        unsigned int *pos = new unsigned int[np];
        unsigned int k = 0;
        for (unsigned int i = 0; i < n; i++){
            if (signal_x->at(i) == peak_x->at(k)){
                pos[k] = i;
                k++;
                if (k == np) break;
            }
        }

        //time between two peaks
        double *times = new double[np-1];
        for (unsigned int i = 0; i < np-1; i++){
            times[i] = peak_x->at(i+1) - peak_x->at(i);
        }

        //mean time
        double mean_time = times[0];
        for (unsigned int i = 1; i < np-1; i++){
            mean_time += times[i];
        }
        mean_time = mean_time / (double)((np-1));

        //mean_x
        unsigned int nm = GetNpi(res);
        for (unsigned int i = 0; i < nm; i++){
            mean_x->append(mean_time * ((double)i/(double)(nm-1)));
        }

        //separate cycles
        QVector<double> *cycles_x_tmp = new QVector<double>[np-1];
        QVector<double> *cycles_y_tmp = new QVector<double>[np-1];
        for (unsigned int i = 0; i < np-1; i++){
            unsigned int nbp = pos[i+1]-pos[i]+1;
            for (unsigned int j = 0; j < nbp; j++){
                cycles_x_tmp[i].append(mean_time * ((double)j/(double)(nbp-1)));
                cycles_y_tmp[i].append(signal_y->at(pos[i]+j));
            }
        }

        //interpolate cycles
        QVector<double> *cycles_x = new QVector<double>[np-1];
        QVector<double> *cycles_y = new QVector<double>[np-1];
        for (unsigned int i = 0; i < np-1; i++){
            bool res;
            extend(&cycles_x[i], &cycles_y[i], &cycles_x_tmp[i], &cycles_y_tmp[i], nm, &res);
        }

        //mean cycles
        for (unsigned int i = 0; i < nm; i++){
            double mean = 0.;
            for (unsigned int j = 0; j < np-1; j++){
                mean += cycles_y[j].at(i);
            }
            mean = mean / (double)(np-1);
            mean_y->append(mean);
        }

        //mean of cycles
        double *mean_cycles = new double[np-1];
        for (unsigned int i = 0; i < np-1; i++){
            mean_cycles[i] = 0.;
            for (unsigned int j = 0; j < nm; j++){
                mean_cycles[i] += cycles_y[i].at(j);
            }
            mean_cycles[i] = mean_cycles[i] / (double)nm;
        }

        //mean of mean cycle
        double mean_cycle = 0.;
        for (unsigned int i = 0; i < nm; i++){
            mean_cycle += mean_y->at(i);
        }
        mean_cycle = mean_cycle / (double)nm;

        //sd
        for (unsigned int i = 0; i < nm; i++){
            double sd = 0.;
            double mean = mean_y->at(i) - mean_cycle;
            for (unsigned int j = 0; j < np-1; j++){
                double current_y = cycles_y[j].at(i) - mean_cycles[j];
                sd += (current_y - mean) * (current_y - mean);
            }
            sd = sqrt((1./(double)(np-1)) * sd);
            sd_y->append(sd);
        }

        //delete
        delete[] pos;
        delete[] times;
        delete[] cycles_x_tmp;
        delete[] cycles_y_tmp;
        delete[] cycles_x;
        delete[] cycles_y;
        delete[] mean_cycles;

        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

void move_curve(int n, QVector<double> *y, QVector<double> *yerr, bool *res){
    unsigned int ny = y->count();
    if ((ny != 0) && (n != (int)ny)){
        n = positive_modulo(n, ny);
        for (int i = 0; i < n; i++){
            y->append(y->takeFirst());
            if (yerr != NULL) yerr->append(yerr->takeFirst());
        }
        if (res != NULL) (*res) = true;
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

void move_curve(double val, QVector<double> *x, QVector<double> *y, QVector<double> *yerr, int *pos, bool *res){
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){

        int LOCAL__pos = -1;
        for (unsigned int i = 0; i < nx; i++){
            if (x->at(i) >= val){
                LOCAL__pos = i;
                break;
            }
        }

        move_curve(LOCAL__pos, y, yerr, res);
        if (res){
            if (pos != NULL) (*pos) = LOCAL__pos;
        }
    }
    else{
        if (res != NULL) (*res) = false;
    }
}

double stroke_volume(const QVector<double> *x, const QVector<double> *y, bool *res){
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){
        double sv = 0.;

        for( unsigned int i = 0; i < nx-1; i++){
            sv += (x->at(i+1) - x->at(i)) * (qAbs(y->at(i+1)) + qAbs(y->at(i))) / 2.;
        }

        if (res != NULL) (*res) = true;
        return (sv/2.);
    }
    else{
        if (res != NULL) (*res) = false;
        return -1.;
    }
}

bool detect_systole_check(const QVector<double> *x, const QVector<double> *y, double *threshold){
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){
        QVector<double> derivative;

        derivative.append( (y->at(1) - y->at(nx-1)) / (x->at(1) - x->at(ny-1)) );
        for (unsigned int i = 1; i < nx-1; i++){
            derivative.append( (y->at(i+1) - y->at(i-1)) / (x->at(i+1) - x->at(i-1)) );
        }
        derivative.append( (y->at(0) - y->at(nx-2)) / (x->at(0) - x->at(ny-2)) );

        bool res;
        double maxd = max(&derivative, NULL, &res);
        if (res){
            (*threshold) = maxd / 2.;
            return res;
        }
        else{
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "Derivative failed" << std::endl;
            (*threshold) = 0.;
            return false;
        }
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

double var(const QVector<double> *x, bool *res=NULL){
    unsigned int n = x->count();

    if (n != 0){
        double var = 0.;

        for (unsigned int i = 0; i < n; i++){
            var += x->at(i) * x->at(i);
        }

        var = var/(double)n;

        double mean_x = mean(x);

        var = var - mean_x*mean_x;

        if (res != NULL) (*res) = true;
        return var;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null size" << std::endl;
        if (res != NULL) (*res) = false;
        return -1.;
    }
}

double cov(const QVector<double> *x, const QVector<double> *y, bool *res=NULL){
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){
        double cov = 0.;

        for (unsigned int i = 0; i < nx; i++){
            cov += x->at(i)*y->at(i);
        }

        cov = cov/(double)nx;

        double mean_x = mean(x);
        double mean_y = mean(y);

        cov = cov - mean_x*mean_y;

        if (res != NULL) (*res) = true;
        return cov;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        if (res != NULL) (*res) = false;
        return -1.;
    }
}

double linear_regression(const QVector<double> *x, const QVector<double> *y, double *a, double *b, bool *res=NULL){
    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){
        bool res2;

        //Mean
        double mean_x = mean(x, &res2);
        if (!res2){
            if (res != NULL) (*res) = false;
            return -1.;
        }
        double mean_y = mean(y, &res2);
        if (!res2){
            if (res != NULL) (*res) = false;
            return -1.;
        }

        //Variance
        double var_x = var(x, &res2);
        if (!res2){
            if (res != NULL) (*res) = false;
            return -1.;
        }
        double var_y = var(y, &res2);
        if (!res2){
            if (res != NULL) (*res) = false;
            return -1.;
        }

        //Standard deviation
        double sigma_x = sqrt(var_x);
        double sigma_y = sqrt(var_y);

        //Covariance
        double cov_xy = cov(x, y, &res2);
        if (!res2){
            if (res != NULL) (*res) = false;
            return -1.;
        }

        //Correlation coefficient
        double corr_coeff = cov_xy / (sigma_x * sigma_y);

        //Regression line
        (*a) = cov_xy / var_x;
        (*b) = mean_y - (*a)*mean_x;

        if (res != NULL) (*res) = true;
        return corr_coeff;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        if (res != NULL) (*res) = false;
        return -1.;
    }
}

bool detect_systole(const QVector<double> *x, const QVector<double> *y, const double threshold, QVector<double> *systole_x, QVector<double> *systole_y){
    systole_x->clear();
    systole_y->clear();

    unsigned int nx = x->count();
    unsigned int ny = y->count();

    if ((nx == ny) && (nx != 0)){
        QVector<double> derivative;

        //Calculate derivatives
        for (unsigned int i = 1; i < nx-1; i++){
            derivative.append( (y->at(i+1) - y->at(i-1)) / (x->at(i+1) - x->at(i)) );
        }

        unsigned int nd = derivative.count();
        if (nd == 0){
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "Derivative failed" << std::endl;
            return false;
        }

        //Append to systole
        for (unsigned int i = 0; i < nd; i++){
            if (derivative.at(i) > threshold){
                systole_x->append(x->at(i+1));
                systole_y->append(y->at(i+1));
            }
        }

        unsigned int nsx = systole_x->count();
        unsigned int nsy = systole_y->count();
        if ((nsx == nsy) && (nsx == 0)){
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "Systole detection failed" << std::endl;
            return false;
        }

        //Check for linear regression
        double a, b;
        double corr_coeff = linear_regression(systole_x, systole_y, &a, &b);
        if (corr_coeff > 0.9){
            //Continue systole to min(y)
            bool res;
            int pos;
            double miny = min(y, &pos, &res);
            if (!res){
                std::cerr << Q_FUNC_INFO << std::endl;
                std::cerr << "Linear regression failed" << std::endl;
                return false;
            }
            systole_x->append((miny - b)/a);
            systole_y->append(miny);

            //Append more points
            double minx = min(systole_x);
            double maxx = max(systole_x);
            double maxy = max(systole_y);

            unsigned int npoints = GetNpi(&res);
            for (unsigned int i = 0; i < npoints; i++){
                systole_x->append(minx + (maxx - minx)*(double)i/((double)npoints-1.));
                systole_y->append(miny + (maxy - miny)*(double)i/((double)npoints-1.));
            }
        }

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool venous_correction(const QVector<double> *A, const QVector<double> *V, QVector<double> *nV, double *correction){
    nV->clear();

    unsigned int na = A->count();
    unsigned int nv = V->count();

    if ((na == nv) && (na != 0)){
        double sumA = A->at(0);
        double sumV = V->at(0);

        for (unsigned int i = 1; i < na; i++){
            sumA += A->at(i);
            sumV += V->at(i);
        }

        double LOCAL__correction = -sumA/sumV;

        for (unsigned int i = 0; i < na; i++){
            nV->append(V->at(i)*LOCAL__correction);
        }

        if (correction != NULL) (*correction) = LOCAL__correction;
        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool csf_correction(const QVector<double> *C, QVector<double> *nC, double *correction){
    nC->clear();

    unsigned int n = C->count();

    if (n != 0){
        bool res;
        double LOCAL__correction = mean(C, &res);
        if (!res){
            std::cerr << Q_FUNC_INFO << std::endl;
            std::cerr << "mean()" << std::endl;
            return res;
        }

        for (unsigned int i = 0; i < n; i++){
            nC->append(C->at(i) - LOCAL__correction);
        }

        if (correction != NULL) (*correction) = LOCAL__correction;
        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null size" << std::endl;
        return false;
    }
}

bool arteriovenous_flow(const QVector<double> *Ax, const QVector<double> *Ay, const QVector<double> *Vy, QVector<double> *AVx, QVector<double> *AVy){
    unsigned int nax = Ax->count();
    unsigned int nay = Ay->count();
    unsigned int nvy = Vy->count();

    if ((nax == nay) && (nay == nvy) && (nax != 0)){

        for (unsigned int i = 0; i < nax; i++){
            AVx->append(Ax->at(i));
            AVy->append(Ay->at(i) + Vy->at(i));
        }

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool arteriovenous_volume(const QVector<double> *AVfx, const QVector<double> *AVfy, QVector<double> *AVvx, QVector<double> *AVvy){
    unsigned int nx = AVfx->count();
    unsigned int ny = AVfy->count();

    if ((nx == ny) && (nx != 0)){

        for (unsigned int i = 0; i < nx-1; i++){
            AVvx->append( (AVfx->at(i+1) + AVfx->at(i)) / (2.) );
            if (i == 0){
                AVvy->append( ((AVfy->at(i+1) + AVfy->at(i)) / (2)) * (AVfx->at(i+1) - AVfx->at(i)) );
            }
            else{
                AVvy->append( AVvy->at(i-1) + ((AVfy->at(i+1) + AVfy->at(i)) / (2)) * (AVfx->at(i+1) - AVfx->at(i)) );
            }
        }

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool arteriovenouscsf_flow(const QVector<double> *Ax, const QVector<double> *Ay, const QVector<double> *Vy, const QVector<double> *CSFy, QVector<double> *AVCSFx, QVector<double> *AVCSFy){
    unsigned int nax = Ax->count();
    unsigned int nay = Ay->count();
    unsigned int nvy = Vy->count();
    unsigned int ncy = CSFy->count();

    if ((nax == nay) && (nvy == nay) && (ncy == nvy) && (nax != 0)){

        for (unsigned int i = 0; i < nax; i++){
            AVCSFx->append(Ax->at(i));
            AVCSFy->append(Ay->at(i) + Vy->at(i) + CSFy->at(i));
        }

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool arteriovenouscsf_volume(const QVector<double> *AVCSFfx, const QVector<double> *AVCSFfy, QVector<double> *AVCSFvx, QVector<double> *AVCSFvy){
    return arteriovenous_volume(AVCSFfx, AVCSFfy, AVCSFvx, AVCSFvy);
}

bool smooth(QVector<double> *v){
    unsigned int n = v->count();

    if (n > 1){

        double val = (v->at(n-1) + v->at(0) + v->at(1))/3.;
        v->replace(0, val);
        for (unsigned int i = 1; i < n-1; i++){
            val = (v->at(i-1) + v->at(i) + v->at(i+1))/3.;
            v->replace(i, val);
        }
        val = (v->at(n-2) + v->at(n-1) + v->at(0))/3.;
        v->replace(n-1, val);

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}

bool transfert_function(QVector<double> *TFx, QVector<double> *TFy, const QVector<double> *Vx, const QVector<double> *Vy, const QVector<double> *Px, const QVector<double> *Py){
    unsigned int nxV = Vx->count();
    unsigned int nyV = Vy->count();
    unsigned int nxP = Px->count();
    unsigned int nyP = Py->count();

    if ((nxV == nyV) && (nxV != 0) && (nxP = nxV) && (nyP == nxV)){
        unsigned int nf = nyV/2+1;

        //FFT Volume
        double *fft_in_V;
        fftw_complex *fft_out_V;
        fftw_plan fft_p_V;

        fft_in_V = (double*)malloc(nyV*sizeof(double));
        for (unsigned int i = 0; i < nyV; i++){
            fft_in_V[i] = Vy->at(i);
        }
        fft_out_V = (fftw_complex*) fftw_malloc(nf*sizeof(fftw_complex));

        fft_p_V = fftw_plan_dft_r2c_1d(nyV, fft_in_V, fft_out_V, FFTW_ESTIMATE);
        fftw_execute(fft_p_V);

        //FFT Pressure
        double *fft_in_P;
        fftw_complex *fft_out_P;
        fftw_plan fft_p_P;

        fft_in_P = (double*)malloc(nyP*sizeof(double));
        for (unsigned int i = 0; i < nyP; i++){
            fft_in_P[i] = Py->at(i);
        }
        fft_out_P = (fftw_complex*) fftw_malloc(nf*sizeof(fftw_complex));

        fft_p_P = fftw_plan_dft_r2c_1d(nyP, fft_in_P, fft_out_P, FFTW_ESTIMATE);
        fftw_execute(fft_p_P);

        //Transfert function
        fftw_complex *fft_TF;

        fft_TF = (fftw_complex*) fftw_malloc(nf*sizeof(fftw_complex));

        for (unsigned int i = 0; i < nf; i++){
            if ((fft_out_V[i])[0] != 0.){
                (fft_TF[i])[0] = (fft_out_P[i])[0] /(fft_out_V[i])[0];
            }
            else{
                (fft_TF[i])[0] = 0.;
            }
            if ((fft_out_V[i])[1] != 0.){
                (fft_TF[i])[1] = (fft_out_P[i])[1] /(fft_out_V[i])[1];
            }
            else{
                (fft_TF[i])[1] = 0.;
            }
        }

        for (unsigned int i = 0; i < nf; i++){
            TFx->append((double)i);
            //TFy->append(atan2((fft_TF[i])[1],(fft_TF[i])[0]));    //phase
            //TFy->append(20.*log10(sqrt(pow((fft_TF[i])[0], 2) + pow((fft_TF[i])[1], 2))));    //amplitude (Db)
            TFy->append(sqrt(pow((fft_TF[i])[0], 2) + pow((fft_TF[i])[1], 2)));    //amplitude
        }
        //TODO: ???
        //IFFT Transfert function
        /*double *ifft_out_TF;
        fftw_plan ifft_p_TF;

        ifft_out_TF = (double*)malloc(nxV*sizeof(double));

        ifft_p_TF = fftw_plan_dft_c2r_1d(nxV, fft_TF, ifft_out_TF, FFTW_ESTIMATE);
        fftw_execute(ifft_p_TF);

        for (unsigned int i = 0; i < nxV; i++){
            TFx->append(Px->at(i));
            TFy->append(ifft_out_TF[i]/nxV);
        }*/

        //Delete
        fftw_destroy_plan(fft_p_V);
        free(fft_in_V);
        fftw_free(fft_out_V);
        fftw_destroy_plan(fft_p_P);
        free(fft_in_P);
        fftw_free(fft_out_P);
        fftw_free(fft_TF);
        //free(ifft_out_TF);
        //fftw_destroy_plan(ifft_p_TF);

        return true;
    }
    else{
        std::cerr << Q_FUNC_INFO << std::endl;
        std::cerr << "Null or incompatible size" << std::endl;
        return false;
    }
}
