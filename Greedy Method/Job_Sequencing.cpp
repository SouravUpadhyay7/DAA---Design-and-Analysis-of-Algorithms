#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id, deadline, profit;
} Job;

int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

// Function to find maximum profit job sequence
void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int result[maxDeadline + 1]; 
    for (int i = 0; i <= maxDeadline; i++)
        result[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");
    for (int i = 1; i <= maxDeadline; i++)
        if (result[i] != -1) printf("%d ", result[i]);

    printf("\nTotal Profit: %d\n", totalProfit);
}

// Main function
int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 50}, {3, 2, 10}, {4, 1, 20}, {5, 3, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);
    return 0;
}

