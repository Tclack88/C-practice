//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004
/* story: We have a list of jobs or something and the prices. You can't take 3 (or more) in a row. What is the maximum value that can be obtained?
Strategy: My first intuition was almost correct. Build a "fee" array, then to build a "best" array where this represents the best possible choice up to and including that index. best[0] will be fee[0] obviously, because it's the only choice. and best[1] will be fee[0]+fee[1] because there's no sense in not choosing (I'm assuming we only have positive vals). Then fee[2] would be the best of either fee[0]+fee[2] or fee[1]+fee[2]. This sets up everything I need to build everything else. From here on, any best[i] I believe should be the maximum of the choice between fee[i]+fee[i-1] + best[i-3] or fee[i] + best[i-2]. The reason is because we can't have 3 or more in a row, so I would either be including the current fee (fee[i])) with the best[i-2] (cannot use best[i-1] because that could potentially be formed from the sum of the previous two and this would make three in a row, or it would be the current and previous fee (fee[i]+fee[i-1]) and then I would definitely have to skip best[i-2] because it  would be included and thus make 3 in a row. HOWEVER. I must also include the case where fee[i] is skipped entirely. It might seem against intuition at first because surely including the current is always higher than not including it. However if you consider the case where fee[i] is relatively low and the next two are much higher, it might be worth skipping two in a row (with the 2nd being fee[i]) in order to include both of the next two. I'm struggling to find or create an example, but sometimes the greedy algorithm isn't always the best.
INPUT:			OUTPUT:
5
10 3 5 7 3			23
----------------------
8
3 2 3 2 3 5 1 3		17
*/
#include <stdio.h>

void printArr(int arr[], int len){
	for (int i=0; i<len; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int main() {
	int N;
	scanf("%d",&N);
    int fee[N];
    for (int i=0; i<N; i++){
        scanf("%d",&fee[i]);
    }
    int best[N];
    best[0] = fee[0];
    best[1] = fee[0]+fee[1];
    best[2] = max(fee[0]+fee[2], fee[1]+fee[2]);
    for (int i=3; i<N; i++)
        best[i] = max(max(fee[i]+fee[i-1] + best[i-3],fee[i] + best[i-2]),best[i-1]);
	printArr(best,N);
    printf("%d\n",max(max(best[N-1],best[N-2]),best[N-3]));
}
