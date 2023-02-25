#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "citrus_maths/linear.h"

Vector *create_vector(int s, ...){

    Vector *ve = (Vector *) malloc(sizeof(Vector));
    double *xs = (double *) calloc(s, sizeof(double));

    va_list ptr;
    va_start(ptr, s);

    for(int i = 0; i<s; i++)
        xs[i] = va_arg(ptr, double);
     va_end(ptr);

    ve->s = xs;
    ve->n = s;

    return ve;
}

void destroy_vector(Vector *ve){
    free(ve->s);
    free(ve);
}

void v_scale(Vector *ve, int scalar){
    for (int i = 0; i<ve->n; i++)
        ve->s[i] *= scalar;
}

void v_normalise(Vector *ve){
    double length = 0;
    
    for (int i = 0; i < ve->n; i++)
        length += (ve->s[i] * ve->s[i]);
    length = sqrt(length);
    // length = length==0 ? 1 : length;
    for(int i = 0; i < ve->n; i++)
        if(length == 0){
            ve->s[i] = 0;
        }
        else{
            ve->s[i] /= length;
        }
}

void v_add(Vector *v1, Vector *v2){
    if(v1->n != v2->n){
        fprintf(stderr, "fatal: addition of invalid sized vectors (v1->n: %f, v2->n: %f)\n", v1->n, v2->n);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<v1->n; i++){ 
        v1->s[i] += v2->s[i]; }
}

void v_subtract(Vector *v1, Vector *v2){
    if(v1->n != v2->n){
        fprintf(stderr, "fatal: subtraction of invalid sized vectors (v1->n: %f, v2->n: %f)\n", v1->n, v2->n);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i<v1->n; i++){ 
        v1->s[i] -= v2->s[i]; }
}


int is_zero(Vector *v){
    int flag = 0;
    for(int i = 0; i<v->n; i++){
        if (v->s[i] != 0.0)
            flag++;
    }

    return flag ? 0 : 1;
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

/*  */
void transform(Vector *ve, Matrix *ma){
    if (!(ma->m<=2 && ma->n<=2)){
        fprintf(stderr, "fatal: invalid matrix given - 2x2 matrix only.\n");
    }
    
}
