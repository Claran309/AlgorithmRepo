#include <bits/stdc++.h>
using namespace std;
int tot,c[10000001],vc[10000001],hc[10000001],nc[10000001],visit3[10000001],cnt,n,visit2[10000001],m,dfn[10000001],cut[10000001],visit[10000001],low[10000001],cv,cu,head[10000001],ver[10000001],nex[10000001],flag,ans;
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
void dfs(int u,int fa,int anc){
	c[u] = anc;
	visit2[u] = 1;
	for(int i=head[u];i!=-1;i=nex[i]){
		int v = ver[i];
		if(visit2[v] == 0 && cut[i] == 0) dfs(v,u,anc);
	}
}
void add_c(int u,int v){
	vc[cnt] = v;
	nc[cnt] = hc[u];
	hc[u] = cnt++;
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
	cout << ans << endl;
	for(int i = 1;i <= n;i++)//找边双联通 
		if(!visit[i]) {
			tot++;//集合点 
			dfs(i,0,tot); 
		}
	cnt = 1;
	for(int i = 2;i <= tot;i++){//缩点 
		int x = ver[i^1],y = ver[i];
		if(c[x] == c[y]) continue;
		add_c(c[x],c[y]);
	}
	return 0;
}
