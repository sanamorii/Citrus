#ifndef _LA_MATHS_H
#define _LA_MATHS_H

enum axis{
    x_,
    y_,
    z_
};

typedef struct Vector{
    double *space;
    int size;
}Vector;

typedef struct Matrix{
    int m;  // column
    int n;  // row
    double **data;
}Matrix;

Vector *create_vector(int s);
void destroy_vector(Vector *);
void v_scale(Vector *, int);
void v_normalise(Vector *);



#endif