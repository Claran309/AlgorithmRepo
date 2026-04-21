#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10001][10001],f[10001][10001],n,m,ans;
int main(){
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++){
			cin>>a[i][j];	
	if (a[i][j]==1) f[i][j]=min(min(f[i][j-1],f[i-1][j]),f[i-1][j-1])+1;
	ans=max(ans,f[i][j]);
	}
	cout<<ans;	
}
