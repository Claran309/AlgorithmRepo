#include <bits/stdc++.h>
using namespace std;
int n,cv,cu,ans,f[1001],been[1001],d[1001];
vector<int> v[1001];
void dp(int u){
	been[u] = 1;
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		int y = v[u][i];
		if(been[y]) continue;
		dp(y);
		ans = max(ans,d[u]+d[y]+1);
		d[u] = max(d[u],d[y]+1);
	}
}
int main(){
	cin >>n;
	for(int i = 1;i < n;i++){
		cin >> cv >> cu;
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	dp(5);
	for(int i = 1;i <= n;i++){
		cout << max(d[i],n-1/*sumi*/-d[i]) << endl;
	}
	cout << ans;
	return 0;
}
