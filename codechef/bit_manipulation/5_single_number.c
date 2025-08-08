//https://www.codechef.com/practice/course/bit-manipulation/BITMF/problems/PREP45
/*
Given a list of numbers, one of those numbers will not have a "matchign pair". Find it and print.
Strategy: To avoid nested for loops, it's clear that any number xor'd with itself will return 0. So if I just take the numbers and stream xor them with each other, all the pairs will zero out each other and the remaining value will just be that unpaired number

INPUT:				OUTPUT:
4
1
5					5
5
2 5 2 10 10			5
5
1 1 10 10 15		15
5
6 8 10 6 8			10
*/
#include <stdio.h>

int main() {
	int T, N, n;
	scanf("%d",&T);
	while (T--){
	    scanf("%d", &N);
	    int val = 0;
	    for (int i=0; i<N; i++){
	        scanf("%d", &n);
	        val ^= n;
	    }
	    printf("%d\n", val);
	}
    return 0;
}
