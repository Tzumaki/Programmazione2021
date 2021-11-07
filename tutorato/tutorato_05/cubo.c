#include <stdio.h>
#define DIM 100

int cubo(int n){
    int i,j,s=0;

    for(i=1;i<=n;i++){
        for(j=0;j<n;j++){
            s+=n;
        }
    }

    return s;
}

int main(){
    int a[DIM];
    int M,i;

    do{
        printf("Inserire la dimensione dell'array\n");
        scanf("%d",&M);
    }while(M<=0 || M>100);

    for(i=1;i<=M;i++){
        a[i-1]=cubo(i);
    }

    for(i=0;i<M;i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    return 0;

}