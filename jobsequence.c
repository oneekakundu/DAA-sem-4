#include <stdio.h>

int id[100], p[100], d[100], slot[100], n, dmax;

void sort_jobs() {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j] < p[j + 1]) { 
                // Swap profit
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                
                // Swap deadline
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
                
                // Swap job id
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }
}

int job_s() {
    int i, k, c, tp;
    
    c = 0;
    tp = 0;
    dmax = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (dmax < d[i]) {
            dmax = d[i];
        }
    }

    printf("\nMaximum deadline is %d\n", dmax);

    // Initialize slots to -1
    for (i = 1; i <= dmax; i++) {
        slot[i] = -1;
    }

    // Sort jobs by profit (descending order)
    sort_jobs();

    // Job scheduling
    for (i = 0; i < n; i++) {
        for (k = d[i]; k > 0; k--) {
            if (slot[k] == -1) {
                slot[k] = id[i];  // Store job ID instead of index
                tp += p[i];
                c++;
                break;
            }
        }
        if (c == dmax)
            break;
    }

    return tp;
}

int main() {
    int i, tp;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the job id, profit, deadline respectively: ");
        scanf("%d %d %d", &id[i], &p[i], &d[i]);
    }

    tp = job_s();

    printf("\nSolution vector:\n");
    for (i = 1; i <= dmax; i++) {  // Only print up to dmax
        if (slot[i] != -1)
            printf("J%d ", slot[i]);  // Prints correct job IDs
    }

    printf("\nTotal profit = %d\n", tp);

    return 0;
}

