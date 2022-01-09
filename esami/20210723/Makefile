greenpass: main.o listaPersone.o date.o
	gcc -g -o greenpass main.o listaPersone.o date.o

date.o: date.c date.h
	gcc -c -g date.c

main.o: main.c listaPersone.h
	gcc -c -g main.c

listaPersone.o: listaPersone.c listaPersone.h date.h
	gcc -c -g listaPersone.c