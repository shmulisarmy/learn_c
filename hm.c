#include <stdio.h>
#include <stdlib.h>




struct bst{
    int key;
    int value;
    struct bst* right;
    struct bst* left;
};


typedef struct bst bst;

void set(bst** b, int key, int value){
    if (*b == NULL){
        *b = (bst*)malloc(sizeof(bst));
        if (*b == NULL){
            perror("cannot malloc for b on line 23\n");
        }

        (*b)->key = key;
        (*b)->value = value;
        (*b)->right = NULL;
        (*b)->left = NULL;
        return;
    }
    if (key == (*b)->key){
        (*b)->value = value;
    } else if (key < (*b)->key){
        set(&(**b).left, key, value);
    } else {
        set(&(**b).right, key, value);
    }
}

int get(bst** b, int key){
    if (*b == NULL){
        return -1;
    }
    if (key == (*b)->key){
        return (*b)->value;
    }
    if (key < (*b)->key){
        return get(&(**b).left, key);
    } else {
        return get(&(**b).right, key);
    }
}


void traverse(bst* b){
    if (b == NULL){
        return;
    }
    traverse(b->left);
    printf("%d: %d\n", b->key, b->value);
    traverse(b->right);
}



int main(){
    bst* b;
    b = (bst*)malloc(sizeof(bst));
    b->key = 5;
    b->value = 4;
    b->left = NULL;
    b->right = NULL;
    set(&b, 7, 4);
    set(&b, 1, 6);
    set(&b, 4, 2);
    set(&b, 1, 6);
    set(&b, 2, 8);
    set(&b, 8, 1);
    // printf("%d", get(&b, 7));
    traverse(b);
}