#include <stdio.h>

int main()
{

    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    // if (year % 4 == 0)
    // {
    //     if (year % 100 == 0)
    //     {
    //         if (year % 400 == 0)
    //         {
    //             printf("Leap Year");
    //         }
    //         else
    //         {
    //             printf("Not a Leap Year");
    //         }
    //     }
    //     else
    //     {
    //         printf("Leap Year");
    //     }
    // }
    // else
    // {
    //     printf("Not a Leap Year");
    // }

    if (year%100==0){

        if (year%400==0){

            printf("Leap Year.");

        }

        else{

            printf("Not a Leap Year.");
        }
    }

    else if (year%4==0){

        printf("Leap Year.");
    }

    else{

        printf("Not a Leap Year.");
    }

    return 0;
}