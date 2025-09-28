// https://www.codechef.com/learn/course/combinatorics/COMBI01/problems/COMB09?tab=solution
/* Given a list of integers which represent the amount of some type of fruits, determine how many different fruit bowls can be made. An empty bowl is also allowed. For example with 1 2, maybe this represents one apple, two oranges. You can have: empty bowl, one apple, one orange, one apple and one orange, one apple and two oranges, or just two oranges. So we would return 6.
Strategy: Given that you can choose 0 of each item, you techinically have one more choice than the number given, so all we need to do is add 1 to the value and then multiply them all together, so the 1 2 example would really be 2 3 which means 2*3 = 6 is our total combinations
INPUT:		OUTPUT:
3
4 
2 1 3 5		144
1
1			2
2
1 2			6
*/
#include <stdio.h>

int main() {
	int T, N, val;
	scanf("%d",&T);
	while (T--){
	    scanf("%d",&N);
	    unsigned long long total = 1;
	    for (int i=0; i<N; i++){
	        scanf("%d",&val);
	        total *= val+1;
	        total = total % 1000000007;
	    }
	    printf("%llu\n",total);
	}
    return 0;
}
