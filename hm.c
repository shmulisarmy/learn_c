#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct linkedList linkedList; 

struct linkedList{
    char* key;
    char* value;
    linkedList* next;
};




void set(linkedList* llp, const char* key, const char* value){
    //to handle the case where this is the first set item
    if (llp->key == NULL){
        llp->key = (char*)malloc(sizeof(strlen(key)+1));
        llp->value = (char*)malloc(sizeof(strlen(value)+1));
        strcpy(llp->key,  key);
        strcpy(llp->value,  value);
        return;
    }
    while(llp && llp->next){
        llp = llp->next;
        printf("loop\n");
        if (strcmp(llp->next->key, key) == 0){
            llp->next->value = (char*)malloc(sizeof(strlen(value)+1));
            strcpy(llp->next->value,  value);
            return;
        }
    }
    llp->next = (linkedList*)malloc(sizeof(linkedList));
    llp->next->key = (char*)malloc(sizeof(strlen(key)+1));
    llp->next->value = (char*)malloc(sizeof(strlen(value)+1));
    strcpy(llp->next->key,  key);
    strcpy(llp->next->value,  value);
}


void display(linkedList* ll){
    while (ll){
        printf("key: %s, value: %s\n", ll->key, ll->value);
        ll = ll->next;
    }
}


int main(){
    linkedList llh;
    llh.next = NULL;
    llh.key = NULL;
    set(&llh, "shmuli", "keller");
    set(&llh, "hershi", "wallfish");
    set(&llh, "chok", "litif");
    set(&llh, "hellen", "keler");
    set(&llh, "c", "++");
    display(&llh);
}