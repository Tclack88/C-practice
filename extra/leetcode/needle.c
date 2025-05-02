#include <stdio.h>

/*int strStr(char* haystack, char* needle) {
	int i=0;
    int ret = -1;
    while (haystack[i] != '\0'){
		if (haystack[i] == needle[0]){
			ret = i;
			int j = 0;
			while (needle[j] != '\0'){
				if (needle[j] != haystack[i+j]){
					ret = -1;
					break;
				}
				j++;
        	}
			if (ret != -1)
				return ret;
    	}
		i++;
	}
    return ret;
}*/

int strStr(char* haystack, char* needle) {
	printf("%d\n",haystack.size());
	printf("%d\n",haystack.size());
}


int main(){
	//char haystack[20] = "sadbutsad";
	//char needle[20] = "sad";
	//char haystack[20] = "leetcode";
	//char needle[20] = "leeto";
	char haystack[20] = "hello";
	char needle[20] = "ll";
	int i = strStr(haystack, needle);
	printf("Found at: %d\n",i);
	return 0;
}
