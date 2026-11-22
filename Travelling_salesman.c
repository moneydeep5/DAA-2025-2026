#include <stdio.h>

int n, cost[10][10], visited[10], minCost = 999;

void tsp(int city, int count, int currentCost) {
    // Base case: all cities visited and path exists back to start (city 0)
    if (count == n && cost[city][0] > 0) {
        if (currentCost + cost[city][0] < minCost) {
            minCost = currentCost + cost[city][0];
        }
        return;
    }

    // Explore all unvisited cities
    for (int next = 0; next < n; next++) {
        if (!visited[next] && cost[city][next] > 0) {
            visited[next] = 1;
            tsp(next, count + 1, currentCost + cost[city][next]);
            visited[next] = 0; // Backtrack
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no direct path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1; // Start from city 0
    tsp(0, 1, 0);

    printf("\nMinimum Travelling Cost: %d\n", minCost);
    return 0;
}
