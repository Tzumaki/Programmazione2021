#include <stdio.h>

int main(){
    int n, fivePower, zeroCount=0;

    printf("Inserire numero\n");
    scanf("%d", &n);

    for(fivePower=5;fivePower<=n;fivePower*=5){
        zeroCount=zeroCount + n/fivePower;
    }

    printf("Il numero di zeri è pari a: %d",zeroCount);

    return 0;
}