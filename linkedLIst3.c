#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


typedef  struct linkedList linkedList ;


struct linkedList{
    linkedList* next;
    char key[10];
    char value[10];
};


linkedList* createNode(char key[10], char value[10]) {
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

void insert(linkedList* llp, char key[10], char value[10]) {
    linkedList* temp = llp;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = createNode(key, value);
}






int main(){
    linkedList *llh = createNode("name", "shmuli");
    insert(llh, "day", "tuesday");
    insert(llh, "tomorrow", "wednesday");
}
