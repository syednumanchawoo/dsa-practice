/*
Problem: 28
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Last Remark: Reattempt
*/


/*
Time: O(N * M)
Space: O(1)
*/

int strStr(char* haystack, char* needle){
    int i = 0, j = 0, index = -1;
    while(haystack[i] != '\0'){
        if(haystack[i] == needle[0]){
            index = i;
            int j = 0, k = i;
            while(1){
                if(needle[j] == haystack[k]){
                    j++;
                    k++;
                }
                else{
                    break;
                }
                if(needle[j] == '\0'){
                    return index;
                }
            }
        
        }
        index = -1;
        i++;
    }
    return index;
}

