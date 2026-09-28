
//Remark: Working but needs improvement
void insertion_sort(int arr[], int size){
    int key = 0;
    for(int i=0; i<size-1; i++){
        key = arr[i+1];
        for(int j=i; j >= 0; j--){
            if(arr[j] > key){
                arr[j+1] = arr[j];
            }
            else if(arr[j] <= key){
                arr[j+1] = key;
                break;
            }
            if(j==0){
                arr[0] = key;
            }
        }
    }
}
