#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int mymax(int a[], int n) {
    int app(int *, int, int);
    return app(a, 0, n - 1);
}

int app(int a[], int i, int n){
    if(i>=n)
        return MAX(a[i], a[n]);
    if(a[i] > a[n])
        return app(a, i, n - 1);
    return app(a, i + 1, n);
}

int main(int argc, char *argv[]) {
    int a[] = {1, 1, 1};
    printf("Got %d, should be 1\n", mymax(a, sizeof(a) / sizeof(int)));

    int b[] = {1, 2, 2, 2, 3};
    printf("Got %d, should be 3\n", mymax(b, sizeof(b) / sizeof(int)));

    int c[] = {1, 2, 2, 3, 1, 1, 2};
    printf("Got %d, should be 3\n", mymax(c, sizeof(c) / sizeof(int)));

    int d[] = {3, 1, 2, 1, 2};
    printf("Got %d, should be 3\n", mymax(d, sizeof(d) / sizeof(int)));
    return 0;
}
