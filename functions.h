/* 
 * File:   functions.h
 * Author: victorsantiagoblanco
 *
 * Created on 22 de septiembre de 2021, 20:47
 */



#include <stdio.h>
/* 
 * File: functions.h
 * Author: Víctor Santiago Blanco
 * NIUB: 20046541
 * GitHub: https://github.com/VikSa666/pract1
 *
 * Created on 21 de septiembre de 2021, 21:12
 */

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

