// https://www.codechef.com/learn/course/bit-manipulation/BITM05/problems/XOR_ORDER?tab=statement
// Work In Progress
#include <stdio.h>

int ones(int A, int B, int C){
    // finds max value, finds the number of bits required (eg n),
    // then returns 2^n (eg if 8 is max, 8 is 4 bits, will return 0b1111 (15))
    int max = (A > B ? A : B);
    max = (max > C ? max : C);
    int count = 0;
    while (max > 0){
        count++;
        max /= 2;
    }
    int ret = 0;
    for (int i=0; i < count; i++)
        ret += (1<i);
    return ret;
}

int xor_vals(int A, int B, int C){
    if (A < B && B < C)
        return 0; // probably not right
    else if (A > B && B > C)
        return ones(A,B,C);
    else
        // TODO
}

int main() {
	int T,A,B,C;
	scanf("%d",&T);
	while (T--){
	    scanf("%d %d %d",&A,&B,&C);
	    printf("%d\n",xor_vals(A,B,C));
	}
    return 0;
}
