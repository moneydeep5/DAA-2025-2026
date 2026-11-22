#include <iostream>
using namespace std;

int knapsack(int n, int m, int p[], int w[])
{
    if (n == 0 || m == 0)
        return 0;

    if (w[n - 1] > m)
        return knapsack(n - 1, m, p, w);

    return max(
        knapsack(n - 1, m - w[n - 1], p, w) + p[n - 1],
        knapsack(n - 1, m, p, w)
    );
}

int main()
{
    int n, m;

    cout << "Enter number of objects: ";
    cin >> n;

    int p[n], w[n];

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << "Enter total weight: ";
    cin >> m;

    cout << "Maximum profit = " << knapsack(n, m, p, w);

    return 0;
}
