#include <bits/stdc++.h>
using namespace std;
struct road{
	int to,w;
};
int n,V,cv,cu,f[10001][1001],cw,s[10001];
vector<road> v[10001];
void dfs(int u,int fa){
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		int y = v[u][i].to;
		if(y == fa) continue;
		dfs(y,u);
		s[u] += s[y]+1;
		for(int j = min(V,s[u]);j >= 1;j--)
			for(int k  =min(s[y],j-1);k >= 0;k--)
				f[u][j] = max(f[u][j],f[u][j-1-k] + v[u][i].w + f[y][k]);	
	}
}
int main(){
	cin >> n >> V;
	for(int i = 1;i < n;i++){
		cin >> cv >> cu >> cw;
		road in;in.to = cu;in.w = cw;
		v[cv].push_back(in);
		in.to = cv;
		v[cu].push_back(in);
	}
	dfs(1,-1);
	cout << f[1][V];
	return 0;
}
