#include <stdio.h>
int main(){

    // C Program to calculate and print the division of a student by taking marks of his 5 subjects.

    int a, b, c, d, e;
    float avg;
    printf("Enter the marks of 5 subjects (separated by space): ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    avg = (a + b + c + d + e) / 5.0;

    printf("The average marks of the student is: %.2f\n", avg);

    if (avg >= 90){
        printf("The student got A grade.\n");
    }
    else if (avg >= 80){
        printf("The student got B grade.\n");
    }
    else if (avg >= 70){
        printf("The student got C grade.\n");
    }
    else if (avg >= 60){
        printf("The student got D grade.\n");
    }
    else if (avg >= 40){
        printf("The student got E grade.\n");
    }
    else{
        printf("The student got F grade.\n");
    }

    return 0;
}