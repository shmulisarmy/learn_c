#include <stdio.h>
#include <string.h>  // Include the string.h library for strcpy function



struct todo_list{
    char** string_list;
    int current_todo_amount;
};



void display_string_list(char string_list[11][11], int string_list_length){
    int i = 0;
    while (i < string_list_length){
        i++;
        printf("todo %d: %s\n", i, string_list[i]);
    }

}


struct todo_list tl;
tl.current_todo_amount = 0;


int todos_in_todos = 0;
char todos[11][11];

void add_todo(char todo[11]){
    strcpy(todos[todos_in_todos], todo);
    todos_in_todos++;
}


int main(){


    add_todo("clean room");
    add_todo("lie room");
    add_todo("do cool");
    display_string_list(todos, 10);


}