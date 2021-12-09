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

  if ((pf = fopen("rubrica.dat", "rb")) == NULL) {
    printf("Errore apertura rubrica.dat");
    exit(1);
  }

  // ricerca

  while (fread(&p, sizeof(Persona), 1, pf) == 1) {
    // p contiene un record del file
    if (strcmp(p.nome, nome) == 0)
      printf("%s %s %s\n", p.nome, p.indirizzo, p.numero);
  }

  // chiusura file
  fclose(pf);

  return 0;
}