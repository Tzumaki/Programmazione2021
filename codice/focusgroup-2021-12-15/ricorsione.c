#include <stdio.h>

int ft(int n) {
  int p = 1;
  int c;
  for (c = 1; c <= n; c++)
    p = p * c;
  return c;
}

int f(int n) {
  if (n < 2)  // caso base
    return 1;
  else  // caso ricorsivo
    return n * f(n - 1);
}

int main() {
  printf("%d\n", f(4));
  return 0;
}