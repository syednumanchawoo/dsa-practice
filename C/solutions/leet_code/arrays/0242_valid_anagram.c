/*
Problem: 242. Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/
*/

#include<stdio.h>
#include<stdbool.h>

/*
Time: O(n)
Space: O(1)
*/
bool isAnagram(char* s, char* t) {
    int s_alpha[26] = {0}, t_alpha[26] = {0}, i=0;
    while((s[i] != '\0') || (t[i] != '\0')){
        if((s[i] != '\0') != (t[i] != '\0')){
            return false;
        }
        s_alpha[s[i]-'a'] += 1;
        t_alpha[t[i]-'a'] += 1;
        i++;
    }
    for(int i=0; i<26; i++){
        if(s_alpha[i] != t_alpha[i]){
            return false;
        }
    }
    return true;
}

/*
Time: O(n)
Space: O(1)
Used Single Array instead of two
*/

bool isAnagram(char* s, char* t){
    int alpha[26] = {0}, i = 0;
    
    while((s[i] != '\0') || (t[i] != '\0')){
        if((s[i] != '\0') != (t[i] != '\0')){
            return false;
        }
        // Change
        alpha[s[i]-'a'] += 1;
        alpha[t[i]-'a'] -= 1;
        i++;
    }
    for(int i=0; i<26; i++){
        if(alpha[i] != 0)
            return false;
    }
    return true;
}
