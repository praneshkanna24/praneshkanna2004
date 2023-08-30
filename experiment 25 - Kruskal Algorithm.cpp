#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5 // Number of vertices
#define E 7 // Number of edges

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to find the set of an element (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform union of two sets (uses union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function to sort edges by weight in ascending order
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm implementation
void kruskalMST(struct Edge edges[]) {
    struct Edge result[V - 1]; // MST will have V-1 edges
    int e = 0; // Index variable for the result array
    int i = 0; // Index variable for the sorted edges array

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Keep adding the smallest edge until V-1 edges are included in the MST
    while (e < V - 1) {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int j = 0; j < V - 1; j++) {
        printf("%d - %d \t%d\n", result[j].src, result[j].dest, result[j].weight);
    }

    free(subsets);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(edges);

    return 0;
}

