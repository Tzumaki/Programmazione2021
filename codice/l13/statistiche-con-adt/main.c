#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(int argc, char *argv[]) {
  FILE* pft;
  Lista l;
  nuova_lista(&l);
  int numero;
  if (argc != 2) {
      printf("Uso: %s file_numeri\n", argv[0]);
      exit(2);
  }
  pft = fopen(argv[1], "rt");
  if (pft == NULL) {
    printf("Errore apertura file %s\n", argv[1]);
    exit(1);
  }
  // ciclo di input
  do {
    fscanf(pft,"%d", &numero);
    if (numero >= 0)
      aggiorna(&l, numero);
  } while (numero >= 0 && lunghezza(l) <= DIM);
  fclose(pft);

  printf("Minimo: %d\n", minimo(l));
  printf("Minimo: %d\n", massimo(l));

  return 0;
}