#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char nome[20];
  char indirizzo[30];
  char telefono[15];
} Persona;

int main() {
  int i;
  Persona persone[5] = {{"Mario_Rossi", "Via_Roma_15", "333_1234567"},
                        {"Giulia_Bianchi", "Piazza_Milano_23", "347_7654321"},
                        {"Elisa_Verdi", "Via_Italia_44", "348_11122233"},
                        {"Maria_Russo", "Viale_Cavour_18", "320_3849234"},
                        {"Carlo_Esposito", "Via_Mazzini_25", "380_98765432"}};

  FILE* pft;
  FILE* pfb;

  if ((pft = fopen("rubrica.txt", "wt")) == NULL) {
    printf("Errore apertura rubrica.txt\n");
    exit(1);
  }

  if ((pfb = fopen("rubrica.dat", "wb")) == NULL) {
    printf("Errore apertura rubrica.dat\n");
    exit(3);
  }

  for (i = 0; i < 5; i++) {
    fprintf(pft, "%s %s %s\n", persone[i].nome, persone[i].indirizzo,
            persone[i].telefono);
    fwrite(&persone[i], sizeof(Persona), 1 , pfb);
  }

  if (fclose(pft) != 0) {
    printf("Errore chiusura file rubrica.txt\n");
    exit(2);
  };

  if (fclose(pfb) != 0) {
    printf("Errore chiusura file rubrica.dat\n");
    exit(4);
  };

  return 0;
};