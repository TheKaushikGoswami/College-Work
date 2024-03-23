#include <stdio.h>

// C Program to take a string from user and count number of vowels in it

int main(){

    char ch[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", ch);

    int c = 0;

    for(int i = 0; i<100; i++){
        if ((ch[i] == 'a') || (ch[i] == 'e') || (ch[i] == 'i') || (ch[i] == 'o') || (ch[i] == 'u') || (ch[i] == 'A') || (ch[i] == 'E') || (ch[i] == 'I') || (ch[i] == 'O') || (ch[i] == 'U')){
            c++;
        }
    }

    printf("The number of vowels in the string is: %d", c);

    return 0;
}