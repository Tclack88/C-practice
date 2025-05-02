#include <stdio.h>
#include <string.h>
/* This is some code I wrote the 2 days around Christmas 2022. It's
 * supposed to take Roman numeral strings and converts it to numbers.
 * I'm quite certain it's inefficient code (question was prompted in leetcode)
 * But I'm saving it in order to see how much I improve later on
 */
int val_index(char s, char **numerals, int *values){
    int j = 0;
    while (strncmp(numerals[j], &s,1) != 0){
        j++;
    }
    return values[j];
}

int romanToInt(char * s){
    char *numerals[] = {"I","V","X","L","C","D","M"};
    int values[] = {1,5,10,50,100,500,1000};
    int total = 0;
    int max = sizeof(numerals)/sizeof(numerals[0])-1;
    for (int i = 0; i<strlen(s); i++){
        int j = val_index(s[i], numerals, values);
        if (i+1 == strlen(s)){
            total += j;
        }
        else if (j > val_index(s[i+1],numerals,values)){
            total+= j;
        }
        else {
            int subtotal = 0;
            int smaller = 0;
            while (j == val_index(s[i],numerals,values)){
                subtotal += j;
                i++;

                if (i==strlen(s)){
                    break;
                }
                if (j < val_index(s[i],numerals,values)){
                smaller = 1;
                }
            }
            if (smaller){
                total -= subtotal;
            }
            else{
                total += subtotal;
            }
            if (i <= strlen(s)-1){
                i--;
            }
        }
    }
    return total;
}
