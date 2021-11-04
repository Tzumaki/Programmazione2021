#include <stdio.h>

float valoreAssoluto(float x) {
  if (x >= 0)
    return x;
  else
    return -x;
}

int main() {
  float a[5];
  int i;
  int m;

  printf("Digita 5 numeri reali\n");
  // a = map (identità, input)
  for (i = 0; i < 5; i++)
    scanf("%f", &a[i]);

  // inizializzazione accumulatore
  m = 0;

  // per i = 1 ... 4
  for (i = 1; i <= 4; i++)
    if (valoreAssoluto(a[m]) <= valoreAssoluto(a[i]))  // | a[m] | <= | a[i] |
      m = m;
    else
      m = i;

  // m è l'indice dell'elemento di valore assoluto minimo
  printf("%f\n", a[m]);

  return 0;
}