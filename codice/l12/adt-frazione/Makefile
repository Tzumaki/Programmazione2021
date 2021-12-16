frazioni: main.o frazione.o	
	gcc -g -o frazioni main.o frazione.o

main.o: main.c frazione.h
	gcc -g -c main.c

frazione.o: frazione.c frazione.h
	gcc -g -c frazione.c 