#include<iostream>
#include<cmath>
using namespace std;
int a[201][201],n,dp[201];
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++)
			cin>>a[i][j];
		dp[i]=1e9;
	}
	for(int i=n-1;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			dp[i]=min(dp[i],a[i][j]+dp[j]);
	cout<<dp[1];
	return 0;
}
