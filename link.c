#include <stdio.h>
#include <stdlib.h>



typedef struct LinkedList LinkedList;
typedef struct HashMap HashMap;

struct LinkedList{
    char* key;
    char* value;
    LinkedList* next;
};


void set(LinkedList** lldp, char* key, char* value){
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

char* get(LinkedList* llp, char* key){
    while (llp){
        if (llp->key == key){
            return llp->value;
        }
        llp = llp->next;
    }
    return NULL;
}

void display(LinkedList* llp){
    while (llp){
        printf("%s: %s\n", llp->key, llp->value);
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


struct HashMap{
    // int size;
    LinkedList* list_of_chains[20];
};

void hmSet(HashMap* hmp, char* key, char* value){
    int modded_hash = hasify(key) %20;
    set(&(hmp->list_of_chains[modded_hash]), key, value);
}

char* hmGet(HashMap* hmp, char* key){
    int modded_hash = hasify(key) %20;
    return get(hmp->list_of_chains[modded_hash], key);
}


int hasify(char charPointer[]){
    int val = 0;
    int index = 0;
    while (charPointer[index] != '\0')
    {
        val += (int)charPointer[index];
        val = val >> 1;
        printf("%d\n", val);
        index++;
    }
    return val;
    

}


void destroy_hash_map(HashMap* hm){
    for (size_t i = 0; i < 20; i++){
        memClear(hm->list_of_chains[i]);
    }
    
}



int main(){
    // HashMap hm;
    // for (size_t i = 0; i < 20; i++)
    // {
    //     hm.list_of_chains[i] = NULL;    /* code */
    // };
    // hmSet(&hm, )
    // destroy_hash_map(&hm);
    // printf("%d", (int)"hello");
    
}


