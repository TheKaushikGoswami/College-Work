#include <stdio.h>
int main(){

    // C Program to take a string from user and then count the number of vowels in that string

    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int count = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
           str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' ||
           str[i] == 'u' || str[i] == 'U'){
            count++;
        }
    }

    printf("The number of vowels in the string is %d\n", count);

    return 0;

}