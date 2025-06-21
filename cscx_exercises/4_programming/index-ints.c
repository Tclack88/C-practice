#include <stdio.h>

int main(){
	int n, i;
	int list[101];
	while (scanf("%d",&n)==1){
		for (int j=0; j < n; j++)
			scanf("%d", &list[j]);
		scanf("%d", &i);
		printf("%d\n", list[i]);
	}
	return 0;
}
