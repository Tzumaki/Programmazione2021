#include <stdio.h>
#include <stdlib.h>

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

void frazione(int n, int d, Frazione* pf) {
  int m;
  if (d == 0) {
    printf("Errore: denominatore nullo\n");
    exit(1);
  }
  if (n == 0) {
    pf->num = 0;
    pf->den = 1;
    return;
  }
  m = MCD(valAssoluto(n), valAssoluto(d));
  pf->num = n / m;
  // equivalente a (*pf).num = n / m;
  pf->den = d / m;
}

void stampaFrazione(Frazione* pf) {
  printf("%d/%d", pf->num, pf->den);
}

void leggiFrazione(Frazione* pf) {
  int n, d;
  // leggo numeratore e denominatore
  scanf("%d%d", &n, &d);
  // inizializzo la Frazione all'indirizzo pf chiamando frazione
  // scanf("%d%d", &pf->num, &pf->den);
  frazione(n, d, pf);
}

void somma(Frazione f1, Frazione f2, Frazione *pf) {
  frazione(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den, pf);
}

void differenza(Frazione f1, Frazione f2, Frazione *pf) {
  frazione(f1.num * f2.den - f1.den * f2.num, f1.den * f2.den, pf);
}

void prodotto(Frazione f1, Frazione f2, Frazione *pf) {
  frazione(f1.num * f2.num, f1.den * f2.den, pf);
}

void quoziente(Frazione f1, Frazione f2, Frazione *pf) {
  frazione(f1.num * f2.den, f1.den * f2.num, pf);
}

int main() {
  Frazione g1, g2, g3;
  leggiFrazione(&g1);
  leggiFrazione(&g2);
  somma (g1, g2, &g3);
  stampaFrazione(&g3); printf("\n");
  differenza (g1, g2, &g3);
  stampaFrazione(&g3); printf("\n");
  prodotto (g1, g2, &g3);
  stampaFrazione(&g3); printf("\n");
  quoziente (g1, g2, &g3);
  stampaFrazione(&g3); printf("\n");
  printf("\n");
  return 0;
}