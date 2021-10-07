#include <stdio.h>

main() {
  int anno;

  printf("Digita l'anno\n");
  scanf("%d", &anno);

  if (anno % 4 == 0)      // anno divisibile per 4
  {                       /* ramo vero */
    if (anno % 100 == 0)  // anno divisibile per 100
    {
      if (anno % 400 == 0)     // anno divisibile per 400
        printf("Bisestile\n"); /* ramo vero */
      else
        printf("Non bisestile\n"); /* ramo falso */
    } else {                     /* ramo falso */
      printf("Bisestile\n");
    }
  } else { /* ramo falso */
    printf("Non bisestile\n");
  }
}