typedef struct {
  int cont;
} Contatore;  // tipo di dato astratto

void inizializza_contatore(Contatore* pc);

void incrementa_contatore(Contatore* pc);  // dichiarazione di funzione
void stampa_contatore(Contatore c);        // dichiarazione di funzione