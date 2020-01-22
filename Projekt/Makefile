COPT = -ggdb -DDEBUG

aprox: main.o splines.o points.o aproksymator_na_bazie.o Gauss/libge.a
	$(CC) $(COPT) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L Gauss -l ge 

aproksymator_na_bazie.o: makespl.h points.h Gauss/piv_ge_solver.h
	$(CC) $(COPT) -I Gauss -c aproksymator_na_bazie.c 

.PHONY: clean

clean:
	-rm *.o aprox
