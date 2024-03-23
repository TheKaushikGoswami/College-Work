#include<stdio.h>
int stringLength(char *str){
	int length = 0;
	int i =0;
	while(str[i]!='\0'){
		length++;
		i++;
	}
	return length;
}
int main(){
	char str[100];
	printf("Enter a string:");
	scanf("%[^\n]", str);
	int length = stringLength(str);
	
	printf("Length of string is: %d", length);
	return 0;
}
