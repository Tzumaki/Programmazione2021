#include <stdio.h>

main() {
  int m, a;
  printf("digita mese e anno\n");
  scanf("%d%d", &m, &a);

  if (m == 2)
    // febbraio
    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
      // anno bisestile
      printf("29\n");
    else
      // anno non bisestile
      printf("28\n");
  else if (m == 4 || m == 6 || m == 9 || m == 11)
    // aprile, giugno, settembre, novembre
    printf("30\n");
  else
    // altri mesi
    printf("31\n");
}
