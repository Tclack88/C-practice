// Weighted Interval Scheduling Algorithm. Solution strategy described here:
// https://www.youtube.com/watch?v=iIX1YvbLbvc
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

void print_task(struct Task* task,int i){
	printf("task %d:\t%d %d %d\n", i+1, task->s, task->e, task->c);
}

void print_tasklist(struct Task* tasklist[], int size){
    for (int i=0; i<size; i++){
		struct Task* task = tasklist[i];
		print_task(task,i);
    }
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
		struct Task* tasklist[size];
	    for (int i=0; i<size; i++){
	        scanf("%d %d %d", &s, &e, &c);
            struct Task* task = create_task(s, e, c);
            tasklist[i] = task;
	    }
	    //print_tasklist(tasklist, size);
	    //printf("\nsorted:\n");
		qsort(tasklist, size, sizeof(struct Task*), comp);
	    //print_tasklist(tasklist, size);
	    //printf("\n");
		int sched[50] = {0};
		//memset(sched,0,size*sizeof(int));
		for(int i=0; i<size; i++){
			struct Task* task = tasklist[i];
			//print_task(task,i);
			int start = task->s;
			int end = task->e;
			sched[end] = max(sched[end],sched[start]+task->c);
			best = max(best, sched[end]);
		}
		//for (int i=0; i<49; i++)
		//	printf("%d, ",sched[i]);
		printf("%d\n",best);
	}
    return 0;
}
