#include <stdio.h>

main() {
  // definizione di una variabile di tipo carattere
  char c;

  // lettura carattere da input
  scanf("%c", &c);

  // stampa della classe del carattere: minuscola, maiuscola, cifra, altro

  if (c >= 'a' && c <= 'z')  // il codice ASCII di c è compreso fra 97 e 122
    printf("minuscola\n");
  else if (c >= 'A' && c <= 'Z')
    printf("maiuscola\n");
  else if (c > '0' && c <= '9')
    printf("cifra\n");
  else
    printf("altro\n");
}