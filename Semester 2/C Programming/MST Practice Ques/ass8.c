// Find the factorial of given function using recursive function. 

#include<stdio.h>

int fact(int n){
	if(n > 0){
		return n*fact(n-1);
	}
	return 1;
}

int main(){
	int n;
	printf("How many numbers?");
	scanf("%d", &n);
	
	int factorial = fact(n);
	printf("%d", factorial);
	
	return 0;
}
