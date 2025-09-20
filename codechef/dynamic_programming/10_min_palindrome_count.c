//https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO15001?tab=Submissions
/* finding the SHORTEST total count of palindromic integer subarrays that any given array can be made from. Strategy: brute force. Make a "best" array where each index represents the shortest count of palindromic integer subarrays. Each check starts from an index of the array. If the array happens to be a palindrome starting from 0, then clearly, it will be filled as a 1. Otherwise, if palindrome is found starting from some non-zero index i, add 1 plus the best value currently stored at best[i-1]. Do not stop once one is found, keep going until i reaches the index you're checking too, as there could be other, more optimal choces. 
INPUT:			OUTPUT:
5
34 45 34 56 34		3
7
1 2 1 3 3 1 2		2
7
2 1 3 3 1 2 1		2
*/
#include <stdio.h>

int min(int a, int b){
	if (a < b)
		return a;
	return b;
}

int is_palindrome(int arr[], int size){
    for(int i=0; i<size/2; i++){
        if (arr[i] != arr[size-1-i])
            return 0;
    }
    return 1;
}

int shortest_palindrome(int best[], int arr[], int size){
	int index = 0;
	int palindrome = is_palindrome(&arr[index], size-index);
	int shortest = 100; // arbitrary number larger than 1
	while (index < size){
		while (!palindrome){
			index++;
			palindrome = is_palindrome(&arr[index], size-index);
		}
		if (index == 0)
			return 1;
		if (1+best[index-1] < shortest)
			shortest = min(shortest,1 + best[index-1]);
		index++;
		palindrome = is_palindrome(&arr[index], size-index); // IMPORTANT to check here otherwise the inner while loop will break
	}
	return shortest;
}

int main() {
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0; i<N; i++)
        scanf("%d",&arr[i]);
    int best[N];
    for (int i=0; i<N; i++)
		best[i] = shortest_palindrome(best, arr, i+1);
	printf("%d\n",best[N-1]);
    return 0;
}
