#include <stdio.h>

#define V 5   // Number of vertices
#define E 7   // Number of edges

typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[E];  // Array to store edges
int parent[V];  // Parent array for union-find

// Function to find root of a node
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Function to perform union of two sets
void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

// Function to implement Kruskal’s Algorithm
void kruskalMST() {
    int totalWeight = 0;

    // Initialize each node as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight (Bubble Sort for simplicity)
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0, count = 0; count < V - 1 && i < E; i++) {
        if (find(edges[i].src) != find(edges[i].dest)) {
            printf("%d - %d  (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(edges[i].src, edges[i].dest);
            count++;
        }
    }

    printf("Total Weight of MST: %d\n", totalWeight);
}

// Main function
int main() {
    edges[0] = (Edge){0, 1, 2};
    edges[1] = (Edge){0, 3, 6};
    edges[2] = (Edge){1, 2, 3};
    edges[3] = (Edge){1, 3, 8};
    edges[4] = (Edge){1, 4, 5};
    edges[5] = (Edge){2, 4, 7};
    edges[6] = (Edge){3, 4, 9};

    kruskalMST();
    return 0;
}

