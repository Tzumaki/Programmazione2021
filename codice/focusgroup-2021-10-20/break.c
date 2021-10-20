#include <stdio.h>

main() {
  int pin;
  int n_tentativi;  // contatore dei tentativi
  n_tentativi = 0;
  while (n_tentativi < 3) {
    printf("Digita il PIN\n");
    scanf("%d", &pin);
    n_tentativi++;
    if (pin == 44121)
      break;
  }
  if (pin == 44121)
    printf("Accesso consentito\n");
  else
    printf("Accesso negato\n");
}