#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int value;
    struct LinkedList* next;
};

typedef struct LinkedList LinkedList;

void insert(LinkedList** lldp, int value){
    while (*lldp){
        lldp = &(**lldp).next;
    }
    *lldp = (LinkedList*)malloc(sizeof(LinkedList));
    (*lldp)->value = value;
    (*lldp)->next = NULL;
}

void display(LinkedList* llp){
    while (llp){
        printf("%d\n", llp->value);
        llp = llp->next;
    }
}

void memClear(LinkedList* llp){
    LinkedList* oldLlp;
    while (llp){
        oldLlp = llp;
        llp = llp->next;
        free(oldLlp);
    }
}

int main(){
    LinkedList* llhp = NULL;
    insert(&llhp, 4);
    insert(&llhp, 45);
    insert(&llhp, 7);
    display(llhp);
    memClear(llhp);
}