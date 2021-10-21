#include <stdio.h>

main(){
    int n;
    scanf("%d", &n);
    // stampa del valore assoluto di n
    printf("%d\n", n < 0 ? -n : n);
}