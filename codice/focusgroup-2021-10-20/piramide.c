#include <stdio.h>

main() {
  int N, i, j;
  printf("Quante righe?\n");
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    // stampa i-esima riga
    // stampa i-1 spazi
    for (j = 1; j <= i - 1; j++)
      printf(" ");
    // stampa 13 - 2 * (i-1) asterischi
    for (j = 1; j <= 13 - 2 * (i - 1); j++)
      printf("*");
    // a capo
    printf("\n");
  }
}