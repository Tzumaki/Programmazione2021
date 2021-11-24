#include <stdio.h>

int main() {
  int a = 5, b = 3;
  int *p1, *p2;

  p1 = &a;
  p2 = &b;
  // *p1 = *p2 vs p1 = p2
  // *p1 = *p2;
  p1 = p2;
  *p1 = 10;
}