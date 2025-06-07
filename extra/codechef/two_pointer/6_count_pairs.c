// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/DSAPROB15?tab=solution
/*
In a sorted array, count all pairs that are less than a certain value x.

My original solution was the brute-force nested for loops (for i in range n, for j in range(i,n) .... ), but it exceeded the time limit. My next attempt came after the hint that I begin with two pointers, one at either end. I decremented the top pointer until the sum of arr[bot] and b[top] was less than x. In that case, I just counted all values as a difference beween top and bottom without needed to check. After this, I would increment a and reset b back to the top. This was closer but still exceeded run time.

Finally, I caved and read the approach:
start with two pointers, one at the bottom and one at the top. if arr[bot] + arr[top] > x, decrement b. Else, we know that everything between is fine (by keeping the bottom and decrementing the top) so just count the difference between the indices. That was my thinking above. However instead of incrementing bottom and resetting top. I just have to increment the bottom and do the same check. End when they meet
INPUT:			OUTPUT:
5
1 2 3 4 5		6
7
NOTE: the main funtion was given to me, I didn't need to write it.
*/
#include <stdio.h>

long long countPairsLessThanX(int arr[], int n, int x) {
    long long count = 0;
    int a=0;
    int b=n-1;
    while (b > a){
        if (arr[a] + arr[b] >= x)
            b--;
        else{
            count += b-a;
            a++;
        }
    }
    return count;
}

int main() {
    int n, x;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    printf("%lld\n", countPairsLessThanX(arr, n, x));
    return 0;
}

