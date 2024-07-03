#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList LinkedList;
typedef struct HashMap HashMap;
typedef struct Trie Trie;




struct LinkedList {
    Trie* key;
    char* value;
    LinkedList* next;
};

void set(LinkedList** lldp, Trie* key, char* value);
char* get(LinkedList* llp, Trie* key);
void display(LinkedList* llp);
void memClear(LinkedList* llp);
int hash(char charPointer[]);

struct HashMap {
    LinkedList* list_of_chains[20];
};

struct Trie {
    HashMap hm;
};




void hmSet(HashMap* hmp, Trie* key, char* value);
char* hmGet(HashMap* hmp, Trie* key);
void destroy_hash_map(HashMap* hm);

Trie* createTrie();
void freeTrie(Trie* trie);

void set(LinkedList** lldp, Trie* key, char* value) {
    while (*lldp) {
        if ((*lldp)->key == key) {
            free((*lldp)->value);
            (*lldp)->value = strdup(value);
            return;
        }
        lldp = &(**lldp).next;
    }
    *lldp = (LinkedList*)malloc(sizeof(LinkedList));
    (*lldp)->key = key;
    (*lldp)->value = strdup(value);
    (*lldp)->next = NULL;
}

char* get(LinkedList* llp, Trie* key) {
    while (llp) {
        if (llp->key == key) {
            return llp->value;
        }
        llp = llp->next;
    }
    return NULL;
}

void display(LinkedList* llp) {
    while (llp) {
        // Note: Trie cannot be printed directly
        // You can print some identifier or value from Trie if needed
        printf("Trie key: %p, Value: %s\n", llp->key, llp->value);
        llp = llp->next;
    }
}

void memClear(LinkedList* llp) {
    LinkedList* oldLlp;
    while (llp) {
        oldLlp = llp;
        llp = llp->next;
        free(oldLlp->value);
        freeTrie(oldLlp->key); // Free the trie
        free(oldLlp);
    }
}

void hmSet(HashMap* hmp, Trie* key, char* value) {
    int modded_hash = hash(key->hm.list_of_chains[0]->value) % 20; // Assuming the first node's value as a hash input
    set(&(hmp->list_of_chains[modded_hash]), key, value);
}

char* hmGet(HashMap* hmp, Trie* key) {
    int modded_hash = hash(key->hm.list_of_chains[0]->value) % 20; // Assuming the first node's value as a hash input
    return get(hmp->list_of_chains[modded_hash], key);
}

int hash(char charPointer[]) {
    int val = 0;
    int index = 0;
    while (charPointer[index] != '\0') {
        val += (int)charPointer[index];
        val = val >> 1;
        index++;
    }
    return val;
}

void destroy_hash_map(HashMap* hm) {
    for (size_t i = 0; i < 20; i++) {
        memClear(hm->list_of_chains[i]);
    }
}

Trie* createTrie() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    for (size_t i = 0; i < 20; i++) {
        trie->hm.list_of_chains[i] = NULL;
    }
    return trie;
}

void freeTrie(Trie* trie) {
    destroy_hash_map(&trie->hm);
    free(trie);
}

int main() {
    HashMap hm;
    for (size_t i = 0; i < 20; i++) {
        hm.list_of_chains[i] = NULL;
    }
    
    Trie* trie1 = createTrie();
    Trie* trie2 = createTrie();
    Trie* trie3 = createTrie();
    
    hmSet(&hm, trie1, "world");
    hmSet(&hm, trie2, "bar");
    hmSet(&hm, trie3, "value");

    printf("trie1: %s\n", hmGet(&hm, trie1));
    printf("trie2: %s\n", hmGet(&hm, trie2));
    printf("trie3: %s\n", hmGet(&hm, trie3));

    destroy_hash_map(&hm);
    freeTrie(trie1);
    freeTrie(trie2);
    freeTrie(trie3);
    
    return 0;
}
