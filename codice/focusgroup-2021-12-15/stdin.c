#include <stdio.h>

int f (FILE *f){
    fscanf(f, ...);
}

int main(){
    FILE *ft;
    ft = fopen(...);

    f(ft);
    fclose(ft);
    f(stdin);
}