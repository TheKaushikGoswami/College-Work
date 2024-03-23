#include <stdio.h>
int main(){

    // C Program to take a string input from user and copy it in another string

    char str[100], str2[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    int i = 0;
    while(str[i] != '\0'){
        str2[i] = str[i];
        i++;
    }

    str2[i] = '\0';

    printf("The copied string is: %s\n", str2);
    return 0;

}