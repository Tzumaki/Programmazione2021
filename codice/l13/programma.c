#include <stdio.h>

#include "lista.h"

int main() {
  int i, a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  Lista l;
  inizializza(&l);
  while (l && l->dato) {
    a[l->dato] = l->dato;
    l = l->next ? (l->next)->next : l->next;
  }
  for (i = 9; i >= 0; i--)
    printf("%d\n", a[9 - i]);
  return 0;
}