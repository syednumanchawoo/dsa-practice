/*
Problem: 709
Link: https://leetcode.com/problems/to-lower-case/
*/

/*
Solution 1
Remark: Efficient
*/
char* toLowerCase(char* s) {
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 65 && s[i] <= 90){
            s[i] = s[i] + 32;
        }
        i++;
    }
    return s;
}

/*
Solution 2
No need to remember ASCII Values
*/
char* toLowerCase(char* s) {
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] + ('a' - 'A');
        }
        i++;
    }
    return s;
}
