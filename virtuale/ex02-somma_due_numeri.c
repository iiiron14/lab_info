#include <stdio.h>

int somma_due_numeri(int x, int y) {
    // TODO
    return -1;
}

int main(void) {
    int x = 1, y = 10;
    printf("la somma di %d e %d e' %d\n", x, y, somma_due_numeri(x, y));
    x = 2, y = 1;
    printf("la somma di %d e %d e' %d\n", x, y, somma_due_numeri(x, y));
    x = 0, y = 1;
    printf("la somma di %d e %d e' %d\n", x, y, somma_due_numeri(x, y));
    x = 1, y = 0;
    printf("la somma di %d e %d e' %d\n", x, y, somma_due_numeri(x, y));
    return 0;
}
