#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char Parola[31];

int rnd_int(int a, int b) {
  return a + (rand() % (b - a + 1));
}

typedef struct {
  char lettera;
  int indovinata;
} LetteraSegreta;

typedef struct {
  int lunghezza;
  LetteraSegreta lettereSegrete[30];
} ParolaSegreta;

typedef enum { Vittoria, Sconfitta, InCorso } StatoGioco;

Parola PAROLE[100000];
int DL;

void parolaCasuale(Parola s) {
  strcpy(s, PAROLE[rnd_int(0, DL - 1)]);
}

ParolaSegreta nuovaParolaSegreta(char s[]);

int contiene(ParolaSegreta* pp, char c);

int main() {
  char parola[31];
  int i;
  int DL;
  ParolaSegreta parolaSegreta;
  int vite;
  StatoGioco stato;
  char lettera[2];

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

  parolaSegreta = nuovaParolaSegreta(parola);

  stato = InCorso;

  while (stato == InCorso) {
    stampaParolaSegreta(parolaSegreta);
    scanf("%s", lettera);
    if (contiene(&parolaSegreta, lettera[0]) == 0)
      vite--;
    if (completamenteIndovinata(parolaSegreta))
      stato = Vittoria;
    if (vite < 1)
      stato = Sconfitta;
  }
  if (stato == Vittoria)
    printf("Hai vinto!\n");
  else if (stato == Sconfitta)
    printf("Hai perso\n");

  printf("%s\n", parola);

  return 0;
}