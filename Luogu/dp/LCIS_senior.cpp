#include <bits/stdc++.h>
using namespace std;
int n,a[3001],b[3001],dp[3001][3001],val;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++)cin >> b[i];
	for(int i = 1;i <= n;i++){
		val = 0; 
		for(int j = 1;j <= n;j++){ 
			if(a[i] == b[j]) 
				dp[i][j] = val+1;
			else
				dp[i][j] = dp[i-1][j];
			if(b[j] < a[i]) val=max(val,dp[i-1][j]);
		} 
	}
	cout << dp[n][n];
	return 0;
}
/*
4
1 3 2 8
1 2 9 8
*/
