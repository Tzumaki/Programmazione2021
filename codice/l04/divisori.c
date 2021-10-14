// richiede all'utente un intero n e stampa tutti i divisori di n compresi  fra
// 2 e n compreso

#include <stdio.h>

main() {
  int n, d;
  printf("Digita un intero positivo\n");
  scanf("%d", &n);
  for (d = 2; d <= n; d++) {
    // d assume la seq di valori 2, 3, ..., n
    if (n % d == 0) {
      // d assume la seq dei valori dei divisori di n compresi fra 2 e n
      printf("%d\n", d);
    }
  }
}