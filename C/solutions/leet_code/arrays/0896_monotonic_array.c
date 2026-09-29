/*
Problem: 896, Monotonic Array
Link: https://leetcode.com/problems/monotonic-array/
*/

#include<stdbool.h>

/*
Solution 1
Remark: Overengineered but efficient
*/

bool isMonotonic(int* nums, int numsSize) {
    bool mono = true, inc = false, dec = false;
    int i;
    for(i=0; i<numsSize-1; i++){
        if(nums[i] < nums[i+1]){
            inc = true;
            break;
        }
        else if(nums[i] > nums[i+1]){
            dec = true;
            break;
        }
    }
    if(!inc && !dec){
        return mono;
    }
    if(inc){
        for(i=i+1; i<numsSize-1; i++){
            if(nums[i] > nums[i+1]){
                mono = false;
                return mono;
            }
        }
    }
    else{
        for(i=i+1; i<numsSize-1; i++){
            if(nums[i] < nums[i+1]){
                mono = false;
                return mono;
            }
        }
    }
    return mono;
}

bool isMonotonic(int* nums, int numsSize){
    bool inc = true, dec = true;

    for(int i=0; i<numsSize-1; i++){
        if(nums[i] < nums[i+1]){
            dec = false;
        }
        else if(nums[i] > nums[i+1]){
            inc = false;
        }
    }
    if(inc || dec){
        return true;
    }
    return false;
}
