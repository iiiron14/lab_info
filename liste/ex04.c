#include <stdio.h>
#include <string.h>

struct persona {
    char *nome;
    char *cognome;
    int telefono;
};

void stampa(struct persona p) {
    printf("Nome=%s Cognome=%s Telefono=%d\n", p.nome, p.cognome, p.telefono);
}

// Restituisce true se la stringa dst è la radice del nome della persona
int match(struct persona src, char *dst) {
    // TODO
}

// Conta le persone che matchano con la radice
int count(struct persona *rubrica, int N, char *prefix) {
    // TODO
}

int main(void) {
    struct persona rubrica[] = {
        {"Matteo", "Rossi", 123},
        {"Mattia", "Bianchi", 123},
        {"Marta", "Verdi", 123},
        {"Luca", "Verdi", 123},
    };

    int N = sizeof(rubrica) / sizeof(struct persona);
    printf("%d should be %d\n", count(rubrica, N, "Ma"), 3);
    printf("%d should be %d\n", count(rubrica, N, "Mar"), 1);
    printf("%d should be %d\n", count(rubrica, N, "Mat"), 2);
    printf("%d should be %d\n", count(rubrica, N, "Luca"), 1);
}