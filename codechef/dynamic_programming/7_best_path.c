// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/MGCRNK
/* Grid traversal. Story aside, in this we are starting in an upper left corner of a square grid and travelling to the bottom right of a square grid. The start/finish are empty (0 points) and all the other ones have points associated with them. Only travelling down or right, find the maximum average points awarded. 
Strategy: This is tantamount to finding the max score then dividign by 2*N - 3 (visualize it, it should be obvious why). So how to find the maximum? Visualizing a smaller 2x2 square, there are only two ways to get from top left to bottom right. I read in the path (scores on each square) then make a "best" matrix to fill in the best path where each value will represent the highest score achievable along either of the two paths. If the traveller only moves along the top or the bottom, these values would simply sum up, so I prefill those values with the sum of the values in the path squares and then simply fill in each smaller [i][j] square by adding [i-1][j-1] and either the one above it or to the left, whichever is greatest. print the average value if >= 0, otherwise print "Bad judges"

INPUT:				OUTPUT:
6
2
0 -4
8 0					8.000000
2
0 -45
-3  0				Bad judges
2
0 1213
-1432 0				1213.000000
2
0 2160
828 0				2160.000000
3
0 -19 -94
676 -2274 -652
-580 1019 0			371.666667
4
0 1553 2164 1774
-1772 715 -2500 1378
2322 1669 -738 1881
1461 570 -967 0		1750.000000
*/
#include <stdio.h>

int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

/*void print2dArr(int N, int arr[N][N]){
    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++)
	            printf("%d ",arr[i][j]);
	        printf("\n");
    }
}
*/

int main() {
	int T,N,val;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    int path[N][N];
		int best[N][N];
	    for(int i=0; i<N; i++){
	        for(int j=0; j<N; j++){
				scanf("%d",&val);	
	            path[i][j] = val;;
				best[i][j] =0;
			}
		}
		for (int i=1; i<N; i++)
			best[i][0] = path[i][0] + best[i-1][0];
		for (int j=1; j<N; j++)
			best[0][j] = path[0][j] + best[0][j-1];
		for(int i=1; i<N; i++){
			for (int j=1; j<N; j++){
				best[i][j] = path[i][j] + max(best[i-1][j], best[i][j-1]);
			}
	    }
		/* 	matrices for double checking:
		print2dArr(N, path);
		printf("---------\n");
	    print2dArr(N, best);
		*/
		double res = (double)(best[N-1][N-1])/(2*N-3);
		if (res < 0)
			printf("Bad Judges\n");
		else
			printf("%f\n",res);
	}
    return 0;
}
