#include <stdio.h>

/*void n2dec(int n, int s, char decimal[]){
	char temp[188];

}

void base2base(char n[], int s, int d, char decimal[], char output[]){
	char temp[188];
	char digit;
	int i = 0;
	while (s > 0){
		digit = 
	}
}
*/

int main(){
	int s, d; // s - source base, d - destination base
	char n[37];
	char output[188]; // worse case:
					  // if all 36 z's (in base 36) converted to binary
					  // then 187 bits are needed
	char decimal[188];// intermediate decimal string
	while( scanf("%s %d %d", n, s, d)==3 ){
		//base2base(n, s, d, decimal, output);
		//printf("%s\n",output);
		// convert to decimal
		int base = 1;
		char digit;
		len = strlen(n)
		for(int i = 1; i <= len; i++){
			digit = n[len-1];
			if (digit >= '0' && digit <='9')
				//
				
		}
	}
}
