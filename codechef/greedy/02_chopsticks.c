// https://www.codechef.com/learn/course/greedy-algorithms/LIGRDSA02/problems/TACHSTCKP
/* chopstick problem. Given a number of chopsticks N and a min length difference D, determine number of chopstick pairs which can be made (it's okay of the chopstick lengths differ by a little (diff <= D). But greater than that, then it cannot be paired
INPUT:			OUTPUT:
5 2				2	
1 3 3 9 4

strategy: sort and check in order for adjacent pairs, if Li cannot pair with L(i+1), then it cannot be part of any pair, since it's been sorted

I will use built in sorting algorithm as sorting isn't the purpose. Also I haven't really used qsort all that much, it's not as self-working as it seems
*/
#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main() {
	int N,D;
	scanf("%d %d",&N,&D);
	int L[N];
	for (int i=0; i<N; i++)
	    scanf("%d",&L[i]);
	qsort(L,N,sizeof(int),comp);

	int count=0;
	int res = L[0];
	for (int i=1; i<N; i++){
	    if (L[i] - res <= D){
	        count++;
	        i++;
	    }
	    res = L[i];
	}
	printf("%d\n", count);
}


