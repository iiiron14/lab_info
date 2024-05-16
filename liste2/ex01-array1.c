#include <stdio.h>
#include <stdlib.h>

int array_equals(int *a, int *b, int n);
void print_array(int *a, int n);

/*
 * FUNZIONE DA REALIZZARE
 * ======================
 * Realizzare la funzione f qui sotto riportata, che dato in ingresso
 * un array di interi a[] di lunghezza n>0, produce in uscita un
 * **nuovo** array di lunghezza dimezzata, ottenuto addizionando due a
 * due gli elementi di posizione opposta di a[] (il primo con l'ultimo,
 * il secondo col penultimo) lasciando eventualmente il valore centrale
 * inalterato.
 * */
int *f(int a[], int n) {
    if(a == NULL)
        return NULL;
    int i=0;
    int size = ((n%2) ? n/2 + 1 : n/2);
    printf("\n----------------------------------\n");
    printf("\nSIZE: %d\n", size);
    int *ret = (int *)malloc((size)*sizeof(int));
    n--;
    while(n >= i){
        printf("\n*(a+i): %d\t*(a+n): %d\n", a[i], a[n]);
        ret[i] = a[i] + a[n];
        
        if(n == i)
            ret[i] = a[i];
        i++;
        n--;
    }
    return ret;
}

int array_equals(int *a, int *b, int n) {
    if (a == NULL) {
        return 0;
    } else {
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return 0;
            }
        }
        return 1;
    }
}

void print_array(int *a, int n) {
    int i;
    printf("[");
    if (a == NULL) {
        printf("NULL");
    } else {
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("]");
}

void test(int in[], int n, int expect[], int m) {
    int *result = f(in, n);
    if (array_equals(result, expect, m)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso ");
        print_array(expect, m);
        printf(", risultato ottenuto ");
        print_array(result, m);
        printf("\n");
    }
    /* qui bisognerebbe usare free(result) per liberare il blocco di
       memoria puntato da 'result', ma omettiamo. */
}

int main(void) {
    int a1[] = {10, 20, 30, 40};
    int o1[] = {50, 50};

    int a2[] = {10, 20, 30, 40, 50, 100};
    int o2[] = {110, 70, 70};

    int a3[] = {10, 20, 30, 40, 50, 100, 70};
    int o3[] = {80, 120, 80, 40};

    int a4[] = {40, 20};
    int o4[] = {60};

    int a5[] = {10, 10, 10, 10, -10};
    int o5[] = {0, 20, 10};

    int a6[] = {40};
    int o6[] = {40};

    test(a1, sizeof(a1) / sizeof(a1[0]), o1, sizeof(o1) / sizeof(o1[0]));
    test(a2, sizeof(a2) / sizeof(a2[0]), o2, sizeof(o2) / sizeof(o2[0]));
    test(a3, sizeof(a3) / sizeof(a3[0]), o3, sizeof(o3) / sizeof(o3[0]));
    test(a4, sizeof(a4) / sizeof(a4[0]), o4, sizeof(o4) / sizeof(o4[0]));
    test(a5, sizeof(a5) / sizeof(a5[0]), o5, sizeof(o5) / sizeof(o5[0]));
    test(a6, sizeof(a6) / sizeof(a6[0]), o6, sizeof(o6) / sizeof(o6[0]));

    return 0;
}
