//Linear Search
int min_array(int arr[], int size){
    int min = arr[0];
    for (int i=1; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
return min;
}

int max_array(int arr[], int size){
    int max = arr[0];
    for (int i=1; i < size; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
return max;
}

void min_max_array(int arr[], int size, int *min, int *max){
    if (size <= 0)
        return;
    *min = arr[0], *max = arr[0];
    for (int i=1; i < size; i++){
        if(*min > arr[i]){
            *min = arr[i];
        }
        if(*max < arr[i]){
            *max = arr[i];
        }
    }
}
