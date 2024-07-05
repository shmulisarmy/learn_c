#include <stdio.h>
#define likely(x)  __builtin_expect(!!(x), 1)




int main(){
    int num = 9;
    if (likely(num > 8)){
        printf("num is hight");
    } else {
        printf("num is low");
    }
}
