#include <stdio.h>

int main() {
    int n, cost[10][10], visited[10] = {0};
    int edges = 0, minCost = 0, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (enter 0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; 
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        int min = 999;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);
        minCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nTotal Minimum Cost: %d\n", minCost);
    return 0;
}