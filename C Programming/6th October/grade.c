#include <stdio.h>

int main(){

    float per;

    printf("Enter the percentage: ");
    scanf("%f", &per);

    if (per >= 90){
        printf("Grade A+");
    }
    else if (per >= 80){
        printf("Grade A");
    }
    else if (per >= 70){
        printf("Grade B+");
    }
    else if (per >= 60){
        printf("Grade B");
    }
    else if (per >= 50){
        printf("Grade C");
    }
    else if (per >= 40){
        printf("Grade D");
    }
    else{
        printf("Grade F");
    }

    return 0;
}