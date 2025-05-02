// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <stdio.h>
#include <string.h>

char* reverseWords(char* s) {
    char* f; // front
    char* b; // back
    int len = strlen(s);
    f = &s[0];
    b = &s[0];
    char tmp;
    char* save;
    while(*f != '\0'){
        while(*b != ' ' && *b != '\0'){
            b++;
        }
        save = b;
        b--;
		while(f < b){
            tmp = *f;
            *f = *b;
            *b = tmp;
            f++;
            b--;
        }
		if(*save != '\0') // check to avoid overstepping bounds of string (leading to seg fault)
			save++;
		
        f = save;
        b = f;
    }
    return s;
}

int main(){
	char words [] = "my name is trevor";
	char rev[50];
	printf("%s\n",reverseWords(words));
}
