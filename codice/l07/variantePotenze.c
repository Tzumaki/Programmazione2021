#include<stdio.h>
// stampa a video le potenze negative sotto forma di frazione
int potenza (int base, int esp){
    int cont, prod = 1;
    if(esp<0){
        printf("1\n-\n");
        return(potenza(base, -esp));
    }
    
    for (cont = 0; cont < esp; cont++)
        prod *= base;

    return(prod);
}

int main(){
    int b, e;
    printf("-- CALCOLO POTENZE --\n");
    printf("Inserisci base: ");
    scanf("%d",&b);
    printf("Inserisci esponente: ");
    scanf("%d",&e);
    printf("%d\n", potenza(b,e));

    return(0);
}