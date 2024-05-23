#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s ="ciao";
    for(char *a=s;*a;a++)
        printf("%c", *a);
    return 0;
}