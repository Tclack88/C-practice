#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//0de5 FizzBuzz exercise as described [here](https://www.0de5.net/stimuli/just-enough-c-to-have-fun)

void fizzbuzz(char sentence[], int n){
	int digit_len;//return length of number if not divisible by 3 or 5
	int loc=0; //location to append to sentence(start at 0)
	char int_str[20]; // holds ascii value of integer i being checked

	for(int i=1; i<=n; i++){
		if(i%3==0){
			strncpy(&sentence[loc],"Fizz",4);
			loc += 4;
		}
		if(i%5==0){
			strncpy(&sentence[loc],"Buzz",4);
			loc +=4;
		}
		if(i%3 != 0 && i%5 !=0){
			digit_len = sprintf(int_str,"%d",i);
			strncpy(&sentence[loc],int_str,digit_len);
			loc+=digit_len;// will change for numnbers larger than 9
		}
		if (i==n)
			strncpy(&sentence[loc],".\n",2);
		else
			strncpy(&sentence[loc],", ",2);
		loc += 2;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	char sentence[n*6]; // Overestimated space allocation as if every spot needs "fizz, " or "buzz, " (6 chars)
	fizzbuzz(sentence, n);
	printf("%s",sentence);
	return 0;
}
