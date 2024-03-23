#include <stdio.h>
int main(){

    // C Program to take a string input from user and check if it is a palindrome

    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0;
    while(str[i] != '\0'){
        i++;
    }

    i--;

    int j = 0;

    while(i >= 0){
        if(str[i] != str[j]){
            printf("The string is not a palindrome\n");
            break;
        }
        else{
            printf("The string is a palindrome\n");
            break;
        }
        i--;
        j++;
    }

    return 0;
    

}