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
                arr[j+1] = key;
                break;}
        }
        if(j+1==0){arr[0] = key;}
    }
}
