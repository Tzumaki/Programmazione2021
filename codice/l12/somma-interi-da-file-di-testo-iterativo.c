#include <stdio.h>
#include <stdlib.h>

int somma_da_file(FILE* pf) {
  int s = 0;
  int numero;
  while (fscanf(pf, "%d", &numero) == 1)  // sequenza non vuota
    s = s + numero; // aggiornamento accumulatore
  return s;
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