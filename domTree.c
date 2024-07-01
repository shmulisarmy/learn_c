#include <stdio.h>
#include <stdlib.h>



#define max_child_count 10
typedef struct DomTree DomTree;


struct DomTree{
    char* tagName;
    char* className;
    char* textContent;
    DomTree* parent;
    DomTree* children[max_child_count];
};


void constructDomTree(DomTree* dtp, char* tagName, char* className, char* textContent){
    dtp->tagName = tagName;
    dtp->className = className;
    dtp->textContent = textContent;
    dtp->parent = NULL;
    for (size_t i = 0; i < max_child_count; i++){
        dtp->children[i] = NULL;
    }
}

void appendChild(DomTree* parent, DomTree* child){
    for (size_t i = 0; i < max_child_count; i++){
        if (parent->children[i] != NULL){
            parent->children[i] = child;
        }
    }
    child->parent = parent;
    
}

void display(DomTree* dtp, int indent_level){
    for (size_t i = 0; i < indent_level; i++){
        printf("    ");
    }
    printf("<%s class='%s'> %s </%s>\n", dtp->tagName, dtp->className, dtp->textContent, dtp->tagName);
    for (size_t i = 0; i < max_child_count; i++){
        if (dtp->children[i] != NULL){
            display(dtp->children[i], indent_level+1);
        }
    }
    
}


int main(){
    DomTree document;
    constructDomTree(&document, "document", "red-primary", "hello world");

    DomTree style;
    constructDomTree(&style, "style", "uses-bootstrap", "hello this is a style");

    DomTree body;
    constructDomTree(&body, "body", "blue-primary", "my name is jerry");

    appendChild(&document, &body);

    display(&document, 0);
}