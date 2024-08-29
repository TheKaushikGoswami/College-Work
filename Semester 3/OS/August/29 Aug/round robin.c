// Round Robin Scheduling Algorithm

#include <stdio.h>

int main(){
    int i, n, bt[10], wt[10], tat[10], temp[10];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    int tq;
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int time = 0;

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (temp[i] > 0) {
                done = 0;

                if (temp[i] > tq) {
                    time += tq;
                    temp[i] -= tq;
                } else {
                    time += temp[i];
                    wt[i] = time - bt[i];
                    temp[i] = 0;
                }
            }
        }

        if (done == 1) {
            break;
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}