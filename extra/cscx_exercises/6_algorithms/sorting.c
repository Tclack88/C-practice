#include <stdio.h>
#include <string.h>

void print_array(int arr[], int size){
	for (int k=0; k<size-1; k++)
		printf("%d ",arr[k]);
	printf("%d\n",arr[size-1]);
}

void selection_sort(int arr[], int size){
	int tmp;
	for (int i=0; i<size; i++){
		int smallest = i;
		for (int j=i; j<size; j++){
			if (arr[j] < arr[smallest])
				smallest = j;
		}
		tmp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = tmp;
	}
}

void insertion_sort(int arr[], int size){
	int tmp;
	for (int i=0; i<size; i++){
		for (int j=i; j>0; j--){
			if (arr[j]<arr[j-1]){
				tmp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=tmp;
			}
		}
	}
}

void slice(int arr[], int start, int end, int new_arr[]){
	int i = 0;
	for (int j=start; j<end; j++){
		new_arr[i] = arr[j];
		i++;
	}
}

void merge_sort(int arr[], int size){
    if (size == 1)
        return;
    else if (size == 2){
        if (arr[0] > arr[1]){
            int tmp = arr[0];
            arr[0] = arr[1];
            arr[1] = tmp;
        }
    }
	else{ // size > 2, split in half, call merge sort, re-merge
        int L_size = size/2;
        int R_size = size - L_size;
        int L_arr[L_size];
        int R_arr[R_size];
        slice(arr, 0, L_size,L_arr);
        slice(arr,L_size,size,R_arr);

        merge_sort(L_arr, L_size);
        merge_sort(R_arr,R_size);
        // merge back together
        int li = 0; // bottom index of left array
        int ri = 0; // bottom index of right array
        for (int i=0; i < size; i++){
            if (ri < R_size && li < L_size){
				// both li and ri in bounds
                if (L_arr[li] < R_arr[ri]){
                    arr[i] = L_arr[li];
                    li++;
                }
                else{
                    arr[i] = R_arr[ri];
                    ri++;
                }
            }
            else if (li < L_size){ // only li in bounds
                arr[i] = L_arr[li];
                li++;
            }
			else{
                arr[i] = R_arr[ri];// only ri in bounds
                ri++;
            }
        }
    }
}


int main(){
	char input[500]; // numbers range 0-1000 (incluseive), 100 max
					//if all were 1000: "1000 1000 1000.... 1000"
					// this is 5 digits*100 = 500 (including nul)
	int arr[101];
	int size;
	while (fgets(input,500,stdin) != NULL){
		int i=0;
		char* token = strtok(input, " ");
		while(token !=NULL){
			sscanf(token,"%d",&arr[i]);
			i++;
			token = strtok(NULL," ");
		}
		//arr[i] = '\0'; // null terminate
		size = i;
		//selection_sort(arr,size);
		//insertion_sort(arr,size);
		merge_sort(arr,size);
		print_array(arr, size);
	}
	return 0;
}
