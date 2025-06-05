// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PREP68?tab=Help
/*
take in size of array (N), a special number (B), then determine if the absolute value of any two numbers in the array equals B

INPUT:					OUTPUT
3
6 78
5 10 3 2 50 80			1
2 30
-10 20					1
4 5
1 2 3 4					0
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int T,N,B,a,b,count;
	scanf("%d",&T);
	while(T--){
	    scanf("%d",&N);
	    scanf("%d",&B);
	    int arr[N];
	    for (int i=0; i<N; i++)
	        scanf("%d",&arr[i]);
	    a = 0;
	    b = 1;
	    count = 0;
	    while (a<N){
	        while(b<N){
	            count += abs(arr[a] - arr[b]) == B;
	            b++;
				if (count) // cannot use "continue" otherwise would
					b=N;   // would break out of while(T--) loop
	        }
	        a++;
			b=a+1;
			if (count) // cannot use "continue" otherwise would
				a=N;   // would break out of while(T--) loop
	    }
	    printf("%d\n",count > 0 ? 1: 0);
	}
    return 0;
}
