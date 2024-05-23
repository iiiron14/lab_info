#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f = fopen("aaa", "w");
    fwrite("a", sizeof(char), 2, f);
    return 0;
}