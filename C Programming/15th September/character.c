#include <stdio.h>

int main(){

	// Take input of 2 characters from user and print their ASCII value

	char a, b;
	printf("Input 2 characters (separated by space): ");
	scanf("%c %c", &a, &b);
	
	printf("ASCII Value of %c is %d\nASCII Value of %c is %d", a,a,b,b);
	return 0;
}
