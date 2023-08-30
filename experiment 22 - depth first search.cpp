#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph using an adjacency list
struct Graph {
    int numVertices;
    int** adjacencyList;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyList[src] = (int*)malloc(sizeof(int));
    graph->adjacencyList[src][0] = dest;
}

// Function to perform Depth First Search traversal
void DFS(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; graph->adjacencyList[vertex][i] != -1; i++) {
        int adjacentVertex = graph->adjacencyList[vertex][i];
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
    }
}

int main() {
    int numVertices = 7;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    int* visited = (int*)calloc(numVertices, sizeof(int));

    printf("Depth First Traversal starting from vertex 0:\n");
    DFS(graph, 0, visited);
    printf("\n");

    free(visited);

    return 0;
}

