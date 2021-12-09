#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[20];
  char indirizzo[30];
  char numero[15];
} Persona;

int main() {
  FILE* pf;
  char nome[20];
  Persona p;

  // richiesta nome

  printf("Digita il nome da ricercare\n");
  scanf("%s", nome);

  // apertura file

  if ((pf = fopen("rubrica.txt", "rt")) == NULL) {
    printf("Errore apertura rubrica.txt");
    exit(1);
  }

  // ricerca
  while (fscanf(pf, "%s%s%s", p.nome, p.indirizzo, p.numero) == 3) {
    // p contiene un record del file
    if (strcmp(p.nome, nome) == 0)
      printf("%s %s %s\n", p.nome, p.indirizzo, p.numero);
  }

  // chiusura file
  fclose(pf);

  return 0;
}