#include <stdio.h>
int main(){

    // C Program to find a binary equivalent of a number. 

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int arr[100];
    int i = 0;

    while(n > 0){
        arr[i] = n % 2;
        n /= 2;
        i++;
    }

    printf("The binary equivalent of the number is: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", arr[j]);
    }

    return 0;
}