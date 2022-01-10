#include <stdlib.h>
#include <string.h>

#include "listaParole.h"

void nuovaLista(Lista* pl) {
  *pl = NULL;
}

void insTesta(Lista* pl, Frequenza f) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = f;
  aux->next = *pl;
  *pl = aux;
}

void aggiorna(Lista* pl, char p[]) {
  // inserimento ordinato di (p,1) se non presente
  // altrimenti incremento del contatore di p

  while (*pl != NULL && strcmp((*pl)->dato.parola, p) < 0)
    pl = &(*pl)->next;

  if (*pl != NULL && strcmp((*pl)->dato.parola, p) == 0)
    (*pl)->dato.n_occorrenze++;
  else {
    Frequenza f;
    strcpy(f.parola, p);
    f.n_occorrenze = 1;
    insTesta(pl, f);
  }
}
void output(Lista l, FILE* pf_out) {
  while (l != NULL) {
    fprintf(pf_out, "%s %d\n", l->dato.parola, l->dato.n_occorrenze);
    l = l->next;
  }
}
