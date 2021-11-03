#include <stdio.h>

float valoreAssoluto(float x) {
  if (x >= 0)
    return x;
  else
    return -x;
}

float radice(float a) {
  float x = 1.0;
  while (valoreAssoluto(x * x - a) > 1e-5)
    x = (x + a / x) / 2.0;
  return x;
}

float f(int n) {
  float quoziente;
  quoziente = (n - 1.0) / (n + 1.0);
  return radice(quoziente);
}

int main() {
  int A, B;
  int n;
  printf("Digita due interi\n");
  scanf("%d%d", &A, &B);
  for (n = A; n <= B; n++)
    if (n % 2 != 0)
      printf("%d\n", n);
    else
      printf("%f\n", f(n));
  return 0;
}