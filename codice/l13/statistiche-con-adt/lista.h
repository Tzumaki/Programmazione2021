#define DIM 100

typedef struct {
    int numero;
    int frequenza;
} Elemento;

typedef struct {
    int n_elementi;
    Elemento dati[DIM];
} Lista;

void nuova_lista(Lista *pl);
void aggiorna(Lista *pl, int numero);
int minimo(Lista l);
int massimo(Lista l);

int lunghezza(Lista l);