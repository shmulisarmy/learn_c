#include <stdio.h>
#include <string.h>




struct todo_list{
    int todo_amount;
    int max_size;
    int max_todo_size;
    char todos[10][10];
};


void todo_list_constructor(struct todo_list* tl){
    tl->max_size = 10;
    tl->max_todo_size = 10;
    tl->todo_amount = 0;
}


int add_todo(struct todo_list* tl, char* new_todo){
    if (strlen(new_todo) > tl->max_todo_size){
        printf("your todo is too long\n");
        return -1;
    }
    if (tl->todo_amount < tl->max_size){
        int index_of_new_todo = tl->todo_amount;
        strcpy(tl->todos[index_of_new_todo], new_todo);
        tl->todo_amount++;
        printf("your todo has been successfully added");
        return index_of_new_todo;
    } else {
        printf("this todo list is already full\n");
        return -1;
        
    }

}


void display_todos(struct todo_list* tl){
    for (short i = 0; i < tl->max_size; i++)
    {   
        printf("\ntodo %d: %s", i, tl->todos[i]);
    }
    
}




int main(){
    struct todo_list tl;
    todo_list_constructor(&tl);
    add_todo(&tl, "clean");
    add_todo(&tl, "stuff");
    display_todos(&tl);

}