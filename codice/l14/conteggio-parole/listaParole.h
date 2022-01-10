#include <stdio.h>

#define LUNGHEZZA_MAX 30

typedef struct {
  char parola[LUNGHEZZA_MAX];
  int n_occorrenze;
} Frequenza;

typedef struct nodo {
  Frequenza dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void aggiorna(Lista* pl, char p[]);
void output(Lista l, FILE *pf_out);