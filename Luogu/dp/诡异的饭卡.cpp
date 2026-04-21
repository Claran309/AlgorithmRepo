#include <bits/stdc++.h>
using namespace std;
int n,w[1001],rest,dp[1001][1001];
bool cmp(int a,int b){
	if(a >= b) return true;
	else return false;
}
int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> w[i];
	cin >> rest;
	if(rest < 5){
		cout << rest;
		return 0;
	}
	sort(w,w+n,cmp);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= rest - 5;j++){
			if(j >= w[i]) dp[i][j] = max(dp[i-1][j-w[i]]+w[i],dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << rest-dp[n][rest-5] - w[0];
	return 0;
}
