#include <stdio.h>

main() {
  int a, b;
  int i;
  scanf("%d", &b);  // b vale a1
  for (i = 1; i < 5; i++) {
    scanf("%d", &a);  // a assume la seq. di valori a2, a3, a4, a5
    if (b < a) // aggiornamento accumulatore
      b = a; 
  }
  printf("%d\n", b);
}