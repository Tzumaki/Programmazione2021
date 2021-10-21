#include <stdio.h>

main() {
  1 ? printf("1\n") : printf("0\n");

  printf("%d\n", 3 > 2 || 5 > 6 ? 5 : 6);
}