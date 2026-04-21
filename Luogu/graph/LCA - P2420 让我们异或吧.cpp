//explanation written br Claran_ran_away
#include <bits/stdc++.h>
using namespace std;
struct uu{
	int to,w;
};
int d[500001],f[500001][101],n,m,cw,dis[500001],cv,cu,qx,qy,t,tmp;
vector<uu> v[500001];
queue<int> q;
void bfs(){//遍历预处理f数组 
	q.push(1); d[1] = 1;//存深度 
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			int to = v[out][i].to;
			if(d[to] != 0) continue;
			d[to] = d[out]+1;//深度+1
			dis[to] = dis[out] xor v[out][i].w;
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
	cin >> n;
	t = (int)(log(n)/log(2))/(log(2)/log(2))+1;//计算t_max 
	for(int i = 1;i < n;i++){
		cin >> cv >> cu >> cw;
		uu in;in.to = cu;in.w = cw;
		v[cv].push_back(in);
		in.to = cv;
		v[cu].push_back(in);
	}
	bfs();
	cin >> m;
		for(int i = 1;i <= m;i++){
		cin >> qx >> qy;
		cout << ((dis[qx] xor dis[lca(qx,qy)]) xor (dis[qy] xor dis[lca(qx,qy)]) )<< endl;
	}
	
	return 0;
}
