/* 
 * File: itMethods.h
 * Author: Víctor Santiago Blanco
 * NIUB: 20046541
 * GitHub: https://github.com/VikSa666/pract1
 *
 * Created on 21 de septiembre de 2021, 21:12
 */


#include "auxMethods.h"


int metode_jacobi(int n, double **A, double tol, double h, int option) {
    int i, j, it_num = 0;
    double **xx, **aux, norma = 10;
    
    /* Guardem memòria per a la matriu auxiliar */
    xx = store_matrix(n+2, n+2);
    
    /* Guardem la frontera en l'auxiliar */
    valors_frontera(xx, n, h, option);
    
    /* Comencem iteracions de Jacobi */
    /* La variable norma s'ha preinicialitzat a un valor alt arbitrari */
    while(norma >= tol) {
        
        for(i = 1; i < n + 1; i++)
            for(j = 1; j < n + 1; j++)
                xx[i][j] = (1./4)*(A[i-1][j] + A[i+1][j] + A[i][j+1] + A[i][j-1] + h*h*f(h*i,h*j, option));
        
        norma = normainf_matrix(A,xx,n+2);
        aux = xx;
        xx = A;
        A = aux;
        it_num++;
    }
    
    for(i = 0; i < n+1; i++) free(xx[i]);
    free(xx);
    return it_num;
}



/* SOR */

int metode_sor(int n, double **A, double tol, int option, double w, double h) {
    int i, j, k, it_num = 0;
    double norma = 1, error;
    
    /* Aquí no necessito una matriu auxiliar, només un paràmetre. */
    /* NOTA: necessito inicialitzar la norma més gran que la tolerància 
     ja que sinó no entrarà al while-loop. Aleshores, un cop dins, li assigno
     el valor zero ja que sino mai sortim del bucle perquè mai entrem al if que
     assigna a la norma l'error màxim. */
    
    while(norma >= tol) {
        norma = 0;
        for(i = 1; i < n+1; i++) {
            for(j = 1; j < n+1; j++) {
                error = A[i][j];
                A[i][j] += w*(1./4)*(A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1] - 4*A[i][j] + h*h*f(h*i,h*j, option));
                error = fabs(error-A[i][j]);
                if(error > norma) norma = error;
            }
        }
        it_num++;
    }
    return it_num;
}


/* GAUSS-SEIDEL (sor amb w = 1) */

int metode_gauss_seidel(int n, double **A, double tol, int option, double h) {
    return metode_sor(n, A, tol, option, 1, h);
}



int metode_gradients_conjugats(double **A, double tol, int n, double h, int option) {
	int i, j, it_num = 0;
	double 	**p, **q, **r;
	double	alpha, beta, norma_pre, norma_post;
        
    p = store_matrix(n+2, n+2);
    q = store_matrix(n+2, n+2);
    r = store_matrix(n+2, n+2);
        
	producte_metodes(A, r, n); /* Guardo A·r en r */
	/* Iteració nº 0: */
    for(j = 1; j < n+1; j++) {
		for(i = 1; i < n+1; i++) {
			r[i][j] = h*h*f(h*i,h*j, option) - r[i][j];
			p[i][j] = r[i][j]; 
		}
	}

	do
	{
        producte_metodes(p, q, n); /* Now q = A·p, and p remains p. */
        norma_pre = producte_escalar_vectors_matriu(r, r, n+2); /* Així ens estalviem aquest càlcul dos cops. */
		alpha = (-1.*norma_pre)/producte_escalar_vectors_matriu(p, q, n+2); /* p^T·A·p en el denominador. */

        /* Actualitzem els valors de A i de r en la iteració k+1 */
		for(j = 1; j < n+1; j++) {
			for(i = 1; i < n+1; i++) {
				A[i][j] -= alpha*p[i][j];
				r[i][j] += alpha*q[i][j];
			}
		}

		norma_post = producte_escalar_vectors_matriu(r,r,n+2); /* Calculem ara la norma després de l'actualització per poder calcular la beta. */
		beta = norma_post/norma_pre; /* Calculem la beta. */

        /* Amb la beta calculada, actualitzem el valor de p en la iteració k+1 */
		for(i=1; i<n+1; i++)
			for(j=1; j<n+1; j++)
				p[i][j] = r[i][j] + beta*p[i][j];

		it_num++; /* Acumulem el número d'iteracions. */
	} while(norma_post >= tol*tol); /* Condició de sortida del propi mètode. */

	return it_num;
}


