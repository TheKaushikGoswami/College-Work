#include <stdio.h>

int main() {

    // Program for finding the sum of all the numbers between two numbers which are divisible by 3

    int n1, n2, sum = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);
    if (n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    int i = n1;
    while (i <= n2) {
        if (i % 3 == 0) {
            sum += i;
        }
        i++;
    }

    printf("%d", sum);
    return 0;
}
