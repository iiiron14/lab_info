# Laboratorio 7: Ricorsione

I seguenti esercizi devono essere risolti tutti seguendo un approccio
ricorsivo.

## Esercizio 1

Si realizzi una funzione `int somma(int x)` che calcoli la somma dei
primi $$x$$ interi $$1 + \ldots + x$$, $$x \geq 0$$ (se $$x=0$$ la somma vale
0) usando lo schema seguente:

$$\mathit{somma}(x) =
\begin{cases}
0 & se~x=0\\
x + \mathit{somma}(x-1) & se~x > 0
\end{cases}$$

## Esercizio 2

Si realizzi una funzione ricorsiva `int somma_due_numeri(int x, int y)`
che calcoli la somma tra due interi non negativi $$x, y$$ usando lo schema
seguente:

$$\mathit{somma\_due\_numeri}(x,y) =
\begin{cases}
x & se~y = 0\\
y & se~x = 0\\
1 + \mathit{somma\_due\_numeri}(x, y-1) & altrimenti
\end{cases}$$

## Esercizio 3

Progettare una funzione `int evens(int a[], int n)` che conta quanti
elementi pari vi sono in un array `a[]` di lunghezza $$n \geq 0$$. Testare
la funzione su alcuni array di input scelti opportunamente per
verificarne empiricamente la correttezza.

## Esercizio 4

Partendo dal sorgente `azzeraNegativi.c` implementare una funzione
`azzeraNegativi()` che accetta come parametro un array e la sua
lunghezza $$n \geq 0$$, e lo modifica mettendo a zero tutti i suoi
elementi negativi.

## Esercizio 5

Creare un programma contenente una funzione `palindrome()` che accetta
come parametro un intero $$n \neq 0$$ e restituisce come risultato un
array di interi il cui contenuto segua lo schema seguente:

- $$n=0 \Rightarrow \{0\}$$

- $$n=1 \Rightarrow \{1,0,1\}$$

- $$n=2 \Rightarrow \{2,1,0,1,2\}$$

- $$\ldots$$

- $$n=5 \Rightarrow \{5,4,3,2,1,0,1,2,3,4,5\}$$

- $$\ldots$$

Suggerimento: potrebbe essere utile definire `palindrome()` come una
funzione NON ricorsiva, che ne invoca un'altra (ricorsiva) per fare il
grosso del lavoro (un po' come abbiamo visto a lezione con la ricerca
binaria ricorsiva).

## Esercizio 6

Risolvere l'esercizio d'esame nel file `ex06-tritonacci.c`

## Esercizio 7

Progettare la funzione `double mypow(double basis, int exponent)` che calcola potenze anche con esponente negativo.

## Esercizio 8

Progettare la funzione `int mymax(int a[], int n)` che restituisce il valore massimo di un array di interi `a` avente lunghezza `n > 0`.

## Esercizio 9

Progettare la funzione `int int2bin(int a)` che trasforma il valore intero `a` in codifica binaria. E.g., dato il numero intero `int2bin(10)=1010`.

## Esercizio 10

Il minimo comune multiplo di due o più numeri, indicato con il simbolo lcm (Least Common Multiple), è il più piccolo numero divisibile per ciascuno di tali numeri. Progettare la funzione `int lcm(int a, int b)` che restituisce il minimo comune multiple di due numeri `a` e `b`.

## Esercizio 11 (esercizio sulle stringhe, non richiede ricorsione)

Risolvere l'esercizio d'esame nel file `ex11-strings-t9.c`.
