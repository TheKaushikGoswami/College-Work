// First Come, First Serve - Disk Scheduling

#include <stdio.h>

int main(){
    int n, i, head, seek = 0, diff;
    float avg;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter the request queue: ");
    for(i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++){
        diff = req[i] - head;
        if(diff < 0) diff *= -1; 
        seek += diff;
        head = req[i]; 
    }

    printf("Total seek time: %d\n", seek);
    avg = seek / (float)n; 
    printf("Average seek time: %.2f\n", avg);

    return 0;
}
