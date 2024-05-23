#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "input-formattato.txt"
#define OUTPUT_FILE "output-formattato.txt"

/**
 * Implementare la funzione sottostante che deve leggere dal file
 * 'input-formattato.txt' delle linee formattate come segue: <stringa di 3
 * caratteri>,<intero di max 5 cifre>,<singolo carattere> e scrivere (creare) un
 * file `output-formattato.txt` dove si cambia la formattazione come segue:
 *    <intero di max 5 cifre>,<singolo carattere>,<stringa di 3 caratteri>
 * Ad esempio, una riga "aaa,  999,z" va mappata a "  999,z,aaa".
 * Si usi opportunamente le funzioni
 *     int fscanf(FILE *stream, const char *format, ...);
 *     int fprintf(FILE *stream, const char *format, ...);
 */
void f() {
    // TODO
}

int main() {
    f();
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "rb")) == NULL) {
        perror("TEST FAILURE");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET); // rewind();
    char buffer[fsize + 1]; // +1 per il NULL-terminatore
    if (fread(buffer, 1, fsize, fp) < fsize) {
        perror("TEST FAILURE");
        exit(1);
    }
    char *expected = " 2011,z,aaa\n99999,y,bbb\n    0,x,ccc\n";
    buffer[fsize] = '\0';
    if (strcmp(buffer, expected) != 0) {
        fprintf(stderr, "TEST FAILURE.\nExpected: \"\n\%s\n\"\nActual: \"\n%s\n\"\n", expected, buffer);
        printf("%d", buffer[fsize - 1]);
        exit(1);
    }
    fclose(fp);
    remove(OUTPUT_FILE);
    printf("TEST SUCCESS.\n");
    return 0;
}
