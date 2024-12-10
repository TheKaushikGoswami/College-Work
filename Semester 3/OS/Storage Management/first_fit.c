// First Fit Allocation Algorithm

#include <stdio.h>

int main() {
    int m, n, i, j;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int memory[m], block_used[m];

    printf("Enter the sizes of the memory blocks: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &memory[i]);
        block_used[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n];

    printf("Enter the sizes of the processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    int allocation[n];
    for (i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) { 
            if (memory[j] >= process[i] && !block_used[j]) {
                allocation[i] = j; 
                memory[j] -= process[i];
                block_used[j] = 1;
                break;
            }
        }
    }

    // Output Allocation and Internal Fragmentation
    printf("\nProcess No.\tProcess Size\tBlock No.\tInternal Fragmentation\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t\t%d\n", allocation[i] + 1, memory[allocation[i]]);
        } else {
            printf("Not Allocated\t\t-\n");
        }
    }

    return 0;
}
