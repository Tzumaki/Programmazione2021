#include <stdio.h>

typedef enum {lun, mar, mer, gio, ven, sab, dom} Giorno;

int main(){
    Giorno g;
    g == mer;
    if (g == mer) printf("ABC");
}
