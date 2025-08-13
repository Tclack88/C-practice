//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ALTARAY?tab=statement
/* In this, we are supposed to find the longest alternating (+ - + - ...) subarray in the provided array starting from the index

strategy: noticing the very right element will be a 1, because there is no change after that. Then if I work leftwards, as long as the sign changes during each move, that number will increment. If it's the same sign, it will be reset to a 1
INPUT:				OUTPUT:
3
4
1 2 3 4				1 1 1 1
4
1 -5 1 -5			4 3 2 1
6
-5 -1 -1 2 -2 -3   1 1 3 2 1 1
*/
#include <stdio.h>

void printArr(int arr[], int size){
    for (int i=0; i < size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int sign_change(int a, int b){
    if ( (a < 0 && b < 0) || (a > 0 && b > 0) )
        return 0;
    return 1;
}

int main() {
    int T, N, size;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&N);
        size = N; // backup the value for printing
        int arr[N];
        for(int i=0; i<N; i++)
            scanf("%d", &arr[i]);
        int sol[N];
        sol[N-1] = 1;
        N--;
        while(--N >= 0){
            // if (arr[N]*arr[N+1] < 0) // Overflow occurs if too large
            if ( sign_change(arr[N],arr[N+1]) )
                sol[N] = sol[N+1] + 1;
            else
                sol[N] = 1;
        }
        printArr(sol,size);
    }
    return 0;
}
