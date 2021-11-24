#include <stdio.h>

typedef struct {
  int num;  // se num > 0 segno +, se num < 0 segno -
  int den;
} Frazione;

int MCD(int a, int b) {
  while (a != b)
    if (a > b)
      a = a - b;
    else
      b = b - a;
  return a;
}

int valAssoluto(int d) {
  return d >= 0 ? d : -d;
}

Frazione frazione(int n, int d) {
  Frazione f;
  int m = MCD(valAssoluto(n), valAssoluto(d));
  f.num = n / m;
  f.den = d / m;
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

  f1 = frazione(4, 6);
  f2 = frazione(1,5);
  stampaFrazionaria(f1);
  printf("\n");
  stampaDecimale(f1);
  printf("\n");
}