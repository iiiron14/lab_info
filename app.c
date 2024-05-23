#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f = fopen(".\\io\\input-formattato.txt", "r");
    if(f == NULL)
        perror("\nErrore aprendo il file");
    int line;
    int intero;
    char str[3];
    char c;
    /* printf("\nValore fscanf: %d", fscanf(f, "%s,",str));
    printf("\nValore fscanf: %d", fscanf(f, "%d,", &intero));
    printf("\nValore fscanf: %d", fscanf(f, "%c\n",&c));
    printf("\nstr: %s, intero: %d, carattere: %c\n", str, intero, c); */
    line = fscanf(f, "%[^,], %d , %c\n", str, &intero, &c);
    printf("str: %s, intero: %d, carattere: %c\n", str, intero, c);
    for(int i=0;i<3;i++)
        printf("%c", str[i]);
    printf("\nline: %d", line);
    fclose(f);
    return 0;
}