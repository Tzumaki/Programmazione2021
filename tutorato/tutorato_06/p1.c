#include <stdio.h>
#define DIM 10

int primo(int n){
    int j=1,i=2;

    //for(i=2;i<n&&j!=0;i++)
    while(j!=0&&i<n){
        j=n;
        while(j>0)
            j-=i;
        i++;
    }

    /*
    if(j!=0)
        return 1;
    
    return 0;
    */

   return j;
}

int main(){
    int a[DIM]; //definiamo la dimensione fisica dell'array
    int i, max=0;
    int n,dl=0;

    do{
        printf("Inserire un numero intero (negativo termina)\n");
        scanf("%d",&n);

        if(n>0){
            a[dl]=n;
            dl++;
        }
    }while(dl<10 && n>0);

    /*int n=1, dl;

    for(dl=0; dl<10 && n>0;dl++){
        printf("Inserire un numero intero (negativo termina)\n");
        scanf("%d",&n);

        if(n>0){
            a[dl]=n;
        }
    }*/

    // dl è la dimensione logica

    for(i=0;i<dl;i++){
        if(primo(a[i]) && max<a[i]){
            max=a[i];
        }
    }

    if(max==0){
        printf("Non sono stati inseriti numeri primi\n");
    }
    else{
        printf("Il numero primo maggiore è: %d\n", max);
    }


    return 0;



}