// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PREP69?tab=statement
/* two pointers. Removing duplicates.
INPUT:				OUTPUT:
3
2					2
5 10				5 10
4					3
1 5 5 10			1 5 10
5					3
4 4 6 6 8			3

In my opinion, this is a space waste because a new array was created solely for counting. If could be reversed and the count could be displayed after the list to prevent a new array from needing to be created
*/

#include <stdio.h>

void printArr(int arr[], int size){
	for(int i=0; i<size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main() {
	int T;
	int N;
	int a,b,count;
	int arr[100001];
	int newArr[100001];
	scanf("%d",&T);
	while (T--){
		count = 0;
		scanf("%d",&N);
		//printf("%d - %d \n",T,N);
		a=b=0;
		//printf("scanning in to arr\n");
		for(int i=0; i<N;i++){
			scanf("%d",&arr[i]);
		}
		//printf("entering while\n");
		while(b<N){
			while(arr[b]==arr[a] && b<N){
				b++;
				//printf("%d,%d  ",a,b);
				//fflush(stdout);
			}
			//printf("\n%d\n",arr[a]);
			newArr[count] = arr[a];
			count++;
			a=b;
		}
		printf("%d\n", count);
		printArr(newArr,count);
	}
	return 0;
}
