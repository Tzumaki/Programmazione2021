#include "date.h"

int giorno_giuliano(int g, int m, int a) {
  // restituisce il numero di giorni trascorsi dal 1/1/4713 a.C alla data g/m/a
  int N0, N1, N2, N3;
  N0 = (m - 14) / 12;
  N1 = 1461 * (a + 4800 + N0) / 4;
  N2 = 367 * (m - 2 - 12 * N0) / 12;
  N3 = 3 * (a + 4900 + N0) / 400;
  return N1 + N2 - N3 + g - 32075;
}

int diff_date(Data d1, Data d2) {
  return giorno_giuliano(d1.giorno, d1.mese, d1.anno) -
         giorno_giuliano(d2.giorno, d2.mese, d2.anno);
}