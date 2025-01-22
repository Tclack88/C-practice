#include <stdio.h>
#include <string.h>
#include <math.h>

long hex2dec(char hex[], int len){
	long dec=0;
	int val;
	char chr;
	for (int i=0; i<len; i++){
		chr = hex[i];
		if (chr >= 'a' && chr <= 'f')
			val = 10 + (chr -'a');
		else
			val = chr - '0';//sscanf(&chr,"%d",&val);	
		//switch (chr){
		//	case 'a':
		//		val = 10;
		//		break;
		//	case 'b':
		//		val = 11;
		//		break;
		//	case 'c':
		//		val = 12;
		//		break;
		//	case 'd':
		//		val = 13;
		//		break;
		//	case 'e':
		//		val = 14;
		//		break;
		//	case 'f':
		//		val = 15;
		//		break;
		//	default:
		//		sscanf(&chr,"%d", &val);		
		//		break;
		//}
		dec += val*pow(16,len-i-1);
	}
	return dec;
}

int main(){
	char hex[10];
	while( scanf("%s",hex)==1 ){
		printf("%ld\n",hex2dec(hex,strlen(hex)));
	}
	return 0;
}
