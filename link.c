#include <stdio.h>
#include <stdlib.h>



typedef struct LinkedList LinkedList;

struct LinkedList{
    int key;
    int value;
    LinkedList* next;
};


void set(LinkedList** lldp, int key, int value){
    while (*lldp){
        if ((*lldp)->key == key){
            (*lldp)->value = value;
            return;
        }
        lldp = &(**lldp).next;
    }
    *lldp = (LinkedList*)malloc(sizeof(LinkedList));
    (*lldp)->key = key;
    (*lldp)->value = value;
    (*lldp)->next = NULL;
}

int get(LinkedList* llp, int key){
    while (llp){
        if (llp->key == key){
            return llp->value;
        }
        llp = llp->next;
    }
    return -1;
}

void display(LinkedList* llp){
    while (llp){
        printf("%d: %d\n", llp->key, llp->value);
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
    set(&llhp, 4, 5);
    set(&llhp, 4, 1);
    set(&llhp, 7, 2);
    set(&llhp, 45, 7);
    set(&llhp, 7, 3);
    printf("%d\n", get(llhp, 7));
    printf("%d\n", get(llhp, 22));
    memClear(llhp);
}