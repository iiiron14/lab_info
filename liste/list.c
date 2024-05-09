/* list.c : struttura dati lista */

/* Scopo di questa esercitazine e' la realizzazione delle funzioni
   segnate con [TODO] */

#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili il blocco di memoria restituita da questa
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

/* [TODO] Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(struct list *L) {
    if(L == NULL)
        return 1;
    return 0;
}

/* [TODO] Stampa i valori contenuti nei nodi di L; si puo' avere L ==
   NULL. */
void list_print(struct list *L) {
    if(is_empty(L))
        return;
    while(L != NULL){
        printf("%d ", L->val);
        L = L->next;
    }
    return;

}

/* [TODO] Restituisce una NUOVA lista con n nodi contenente i valori
   0, 1, ..., n-1 (il primo nodo della lista contiene 0, il secondo 1
   e cosi' via). Se n == 0 restituisce NULL.  SUGGERIMENTO: si puo'
   usare una soluzione ricorsiva o iterativa; nel caso di soluzione
   ricorsiva è probabilmente utile appoggiarsi ad una funzione
   ausiliaria ricorsiva:

   struct list *list_create_n_ric(int v, int n)

   che crea una lista di lunghezza n i cui nodi contengono rispettivamente
   i valori v, v+1, v+2, ... v+n-1
*/
struct list *list_create_n(int n) {
    if(!n)
        return NULL;
    struct list *l = (struct list *)malloc(sizeof(struct list));
    l->val = --n;
    l->next = NULL;
    while(n>0){
        l = list_create(--n, l);
    }
    return l;
}

/* [TODO] restituisce un puntatore ad un nodo della lista L il cui
   campo val abbia valore k; se k non compare nella lista, restituisce
   NULL */
struct list *list_search(struct list *L, int k) {
    if(is_empty(L))
        return NULL;
    do{
        if(L->val == k)
            return L;
        L = L->next;
    }while(L != NULL);
    return NULL;
}

/* [TODO] realizzare la funzione nth_element che restituisca il
   puntatore all'n-esimo nodo della lista (n=0 e' il primo nodo, n=1
   il secondo nodo, ecc.). Se tale nodo non esiste, restituisce
   NULL.

   SUGGERIMENTO: si puo' adottare una soluzione iteratia o ricorsiva.
   Nel caso di una soluzione ricorsiva, i casi base sono (L==NULL)
   oppure (n==0)...
*/
struct list *nth_element(struct list *L, int n) {
    if(is_empty(L))
        return NULL;
    while(n-- > 0){
        L = L->next;
        if(L == NULL)
            return NULL;
    }
    return L;
}

/* [TODO] crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 è
   il primo nodo della lista). SUGGERIMENTO: e' possibile realizzare
   una soluzione ricorsiva oppure iterativa. */
struct list *list_from_array(int v[], int n) {
    if(!n)
        return NULL;
    struct list *l = (struct list *)malloc(sizeof(struct list));
    l = NULL;
    while(n>0){
        n--;
        l = list_create(v[n], l);
    }
    return l;
}

/* Concatena L2 in coda a L1 e ritorna il puntatore all'inizio della
   nuova lista. Questa funzione non crea nuovi nodi, ma modifica L1 e
   L2. Al termine di questa funzione le vecchie liste non vanno piu'
   utilizzate, perche' il contenuto dei loro nodi (in particolare, dei
   puntatori al nodo successivo) possono essere cambiati. */
struct list *list_concat(struct list *L1, struct list *L2) {
    if (NULL == L1) {
        return L2;
    } else {
        if (NULL == L2) {
            return L1;
        } else {
            L1->next = list_concat(L1->next, L2);
            return L1;
        }
    }
}

/* [TODO] Data una lista L (anche vuota), ritorna il puntatore
   all'inizio di una NUOVA lista contenente gli stessi valori di L. In
   altre parole, questa funzione deve creare un duplicato della lista
   L. La lista L non deve essere modificata. */
struct list *list_duplicate(struct list *L) {
    struct list *p = (struct list *)malloc(sizeof(struct list));
    struct list *m = (struct list *)malloc(sizeof(struct list));

    m = L;
    p = m;
    while(L != NULL){
        L = L->next;
        m->next = L;
        m = m->next;
    }
    return p;
}

/* [TODO] Restituisce 1 se e solo se le liste L1 e L2 hanno la stessa
   lunghezza, e contengono gli stessi valori nello stesso ordine; 0
   altrimenti. Questa funzione non deve modificare ne' L1 ne' L2. */
int list_equal(struct list *L1, struct list *L2) {
    while(L1 != NULL){
        if(L2 == NULL || (L1->val != L2->val))
            return 0;
        L1 = L1->next;
        L2 = L2->next;
    }
    return 1;
}

/* [TODO] Data una lista L (anche vuota), ritorna un puntatore al
   primo nodo della lista ottenuta "rovesciando" L (l'ultimo nodo di L
   diventa il primo della nuova lista; il penultimo diventa il
   secondo, e cosi' via). Questa funzione non deve creare nuovi nodi,
   ma deve "riarrangiare" quelli di L. Dopo aver invocato questa
   funzione il puntatore all'inizio della vecchia lista L non deve
   essere utilizzato.

   SUGGERIMENTO: lasciare questa funzione per ultima, perche' non e'
   semplice come sembra. Consiglio di risolverla in modo iterativo.
*/

struct list *find_null_node(struct list *l){
    while(l->next != NULL)
        l = l->next;
    return l;
}

struct list *list_reverse(struct list *L) {
    if(is_empty(L))
        return NULL;
    struct list *m = L;
    struct list *p = NULL;
    struct list *n = NULL;

    while(m != NULL){
        p = m->next;
        m->next = n;
        n = m;
        m = p;
    }
    L = n;
    return L;
}

int main(void) {
    struct list *L1 = NULL, *L2 = NULL, *L3 = NULL, *L4 = NULL, *L5 = NULL;
    struct list *p;

    int val1[] = {1, 1, 2, 3, 5, 8, 13};
    int val2[] = {21, 34, 55};
    int i;
    const int n = 5;

    printf("is_empty(NULL) deve restituire VERO. %s\n",
           is_empty(NULL) ? "OK" : "ERRORE");
    L1 = list_create(77, NULL);
    printf("is_empty([77,NULL]) deve restituire FALSO. %s\n",
           !is_empty(L1) ? "OK" : "ERRORE");
    free(L1); // liberiamo L1

    /*
     * crea la lista (0, 1, 2, 3, 4); test delle funzioni
     * list_create_n(), is_empty(), e list_print()
     */
    L1 = list_create_n(n);
    printf("Lista L1: ");
    list_print(L1);
    printf("\n");

    /*
     * test della funzione list_search
     */
    printf("Cerchiamo il valore 2 in L1: ");
    p = list_search(L1, 2);
    if ((p != NULL) && (p->val == 2)) {
        printf("Ok, trovato!\n");
    } else {
        printf("ERRORE\n");
        return -1;
    }

    printf("Cerchiamo il valore %d in L1 (che non esiste): ", n);
    p = list_search(L1, n);
    if (p == NULL) {
        printf("Ok, non trovato!\n");
    } else {
        printf("ERRORE: restituito un nodo diverso da NULL\n");
        return -1;
    }

    /*
     * test della funzione nth_element()
     */
    for (i = 0; i < n; i++) {
        p = nth_element(L1, i);
        if ((p != NULL) && (p->val == i)) {
            printf("OK: nth_element(L1,%d) == %d\n", i, p->val);
        } else {
            printf("ERRORE: nth_element(L1,%d) ritorna ", i);
            if (p == NULL) {
                printf("NULL ");
            } else {
                printf("%d ", p->val);
            }
            printf(" anziche' %d\n", i);
            return -1;
        }
    }
    p = nth_element(L1, n);
    if (p == NULL) {
        printf("OK: nth_element(L1,%d) == NULL\n", n);
    } else {
        printf("ERRORE: nth_element(L1,%d) != NULL\n", n);
        return -1;
    }

    /*
     * Test della funzione list_from_array()
     */
    L2 = list_from_array(val1, 7);
    L3 = list_from_array(val2, 3);
    printf("L2 ha %d elementi (devono essere 7): ", list_length(L2));
    list_print(L2);
    printf("\nL3 ha %d elementi (devono essere 3): ", list_length(L3));
    list_print(L3);
    printf("\n");

    /*
     * Test della funzione list_concat()
     */
    L4 = list_concat(L2, L3);
    printf("L4 ha %d elementi (devono essere 10): ", list_length(L4));
    list_print(L4);
    printf("\n");

    /*
     * Test delle funzioni list_duplicate() e list_equal()
     */
    printf("Duplico L1 in L5\n");
    L5 = list_duplicate(L1);
    printf("Lista L1: ");
    list_print(L1);
    printf("Lista L5: ");
    list_print(L5);
    if (list_equal(L1, L5) == 1) {
        printf("Ok: L1 e L5 sono uguali\n");
    } else {
        printf("ERRORE: L1 e L5 differiscono\n");
    }

    /*
     * Test della funzione list_reverse()
     */
    printf("Rovescio la lista L4: ");
    L4 = list_reverse(L4);
    list_print(L4);
    printf("\n");

    printf("Distruggo L1\n");
    list_destroy(L1);
    /* L2 e L3 non vanno distrutte, perche' sono confluite in L4 */
    printf("Distruggo L4\n");
    list_destroy(L4);
    printf("Distruggo L5\n");
    list_destroy(L5);

    return 0;
}
