#include <stdio.h>

float radice2(float y){
    float a,b,m,d;

    if(y>1){
        a=1;
        b=y;
    }else{
        a=y;
        b=1;
    }

    do{
        m=(a+b)/2.0;
        if(m*m<y){
            a=m;
        }
        else{
            b=m;
        }
        d=m*m-y;

        if(d<0)
            d=-d;
    }while(d>1e-5); //1.0/(10*10*10*10*10)

    return m;
}

int main(){
    float a[10], n; //10 è la dimensione fisica dell'array
    int i, c=0;

    printf("Inserisci 10 valori\n");
    for(i=0;i<10;i++){
        scanf("%f",&n);
        if(n>0){
            a[c]=radice2(n);
            c++;
        }
    }

    // c è la dimensione logica dell'array
    for(i=0;i<c;i++){
        printf("%f\n",a[i]);
    }

    return 0;

}