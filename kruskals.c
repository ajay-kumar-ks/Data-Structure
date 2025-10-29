#include <stdio.h>
#define MAX 10
#define INF 9999

int parent[MAX];
int cost[MAX][MAX];

// Find operation for Disjoint Set
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union operation for Disjoint Set
int union_sets(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; // Replace 0 with INF for no connection
        }
    }

    // Initialize parent array
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int edgeCount = 0;
    int mincost = 0;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edgeCount < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        // Find the minimum cost edge
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && union_sets(a, b)) {
            printf("Edge %d: (%d, %d) cost: %d\n", edgeCount + 1, a, b, min);
            mincost += min;
            edgeCount++;
        }

        cost[a][b] = cost[b][a] = INF; // Mark edge as used
    }

    printf("\nMinimum cost of the spanning tree = %d\n", mincost);

    return 0;
}
