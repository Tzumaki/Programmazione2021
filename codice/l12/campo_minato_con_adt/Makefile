campo-minato: main.o azione.o
	gcc -g -o campo-minato main.o azione.o

main.o: main.c azione.h gioco.h
	gcc -g -c main.c

azione.o: azione.c azione.h
	gcc -g -c azione.c

gioco.o: gioco.c gioco.h dimensioni.h azione.h casella.h
	gcc -g -c gioco.c

casella.o: casella.c casella.h dimensioni.h
	gcc -g -c casella.c