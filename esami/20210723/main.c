#include <stdio.h>
#include <stdlib.h>

#include "listaPersone.h"

int main(int argc, char* argv[]) {
  Record a;
  FILE* fp;
  Lista l;
  if (argc != 2 && argc != 5) {
    printf("Uso: %s fileEventi [giorno mese anno]\n", argv[0]);
    exit(1);
  }
  nuovaLista(&l);
  if ((fp = fopen(argv[1], "rb")) == NULL) {
    printf("Errore apertura %s\n", argv[1]);
    exit(2);
  }
  while (fread(&a, sizeof(Record), 1, fp) == 1)
    aggiorna(&l, a);
  fclose(fp);
  if (argc == 5) {
    // parte 2
    Data d;
    /* sscanf è come fscanf ma legge dalla stringa primo argomento anziché da
     file */
    sscanf(argv[2], "%d", &d.giorno);
    sscanf(argv[3], "%d", &d.mese);
    sscanf(argv[4], "%d", &d.anno);
    stampaRecenti(l, d, 
    3, // tampone fatto max 3 giorni prima di d
    180); // vaccino fatto max 180 giorni prima di d
  } else
    // parte 1
    stampa(l);
  return 0;
}
