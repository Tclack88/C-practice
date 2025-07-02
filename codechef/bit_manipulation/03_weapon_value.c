// https://www.codechef.com/learn/course/bit-manipulation/BITM04/problems/SC31
/* This is a long description about finding weapon values where people fight and the the winner gains any weapons the loser had, but if they both had the same weapon, they are destroyed. The goal is to find the max weapons which can be awarded at the end. The story is awkward and really it boils down to reading in multiple numbers of 10 digit string value (0 through 1) then xor'ing them all. Finally counting the number of 1's in the final value
INPUT:			OUTPUT:
1				4
3
1110001101
1010101011
0000000011
*/
#include <stdio.h>

int str2bin(char* bin_string){
    int bin = 0;
    for (int i=0; i<10; i++){
        if (bin_string[i] == '1')
            bin += (1 << (9-i));
    }
    return bin;
}

int count_ones(int bin){
    int count = 0;
    while (bin > 0){
        if (bin % 2 == 1)
            count++;
        bin /= 2;
    }
    return count;
}

int main() {
	int T,N;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    char bin_string[11];
	    int res = 0;
	    while (N--){
	        scanf("%s",bin_string);
	        int bin = str2bin(bin_string);
	        res ^= bin;
	    }
	    printf("%d\n",count_ones(res));
	}
	return 0;
}
