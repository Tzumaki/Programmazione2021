// Laboratorio 05 Approssimazione Seno
// Sto usando troppe variabili? Ci sono migliorie da implementare?
#include <stdio.h>
main() {
  float x;  // argomento del seno
  printf(
      "Inserire angolo in radianti per calcolarne un'approssimazione del seno");
  scanf("%f", &x);

  float s;  // accumulatore della sommatoria che alla fine conterrà l'appr. del
            // seno

  int n;        // contatore sommatoria
  int j;        // contatore for dei vari termini (potenze e fattoriale)
  float segno;  // accumulatore (-1)^n
  float pot;    // accumulatore x^(2n+1)
  float fatt;   // accumulatore fattoriale

  fatt = 1;
  pot = x;
  s = x;

  for (n = 1; n <= 9; n++) {
    // parte l'iterazione per n da o fino a 9 della sommatoria
    segno = n % 2 == 0 ? 1 : -1;  // inizializzo variabili:

    pot = pot * x * x;

    fatt = fatt * (2 * n) * (2 * n + 1);

    s = s + (segno * pot) / (fatt);  // aggiorno l'approssimazione
  }

  printf("%f\n", s);  // stampa del seno (approssimato)
}

// Sto usando troppe variabili? Ci sono migliorie da implementare?