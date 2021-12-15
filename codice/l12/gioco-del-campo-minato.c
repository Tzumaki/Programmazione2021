#include <stdio.h>
#include <stdlib.h>

#define NRIGHE 4
#define NCOLONNE 6
#define PROBMINA 0.2

typedef enum { InCorso, Vittoria, Sconfitta } Risultato;

typedef struct {
  int riga;
  int colonna;
} Azione;

Azione leggiAzione() {
  char s[3];
  Azione a;
  printf("Quale cella vuoi scoprire?");
  scanf("%s", s);  // esempio "c4" corrisponde {riga = 3; colonna = 2};
  a.colonna = s[0] - 'a';
  a.riga = s[1] - '1';
  return a;
}

float rnd_float(float a, float b) {
  return a + (b - a) * (float)rand() / RAND_MAX;
}

typedef struct {
  int minata;
  int coperta;
} Casella;

void inizializza(Casella c[NRIGHE][NCOLONNE]) {
  int i, j;
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++) {
      c[i][j].coperta = 1;
      // assegnare alla casella all'indice [i][j] una mina con probabilità
      // PROBMINA
      if (rnd_float(0.0, 1.0) < PROBMINA)
        c[i][j].minata = 1;
      else
        c[i][j].minata = 0;
    }
}

int minaPresente(Casella c[][NCOLONNE], int i, int j) {
  if (i >= 0 && i < NRIGHE && j >= 0 && j < NCOLONNE)
    return c[i][j].minata;
  else
    return 0;
}

int mine_adiacenti(Casella c[NRIGHE][NCOLONNE], int rg, int cl) {
  int mine = 0;
  int j, i;
  // contiamo le mine
  for (i = rg - 1; i <= rg + 1; i++)
    for (j = cl - 1; j <= cl + 1; j++)
      if (i != rg || j != cl)
        mine += minaPresente(c, i, j);
  return mine;
}

void stampaCasella(Casella c[NRIGHE][NCOLONNE], int i, int j) {
  if (c[i][j].coperta)
    printf("#");
  else {
    if (c[i][j].minata)
      printf("*");
    else {
      int contatore = mine_adiacenti(c, i, j);
      if (contatore > 0)
        printf("%d", contatore);
      else
        printf(" ");
    }
  }
}

void stampa(Casella c[NRIGHE][NCOLONNE]) {
  int i, j;
  for (j = 0; j < 2 * NCOLONNE + 3; j++)
    printf("-");
  printf("\n");
  for (i = NRIGHE - 1; i >= 0; i--) {
    printf("%d ", i + 1);
    for (j = 0; j < NCOLONNE; j++) {
      printf("|");
      stampaCasella(c, i, j);
    }
    printf("|\n");
    for (j = 0; j < 2 * NCOLONNE + 3; j++)
      printf("-");
    printf("\n");
  }
  printf("  ");
  for (j = 0; j < NCOLONNE; j++)
    printf(" %c", 'a' + j);
  printf("\n");
}

void applica(Casella c[NRIGHE][NCOLONNE], Azione a) {
  if (a.riga < 0 || a.riga > NRIGHE - 1 || a.colonna < 0 ||
      a.colonna > NCOLONNE) {
    printf("azione non valida\n");
    return;
  }
  c[a.riga][a.colonna].coperta = 0;
}

Risultato valuta(Casella c[NRIGHE][NCOLONNE]) {
  int i, j;
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++)
      if (c[i][j].minata && !c[i][j].coperta)
        return Sconfitta;
  for (i = 0; i < NRIGHE; i++)
    for (j = 0; j < NCOLONNE; j++)
      if (!c[i][j].minata && c[i][j].coperta)
        return InCorso;
  return Vittoria;
}

int main() {
  Casella campo[NRIGHE][NCOLONNE];
  Azione azione;
  Risultato risultato;

  inizializza(campo);
  risultato = InCorso;
  while (risultato == InCorso) {
    stampa(campo);
    azione = leggiAzione();
    applica(campo, azione);
    risultato = valuta(campo);
  }
  switch (risultato) {
    case Sconfitta:
      printf("Hai perso\n");
      break;
    case Vittoria:
      printf("Hai vinto");
      break;
  }
}