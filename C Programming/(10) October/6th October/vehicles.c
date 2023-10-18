#include <stdio.h>

int main(){

    // A company manufactures 2 types of vehicles, 4 wheeler = fr and 3 wheeler = th. if total no. of vehicles is 137 and total no. of wheels = 512, how many three wheelers and four wheelers are there?

    int vehicles, wheels, th, fr;
    
    printf("Enter the number of vehicles and wheels (separated by space): ");
    scanf("%d %d", &vehicles, &wheels);

    fr = (wheels - (3 * vehicles));
    th = vehicles - fr;

    printf("Number of Four Wheeler: %d\n", fr);
    printf("Number of Three Wheeler: %d\n", th);

    return 0;
}