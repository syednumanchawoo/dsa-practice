#include<string.h>
void swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *str, int left, int right){
    if(left >= right){
        return;
    }
    swap(&str[left], &str[right]);
    reverseString(str, left+1, right-1);
}
