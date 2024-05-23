#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFDIM 1000

char *word_delimiters = "\"&()_;:,.!?'- \n\t";

/*
 * La funzione seguente restituisce il numero di occorrenze della parola w
 * nella stringa s.
 * Si controlli la documentazione per:
 *    char *strtok(char *str, const char *delim)
 */
int numero_occorrenze_parola(char *s, char *w) {
    int n = 0;
    char *token;
    if ((token = strtok(s, word_delimiters)) == NULL) {
        return 0;
    }
    if (strcmp(token, w) == 0) {
        n++;
    }
    while ((token = strtok(NULL, word_delimiters)) != NULL) {
        if (strcmp(token, w) == 0) {
            n++;
        }
    }
    return n;
}

/**
 * Definire la funzione seguente, che restituisce il numero di occorrenze
 * della parola w nel file fp (già aperto e chiuso esternamente alla funzione).
 * La funzione deve restituire -1 in caso di errore.
 * Nota: si consideri una parola una sequenza di caratteri delimitata
 * da caratteri diversi da 'a'..'z', 'A'..'Z'; si può assumere che i
 * delimitatori di parole sono quelli contenuti nella variabile globale
 * word_delimiters.
 *
 * Si valuti l'uso di
 *         char *fgets(char *s, int size, FILE *stream)
 * con un buffer di dimensione BUFDIM (si veda costante simbolica in alto). Si
 * guardi inoltre la funzione int numero_occorrenze_parola(char *s, char *w) già
 * fornita.
 */
int conta_occorrenze(FILE *fp, char *w) {
    char *buff = (char *)malloc(BUFDIM*sizeof(char));
    int c, i=0, occ = 0;
    while((c = getc(fp)) != EOF){
        if((c >= 'a' && c <= 'z') || (c >= 'A' &&  c <= 'Z')){
            buff[i++] = c;
        }
        if(c < 'A' || (c >'Z' && c < 'a') || c > 'z'){
            buff[i] = '\0';
            occ += numero_occorrenze_parola(buff, w);
            i = 0;
        }
    }
    if(!errno)
        return -1;
    return occ;
}

void test(char *s, char *w, int expected) {
    // FILE *fp = tmpfile();
    FILE *fp = fopen("foo.ignore", "w+");
    if (fputs(s, fp) == EOF) {
        perror("Failed put on test creation");
        exit(1);
    }
    rewind(fp);
    int actual = conta_occorrenze(fp, w);
    printf("Expected: %d. Actual: %d. %s\n", expected, actual, actual != expected ? "TEST FAILURE" : "TEST OK");
    fclose(fp);
}

int main() {
    char s1[] = "ciao, ciao ciao!";
    char s2[] = "..ciao     mondo";
    char s3[] = "! !";
    assert(3 == numero_occorrenze_parola(s1, "ciao"));
    assert(1 == numero_occorrenze_parola(s2, "ciao"));
    assert(0 == numero_occorrenze_parola(s3, "ciao"));

    test("", "", 0);
    test("foo bar", "foo", 1);
    test("foo bar,foo, foo!", "foo", 3);
    test("foo bar,foo, foo!", "bar", 1);
    test("foo bar,foo, foo!", "fo", 0);
    test("foo bar,foo, foo!", "foo,", 0);
}
