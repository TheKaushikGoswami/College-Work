#include <stdio.h>
int main(){

    // C Program to take a string input from user and store it's reverse in another string

    char str[100], str2[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0, j = 0;
    while(str[i] != '\0'){
        i++;
    }

    i--;
    
    while(i >= 0){
        str2[j] = str[i];
        i--;
        j++;
    }

    str2[j] = '\0';

    printf("The reversed string is: %s\n", str2);
    return 0;

}