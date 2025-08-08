//https://www.codechef.com/practice/course/bit-manipulation/BITMF/problems/CIELRCPT
/*
background: Someone wants to order items on a menu (cost happens to be powers of 2 from $1 to $2048) and they want to find the smallest number of dishes that can be ordered to meet a certain price

Strategy: Binary is layed out in a way such that all numbers are represented by 1's in a 0,1,2,4,8... etc. place. The total number is just the sum of the items in that spot. As all items on the menu have no gaps, it's as straightforward as adding up all the 1's in the binary representation of the number (and if the number exceeds 2048, we must subtract off multiples of 2048 until the value is less tthan 2048, and then we do as above)

INPUT:			OUTPUT:
4
10					2  <--- 2+8
256					1  <--- 256
255					8  <--- 1+2+4+8+16+32+64+128
4096				2  <--- 2048 is the max value, so two 2048's
*/
#include <stdio.h>

int count_bits(int N){
    int bit_count = 0;
    for (int i=0; i < 12; i++){
        bit_count += ((N & (1<<i)) >= 1);
    }
    return bit_count;
}

int main() {
	int T, N;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    int total = 0;
	    while (N > 2048){
	        total++;
	        N -= 2048;
	    }
	    total += count_bits(N);
	    printf("%d\n", total);
	}
    return 0;
}
