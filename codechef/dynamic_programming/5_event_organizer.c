// Weighted Interval Scheduling Algorithm. Solution strategy described here:  https://www.youtube.com/watch?v=iIX1YvbLbvc
/* Strategy: Read in start, end and compensation into a Task struct then qsort by end. Then create a "prev" array which holds the index of the previous index that ends at or before this task starts. The reason for this is we want to add any previous values that exist and end at or before the next task starts. Then we make an "opt" (for optimum) array of the same size where we hold the values for the best/optimal value up to and/or including the task we are looking at. It's calculated by adding the weight of the present tasks compensation to the prev at that the prev index or ignoring the new weight and just consider the last opt value, whichever is higher:
(opt[j] = max(w_j + opt[prev[j]], opt[j-1] )
INPUT:		OUTPUT:
2
4
1 2 100
2 3 200
3 4 1600
1 3 2100			3700
3
1 10 2000
2 5 100
6 9 400				2000
To make the above more comprehensible, here's the "prev" and "opt" for the first example (set 0 to first index of each as base case where "nothing" is included):
prev: 0   0   1   0    3
opt:  0   100 300 2100 3700
*/
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if (a > b)
		return a;
	return b;
}

struct Task{
    int s;
    int e;
    int c;
};

int comp(const void* a, const void* b){
	// works the same, but a little confusing:
	//   const struct Task* const* taskA = (const struct Task* const*)a;
	//   const struct Task* const* taskB = (const struct Task* const*)b;
	//   return (*taskA)->e - (*taskB)->e;
	// Since tasklist is an array of pointers, I need to cast a to a 
	// double pointer. compare with a "standard" example of casting to an
	// integer pointer: (int a  = *(int*)a
	const struct Task* taskA = *(const struct Task**)a;
	const struct Task* taskB = *(const struct Task**)b;
	return taskA->e - taskB->e;
}

void bin_search_prev(struct Task* tasklist[], int prev[], int size){
	for (int i=size; i > 0; i--){
		struct Task* task = tasklist[i];
		int start = task->s;
		int top = i;
		int bottom = 0;
		int best = 0;
		int mid = (top + bottom)/2;
		while( bottom <= top ){
			if (tasklist[mid]->e <= start) // drive upward if
				bottom = mid;	// multiple of target val (start)
			else if (tasklist[mid]->e > start)
				top = mid;
			best = bottom;
			mid = (top + bottom)/2;
			if (bottom == mid) // avoid infinite loops
				break;
		}
		prev[i] = best;
	}
	prev[0] = 0;
}

struct Task* create_task(int s, int e, int c){
    	struct Task* task = malloc(sizeof(struct Task));
	    task -> s = s;
	    task -> e = e;
	    task -> c = c;
	    return task;
}

int main() {
	int T, size, s, e, c;
	scanf("%d", &T);
	while (T--){
		int best = 0;
	    scanf("%d", &size);
		struct Task* tasklist[size+1];
		struct Task* task = create_task(0, 0, 0);
        tasklist[0] = task;
	    for (int i=1; i<=size; i++){
	        scanf("%d %d %d", &s, &e, &c);
            struct Task* task = create_task(s, e, c);
            tasklist[i] = task;
	    }
		qsort(tasklist, size+1, sizeof(struct Task*), comp);
		int prev[size+1]; // prev = "previous" as in the latest task that ends at or just before the current task (in task index, counting from 1) begins
		bin_search_prev(tasklist, prev, size);
		int opt[size+1]; // opt = "optimal"
		opt[0] = 0;
		for (int i=1; i<=size; i++)
			opt[i] = max(tasklist[i]->c + opt[prev[i]], opt[i-1]);
		
		printf("%d\n",opt[size]);
	}
    return 0;
}
