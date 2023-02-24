test_speed.out: main.o speed_print.o cpucycles.o genmatrix.o
	gcc main.o speed_print.o cpucycles.o genmatrix.o -o test_speed.out

main.o: main.c main.h
	gcc main.c -c

genmatrix.o: genmatrix.c genmatrix.h
	gcc genmatrix.c -c

speed_print.o: speed_print.c speed_print.h
	gcc speed_print.c -c

cpucycles.o: cpucycles.c cpucycles.h
	gcc cpucycles.c -c

clean: 
	rm -f main.o speed_print.o cpucycles.o genmatrix.o test_speed.out