frazioni: main.o frazione.o	
	gcc -g -o frazioni main.o frazione.o

frazione.o: frazione.c frazione.h
	gcc -g -c frazione.c 

main.o: main.c frazione.h
	gcc -g -c main.c
