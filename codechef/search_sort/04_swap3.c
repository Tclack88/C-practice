// https://www.codechef.com/learn/course/searching-sorting/SORTSEARCH3/problems/SESO12?tab=statement
/* 
INPUT		OUTPUT
5 2 7		2 5 7
*/
#include <stdio.h>

int main() {
	int x,y,z,tmp;
	
	scanf("%d %d %d",&x,&y,&z);
	
	if (x>y){
        tmp = x;
        x = y;
        y = tmp;
    }
	if (x>z){
        tmp = x;
        x = z;
        z = tmp;
    }
    if (y>z){
        tmp = y;
        y = z;
        z = tmp;
    }
	printf("%d %d %d",x,y,z);
	return 0;
}
