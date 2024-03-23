#include <stdio.h>
int main()
{

    // C Program to take an arrray from user and count number of even elements

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of element number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            c++;
        }
    }

    printf("The number of even elements is: %d", c);

    return 0;
}