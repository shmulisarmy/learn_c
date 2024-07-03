#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct linkedList linkedList;

struct linkedList{
    char key[10];
    char value[10];
    linkedList* next;
};



void set(linkedList* llp, const char key[10], const char value[10]){
    while (llp){
        if (strcmp(llp->key, key) == 0){
            strcpy(llp->value, value);
            return;
        if (llp->next == NULL){
            break;
        }
        llp = llp->next;
        }
    }
    llp->next = (linkedList*)malloc(sizeof(linkedList));
} 

linkedList* linkedListConstructor(const char firstKey[10], const char firstKey[10]){
    linkedList* llhp = (linkedList*)malloc(sizeof(linkedList));
    llhp->next = NULL;
    strcpy(llhp->key, firstKey);
    strcpy(llhp->value, firstKey);
    return llhp;
}



int main(){
    linkedList* llhp = linkedListConstructor("first", "key");
    set(llhp, "name", "shmuli");
    set(llhp, "berel", "keller");
    set(llhp, "chana", "keller");
    set(llhp, "jell", "scroog");
    set(llhp, "name", "shalom");
}