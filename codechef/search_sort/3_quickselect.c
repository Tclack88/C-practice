#include <stdio.h>
// https://www.codechef.com/practice/course/sorting/SORTING/problems/CUTOFF?tab=statement
/*after test cases, this program provides number of scores and the number of people who passed. Then it provides the scores. From this info, we must ascertain the maximum value of the passing score
with 4 1
5 1 7 4. only the score of 7 passed, which means that the passing score's boundary is greater than 6. We would return 6 in this case
example:
INPUT:				OUTPUT: 
3 <-- # test cases		0
2 2						6
5 1						30
4 1
5 1 7 4
4 3
15 70 100 31

Quickselect algorithm seems appropriate here because it will "quasi sort" the array. It won't waste time on parts of the arrays that don't need to be sorted.
*/
void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int quickselect(int* arr, int n, int di){
    int pivot = arr[n-1];
    int i=-1;
    int j=0;
    int tmp;
    while (j<n-1){
        if (arr[j] < pivot){
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        j++;
    }
    i++;
    tmp = arr[i];
    arr[i] = pivot;
    arr[n-1] = tmp;
    int diff = i - di;
    if (diff == 0)
        return di; // pivot index
    if (diff > 0) // di lies in left partition
        return quickselect(arr,i,di);
    else // di lies in right partition
        return quickselect(&arr[i+1],n-i-1, -diff-1) + i + 1;
		// -diff-1 (di-i-1) is the desired
		// index of the inner array. Ultimately
		// I still must return di. And this will
		// return -diff-1 (when the other condtons
		// are eventually met
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int di = n-x; // di = desired index
        int passing_index = quickselect(a,n,di);
		printf("after 'sorting':\n");
		printArr(a,n);
		printf("ANSWER: %d\n",a[passing_index]-1);
    }
    return 0;
}
