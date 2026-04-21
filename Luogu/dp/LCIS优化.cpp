#include <bits/stdc++.h>
using namespace std;
int n,s1[101],s2[101],dp[101][101];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s1[i];
	for(int i = 1;i <= n;i++) cin >> s2[i];
	for(int i = 1;i <= n;i++){
		int valve = 0;
		for(int j = 1;j <= n;j++){
			if(s1[i] == s2[j]) dp[i][j] = valve + 1;
			else dp[i][j] = dp[i-1][j];
			if(s2[j] < s1[i]) valve = max(valve,dp[i][j]);
		}
	}
	cout << dp[n][n];
	return 0;
}
