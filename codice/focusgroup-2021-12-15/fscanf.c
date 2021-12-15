#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *ft;
    char s[2];
    ft = fopen("testo.txt", "rt");
    if (ft == NULL) {
        exit(1);
    }
    while (fscanf(ft, "%s", s) == 1){
        // in c c'è un carattere del file
        printf("%c", s[0]);
    }
    fclose(ft);
    return 0;
}