// https://www.codechef.com/learn/course/greedy-algorithms/LIGRDSA01/problems/XYSTRP
/*
simply greedy algorithm finding xy pairs

INPUT:		OUTPUT:
3				1
xy				2
xyxxy			0
yy
*/
#include <stdio.h>

int main() {
	int T;
	char chr;
	int x,y,pairs;
	scanf("%d\n",&T);
	while(T--){
	    pairs=0, x=0, y=0;
	    chr = getchar();	 // needed this in the online test
	    while (chr != '\n'){ // while (chr == 'x' || chr == 'y'){
	        if (chr == 'x')
	            x = x|1;
	        else //chr == 'y'
	            y = y|1;
	        if (x&y){
	            pairs++;
	            x=0,y=0;
	        }
	        chr = getchar();
	    }
	    printf("%d\n",pairs);
	    pairs = 0;
	}
}
