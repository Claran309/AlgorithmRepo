
#include <bits/stdc++.h>
using namespace std;
long long ans; 
int t,cv,cu,cc,n,m,f[500011][25],d[500011],sum;
vector<int> v[500011];
queue<int> q;
void bfs(){
	q.push(1);d[1] = 1;
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			int to = v[out][i];
			if(d[to]) continue;
			d[to] = d[out]+1;
			f[to][0] = out;
			for(int j = 1;j <= t;j++)
				f[to][j] = f[f[to][j-1]][j-1];
			q.push(to);
		}
	}
}
int lca(int x,int y){
	if(d[x] > d[y]) swap(x,y);
	for(int i = t;i >= 0;i--)
		if(d[f[y][i]] >= d[x]) y = f[y][i];
	if(x == y) return x;
	for(int i = t;i >= 0;i--)
		if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	return f[x][0];
}

int main(){
	scanf("%d%d",&n,&m);
	t = log2(n)+1;	
	for(int i = 1;i < n;i++){
		scanf("%d%d",&cu,&cv);
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	bfs();
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&cv,&cu,&cc);
		int t1 = lca(cv,cu);
		int t2 = lca(cv,cc);
		int t3 = lca(cu,cc);
		if(t1 == t2) sum = t3;
		if(t1 == t3) sum = t2;
		if(t2 == t3) sum = t1;
		ans = d[cv]+d[cu]+d[cc]-d[t1]-d[t2]-d[t3];
		cout << sum << " " << ans << endl;
	}
	return 0;
}
