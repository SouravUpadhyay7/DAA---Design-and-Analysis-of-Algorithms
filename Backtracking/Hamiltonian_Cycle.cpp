#include <stdio.h>

#define N 5 // Number of vertices

int graph[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[N]; // Stores Hamiltonian Path

// Function to check if adding vertex v to the path is valid
int isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) return 0; // If not adjacent
    for (int i = 0; i < pos; i++) // If already in path
        if (path[i] == v) return 0;
    return 1;
}

// Function to solve Hamiltonian Cycle using backtracking
int solveHamiltonian(int pos) {
    if (pos == N) { // All vertices included
        if (graph[path[pos - 1]][path[0]]) { // Check if cycle exists
            for (int i = 0; i < N; i++)
                printf("%d -> ", path[i]);
            printf("%d\n", path[0]); // Completing the cycle
            return 1;
        }
        return 0;
    }

    for (int v = 1; v < N; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (solveHamiltonian(pos + 1))
                return 1;
            path[pos] = -1; // Backtrack
        }
    }

    return 0;
}

// Main function
int main() {
    for (int i = 0; i < N; i++) path[i] = -1; // Initialize path
    path[0] = 0; // Start from vertex 0

    if (!solveHamiltonian(1))
        printf("No Hamiltonian Cycle exists!\n");

    return 0;
}

