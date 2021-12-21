#include "dimensioni.h"

typedef enum { InCorso, Vittoria, Sconfitta } Risultato;

typedef struct {
    Risultato risultato;
    Casella campo[NRIGHE][NCOLONNE];
} Gioco;

void inizializza(Gioco *pg);
void applica(Gioco *pg, Azione a);
void stampa(Gioco g);
void valuta(Gioco *pg);
Risultato valutazione(Gioco g);