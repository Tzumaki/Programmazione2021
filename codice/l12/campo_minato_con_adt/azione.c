#include <stdio.h>

#include "azione.h"

Azione leggiAzione() {
  char s[3];
  Azione a;
  printf("Quale cella vuoi scoprire?");
  scanf("%s", s);  // esempio "c4" corrisponde {riga = 3; colonna = 2};
  a.colonna = s[0] - 'a';
  a.riga = s[1] - '1';
  return a;
}
