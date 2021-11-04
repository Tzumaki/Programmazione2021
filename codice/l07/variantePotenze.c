#include <stdio.h>
// stampa a video le potenze negative sotto forma di frazione
int potenza(int base, int esp) {
  int cont, prod = 1;

  for (cont = 0; cont < esp; cont++)
    prod *= base;

  return (prod);
}

int main() {
  int b, e;
  printf("-- CALCOLO POTENZE --\n");
  printf("Inserisci base: ");
  scanf("%d", &b);
  printf("Inserisci esponente: ");
  scanf("%d", &e);

  if (e < 0) {
    printf("1\n-\n");
    printf("%d\n", potenza(b, -e));
  } else
    printf("%d\n", potenza(b, e));

  return (0);
}

/* Modificare l'output in modo che per

b = 2, e = -20

il programma stampi
   1
-------
1048576

*/