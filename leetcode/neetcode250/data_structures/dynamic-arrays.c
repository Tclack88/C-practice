// Notes of things learned while researching:
// Done with malloc or calloc. Resized with alloc
// malloc(total-byte-size) allocates random memory which is junk-filled
// it returns a void pointer, so you need to cast it EDIT: no need to explicitly cast
// int* ptr =  malloc(sizof(int)*10); // for 10 integer slots
// calloc(element-count,size-of-element) zero-fills that memory
// int* ptr =  malloc(10,sizeof(int)); // for 10 integer slots
// need to include stdlib to use either

#include <stdio.h>
#include <stdlib.h> // needed to use malloc,calloc,realloc, etc.
#include <string.h>

int fill_list(int* list, int list_size){
	for (int i=0; i<50; i++){
		//
	}
}

int main(){
	int list_size = 10;	
	int* list = malloc(list_size*sizeof(int));	
	for(int i=0; i<list_size; i++)
		printf("%d: %d\n",i,list[i]);
	memset(list,8,list_size*sizeof(int));
	for(int i=0; i<list_size; i++)
		printf("%d: %d\n",i,list[i]);
	return 0;
}
