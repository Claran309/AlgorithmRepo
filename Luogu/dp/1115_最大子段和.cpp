#include <bits/stdc++.h>
using namespace std;
int a[200001],dp[200001];
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	dp[0] = a[0];
	int m = -200001;
	for(int i = 1;i < n;i++){
		dp[i] = max(a[i],dp[i-1]+a[i]);
		if(dp[i] > m){
			m = dp[i];
		}
	}
	cout << m;
	return 0;
}
