#include <stdlib.h>

#include "dimensioni.h"
#include "azione.h"
#include "casella.h"

#include "gioco.h"

#define PROBMINA 0.2


float rnd_float(float a, float b) {
  return a + (b - a) * (float)rand() / RAND_MAX;
}

void stampa(Gioco g) {}
void inizializza(Gioco* pg) {
    ... PROBMINA ...
}
void applica(Gioco* pg, Azione a) {}
Risultato valutazione(Gioco g) {}