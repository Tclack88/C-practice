#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//char* even_odd();
char* even_odd(int n){
    char *ret;
    ret = malloc(100);
    if (n % 2 == 0){
        strcpy(ret, "even");
    } else {
        strcpy(ret, "odd");
    }
    return ret;
}

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    int vals[2] = {a,b};
    char words[][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //int len = sizeof(vals)/sizeof(vals[0]);
    //printf("size of words: %d\n", len);
    for (int i = 0; i<2; i++){
	    int val = vals[i];
	    printf("%s\n",(val < 9 ? words[val-1] : even_odd(val)) );
    }

    return 0;
}

