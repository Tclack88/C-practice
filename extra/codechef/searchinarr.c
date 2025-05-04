// https://www.codechef.com/practice/course/arrays/ARRAYS/problems/SEARCHINARR
#include <stdio.h>

int main() {
	int n,x,num;
	scanf("%d %d",&n,&x);
	for(int i=0; i<n;i++){
	    scanf("%d",&num);
	    if (num==x){
	        printf("YES\n");
	        return 0;
	    }
	}
	printf("NO\n");
	return 0;

}


