typedef struct {
  int num;  // se num > 0 segno +, se num < 0 segno -
  int den;
} Frazione;

Frazione frazione(int n, int d);
void stampaFrazionaria(Frazione f);
void stampaDecimale(Frazione f);
Frazione somma(Frazione f1, Frazione f2);

