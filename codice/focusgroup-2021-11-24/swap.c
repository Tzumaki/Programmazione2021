#include <stdio.h>

void swap(int* pm, int* pn) {
  int t = *pm;
  *pm = *pn;
  *pn = t;
}

int main() {
  int a = 5, b = 3;
  printf("%d %d\n", a, b);
  // scambio i valori di a e b
  swap(&a, &b); // simulazione del passaggio per riferimento
  printf("%d %d\n", a, b);
}