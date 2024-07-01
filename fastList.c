//i discovered that doing multiplication is way faster than reading from memory unless cached



#include <stdio.h>

void displayList(int nums[], int size){
    for (size_t i = 0; i < size; i++)
    {
        printf("index %zu: %d\n", i, nums[i]);
    }
}


int main(){
    int nums[20];
    for (size_t i = 0; i < 20; i++)
    {
        nums[i] = i*i;
    }
    displayList(nums, 20);
    nums = realloc(nums, sizeof(int)*40)

    
    
}