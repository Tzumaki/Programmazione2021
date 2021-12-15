#include <stdio.h>

#include "casella.h"
#include "azione.h"
#include "gioco.h"

int main() {
  Gioco gioco;
  Azione azione;
  
  inizializza(&gioco);
  while (valutazione(gioco) == InCorso) {
    stampa(gioco);
    azione = leggiAzione();
    applica(&gioco, azione);
    valuta(&gioco);
  }
  switch (valutazione(gioco)) {
    case Sconfitta:
      printf("Hai perso\n");
      break;
    case Vittoria:
      printf("Hai vinto");
      break;
  }
  return 0;
}