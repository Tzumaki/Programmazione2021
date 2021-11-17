// chiede all'utente i dati di alcune persone e li stampiamo in ordine di età
// crescente

#include <stdio.h>

typedef struct {
  char nome[20];
  char cognome[30];
  int eta;
} Persona;

void stampaPersona(Persona p) {
  printf("%s %s %d\n", p.nome, p.cognome, p.eta);
}

Persona leggiPersona() {
  Persona p;
  printf("Nome?\n");
  scanf("%s", p.nome);
  printf("Cognome?\n");
  scanf("%s", p.cognome);
  printf("Età?\n");
  scanf("%d", &p.eta);
  return p;
}

int minore(Persona p1, Persona p2) {
  if (p1.eta < p2.eta)
    return 1;
  else
    return 0;
  // return p1.eta < p2.eta;
}

int main() {
  Persona persone[5];
  int i;
  int DL;
  Persona p;
  DL = 0;
  for (i = 0; i < 5; i++) {
    int j;
    p = leggiPersona();
    // inserisco p in persone in ordine crescente di età
    j = DL;
    // scalo verso destra tutti gli elementi più anziani di quello da inserire
    while (j > 0 && minore(p, persone[j - 1])) {
      persone[j] = persone[j - 1];
      j--;
    }
    persone[j] = p;
    DL++;
  }

  for (i = 0; i < 5; i++)
    stampaPersona(persone[i]);

  return 0;
}