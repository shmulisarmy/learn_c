#include <stdio.h>


typedef struct Meeting Meeting; ;

struct Meeting{
    int priority;
    int startTime;
    int endTime;
};


int get_best_meeting_time(Meeting meetings[], int meetings_length, int new_meeting_size){
    //sliding window
    int firstPointer = 0;
    int secondPointer = 1;
    int lowest_cost_so_far = 10000;
    int current_cost = 0;
    int current_available_time;

    while (secondPointer < meetings_length){
        current_available_time = meetings[secondPointer].startTime  - meetings[secondPointer].endTime;
        if (current_available_time < new_meeting_size){
            //not enough time availible
            current_cost+=meetings[secondPointer].priority;
            secondPointer++;
        } else{
            //enough time
            firstPointer++;
            current_cost-=meetings[firstPointer].priority;
            if (current_cost < lowest_cost_so_far){
                lowest_cost_so_far = current_cost;
            }
        }
    }
    return lowest_cost_so_far;
}



int main(){
    Meeting meetings[10] = {
        {1, 5, 6},
        {9, 13, 2},
        {13, 15, 1},
        {18, 25, 4},
        {21, 26, 6},
    };
    printf("smallest cost to insert meeting of size 4 is %d", get_best_meeting_time(meetings, 5, 4));
}
