typedef enum { InCorso, Vittoria, Sconfitta } Risultato;

typedef struct {
    Casella campo[NRIGHE][NCOLONNE];
    Risultato risultato;
} Gioco;

void stampa(Gioco g);
void inizializza(Gioco *pg);
void applica(Gioco *pg, Azione a);
Risultato valutazione(Gioco g);