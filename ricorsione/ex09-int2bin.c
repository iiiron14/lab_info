#include <stdio.h>
#include <stdlib.h>

int int2bin(int a) {
    if(!a)
        return 0;
    return (a % 2) + int2bin(a/2)*10;
}

int main(int argc, char *argv[]) {
    printf("Got %d, should be 1010\n", int2bin(10));
    printf("Got %d, should be 1011\n", int2bin(11));
    printf("Got %d, should be 1\n", int2bin(1));
    printf("Got %d, should be 0\n", int2bin(0));
    printf("Got %d should be 10000000\n", int2bin(128));
    return 0;
}
