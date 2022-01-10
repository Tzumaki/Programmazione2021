#include <stdio.h>
#include <stdlib.h>

#include "listaParole.h"

int main(int argc, char* argv[]) {
  Lista l;
  FILE *pf_in, *pf_out;
  char p[LUNGHEZZA_MAX];

  if (argc != 3) {
    printf("Uso: %s fileIn fileOut\n", argv[0]);
    exit(1);
  }

  pf_in = fopen(argv[1], "rt");
  if (pf_in == NULL) {
    printf("Errore apertura %s\n", argv[1]);
    exit(2);
  }
  // reduce(aggiornamento, [], input)
  nuovaLista(&l);

  while (fscanf(pf_in, "%s", p) == 1) {
    aggiorna(&l, p);
  }
  fclose(pf_in);

  pf_out = fopen(argv[2], "wt");
  if (pf_out == NULL) {
    printf("Errore apertura %s\n", argv[2]);
    exit(3);
  }
  output(l, pf_out);
  fclose(pf_out);

  return 0;
}