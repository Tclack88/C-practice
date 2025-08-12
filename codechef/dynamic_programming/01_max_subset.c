#include <stdio.h>

int main() {
	int T, N, n;
	scanf("%d",&T);
	while (T--){
	    scanf("%d", &N);
	    int sum = 0;
	    for (int i=0; i<N; i++){
	        scanf("%d",&n);
	        if (n > 0)
	            sum += n;
	    }
	    printf("%d\n",sum);
	}
    return 0;
}
