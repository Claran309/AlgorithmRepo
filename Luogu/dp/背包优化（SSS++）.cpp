//代码超短，理解超难的 01背包 优化版 
#include <bits/stdc++.h>
using namespace std;

int dp[205],w[35],v[35],W,N;
int main(){
	cin >> N >> W;
	for(int i = 1;i <= N;i++)
		for(int j = 0;j <= W;j++) dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
	cout << dp[W];
	return 0;
}
