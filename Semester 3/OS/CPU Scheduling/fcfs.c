// First Come, First Serve - CPU Scheduling

#include <stdio.h>

int main(){
    int n, i, j, bt[20], wt[20], tat[20], avwt=0, avtat=0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Process Burst Time\n");
    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] += bt[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;
    
    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d", avtat);

    return 0;
}