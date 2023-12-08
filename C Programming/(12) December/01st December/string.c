#include <stdio.h>
int main(){

    // All different methods of taking a string input in C

    // Method 1: Using %s in scanf
    char str1[100];
    printf("Enter a string: ");
    scanf("%s", &str1);
    printf("The string is: %s\n", str1); // This method will only take the first word of the string

    // Method 2: Using %s %s in scanf
    char str4[100], str5[100];
    printf("Enter a string: ");
    scanf("%s %s", str4, str5);
    printf("The string is: %s %s\n", str4, str5); // This method will take the first 2 words from the string

    // Method 3: Using %c in scanf
    char str2[100];
    printf("Enter a string: ");
    scanf("%c", str2);
    printf("The string is: %s\n", str2); // This method will only take the first character of the string

    // Method 4: Using %[^] in scanf
    char str3[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str3);
    printf("The string is: %s\n", str3); // This method will take the whole string

    // Method 5: %s\n in scanf
    char str6[100];
    printf("Enter a string: ");
    scanf("%s\n", str6);
    printf("The string is: %s\n", str6); // This method will take one word and wait for the user to press enter and then print the 1st word

    // Method 6: %[^#] in scanf
    char str7[100];
    printf("Enter a string: ");
    scanf("%[^#]s", str7);
    printf("The string is: %s\n", str7); // This method will take the whole string until it encounters a #

    return 0;
}