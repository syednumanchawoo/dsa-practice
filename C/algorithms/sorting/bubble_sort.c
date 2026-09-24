#include <stdio.h>
#include<stdbool.h>

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    bool swapped = true;
    for(int i = 0; i<n; i++){
        if(swapped == false){
            break;
        }
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
    }
}
