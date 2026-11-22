#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[20];
    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int c[20][20], k[20][20];

    for (int i = 1; i <= n; i++)
        c[i][i] = 0;

    for (int d = 1; d < n; d++) {
        for (int i = 1; i <= n - d; i++) {
            int j = i + d;
            c[i][j] = 999999;

            for (int x = i; x < j; x++) {
                int cost = c[i][x] + c[x + 1][j] + p[i - 1] * p[x] * p[j];

                if (cost < c[i][j]) {
                    c[i][j] = cost;
                    k[i][j] = x;
                }
            }
        }
    }

    cout << "Minimum cost = " << c[1][n] << endl;

    cout << "K Table:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < j)
                cout << k[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
