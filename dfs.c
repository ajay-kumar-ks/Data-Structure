#include <stdio.h>

int a[20][20];
int visited[20];
int n;

void dfs(int v) {
    for (int i = 0; i < n; i++) {
        if (a[v][i] != 0 && visited[i] == 0) {
            visited[i] = 1;
            printf(" %d", i);
            dfs(i);
        }
    }
}

int main() {
    int v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &v);

    visited[v] = 1;
    printf("\nDepth First Traversal:");
    printf(" %d", v);

    dfs(v);

    printf("\n");

    return 0;
}