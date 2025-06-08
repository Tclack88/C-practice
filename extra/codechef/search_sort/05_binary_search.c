// https://www.codechef.com/learn/course/binary-search/LIBSDSA01/problems/DSAAGP1093
/*
NOTE: this was a very fill-in-the-blank sort of question, much of it was given, just a simple implementation of binary search. Return the index if present else return -1
INPUT:						OUTPUT:
9 7
1 3 6 7 10 13 20 25 27		3
---------------------------------
9 2							-1
1 3 6 7 10 13 20 25 27
*/
#include <stdio.h>

int binary_search(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == k) {
            return middle;
        } else if (arr[middle] > k) {
            right = middle-1;
        } else {
            left = middle+1;
        }
    }
    return -1; // k not found
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", binary_search(arr, n, k));
    return 0;
}

