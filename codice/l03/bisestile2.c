#include <stdio.h>

main() {
  int anno;
  printf("Digita l'anno\n");
  scanf("%d", &anno);
  if ((!(anno % 4) && anno % 100) || !(anno % 400))
    printf("Bisestile\n");
  else
    printf("Non bisestile\n");
}