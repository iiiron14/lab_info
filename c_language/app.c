#include <stdio.h>

static char *cod[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main(){
	printf("%c", *(cod[0] + 1));
	return 0;
}