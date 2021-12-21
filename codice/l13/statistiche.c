#include <stdio.h>

#define DIM 100

int main() {
  int a[DIM], numeri[DIM], frequenze[DIM];
  int DL;    // DL <= DIM
  int DLFr;  // dimensione logica per frequenza
  int numero;
  int i, j;
  int trovato;
  int m;  // accumulatore indice
  int s;  // accumulatore somma

  // input di al massimo DIM elementi (fermandosi quando l'input è negativo)
  DL = 0;
  do {
    scanf("%d", &numero);
    if (numero >= 0)
      a[DL++] = numero;
  } while (DL < DIM && numero >= 0);

  // minimo
  m = 0;
  for (i = 1; i < DL; i++)
    if (a[i] < a[m])
      m = i;
  // m è l'indice dell'elemento minimo

  printf("Minimo: %d\n", a[m]);

  // massimo
  m = 0;
  for (i = 1; i < DL; i++)
    if (a[i] > a[m])
      m = i;
  // m è l'indice dell'elemento massimo
  printf("Massimo: %d\n", a[m]);

  // media aritmetica

  // somma degli elementi validi / numero di elementi validi
  // somma = reduce(+, 0, a)
  s = 0;
  for (i = 0; i < DL; i++)
    s += a[i];
  // s contiene la somma degli elementi validi dell'array
  printf("Media: %.2f\n", (float)s / DL);

  // numeri più frequenti
  DLFr = 0;
  for (i = 0; i < DL; i++) {
    // ricerco a[i] in numeri
    trovato = 0;
    for (j = 0; j < DLFr && !trovato; j++)
      if (numeri[j] == a[i]) {
        frequenze[j]++;
        trovato = 1;
      }
    if (!trovato) {
      numeri[DLFr] = a[i];
      frequenze[DLFr] = 1;
      DLFr++;
    }
  }
  // calcolo frequenza massima
  m = 0;
  for (i = 1; i < DLFr; i++)
    if (frequenze[i] > frequenze[m])
      m = i;

  // m è l'indice della frequenza massima
  // frequenze[m] è la frequenza massima
  printf("Numeri più frequenti (%d ripetizioni): ", frequenze[m]);
  for (i = 0; i < DLFr; i++)
    if (frequenze[i] == frequenze[m])
      printf("%d ", numeri[i]);
  printf("\n");

  return 0;
}