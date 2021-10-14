/*
 * Funcions auxiliars que poden ser útils per a fer els mètodes iteratius,
 * com ara per exemple un que inicialitza la matriu.
 * 
 * NOTA: moltes d'aquestes funcions són reutilitzades d'altres programes
 * de Mètodes Numèrics II. Amb la qual cosa, potser hi ha funcions que no
 * utilitzaré.
 */



#include "functions.h"
#include "mave.h"

/* Funció per guardar els valors de la frontera directament */
void valors_frontera(double **A, int n, double h, int option) {
    int i;
    for (i = 0; i < n+2; i++) {
        A[i][0] = g(i*h,0, option);
        A[0][i] = g(0,i*h, option);
        A[i][n+1] = g(i*h,1, option);
        A[n+1][i] = g(1,i*h, option);
    }
}

/* Funció per calcular el producte segons el nostre mètode */
void producte_metodes(double **p, double **x, int dim) {
	int i, j;
	
	for(i=1; i<dim+1; i++) 
        for(j=1; j<dim+1; j++)
			x[i][j] = -p[i-1][j] - p[i+1][j] - p[i][j-1] - p[i][j+1] + 4*p[i][j];
}

/* Funció per calcular l'error a l'exercici option. */
double error(double **A, int n, double h, int option) {
    int i, j;
    double error = 0.;
    for(i = 0; i < n; i++) 
        for(j = 0; j < n; j++) 
            if(fabs(A[i][j] - g(i*h, j*h, option)) > error) error = fabs(A[i][j] - g(i*h, j*h, option));
    
    return error;
}