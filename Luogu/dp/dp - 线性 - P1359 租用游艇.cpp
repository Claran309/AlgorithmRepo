#include <bits/stdc++.h>
using namespace std;
int n,a[201][201],dp[201][201],f[201];
int main(){
	cin >> n;
	for(int i = 1;i <= n-1;i++)
		for(int j = 1;j <= n-i;j++){
			cin >> a[i][j];
			dp[i][j] = a[i][j];
		}
	for(int i = 1;i <= n-1;i++)
		for(int j = 1;j <= n-i;j++){
			for(int x = 1;x <= n-i;x++)
				if(f[i+j] != 0)
					dp[i+j][x] = min(dp[i+j][x],a[i+j][x] + dp[i][j]);
				else dp[i+j][x] += dp[i][j];
			f[i+j]++;
		}
	
	for(int i = 1;i <= n-1;i++){
		for(int j = 1;j <= n-i;j++){
			cout << dp[i][j] << " ";
		}cout << endl;
	}
	
	cout << dp[n-1][1];
	return 0;
}
