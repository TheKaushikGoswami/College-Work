// Shortest Seek Time First - Disk Scheduling

#include <stdio.h>

int main(){
    int n, i, j, head, seek = 0, diff, min, pos;
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
        min = 1e9;
        for(j = 0; j < n; j++){
            diff = req[j] - head;
            if(diff < 0) diff *= -1;
            if(diff < min){
                min = diff;
                pos = j;
            }
        }
        seek += min;
        head = req[pos];
        req[pos] = 1e9;
    }

    printf("Total seek time: %d\n", seek);
    avg = seek / (float)n;
    printf("Average seek time: %.2f\n", avg);

    return 0;
}