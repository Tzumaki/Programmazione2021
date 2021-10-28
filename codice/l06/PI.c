#include <stdio.h>

int primo(int n) {
  int i;
  // n è primo se non ha divisori compresi fra 2 e n-1
  int ha_divisori = 0;
  // per i che va da 2 a d-1
  if (n < 2)
    return 0;
  // si può ottimizzare
  for (i = 2; ha_divisori == 0 && i <= n - 1; i++)
    // se i divide d
    if (n % i == 0)
      // attivo il flag
      ha_divisori = 1;

  return !ha_divisori;
}

int PI(int n) {  // o (float n)
  int cont = 0, i;
  for (i = 1; i <= n; i++)
    if (primo(i))  // i è primo
      cont++;
  return cont;
}

int main() {
  int i;
  for (i = 1; i <= 5; i++)
    printf("%d\n", PI(i));
  return 0;
}