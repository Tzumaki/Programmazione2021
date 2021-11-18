#include <stdio.h>

typedef struct {
  int num;  // se num > 0 segno +, se num < 0 segno -
  int den;
} Frazione;

Frazione frazione(int n, int d) {
  Frazione f;
  f.num = n;
  f.den = d;
  return f;
}

Frazione leggiFrazione(void) {
  // richiede all'utente num e den e restituisce la corrispondente frazione
  int n, d;
  printf("Digita numeratore e denominatore\n");
  scanf("%d%d", &n, &d);
  return frazione(n, d);
  ;
}

void stampaFrazionaria(Frazione f) {
  printf("%d/%d", f.num, f.den);
}

void stampaDecimale(Frazione f) {
  printf("%f", (float)f.num / f.den);
}

int main() {
  Frazione f1, f2;

  f1 = frazione(2, 4);
  // f2 = leggiFrazione();
  stampaFrazionaria(f1);
  printf("\n");
  stampaDecimale(f1);
  printf("\n");
}