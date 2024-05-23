#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int size);
void print_array(int *a, int size);

/*  Realizzare la funzione sotto riportata che presi in ingresso due puntatori a
   file (e quindi a file già aperti e non da chiudere), un carattere e una
   stringa, riversa il file di ingresso in uscita sostituendo ogni occorrenza
   del carattere con l'intera stringa. La funzione ritorni un valore negativo se
   le letture/scritture su file comportano errori, altrimenti ritorni il numero
   di sostituzioni effettuate.

    Come riferimento si consideri che l'esecuzione del main chiama la funzione
   su stdin e stdout, e preleva carattere e stringa da linea di comando. Ad
   esempio richiamando il programma con:

    ./E3 a prova

    e dando in ingresso il file di testo:

    aac
    fkdkfl fdklfkd akfldk
    xa
    a

    si dovrà avere in uscita:

    provaprovac
    fkdkfl fdklfkd provakfldk
    xprova
    prova

    Per lavorare sui file si suggerisce di usare queste funzioni già viste in
   aula:

    int fgetc(FILE *f);
    La funzione fgetc() legge un carattere da f.
    Ritorna il carattere letto oppure EOF se e' stato riscontrato un errore o la
   fine del file.

    int fputc(int c, FILE *f);
    La funzione fputc() scrive il carattere c su f.
    Ritorna il carattere scritto se la funzione ha successo, altrimenti EOF in
   caso di errore.

    */

int f(FILE *in, FILE *out, char c, char *s) { return 0; }

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Numero di argomenti errato\n");
        exit(1);
    }
    int h = f(stdin, stdout, argv[1][0], argv[2]);
    if (h < 0) {
        printf("Errore\n");
        exit(1);
    } else {
        printf("Effettutate %d sostituzioni\n", h);
        exit(0);
    }
}

int array_equals(int a[], int b[], int size) {
    for (; size--;)
        if (a[size] != b[size])
            return FALSE;
    return TRUE;
}

void print_array(int *a, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("/n");
}
