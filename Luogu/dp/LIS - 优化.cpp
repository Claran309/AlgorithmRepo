#include <bits/stdc++.h>
using namespace std;
int n,a[101],dp[101],ans,len;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dp[1] = a[1],len++;
	for(int i = 2;i <= n;i++)
		if(a[i] > dp[len]) dp[++len] = a[i];
		else{
			int pos = lower_bound(dp+1,dp+len+1,a[i]) - dp;
			dp[pos] = a[i];	
		}
	for(int i = 1;i <= len;i++) cout << dp[i] << " ";
	return 0;
}
