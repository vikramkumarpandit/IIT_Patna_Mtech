#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Direction vectors for up, down, left, and right movements
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Structure to store grid coordinates and path cost
typedef struct {
    int x, y, cost;
} Node;

// Queue functions for BFS
typedef struct {
    Node nodes[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Node node) {
    q->nodes[q->rear++] = node;
}

Node dequeue(Queue *q) {
    return q->nodes[q->front++];
}

// BFS function to find the shortest path
int bfs(int grid[MAX][MAX], int N, int srcX, int srcY, int destX, int destY) {
    bool visited[MAX][MAX] = {false};
    Queue q;
    initQueue(&q);

    // Start BFS from the source point
    enqueue(&q, (Node){srcX, srcY, 0});
    visited[srcX][srcY] = true;

    while (!isEmpty(&q)) {
        Node current = dequeue(&q);

        // Check if we've reached the destination
        if (current.x == destX && current.y == destY) {
            return current.cost;
        }

        // Explore all 4 possible movements
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Check bounds and if the cell is not blocked and unvisited
            if (newX >= 0 && newX < N && newY >= 0 && newY < N && 
                grid[newX][newY] != -1 && !visited[newX][newY]) {
                
                visited[newX][newY] = true;
                enqueue(&q, (Node){newX, newY, current.cost + 1});
            }
        }
    }

    return -1;  // If the destination is unreachable
}

int main() {
    int N;
    printf("Enter the size of the grid (N): ");
    scanf("%d", &N);

    int srcX, srcY, destX, destY;
    printf("Enter the source coordinates (x y): ");
    scanf("%d %d", &srcX, &srcY);

    printf("Enter the destination coordinates (x y): ");
    scanf("%d %d", &destX, &destY);

    int grid[MAX][MAX] = {0};

    int m;
    printf("Enter the number of blocked cells: ");
    scanf("%d", &m);

    printf("Enter the blocked cells' coordinates:\n");
    for (int i = 0; i < m; i++) {
        int bx, by;
        scanf("%d %d", &bx, &by);
        grid[bx][by] = -1;  // Mark blocked cells as -1
    }

    int result = bfs(grid, N, srcX, srcY, destX, destY);

    if (result != -1) {
        printf("Shortest path cost: %d\n", result);
    } else {
        printf("Path is not reachable.\n");
    }

    return 0;
}
