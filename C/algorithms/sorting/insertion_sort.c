#include <stdio.h>

void insertion_sort(int arr[], int size){
    if(size <= 1 ) {return;}
    int key;
    
    for(int i=1; i<size; i++){
        key = arr[i];
        int j;
        for(j=i-1; j>=0; j--){
            if(key < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;}
        }
        arr[j+1] == key;
    }
}

// Cleanest Code

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
