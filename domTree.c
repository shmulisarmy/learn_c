#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct htmlElement htmlElement;

struct htmlElement {
  char tagName[10];
  char className[10];
  char attributes[10];
  char text[20];
  int childCount;
  htmlElement *children[10];
  htmlElement *parent;

};



void appendChild(htmlElement* parent, htmlElement* child){
  parent->children[parent->childCount] = child;
  parent->childCount++;
  child->parent = parent;
}


htmlElement* create_htmlElement(char tagName[10], char text[10], char className[10], char attributes[10], htmlElement* parent){
    htmlElement* e = (htmlElement*)malloc(sizeof(htmlElement));
    if (!e) {
        fprintf(stderr, "Error allocating memory.");
        exit(EXIT_FAILURE);
    }
    strcpy(e->text, text);
    strcpy(e->className, className);
    strcpy(e->attributes, attributes);
    strcpy(e->tagName, tagName);
    e->childCount = 0;
    // for(int i = 0; i < passed_child_len; i++){
    //     e->children[i] = children[i];
    // }
    appendChild(parent, e);
    return e;
}


void display(htmlElement* elementPointer, int indentLevel){
  for (size_t i = 0; i < indentLevel; i++)
  {
    printf("  ");
  }
  
    printf("<%s class='%s'>", elementPointer->className, elementPointer->className);
    for (size_t i = 0; i < 10; i++)
    {
      if (elementPointer->children[i] != NULL){
        display(elementPointer->children[i], indentLevel+1);
      }
    }
    for (size_t i = 0; i < indentLevel; i++)
    {
      printf("  ");
    } 
    printf("</%s>", elementPointer->tagName);

}


int main(){
    htmlElement* document = create_htmlElement("document", "document", "none", "none", NULL);
    htmlElement* body = create_htmlElement("body", "body", "none", "none", document);
    htmlElement* h1 = create_htmlElement("h1", "h1", "none", "none", body);
    strcpy(h1->text, "hello world");
    htmlElement* p = create_htmlElement("p", "p", "none", "none", body);
    strcpy(p->text, "this is a test");
    display(document, 0);
}
