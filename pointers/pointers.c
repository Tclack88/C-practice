#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
	while (*y != '\0'){
		*x = *y;
		//printf("%c %c\n", *x, *y);
		x++;
		y++;
	}	

}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
	//printf("%c, %c\n", *str, c);
	while (*str != c){
		//printf("%c\n",*str);
		str++;
	}	
	return str;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
	while (*needle != *haystack){
		printf("outer: %c, %c\n", *haystack, *needle);	
		*haystack++;
		if (*needle == *haystack){
			for (int j=0; j<strlen(needle); j++){
				printf("inner: %s, %s\n", haystack, needle);	
				printf("%d\n",j):
				if (needle[j] != haystack[j]){
					haystack++;
				}
				if (j+1 == strlen(needle)){
					printf("%s", "yo!\n");
					return haystack;
				}
			}
		}
	}

	printf("match: %c, %c\n", *haystack, *needle);	
	printf("%s - %s", needle, haystack);
	printf("needle: \"%s\", haystack: \"%s\" (needle len %d)\n", needle, haystack, strlen(needle));
	return "failed to end";
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("helloworld", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
