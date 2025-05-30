#include <stdio.h>
/* Sorting - quick sort
INPUT:			OUTPUT:
5   (<--- num of numbers about to be counted in)
5				1
3				3
6				5
7				6
1				7
NOTE: the actual submission did not accept my quicksort,
though it passes all my local tests, I was getting a time limit exceeded
so I passed in a previously written merge-sort
*/

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
	printf("\n");
}

void quicksort(int arr[], int size){
    int pivot = arr[size-1];
    int tmp, i, j;
    if (size <= 1)
        return;
    else{
        i = -1;
        j = 0;
        while (j < size-1){
            if (arr[j] < pivot){
                i++;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
			j++;
        }
        i++;
        tmp = arr[i];   // swap pivot to  i+1 location
        arr[i] = pivot;
        arr[size-1] = tmp;
    }
    quicksort(&arr[0],i);
    quicksort(&arr[i+1],size-i-1);
	return;
}

int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i=0; i<n; i++){
	    scanf("%d", &arr[i]);
	}
	//quicksort(arr,n);
	selection_sort(arr,n);
	printArr(arr,n);
    return 0;
}
