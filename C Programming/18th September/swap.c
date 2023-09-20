#include <stdio.h>
int main(){
	
	int a, b;
	printf("Enter the first integer: ");
	scanf("%d", &a);
	printf("Enter the second integer: ");
	scanf("%d", &b);
	      
	printf("Before swap a=%d b=%d",a,b);      
	a=a+b;
	b=a-b;
	a=a-b;
	printf("\nAfter swap a=%d b=%d",a,b);    
	
	/*
	printf("\nBefore swapping\nthe value of 'a' is %d\nand the value of 'b' is %d", a, b);
	int c = b;
	b = a;
	a = c;
	
	printf("\nAfter swapping\nthe value of 'a' is %d\nand the value of 'b' is %d", a, b);
	*/
	
	return 0;
}
