#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <string.h>

int rnd_int(int a, int b) {
  return a + rand() % (b - a + 1);
}

int main() {
  char s[37] = "https://meet.google.com/xxx-xxxx-xxx";
  int i;

  srand(time(NULL));

  // oppure:
  // char s[37];
  // strcpy(s, "https://meet.google.com");

  for (i = 24; i <= 35; i++)
    if (s[i] == 'x')
      s[i] = rnd_int('a', 'z');
  
  printf("%s\n", s);
}
