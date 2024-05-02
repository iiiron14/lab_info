/* azzeraNegativi.c */
#include <stdio.h>
#include <stdlib.h>

void azzeraNegativi(int a[], int n) {
    // TODO
}

/**
 ** Non dovrebbe essere necessario modificare il codice che segue
 **/

/* restituisce 1 se a[] e b[] contengono gli stessi valori, 0 altrimenti */
int array_equals(int a[], int b[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

/* Stampa il contenuto di v[] */
void print_array(const int v[], int n) {
    int i;
    printf("{");
    for (i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("}");
}

void test(int a[], int n, int expect[]) {
    azzeraNegativi(a, n);
    if (array_equals(a, expect, n)) {
        printf("test OK\n");
    } else {
        printf("Test FALLITO: a[]=");
        print_array(a, n);
        printf(", risultato atteso=");
        print_array(expect, n);
        printf("\n");
    }
}

int main(void) {
    int a1[] = {10, 20, 30}, e1[] = {10, 20, 30};
    int a2[] = {10, 20, -5, 30}, e2[] = {10, 20, 0, 30};
    int a3[] = {10, 20, -5, -1, 30}, e3[] = {10, 20, 0, 0, 30};
    int a4[] = {-1, -2, -3}, e4[] = {0, 0, 0};
    int a5[] = {666}, e5[] = {666};
    /* ANSI C proibisce la dichiarazione di array vuoti; nel test sotto passiamo
     * come secondo argomento alla funzione test il valore 0, per cui la
     * funzione dovrà trattare a5[] come se fosse vuoto
     * */
    test(a1, sizeof(a1) / sizeof(a1[0]), e1);
    test(a2, sizeof(a2) / sizeof(a2[0]), e2);
    test(a3, sizeof(a3) / sizeof(a3[0]), e3);
    test(a4, sizeof(a4) / sizeof(a4[0]), e4);
    test(a5, 0, e5);
    return 0;
}
