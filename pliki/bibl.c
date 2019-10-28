#include "bibl.h"              

#include <math.h>               /* dzieki temu kompilator sprawdzi, czy
                                 * dobrze uzywamy funkcji sqrt */      

/* Definicje funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe             
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu                  
 *                                                                           
 * Format wektora w pliku - np.:  5 [ 0.1 1.2 2.3 3.4 4.5 ]                  
 */                                                                          
int                                                                          
read(FILE * p, double v[], int max_l_e)                                      
{                                                                            
        int             n, i;                       

        if (fscanf(p, "%i", &n) != 1 || n <= 0 || n > max_l_e) {
                return -1;
        }
        while ((i = fgetc(p)) == ' ');

        if (i != '[')
                return -1;

        for (i = 0; i < n; i++)
                if (fscanf(p, "%lf", &(v[i])) != 1)
                        return -1;

        while ((i = fgetc(p)) == ' ');

        if (i != ']')
                return -1; 


        return n;
}

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double
L2(double v[], int n)
{
        int             i;
        int             l2 = 0; /* wazne jest, aby nadac l2 wartosc
                                 * poczatkowa */
        for (i = 0; i < n; i++)
                l2 += v[i] * v[i];
        return sqrt(l2);
}

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double
dot_product(double v[], double u[], int n)
{
        int             i;
        double           dp = 0; /* wazne jest, aby nadac dp wartosc
                                 * poczatkowa */
        for (i = 0; i < n; i++)
                dp += v[i] * u[i];
        return dp;
}

double norma_max(double v[], int n)
{
    double  u[Size];
    int i;
	double max;

	for (i = 0; i < n; i++)
		u[i] = fabs( v[i] );

	max = u[0];

	for (i = 1; i < n; i++)
		if ( u[i] > max ) max = v[i];

	return max;
}

void add_v(double v[], double u[], double w[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		w[i] = u[i] + v[i];

}

void normlizacja(double v[], double w[], int n, double l2)
{
        int i;
        for (i = 0; i < n; i++)
        {
                w[i] = v[i] / l2;
        }
}

void mno_przez_licz(double v[], double w[], int n, double m)
{
        int i;
        for (i = 0; i < n; i++)
        {
                w[i] = m * v[i];               
        }
}

void write_vector(double v[], int n, FILE *out)
{
        int i;
        fprintf( out, "( ");
        for (i = 0; i < n; i++)
            fprintf(out, "%f ", v[i]);
        fprintf(out, ")\n");
}
