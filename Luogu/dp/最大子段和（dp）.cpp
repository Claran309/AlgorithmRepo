#include <bits/stdc++.h>
using namespace std;
int m = -200001,in[200001],dp[200001],n;
int main(){
	cin >> n;
	for(int i = 0;i < n;i++) cin >> in[i];
	dp[0] = in[0];
	for(int i = 1;i < n;i++){
		dp[i] = max(in[i],dp[i-1] + in[i]);
		if(dp[i] > m) m = dp[i];
	}
	cout << m;
	return 0;
}
