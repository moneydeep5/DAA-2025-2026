#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, cost[10][10];
    int edges = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    printf("Enter adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        int min = 999, u = 0, v = 0, a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d - %d : %d\n", a, b, min);
            minCost += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nTotal Minimum Cost: %d\n", minCost);
    return 0;
}