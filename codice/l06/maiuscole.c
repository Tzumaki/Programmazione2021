#include <stdio.h>

char toUpperCase(char c) {
  if (c >= 'a' && c <= 'z')  // se c è una lettera minuscola
    return c - 32;           // restituire la corrispondente maiuscola
  // altrimenti
  // restituire c
  else
    return c;
}

int main() {
  char c;
  int i;
  do {
    scanf("%c", &c);
    printf("%c", toUpperCase(c));
  } while (c != '\n');

  return 0;
}