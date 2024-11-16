#include <stdio.h>

#define MAX 100

void dfs(int friends[MAX][MAX], int visited[MAX], int n, int person) {
    visited[person] = 1;
    for (int i = 0; i < n; i++) {
        if (friends[person][i] == 1 && !visited[i]) {
            dfs(friends, visited, n, i);
        }
    }
}

int findFriendCircles(int friends[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int friendCircles = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(friends, visited, n, i);
            friendCircles++;
        }
    }
    return friendCircles;
}

int main() {
    int n;
    printf("Enter the number of people (N): ");
    scanf("%d", &n);

    int friends[MAX][MAX];
    printf("Enter the friendship matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &friends[i][j]);
        }
    }

    int result = findFriendCircles(friends, n);
    printf("Number of friend circles: %d\n", result);

    return 0;
}
