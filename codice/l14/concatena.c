#include <stdlib.h>
#include <stdio.h>

typedef struct nodo {
  int dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void insTesta(Lista* pl, int d) {
  Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
  aux->dato = d;
  aux->next = *pl;
  *pl = aux;
}

void concatena(Lista* pl1, Lista l2) {
  while (*pl1 != NULL)
    pl1 = &(*pl1)->next;
  *pl1 = l2;
}

void stampa(Lista l) {
  // ForEach(printf,l)
  while (l != NULL) {
    printf("%d\n", l->dato);
    l = l->next;
  }
}

int main() {
  Lista l1 = NULL, l2 = NULL;
  insTesta(&l1, 2);
  insTesta(&l1, 1);
  insTesta(&l2, 4);
  insTesta(&l2, 3);

  concatena(&l1, l2);

  stampa(l1);
  return 0;
}