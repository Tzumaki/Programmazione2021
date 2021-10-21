#include <math.h>
#include <stdio.h>

main() {
  float a, x;

  // input di a;
  printf("Digita un numero reale\n");
  scanf("%f", &a);

  // inizializzazione di x;
  x = 1.0;

  // ciclo di aggiornamento di x;

  while (fabsf(a - x * x) >= 1e-5)
    x = (x + a / x) / 2.0;
  // stampa di x;

  printf("%f\n", x);
}