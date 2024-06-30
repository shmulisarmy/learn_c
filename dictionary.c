#include <stdio.h>
#include <stdlib.h>




struct LinkedList{
    char* key;
    char* value;
    struct LinkedList* next;
};



typedef struct LinkedList LinkedList;


void display(LinkedList* ll){
    LinkedList* cll = ll;
    while(cll){
        printf("%s: %s\n", ll->key, ll->value);
        cll = cll->next;
    }

}

void insert(LinkedList* ll, char* key, char* value){
    LinkedList* cll = ll;
    while(cll){
        cll = cll->next;
    }
    cll = (LinkedList*)malloc(sizeof(LinkedList));
    if (cll == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        // return 1;
    }
    cll->key = key;
    cll->value = value;

}

void unalloc(LinkedList* ll){
    LinkedList* cll = ll;
    while(cll){
        free(cll);
        LinkedList* old_ll = cll;
        cll = cll->next;
        free(old_ll);
    }
}


int main(){
    LinkedList* ll = NULL;
    insert(ll, "age", "20");
    insert(ll, "age", "20");
    display(ll);
    // unalloc(ll);

}
