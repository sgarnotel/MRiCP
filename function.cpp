#include "headers.hpp"


/*!
 * \brief Coord2QVector
 * \param in
 * \return
 *
 * Convert a Coord to two QVector<double>
 */
QVector<double> *Coord2QVector(Coord *in)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    QVector<double> *out = new QVector<double>[2];

    for (int i = 0; i < in->size(); i++){
        out[0].append(in->coord(i, XCOORD));
        out[1].append(in->coord(i, YCOORD));
    }

    return out;
}

/*!
 * \brief min
 * \param x
 * \param y
 * \return min
 *
 * Return the min of x or y (double)
 */
double dmin(double x, double y)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    if (x < y){
        return x;
    }
    else{
        return y;
    }
}

/*!
 * \brief max
 * \param x
 * \param y
 * \return max
 *
 * Return the max of x or y (double)
 */
double dmax (double x, double y)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    if (x < y){
        return y;
    }
    else{
        return x;
    }
}

/*!
 * \brief min
 * \param x
 * \param n
 * \return min
 *
 * Return the max of x (vector)
 */
double min(double *x, int n)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    double min = x[0];
    for (int i = 1; i < n; i++){
        if (min > x[i]){
            min = x[i];
        }
    }
    return min;
}

/*!
 * \brief max
 * \param x
 * \param n
 * \return max
 *
 * Return the max of x (vector)
 */
double max(double *x, int n)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    double max = x[0];
    for (int i = 1; i < n; i++){
        if (max < x[i]){
            max = x[i];
        }
    }
    return max;
}

/*!
 * \brief min
 * \param x
 * \return min
 *
 * Return the min of x (QVector<double>)
 */
double min(QVector<double> x)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    double min = x.at(0);
    for (int i = 1; i < x.size(); i++){
        if (min > x.at(i)){
            min = x.at(i);
        }
    }
    return min;
}

/*!
 * \brief max
 * \param x
 * \return max
 *
 * Return the max of x (QVector<double>)
 */
double max(QVector<double> x)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    double max = x.at(0);
    for (int i = 1; i < x.size(); i++){
        if (max < x.at(i)){
            max = x.at(i);
        }
    }
    return max;
}

/*!
 * \brief mean
 * \param coord
 * \return
 */
double mean(Coord coord, char type)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = coord.size();
    double mean = 0.;

    for (int i = 0; i < n; i++){
        mean += coord.coord(i, type);
    }
    mean = mean/(double)n;

    return mean;
}

/*!
 * \brief mean
 * \param x
 * \return
 */
double mean(QVector<double> x)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = x.size();
    double mean = 0.;

    for (int i = 0; i < n; i++){
        mean += x.at(i);
    }

    mean = mean/(double)n;

    return mean;
}

/*!
 * \brief var
 * \param x
 * \return
 */
double var(QVector<double> x)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = x.size();
    double var = 0.;

    for (int i = 0; i < n; i++){
        var += x.at(i) * x.at(i);
    }

    var = var/(double)n;

    double mean_x = mean(x);

    var = var - mean_x*mean_x;

    return var;
}

/*!
 * \brief cov
 * \param x
 * \param y
 * \return
 */
double cov(QVector<double> x, QVector<double> y)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = x.size();
    double cov = 0.;

    for (int i = 0; i < n; i++){
        cov += x.at(i)*y.at(i);
    }

    cov = cov/(double)n;

    double mean_x = mean(x);
    double mean_y = mean(y);

    cov = cov - mean_x*mean_y;

    return cov;
}

/*!
 * \brief fourier
 * \param coord_fourier
 * \param coord_selected
 * \return
 */
bool fourier(Coord *coord_fourier, Coord coord_selected)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //FFTW3 VERSION
    {
        //FFT
        int n = coord_selected.size();
        coord_fourier->set_size(n/2. + 1);

        double *in;
        fftw_complex *out;
        fftw_plan p;

        in = (double*)malloc(n*sizeof(double));
        for (int i = 0; i < n; i++){
            in[i] = coord_selected.coord(i, YCOORD);
        }

        out = (fftw_complex*) fftw_malloc(((n/2)+1)*sizeof(fftw_complex));
        p = fftw_plan_dft_r2c_1d(n, in, out, FFTW_ESTIMATE);
        fftw_execute(p);

        //Fourier spectrum
        for (int i = 0; i < n/2+1; i++){
            coord_fourier->set_coord(i, i, XCOORD);
            double y_val = ((out[i])[0])*((out[i])[0]) + ((out[i])[1])*((out[i])[1]);
            coord_fourier->set_coord(y_val, i, YCOORD);
        }

        //Delete
        fftw_destroy_plan(p);
        free(in);
        fftw_free(out);

        return true;
    }
}

bool fourier_test(Coord *coord_fourier, Coord coord_selected)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //FFTW3 VERSION
    {
        //FFT
        int n = coord_selected.size();
        coord_fourier->set_size(n/2. + 1);

        double *in;
        fftw_complex *out;
        fftw_plan p;

        in = (double*)malloc(n*sizeof(double));
        for (int i = 0; i < n; i++){
            in[i] = coord_selected.coord(i, YCOORD);
        }

        out = (fftw_complex*) fftw_malloc(((n/2)+1)*sizeof(fftw_complex));
        p = fftw_plan_dft_r2c_1d(n, in, out, FFTW_ESTIMATE);
        fftw_execute(p);

        double sample = 1. / (coord_selected.coord(1, XCOORD) - coord_selected.coord(0, XCOORD));

        //Fourier spectrum
        for (int i = 0; i < n/2+1; i++){
            coord_fourier->set_coord(sample * (double)i/((double)n), i, XCOORD);  //TODO
            //coord_fourier->set_coord(i, i, XCOORD);
            double y_val = ((out[i])[0])*((out[i])[0]) + ((out[i])[1])*((out[i])[1]);
            coord_fourier->set_coord(y_val, i, YCOORD);
        }

        //Delete
        fftw_destroy_plan(p);
        free(in);
        fftw_free(out);

        return true;
    }
}

/*!
 * \brief ifft
 * \param coord_ifft
 * \param coord_selected
 * \param min_threshold
 * \param max_threshold
 * \return
 */
bool ifft(Coord *coord_ifft, Coord coord_selected, int min_threshold, int max_threshold)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //FFTW3 VERSION
    {
        //FFT
        int n = coord_selected.size();
        int n_ifft = n/2+1;
        coord_ifft->set_size(n);

        double *fft_in;
        fftw_complex *fft_out;
        fftw_plan fft_p;

        fft_in = (double*)malloc(n*sizeof(double));
        for (int i = 0; i < n; i++){
            fft_in[i] = coord_selected.coord(i, YCOORD);
        }
        fft_out = (fftw_complex*) fftw_malloc(n_ifft*sizeof(fftw_complex));

        fft_p = fftw_plan_dft_r2c_1d(n, fft_in, fft_out, FFTW_ESTIMATE);
        fftw_execute(fft_p);

        //Harmonics select
        fftw_complex *ifft_in;
        double *ifft_out;
        fftw_plan ifft_p;

        ifft_in = (fftw_complex*) fftw_malloc(n_ifft*sizeof(fftw_complex));
        for (int i = 0; i < n_ifft; i++){
            if (i >= min_threshold && i <=max_threshold){
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

        for (int i = 0; i < n; i++){
            coord_ifft->set_coord(coord_selected.coord(i, XCOORD), i, XCOORD);
            coord_ifft->set_coord(ifft_out[i]/n, i, YCOORD);
        }

        //Delete
        fftw_destroy_plan(fft_p);
        fftw_destroy_plan(ifft_p);
        free(fft_in);
        free(ifft_out);
        fftw_free(fft_out);
        fftw_free(ifft_in);

        return true;
    }
}

/*!
 * \brief detect_peaks
 * \param coord
 * \param peaks
 * \param threshold
 */
void detect_peaks(Coord coord, Coord *peaks, double threshold)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = coord.size();

    Coord *peaks_tmp = new Coord();
    peaks_tmp->set_size(n);

    int k = 0;
    for (int i = 0; i < n; i++){
        if (coord.coord(i, YCOORD) > threshold){
            //We are upper than threshold
            while(coord.coord(i, YCOORD) > threshold && i < n-1){
                if (i != 0){
                    if (coord.coord(i-1, YCOORD) < coord.coord(i, YCOORD) && coord.coord(i, YCOORD) > coord.coord(i+1, YCOORD)){
                        peaks_tmp->set_coord(coord.coord(i, XCOORD), k, XCOORD);
                        peaks_tmp->set_coord(coord.coord(i, YCOORD), k, YCOORD);
                        k++;
                    }
                }
                i++;
            }
        }
    }

    peaks->set_size(k);
    for (int i = 0; i < k; i++){
        peaks->set_coord(peaks_tmp->coord(i, XCOORD), i, XCOORD);
        peaks->set_coord(peaks_tmp->coord(i, YCOORD), i, YCOORD);
    }
}

/*!
 * \brief mean_icp
 * \param coord
 * \param peaks
 * \param mean
 * \param SD
 */
void mean_icp(Coord coord, Coord peaks, Coord *mean, Coord *SD)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //Sizes
    int n = coord.size();
    int n_peaks = peaks.size();

    //First peak
    int n0 = 0;
    for (int i = 0; i < n; i++){
        if (coord.coord(i, XCOORD) == peaks.coord(0, XCOORD)){
            n0 = i;
            break;
        }
    }

    //Number of points between 2 peaks
    int *nb_pts = new int[n_peaks-1];
    for (int i = 0; i < n_peaks-1; i++){
        nb_pts[i] = 0;
        for (int j = 0; j < n; j++){
            if (peaks.coord(i, XCOORD) == coord.coord(j, XCOORD)){
                while (peaks.coord(i+1, XCOORD) != coord.coord(j, XCOORD)){
                    nb_pts[i]++;
                    j++;
                }
            }
        }
    }

    //Position of points
    int *pos_pts = new int[n_peaks-1];
    pos_pts[0] = n0;
    for (int i = 1; i < n_peaks-1; i++){
        pos_pts[i] = pos_pts[i-1] + nb_pts[i];
    }

    //Mean nb of points
    /*int mean_pts = 0;
    for (int i = 0; i < n_peaks-1; i++){
        mean_pts += nb_pts[i];
    }
    mean_pts = mean_pts / (n_peaks-1.);*/

    //Time between 2 peaks
    double *times = new double[n_peaks-1];
    for (int i = 0; i < n_peaks-1; i++){
        times[i] =peaks.coord(i+1, XCOORD) - peaks.coord(i, XCOORD);
    }

    //Mean time
    double mean_time =0.;
    for (int i = 0; i < n_peaks-1; i++){
        mean_time += times[i];
    }
    mean_time = mean_time / (n_peaks-1.);

    //Create mean x (with mean nb points and mean time)
    int mean_pts;
    get_npi(&mean_pts);
    mean->set_size(mean_pts);
    for (int i = 0; i < mean_pts; i++){
        mean->set_coord((i/(mean_pts-1.)*mean_time), i, XCOORD);
    }

    //Creat SD x
    SD->set_size(mean_pts);
    for (int i = 0; i < mean_pts; i++){
        SD->set_coord((i/(mean_pts-1.)), i, XCOORD);
    }

    //Separate cycles
    Coord *coords_tmp = new Coord[n_peaks-1];
    for (int i = 0; i < n_peaks-1; i++){
        coords_tmp[i].set_size(nb_pts[i]);
        for (int j = 0; j < nb_pts[i]; j++){
            coords_tmp[i].set_coord(j/(nb_pts[i]-1.)*mean_time, j, XCOORD);
            coords_tmp[i].set_coord(coord.coord(pos_pts[i]+j, YCOORD), j, YCOORD);
        }
    }

    //Interpolate  cycles
    Coord *coords = new Coord[n_peaks-1];
    for (int i = 0; i < n_peaks-1; i++){
        coords[i].set_size(mean_pts);

        //x
        for (int j = 0; j < mean_pts; j++){
            coords[i].set_coord((j/(mean_pts-1.)*mean_time), j, XCOORD);
        }

        //y
        //First value
        coords[i].set_coord(coords_tmp[i].coord(0, YCOORD), 0, YCOORD);
        //Middle values
        for (int j = 1; j < mean_pts-1; j++){
            double val = 0.;
            int pos = 0;
            while (coords[i].coord(j, XCOORD) > coords_tmp[i].coord(pos, XCOORD) && pos < nb_pts[i]){
                pos++;
            }
            val = coords_tmp[i].coord(pos-1, YCOORD) + (coords_tmp[i].coord(pos, YCOORD) - coords_tmp[i].coord(pos-1, YCOORD))*(coords_tmp[i].coord(pos-1, XCOORD) - coords[i].coord(j, XCOORD))/(coords_tmp[i].coord(pos-1, XCOORD) - coords_tmp[i].coord(pos, XCOORD));
            coords[i].set_coord(val, j, YCOORD);
        }
        //Last value
        coords[i].set_coord(coords_tmp[i].coord(nb_pts[i]-1, YCOORD), mean_pts-1, YCOORD);
    }

    //Mean cycle
    for (int i = 0; i < mean_pts; i++){
        double mean_y = 0.;
        for (int j = 0; j < n_peaks-1; j++){
            mean_y += coords[j].coord(i, YCOORD);
        }
        mean_y = mean_y / (n_peaks -1.);
        mean->set_coord(mean_y, i, YCOORD);
    }

    //Mean of cycles
    double *mean_cycles = new double[n_peaks-1];
    for (int i = 0; i < n_peaks-1; i++){
        mean_cycles[i] = 0.;
        for (int j = 0; j < mean_pts; j++){
            mean_cycles[i] += coords[i].coord(j, YCOORD);
        }
        mean_cycles[i] = mean_cycles[i] / mean_pts;
    }
    //Mean of mean cycle
    double mean_cycle = 0.;
    for (int i = 0; i < mean_pts; i++){
        mean_cycle += mean->coord(i, YCOORD);
    }
    mean_cycle = mean_cycle / mean_pts;
    //SD
    for (int i = 0; i < mean_pts; i++){
        double standard_deviation = 0.;
        double mean_y = (mean->coord(i, YCOORD) - mean_cycle);
        for (int j = 0; j < n_peaks-1; j++){
            double current_y = (coords[j].coord(i, YCOORD) - mean_cycles[j]);
            standard_deviation += (current_y - mean_y) * (current_y - mean_y);
        }
        standard_deviation = sqrt((1. / (n_peaks-1.)) * standard_deviation);
        SD->set_coord(standard_deviation, i, YCOORD);
    }

    delete[] mean_cycles;
    delete[] coords_tmp;
    delete[] coords;
}

/*!
 * \brief adjust
 * \param coord
 * \param SD
 * \param type
 */
void adjust(Coord *coord, Coord *SD, string type)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = coord->size();

    Coord *coord_cpy = new Coord;
    Coord *SD_cpy = new Coord;
    coord_cpy->set_size(n);
    SD_cpy->set_size(n);

    for (int i = 0; i < n; i++){
        coord_cpy->set_coord(coord->coord(i, XCOORD), i, XCOORD);
        coord_cpy->set_coord(coord->coord(i, YCOORD), i, YCOORD);
        if (SD != NULL){
            SD_cpy->set_coord(SD->coord(i, XCOORD), i, XCOORD);
            SD_cpy->set_coord(SD->coord(i, YCOORD), i, YCOORD);
        }
    }

    if (type.compare("min x") == 0){
        double min = coord_cpy->coord(0, YCOORD);
        int pos = 0;

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val < min){
                min = val;
                pos = i;
            }
        }

        int k = 0;
        for (int i = pos; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD), k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
        for (int i = 0; i < pos; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD), k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }
    else if (type.compare("min y") == 0){
        double min = coord_cpy->coord(0, YCOORD);

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val < min){
                min = val;
            }
        }

        int k = 0;
        for (int i = 0; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-min, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }
    else if (type.compare("min xy") == 0){
        double min = coord_cpy->coord(0, YCOORD);
        int pos = 0;

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val < min){
                min = val;
                pos = i;
            }
        }

        int k = 0;
        for (int i = pos; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-min, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
        for (int i = 0; i < pos; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-min, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }
    else if (type.compare("max x") == 0){
        double max = coord_cpy->coord(0, YCOORD);
        int pos = 0;

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val > max){
                max = val;
                pos = i;
            }
        }

        int k = 0;
        for (int i = pos; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD), k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
        for (int i = 0; i < pos; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD), k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }
    else if (type.compare("max y") == 0){
        double max = coord_cpy->coord(0, YCOORD);

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val > max){
                max = val;
            }
        }

        int k = 0;
        for (int i = 0; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-max, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }
    else if (type.compare("max xy") == 0){
        double max = coord_cpy->coord(0, YCOORD);
        int pos = 0;

        for (int i = 0; i < n; i++){
            double val = coord_cpy->coord(i, YCOORD);
            if (val > max){
                max = val;
                pos = i;
            }
        }

        int k = 0;
        for (int i = pos; i < n; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-max, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }
        for (int i = 0; i < pos; i++){
            coord->set_coord(coord_cpy->coord(i, YCOORD)-max, k, YCOORD);
            if (SD != NULL) SD->set_coord(SD_cpy->coord(i, YCOORD), k, YCOORD);
            k++;
        }

    }
    else{
        cout << "adjust(Coord *coord, string type) -- BAD TYPE" << endl;
    }
}

/*!
 * \brief normalize
 * \param coord
 * \param SD
 */
void normalize(Coord *coord, Coord *SD)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = coord->size();

    double ymin = min(coord->coords(YCOORD), coord->size());
    double ymax = max(coord->coords(YCOORD), coord->size());

    double ynorm = max(ymax, -ymin);

    for (int i = 0; i < n; i++){
        coord->set_coord((coord->coord(i, YCOORD))/(ynorm), i, YCOORD);
        if (SD != NULL) SD->set_coord(SD->coord(i, YCOORD)/(ynorm), i, YCOORD);
    }
}

/*!
 * \brief av_conservation
 * \param arterial
 * \param venous
 * \return
 */
double av_conservation(Coord arterial, Coord venous)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = arterial.size();
    double alpha = 0.;
    double suma = 0., sumv = 0.;

    for (int i = 0; i < n; i++){
        suma += arterial.coord(i, YCOORD);
        sumv += venous.coord(i, YCOORD);
    }

    alpha = -suma/sumv;

    return alpha;
}



void arteriovenous_flow(Coord *arteriovenous, Coord arterial, Coord venous)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = arterial.size();

    arteriovenous->clear();
    arteriovenous->set_size(n);

    for (int i = 1; i < n; i++){
        arteriovenous->set_coord(arterial.coord(i, XCOORD), i, XCOORD);
        arteriovenous->set_coord(arterial.coord(i, YCOORD) + venous.coord(i, YCOORD), i, YCOORD);
    }
}


/*!
 * \brief arteriovenous
 * \param arteriovenous
 * \param arterial
 * \param venous
 */
void arteriovenous_volume(Coord *arteriovenous, Coord arterial, Coord venous)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = arterial.size();

    arteriovenous->clear();
    arteriovenous->set_size(n);

    arteriovenous->set_coord(arterial.coord(0, XCOORD), 0, XCOORD);
    arteriovenous->set_coord((arterial.coord(0, YCOORD) + venous.coord(0, YCOORD)) * arterial.coord(0, XCOORD), 0, YCOORD);
    for (int i = 1; i < n; i++){
        arteriovenous->set_coord(arterial.coord(i, XCOORD), i, XCOORD);
        arteriovenous->set_coord(arteriovenous->coord(i-1, YCOORD) + (arterial.coord(i, YCOORD) + venous.coord(i, YCOORD)) * (arterial.coord(i, XCOORD) - arterial.coord(i-1, XCOORD)), i, YCOORD);
    }
}

void icvc_flow(Coord *icvc, Coord arterial, Coord venous, Coord csf)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = arterial.size();

    icvc->clear();
    icvc->set_size(n);

    for (int i = 0; i < n; i++){
        icvc->set_coord(arterial.coord(i, XCOORD), i, XCOORD);
        icvc->set_coord(arterial.coord(i, YCOORD) + venous.coord(i, YCOORD) + csf.coord(i, YCOORD), i, YCOORD);
    }
}

/*!
 * \brief icvc
 * \param icvc
 * \param arterial
 * \param venous
 * \param csf
 */
void icvc_volume(Coord *icvc, Coord arterial, Coord venous, Coord csf)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = arterial.size();

    icvc->clear();
    icvc->set_size(n);

    icvc->set_coord(arterial.coord(0, XCOORD), 0, XCOORD);
    icvc->set_coord((arterial.coord(0, YCOORD) + venous.coord(0, YCOORD) + csf.coord(0, YCOORD)) * arterial.coord(0, XCOORD), 0, YCOORD);
    for (int i = 1; i < n; i++){
        icvc->set_coord(arterial.coord(i, XCOORD), i, XCOORD);
        icvc->set_coord(icvc->coord(i-1, YCOORD) + (arterial.coord(i, YCOORD) + venous.coord(i, YCOORD) + csf.coord(i, YCOORD)) * (arterial.coord(i, XCOORD) - arterial.coord(i-1, XCOORD)), i, YCOORD);
    }
}

/*!
 * \brief extend
 * \param in
 * \param out
 * \param npi
 */
void extend(Coord *out, int npi)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = out->size();

    if (n > 0){
        Coord in;
        in.set_size(n);
        in.set_coords(out->coords(XCOORD), out->coords(YCOORD));

        double xmin = min(in.coords(XCOORD), in.size());
        double xmax = max(in.coords(XCOORD), in.size());

        out->set_size(npi);
        for (int i = 0; i < npi; i++){
            //x
            out->set_coord(xmin + ( (double)i/((double)npi-1) * (xmax - xmin)), i, XCOORD);
            //y
            int pos = 0;
            while(out->coord(i, XCOORD) > in.coord(pos, XCOORD)){
                pos++;
            }
            out->set_coord(in.coord(pos-1, YCOORD) + (in.coord(pos, YCOORD) - in.coord(pos-1, YCOORD))*(in.coord(pos-1, XCOORD) - out->coord(i, XCOORD))/(in.coord(pos-1, XCOORD) - in.coord(pos, XCOORD)), i, YCOORD);
        }
    }
}

/*!
 * \brief intercorr
 * \param coord_corr
 * \param coord_signal1
 * \param coord_signal2
 * \return
 */
bool intercorr(Coord *coord_corr, Coord coord_signal1, Coord coord_signal2)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //FFTW3 VERSION
    {
        //FFT
        int n = coord_signal1.size();
        int n_ifft = n/2+1;
        coord_corr->set_size(n);

        //Signal1
        double *fft_in1;
        fftw_complex *fft_out1;
        fftw_plan fft_p1;

        fft_in1 = (double*)malloc(n*sizeof(double));
        for (int i = 0; i < n; i++){
            fft_in1[i] = coord_signal1.coord(i, YCOORD);
        }
        fft_out1 = (fftw_complex*)fftw_malloc(n_ifft*sizeof(fftw_complex));

        fft_p1 = fftw_plan_dft_r2c_1d(n, fft_in1, fft_out1, FFTW_ESTIMATE);
        fftw_execute(fft_p1);

        //Signal2
        double *fft_in2;
        fftw_complex *fft_out2;
        fftw_plan fft_p2;

        fft_in2 = (double*)malloc(n*sizeof(double));
        for (int i = 0; i < n; i++){
            fft_in2[i] = coord_signal2.coord(i, YCOORD);
        }

        fft_out2 = (fftw_complex*)fftw_malloc(n_ifft*sizeof(fftw_complex));

        fft_p2 = fftw_plan_dft_r2c_1d(n, fft_in2, fft_out2, FFTW_ESTIMATE);
        fftw_execute(fft_p2);

        //IFFT
        fftw_complex *ifft_in;
        double *ifft_out;
        fftw_plan ifft_p;

        //Multiply FFT(signal1) and signal2
        ifft_in = (fftw_complex*)fftw_malloc(n_ifft*sizeof(fftw_complex));
        for (int i = 0; i < n_ifft; i++){
            (ifft_in[i])[0] = ( (fft_out1[i])[0] * (fft_out2[i])[0] ) + ( (fft_out1[i])[1] * (fft_out2[i])[1] );
            (ifft_in[i])[1] = - ( (fft_out1[i])[0] * (fft_out2[i])[1] ) + ( (fft_out1[i])[1] * (fft_out2[i])[0] );
        }
        ifft_out = (double*)malloc(n*sizeof(double));

        ifft_p = fftw_plan_dft_c2r_1d(n, ifft_in, ifft_out, FFTW_ESTIMATE);
        fftw_execute(ifft_p);

        for (int i = 0; i < n; i++){
            coord_corr->set_coord(coord_signal1.coord(i, XCOORD), i, XCOORD);
            coord_corr->set_coord(ifft_out[i], i, YCOORD);
        }

        //Delete
        fftw_destroy_plan(fft_p1);
        fftw_destroy_plan(fft_p2);
        fftw_destroy_plan(ifft_p);
        free(fft_in1);
        free(fft_in2);
        free(ifft_out);
        fftw_free(fft_out1);
        fftw_free(fft_out2);
        fftw_free(ifft_in);

        return true;
    }
}

/*!
 * \brief norm2
 * \param coord
 * \return
 */
double norm2(Coord *coord)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    double norm = 0.;
    for (int i = 0; i < coord->size(); i++){
        norm += coord->coord(i, YCOORD) * coord->coord(i, YCOORD);
    }
    norm = sqrt(norm);
    return norm;
}

/*!
 * \brief correlate
 * \param compare
 * \param volume
 * \param pressure
 */
void correlate(Coord *compare, Coord *volume, Coord *pressure)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    intercorr(compare, *volume, *pressure);

    double normxy = volume->size() * norm2(volume) * norm2(pressure);
    for (int i = 0; i < compare->size(); i++){
        compare->set_coord(compare->coord(i, YCOORD)/normxy, i, YCOORD);
    }

    /*cout << "x = [";
    for (int i = 0; i < volume->size(); i++){
        cout << volume->coord(i, YCOORD);
        if (i < volume->size()-1){
            cout << ", ";
        }
        else{
            cout << "]\n";
        }
    }
    cout << "y = [";
    for (int i = 0; i < pressure->size(); i++){
        cout << pressure->coord(i, YCOORD);
        if (i < pressure->size()-1){
            cout << ", ";
        }
        else{
            cout << "]\n";
        }
    }
    cout << "c = [";
    for (int i = 0; i < compare->size(); i++){
        cout << compare->coord(i, YCOORD);
        if (i < compare->size()-1){
            cout << ", ";
        }
        else{
            cout << "]\n";
        }
    }*/
}

/*!
 * \brief linear_regression
 * \param x
 * \param y
 * \param a
 * \param b
 * \return
 */
double linear_regression(QVector<double> x, QVector<double> y, double *a, double *b)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //Mean
    double mean_x = mean(x);
    double mean_y = mean(y);

    //Variance
    double var_x = var(x);
    double var_y = var(y);

    //
    double sigma_x = sqrt(var_x);
    double sigma_y = sqrt(var_y);

    //Covariance
    double cov_xy = cov(x, y);

    //Correlation coefficient
    double corr_coeff = cov_xy / (sigma_x * sigma_y);

    //Regression line
    (*a) = cov_xy / var_x;
    (*b) = mean_y - (*a)*mean_x;

    return corr_coeff;
}

/*!
 * \brief smooth
 * \param signal
 * \return
 */
Coord *smooth(Coord signal)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = signal.size();

    Coord *smooth_signal = new Coord;
    smooth_signal->set_size(n);

    smooth_signal->set_coord(signal.coord(0, XCOORD), 0, XCOORD);
    smooth_signal->set_coord(signal.coord(0, YCOORD), 0, YCOORD);

    for (int i = 1; i < n-1; i++){
        smooth_signal->set_coord(signal.coord(i, XCOORD), i, XCOORD);
        double smooth = (signal.coord(i-1, YCOORD) + signal.coord(i, YCOORD) + signal.coord(i+1, YCOORD))/3.;
        smooth_signal->set_coord(smooth, i, YCOORD);
    }

    smooth_signal->set_coord(signal.coord(n-1, XCOORD), n-1, XCOORD);
    smooth_signal->set_coord(signal.coord(n-1, YCOORD), n-1, YCOORD);

    return smooth_signal;
}

/*!
 * \brief test_detect_systole
 * \param signal
 * \param delay
 * \return
 */
double *test_detect_systole(Coord signal, int delay)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    delay = max(delay, 1);

    int n = signal.size();
    double *range = new double[2];
    range[0] = 0.; range[1] = 0.;

    if (n > 0){
        Coord *systole_zone = new Coord;
        systole_zone->set_size(n);

        for (int i = 0; i < delay; i++){
            systole_zone->set_coord(signal.coord(i, XCOORD), i, XCOORD);
            systole_zone->set_coord(0., i, YCOORD);
        }
        for (int i = delay; i < n-delay; i++){
            systole_zone->set_coord(signal.coord(i, XCOORD), i, XCOORD);
            systole_zone->set_coord(signal.coord(i, YCOORD)-signal.coord((i-delay), YCOORD), i, YCOORD);
        }
        for (int i = 0; i < delay; i++){
            systole_zone->set_coord(signal.coord(n-(i+1), XCOORD), n-(i+1), XCOORD);
            systole_zone->set_coord(0., n-(i+1), YCOORD);
        }

        range[0] = max(0., min(systole_zone->coords(YCOORD), systole_zone->size()));
        range[1] = max(systole_zone->coords(YCOORD), systole_zone->size());
    }
    return range;
}

/*!
 * \brief detect_systole
 * \param signal
 * \param delay
 * \param threshold
 * \return
 */
Coord *detect_systole_new(Coord signal, int delay, double threshold)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = signal.size();

    if (n > 0){
        Coord *systole_zone = new Coord;
        systole_zone->set_size(n);

        bool linear_reg = false;
        threshold = 1.;

        while(!linear_reg){
            //TODO
        }
    }
}

Coord *detect_systole(Coord signal, int delay, double threshold)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = signal.size();

    Coord *systole_zone = new Coord;
    systole_zone->set_size(n);


    for (int i = 0; i < delay; i++){
        systole_zone->set_coord(signal.coord(i, XCOORD), i, XCOORD);
        systole_zone->set_coord(signal.coord(i, YCOORD)-signal.coord(n-delay+i, YCOORD), i, YCOORD);
    }
    for (int i = delay; i < n; i++){
        systole_zone->set_coord(signal.coord(i, XCOORD), i, XCOORD);
        systole_zone->set_coord(signal.coord(i, YCOORD)-signal.coord((i-delay), YCOORD), i, YCOORD);
    }

    Coord *systole_tmp = new Coord;
    systole_tmp->set_size(n);

    int k = 0;
    for (int i = 0; i < n; i++){
        if (systole_zone->coord(i, YCOORD) > threshold){
            systole_tmp->set_coord(signal.coord(i, XCOORD), k, XCOORD);
            systole_tmp->set_coord(signal.coord(i, YCOORD), k, YCOORD);
            k++;
        }
    }

    delete systole_zone;

    Coord *systole = new Coord;
    systole->set_size(k);

    for (int i = 0; i < k; i++){
        systole->set_coord(systole_tmp->coord(i, XCOORD), i, XCOORD);
        systole->set_coord(systole_tmp->coord(i, YCOORD), i, YCOORD);
    }

    delete systole_tmp;

    double a, b;
    QVector<double> *xy = Coord2QVector(systole);
    double corr_coeff = linear_regression(xy[0], xy[1], &a, &b);

    if (corr_coeff > 0.95){
        Coord *systole_reg = new Coord;
        int sup = 2;
        systole_reg->set_size(k+2*sup);

        double delta_x = systole->coord(1, XCOORD) - systole->coord(0, XCOORD);

        for (int i = 0; i < sup; i++){
            systole_reg->set_coord(systole->coord(0, XCOORD)-(sup-i)*delta_x, 0, XCOORD);
            systole_reg->set_coord(a*systole_reg->coord(i, XCOORD)+b, 0, YCOORD);
        }
        for (int i = sup; i < k+sup; i++){
            systole_reg->set_coord(systole->coord(i-sup, XCOORD), i, XCOORD);
            systole_reg->set_coord(a*systole_reg->coord(i, XCOORD)+b, i, YCOORD);
        }
        for (int i = k+sup; i < k+2*sup; i++){
            systole_reg->set_coord(systole->coord(k-1, XCOORD)+(i-(k+sup)+1)*delta_x, k+1, XCOORD);
            systole_reg->set_coord(a*systole_reg->coord(i, XCOORD)+b, k+1, YCOORD);
        }

        delete systole;

        systole_reg->sort(YCOORD);

        return systole_reg;
    }
    else{
        /*if (threshold == 0){
            threshold = 1.;
        }
        else{
            threshold = threshold * 1.1;
        }

        detect_systole(signal, delay, threshold);*/ //TODO

        return systole_zone;
    }
}

/*!
 * \brief compliance_continuous
 * \param volume
 * \param pressure
 * \param width
 * \return
 */
Coord *compliance_continuous(Coord volume, Coord pressure, int width)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    //C = dV/dP
    int n1 = volume.size();
    int n2 = pressure.size();

    Coord *compliance = new Coord;

    if (n1 > 0 && n1 == n2 && n1 > width){
        compliance->set_size(n1);

        for (int i = 0; i < width; i++){
            compliance->set_coord(volume.coord(0, XCOORD), i, XCOORD);
            compliance->set_coord( (volume.coord(n1-width+i, YCOORD)-volume.coord(0, YCOORD)) / (pressure.coord(n1-width+i, YCOORD)-pressure.coord(0, YCOORD)) , i, YCOORD);
        }
        for (int i = width; i < n1; i++){
            compliance->set_coord(volume.coord(i, XCOORD), i, XCOORD);
            compliance->set_coord( (volume.coord(i-width, YCOORD)-volume.coord(i, YCOORD)) / (pressure.coord(i-width, YCOORD)-pressure.coord(i, YCOORD)) , i, YCOORD);
        }
    }

    return compliance;
}

/*!
 * \brief filter
 * \param signal
 * \param threshold
 * \return
 */
bool filter(Coord *signal, int threshold)
{
    if (DEBUG > 10) cout << Q_FUNC_INFO << endl;

    int n = signal->size();
    if (n > 0){
        int *todel = new int[n];
        for (int i = 0; i < n; i++){
            todel[i] = 0;
        }

        double ymean = mean(*signal, YCOORD);

        double ymin = min(signal->coords(YCOORD), n);
        double ymax = max(signal->coords(YCOORD), n);

        double ygrad2 = (ymax - ymin)/2.;

        double threshold_min = ymean - (1.-threshold/100.)*ygrad2;
        double threshold_max = ymean + (1.-threshold/100.)*ygrad2;

        for (int i = 0; i < n; i++){
            if (signal->coord(i, YCOORD) < threshold_min){
                todel[i] = 1;
            }
            else if (signal->coord(i, YCOORD) > threshold_max){
                todel[i] = 1;
            }
        }

        int num_zero = 0;
        for (int i = 0; i < n; i++){
            if (todel[i] == 0){
                num_zero++;
            }
        }

        if (num_zero < 3){
            for (int i = 0; i < n; i++){
                signal->set_coord(0., i, YCOORD);
            }
        }
        else{
            for (int i = 0; i < n; i++){
                if (todel[i] == 1){
                    int pos = i;
                    int pos2 = i;
                    while(todel[pos2] == 1){
                        pos2++;
                        pos2 = pos2 % n;
                        if (pos2 == pos){
                            break;
                        }
                    }

                    for (int j = pos; j < pos2; j++){
                        signal->set_coord((signal->coord(pos, YCOORD)+signal->coord(pos2, YCOORD))/2., j, YCOORD);
                    }
                }
            }
        }

        delete[] todel;

        return true;
    }
    return false;
}

/*!
 * \brief remove_processed_file
 * \param file_name
 * \return
 *
 * LINUX/MACOS/WINDOWS
 */
bool remove_processed_file(QString file_name){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

#ifdef LINUX_OS
    QString command = "rm " + get_Results_directory() + file_name;
#endif
#ifdef MAC_OS
    QString command = "rm " + get_Results_directory() + file_name;
#endif
#ifdef WIN_OS
    QString command = "del /Q " + get_Results_directory() + file_name;
#endif

    int res = system(command.toStdString().c_str());

    if (res){
        return false;
    }

    return true;
}

/*!
 * \brief stroke_volume
 * \param coord
 * \return
 */
double stroke_volume(Coord coord){
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //int_{xmin}^{xmax}{abs(y)}

    int n = coord.size();
    double sv = 0.;

    for (int i = 1; i < n; i++){
        //Rectangle gauche
        //sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD))*qAbs(coord.coord(i-1, YCOORD));
        //Rectangle droite
        //sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD))*qAbs(coord.coord(i, YCOORD));
        //Trapèze
        sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD)) * (qAbs(coord.coord(i, YCOORD)) + qAbs(coord.coord(i-1, YCOORD)))/2.;
    }

    return sv/2.;
}

/*!
 * \brief stroke_volume_csf
 * \param coord
 * \return
 */
double stroke_volume_csf(Coord coord)
{
    if (DEBUG) cout << Q_FUNC_INFO << endl;

    //int_{xmin}^{xmax}{abs(y)}

    int n = coord.size();
    double sv = 0.;

    for (int i = 1; i < n; i++){
        //Rectangle gauche
        //sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD))*qAbs(coord.coord(i-1, YCOORD));
        //Rectangle droite
        //sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD))*qAbs(coord.coord(i, YCOORD));
        //Trapèze
        sv += (coord.coord(i, XCOORD)-coord.coord(i-1, XCOORD)) * (qAbs(coord.coord(i, YCOORD)) + qAbs(coord.coord(i-1, YCOORD)))/2.;
    }

    return sv/2.;
}

bool IsFlowAnalysisPatientDir(QString dir)
{
    //list Files
#ifdef LINUX_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef MAC_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef WIN_OS
    dir.replace("/", "\\");
    QString command = "dir /B /A:D \"" + dir + "\" > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif

    int res = system(command.toStdString().c_str());
    if (!res){
        //Read List
        QStringList exam_list;

        QFile file(QString(SYSTEM_DIR) + "ls1.txt");
        if (file.open(QIODevice::ReadOnly)){
            while(!file.atEnd()){
                QString tmp = file.readLine();
                tmp.remove("\r").remove("\n");
                exam_list.append(tmp);
            }

            //Verify dir
            bool ok = true;
            for (int i = 0; i < exam_list.size(); i++){
                exam_list.at(i).toLongLong(&ok);
                if (!ok){
                    if (exam_list.at(i).compare("NOID") == 0){
                        ok = true;
                    }
                }
            }

            return ok;
        }
        return false;
    }
    return false;
}


/*Flow num files*/
int GetFlowAnalysisNumFiles(QString dir)
{
    //list Files
#ifdef LINUX_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef MAC_OS
    QString command = "ls \'" + dir + "\' > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif
#ifdef WIN_OS
    dir.replace("/", "\\");
    QString command = "dir /B /A:D \"" + dir + "\" > " + QString(SYSTEM_DIR) + "ls1.txt\n";
#endif

    int res = system(command.toStdString().c_str());
    if (!res){
        //Read List
        QStringList exam_list;

        QFile file(QString(SYSTEM_DIR) + "ls1.txt");
        if (file.open(QIODevice::ReadOnly)){
            while(!file.atEnd()){
                QString tmp = file.readLine();
                tmp.remove("\r").remove("\n");
                exam_list.append(tmp);
            }

            //Count files in every exam number sub-directories
            bool ok = true;
            int max_num = -1;
            for (int i = 0; i < exam_list.size(); i++){
                exam_list.at(i).toLongLong(&ok);
                if (!ok){
                    if (exam_list.at(i).compare("NOID") == 0){
                        ok = true;
                    }
                }

                if (ok){
#ifdef LINUX_OS
                    QString command = "ls \'" + dir + DIR_SEPARATOR + exam_list.at(i) + "\' > " + QString(SYSTEM_DIR) + "ls2.txt\n";
#endif
#ifdef MAC_OS
                    QString command = "ls \'" + dir + DIR_SEPARATOR + exam_list.at(i) + "\' > " + QString(SYSTEM_DIR) + "ls2.txt\n";
#endif
#ifdef WIN_OS
                    dir.replace("/", "\\");
                    QString command = "dir /B \"" + dir + DIR_SEPARATOR + exam_list.at(i) + "\" > " + QString(SYSTEM_DIR) + "ls2.txt\n";
#endif

                    res = system(command.toStdString().c_str());
                    if (!res){
                        //Read list
                        QFile file2(QString(SYSTEM_DIR) + "ls2.txt");
                        if (file2.open(QIODevice::ReadOnly)){
                            int num = 0;
                            while(!file2.atEnd()){
                                QString tmp = file2.readLine();
                                if (tmp.contains(".txt")){
                                    num++;
                                }
                            }
                            max_num = max(max_num, num);
                        }
                    }
                }
            }

            return max_num;
        }
        return -1;
    }
    return -1;
}

bool unity_convert_flow(QVector<double> *xy, QString flow_unity, QString time_unity){
    int n = xy[0].size();

    if (n > 0){
        //Flow originally in mm3/s
        //Time originally in s

        if (flow_unity.compare(UNITY_MM3_S) == 0){
            //Nothing to do
        }
        else if (flow_unity.compare(UNITY_MM3_MIN) == 0){
            for (int i = 0; i < n; i++){
                xy[1][i] = xy[1][i] * 60.;
            }
        }
        else if (flow_unity.compare(UNITY_ML_S) == 0){
            for (int i = 0; i < n; i++){
                xy[1][i] = xy[1][i] * 1.e-3;
            }
        }
        else if (flow_unity.compare(UNITY_ML_MIN) == 0){
            for (int i = 0; i < n; i++){
                xy[1][i] = (xy[1][i] * 1.e-3) * 60.;
            }
        }

        if (time_unity.compare(UNITY_S) == 0){
            //Nothing to do
        }
        else if (time_unity.compare(UNITY_MIN) == 0){
            for (int i = 0; i < n; i++){
                xy[0][i] = xy[0][i] / 60.;
            }
        }

        return true;
    }
    return false;
}

void unity_convert_flow_data(double *min, double *max, double *mean, double *sv, QString flow_unity, QString volume_unity)
{
    if (flow_unity.compare(UNITY_MM3_S) == 0){
        //Nothing to do
    }
    else if (flow_unity.compare(UNITY_MM3_MIN) == 0){
        *min = *min * 60.;
        *max = *max * 60.;
        *mean = *mean * 60.;
    }
    else if (flow_unity.compare(UNITY_ML_S) == 0){
        *min = *min * 1.e-3;
        *max = *max * 1.e-3;
        *mean = *mean * 1.e-3;
    }
    else if (flow_unity.compare(UNITY_ML_MIN) == 0){
        *min = (*min * 1.e-3) * 60.;
        *max = (*max * 1.e-3) * 60.;
        *mean = (*mean * 1.e-3) * 60.;
    }

    if (volume_unity.compare(UNITY_MM3) == 0){
        //Nothing to do
    }
    else if (volume_unity.compare(UNITY_ML) == 0){
        *sv = *sv * 1.e-3;
    }
}

bool unity_convert_volume(QVector<double> *xy, QString volume_unity, QString time_unity)
{
    int n = xy[0].size();

    if (n > 0){
        //Volume originally in mm3
        //Time originally in s

        if (volume_unity.compare(UNITY_MM3) == 0){
            //Nothing to do
        }
        else if (volume_unity.compare(UNITY_ML) == 0){
            for (int i = 0; i < n; i++){
                xy[1][i] = xy[1][i] * 1.e-3;
            }
        }

        if (time_unity.compare(UNITY_S) == 0){
            //Nothing to do
        }
        else if (time_unity.compare(UNITY_MIN) == 0){
            for (int i = 0; i < n; i++){
                xy[0][i] = xy[0][i] / 60.;
            }
        }
        return true;
    }
    return false;
}

void unity_convert_volume_data(double *min, double *max, double *mean, QString volume_unity)
{
    if (volume_unity.compare(UNITY_MM3) == 0){
        //Nothing to do
    }
    else if (volume_unity.compare(UNITY_ML) == 0){
        *min = *min * 1.e-3;
        *max = *max * 1.e-3;
        *mean = *mean * 1.e-3;
    }
}
