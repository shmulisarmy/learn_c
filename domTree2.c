#include <stdio.h>
#include <assert.h>  // Include this header to use assert
#include <string.h>
#include <stdlib.h>

typedef struct element element;

void* pointers[100] = {NULL};
int pointerCount = 0;

struct element{
    char tagName[10];
    char className[10];
    char text[10];
    element* children[10];
    element* parent;
    int childCount;
};



element* create_element(char tagName[10], char className[10], char text[10]){
    element* e = malloc(sizeof(element));
    assert(e);
    pointers[pointerCount] = e;
    pointerCount++;
    strcpy(e->tagName, tagName);
    strcpy(e->className, className);
    strcpy(e->text, text);
    e->childCount = 0;
    return e;
}


void appendChild(element* parent, element* child){
    child->parent = parent;
    parent->children[parent->childCount] = child;
    parent->childCount++;
}



void displayElement(element* el){
    printf("<%s class='%s'>%s\n", el->tagName, el->className, el->text);
    for (size_t i = 0; i < el->childCount; i++){
        displayElement(el->children[i]);
    }
    printf("</%s>\n", el->tagName);
    
}



int testElementConstructor(){
    printf("running test testElementConstructor\n");
    element* el = create_element("tagname", "none", "none");
    assert(strcmp(el->tagName, "tagname") == 0);
    assert(pointers[0] == el);
    return 0;
}

int main(){
    testElementConstructor();
    element* document = create_element("document", "none", "hello");
    printf("documents tagname is: %s\n", document->tagName); //debug statment
    element* body = create_element("body", "none", "world");
    appendChild(document, body);
    displayElement(document);
    for (size_t i = 0; i < pointerCount; i++){
        printf("pointer about to be freed: %p\n", pointers[i]);
        free(pointers[i]);
    }

    
}



