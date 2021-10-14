// stampa tutte le terne pitagoriche di ipotenusa minore o uguale a un numero
// richiesto all'utente

#include <stdio.h>
main() {
  int M;
  int a, b, c;
  int contatore = 0;
  printf("Digita l'ipotenusa massima\n");
  scanf("%d", &M);

  // a assume tutti i valori possibili per il primo cateto
  for (a = 1; a <= M; a++)
    // b assume tutti i valori possibili per il secondo cateto
    for (b = a + 1; b <= M; b++)
      // c assume tutti i valori possibili per l'ipotenusa
      for (c = b + 1; c <= M; c++) {
        contatore++;
        if (a * a + b * b == c * c)       // se <a,b,c> è una terna pitagorica
          printf("%d %d %d\n", a, b, c);  // stampala
      }
  printf("Terne testate: %d\n", contatore);
}