// stampa il giorno giuliano della data in input

#include <stdio.h>

main() {
  int G, M, A;
  int JD;

  int N0, N1, N2, N3;

  printf("Digita giorno, mese e anno\n");
  scanf("%d%d%d", &G, &M, &A);  // input

  // calcolo valori intermedi
  N0 = (M - 14) / 12;
  N1 = (1461 * (A + 4800 - N0)) / 4;
  N2 = 367 * (M - 2 - 12 * N0) / 12;
  N3 = 3 * (A + 4900 + N0) / 400;

  // calcolo del valore di output
  JD = N1 + N2 - N3 + G - 32075;

  // output
  printf("Il giorno giuliano è %d\n", JD);
}