#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Dato d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

int giorno_giuliano(int g, int m, int a) {
  // restituisce il numero di giorni trascorsi dal 1/1/4713 a.C alla data g/m/a
  int N0, N1, N2, N3;
  N0 = (m - 14) / 12;
  N1 = 1461 * (a + 4800 + N0) / 4;
  N2 = 367 * (m - 2 - 12 * N0) / 12;
  N3 = 3 * (a + 4900 + N0) / 400;
  return N1 + N2 - N3 + g - 32075;
}

int differenzaDate(Data d1, Data d2) {
  return giorno_giuliano(d1.giorno, d1.mese, d1.anno) -
         giorno_giuliano(d2.giorno, d2.mese, d2.anno);
}

void aggiorna(Lista* pl, Record r, Data oggi) {
  // se evento troppo vecchio non faccio nullo
  Data dataEvento = {r.giorno, r.mese, r.anno};
  if (r.evento == 'T' && differenzaDate(oggi, dataEvento) > 3)
    return;
  if (r.evento == 'V' && differenzaDate(oggi, dataEvento) > 180)
    return;

  // se CF già presente aggiorna il flag
  // altrimenti inserisce ordinatamente nuovo elemento
  while (*pl != NULL && strcmp((*pl)->dato.CF, r.CF) < 0)
    pl = &(*pl)->next;

  if (*pl == NULL || strcmp((*pl)->dato.CF, r.CF) != 0) {
    Dato d;
    strcpy(d.CF, r.CF);
    d.tampone = 0;
    d.vaccino = 0;
    insTesta(pl, d);
  }
  if (r.evento == 'V')
    (*pl)->dato.vaccino = 1;
  else if (r.evento == 'T')
    (*pl)->dato.tampone = 1;
}

void stampa(Lista l) {
  while (l) {
    printf("%s ", l->dato.CF);
    if (l->dato.vaccino)
      printf("vaccino ");
    if (l->dato.tampone)
      printf("tampone ");
    printf("\n");
    l = l->next;
  }
}