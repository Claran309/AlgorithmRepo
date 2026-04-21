#include <bits/stdc++.h>
using namespace std;
int dp[35][205],w[35],v[35],W,N;
int main(){
	cin >> W >> N;
	for(int i = 1;i <= N;i++)
		cin >> w[i] >> v[i];
	for(int i = 1;i <= N;i++)
		for(int j = 0;j <= W;j++)
			if(j < w[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i][j-w[i]]+v[i],dp[i-1][j]);
	cout << "max=" << dp[N][W];
	return 0;
}
