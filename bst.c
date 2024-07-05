#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct bst bst;

struct bst{
    int key;
    char value[10];
    bst* right;
    bst* left;
};

void set(bst* node, int key, char value[10]){
    while (1){
        if (key == node->key){
            strcpy(node->value, value);
            return;
        if (key > node->key){
            node = node->right;
            if (!node->right){
                node->right = (bst*)malloc(sizeof(bst));
            }
        } else {
            node = node->left;
            if (!node->left){
                node->left = (bst*)malloc(sizeof(bst));
            }
          }
        }
    }
}
