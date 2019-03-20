main: main.o print.o
	gcc main.o print.o -o main
    
main.o: main.c print.h
	gcc -Wall -std=c99 -c main.c

print.o: print.c print.h
	gcc -Wall -std=c99 -c print.c