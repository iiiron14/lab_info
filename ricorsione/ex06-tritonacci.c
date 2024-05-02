/* tritonacci.c */
#include <stdio.h>
#include <stdlib.h>

/* FUNZIONE DA REALIZZARE
   ======================

   La successione di "tritonacci" e' definita in modo simile alla
   successione di Fibonacci, con la differenza che ogni termine della
   successione di tritonacci e' dato dalla somma dei TRE valori
   precedenti (anziche' due come nella successione di Fibonacci).
   Formalmente, la successione di tritonacci T(1), T(2), T(3),
   ... T(n) ... e' definita come segue:

   T(1) = 1
   T(2) = 1
   T(3) = 1
   T(n) = T(n-1) + T(n-2) + T(n-3) se n>3

   Quindi la successione di tritonacci e' 1, 1, 1, 3, 5, 9, 17, 31,
   57, ...

   Realizzare la funzione tritonacci(n) che restituisce l'n-esimo
   numero di Tritonacci.

   Suggerimento: l'implementazione ricorsiva basata sulla definizione
   e' troppo lenta per completare tutti i test (perche'?). Occorre
   quindi pensare ad una implementazione iterativa piu' efficace.
*/

/* Questa e' una implementazione ricorsiva basata direttamente sulla
   definizione della successione di "tritonacci", che pero' richiede
   troppo tempo gia' per valori moderati di n. Si puo' dimostrare, in
   modo analogo alla successione di Fibonacci, che questa funzione
   richiede tempo esponenziale in n.
*/
/* int tritonacci_rec(int n) {
    if (n <= 3) {
        return 1;
    }

    return tritonacci(n - 3) + tritonacci(n - 2) + tritonacci(n - 1);
} */

int tritonacci(int n) {
    int n1 = 1, n2 = 1, n3 = 1, ris = 3, i, app;
    if(n <= 3)
        return 1;
    for(i = 4; i < n; i++){
        app = n3;
        n3 += n1 + n2;
        n1 = n2;
        n2 = app;
        
        ris = n1 + n2 + n3;
    }
    return ris;
}

void test(int n, int expect) {
    int v = tritonacci(n);
    printf("tri(%d)=%d -- ", n, v);
    if (v == expect) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso %d\n", expect);
    }
}

int main(void) {
    test(1, 1);
    test(2, 1);
    test(3, 1);
    test(4, 3);
    test(5, 5);
    test(6, 9);
    test(7, 17);
    test(8, 31);
    test(9, 57);
    test(15, 2209);
    test(20, 46499);
    test(30, 20603361);
    test(35, 433695873);
    test(40, 539260895);
    return 0;
}
