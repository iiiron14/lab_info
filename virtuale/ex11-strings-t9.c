/* t9.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Realizzare una funzione t9() secondo le specifiche seguenti. La
 * funzione accetta in input una stringa s composta esclusivamente
 * dalle lettere minuscole 'a'..'z'. La funzione restituisce un
 * puntatore ad una nuova stringa, allocata con malloc(), avente la
 * stessa lunghezza di s. Tale stringa deve essere composta dai
 * caratteri '2'..'9' in modo tale che ad ogni lettera di s
 * corrisponda un carattere numerico secondo la codifica seguente:
 *
 * abc -> 2
 * def -> 3
 * ghi -> 4
 * jkl -> 5
 * mno -> 6
 * pqrs -> 7
 * tuv -> 8
 * wxyz -> 9
 *
 * Quindi i caratteri 'a', 'b' e 'c' vengono rappresentati da un
 * singolo carattere '2', i caratteri 'd', 'e', 'f' da un singolo
 * carattere '3' e cosi' via. La codifica sopra e' quella utilizzata
 * dal t9 dei vecchi cellulari. Se lo si reputa utile, si puo' fare
 * uso delle funzioni definite nell'header file <string.h>, gia'
 * incluso nel programma; l'unica funzione che potrebbe risultare
 * utile e' strlen(s), che restituisce la lunghezza di una stringa s.
 *
 * Consiglio: si veda in fondo al file.
 */

#define COD_SIZE    8
#define INT_TO_CHAR   48

static char *cod[COD_SIZE] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char *t9(char *s) {
    void code(char *, char *, int);
    int size=0;
    while(*(s + size++) != '\0') ;
    char *str = (char *)malloc(size*sizeof(char));
    code(s, str, 0);
    *(str + size - 1) = '\0'; // I write in the string till string[size - 2], string[size - 1] = '\0'
    return str;               // the total amount of memory to allocate is size - 1 + 1 = size (because of the zero element)
}

void code(char *s, char *p, int i){
    if(*(s + i) == '\0')
        return;
    for(int j = 0; j < COD_SIZE; j++)
        for(int k=0; *(cod[j] + k) !='\0'; k++)
            if(*(s + i) == *(cod[j] + k))
                *(p + i) = (j + 2 + INT_TO_CHAR);
    code(s, p, i + 1);
}


/**
 ** Non dovrebbe essere necessario modificare la parte seguente
 **/
void test(char *str, char *expect) {
    char *result = t9(str);
    if ((result != NULL) && (strcmp(result, expect) == 0)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: str=%s, risultato atteso=%s, risultato ottenuto=%s\n", str, expect, result);
    }
    free(result);
}

int main(void) {
    test("informatica", "46367628422");
    test("finfa", "34632");
    test("ciao", "2426");
    return 0;
}
/*
 * Consiglio: è possibile evitare if/else utilizzando una tabella (array)
 * che fornisca il mapping (corrispondenza) tra lettere e caratteri numerici.
 */
