#include <stdio.h>

struct persona{
    char *nome;
    char *cognome;
    char *indirizzo;
    char *city;
    char *birth_date;
};

void stampa(struct persona p){
    printf("%s, %s, %s, %s, %s\n", p.nome, p.cognome, p.indirizzo, p.city, p.birth_date);
}

int main(){
    struct persona p1; // no inizializzazione
    struct persona p2 = {"Luca", "Pollo", "via pollo dei polli", "pollia", "15/02/2000"}; // inizializzazione completa
    struct persona p3 = {"Giulio"};
    struct persona p4 = { .cognome = "pollini"};
    
    // printf("p1:\n");
    // printf("%s, %s, %s, %s, %s\n", p1.nome, p1.cognome, p1.indirizzo, p1.city, p1.birth_date);
    stampa(p2);
    stampa(p3);
    stampa(p4);
    return 0;
}