#include <stdio.h>
#include <string.h>

struct student{
    char name[20];
    int roll;
    float per;
};

int main(){
    struct student s1, s2;
    printf("Enter student name: ");
    gets(s1.name);
    printf("Enter the roll number: ");
    scanf("%d", &s1.roll);
    printf("Enter the percentage: ");
    scanf("%f", &s1.per);

    printf("Enter student name: ");
    gets(s2.name);
    gets(s2.name);
    printf("Enter the roll number: ");
    scanf("%d", &s2.roll);
    printf("Enter the percentage: ");
    scanf("%f", &s2.per);

    s1.name, s2.name, s1.roll, s2.roll, s1.per, s2.per);

    return 0;

}