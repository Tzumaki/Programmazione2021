#include <stdio.h>

int main() {
  FILE* ft;
  char s[8];
  int i = 0;
  ft = fopen("testo.txt", "r");
  if (ft == NULL) {
    printf("Errore apertura file\n");
    exit(1);
  }
  while (fgets(s, 5, ft) != NULL)
    fprintf(stdout, "%s\n", s);
  fclose(ft);
  return 0;
}