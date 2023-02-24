#ifndef _LINEAR_ALGEBRA_H
#define _LINEAR_ALGEBRA_H

enum axis{
    x_,
    y_,
    z_
};

typedef struct Vector{
    double *s;
    int n;
}Vector;

typedef struct Matrix{
    int m;  // column
    int n;  // row
    double **data;
}Matrix;

Vector *create_vector(int s, ...);
void destroy_vector(Vector *);
void v_scale(Vector *, int);
void v_normalise(Vector *);
void v_add(Vector *, Vector *);
void v_subtract(Vector *, Vector *);

void transform(Vector *, Matrix *);

#endif