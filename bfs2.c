#include <stdio.h>

int a[20][20];     
int q[20];         
int visited[20];  
int n;
int f = -1;       
int r = -1;        

void bfs(int v) {
    for (int i = 0; i < n; i++) {
        if (a[v][i] != 0 && visited[i] == 0) {
            r += 1;      
            q[r] = i;        
            visited[i] = 1;  
            printf(" %d", i); 
        }
    }

    f += 1; 
    if (f > r) { 
        return;
    }

    bfs(q[f]);
}

int main() {
    int v; 

    printf("Enter number of vertices (max 20): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter adjacency matrix (enter 0 if no edge, 1 otherwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    f = 0;
    r = 0;
    q[r] = v;
    visited[v] = 1; 

    printf("\nBreadth First Traversal:");
    printf(" %d", v);

    bfs(v);

    if (r != n - 1) {
      printf("bfs traversal is not possible");
    }

    printf("\n");

    return 0;
}
