#include <stdio.h>

// Write a program in C to find the greater number between two numbers using a pointer.

int findGreater(int *num1, int *num2){
	if(*num1 > *num2){
		return *num1;
	}
	else
		return *num2;
}

int main(){
	int num1, num2;
	printf("Enter any two numbers:");
	scanf("%d %d", &num1, &num2);

	if(num1 == num2){
		printf("Both are equal.");
	}
	else{
		int result = findGreater(&num1, &num2);
		printf("Greater number is: %d", result);
	}

	return 0;
}
