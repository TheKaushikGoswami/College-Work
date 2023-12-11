#include <stdio.h>
int main(){

    // C Program to to find maximum frequency element in a given sequence(array).

    int arr[100], n, c;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value of element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = 0, el = 0;

    for (int i = 0; i < n; i++) {
        c = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                c++;
            }
        }
        if (c > max) {
            max = c;
            el = arr[i];
        }
    }

    printf("The maximum frequency element is %d", el);

    return 0;
}