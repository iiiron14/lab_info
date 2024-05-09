#include <stdio.h>

struct list {
    int val;
    struct list *next;
};

int main(){
    struct list *l = NULL;
    l->val = 0;
    l->next = NULL;
    printf("%d ", l->val);
    return 0;
}