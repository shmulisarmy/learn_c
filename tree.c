#include <stdio.h>



#define max_child_count 10
typedef struct domTree domTree;
struct domTree{
    char* tagName;
    char* textContent;
    char* id;
    char* classList[max_child_count];
    struct domTree* children[10];
    struct domTree* parentElement;
};


//return type is used to notify of new index or -1 
int appendChild(struct domTree* dt, domTree* childPointer){
    for (size_t i = 0; i < max_child_count; i++)
    {
        if (dt->children[i] == NULL){
            dt->children[i] = childPointer;
            return i;
        };
    };
    return -1;
    
};


void display(domTree* element, int indent_level){
    for (size_t i = 0; i < indent_level; i++)
    {
        printf("     ");
    }
    
    printf("%s#%s: %s\n", element->tagName, element->id, element->textContent);
    for (size_t i = 0; i < max_child_count; i++){
        if (element->children[i] != NULL){
            display(element->children[i], indent_level+1);
        }
    }
}


void remove(domTree* elementPointer){
    domTree *parent = elementPointer->parentElement;
    free(elementPointer);
    elementPointer = NULL;
    for (size_t i = 0; i < max_child_count; i++)
    {
        if (parent->children[i] == elementPointer){
            parent->children[i] = NULL;
        }
    }
}




int main(){
    //will turn into a dangeling pointer when main is exited (assuming that an external program is still holding onto a pointer)
    struct domTree document = {"div", "this is the main element", "main", {"head", "leader", "menu"}};
    for (size_t i = 0; i < 10; i++)
    {
        document.children[i] = NULL;
        /* code */
    }
    
    document.parentElement = NULL;
    domTree child = {"form", "how old are you", "q", {"?"}};
    appendChild(&document, &child);
    display(&document, 0);
    
}