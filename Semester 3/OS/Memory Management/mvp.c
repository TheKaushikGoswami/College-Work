// Memory Variable Partition

#include <stdio.h>

int main(){
    int n, i, j, m, k, temp, flag = 0;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    printf("Enter the number of processes: ");
    scanf("%d", &m);
    int mem[n], proc[m];
    printf("Enter the memory blocks: ");
    for(i = 0; i < n; i++){
        scanf("%d", &mem[i]);
    }
    printf("Enter the processes: ");
    for(i = 0; i < m; i++){
        scanf("%d", &proc[i]);
    }
    for(i = 0; i < m; i++){
        flag = 0;
        for(j = 0; j < n; j++){
            if(mem[j] >= proc[i]){
                printf("Process %d allocated to memory block %d\n", proc[i], j+1);
                mem[j] -= proc[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("Process %d cannot be allocated\n", proc[i]);
        }
    }
    return 0;
}