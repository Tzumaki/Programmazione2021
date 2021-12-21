#include <stdio.h>
#include <stdlib.h>

#include "azione.h"
#include "casella.h"
#include "dimensioni.h"
#include "gioco.h"

#define PROBMINA 0.2

float rnd_float(float a, float b) {
  return a + (b - a) * (float)rand() / RAND_MAX;
}

void inizializza(Gioco* pg) {
  int i, j;
  pg->risultato = InCorso;
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++) {
      pg->campo[i][j].coperta = 1;
      // assegnare alla casella all'indice [i][j] una mina con probabilità
      // PROBMINA
      if (rnd_float(0.0, 1.0) < PROBMINA)
        pg->campo[i][j].minata = 1;
      else
        pg->campo[i][j].minata = 0;
    }
}

void applica(Gioco* pg, Azione a) {
  if (a.riga < 0 || a.riga > NRIGHE - 1 || a.colonna < 0 ||
      a.colonna > NCOLONNE) {
    printf("azione non valida\n");
    return;
  }
  pg->campo[a.riga][a.colonna].coperta = 0;
}

void stampa(Gioco g) {
  int i, j;
  for (j = 0; j < 2 * NCOLONNE + 3; j++)
    printf("-");
  printf("\n");
  for (i = NRIGHE - 1; i >= 0; i--) {
    printf("%d ", i + 1);
    for (j = 0; j < NCOLONNE; j++) {
      printf("|");
      stampaCasella(g.campo, i, j);
    }
    printf("|\n");
    for (j = 0; j < 2 * NCOLONNE + 3; j++)
      printf("-");
    printf("\n");
  }
  printf("  ");
  for (j = 0; j < NCOLONNE; j++)
    printf(" %c", 'a' + j);
  printf("\n");
}

void valuta(Gioco* pg) {
  int i, j;
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++)
      if (pg->campo[i][j].minata && !pg->campo[i][j].coperta) {
        pg->risultato = Sconfitta;
        return;
      }
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++)
      if (!pg->campo[i][j].minata && pg->campo[i][j].coperta) {
        pg->risultato = InCorso;
        return;
      }
  pg->risultato = Vittoria;
}

Risultato valutazione(Gioco g) {
  return g.risultato;
}
