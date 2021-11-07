#include <stdio.h>

int main(){
    int i;

    for(i=0;i<500;i++){
        printf("%d ", i%2?i+500:i+1);
    }
    printf("\n");
}