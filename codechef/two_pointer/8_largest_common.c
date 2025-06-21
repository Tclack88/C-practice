// https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/DSAPROB20?tab=statement
/*
given two arrays, determine the largest common value
Strategy: sort (using stdlib qsort)
		 set pointer at top and decrement  the larger of the two (unless they're equal in which case return that)

NOTE: main boiler plate code provided. I did not author
INPUT:			OUTPUT:
5 6
1 3 4 6 7		7
2 3 5 6 7 8
-----------------------
4 3
1 2 3 4			-1
5 6 7
*/

#include <stdio.h>
#include <stdlib.h>

int n,m;

int comp(const void* a, const void*b){
    return *((int*) a) - *((int*) b);
}

int largestCommonElement(int* arr1, int* arr2) {
    qsort(arr1,n,sizeof(int),comp);
    qsort(arr2,m,sizeof(int),comp);
    m--;
    n--;
    int ret = -1;
    while(n > 0 && m > 0){
        if (arr1[n] > arr2[m])
            n--;
        else if (arr2[m] > arr1[n])
            m--;
        else{
            ret = arr1[n];
            break;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; ++i) scanf("%d", &arr1[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &arr2[i]);
    printf("%d", largestCommonElement(arr1, arr2));
    free(arr1);
    free(arr2);
    return 0;
}
