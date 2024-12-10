// Banker's Algorithm 

#include <stdio.h>

int main(){
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m], need[n][m], work[m], finish[n];
    printf("Enter the allocation matrix: ");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix: ");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources: ");
    for(i = 0; i < m; i++){
        scanf("%d", &avail[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    for(i = 0; i < m; i++){
        work[i] = avail[i];
    }
    for(i = 0; i < n; i++){
        finish[i] = 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(finish[j] == 0){
                int flag = 0;
                for(k = 0; k < m; k++){
                    if(need[j][k] > work[k]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    for(k = 0; k < m; k++){
                        work[k] += alloc[j][k];
                    }
                    finish[j] = 1;
                }
            }
        }
    }
    int safe = 1;
    for(i = 0; i < n; i++){
        if(finish[i] == 0){
            safe = 0;
            break;
        }
    }
    if(safe == 1){
        printf("The system is in safe state, Following is the safe sequence: ");
        // The safe sequence of processes , ex: P0 -> P1 -> P2 -> P3 -> P4
        for(i = 0; i < n; i++){
            printf("P%d", i);
            if(i != n-1){
                printf(" -> ");
            }
        }
        
    } else {
        printf("The system is in unsafe state\n");
    

    return 0;
}
}