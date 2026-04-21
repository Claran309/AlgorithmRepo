#include <bits/stdc++.h>
using namespace std;
int n,cn,cto,f[1501][2],m;
vector<int> v[1501];
void dfs(int u,int fa){
	f[u][1] = 1;
	f[u][0] = 0;
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		int y = v[u][i];
		if(y != fa){
			dfs(y,u);
			f[u][1] += min(f[y][1],f[y][0]);
			f[u][0] += f[y][1];
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> m >> cn;
		for(int j = 1;j <= cn;j++){
			cin >> cto;
			v[m].push_back(cto);
			v[cto].push_back(m);
		}
	}
	int ans = 1e8;
	for(int i = 0;i < n;i++){
		dfs(i,-1);
		ans = min(ans,min(f[i][1],f[i][0]));
	}
	cout << ans;
	return 0;
}
