#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE* ft;
  char s[8];
  int i = 0;
  printf("%s\n", argv[0]);
  ft = fopen(argv[1], "r");
  if (ft == NULL) {
    printf("Errore apertura file\n");
    exit(1);
  }
  while (fgets(s, 5, ft) != NULL)
    fprintf(stdout, "%s\n", s);
  fclose(ft);
  return 0;
}