// https://www.codechef.com/learn/course/bit-manipulation/BITM05/problems/ANDSUBAR?tab=statement
/* Given some input number N, the goal here is to consider sequentially bitwise and of each value from 1 to N. We must find and return the largestlength of any non-zero contiguous subset of values in that range
Observation: The boundary between any power of 2 will bitwise and to zer0. eg 1&2,  3&4,  7&8, 15&16, 31&32 ... etc. So between these (and includeing the endpoints) we can find non-zer0 continuous vals i..e everything between and includeing 2-3, 4-7, 8-15, 16-31, etc.
Now, if I have a number on the lower range (like 9), then the range of values before that will be larger (4 through 7 sum to 4), that's larger than 8-9 (2). But if it's in the upper range, then my largest range is simply the difference between that value and the lower power of two (eg. for 14, 8 though 15 is 8 which is larger than 4 through 7 (4).
So for each value N, I find what the "upper" power of 2 is, the "lower" power of 2 and the "even_lower" power of 2.
eg. for 9, upper = 16, lower = 8, even_lower = 4. Then i just compare 8->9 vs 4->8
INPUT:				OUTPUT:
8 (8 test cases)
1					1
2					1
3					2
4					2
7					4
8					4
9					4
30					15
*/
#include <stdio.h>

int longest_and(int N){
    // printf("for %d, ",N);
    int count = 0;
    int upper = 0;
    while(upper < N){
        upper = 1<<count;
        count++;
    }
    int lower = 1<<(count-2);
    int even_lower = 1<<(count-3);
    if (upper == 1){ // special case for 1
        lower = 0;
        even_lower = 0;
    }
    if (upper == N)
        return (N - lower); // guaranteed surrounded by zeros
    int top = N - lower + 1;
    int bottom = lower - even_lower;
    return (top >= bottom) ? top : bottom; // total elements
}

int main() {
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d\n", longest_and(N));
    }
	return 0;
}

/*This should work, however it's too slow
one slight optimizaton here is computing the arr once so it doesn't have
to be created from scratch for every test
int main() {
    int T,N;
    scanf("%d",&T);
    int arr[10001]; // build array 1st and once
    for (int i=0; i<10001; i++)
        arr[i] = (i)&(i+1);
    while(T--){
        scanf("%d",&N);
        int longest = 0;
        int last_index = 0; // last index when longest stretch is found
        int count = 0;
        for (int i=1; i<N; i++){
            if (arr[i]==0){
                if (count > longest){
                    longest = count;
                    last_index = i;
                }
                count=0;
            }
            else
                count++;
        }
        if (count > longest)
            longest = count;
        if (arr[last_index]==0)
            printf("%d\n", longest+1);
        else
            printf("%d\n",longest);
    }
	return 0;
}*/
