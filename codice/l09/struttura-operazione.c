#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;  // se num > 0 segno +, se num < 0 segno -
  int den;
} Frazione;

typedef enum { add, sot, mol, quo } Operatore;

typedef struct {
  Operatore op;
  Frazione f1, f2;
} Operazione;

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
  // sintassi: 2/3  oppure 2 / 3
  int n, d;
  char c;
  // leggo numeratore
  scanf("%d", &n);

  c = leggiCarattere();
  if (c != '/') {
    printf("Errore di sintassi\n");
    exit(2);
  }

  // leggo il denominatore
  scanf("%d", &d);
  // inizializzo la Frazione all'indirizzo pf chiamando frazione
  // scanf("%d%d", &pf->num, &pf->den);
  frazione(n, d, pf);
}

char leggiCarattere(void) {
  char c;
  do {
    scanf("%c", &c);
  } while (c == ' ');

  return c;
}

void leggiOperazione(Operazione* po) {
  char c;
  // lettura primo operando
  leggiFrazione(&(po->f1));
  // lettura operatore

  c = leggiCarattere();

  switch (c) {
    case '+':
      po->op = add;
      break;
    case '-':
      po->op = sot;
      break;
    case '*':
      po->op = mol;
      break;
    case '/':
      po->op = quo;
      break;
    default:
      printf("%c non è un operatore\n");
      exit(3);
  }

  // lettura secondo operando
  leggiFrazione(&(po->f2));
}

void somma(Frazione f1, Frazione f2, Frazione* pf) {
  frazione(f1.num * f2.den + f1.den * f2.num, f1.den * f2.den, pf);
}

void differenza(Frazione f1, Frazione f2, Frazione* pf) {
  frazione(f1.num * f2.den - f1.den * f2.num, f1.den * f2.den, pf);
}

void prodotto(Frazione f1, Frazione f2, Frazione* pf) {
  frazione(f1.num * f2.num, f1.den * f2.den, pf);
}

void quoziente(Frazione f1, Frazione f2, Frazione* pf) {
  frazione(f1.num * f2.den, f1.den * f2.num, pf);
}

int main() {
  Operazione o;
  Frazione ris;
  leggiOperazione(&o);
  // valuta(... o... ris...);
  // stampa(&ris);
  return 0;
}