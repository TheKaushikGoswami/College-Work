#include <stdio.h>
int main(){

    // C Program to to find maximum frequency element in a given sequence(array).

    int arr[100], n, i, j, c;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value of element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = 0;

    for (i = 0; i < n; i++) {
        c = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                c++;
            }
        }
        if (c > max) {
            max = c;
        }
    }

    if (max == 1) {
        printf("All elements have 1 frequency.");
        return 0;
    }

    printf("The element with maximum frequency is: %d", max);

    return 0;
}