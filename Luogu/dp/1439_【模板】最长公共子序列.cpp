#include <bits/stdc++.h>
using namespace std;
int n,s1[1001],s2[1001],dp[1001][1001];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s1[i];
	for(int i = 1;i <= n;i++) cin >> s2[i];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s1[i] == s2[j])
			dp[i][j] = max(dp[i][j],dp[i-1][j-1] +1); 
		}
	cout << dp[n][n];
	return 0;
}
