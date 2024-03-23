#include<stdio.h>
#include<ctype.h>
void countVowelsConsonants(char *str, int *vowelCount, int *consonantCount ){
	while(*str!='\0'){
		char ch = tolower(*str);
		if(ch>='a' && ch<='z'){
			if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
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
