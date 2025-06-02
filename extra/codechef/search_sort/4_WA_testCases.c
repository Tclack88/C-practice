//https://www.codechef.com/practice/course/sorting/SORTING/problems/WATESTCASES?tab=statement
/* In this challenge, each test case gives a list of testcase indices and then a string of 0's and 1's.
0 means not passed, 1 means passed
The goal is to find the lowest test case index of those who didn't pass (there's guaranteed to be at least one)
This is like finding the minimum element, except we ignore the cases where a 1 shows up.
As repeats were available and the number of test cases isn't large (less than 100), I decided to use a counting sort. However, the actual final sorting wasn't necessary, I just needed the index of the first non-zero element, which would represent the smallest score
INPUT:					OUTPUT:
5						3
3						5
5 10 3					5
000						5
3						10
5 10 3
001
3
5 5 3
001
3
5 5 3
101
5
10 100 100 10 10
00001
*/
#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int s[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        char v[n+1];
        scanf("%s", v);
        int counting_arr[101]; // store up to max val 100
        memset(counting_arr,0,sizeof(counting_arr)); // zero-fill array

        for (int i=0; i<n; i++){
            if (v[i] == '0')
                counting_arr[s[i]]++;
        }

        int idx = 0;
        int found = counting_arr[idx];
        while (!found){
            idx++;
            found = counting_arr[idx];
        }
        printf("%d\n",idx);
    }
    return 0;
}
