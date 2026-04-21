#include <bits/stdc++.h>
using namespace std;
int n,s1[101],s2[101],dp[101][101];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> s1[i];
	for(int i = 1;i <= n;i++) cin >> s2[i];
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= n;j++){
		if(s1[i] == s2[j]) 
		for(int l = 0;l <= j;l++){ 
			if(s1[i] > s2[l]) dp[i][j] = max(dp[i][j],dp[i-1][l]+1);
		} 
		else dp[i][j] = dp[i-1][j];
	}
	cout << dp[n][n];
	return 0;
}
