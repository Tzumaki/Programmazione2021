#include <stdio.h>

int main() {
  int a = 750;
  int b = 100;
  int* p;
  p = &a;
  *p = 25;
  p = &b;
  *p = 25;
  *&b = 200;
}