typedef struct nodo {
  int dato;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

void inizializza(Lista* pl);
