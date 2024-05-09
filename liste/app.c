#include <stdio.h>

void funz(char *p){
    p = "no";
    printf("\ndentro funzione");
    return;
}

int main(){
    char *p = "prova";
    funz(p);
    printf("\n%s", p);
    return 0;
}