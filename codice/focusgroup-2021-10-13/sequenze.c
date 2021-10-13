// scrivere un programma che stampi la somma dei tripli dei numeri dispari
// compresi fra 20 e 30

#include <stdio.h>

main() {
  int i;int j;
  int acc;
  
  acc = 0; // inizializzazione accumulatore
  for (i = 20; i<= 30; i++)
    {
        // i assume la seq. di valori 20..30 (s1) - generazione sequenza
       if  (i % 2 == 1)
       {
           // i assume la seq. di valori 21, 23, ..., 29 (s2) - filter
           j = 3 * i;
           // j assume la seq. di valori 63, 69, ..., 87 (s3) - map
           acc = acc + j; // reduce
           }
    }
    // acc contiene il risultato desiderato
    printf("%d\n", acc);
}