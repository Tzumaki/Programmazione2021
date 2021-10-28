#include <stdio.h>

float potenza(int base, int esp) {
  int cont, prod = 1;
  if (esp < 0)
    return 1 / potenza(base, -esp);
  for (cont = 0; cont < esp; cont++)
    prod *= base;
  return prod;
}

int main() {
  // 2^3 = 8
  printf("%f\n", potenza(2, 3));  // dovrebbe stampare 8
  // 2^0 = 1
  printf("%f\n", potenza(2, 0));  // dovrebbe stampare 1
  // 2^(-3) = 1/8
  printf("%f\n", potenza(2, -3));  // dovrebbe stampare 0.125
}