#include <stdio.h>

#define SIZE 9

int evens(int a[], int n) ;
void print_array(int a[], int n);

int main(){
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("Array a:\n");
    print_array(a, SIZE);
    printf("\nIn a ci sono %d numeri pari", evens(a, SIZE - 1));
    return 0;
}

int evens(int a[], int n){
    if(!n)
        return !(a[n] % 2);
    // printf("\n%d resto %d", a[n], a[n] % 2);
    return !(a[n] % 2) + evens(a, n - 1);
}

void print_array(int a[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}