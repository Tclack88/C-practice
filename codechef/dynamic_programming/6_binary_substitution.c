/* https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/BINARYSUB
helpful to review this: https://youtu.be/oBt53YbR9Kk?si=inBqB05_-h3VL102&t=16793
In this, we are reading a string of a's and b's. We want to determine how many ways we can construct it from the building blocks: 'a','b','ab','ba'. eg. "abba" has 5 ways: (a+b+b+a,ab+ba,a+b+ba,ab+b+a,a+ba+b). 
Strategy:
We have 4 possible substrings, I need to make a counting array as long as the string being read in. Then from there, see how many of the substrings can be placed in that spot. so with 'abba' at that first index, I can choose 'a' which will fill out that first spot, or I can choose 'ab' which will fill out those first two spots. Then I move forward. From the next spot, I can chose 'b' to fill that spot, or 'ba' to fill out the next spot and so on. The array will actually represent the number of possible choises of the 4 substrings up to (but NOT INCLUDING) that space. The base case is 1 as there is 1 way to choose nothing to get a blank. Then from each spot, I add the value I'm currently in forward 1 or 2 spots (since those are the only two lengths available). 
In this particular case, I will always have the current spot, so I don't need to explicitely check it, it will be a or b so, I will add the current spot forward. And I don't need to check if we have 'ab' or 'ba' to add two spots forward, instead I just can check a single time if the current and next spots differ, if so, add the current value two ahead.
INPUT:		OUTPUT:
4
ab			2
aa			1
abb			2
abab		5
*/
#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d ",&T);
	while (T--){
		char ab_string[500003];
		int count[500003];
	    scanf("%s",ab_string);
		int len = strlen(ab_string);
		memset(count,0,(len+3)*sizeof(int));
		count[0] = 1;
		for (int i=0; i<len; i++){
			if (ab_string[i] != ab_string[i+1]){
				count[i+2] += count[i];
			}
			count[i+1] += count[i];
		}
		printf("\n%d\n",count[len]);
	}
    return 0;
}

/* Works but is too slow
int main() {
	int T;
	scanf("%d ",&T);
	while (T--){
		char ab_string[500003];
		int count[500003];
		memset(count,0,500003*sizeof(int));
		count[0] = 1;
	    scanf("%s",ab_string);
		int len = strlen(ab_string);
		for (int i=0; i<len; i++){
			if (ab_string[i] == 'a'){
				count[i+1] += count[i];
				if (ab_string[i+1] == 'b')
					count[i+2] += count[i];
			}
			else if (ab_string[i] == 'b'){
				count[i+1] += count[i];
				if (ab_string[i+1] == 'a')
					count[i+2] += count[i];
			}	
		}
		printf("%d\n",count[len]);
	}
    return 0;
}
*/
