#include <stdio.h>
#include <string.h>

int main(){

    // gets() is a function in C which is used to take a string from the user

    char str[100], str2[100] = "Hello";
    printf("Enter a string: ");
    gets(str); // taking single line input from the user
    puts(str); // printing the string

    // char str1[100], str2[100];
    // printf("Enter 2 strings: ");
    // gets(str1);
    // gets(str2);
    // puts(str1);
    // puts(str2);

    int len = strlen(str); // strlen() is a function in C which is used to find the length of a string
    printf("The length of the string is %d\n", len);

    strcpy(str2, str); // strcpy() is a function in C which is used to copy a string from one variable to another: strcpy(destination, source)
    puts(str2);

    strrev(str); // strrev() is a function in C which is used to reverse a string
    puts(str);

    strcat(str, str2); // strcat() is a function in C which is used to concatenate two strings: strcat(string1, string2)
    puts(str);
    puts(str2);

    if(strcmp(str, str2) == 0){ // strcmp() is a function in C which is used to compare two strings: strcmp(string1, string2)
        printf("The strings are equal\n");
    }
    else if(strcmp(str, str2) > 0){
        printf("The first string's ASCII value is greater than the second string\n");
    }
    else{
        printf("The strings are not equal\n");
    }

    return 0;
}