#include <stdio.h>

float potenza(float base, int esponente) {
  float p = 1;
  int i;
  for (i = 1; i <= esponente; i++)
    p = p * base;
  // dentro p c'è base^esponente
  return p;
}

int main() {
  float x = 1.5;

  printf("%f\n", potenza(x, 3));

  return 0;
}