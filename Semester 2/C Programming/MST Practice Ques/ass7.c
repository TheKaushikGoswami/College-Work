//Find the sum of n numbers using recursive function.

#include<stdio.h>

int sum(int n){
	if(n > 0){
		return n + sum(n - 1);
	}
}

int main(){
	int n;
	printf("How many numbers?");
	scanf("%d", &n);
	int c = sum(n);
	printf("%d", c);
	
	return 0;
}
