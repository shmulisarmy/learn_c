#include <stdio.h>




typedef struct  person person;
#define display(p) printf("this persons name is %s and his age is %d\n", p.name, p.age);
#define f printf("fuck you\n")


struct person{
    char* name;
    int age;
};




// void display(person* p){
//     printf("this persons name is %s and his age is %d\n", p->name, p->age);
// }





int main(){
    person people[10];
    people[0].name = "shmuli";
    people[0].age = 20;
    display(people[0]);
}
