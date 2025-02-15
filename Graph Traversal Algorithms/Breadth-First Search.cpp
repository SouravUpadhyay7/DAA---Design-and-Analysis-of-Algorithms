#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Max number of vertices

int queue[MAX], front = -1, rear = -1;
int visited[MAX]; // To track visited nodes

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int graph[MAX][MAX], int vertices, int start) {
    for (int i = 0; i < vertices; i++) visited[i] = 0;
    
    printf("BFS Traversal: ");
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
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

    bfs(graph, vertices, 0);
    return 0;
}

