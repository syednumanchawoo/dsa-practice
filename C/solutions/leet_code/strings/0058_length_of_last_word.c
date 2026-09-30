/*
Problem: 58
Link: https://leetcode.com/problems/length-of-last-word/
*/


int lengthOfLastWord(char* s) {
    int i = 0, length=0;
    while(s[i] != '\0'){
        i++;
    }
    i--;
    while(s[i] == ' '){
        i--;
    }
    
    while(i>=0 && s[i] != ' '){
        length+=1;
        i--;
    }
    return length;
}
