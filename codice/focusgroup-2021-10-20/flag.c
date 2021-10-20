#include <stdio.h>

main() {
  int pin;
  int corretto; // flag di correttezza del pin inserito
  int n_tentativi; // contatore dei tentativi
  corretto = 0;
  n_tentativi = 0;
  while (!corretto && n_tentativi < 3) {
    printf("Digita il PIN\n");
    scanf("%d", &pin);
    n_tentativi++;
    if (pin == 44121)
        corretto = 1;
  }
  if (corretto)
    printf("Accesso consentito\n");
  else
    printf("Accesso negato\n");
}