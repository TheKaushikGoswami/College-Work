// Priority-based Scheduling - CPU Scheduling

#include <stdio.h>

int main(){
    int n, i, j, bt[20], wt[20], tat[20], p[20], pr[20], pos, temp, avwt=0, avtat=0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Process Burst Time and Priority\n");
    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i+1;
    }

    for(i=0; i<n; i++){
        pos = i;
        for(j=i+1; j<n; j++){
            if(pr[j] < pr[pos]){
                pos = j;
            }
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for(i=1; i<n; i++){
        wt[i] = 0;
        for(j=0; j<i; j++){
            wt[i] += bt[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    avwt /= n;
    avtat /= n;
    
    printf("\nAverage Waiting Time: %d", avwt);
    printf("\nAverage Turnaround Time: %d", avtat);

    return 0;
}