#include <stdio.h>

int somma(int x){
    if(!x)
        return 0;
    return x + somma(x - 1);
}

int main(void) {
    int a = 4;
    printf("la somma dei primi %d numeri e' %d\n", a, somma(a));
    return 0;
}
