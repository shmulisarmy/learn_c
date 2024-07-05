#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


typedef  struct hashMap hashMap;
typedef  struct linkedList linkedList;



struct linkedList{
    char key[10];
    char value[10];
    linkedList* next;
};



void set(linkedList* llp, const char key[10], const char value[10]){
    if (llp->key[0] == '\0') {  // Check if the key is empty
        strcpy(llp->key, key);
        strcpy(llp->value, value);
        return;
    }
    while(!(llp == NULL)){
        if (strcmp(llp->key, key) == 0){
            // free(llp->value);
            strcpy(llp->value, value);
            return;
        }
        if (!llp->next){
            llp->next = (linkedList*)malloc(sizeof(linkedList));
            assert(llp);
            llp->next->next = NULL;
            strcpy(llp->next->key, key);
            strcpy(llp->next->value, value);
            return;
        }
        llp = llp->next;
    }
}

char* get(linkedList* llp, const char key[10]){
    while(llp){
        if (strcmp(llp->key, key) == 0){
            return llp->value;
        }
        llp = llp->next;
    }
    return NULL;
}


void display(linkedList* llp){
    while(llp){
        printf("Key: %s, Value: %s\n", llp->key, llp->value);
        llp = llp->next;
    }
}



// Hash function based on the product of ASCII values of each character in the string
int hash(char key[10]){
    unsigned int hashValue;
    for (size_t i = 0; key[i] != '\0'; i++)
    {
        hashValue += (int)key[i] << 1;
    }
    return hashValue;

}

struct hashMap{
    linkedList lls[20];
    int size;
};


void hmSet(hashMap* hm, char key[10], char value[10]){
    unsigned int moddedHashValue = hash(key)%hm->size;
    set(&(hm->lls[moddedHashValue]), key, value);
}

char* hmGet(hashMap* hm, char key[10]){
    unsigned int moddedHashValue = hash(key)%hm->size;
    return get(&(hm->lls[moddedHashValue]), key);

}

void hashMapConstructor(hashMap* hm, int size){
    hm->size = size;
    for (int i = 0; i < size; i++){
        hm->lls[i].key[0] = '\0'; // Initialize the head node
        hm->lls[i].next = NULL;
    }
}

int main(){
    hashMap hm;
    hashMapConstructor(&hm, 20);
    hmSet(&hm, "key1", "value1");
    hmSet(&hm, "key2", "value2");
    hmSet(&hm, "key3", "value3");
    printf("%s\n, hmGet(&hm, "key1"));

}
