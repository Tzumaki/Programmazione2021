#include <stdio.h>

int f(int i){
    int a;
    a=2*i;
    return a;
}

int main(){
    int k;
    k = 5;
    printf("%d\n", f(k));
    k = 0;
}
