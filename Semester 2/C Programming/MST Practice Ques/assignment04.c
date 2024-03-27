#include<stdio.h>

// Write a program in C to count the number of vowels and consonants in a string using a pointer.
void countVowelsConsonants(char *str, int *vowelCount, int *consonantCount ){
	while(*str!='\0'){
		if(((*str)>='a' && (*str)<='z') || ((*str)>='A' && (*str)<='Z')){
			if((*str) == 'a' || (*str) == 'e' || (*str) == 'i' || (*str) == 'o' || (*str) == 'u' || (*str) == 'A' || (*str) == 'E' || (*str) == 'I' || (*str) == 'O' || (*str) == 'U'){
				(*vowelCount)++;
			}
			else{
				(*consonantCount)++;
			}
		}
		str++;
	}
}
int main(){
	char str[100];
	int vowelCount=0, consonantCount=0;
	printf("Enter a string:");
	scanf("%[^\n]", str);
    countVowelsConsonants(str, &vowelCount, &consonantCount);
    
    printf("No. of Vowels = %d\n", vowelCount);
    printf("No. of Consonants = %d\n", consonantCount);
    
    return 0;
}
