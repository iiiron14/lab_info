# Laboratorio 7: Ricorsione

I seguenti esercizi devono essere risolti tutti seguendo un approccio
ricorsivo.

## Esercizio 1

Si realizzi una funzione `int somma(int x)` che calcoli la somma dei
primi <img src="https://i.upmath.me/svg/x" alt="x" /> interi <img src="https://i.upmath.me/svg/1%20%2B%20%5Cldots%20%2B%20x" alt="1 + \ldots + x" />, <img src="https://i.upmath.me/svg/x%20%5Cgeq%200" alt="x \geq 0" /> (se <img src="https://i.upmath.me/svg/x%3D0" alt="x=0" /> la somma vale
0) usando lo schema seguente:

<img src="https://i.upmath.me/svg/%5Cmathit%7Bsomma%7D(x)%20%3D%0A%5Cbegin%7Bcases%7D%0A0%20%26%20se~x%3D0%5C%5C%0Ax%20%2B%20%5Cmathit%7Bsomma%7D(x-1)%20%26%20se~x%20%3E%200%0A%5Cend%7Bcases%7D" alt="\mathit{somma}(x) =
\begin{cases}
0 &amp; se~x=0\\
x + \mathit{somma}(x-1) &amp; se~x &gt; 0
\end{cases}" />

## Esercizio 2

Si realizzi una funzione ricorsiva `int somma_due_numeri(int x, int y)`
che calcoli la somma tra due interi non negativi <img src="https://i.upmath.me/svg/x%2C%20y" alt="x, y" /> usando lo schema
seguente:

<img src="https://i.upmath.me/svg/%5Cmathit%7Bsomma%5C_due%5C_numeri%7D(x%2Cy)%20%3D%0A%5Cbegin%7Bcases%7D%0Ax%20%26%20se~y%20%3D%200%5C%5C%0Ay%20%26%20se~x%20%3D%200%5C%5C%0A1%20%2B%20%5Cmathit%7Bsomma%5C_due%5C_numeri%7D(x%2C%20y-1)%20%26%20altrimenti%0A%5Cend%7Bcases%7D" alt="\mathit{somma\_due\_numeri}(x,y) =
\begin{cases}
x &amp; se~y = 0\\
y &amp; se~x = 0\\
1 + \mathit{somma\_due\_numeri}(x, y-1) &amp; altrimenti
\end{cases}" />

## Esercizio 3

Progettare una funzione `int evens(int a[], int n)` che conta quanti
elementi pari vi sono in un array `a[]` di lunghezza <img src="https://i.upmath.me/svg/n%20%5Cgeq%200" alt="n \geq 0" />. Testare
la funzione su alcuni array di input scelti opportunamente per
verificarne empiricamente la correttezza.

## Esercizio 4

Partendo dal sorgente `azzeraNegativi.c` implementare una funzione
`azzeraNegativi()` che accetta come parametro un array e la sua
lunghezza <img src="https://i.upmath.me/svg/n%20%5Cgeq%200" alt="n \geq 0" />, e lo modifica mettendo a zero tutti i suoi
elementi negativi.

## Esercizio 5

Creare un programma contenente una funzione `palindrome()` che accetta
come parametro un intero <img src="https://i.upmath.me/svg/n%20%5Cneq%200" alt="n \neq 0" /> e restituisce come risultato un
array di interi il cui contenuto segua lo schema seguente:

- <img src="https://i.upmath.me/svg/n%3D0%20%5CRightarrow%20%5C%7B0%5C%7D" alt="n=0 \Rightarrow \{0\}" />

- <img src="https://i.upmath.me/svg/n%3D1%20%5CRightarrow%20%5C%7B1%2C0%2C1%5C%7D" alt="n=1 \Rightarrow \{1,0,1\}" />

- <img src="https://i.upmath.me/svg/n%3D2%20%5CRightarrow%20%5C%7B2%2C1%2C0%2C1%2C2%5C%7D" alt="n=2 \Rightarrow \{2,1,0,1,2\}" />

- <img src="https://i.upmath.me/svg/%5Cldots" alt="\ldots" />

- <img src="https://i.upmath.me/svg/n%3D5%20%5CRightarrow%20%5C%7B5%2C4%2C3%2C2%2C1%2C0%2C1%2C2%2C3%2C4%2C5%5C%7D" alt="n=5 \Rightarrow \{5,4,3,2,1,0,1,2,3,4,5\}" />

- <img src="https://i.upmath.me/svg/%5Cldots" alt="\ldots" />

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
