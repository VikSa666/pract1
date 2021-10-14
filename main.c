/* 
 * File:   main.c
 * Author: victorsantiagoblanco
 *
 * Created on 21 de septiembre de 2021, 21:12
 */

#include <time.h>
#include "itMethods.h"

void executar_funcions(double **, double, int, double, double, int);
/*
 * 
 */
int main(void) {

    int i, j, k=0, n, iter_num, option;
    double **A,*b, *x, tol, h, w;
    
    // Llegim paràmetres 
    printf("Dimensió:");
    scanf("%d", &n);
    printf("La w per SOR:");
    scanf("%le", &w);
    
    // Guardem memòria, comptant amb la frontera també (per això n+2). 
    A = store_matrix(n+2, n+2);
    
    // Definim la h = 1/(N+1) 
    h = 1./(n+1);

    printf("Escriu el número de l'exercici que vols realitzar (1 o 2): \n");
    scanf("%d", &option);
    if(option != 1 && option != 2) {
        printf("%d no és una opció...\n", option);
        exit(1);
    }

    // Executem els mètodes canviant la tolerància
    tol = 1e-6;
    executar_funcions(A, tol, n, h, w, option);
    tol = 1e-8;
    executar_funcions(A, tol, n, h, w, option);
    tol = 1e-12;
    executar_funcions(A, tol, n, h, w, option);

    return 0;
}

// Funció auxiliar que ajuda a fer més àgil el procés d'executar tots els mètodes i escriure els resultats.
void executar_funcions(double **A, double tol, int n, double h, double w, int option) {
    
    double t, begin_t, end_t;
    int iter_num;

    printf("\n--------- Executant mètodes amb n = %d i tol = %.2le -------------\n", n, tol);
    
    // Fem Jacobi 
    omplir_zeros(n+2,A);
    begin_t = clock();
    valors_frontera(A, n, h, option);
    iter_num = metode_jacobi(n, A, tol, h, option);
    end_t = clock();
    t = (end_t-begin_t)/CLOCKS_PER_SEC;
    printf("\nJACOBI:\n");
    printf("El mètode de Jacobi ha estat implementat amb tolerància %.2le i amb els següents resultats:\n", tol);
    printf("Iteracions: %d.\n", iter_num);
    printf("Error real: %le.\n", error(A,n+2, h, option));
    printf("Temps: %f segons\n", t);
    
    // Fem Gauss-Seidel 
    omplir_zeros(n+2,A);
    valors_frontera(A, n, h, option);
    begin_t = clock();
    iter_num = metode_gauss_seidel(n, A, tol, option, h);
    end_t = clock();
    t = (end_t-begin_t)/CLOCKS_PER_SEC;
    printf("\nGAUSS-SEIDEL:\n");
    printf("El mètode de Gauss-Seidel ha estat implementat amb tolerància %.2le i amb els següents resultats:\n", tol);
    printf("Iteracions: %d.\n", iter_num);
    printf("Error real: %le.\n", error(A,n+2, h, option));
    printf("Temps: %f segons\n", t);
    
    // Fem SOR
    omplir_zeros(n+2,A);
    valors_frontera(A, n, h, option);
    begin_t = clock();
    iter_num = metode_sor(n, A,tol,option, w, h);
    end_t = clock();
    t = (end_t-begin_t)/CLOCKS_PER_SEC;
    printf("\nSOR:\n");
    printf("El mètode de SOR ha estat implementat amb tolerància %.2le, w = %.2le i amb els següents resultats:\n", tol, w);
    printf("Iteracions: %d.\n", iter_num);
    printf("Error real: %le.\n", error(A,n+2, h, option));
    printf("Temps: %f segons\n", t);

    // Fem gradient conjugat
    omplir_zeros(n+2,A);
    valors_frontera(A, n, h, option);
    begin_t = clock();
    iter_num = metode_gradients_conjugats(A, tol, n, h, option);
    end_t = clock();
    t = (end_t-begin_t)/CLOCKS_PER_SEC;
    printf("\nGRADIENTS CONJUGATS:\n");
    printf("El mètode de Gradients Conjugats ha estat implementat amb tolerància %.2le i amb els següents resultats:\n", tol);
    printf("Iteracions: %d.\n", iter_num);
    printf("Error real: %le.\n", error(A,n+2, h, option));
    printf("Temps: %f segons\n", t);
}





