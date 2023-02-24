#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "tools/linear.h"

Vector *create_vector(int s){

    Vector *ve = (Vector *) malloc(sizeof(Vector));
    double *xs = (double *) calloc(s, sizeof(double));

    for(int i = 0; i<s; i++)
        xs[i] = 0.0;

    ve->space = xs;
    ve->size = s;

    return ve;
}

void destroy_vector(Vector *ve){
    free(ve->space);
    free(ve);
}

void v_scale(Vector *ve, int scalar){
    for (int i = 0; i<ve->size; i++)
        ve->space[i] *= scalar;
}

void v_normalise(Vector *ve){
    double length = 0;
    
    for (int i = 0; i < ve->size; i++)
        length += (ve->space[i] * ve->space[i]);
    length = sqrt(length);
    for(int i = 0; i < ve->size; i++)
        ve->space[i] /= length;
}

void transform(Vector *ve, Matrix *ma){
    NULL;
}


Matrix *create_matrix(int m, int n){
    Matrix *ma = (Matrix *) malloc(sizeof(Matrix));
    double **data;

    data = (double **) calloc(m, sizeof(double *));
    for (int i = 0; i < m; i++){
        data[i] = (double *) calloc(n, sizeof(double));
        for (int j = 0; j<n; j++){ data[i][j] = 0.0; }
    }

    ma->m = m;
    ma->n = n;
    ma->data = data;

    return ma;
}

