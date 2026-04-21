#include <bits/stdc++.h>//1325
using namespace std;
typedef long long ll;
ll dp[2051][2051],n,m;
string s1,s2;
int main(){
	memset(dp,0x3f,sizeof(dp));
	cin >> s1 >> s2;
	n = s1.length();
	m = s2.length();
	for(ll i = 1;i <= n;i++) dp[i][0] = i;
	for(ll i = 1;i <= m;i++) dp[0][i] = i;
	for(ll i = 1;i <= n;i++) 
		for(ll j = 1;j <= m;j++) 
			if(s1[i-1] == s2[j-1]) dp[i][j] = min(dp[i-1][j-1],dp[i][j]);
			else dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]) + 1; 
	cout << dp[n][m];
	return 0;
}
