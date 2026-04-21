//explanation written br Claran_ran_away
#include <bits/stdc++.h>
using namespace std;
int d[500001],f[500001][101],n,m,dis[500001],cv,cu,v1,u1,v2,u2,t,tmp;
vector<int> v[500001];
queue<int> q;
void bfs(){//遍历预处理f数组 
	q.push(1); d[1] = 1;//存深度 
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			int to = v[out][i];
			if(d[to] != 0) continue;
			d[to] = d[out]+1;//深度+1
			dis[to] = dis[out] + 1;
			f[to][0] = out;//父节点 
			for(int i = 1;i <= t;i++)
				f[to][i] = f[f[to][i-1]][i-1];//递推式 
			q.push(to);
		}
	}
}
int lca(int x,int y){
	if(d[x] > d[y]) swap(x,y);//以y为基准 
	for(int i = t;i >= 0;i--)
		if(d[f[y][i]] >= d[x]) y = f[y][i];//调整y的深度到x 
	if(x == y) return y;//特判 
	for(int i = t;i >= 0;i--)
		if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];//同时向上调整 
	return f[y][0];//父节点即为LCA 
}
int main(){
	cin >> n >> m;
	t = (int)(log(n)/log(2))/(log(2)/log(2))+1;//计算t_max 
	for(int i = 1;i < n;i++){
		cin >> cv >> cu;
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	bfs();
	for(int i = 1;i <= m;i++){
		cin >> v1 >> u1 >> v2 >> u2;
		int dis1 = dis[v1]+dis[u1]-2*dis[lca(v1,u1)];
		int dis2 = dis[v2]+dis[u2]-2*dis[lca(v2,u2)];
		int dis3 = dis[v1]+dis[v2]-2*dis[lca(v1,v2)];
		int dis4 = dis[u1]+dis[u2]-2*dis[lca(u1,u2)];
		if(dis1+dis2>=dis3+dis4) cout << "Y" << endl;
		else cout <<"N"<<endl;
	}

	return 0;
}
