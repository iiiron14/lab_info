#include <stdio.h>
#include <stdlib.h>

void print_array(int *a, int n);

/*
    FUNZIONE DA REALIZZARE
    ======================

    Realizzare la funzione ultimozero qui sotto riportata che prende
    in ingresso un array di interi 'array', la sua dimensione 'size' e
    il puntatore 'pos' ad una variabile intera. La funzione deve
    trovare l'ultimo zero presente nell'array, e quindi deve
    depositare in 'pos' la sua posizione (ossia l'indice, un intero
    compreso fra 0 e size-1), e in piu' deve tornare come risultato il
    puntatore alla sua posizione in memoria.  Se non ci fossero zeri,
    il contenuto di 'pos' non va modificato, e si deve ritornare NULL.
*/
int *ultimozero(int a[], int size, int *pos) {
    int i;
    for(i = size - 1; i >= 0; i--)
        if(!a[i]){
            *pos = i;
            return &a[i];
        }
    return NULL;
}

void print_array(int *a, int n) {
    printf("[");
    if (a == NULL) {
        printf("NULL");
    } else {
        int i;
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("]");
}

void test(int a[], int n, int *expect_result) {
    int pos = -1;
    int *result = ultimozero(a, n, &pos);
    if (result == expect_result && (expect_result == NULL || result == &a[pos])) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO\n");
    }
}

int main(void) {
    int a[] = {10, 13, -1, 21, 1}, *posa = NULL;
    int b[] = {4, 0, 77, 77, 80}, *posb = &b[1];
    int c[] = {31, 0, 21, 0, -1}, *posc = &c[3];
    int d[] = {15, 0, 18, 0, 0}, *posd = &d[4];
    int e[] = {0, 0, 0, 0, 0, 0, 0}, *pose = &e[6];

    test(a, sizeof(a) / sizeof(a[0]), posa);
    test(b, sizeof(b) / sizeof(b[0]), posb);
    test(c, sizeof(c) / sizeof(c[0]), posc);
    test(d, sizeof(d) / sizeof(d[0]), posd);
    test(e, sizeof(e) / sizeof(e[0]), pose);

    return 0;
}
