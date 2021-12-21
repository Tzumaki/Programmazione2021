#include <stdio.h>

#include "casella.h"

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
      if (i >= 0 && i < NRIGHE && j >= 0 && j < NCOLONNE &&  i != rg || j != cl)
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
