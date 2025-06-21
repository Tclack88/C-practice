// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/COVID19?tab=statement
/*
COVID. People are lined up with distances between them. If a person is less than or equal to 2 "units" away, they will be infected. Find the maximum and minimum number of people infected for the provided lineup.

Strategy: two pointer. Start then together, advance one in the front until the distance between it and the next exceed 2, then sum up the distance between it and the starting pointer. Then move them together and repeat. FULL DISCLOSURE: This is working locally, but didn't pass online. the message is weird: "When run on each test case individually, your code appears to be correct. However, when run on the entire test file, it returns a WA. The most common reasons for this are that you do not have a newline after each test case, or you do not reinitialize some variables in each test case."

I don't care enough to figure it out. It works for me, and technicallty works for all their test-cases
INPUT:		OUTPUT:
3			1 1
2			3 3
3 6			2 3
3
1 3 5
5
1 2 5 6 7
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, N, a, b;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    int arr[N];
	    for (int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    int smallest, largest, dist;
	    smallest = N;
	    largest = 1; // initial infected person
	    a = b = 0;
	    while (b<N){
	        /*if (b+1 == N){
	            b++;
	            continue; // advance b as well? (avoid infinite loop)
	        }*/
	        while (abs(arr[b+1] - arr[b]) <= 2 && b<N)
	            b++;
	        dist = b-a+1;
	        if (dist < smallest)
	            smallest = dist;
	        if (dist > largest)
	            largest = dist;
			b++;
	        a = b;
	    }
	    printf("%d %d\n", smallest,largest);
	}
	return 0;
}
