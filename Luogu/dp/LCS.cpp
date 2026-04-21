#include <bits/stdc++.h>
using namespace std;
int n,a[10001],b[10001],dp[10001][10001];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
		cin >> b[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(a[i] == b[j]) dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
		}
	cout << dp[n][n];
	return 0;
}
