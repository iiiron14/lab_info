#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

/* Dichiarazione di alcune delle funzioni viste a lezione; le funzioni
   sono definite sotto (non devono essere implementate), e possono
   essere usate se serve. */
struct list *list_create(int v, struct list *t);
int list_length(struct list *L);
void list_destroy(struct list *L);
int is_empty(struct list *L);
void list_print(struct list *L);

/* FUNZIONE DA REALIZZARE
   ======================

   Realizzare la funzione esistono_duplicati(L) secondo le specifiche
   seguenti. La funzione accetta come parametro una lista L, che puo'
   anche essere vuota; la funzione restituisce 1 se e solo se nella
   lista L sono presenti valori duplicati, cioe' se esistono due o
   piu' occorrenze dello stesso valore (campo val dei nodi). Il
   contenuto della lista L non e' necessariamente ordinato. Nel caso
   in cui L sia la lista vuota, la funzione restituisce 0 in quanto
   sicuramente non sono presenti valori duplicati.

   Ad esempio, se L = (1, -3, 10, 9, 1, 21, 1), la funzione deve
   restituire 1, dato che esistono tre occorrenze del valore 1. Se L =
   (-1) la funzione deve restituire 0, in quanto non ci sono valori
   ripetuti. Se L = (30, 29, 38, 28, 29, 30) la funzione deve
   restituire 1, in quanto sono presenti piu' occorrenze di 30 (ma
   anche di 29 e di 28). Si faccia riferimento ai test per ulteriori
   esempi.

   NOTA: soluzioni che fanno uso di array verranno valutate max 5
   punti. Per ottenere punteggio massimo, la soluzione deve operare
   esclusivamente sulla lista, ed essere ovviamente corretta.

   Si ricorda che una funzione che supera i test non e'
   necessariamente corretta.
*/
int esistono_duplicati(struct list *L) {
    if(is_empty(L))
        return 0;
    struct list *first;
    struct list *second;
    first = L;
    second = L->next;
    while(first != NULL){
        while(second != NULL){
            if(first->val == second->val)
                return 1;
            second = second->next;
        }
        first = first->next;
    }
    return 0;
}

/**
 ** Le funzioni seguenti sono gia' implementate
 **/

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili la zona di memoria restituita da questa
   funzione, quando non piu' utilizzata */
struct list *list_create(int v, struct list *t) {
    struct list *r = (struct list *)malloc(sizeof(struct list));
    r->val = v;
    r->next = t;
    return r;
}

/* Restituisce la lunghezza (numero di nodi) della lista L; se L e' la
   lista vuota, restituisce 0 */
int list_length(struct list *L) {
    /* Versione ricorsiva */
    if (NULL == L) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(struct list *L) {
    /* versione ricorsiva */
    if (L != NULL) {
        list_destroy(L->next);
        L->next = NULL; /* non necessario... */
        free(L);
    }
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(struct list *L) { return (NULL == L); }

/* Stampa il contenuto della lista L */
void list_print(struct list *L) {
    printf("(");
    while (L != NULL) {
        printf("%d", L->val);
        if (L->next != NULL)
            printf(", ");
        L = L->next;
    }
    printf(")");
}

void test(struct list *L, int expect) {
    int r = esistono_duplicati(L);

    if (r == expect) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: ");
        list_print(L);
        printf(" risultato atteso=%d, risultato ottenuto=%d\n", expect, r);
    }
}

int main(void) {
    test(list_create(1, list_create(-3, list_create(10, list_create(9, list_create(1, list_create(21, list_create(1, NULL))))))), 1);
    test(list_create(-1, NULL), 0);
    test(NULL, 0);
    test(list_create(30, list_create(29, list_create(28, list_create(28, list_create(29, list_create(30, NULL)))))), 1);
    test(list_create(10, list_create(10, list_create(10, list_create(10, NULL)))), 1);
    test(list_create(39, list_create(39, NULL)), 1);
    test(list_create(10, list_create(-1, list_create(9, list_create(12, NULL)))), 0);
    test(list_create(-1, list_create(-2, list_create(-3, list_create(-4, NULL)))), 0);
    test(list_create(-1, list_create(-1, NULL)), 1);
    test(list_create(1, list_create(2, list_create(-1, list_create(-10, list_create(1, NULL))))), 1);
    test(list_create(10, list_create(38, list_create(11, list_create(-1, list_create(-29, list_create(18, list_create(13, NULL))))))), 0);
    return 0;
}
