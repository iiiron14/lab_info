#include <stdio.h>

int somma(int);

int main(int argc, char *argv[]){
    if(*argv[1] < 0)
        return -1;
    printf("\nnum: %d", *argv[1]);
    printf("\nLa somma da %d a 0 e': %d", *argv[1], somma(*argv[1]));
    return 0;
}

int somma(int x){
    if(!x)
        return 0;
    return x + somma(x - 1);
}