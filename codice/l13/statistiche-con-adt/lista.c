#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void nuova_lista(Lista* pl) {
  pl->n_elementi = 0;
}

int lunghezza(Lista l) {
  return l.n_elementi;
}

void aggiorna(Lista* pl, int numero) {
  int i = 0;
  int trovato = 0;
  while (!trovato && i < pl->n_elementi) {
    if (pl->dati[i].numero == numero) {
      pl->dati[i].frequenza++;
      trovato = 1;
    }
    i++;
  }
  if (!trovato) {
    if (pl->n_elementi == DIM) {
      printf("Errore: lista piena\n");
      exit(101);
    }
    pl->dati[pl->n_elementi].numero = numero;
    pl->dati[pl->n_elementi].frequenza = 1;
    pl->n_elementi++;
  }
}

int minimo(Lista l) {
  int m, i;
  if (l.n_elementi == 0) {
    printf("Impossibile calcolare il minimo di una lista vuota");
    exit(100);
  }
  m = l.dati[0].numero;
  for (i = 1; i < l.n_elementi; i++)
    if (l.dati[i].numero < m)
      m = l.dati[i].numero;
  return m;
}
int massimo(Lista l) {
  int m, i;
  if (l.n_elementi == 0) {
    printf("Impossibile calcolare il massimo di una lista vuota");
    exit(100);
  }
  m = l.dati[0].numero;
  for (i = 1; i < l.n_elementi; i++)
    if (l.dati[i].numero > m)
      m = l.dati[i].numero;
  return m;
}