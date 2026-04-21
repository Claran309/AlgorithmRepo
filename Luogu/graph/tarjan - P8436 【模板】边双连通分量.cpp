#include <bits/stdc++.h>
using namespace std;
int visit3[10000001],cnt,n,visit2[10000001],m,dfn[10000001],cut[10000001],visit[10000001],low[10000001],cv,cu,head[10000001],ver[10000001],nex[10000001],flag,ans;
void add(int u,int v){
	ver[cnt] = v;
	nex[cnt] = head[u];
	head[u] = cnt++;
}
void tarjan(int u,int in_edge){
	dfn[u] = low[u] = ++cnt;
	for(int i=head[u];i!=-1;i=nex[i]){
		int v = ver[i];
		if(!dfn[v]){
			tarjan(v,i);
			low[u] = min(low[u],low[v]);
			if(low[v] > dfn[u])
				cut[i] = cut[i^1] = true;
		}else if(i != (in_edge ^ 1))
			low[u] = min(low[u],dfn[v]);
	}
}
void dfs2(int u,int fa){
	cout << u << " ";
	visit2[u] = 1;
	for(int i=head[u];i!=-1;i=nex[i]){
		int v = ver[i];
		if(visit2[v] == 0 && cut[i] == 0) dfs2(v,u);
	}
}
void dfs3(int u,int fa){
	visit3[u] = 1;
	for(int i=head[u];i!=-1;i=nex[i]){
		int v = ver[i];
		if(visit3[v] == 0 && cut[i] == 0) dfs3(v,u);
	}
}
void dfs(int u,int fa,int t){
	flag++;
	visit[u] = 1;
	for(int i=head[u];i!=-1;i=nex[i]){
		int v = ver[i];
		if(visit[v] == 0 && cut[i] == 0) dfs(v,u,t+1);
	}
}
int main(){
	cin >> n >> m;
	memset(head,-1,sizeof(head));
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		add(cv,cu);
		add(cu,cv);
	}
	cnt = 0;
	for(int i = 1;i <= n;i++)
		if(!dfn[i]) tarjan(i,0);
	for(int i = 1;i <= n;i++)
		if(visit3[i] == 0){
			dfs3(i,0);
			ans++;
		}
	cout << ans << endl;
	for(int i = 1;i <= n;i++)
		if(!visit[i]) {
			dfs(i,0,1);
			cout << flag << " ";
			dfs2(i,0); 
			flag = 0;
			cout << endl;
		}
	return 0;
}
