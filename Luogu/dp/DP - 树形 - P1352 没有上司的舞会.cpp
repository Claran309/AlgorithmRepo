#include <bits/stdc++.h>
using namespace std;
int n,cv,cu,dp[17000][2],p[17000],ans,f,d[12000];
vector<int> v[17000];
void dfs(int u,int fa){
	dp[u][1] = p[u];
	dp[u][0] = 0;
	for(int i = 0;i <= (int)v[u].size()-1;i++){ 
		int y = v[u][i];
		if(y != fa){ 
			dfs(y,u);
			dp[u][1] += max(0,dp[y][0]);
			dp[u][0] += max(0,max(dp[y][0],dp[y][1]));
		}
	} 
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> p[i];
	for(int i = 1;i < n;i++){
		cin >> cv >> cu;
		v[cu].push_back(cv);
	}
	//dfs(1,-1);
	ans = INT_MIN;
	for(int i = 1;i <= n;i++){
		dfs(i,-1);
		ans = max(ans,max(dp[i][0],dp[i][1]));
	}
		
	cout << ans;
	return 0;
}
