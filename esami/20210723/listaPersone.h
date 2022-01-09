#include "date.h"

typedef struct {
  int giorno;
  int mese;
  int anno;
  char CF[17];
  char evento;
} Record;

typedef struct {
  char CF[17];
  Data ultimoTampone; // serve per la parte 2; per la parte 1 è sufficiente un flag
  Data ultimoVaccino; // serve per la parte 2; per la parte 1 è sufficiente un flag
} Dato;

typedef struct nodo {
  Dato dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void nuovaLista(Lista* pl);
void aggiorna(Lista* pl, Record v);
void stampa(Lista l);
void stampaRecenti(Lista l, Data d, int maxDiffT, int maxDiffV);