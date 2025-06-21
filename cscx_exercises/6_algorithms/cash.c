#include <stdio.h>

int get_bills(int m){
	int q,r;
	q = m / 100;
	r = m % 100;
	int first = 1;
	if (q != 0){
		printf("%dx100",q);
		first = 0;
	}
	if (r != 0){
		q = r / 50;
		r = r % 50;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx50",q);
			first = 0;
		}
	}
	if (r != 0){
		q = r / 20;
		r = r % 20;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx20", q);
			first = 0;
		}
	}
	if (r != 0){
		q = r / 10;
		r = r % 10;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx10", q);
			first = 0;
		}
	}
	if (r != 0){
		q = r / 5;
		r = r % 5;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx5", q);
			first = 0;
		}
	}
	if (r != 0){
		q = r / 2;
		r = r % 2;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx2", q);
			first = 0;
		}
	}
	if (r != 0){
		q = r / 1;
		r = r % 1;
		if (q != 0){
			if (!first)
				printf(" ");
			printf("%dx1", q);
			first = 0;
		}
	}
	printf("\n");
}

int main(){
	int m;
	while ( scanf("%d",&m)==1 ){
		get_bills(m);
	}
	return 0;
}
