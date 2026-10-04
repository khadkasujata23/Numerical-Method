#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int n; // Number of vertices

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) {
        return -1; // Queue empty
    }
    return queue[front++];
}

// Initialize graph
void initGraph() {
    int i, j;
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
}

// DFS traversal (recursive)
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] && !visited[i])
            DFS(i);
    }
}

// BFS traversal
void BFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Display adjacency matrix
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int main() {
    int choice, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    initGraph();

    while (1) {
        printf("\nGraph Menu:\n");
        printf("1. Add Edge\n2. Display Adjacency Matrix\n3. DFS Traversal\n4. BFS Traversal\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter edge (u v): ");
                scanf("%d %d", &u, &v);
                if (u >= 0 && u < n && v >= 0 && v < n) {
                    adjMatrix[u][v] = 1;
                    adjMatrix[v][u] = 1; // For undirected graph
                } else {
                    printf("Invalid vertices\n");
                }
                break;
            case 2:
                displayMatrix();
                break;
            case 3:
                for (int i = 0; i < n; i++) visited[i] = 0;
                printf("DFS Traversal starting from vertex 0: ");
                DFS(0);
                printf("\n");
                break;
            case 4:
                printf("BFS Traversal starting from vertex 0: ");
                BFS(0);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}