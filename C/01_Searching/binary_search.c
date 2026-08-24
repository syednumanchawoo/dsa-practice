/*
Binary search is a way to find a target value in a sorted array by repeatedly looking at the middle
element and deciding whether the target must be in the left half or the right half, then repeating
on that half. It is much faster than linear search for large sorted arrays.
*/

#include <stdio.h>

int main(){
    int arr[12] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int lowest = 0, highest = sizeof(arr)/sizeof(arr[0])-1, mean;
    int target = 55;
    int found = 0;

    

    while(lowest <= highest){
        mean = (lowest + highest) / 2;
        if (target == arr[mean]){
            printf("Target found on index %d", mean);
            found = 1;
            break;
        }
        
        else if (target > arr[mean]){
            lowest = mean+1;
        }
        else {
            highest = mean-1;
        }
    }

        if (found == 0){
            printf("Target not Found\n");
        }

    return 0;
}
