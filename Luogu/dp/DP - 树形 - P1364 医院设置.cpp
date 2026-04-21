#include <bits/stdc++.h>
using namespace std;
int n,cl,cr,p[110],f[110],ans,cnt;
vector<int> v[110];
void dfs(int u,int fa,int d){
	f[u] = p[u];
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		int y = v[u][i];
		if(y != fa){
			dfs(y,u,d+1);
			f[u] += f[y];
			cnt += f[y];
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> p[i] >> cl >> cr;
		if(cl != 0) v[i].push_back(cl),v[cl].push_back(i);
		if(cr != 0) v[i].push_back(cr),v[cr].push_back(i);
	}
	ans = 1e9;
	for(int i = 1;i <= n;i++){//枚举根节点 
		dfs(i,-1,1);
		ans = min(ans,cnt);
		memset(f,0,sizeof(f));
		cnt = 0;
	}
	cout << ans;
	return 0;
}

