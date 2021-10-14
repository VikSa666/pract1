/* 
 * File:   functions.h
 * Author: victorsantiagoblanco
 *
 * Created on 22 de septiembre de 2021, 20:47
 */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* EXERCICI 1 */
double f(double x, double y, int option) {
    switch (option) {
        case 1: return 0.;
            break;
        case 2: return -6*(x+y);
            break;
    }
    return 0;
}

double g(double x, double y, int option) {
    switch (option) {
        case 1: return 1.;
            break;
        case 2: return x*x*x + y*y*y;
            break;
    }
    return 0;
}

/* EXERCICI 2 */

/*
double f(double x, double y) {
    return -6*(x+y);
}

double g(double x, double y) {
    return x*x*x + y*y*y;
}
 */

