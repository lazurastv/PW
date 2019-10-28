#ifndef _BIBL_H_                /* zabezpieczenie przed wielokrotnym
                                 * wlaczeniem tego pliku */
#define _BIBL_H_

#include <stdio.h>

#define Size 10

/* Prototypy funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu format wektora to
 * <liczba_elementow> [ <element> ... ] np. 3 [ 1.2 4.5, 7.8]
 */
int             read(FILE * p, double v[], int max_l_e);

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double           L2(double v[], int n);

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double           dot_product(double v[], double u[], int n);

double norma_max(double v[], int n);

void add_v(double v[], double u[], double w[], int n);

void normlizacja(double v[], double w[], int n, double l2);

void mno_przez_licz(double v[], double w[], int n, double m);

void write_vector(double v[], int n, FILE *out);

#endif
