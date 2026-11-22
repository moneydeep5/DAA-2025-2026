#include <stdio.h>

int adj[10][10], vis[10], q[10], f = 0, r = 0, n;

void DFS(int v) {
    printf("%d ", v);
    vis[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !vis[i])
            DFS(i);
    }
}

void BFS(int start) {
    int b_vis[10] = {0};
    f = 0;
    r = 0;

    q[r++] = start;
    b_vis[start] = 1;

    while (f < r) {
        int v = q[f++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !b_vis[i]) {
                q[r++] = i;
                b_vis[i] = 1;
            }
        }
    }
}

int main() {
    int e, u, v, start;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS: ");
    DFS(start);

    printf("\nBFS: ");
    BFS(start);

    return 0;
}