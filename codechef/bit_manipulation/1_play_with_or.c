//https://www.codechef.com/learn/course/bit-manipulation/BITM05/problems/FIZZBUZZ2304?tab=statement
/*Given an array of N integers and a "window-size" (subarray, contiguous elements) K, determine if that window of values contains an odd number. The strategy was to make a subarray of 1 or 0 (1 if odd, obtained from bitwise-or). Then add the values. If it's still 0, that array is even. Then change just one value in that array, i.e. add the next value (1 or 0), then repeat
INPUT:		OUTPUT:
2				3
5 2				2
5 7 13 4 6
4 3
2 6 7 4
*/
#include <stdio.h>

// This worked, but time limit exceeded for large values
// int bit_or(int arr[], int N, int K){
//     int count = 0;
//     for (int i=0; i<=(N-K); i++){
//         int res = 0;
//         for(int j=0; j<K; j++)
//             res |= (arr[i+j]&1);
//         if (res & 1)
//             count++;
//     }
//     return count;
// }

int bit_or(int arr[], int N, int K){
    int is_odd = 0;
    int count = 0;
    int subset[K];
    for (int i=0; i<K; i++){// set initial array as first K values
        subset[i] = (arr[i] & 1);
        if (subset[i])
            is_odd = 1; 
    }
    if (is_odd)
        count++; // count if starting array has an odd number
	// strategy: replace just one number in a rolling array of K values
	// checking if any of them are 1. If so, increase count
    for (int i=K; i<N; i++){
        subset[(i-K)%K] = (arr[i] & 1);
		is_odd = 0;
		for (int j=0; j<K; j++){
			is_odd += subset[j];
			if (is_odd){ // early break
				count++;
				break;
			}
		}
    }
    return count;
}

int main() {
	int T, N, K;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d",&N, &K);
	    int arr[N];
	    for (int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    printf("%d\n", bit_or(arr,N,K));
	}
    return 0;
}
