#include <stdio.h>

int main(){
	int n;
	int list[101];
	while(scanf("%d",&n) == 1){
		for(int i=0; i < n; i++){
			scanf("%d", &list[i]);
		}
		printf("%d elements: ",n);
		for(int i=0; i < n; i++){
			printf("%d", list[i]);
			if (i != n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
		
