#include "contatore.h"
#include <stdio.h>

void inizializza_contatore(Contatore* pc) {
  pc->cont = 0;
}

void incrementa_contatore(Contatore* pc) {
  pc->cont++;
}

void stampa_contatore(Contatore c) {
  printf("%d\n", c.cont);
}