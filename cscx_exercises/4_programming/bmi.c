#include <stdio.h>
#include <string.h> 

float bmi(float h, float w){
	return w/(h*h);
}

int main(){
	float h, w, BMI;
	char prog[16]; // prognosis
	while( scanf("%f %f", &h, &w)==2 ){
		BMI = bmi(h,w);	
		if (BMI < 18.5)
			// learned you can't simply set variables here like java/python
			// eg. prog = "underwight"
			// this is because prog is a pointer in memory. Setting a pointer to
			// an immutable string array doesn't make sense. Instead, we must copy
			// the string into the pointer using strcpy (or strncpy)
			strcpy(prog, "underweight");
		else if (18.5 <= BMI && BMI < 25)
			strcpy(prog, "normal weight");
		else if (25 <= BMI && BMI < 30)
			strcpy(prog,"overweight");
		else
			strcpy(prog,"obese");
		printf("%s\n", prog);
	}
}
