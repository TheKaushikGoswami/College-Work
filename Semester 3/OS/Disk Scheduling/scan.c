// Scan Algorithm - Disk Scheduling

#include <stdio.h>

int main(){
    int n, currentPosition, upperLimit;

    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    int sequence[n];
    printf("Enter the elements of the sequence:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &sequence[i]);
    }
    1
    printf("Enter the current position of the disk head: ");
    scanf("%d", &currentPosition);

    printf("Enter the upper limit of the disk: ");
    scanf("%d", &upperLimit);


    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(sequence[j] > sequence[j+1]){
                int temp = sequence[j];
                sequence[j] = sequence[j+1];
                sequence[j+1] = temp;
            }
        }
    }

    int totalHeadMovement = (upperLimit - currentPosition) + (upperLimit - sequence[0]);

    printf("The total head movement is: %d\n", totalHeadMovement);

    return 0;
}