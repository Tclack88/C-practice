//https://www.codechef.com/learn/course/number-theory/LINTDSA04/problems/CUTRECIPE
/*
The story is of a chef making dishes from recipes. Each line has the format N n1 n2 n3... where N is the number of ingredients and each n# following is the amount of that ingredient needed. We are to determine the quantity of each ingredient needed to make the least amount of food as possible (eg. with the first test case, (4 4) we know we need equal amounts of each quantity, so we just need 1 of each. 
STRATEGY: We need to find the GCD of all the ingredients. Then divide each value by the GCD to find a reduced (yet still integer amount) of each ingredient necessary.
INPUT:			OUTPUT:
3
2 4 4			1 1
3 2 3 4			2 3 4
4 3 15 9 6		1 5 3 2
*/
#include <stdio.h>

int gcd(int a, int b){
    int M = a;
    int m = b;
    if (b > a){
        M = b;
        m = a;
    }
    int R = 1;
    while (R){
        R = M%m;
        M = m;
        m = R;
    }
    return M;
}

int main() {
	int T, N, a, b;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
        int arr[N];
        for (int i=0; i<N; i++)
            scanf("%d",&arr[i]);
        int GCD = gcd(arr[0],arr[0]);
        for (int i=0; i<N-1; i++)
            GCD = gcd(GCD,arr[i+1]);
        for (int i=0; i<N; i++)
            printf("%d ",arr[i]/GCD);
        printf("\n");
	}
	return 0;
}


