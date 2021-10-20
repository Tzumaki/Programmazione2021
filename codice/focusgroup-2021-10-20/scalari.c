#include <stdio.h>

main() {
  int i;   // 32 bit
  char c;  // 8 bit
  long l;  // 64 bit

  float x;
  double y;
  long double z;

  c = 'A';  // c = 65;
  c = 2;
  c = '2';  // c = 50;
  printf("%d\n", c / 2);
  printf("%c\n", c);

  x = 1.5;
  y = 3.2;

  printf("%f\n", 1 / (float)2);
}