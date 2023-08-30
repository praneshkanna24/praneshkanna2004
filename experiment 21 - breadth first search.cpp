#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Important for avoiding overwrite
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Placeholder value to indicate an empty queue
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

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

// Function to perform Breadth First Search traversal
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue(graph->numVertices);
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("Breadth First Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; graph->adjacencyList[currentVertex][i] != -1; i++) {
            int adjacentVertex = graph->adjacencyList[currentVertex][i];
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
        }
    }

    printf("\n");
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

    BFS(graph, 0);

    return 0;
}

