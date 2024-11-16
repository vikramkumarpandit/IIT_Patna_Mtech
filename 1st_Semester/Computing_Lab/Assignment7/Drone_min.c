#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 10000

// Directions based on the allowed moves
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

typedef struct {
    int x, y, steps;
} Node;

int is_within_bounds(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int bfs(int n, int startX, int startY, int targetX, int targetY) {
    int visited[MAX][MAX] = {0};
    Node queue[MAX * MAX];
    int front = 0, rear = 0;

    // Initialize the queue with the starting position
    queue[rear++] = (Node){startX, startY, 0};
    visited[startX][startY] = 1;

    while (front < rear) {
        Node current = queue[front++];
        
        // Check if the target is reached
        if (current.x == targetX && current.y == targetY) {
            return current.steps;
        }

        // Explore all possible moves
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (is_within_bounds(newX, newY, n) && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                queue[rear++] = (Node){newX, newY, current.steps + 1};
            }
        }
    }
    return -1;  // If the target is unreachable
}

int main() {
    int n, startX, startY, targetX, targetY;

    printf("Enter the size of the grid (N): ");
    scanf("%d", &n);
    printf("Enter the starting position (startX startY): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter the target position (targetX targetY): ");
    scanf("%d %d", &targetX, &targetY);

    int result = bfs(n, startX, startY, targetX, targetY);
    if (result != -1) {
        printf("Minimum steps: %d\n", result);
    } else {
        printf("Target is unreachable\n");
    }

    return 0;
}
