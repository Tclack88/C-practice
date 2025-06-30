//https://www.codechef.com/practice/course/heaps/HEAPF/problems/RRCOPY?tab=statement
/* another one of those problems that don't seem like they are meant for heaps
a complicated description really just to determine the number of unique elements of an array
INPUT:		OUTPUT:
2
5
1 1 1 1 1	1
5
1 2 3 1 2	3
*/
#include <stdio.h>

int main() {
	int T,N,n;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    int count_arr[N+1];
	    for (int i=0; i<N+1; i++){
	    	count_arr[i] = 0;
	    }
	    for (int i=0; i<N; i++){
	    	scanf("%d",&n);
	        count_arr[n] += 1;
	    }
	    int unique = 0;
	    for (int i=0; i<N+1; i++){
	        if (count_arr[i] != 0)
	            unique++;
	    }
	    printf("%d\n",unique);
	}
}
