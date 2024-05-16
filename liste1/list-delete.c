/* list-delete.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int val;
    struct list *next;
};

/* Crea (mediante malloc()) e restituisce un puntatore ad un nuovo
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
    if (NULL == L) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(struct list *L) {
    if (L != NULL) {
        list_destroy(L->next);
        L->next = NULL; /* non necessario... */
        free(L);
    }
}

/* Stampa i valori contenuti nei nodi di L; si puo' avere L ==
   NULL. */
void list_print(struct list *L) {
    printf("[");
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf("]\n");
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0
   altrimenti */
int is_empty(struct list *L) { return (L == NULL); }

/* Crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 �
   il primo nodo della lista). */
struct list *list_from_array(int v[], int n) {
    if (n > 0) {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    } else {
        return NULL;
    }
}

/* restituisce 1 se e solo se le due liste sono uguali, 0 altrimenti */
int list_equal(struct list *l1, struct list *l2) {
    if (is_empty(l1) && is_empty(l2)) {
        return 1;
    }
    if (!is_empty(l1) && !is_empty(l2) && l1->val == l2->val) {
        return list_equal(l1->next, l2->next);
    }
    return 0;
}

/* [TODO] Data una lista e un intero k, cancella dalla lista
   (liberando anche la memoria con la free()) tutti i nodi che
   contengono k, se ce ne sono */
struct list *list_delete_k(struct list *L, int k) {
    struct list *app = NULL;
    struct list *current;
    // if the k value is first (one or more occurences)
    while(L != NULL && L->val == k){
        app = L->next;
        free(L);
        L = app;
    }
    // if the k value is in the body or the tail
    current = L;
    while(current != NULL){
        if(current->next != NULL && (current->next)->val == k){
            app = current->next;
            current->next = (current->next)->next;
            free(app);
        }
        current = current->next;
    }
    return L;
}

int test(void) {
    int a[] = {10, 20, 30, 10, 15, 21, 40, 10};
    struct list *la = list_from_array(a, sizeof(a) / sizeof(a[0]));

    int b[] = {1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};
    struct list *lb = list_from_array(b, sizeof(b) / sizeof(b[0]));

    int c[] = {100, 200, 300};
    struct list *lc = list_from_array(c, sizeof(c) / sizeof(c[0]));

    int resa[] = {20, 30, 15, 21, 40};
    struct list *lresa = list_from_array(resa, sizeof(resa) / sizeof(resa[0]));

    int resb[] = {1, 3, 4, 5, 6, 7, 6, 5, 4, 3, 1};
    struct list *lresb = list_from_array(resb, sizeof(resb) / sizeof(resb[0]));

    int resc[] = {100, 200, 300};
    struct list *lresc = list_from_array(resc, sizeof(resc) / sizeof(resc[0]));

    /* printf("lista a:\n");
    list_print(la);
    printf("\nlista b:\n");
    list_print(lb);
    printf("\nlista c:\n");
    list_print(lc); */

    return list_equal(list_delete_k(la, 10), lresa) &&
           list_equal(list_delete_k(lb, 2), lresb) &&
           list_equal(list_delete_k(lc, 10), lresc);
}

int main(void) {
    printf("Test: %s\n", test() ? "Test OK" : "Test FAILED");
    return 0;
}
