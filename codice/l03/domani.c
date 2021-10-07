#include <stdio.h>

main() {
  int g, m, a;
  int giorni_del_mese;

  printf("Digita giorno, mese e anno\n");
  scanf("%d%d%d", &g, &m, &a);

  // calcolo giorni del mese
  if (m == 2)
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
      giorni_del_mese = 29;
    else
      giorni_del_mese = 28;
  else if (m == 4 || m == 6 || m == 9 || m == 11)
    giorni_del_mese = 30;
  else
    giorni_del_mese = 31;

  if (g == 31 && m == 12)  // ultimo dell'anno
    printf("%d/%d/%d\n", 1, 1, a + 1);
  else if (g == giorni_del_mese)  // ultimo del mese
    printf("%d/%d/%d\n", 1, m + 1, a);
  else
    // altri casi
    printf("%d/%d/%d\n", g + 1, m, a);
}