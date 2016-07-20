#ifndef COORD_H
#define COORD_H

#include <iostream>
using namespace std;

#include "TextDef.h"
#include "TextDef__Error.h"


/*!
 * \brief The Coord class
 *
 * This class contains one integer n and two vector of size n.
 *
 * That represents coordiantes of 2 dimensional vector (matrix).
 */
class Coord
{
public:
    Coord();
    Coord(int in_n, double *in_x, double *in_y);

    void set_size(int in_n);
    void set_coord(double val, int i, char type);
    void set_coords(double *in_x, double *in_y);

    int size();
    double coord(int i, char type);
    double *coords(char type);

    void clear();
    void multiply(char type, double a);
    void sort(char type);

private:
    int n;
    double *x;
    double *y;
};

#endif // COORD_H
