// https://www.codechef.com/learn/course/bit-manipulation/BITM05/problems/XOR_ORDER?tab=statement
/*The "working" solution following the comment was an accident/guess
I don't see how it works generally, it's only flipping one bit
and it passed all test cases, but it seems that you would need
to strategically flip one bit as I have below and put the sum of those
flipped bits together. In fact my code works from the left and flips the left most bit when there's a difference that will give a correct order, 
but then it continues while there is no solution where as the "working"
solution merely flips one bit, it would only supply 10, 100, 1000, etc.
Since my code qalso does that, it should pass, yet the failed test case
was
1
1 2 3

which my code returned 0 (a valid solution) however it was flagged as
incorrect and I still do not understand ;/ Finally, this worked too 
return 1<<ones_count(C); instead of returning 0 when A < B < C
(i.e. already met condition with given vals), but it was (and still is)
rejected

UPDATE: after submitting the version 2, my version 1 passed when I 
re-submitted, I'm going to chalk this up to a bug. My original version 
will be labeled xor_vals1 and the other brute forcey one xor_vals2
INPUT:		(possible) OUTPUT:
3
1 2 3				4
3 1 2				-1
3 2 1				3
*/
#include <stdio.h>

int ones_count(int n){
    int count = 0;
    while (n > 0){
        count++;
        n /= 2;
    }
    return count;
}

int ones(int A, int B, int C){
    // finds max value, finds the number of bits required (eg n),
    // then returns 2^n (eg if 8 is max, 8 is 4 bits, will return 0b1111 (15))
    int max = (A > B ? A : B);
    max = (max > C ? max : C);
    int count = ones_count(max);
    // printf("\ncount: %d\n", count);
    int ret = 0;
    for (int i=0; i < count; i++){
        ret += (1<<i);
        // printf("ret: %d ", ret);
    }
    return ret;
}

int find_switch_bit(int m, int n){
    int max = (m > n ? m : n);
    int min = (m < n ? m : n);
    int size = ones_count(max);
    for (int i=size-1; i>=0; i--){
        if ( (min & 1<<i) ^ (max & 1<<i) ) // max is 1 and min is 0. flip here
            return 1<<i;
    }
    return 0;
}

/* This version was my personal attempt.*/
int xor_vals1(int A, int B, int C){
    if (A < B && B < C)
        return 0; // return 1<<ones_count(C);
    else if (A > B && B > C)
        return ones(A,B,C);
    else{
        int X = 0;
        if (A > B)
            X += find_switch_bit(A,B);
        if (B > C)
            X += find_switch_bit(B,C);
        if ( ( (A^X) < (B^X)) && ((B^X) < (C^X) ) )
            return X; 
        return -1;
    }
}
/* this was the "accepted" version. it's brute-forcy, I don't like it and
also doesn't currently make sense as to why it would work generally*/
int xor_vals2(int A, int B, int C){
    if (A < B && B < C)
        return 0; // return 1<<ones_count(C);
    else if (A > B && B > C)
        return ones(A,B,C);
    else{
        for (int i=0; i < 30; i++){
            int X = 1 << i;
            if ( ( (A^X) < (B^X) ) && ( (B^X) < (C^X) ) )
                return X;
        }
        return -1;
    }
}


int main() {
	int T,A,B,C;
	scanf("%d",&T);
	while (T--){
	    scanf("%d %d %d",&A,&B,&C);
	    printf("%d\n",xor_vals1(A,B,C));
	}
    return 0;
}
