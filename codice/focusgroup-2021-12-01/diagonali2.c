#include <stdio.h>

int main() {
  int M[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int i, j;
  int i_iniziale;

  i_iniziale = -3;
  while (i_iniziale <= 3) {
    i = i_iniziale;
    j = 0;
    while (j <= 3) {
      if (i >= 0 && i <= 3 && j >= 0 && j <= 3)
        printf("%d ", M[i][j]);
      i++;
      j++;
    }
    printf("\n");
    i_iniziale++;
  }
}