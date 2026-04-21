#include <bits/stdc++.h>
using namespace std;
int n,cv,cu,dp[17000],p[17000],ans;
vector<int> v[17000];
void dfs(int u,int fa){
	dp[u] = p[u];
	for(int i = 0;i <= (int)v[u].size()-1;i++){ 
		int y = v[u][i];
		if(y != fa){
			dfs(y,u);
			dp[u] += max(0,dp[y]);
		}
	} 
	if(f[u]*2 >= n && !ans) ans = u;//改动    依据定理 
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
	cout << ans;
	return 0;
}
