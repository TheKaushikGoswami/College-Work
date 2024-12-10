// Dining Philosopher Problem

#include <stdio.h>

int main(){
    int n, i, j, k;
    printf("Enter the number of philosophers: ");
    scanf("%d", &n);
    int chop[n];
    for(i = 0; i < n; i++){
        chop[i] = 1;
    }
    for(i = 0; i < n; i++){
        if(chop[i] == 1 && chop[(i+1)%n] == 1){
            chop[i] = 0;
            chop[(i+1)%n] = 0;
            printf("Philosopher %d is eating\n", i+1);
            chop[i] = 1;
            chop[(i+1)%n] = 1;
        }
    }
    return 0;
}