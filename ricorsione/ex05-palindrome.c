/* palindrome.c */
#include <stdio.h>
#include <stdlib.h>

#define POSITIVE 1
#define NEGATIVE -1

int *palindrome(int n) {
    int sign=POSITIVE;
    if(n < 0){
        sign = NEGATIVE;
        n = n*(-1);
    }
    printf("n: %d\n", n);
    void build_array(int *, int, int, int, int);
    int *r = (int *)malloc((n*2 + 1)*sizeof(int));

    build_array(r, n*2, 0, n, sign);
    return r;
}

void build_array(int r[], int n, int i, int f, int sign){
    *(r + n) = f*sign;
    *(r + i) = f*sign;
    if(f == 0)
        return;
    return build_array(r, n-1, i + 1, f - 1, sign);
}

/**
 ** Non dovrebbe essere necessario modificare il codice che segue
 **/

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

int main(void) {
    int n = -2;
    int *r = palindrome(n);
    if(n < 0)
        n *= NEGATIVE;
    print_array(r, 2 * n + 1);
    printf("\n");
    free(r);
    return 0;
}
