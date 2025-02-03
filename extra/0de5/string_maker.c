#include <stdio.h>

void dec2bin(int i){
	int len=0;
	int copy = i;
	while(copy>0){
		copy /= 2;
		len++;
	}
	for (int b=7; b>=0; b--){
		copy = i>>b;
		printf("%d",copy&1);
	}
}

int main(){

unsigned int bytes[15];

bytes[0] = 0b01001101;
bytes[1] = 79;
bytes[2] = 0b00100000;
bytes[3] = 0b01101110;
bytes[4] = 61;
bytes[5] = 0xD6;
bytes[6] = 0b01100101;
bytes[7] = 20;
bytes[8] = 69;
bytes[9] = 73;
bytes[10] = 0b00101110;
bytes[11] = '.';
bytes[12] = 0b00101110;
bytes[13] = 0b00100000;
//bytes[14] = 0;// terminating null byte. Guess not necessary?

printf("integer\tbinary\t\toctal\thex\tASCII\n");
for (int i=0;i < (sizeof(bytes)/sizeof(int)); i++){
	printf("%4d \t",bytes[i]);
	dec2bin(bytes[i]);
	printf("\t %4o \t %2x \t %2c\n",bytes[i],bytes[i],bytes[i]);

}

return 0;
}
