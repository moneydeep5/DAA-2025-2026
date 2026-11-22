#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of denominations: ";
    cin >> n;

    int d[n];

    cout << "Enter denominations: ";
    for (int i = 0; i < n; i++)
        cin >> d[i];

    cout << "Enter amount: ";
    cin >> amount;

    int c[n + 1][amount + 1];

    for (int j = 0; j <= amount; j++)
        c[0][j] = j;

    for (int i = 1; i <= n; i++) {
        c[i][0] = 0;

        for (int j = 1; j <= amount; j++) {
            if (j < d[i - 1])
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = min(c[i - 1][j], 1 + c[i][j - d[i - 1]]);
        }
    }

    cout << "Minimum coins = " << c[n][amount] << endl;

    return 0;
}
