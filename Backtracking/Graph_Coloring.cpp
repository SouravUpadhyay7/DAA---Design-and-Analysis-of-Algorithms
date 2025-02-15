#include <stdio.h>

#define N 4 // Number of vertices

int graph[N][N] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int colors[N]; // Stores colors of vertices

// Function to check if the current color assignment is valid
int isSafe(int v, int c) {
    for (int i = 0; i < N; i++)
        if (graph[v][i] && colors[i] == c) // If adjacent vertex has the same color
            return 0;
    return 1;
}

// Function to solve the graph coloring problem using backtracking
int solveGraphColoring(int v, int m) {
    if (v == N) { // All vertices colored successfully
        for (int i = 0; i < N; i++)
            printf("Vertex %d -> Color %d\n", i, colors[i]);
        printf("\n");
        return 1;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            colors[v] = c; // Assign color
            if (solveGraphColoring(v + 1, m))
                return 1;
            colors[v] = 0; // Backtrack
        }
    }

    return 0; // No valid coloring found
}

// Main function
int main() {
    int m = 3; // Number of colors
    for (int i = 0; i < N; i++) colors[i] = 0; // Initialize colors

    if (!solveGraphColoring(0, m))
        printf("No solution exists!\n");

    return 0;
}

