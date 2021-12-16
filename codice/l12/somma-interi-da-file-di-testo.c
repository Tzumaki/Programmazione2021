#include <stdio.h>
#include <stdlib.h>

int somma_da_file(FILE* pf) {
  // la somma degli elementi
  // è il primo elemento +
  // la somma degli elementi rimanenti
  // se c'è almeno un elemento
  // altrimenti è 0
  int numero;
  if (fscanf(pf, "%d", &numero) == 1)
    // caso ricorsivo
    return numero + somma_da_file(pf);
  else
    // caso base
    return 0;
}

int main() {
  FILE* pft;
  int s;
  // aprire file
  if ((pft = fopen("interi.txt", "rt")) == NULL) {
    printf("errore apertura file\n");
    exit(1);
  }
  // calcolare la somma degli interi contenuti
  s = somma_da_file(pft);
  // chiudere il file
  fclose(pft);
  // stampare la somma
  printf("Somma: %d\n", s);
  return 0;
}