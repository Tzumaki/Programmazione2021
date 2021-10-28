#include <math.h>
#include <stdio.h>

float media(float a, float b) {
  return (a + b) / 2.0;
}

float radq(float c) {
  float x = 1.0;
  while (fabsf(x * x - c) > 1e-5)
    // assegno a x la media di x e c/x
    x = media(x, c / x);
  return x;
}

int main(void) {
  float a;
  printf("Digita un numero\n");
  scanf("%f", &a);
  if (a < 0) {
    printf("%f e` negativo\n", a);
    return -1;
  }
  printf("La radice quadrata di %.2f e` circa %f\n", a, radq(a));
  return 0;
}