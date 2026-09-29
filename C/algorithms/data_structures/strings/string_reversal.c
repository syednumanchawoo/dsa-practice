#include<string.h>
void swap(char* a, char* b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char str[]){
    int len = strlen(str);
    for(int i = 0; i < len-1-i; i++){
        swap(&str[i], &str[len-1-i]);
    }
}
