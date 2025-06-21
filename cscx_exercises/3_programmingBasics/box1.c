#include <stdio.h>

int volume(int w, int h, int d){
	return w * h * d;
}

int area(int w, int h, int d){
	return 2*(w*h + w*d + h*d);
}

int main(){
	int w;
	int h;
	int d;
	scanf("%d %d %d", &w, &h, &d);
	printf("The volume of a %d by %d by %d box is %d.\n", w, h, d, volume(w,h,d));  
	printf("The surface area of a %d by %d by %d box is %d.\n", w, h, d, area(w,h,d));  
	return 0;
}
