#include <stdio.h>
#include <stdlib.h>





struct tree{
    int value;
    struct tree* right;
    struct tree* left;
};

typedef struct tree tree;



void insert(tree* t, int num){
    if (t == NULL){
        t = (tree*)malloc(sizeof(tree));
        if (t == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        t->value = num;
        t->right = NULL;
        t->left = NULL;
    } else {

    if (num > t->value){
        insert(t->right, num);
    } else {
        insert(t->left, num);
    }
    }

}


void display(tree* t){
    if (t->right){
        display(t->right);
    }
    printf("%d", t->value);
    if (t->left){
        display(t->left);
    }
    
}


void destroy(tree* t) {
    if (t != NULL) {
        destroy(t->right);
        destroy(t->left);
        free(t);
    }
}




int main(){
    tree t = {4};
    insert(&t, 5);
    insert(&t, 6);
    insert(&t, 2);
    insert(&t, 1);
    insert(&t, 8);
    display(&t);
}