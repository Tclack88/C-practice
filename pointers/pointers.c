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

	for (int i=0; i<strlen(haystack); i++){
		printf("%ld\n",strlen(needle));
		//char buffer[1024];
		char substring[8];
		for (int j=0; j<strlen(needle); j++){
			substring[j] = haystack[j];
		}
		printf("Current substring: '%s', needle: '%s'\n", substring, needle);
		printf("substring = needle?%d\n", strcmp(substring,needle) != 0);
		if (strcmp(substring, needle) == 0){
			printf("%s\n", "found!");
			return haystack;
		}
		haystack++;
		/*for (int j=0; j<strlen(needle); j++){
			buffer[j] = substring;
		}	
		printf("buffer: %s, needle: %s\n",buffer, needle);
		*/
	}
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    //char *found_string = find_string("helloworld", "or");
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
