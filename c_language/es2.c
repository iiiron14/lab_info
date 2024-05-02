#include <stdio.h>

#define CHAR_TO_INT 48

int somma_due_interi(int , int );

int main(int argc, char *argv[]){
    printf("la somma tra %d e %d e' : %d", *argv[1] - CHAR_TO_INT, *argv[2] - CHAR_TO_INT, somma_due_interi(*argv[1] - CHAR_TO_INT, *argv[2] - CHAR_TO_INT)); 
    return 0;
}

int somma_due_interi( int x, int y ){
    if(!x)
        return y;
    if(!y)
        return x;
    return 1 + somma_due_interi(x, y - 1);
}