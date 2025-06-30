// https://www.codechef.com/practice/course/heaps/HEAPF/problems/CAPPLE?tab=Help
/* Another weird problem that doesn't have to do with heaps and boils down to counting the uniq elements. The max value of the elements is 10^5, so the plan was to make an array that large, zero it out, then increment that place in the array. in the end, summing the non-zero elements is tantamount to counting
INPUT:			OUTPUT
2
3
3 3 3			1
4
1 2 3 3			3
*/

#include <stdio.h>


int main() {
	const int MAX=100001;
    int T, N, n;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&N);
        int arr[MAX];
        for (int i=0; i<MAX ; i++)
            arr[i] = 0;
        for (int i=0; i<N; i++){
            scanf("%d",&n);
            arr[n] += 1;
        }
        int total = 0;
        for (int i=0; i<MAX; i++){
			if (arr[i] != 0)
				total++;
		}
            //total += (arr[i] == 0 ? 0 : 1);
        printf("%d\n",total);
    }
	return 0;
}
