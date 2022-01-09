#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaPersone.h"

Data dataNulla = {0, 0, 0};
// per indicare una data non impostata
// ad esempio la data dell'ultimo vaccino per persone non ancora vaccinate

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Dato d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

void aggiorna(Lista* pl, Record a) {
  Data dataEvento = {a.giorno, a.mese, a.anno};
  while (*pl != NULL && strcmp((*pl)->dato.CF, a.CF) < 0)
    pl = &(*pl)->next;
  if (*pl == NULL || strcmp((*pl)->dato.CF, a.CF) != 0) {
    Dato d;
    strcpy(d.CF, a.CF);
    d.ultimoTampone = dataNulla;
    d.ultimoVaccino = dataNulla;
    insTesta(pl, d);
  }
  switch (a.evento) {
    case 'T':
      if (diff_date((*pl)->dato.ultimoTampone, dataEvento) < 0)
        (*pl)->dato.ultimoTampone = dataEvento;
      break;
    case 'V':
      if (diff_date((*pl)->dato.ultimoVaccino, dataEvento) < 0)
        (*pl)->dato.ultimoVaccino = dataEvento;
      break;
  }
}

// parte 1
void stampa(Lista l) {
  while (l) {
    printf("%s", l->dato.CF);
    if (diff_date(l->dato.ultimoTampone, dataNulla) != 0)
      printf(", tampone");
    if (diff_date(l->dato.ultimoVaccino, dataNulla) != 0)
      printf(", vaccino");
    printf("\n");
    l = l->next;
  }
}

// parte 2
void stampaRecenti(Lista l, Data d, int maxDiffT, int maxDiffV) {
  while (l) {
    int diffT = diff_date(d, l->dato.ultimoTampone);
    int diffV = diff_date(d, l->dato.ultimoVaccino);
    if (diffT >= 0 && diffT <= maxDiffT || diffV >= 0 && diffV <= maxDiffV) {
      printf("%s", l->dato.CF);
      if (diffT >= 0 && diffT <= maxDiffT)
        printf(", tampone");
      if (diffV >= 0 && diffV <= maxDiffV)
        printf(", vaccino");
      printf("\n");
    }
    l = l->next;
  }
}