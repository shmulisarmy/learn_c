// CONSTANTS:
//      struct LinkedList: in order to handle collisions in the hashMap    
// 





#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    char* key;
    char* value;
    struct LinkedList* next;
};

typedef struct LinkedList LinkedList;

void display(LinkedList* ll) {
    LinkedList* cll = ll;
    while (cll) {
        printf("%s: %s\n", cll->key, cll->value);
        cll = cll->next;
    }
}

void insert(LinkedList** ll, char* key, char* value) {
    LinkedList* new_node = (LinkedList*)malloc(sizeof(LinkedList));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (*ll == NULL) {
        *ll = new_node; // If list is empty, new_node becomes the head
    } else {
        LinkedList* cll = *ll;
        while (cll->next) {
            cll = cll->next;
        }
        cll->next = new_node; // Append new_node at the end of the list
    }
}

void unalloc(LinkedList* ll) {
    LinkedList* cll = ll;
    while (cll) {
        LinkedList* next = cll->next;
        free(cll);
        cll = next;
    }
}



struct hashMap{
    LinkedList llList;
}

int main() {
    
}
