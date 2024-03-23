#include <stdio.h>
int main(){

    // C Program to take a string input from user and count the number of words in it

    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0, c = 0;
    while(str[i] != '\0'){
        if(str[i] == ' '){
            c++;
        }
        i++;
    }

    printf("Number of words in the string: %d\n", c+1);
    return 0;
    
}