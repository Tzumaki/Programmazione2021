// richiede all'utente un intero n e stampa tutti i divisori di n compresi  fra
// 2 e n compreso

#include <stdio.h>

main() {
  int n;
  int d, ha_divisori, i;
  int quoziente, esponente;
  printf("Digita un intero positivo\n");
  scanf("%d", &n);
  quoziente = n;
  for (d = 2; d <= n; d++) {
    // d assume la seq di valori 2, 3, ..., n
    if (n % d == 0) {
      // d assume la seq dei valori dei divisori di n compresi fra 2 e n

      // determinare se d è primo cercando divisori di d compresi fra 2 e d-1
      // inizializzo il flag
      ha_divisori = 0;
      // per i che va da 2 a d-1
      for (i = 2; ha_divisori == 0 && i <= d - 1; i++)
        // se i divide d
        if (d % i == 0)
          // attivo il flag
          ha_divisori = 1;

      if (!ha_divisori)  // d è primo
      {
        // d assume la seq dei divisori primi di n compresi fra 2 e n
        esponente = 0;

        while (quoziente % d == 0) {
          quoziente = quoziente / d;
          esponente++;
        }        

        printf("%d^%d\n", d, esponente);
      }
    }
  }
}