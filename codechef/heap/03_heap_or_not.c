// https://www.codechef.com/learn/course/heaps/LIHP01/problems/HEAP07
/*  This code will read in the index of an already settled supposed min heap. If it's proper, it will print "Yes", otherwise "No"

Strategy: Recursively check each node and its children (ignoring out of index). Only returns 0 if a problem occurs.
INPUT:						OUTPUT:
2
7
10 15 30 40 50 100 40		"Yes"
3
15 10 18					"No"
*/
#include <stdio.h>

int check_children(int arr[], int index, int size){
    int c1 = 2*index+1;
    int c2 = 2*index+2;
    int isHeap = 1;
    if (c1 < size){
        if (arr[c1] < arr[index])
            return 0;
		else{
			isHeap = check_children(arr,c1,size);
    		if (!isHeap)
        		return 0;
		}
    }
    if (c2 < size){
        if (arr[c2] < arr[index])
            return 0;
		else
			isHeap = check_children(arr,c2,size);
    }
	return isHeap;
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        int isHeap = 1;
        for (int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        //Write you code to check if the arr represents a heap
        isHeap = check_children(arr, 0, n);
		printf("%s\n", isHeap ? "Yes" : "No");
    }
	return 0;
}
