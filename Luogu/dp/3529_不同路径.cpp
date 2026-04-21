#include <bits/stdc++.h>
using namespace std;
int n, m;
int ma[10][10];
int main() {
    cin >> n >> m;
    ma[1][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            ma[i][j] = ma[i - 1][j] + ma[i][j - 1];
        }
    cout << ma[n][m];
    return 0;
}
