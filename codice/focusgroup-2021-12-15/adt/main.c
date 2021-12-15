#include <stdio.h>

#include "contatore.h"

int main() {
  int i;
  Contatore c1, c2;
  Contatore array[100];
  char c;
  for (i = 0; i < 99; i++)
    inizializza_contatore(&(array[i]));
  inizializza_contatore(&c2);
  inizializza_contatore(&c1);
  while (scanf("%c", &c) == 1)
    incrementa_contatore(&c1);

  incrementa_contatore(&c2);
  incrementa_contatore(&c2);
  stampa_contatore(c1);
  stampa_contatore(c2);

}