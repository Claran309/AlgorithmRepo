#include <bits/stdc++.h>
using namespace std;
int W,N,w[36],dp[36][200],v[35];
int main(){
	cin >> W >> N;
	for(int i = 1;i <= N;i++) cin >> w[i] >> v[i];
	for(int i = 1;i <= N;i++)
		for(int j = 0;j <= W;j++)
			if(j >= w[i]) dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
	cout << dp[N][W];
	return 0;
}
