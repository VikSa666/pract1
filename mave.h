#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Arxiu que conté totes les funcions d'operacions i coses amb matrius */

/* Funció per guardar memòria d'una matriu */
double **store_matrix(int rows, int cols) {
    int i;
    double **matrix;

    matrix = (double**)calloc(rows, sizeof(double*));
    if (matrix == NULL) {
        printf("Error en guardar memòria.\n");
        exit(1);
    }
    for(i = 0; i < cols; i++) {
        matrix[i] = (double*)calloc(cols, sizeof(double));
        if(matrix[i] == NULL) {
            printf("Error en guardar memòria.\n");
            exit(1);
        }
    }

    return matrix;
}

/* Funció per guardar memòria d'un vector */
double *store_vector(int dim) {
    double *vector;
    vector = (double*)calloc(dim, sizeof(double));
    if(vector == NULL) {
        printf("Error en guardar memòria.\n");
        exit(1);
    }
    return vector;
}

/* Funció per alliberar memòria d'una mariu. */
void free_matrix(double** matrix, int cols) {
    int i;
    for (i = 0; i < cols; i++) free(matrix[i]);
    free(matrix);
}

/* Funció per calcular el producte escalar d'un vector per un altre */
double producte_escalar_vectors(double *u, double *v, int n) {
    int i;
    double prod = 0.;
    for(i = 0; i < n; i++) prod+=u[i]*v[i];
    return prod;
}

/* Funció que calcula el producte d'una matriu A per un vector v i guarda el resultat en v. */
void producte_matriu_vector(double **A, double *v, int n) {
    int i, j;
    double prod = 0.;
    double *res;
    
    res = store_vector(n);
    
    for(i = 0; i < n; i++) for(j = 0; j < n; j++) res[i] += A[i][j]*v[j];
    
    for(i = 0; i < n; i++) v[i] = res[i];
    free(res);
}

/* Funció que calcula el producte escalar de dos vectors guardats en forma de matriu, */
/* i.e. en comptes de tenir un vector de N^2 components, tinc una matriu NxN. */
double producte_escalar_vectors_matriu(double **u, double **v, int n) {
    int i, j;
    double prod = 0.;

    for(i = 0; i < n; i++) for(j = 0; j < n; j++) prod += u[i][j]*v[i][j];
    return prod;
}

/* Funció que omple un vector de zeros, per anar més ràpid... */
void omplir_zeros(int n, double **A) {
    int i, j;
    for(i = 0; i < n; ++i) 
        for(j = 1; j < n-1; j++) 
            A[i][j] = 0;
}

/* Funció que simplement imprimeix la matriu de forma ordenada. No l'utilitzo al programa però l'he fet servir per fer proves. */
void print_matrix(double **A, int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%.4e ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Funció per calcular la norma infinit d'un vector. */
double normainf(double *x, int n) {
    double max;
    int i;
    max = fabs(x[0]);
    for(i = 0; i < n; i++) {
        if(fabs(x[i]) > max)
            max = fabs(x[i]);
    }
    return max;
}

/* Funció per calcular la norma infinit de la resta de dues matrius*/
double normainf_matrix(double**A, double**B, int n) {
    int i, j;
    double norma = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(fabs(A[i][j] - B[i][j]) > norma) {
                norma = fabs(A[i][j] - B[i][j]);
            }
        }
    }
    
    return norma;
}

