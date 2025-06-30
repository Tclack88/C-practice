// https://www.codechef.com/practice/course/heaps/HEAPF/problems/CLEANUP?tab=statement
/* Not related to heaps again, but fun enough
Each test case consist of two lines of two numbers:
n, m
(m numbers)
n is the numnber of tasks, m is the number of tasks already completed
the list of m numbers is the task number which has already been completed.
We are tasked to take the remaining tasks and divvy them up in order among two people, so we must output those remaining tasks
INPUT:					OUTPUT
3
6 3						3 6
2 4 1					5
3 2						1
3 2						-1
8 2						1 4 6
3 8						2 5 7
*/
#include <stdio.h>

void printArr(int arr[], int size){
    if (size == 0){
        printf("-1\n");
        return;
    }
    for (int i=0; i<size; i++)
            printf("%d ",arr[i]);
    printf("\n");
}

int get_size(int N){
    if (N % 2 ==0)
        return N/2;
    return (N/2)+1;
}

int main() {
	int T, n, m, val;
	scanf("%d",&T);
	while(T--){
	    scanf("%d %d", &n, &m);
	    int arr[n+1];
	    for(int i=0; i<n+1; i++)
	        arr[i] = i;
	    for (int i=0; i<m; i++){
	        scanf("%d",&val);
	        arr[val] = 0;
	    }
	    int size = get_size(n-m);;
	    int chef[size]; // chef's tasks
	    int assist[n-m-size]; // assistant's tasks
	    int count = 0;
        for (int i=0; i<n+1; i++){
            if (arr[i] != 0){
                if (count%2 == 0)
                    chef[count/2] = arr[i];
                else
                    assist[count/2] = arr[i];
                count++;
            }
        }
        printArr(chef,size);
        printArr(assist,n-m-size);
	}
   	return 0; 
}
