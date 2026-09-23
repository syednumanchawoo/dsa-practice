#include<stdio.h>
#include "../include/array_utils.h"

size_t inputArray(int arr[], size_t max_size){
    size_t elements_read = 0;

    for(size_t i=0; i < max_size; i++){
        printf("arr[%zu]: ", i);
        
        // Ensure exactly 1 integer was read
        if(scanf("%d", &arr[i]) != 1){
            // Clear the bad input from the buffer so it doesn't break future reads
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Invalid input detected. Terminating array input.\n");
            break;
        }

        elements_read++;
    }
    return elements_read;
}
