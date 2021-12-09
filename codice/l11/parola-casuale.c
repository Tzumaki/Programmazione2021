#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char Parola[31];

int rnd_int(int a, int b) {
  return a + (rand() % (b - a + 1));
}

Parola PAROLE[100000];
int DL;

void parolaCasuale(Parola s) {
  strcpy(s, PAROLE[rnd_int(0, DL - 1)]);
}

int main() {
  char parola[31];
  int i;
  int DL;

  srand(time(NULL));

  FILE* pf;
  if ((pf = fopen("words.italian.txt", "rt")) == NULL) {
    printf("Errore apertura file vocabolario\n");
    exit(1);
  }
  i = 0;
  while (fscanf(pf, "%s", PAROLE[i]) == 1)
    i++;
  fclose(pf);
  DL = i;

  parolaCasuale(parola);

  printf("%s\n", parola);

  return 0;
}