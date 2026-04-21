#include <bits/stdc++.h>
using namespace std;
int n,num[1000001],dp[1000001],ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> num[i];
		dp[i] = 1;
	}
	for(int i = 1;i <= n;i++){ 
		for(int j = 1;j <= i-1;j++){
			if(num[i] <= num[j]) continue;
			dp[i] = max(dp[j]+1,dp[i]);
			ans = max(dp[i],ans);
		}
	} 
	cout << ans;
	return 0;
}
