#include <stdio.h>
int main(){
	
	// Take input of 5 marks and print the percentage

	float a, b, c, d, e;
	printf("PERCENTAGE CALCULATOR\n");
	printf("Enter the marks (out of 100) when prompted and press Enter\n\n");
	printf("Enter 1st Marks: ");
	scanf("%f", &a);
	printf("Enter 2nd Marks: ");
	scanf("%f", &b);
	printf("Enter 3rd Marks: ");
	scanf("%f", &c);
	printf("Enter 4th Marks: ");
	scanf("%f", &d);
	printf("Enter 5th Marks: ");
	scanf("%f", &e);
	
	float per = (a+b+c+d+e)/5;
	
	printf("Total marks scored is: %.2f\n", a+b+c+d+e);
	printf("The Percentage Scored is: %.2f", per);
	
	return 0;
	
}
