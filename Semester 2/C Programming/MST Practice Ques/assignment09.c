
#include<stdio.h>

// Find the nth term of Fibonacci series using recursive function. 

int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else{
		return fibonacci(n-1) + fibonacci(n-2);
	}
}

int main(){
	int n;
	printf("Enter the term for which you want to get the value: ");
	scanf("%d", &n);
	int fib = fibonacci(n);
	printf("%d", fib);
	
	return 0;
	
}
