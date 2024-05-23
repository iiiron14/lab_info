#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFDIM 1000

struct job {
    char fname[20];
    char c;
    int k;
};

/**
 * Implementare la funzione sottostante, che si deve comportare come segue:
 *    - Legge una serie di oggetti 'struct job' dallo stream fp fornito in input
 *    - Ogni job j descrive un lavoro da effettuare: la creazione di un file
 *        - con nome j.name (nella cartella corrente)
 *        - con contenuto dato dal carattere j.c ripetuto per j.k volte
 *    - Nota: i job devono essere eseguiti nell'ordine indicato
 *    - Restituisce il numero di file scritti, o -1 in caso di errore.
 */
int f(FILE *fp) {
    int i=0;
    struct job j;

    while(fread(&j, sizeof(j),1, fp)){
        printf("%s %c %d\n", j.fname, j.c, j.k);
        FILE *f = fopen(j.fname, "w");
        for(int m= 0; m< j.k; m++)
            fputc(j.c, f);
        fclose(f);
        i++;
    }
    return i;
}

void test(struct job *jobs, int njobs, char **files, char **contents, int k) {
    // FILE *fp = tmpfile();
    FILE *fp = fopen("foo.ignore", "w+");
    if (fwrite(jobs, sizeof(struct job), njobs, fp) < njobs) {
        perror("Failed put on test creation");
        exit(1);
    }
    rewind(fp);
    int nwritten = f(fp);
    if (nwritten != njobs)
        printf("WARNING! Expected files written is %d but got %d.\n", njobs, nwritten);
    for (int i = 0; i < k; i++) {
        FILE *fp = fopen(files[i], "r");
        if (fp == NULL) {
            printf("Test %d FAILED (no file)\n", i);
            continue;
        }
        char buff[BUFDIM];
        buff[0] = '\0';
        if (fgets(buff, BUFDIM, fp) != buff && ferror(fp)) {
            perror("Cannot read file");
            continue;
        }
        if (strcmp(buff, contents[i]) != 0)
            printf("Test %d FAILED (bad content:'%s' vs. '%s')\n", i, buff, contents[i]);
        else
            printf("Test %d OK\n", i);
        fclose(fp);
        // remove(files[i]); // cleanup
    }
    fclose(fp);
}

int main(void) {
    #define NJOBS 4
    struct job jobs[NJOBS] = {
        {.fname = "aaa", 'x', 5},
        {.fname = "bbb", 'y', 0},
        {.fname = "aaa", 'x', 3},
        {.fname = "ccc", 'z', 15},
    };
    #define NRESULTS 3
    char *files[NRESULTS] = {"aaa", "bbb", "ccc"};
    char *contents[NRESULTS] = {"xxx", "", "zzzzzzzzzzzzzzz"};
    test(jobs, NJOBS, files, contents, NRESULTS);
}
