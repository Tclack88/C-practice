#include <stdio.h>
#include <string.h>

void dec2hex(int dec, char hex[]){
	if (dec == 0){ // handle edge case where 0 is provided
		hex[0] = '0';
		hex[1] = '\0';
		return;
	}
	char temp[9]; // builds up hex value in reverse
	int hexdigit;
	int i = 0;
	while(dec>0){
		hexdigit = dec-16*(dec/16);
		if (hexdigit < 10)
			temp[i] = '0' + hexdigit;
		else
			temp[i] = 'a' - 10 + hexdigit;
		i++;	
		dec /= 16;
	}
	int len = i;// i was counting up and so reflects the length
	for(int j = len-1; j>=0; j--){
		hex[len-j-1] = temp[j];	
	}
	hex[len] = '\0';// terminating nullbyte; avoids carryover
}

int main(){
	int dec;
	char hex[9];
	while( scanf("%d",&dec)==1 ){
		dec2hex(dec,hex);
		printf("%s\n", hex);
	}
	return 0;
}
