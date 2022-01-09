campo-minato: main.o gioco.o azione.o casella.o
	gcc -g -o campo-minato main.o gioco.o azione.o casella.o

main.o: main.c casella.h azione.h gioco.h
	gcc -g -c main.c

# serve per non aggiungere dimensioni.h come dipendenza a tutti i target che dipendono da gioco.h
gioco.h: dimensioni.h
	touch gioco.h

casella.o: casella.c casella.h
	gcc -g -c casella.c

# come sopra
casella.h: dimensioni.h
	touch casella.h

azione.o: azione.c azione.h
	gcc -g -c azione.c

gioco.o: gioco.c casella.h azione.h gioco.h
	gcc -g -c gioco.c