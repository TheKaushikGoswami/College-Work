// Memory Fixed Partition - Memory Management

#include <stdio.h>

int main() {
    int i, j, n, m, block[10], process[10], allocation[10], flag[10];

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of blocks\n");
    for(i=0; i<m; i++){
        printf("Block %d: ", i+1);
        scanf("%d", &block[i]);
    }

    printf("Enter size of processes\n");
    for(i=0; i<n; i++){
        printf("Process %d: ", i+1);
        scanf("%d", &process[i]);
    }

    for(i=0; i<n; i++){
        allocation[i] = -1;
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(block[j] >= process[i]){
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess\t\tProcess Size\tBlock\n");
    for(i=0; i<n; i++){
        printf("P[%d]\t\t%d\t\t", i+1, process[i]);
        if(allocation[i] != -1){
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not Allocated\n");
        }
    }

    return 0;
}