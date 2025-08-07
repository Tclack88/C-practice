// codechef.com/learn/course/bit-manipulation/BITM05/problems/EQBYXOR?tab=statement
/*
In this problem, we are given 3 numbers, A, B and N. We must determine how many XOR operations must be done on A to convert A to B. This of course would only just be 1 except the catch is an upper limit N is introduced as a number we are unable to exceed.

Strategy: If A == B, then nothing needs to be changed (and the limit N is guaranteed to be greater than 0, it's at least 1) so return zero. Otherwise, XOR A and B to find what number must be used to change A to B. If this number (X) is under the limit (N) then it of course can be XOR'd with a single operation. Now for the trick part. Just because X is greater than, N that doesn't mean it's impossible. Take for instance X = 1010 and N = 1001. We can xor once with 1000 and then with 1. However if N = 1000, we are unable to, because we must remove that leading 1. So we can check if the most-significant 1's are equal (or that they have the same number of digits). In this case, as long as N has more than one 1, then we can break X down into 2 sub operations, once to remove that leading 1 and again to remove the rest. Otherwise it's impossible
INPUT:		OUTPUT:
8
5 5 2		0
3 7 8		1
8 11 1		-1
24 27 3		2
2 3 1		-1
3 7 4		-1
12 6 9		2
1 4 4		-1
*/
#include <stdio.h>

int find_size(int A, int B){
    int max = A >= B ? A : B;
    int min = A > B ? A : B;
    int size = 0;
    while(max > 0){
        max /= 2;
        size++;
    }
    // printf("size: %d, ",size);
    return size;
}

int num_digits(int n){
	int size = find_size(n,0);
	int count = 0;
	for (int i=0; i <size; i++){
		if (n & (1<<i))
			count++;
	}
	return count;
}

int equal_xor(int A, int B, int N){
    if (A == B)
        return 0;
    int n_digits = find_size(N,0);
    int size = find_size(A,B);
    int X = 0;
    for(int i=0; i <= size; i++){
        int digit = (1 << i);
        if( (A&digit) ^ (B&digit) )
            X += digit;
    }
	int x_digits = find_size(X,0);
    // printf("X: %d\n",X);
	//printf("\tA: %d, B: %d, X: %d (%d), N: %d (%d)\n",A,B,X,x_digits, N,n_digits); 
    if (X < N)
        return 1;
    else if ( (find_size(X,0) == find_size(N,0)) && (num_digits(N) > 1 ) )
        return 2;
    return -1;
}

int main() {
    int T, A, B, N;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&A, &B, &N);
        printf("%d\n", equal_xor(A,B,N));
    }
    return 0;
}
