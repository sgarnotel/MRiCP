#include "coord.h"

//Constructor
/*!
 * \brief Coord::Coord
 *
 * Empty constructor of a Coord.
 */
Coord::Coord()
{
    if (DEBUG > 100) cout << "Coord::Coord()"<< endl;

    n = 0;
    x = NULL;
    y = NULL;
}

/*!
 * \brief Coord::Coord
 * \param n size of Coord
 * \param x x vector (size n)
 * \param y y vector (size n)
 *
 * Full constructor of a Coord.
 */
Coord::Coord(int n, double *x, double *y)
{
    if (DEBUG > 100) cout << "Coord::Coord(int n, double *x, double *y)" << endl;

    this->n = n;
    if (n > 0){
        this->x = new double[n];
        this->y = new double[n];
        for (int i = 0; i < n; i++){
            this->x[i] = x[i];
            this->y[i] = y[i];
        }
    }
}

/*!
 * \brief Coord::set_size
 * \param n size of Coord
 *
 * Partial constructor of a Coord. x and y are set to zero.
 */
void Coord::set_size(int n)
{
    if (DEBUG > 100) cout << "void Coord::set_size(int n)" << endl;

    this->n = n;

    if (x != NULL){
        delete[] x;
        x = NULL;
    }
    if (y != NULL){
        delete[] y;
        y = NULL;
    }

    if (n > 0){
        x = new double[n];
        y = new double[n];

        for (int i = 0; i < n; i++){
            x[i] = 0.;
            y[i] = 0.;
        }
    }
}

/*!
 * \brief Coord::set_coord
 * \param val value
 * \param i position
 * \param type XCOORD or YCOORD
 *
 * Set coordinate in position i of vector type of a Coord.
 */
void Coord::set_coord(double val, int i, char type)
{
    if (DEBUG > 100) cout << "void Coord::set_coord(double val, int i, char type)" << endl;

    if (i >= n){
        cout << "Coord::set_coord " << COORD_ERROR_001 << endl;
        cout << "n = " << n << ", i = " << i << endl;
    }
    if (type == XCOORD){
        x[i] = val;
    }
    else if (type == YCOORD){
        y[i] = val;
    }
    else{
        cout << "Coord::set_coord " << COORD_ERROR_002 << endl;
        cout << "type = " << type << endl;
    }
}

/*!
 * \brief Coord::set_coords
 * \param x vector x (at least size n)
 * \param y vector y (at least size n)
 *
 * Set coordinates of a Coord.
 */
void Coord::set_coords(double *x, double *y)
{
    if (DEBUG > 100) cout << "void Coord::set_coords(double *x, double *y)" << endl;

    if (n <= 0){
        cout << "Coord::set_coords " << COORD_ERROR_003 << endl;
    }
    else{
        if (this->x != NULL){
            delete[] this->x;
            this->x = NULL;
        }
        if (this->y != NULL){
            delete[] this->y;
            this->y = NULL;
        }

        this->x = new double[n];
        this->y = new double[n];
        for (int i = 0; i < n; i++){
            this->x[i] = x[i];
            this->y[i] = y[i];
        }
    }
}

/*!
 * \brief Coord::size
 * \return size of Coord
 *
 * Get the size of a Coord.
 */
int Coord::size()
{
    if (DEBUG > 100) cout << "int Coord::size()" << endl;

    return n;
}

/*!
 * \brief Coord::coord
 * \param i position
 * \param type XCOORD or YCOORD
 * \return coordinate i of vector type
 *
 * Get coordinate in position i of the vector type of a Coord.
 */
double Coord::coord(int i, char type)
{
    if (DEBUG > 100) cout << "double Coord::coord(int i, char type)" << endl;

    if (i >= n){
        cout << "Coord::coord " << COORD_ERROR_001 << endl;
        cout << "n = " << n << ", i = " << i << endl;
        return 0.;
    }
    if (type == XCOORD){
        return x[i];
    }
    else if (type == YCOORD){
        return y[i];
    }
    else{
        cout << "Coord::coord " << COORD_ERROR_002 << endl;
        cout << "type = " << type << endl;
        return 0.;
    }
}

/*!
 * \brief Coord::coords
 * \param type XCOORD or YCOORD
 * \return vector type
 *
 * Get vector type of a Coord.
 */
double *Coord::coords(char type)
{
    if (DEBUG > 100) cout << "double *Coord::coords(char type)" << endl;

    if (type == XCOORD){
        double *out_x = new double[n];
        for (int i = 0; i < n; i++){
            out_x[i] = x[i];
        }
        return out_x;
    }
    else if (type == YCOORD){
        double *out_y = new double[n];
        for (int i = 0; i < n; i++){
            out_y[i] = y[i];
        }
        return out_y;
    }
    else{
        cout << "Coord::coords " << COORD_ERROR_002 << endl;
        cout << "type = " << type << endl;
        return NULL;
    }
}

/*!
 * \brief Coord::clear
 *
 * Clear a Coord.
 */
void Coord::clear()
{
    if (DEBUG > 100) cout << "void Coord::clear()" << endl;

    if (x != NULL){
        delete[] x;
        x = NULL;
    }
    if (y != NULL){
        delete[] y;
        y = NULL;
    }
    n = 0;
}

/*!
 * \brief Coord::multiply
 * \param type XCOORD or YCOORD
 * \param a multiply parameter
 *
 * Multiply vector type by a of a Coord.
 */
void Coord::multiply(char type, double a)
{
    if (DEBUG > 100) cout << "void Coord::multiply(char type, double a)" << endl;

    if (n > 0){
        if (type == XCOORD){
            for (int i = 0; i < n; i++){
                x[i] = x[i] * a;
            }
        }
        else if (type == YCOORD){
            for (int i = 0; i < n; i++){
                y[i] = y[i] * a;
            }
        }
        else{
            cout << "Coord::multiply" << COORD_ERROR_002 << endl;
            cout << "type = " << type << endl;
        }
    }
}

/*!
 * \brief Coord::sort
 * \param type
 */
void Coord::sort(char type)
{
    if (DEBUG > 100) cout << "void Coord::sort(char type)" << endl;

    if (type == XCOORD){
        for (int i = 0; i < n; i++){
            int ordered = 1;
            for (int j = 1; j < n-i; j++){
                if (x[j-1] < x[j]){
                    double x_tmp = x[j-1];
                    x[j-1] = x[j];
                    x[j] =x_tmp;

                    double y_tmp = y[j-1];
                    y[j-1] = y[j];
                    y[j] = y_tmp;

                    ordered = 0;
                }
            }
            if (ordered == 1){
                break;
            }
        }
    }
    else if (type == YCOORD){
        for (int i = 0; i < n; i++){
            int ordered = 1;
            for (int j = 1; j < n-i; j++){
                if (y[j-1] > y[j]){
                    double y_tmp = y[j-1];
                    y[j-1] = y[j];
                    y[j] = y_tmp;

                    double x_tmp = x[j-1];
                    x[j-1] = x[j];
                    x[j] =x_tmp;

                    ordered = 0;
                }
            }
            if (ordered == 1){
                break;
            }
        }
    }
    else{
        cout << "Coord::sort" << COORD_ERROR_002 << endl;
        cout << "type = " << type << endl;
    }
}


