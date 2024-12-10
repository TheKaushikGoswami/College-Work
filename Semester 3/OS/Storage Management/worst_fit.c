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

    // Worst Fit Allocation
    for (i = 0; i < n; i++) {
        int worst_fit = -1;
        for (j = 0; j < m; j++) {
            if (!block_used[j] && memory[j] >= process[i]) {
                if (worst_fit == -1 || memory[j] > memory[worst_fit]) {
                    worst_fit = j;
                }
            }
        }

        if (worst_fit != -1) {
            memory[worst_fit] -= process[i];
            allocation[i] = worst_fit;
            block_used[worst_fit] = 1;
        }
    }

    // Output Allocation
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
    