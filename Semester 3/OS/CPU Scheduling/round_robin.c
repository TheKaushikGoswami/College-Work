// Round Robin Algorithm - CPU Scheduling

#include <stdio.h>

int main(){
    int i, n, bt[20], wt[20], tat[20], temp[20], tq, time=0, remain, flag=0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    for(i=0; i<n; i++){
        wt[i] = 0;
    }

    while(remain != 0){
        for(i=0; i<n; i++){
            if(temp[i] > tq){
                time += tq;
                temp[i] -= tq;
            } else if(temp[i] > 0){
                time += temp[i];
                wt[i] = time - bt[i];
                temp[i] = 0;
                remain--;
            }
        }
    }

    for(i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0; i<n; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    return 0;
}