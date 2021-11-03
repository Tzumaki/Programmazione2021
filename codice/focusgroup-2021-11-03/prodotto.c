#include <stdio.h>

int main() {
  int a[5];
  int i;
  int p;  // accumulatore
  // ForEach(input,a)
  for (i = 0; i <= 4; i++)
    scanf("%d", &a[i]);

  p = 1;  // inizializzazione accumulatore
  for (i = 0; i <= 4; i++)
    p = p * a[i];  // aggiornamemnto accumulatore

  // p contiene il prodotto degli elementi di a;

  for (i = 0; i < 5; i++) {
    printf("%d ", a[i]);
    if (i < 4)
      printf(" x ");
  }

  printf("= %d\n", p);

  return 0;
}