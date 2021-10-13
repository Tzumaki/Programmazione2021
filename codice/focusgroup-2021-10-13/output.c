// scrivere un programma che stampa il triplo dei numeri compresi fra 5 e 10

#include <stdio.h>
main(){
int i;
for (i = 5; i <=10;i++) // i assume la sequenza di valori 5, 6, 7, 8, 9, 10
   printf("%d\n", 3 * i); // map (3*, valori di i)
}