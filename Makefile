proj1: main.o getaddress.o functions.o iofunctions.o
	gcc -o proj1 main.o getaddress.o functions.o iofunctions.o

main.o: main.c
	gcc -ansi -pedantic-errors -Wall -c main.c

iofunctions.o: iofunctions.c
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

getaddress.o: getaddress.c
	gcc -ansi -pedantic-errors -Wall -c getaddress.c

functions.o: functions.c
	gcc -ansi -pedantic-errors -Wall -c functions.c

clean:
		rm *.o

