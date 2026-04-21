#include <bits/stdc++.h>
using namespace std;
int n,cv,cu,dp[17000],p[17000],ans;
vector<int> v[17000];
void dfs(int u,int fa){
	dp[u] = p[u];
	for(int i = 0;i <= (int)v[u].size()-1;i++){ 
		int y = v[u][i];
		if(y != fa){//走不一样的节点 
			dfs(y,u);
			dp[u] += max(0,dp[y]);
		}
	} 
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> p[i];
	for(int i = 1;i < n;i++){
		cin >> cv >> cu;
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	dfs(1,-1);
	ans = INT_MIN;
	for(int i = 1;i <= n;i++)
		ans = max(ans,dp[i]);
	cout << ans;
	return 0;
}
