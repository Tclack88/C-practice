//https://leetcode.com/problems/reverse-string-ii
#include <stdio.h>

char* reverseStr(char* s, int k) {
    char* f; // front
    char* b; // back
    char tmp;
    int top = strlen(s);
    int i=0;
    while( i <= top-k){
        for(int j=0; j< k/2; j++){
            f = &s[i+j];
            b = &s[i+k-j-1];
            tmp = *f;
            *f = *b;
            *b = tmp;
        }
		i += 2*k;
    }
    int rem = top - i; // remainder
    if (rem > 0){
        for(int j=0; j<rem/2; j++){
            f = &s[i+j];
            b = &s[i+rem-j-1];
            tmp = *f;
            *f = *b;
            *b = tmp;
        }
    }
}
