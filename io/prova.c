#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE "C:\\Users\\User\\Desktop\\uni\\lab_info\\io\\input-formattato.txt"
#define OUTPUT_FILE "C:\\Users\\User\\Desktop\\uni\\lab_info\\io\\output-formattato.txt"

/**
 * Implementare la funzione sottostante che deve leggere dal file 'input-formattato.txt'
 * delle linee formattate come segue:
 *    <stringa di 3 caratteri>,<intero di max 5 cifre>,<carattere>
 * e scrivere un file `output-formattato.txt` dove si cambia la formattazione come segue:
 *    <intero di max 5 cifre>,<carattere>,<stringa di 3 caratteri>
 */
void f()
{
    FILE *in, *out;
    if ((in = fopen(INPUT_FILE, "r")) == NULL)
    {
        perror("Cannot open input file");
        return;
    }
    if ((out = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        perror("Cannot open input file");
        return;
    }

    char s[4]; // 15 + 1 per il NULL-terminatore
    int d;
    char c;
    while (fscanf(in, "%3s,%5d,%c\n", s, &d, &c) != EOF)
    {
        // printf("Writing: %5d,%c,%3s\n", d, c, s);
        if (fprintf(out, "%5d,%c,%3s\n", d, c, s) == EOF)
        {
            perror("Failed write");
            return;
        }
    }
    // if(feof(in)) { printf("Got EOF.\n"); }
    if (ferror(in))
    {
        perror("Failed");
    }

    if (fclose(in) != 0 || fclose(out) != 0)
    {
        perror("Problem in closing file descriptors");
    };
}

int main()
{
    f();
    FILE *fp;
    if ((fp = fopen(OUTPUT_FILE, "r")) == NULL)
    {
        perror("TEST FAILURE");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET); // rewind();
    char buffer[fsize + 1]; // +1 per il NULL-terminatore
    if (fread(buffer, 1, fsize, fp) && ferror(fp))
    {
        perror("TEST FAILURE");
        exit(1);
    }
    char *expected = " 2011,z,aaa\n99999,y,bbb\n    0,x,ccc\n";
    buffer[fsize] = '\0';
    if (strcmp(buffer, expected) != 0)
    {
        fprintf(stderr, "TEST FAILURE.\nExpected: \"\n\%s\n\"\nActual: \"\n%s\n\"\n", expected, buffer);
        printf("%d", buffer[fsize - 1]);
        exit(1);
    }
    fclose(fp);
    remove(OUTPUT_FILE);
    printf("TEST SUCCESS.\n");
    return 0;
}