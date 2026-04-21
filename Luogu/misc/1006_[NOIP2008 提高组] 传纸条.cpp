#include <bits/stdc++.h>
using namespace std;
int f[51][51][51][51],n,m,ma[51][51];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin >> ma[i][j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			for(int k = 1;k <= n;k++)
				for(int l = 1;l <= m;l++){
					if((i != k && j != l) || (i == n && j == m && k == n && l == m))
					f[i][j][k][l] = max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1])) + ma[i][j] + ma[k][l];
				}
	cout << f[n][m][n][m];
	return 0;
}
