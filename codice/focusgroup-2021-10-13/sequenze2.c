// scrivere un programma che stampi la somma dei tripli dei numeri dispari
// compresi fra 20 e 30

#include <stdio.h>

main() {
  int i;
  int j;
  int acc;

  acc = 0;  // inizializzazione accumulatore
  for (i = 21; i <= 29; i += 2) {
    // i assume la seq. di valori 21, 23, ..., 29 (s2) - filter
    acc = acc + 3 * i;  // reduce
  }
  // acc contiene il risultato desiderato
  printf("%d\n", acc);
}