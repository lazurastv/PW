#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB
#define MAXSIZE 100000

int cmp ( const void *d, const void *e)
{
	char **cd = (char**)d;
	char **ce = (char**)e;
	return strcmp( *cd, *ce );
}

int
main( int argc, char **argv ) {
	  int ile_linii;
	    char buf[BUFSIZE];

	    char *a;
	    int b = argc-2;
		int ln[b];

		for (int m = 0; m < b; m++)
		{
			a = *(argv+2+m);
			ln[m] = atoi(a);
		}


	        FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

		FILE *out = fopen( ".memory", "w" );

		if ( argc == 1)
		{
			printf("Sposób użycia: a.exe [nazwa pliku] [linia n] [linia m] ...\n");
			return EXIT_FAILURE;
		}

		  if( argc < 3 && argc != 1 ) {
			      fprintf( stderr, "Proszę podać linie do wczytania.\n");
			          return EXIT_FAILURE;
				    }

		    if( in == NULL ) {
			        fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[2] );
				    return EXIT_FAILURE;
				      }

		      ile_linii= 0;
		      char *cp[MAXSIZE];
		      int s = 0;
		        while( fgets( buf, BUFSIZE, in ) != NULL ) {
				    ile_linii++;
				        for (int i = 0; i < b; i++)
					{
						if (ile_linii == ln[i])
						{
						      fprintf( out, "%s", buf );
//	ta część nie działa			      strcpy ( cp[s], buf);
							      s++; 
						}
					}
			}

/*			qsort( cp, s, sizeof *cp, cmp);

to zależy od *cp	for (int i = 0; i < s; i++)
				printf ("%s", cp[i]);
*/
			  return EXIT_SUCCESS;
}
