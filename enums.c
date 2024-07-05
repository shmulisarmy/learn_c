#include <stdio.h>




enum size{
    small = 10,
    medium = 15,
    large = 20,
};




struct user{

};



int main(){
    enum size showSize = large;
    printf("%d", showSize);
}
