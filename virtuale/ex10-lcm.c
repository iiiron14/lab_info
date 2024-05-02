#include <stdio.h>
#include <stdlib.h>

int lcm(int a, int b) {
    // TODO
    return -1;
}

int main(int argc, char *argv[]) {
    printf("Got %d, should be 20\n", lcm(20, 20));
    printf("Got %d, should be 20\n", lcm(20, 10));
    printf("Got %d, should be 20\n", lcm(10, 20));
    printf("Got %d, should be 55\n", lcm(11, 5));
    printf("Got %d, should be 1800\n", lcm(360, 300));
    return 0;
}
