#include <stdio.h>
int main(){

    // C Program to find the largest and second largest element in an array.

    int arr[100], n, c;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value of element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = 0, max2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max2 = max;
            max = arr[i];
        }else if (arr[i] > max2 && arr[i] != max) {
            max2 = arr[i];
        }
    }

    printf("The largest element is %d and the second largest element is %d", max, max2);

    return 0;
}