//https://www.codechef.com/learn/course/binary-search/LIBSDSA01/problems/DSAAGP1094
/*
note: no main function provided. Binary search but inserting a value. Return the index where it is found, or if it's not found, return the index where it would be inserted
NOTE: I have no idea what the "1" is used for. Also I don't like the redundant setting of the middle variable. But it was necessary, otherwise tests like the first return one smaller than the element of interest because the "middle" is set at the beginning of the loop
INPUT:						OUTPUT
9 1
1 3 6 7 10 13 20 25 27		3
7
--------------------------------
9 1
1 3 6 7 10 13 20 25 27		4
9
*/
int search_insert_position(int arr[], int n, int k) {
    int left = 0;
    int right = n-1;
    int middle;
    middle = (left + right)/2;
    while (left < right){
        if (arr[middle] >= k && arr[middle-1] < k) 
            return middle;
        else if (arr[middle] < k)
            left = middle + 1;
        else
            right = middle - 1;
        middle = (left + right)/2;
    }
    return middle;
}
