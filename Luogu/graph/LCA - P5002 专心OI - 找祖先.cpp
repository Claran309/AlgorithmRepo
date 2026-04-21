//不看题解不会做 ——Claran 
//explained by Claran
#include <bits/stdc++.h>
using namespace std;
int n,m,r,cv,cu,dp[50001],f[50001],ans[50001];
vector<int> v[50001];
int dfs(int u,int fa){//count_size
	dp[u] = 1;
	f[u] = fa;
	for(int i = 0;i <= (int)v[u].size()-1;i++)
		if(v[u][i] != fa) dp[u] += dfs(v[u][i],u);
	return dp[u];
}
int main(){
	cin >> n >> r >> m;
	for(int i = 1;i < n;i++){
		cin >>cv >> cu;
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	dfs(r,0);
	for(int i = 1;i <= n;i++){
		int u = i;
		for(int j = 0;j <= (int)v[u].size()-1;j++){
			int to = v[u][j];
			if(f[u] == to) continue;
			ans[u] += (dp[u]-dp[to])*dp[to];
		}
		ans[u] = ans[u]+dp[u];
	}
	for(int i = 1;i <= m;i++){
		cin >> cv;
		cout << ans[cv] << endl;
	}
	return 0;
}
