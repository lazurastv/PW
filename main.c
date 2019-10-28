#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibl.h"

int
main(int argc, char *argv[])
{
        double          w_1[Size];
        double          w_2[Size];
        double          tempv[Size];     /*chroni przed zmiana wartosci w oryginale(pojemnik na wyniki)*/
        double          templ2;          /* do pezechowania wartosci normy L2 */
        double          multiplier;
        int             n1;
        int             n2;

        FILE           *we, *wy;

        /*---------------------wczytanie nazw plikow i warosci "mnoznika"----------------------------*/

	    if (argc > 1 && strcmp(argv[1], "-")) /* wpisujemy myslnik gdy pobieramy dane z konsoli*/
		    we = fopen(argv[1], "r");
	    else 
		    we = stdin;

        if (argc > 2 && strcmp(argv[2], "-")) /* wpisujemy myslnik gdy wypisuje dane na konsole*/
		    wy = fopen(argv[2], "w");
	    else 
		    wy = stdout;

        multiplier = argc > 3 ? atof( argv[3]) : 2; /* pobiera mnoznik z konsoli */
                                                    /* jesli go nie ma pryjmuje wartosc domyslna 2*/


        /*-------------------------------sprawdzenie piliow------------------------------------*/

        if (we == NULL) {       /* stdin != NULL, a wiec to mozliwe tylko,
                                 * gdy argv[1] zawiera cos, co nie jest nazwa
                                 * istniejacego pliku */
                fprintf(stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
                exit(1);
        }

        if (wy == NULL) {       /* sprawdam czy mam prawa zapisu do pliku */
                fprintf(stderr, "Plik wyjsciowy %s (prawdopodobnie) jest preznaczony tylko do odczytu!\n", argv[2]);
                exit(1);
        }

        /*---------------------------------Wektor   1  ---------------------------------------*/
         
        n1 = read(we, w_1, Size);   /* czytamy z wejscia wektor i pakujemy go
                                 * do w_1 */

        if (n1 > 0) {
                fprintf( wy, "Wczytano %i-elementowy wektor:\n", n1);
                write_vector(w_1, n1, wy);
        } else {
                fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n1);
                return 1;
        }

        templ2 = L2(w_1, n1);
        fprintf(wy, "Norma L2 wczytanego wektora = %f\n", templ2);
	    fprintf(wy, "Norma maximum wczytanego wektora = %f\n", norma_max(w_1, n1));
        fprintf(wy, "Normalizacja wektora za pomaca normy L2: ");
        normlizacja(w_1, tempv, n1, templ2);
        write_vector(tempv, n1, wy);
        fprintf(wy, "Wektor pomnozony przez %lf: ", multiplier);
        mno_przez_licz(w_1, tempv, n1, multiplier);
        write_vector(tempv, n1, wy);


        /*---------------------------------Wektor   2 -----------------------------------*/                

        n2 = read(we, w_2, Size);   /* czytamy z wejscia wektor i pakujemy go
                                 * do w_2 */

        if (n2 > 0) {
                fprintf(wy, "Wczytano %i-elementowy wektor:\n", n2);
                write_vector(w_2, n2, wy);
        } else {
                fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n2);
                return 1;
        }

        templ2 = L2(w_2, n2);
        fprintf(wy, "Norma L2 wczytanego wektora = %f\n", templ2);
	    fprintf(wy, "Norma maximum wczytanego wektora = %f\n", norma_max(w_2, n2));
        fprintf(wy, "Normalizacja wektora za pomaca normy L2:");
        normlizacja(w_2, tempv, n2, templ2);
        write_vector(tempv, n2, wy);
        fprintf(wy, "Wektor pomnozony przez %lf: ", multiplier);
        mno_przez_licz(w_2, tempv, n2, multiplier);
        write_vector(tempv, n2, wy);

        /*-------------------------Dziaania dodawania i mnozenia--------------------------------*/

        if (n1 == n2 ) {
                fprintf(wy, "Iloczyn skalarny wczytanych wektorow = %f\n", dot_product(w_1, w_2, n1));
                fprintf(wy, "Suma wektorów: ");
		        add_v(w_1, w_2, tempv, n1);
                write_vector(tempv, n1, wy);
        } else {
                fprintf(wy, "Wczytane wektory maja rozna dlugosci i nie mozna ich pomnozyc przez siebie, ani dodać.\n" );
        }

        fclose(we);         /*zamkniecie plikow */
        fclose(wy);

        return 0;
}
