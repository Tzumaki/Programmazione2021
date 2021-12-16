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
    int s;
  
  // calcolare la somma degli interi contenuti
  s = somma_da_file(ct);

  // stampare la somma
  printf("Somma: %d\n", s);
  return 0;
}