#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 8  // Number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to implement Bellman-Ford Algorithm
void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    // Step 1: Initialize distances from source to all other vertices as INFINITY
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Step 2: Relax all edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(edges, 0);  // Find shortest paths from vertex 0

    return 0;
}

