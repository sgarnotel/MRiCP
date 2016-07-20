//roesttacode.org

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { double x, y; int group; } point_t, *point;

double randf(double m)
{
    return m * rand() / (RAND_MAX - 1.);
}

point gen_xy(double *x, double *y, int n){
    int i = 0;
    point p, pt = (point)malloc(sizeof(point_t) * n);

    for (p = pt + n; p-- > pt;) {
        p->x = x[i];
        p->y = y[i];
        i++;
        /*printf("%d\n", i);*/
    }

    return pt;
}

inline double dist2(point a, point b)
{
    double x = a->x - b->x, y = a->y - b->y;
    return x*x + y*y;
}

inline int
nearest(point pt, point cent, int n_cluster, double *d2)
{
    int i, min_i;
    point c;
    double d, min_d;

#	define for_n for (c = cent, i = 0; i < n_cluster; i++, c++)
    for_n {
        min_d = HUGE_VAL;
        min_i = pt->group;
        for_n {
            if (min_d > (d = dist2(c, pt))) {
                min_d = d; min_i = i;
            }
        }
    }
    if (d2) *d2 = min_d;
    return min_i;
}

void kpp(point pts, int len, point cent, int n_cent)
{
#	define for_len for (j = 0, p = pts; j < len; j++, p++)
    int i, j;
    int n_cluster;
    double sum, *d = (double*)malloc(sizeof(double) * len);

    point p, c;
    cent[0] = pts[ rand() % len ];

    for (n_cluster = 1; n_cluster < n_cent; n_cluster++) {
        sum = 0;
        for_len {
            nearest(p, cent, n_cluster, d + j);
            sum += d[j];
        }
        sum = randf(sum);
        for_len {
            if ((sum -= d[j]) > 0) continue;
            cent[n_cluster] = pts[j];
            break;
        }
    }

    for_len p->group = nearest(p, cent, n_cluster, 0);
    free(d);
}

point lloyd(point pts, int len, int n_cluster)
{
    int i, j, min_i;
    int changed;

    point cent = (point)malloc(sizeof(point_t) * n_cluster), p, c;

    /* assign init grouping randomly */
    //for_len p->group = j % n_cluster;

    /* or call k++ init */
    kpp(pts, len, cent, n_cluster);

    do {
        /* group element for centroids are used as counters */
        for_n { c->group = 0; c->x = c->y = 0; }
        for_len {
            c = cent + p->group;
            c->group++;
            c->x += p->x; c->y += p->y;
        }
        for_n { c->x /= c->group; c->y /= c->group; }

        changed = 0;
        /* find closest centroid of each point */
        for_len {
            min_i = nearest(p, cent, n_cluster, 0);
            if (min_i != p->group) {
                changed++;
                p->group = min_i;
            }
        }
    } while (changed > (len >> 10)); /* stop when 99.9% of points are good */

    for_n { c->group = i; }

    return cent;
}

int *clustering(int PTS, double *a, double *b, int K)
{
    point v = gen_xy(a, b, PTS);
    point c = lloyd(v, PTS, K);

    int *group = new int[PTS];
    for (int i = 0; i < PTS; i++){
        group[i] = v[i].group;
    }
    return group;
}
