#include <stdio.h>

int main() {
  int x;

  printf("%d\n" , (3 + 2 * 5 - 8 ? (x = 17) : (x = 5)) + 8.0);
}