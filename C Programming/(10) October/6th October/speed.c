#include <stdio.h>

int main(){

    // An aeroplane with a speed of x kmph covers distance of 2535 km in 5 hours. Find the speed of aeroplane if it covers the same distance in 3.5 hours.

    float distance = 2535; 
    float time = 3.5;
    float speed = distance / time;

    printf("The speed of the aeroplane is %.2f kmph", speed);

    return 0;
}