// Shortest Job First Algorithm

#include <stdio.h>

int main(){
    int n, bt[20], wt[20], tat[20], i, j, temp;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times of the processes: ");
    for(i=0; i<n; i++){
        scanf("%d", &bt[i]);
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(bt[i] > bt[j]){
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    for(i=0; i<n; i++){
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", avgwt);
    printf("Average Turnaround Time: %.2f\n", avgtat);

    return 0;
}