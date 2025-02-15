#include <stdio.h>

#define MAX 100  // Max number of vertices

int visited[MAX]; // To track visited nodes

void dfs(int graph[MAX][MAX], int vertices, int node) {
    if (visited[node]) return;
    
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(graph, vertices, i);
        }
    }
}

int main() {
    int vertices = 5;
    int graph[MAX][MAX] = { 
        {0, 1, 1, 0, 0}, 
        {1, 0, 0, 1, 1}, 
        {1, 0, 0, 0, 1}, 
        {0, 1, 0, 0, 1}, 
        {0, 1, 1, 1, 0} 
    };

    for (int i = 0; i < vertices; i++) visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(graph, vertices, 0);
    printf("\n");

    return 0;
}

