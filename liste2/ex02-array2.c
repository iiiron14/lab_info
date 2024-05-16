#include <stdio.h>
#include <stdlib.h>

int array_equals(int *a, int *b, int n);
void print_array(int *a, int n);

/*
  FUNZIONE DA REALIZZARE
  ======================

  Realizzare la funzione f qui sotto riportata, che dato un array di
  interi a[] di lunghezza n>2 che contiene sempre almeno due 0,
  restituisce un **nuovo** array contenente i valori di a[] tranne
  quelli compresi fra il primo e secondo 0 (estremi inclusi).  Si
  garantisce che il risultato conterrà sempre almeno un elemento
  (quindi non dovrà mai essere restituito l'array vuoto). Si faccia
  riferimento ai test per alcuni esempi. Si presti attenzione ad
  allocare lo spazio di memoria corretto per l'array risultato (quindi
  non bisogna allocate più spazio di quello effettivamente
  richiesto).
*/

#define IN 1
#define OUT 0

int first_index(int *a, int size, int k){
    int i;
    for(i=0; i < size; i++)
        if(a[i] == k)
            return i;
    return -1;
}

int second_index(int *a, int size, int k){
    int i = 0, cond = OUT;
    for(i = 0; i < size; i++){
        if(cond && (a[i] == k))
            return i;
        if(a[i] == k)
            cond = IN;
    }
    return -1;
}

int *f(int *a, int n) {
    int first = first_index(a, n, 0);
    int second = second_index(a, n, 0);
    int size = n - (second - first + 1);
    int *b = (int *)malloc(size*sizeof(int));
    int i, j = 0;
    for(i=0; i<n; i++)
        if(i < first || i > second)
            *(b + j++) = a[i];
    return b;
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

void test(int in[], int n, int expect[], int m) {
    int *result = f(in, n);
    if (array_equals(result, expect, m)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO\n");
    }
}

int main(void) {
    int in1[] = {10, 20, 30, 0, 40, 50, 0, 60, 70};
    int out1[] = {10, 20, 30, 60, 70};

    int in2[] = {10, 20, 30, 0, 0, 60, 70, 80, 90};
    int out2[] = {10, 20, 30, 60, 70, 80, 90};

    int in3[] = {0, 20, 0, 30, 0, 60, 70, 80, 90};
    int out3[] = {30, 0, 60, 70, 80, 90};

    int in4[] = {60, 0, 70, 0, 0};
    int out4[] = {60, 0};

    test(in1, sizeof(in1) / sizeof(in1[0]), out1, sizeof(out1) / sizeof(out1[0]));
    test(in2, sizeof(in2) / sizeof(in2[0]), out2, sizeof(out2) / sizeof(out2[0]));
    test(in3, sizeof(in3) / sizeof(in3[0]), out3, sizeof(out3) / sizeof(out3[0]));
    test(in4, sizeof(in4) / sizeof(in4[0]), out4, sizeof(out4) / sizeof(out4[0]));

    return 0;
}
