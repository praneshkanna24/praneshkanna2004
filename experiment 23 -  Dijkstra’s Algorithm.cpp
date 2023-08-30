#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the shortest path from source to vertex v
void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d ", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("%d ", v);
}

// Function to print the solution (distances and shortest paths)
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance from Source\tShortest Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Array to store the shortest distances
    int visited[V];  // Array to track visited vertices
    int parent[V];   // Array to store the shortest path tree

    // Initialize dist[] and visited[]
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the solution
    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int source = 0; // Source vertex

    dijkstra(graph, source);

    return 0;
}


