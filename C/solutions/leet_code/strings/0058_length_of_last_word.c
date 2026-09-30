/*
Problem: 58
Link: https://leetcode.com/problems/length-of-last-word/
*/

/*
Solution 1
Remark: Efficient and Correct
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

/*
Solution 2
Remark: 1 is better for this problem
*/
int lengthOfLastWord(char* s){
    int len = 0;
    for(int i=0; s[i] != '\0'; i++){
        if(i>0 && s[i-1] == ' ' && s[i] != ' '){
            len = 1;
            continue;
        }
        else if(s[i] == ' '){
            continue;
        }
        len++;
    }
    return len;
}

