//https://www.codechef.com/practice/course/arrays/ARRAYS/problems/DISCOUNTT

#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x, y;
		scanf("%d %d %d", &n, &x, &y);
		int a[n];

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		// My part of code starts here
		int with = x;
		for(int i=0; i < n; i++){
			without += a[i];
			with += (a[i]-y > 0) ? a[i]-y : 0;
		}
		if (with < without)
				printf("COUPON\n");
		else
			printf("NO COUPON\n");
		// My part of code ends here
	}
	return 0;
}
