#include <stdio.h>

int main() {
  int M[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int i, j;
  int j_iniziale = 3;
  int i_iniziale;

  while (j_iniziale >= 0) {
    i = 0;
    j = j_iniziale;
    while (j <= 3) {
      printf("%d ", M[i][j]);
      i++;
      j++;
    }
    printf("\n");
    j_iniziale--;
  }

  i_iniziale = 1;
  while (i_iniziale <= 3) {
    i = i_iniziale;
    j = 0;
    while (i <= 3) {
      printf("%d ", M[i][j]);
      i++;
      j++;
    }
    printf("\n");
    i_iniziale++;
  }
}