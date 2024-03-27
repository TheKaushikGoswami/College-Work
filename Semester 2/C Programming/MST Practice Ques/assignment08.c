#include<stdio.h>

// Find the factorial of given integer using recursive function. 

int fact(int n){
	if (n == 0){
		return 1;
	}
	else{
		return n * fact(n-1);
	}
}

int main(){
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	
	int factorial = fact(n);
	printf("%d", factorial);
	
	return 0;
}
