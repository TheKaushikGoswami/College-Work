#include <stdio.h>
int main(){

    // Input age and Salary from user and calculate the bonus, the conditions are – 
    // Salary>=15000 bonus is 5% of salary 
    // Salary<15000 but age>=32 bonus is 3% of salary 
    // Salary<15000 and age<32 bonus is 2% of salary

    int age;
    float salary, bonus;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your salary: ");
    scanf("%f", &salary);

    if(salary >= 15000){
        bonus = salary * 0.05;
    }else if(salary < 15000 && age >= 32){
        bonus = salary * 0.03;
    }else if(salary < 15000 && age < 32){
        bonus = salary * 0.02;
    }

    printf("Your bonus is %.2f", bonus);

    return 0;
}