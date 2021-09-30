// stampa la differenza fra le date ricevute in input

#include <stdio.h>

main() {
  int G, M, A;

  int N0, N1, N2, N3;

  int JD1, JD2;

  printf("Digita giorno, mese e anno delle due date\n");
  scanf("%d%d%d", &G, &M, &A);

  N0 = (M - 14) / 12;
  N1 = (1461 * (A + 4800 + N0)) / 4;
  N2 = 367 * (M - 2 - 12 * N0) / 12;
  N3 = 3 * (A + 4900 + N0) / 400;
  JD1 = N1 + N2 - N3 + G - 32075;

  scanf("%d%d%d", &G, &M, &A);

  N0 = (M - 14) / 12;
  N1 = (1461 * (A + 4800 + N0)) / 4;
  N2 = 367 * (M - 2 - 12 * N0) / 12;
  N3 = 3 * (A + 4900 + N0) / 400;
  JD2 = N1 + N2 - N3 + G - 32075;

  printf("La differenza fra le date e` %d\n", JD2 - JD1);
}