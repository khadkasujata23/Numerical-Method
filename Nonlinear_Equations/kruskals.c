#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

// For Disjoint Set (Union-Find)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[yset] = xset;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edges[E];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight
    qsort(edges, E, sizeof(struct Edge), compare);

    // Initialize parent array for Union-Find
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in the Minimum Spanning Tree:\n");
    int count = 0;
    int totalWeight = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int uSet = find(parent, edges[i].u);
        int vSet = find(parent, edges[i].v);

        if (uSet != vSet) {
            printf("%d -- %d  (weight %d)\n", edges[i].u, edges[i].v, edges[i].weight);
            totalWeight += edges[i].weight;
            unionSet(parent, uSet, vSet);
            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}