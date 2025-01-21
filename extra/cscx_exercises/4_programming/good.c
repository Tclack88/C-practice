#include <stdio.h>

int main(){
	int h;
	while( scanf("%d",&h)==1 ){
		if (h>=4 && h <= 11)
			printf("Good morning\n");
		else if (12 <= h && h <= 17)
			printf("Good afternoon\n");
		else if (18 <= h && h <= 23)
			printf("Good evening\n");
		else
			printf("Hi\n");
	}
	// learned I can't use switch case like this:
	//	switch (1){
	//		case (4 <= h && h<=11):
	//			printf("Good morning\n");
	//			break;
	//		case (12 <= h && h <=16):
	//			printf("Good afternoon\n");
	//			break;
	//		case (18 <=h && h <= 23):
	//			printf("Good evening\n");
	//			break;
	//		default:
	//			printf("Hi\n");
	//			break;
	//	}
	// if could be done like this:
	// switch (h) {
    // 		case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
    //	    printf("Good morning\n");
    //  	 break;
	//  ... and so on, but that's not convenient or clean
	return 0;
}
