#include <stdio.h>

main() {
  int N, N_rov, q;
  scanf("%d", &N);
  N_rov = 0;
  q = N;
  while (q > 0) {
    N_rov = N_rov * 10 + q % 10;
    q = q / 10;
  }
  if (N == N_rov)
    printf("Palindromo\n");
  else
    printf("Non palindromo\n");
}