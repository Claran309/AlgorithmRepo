#include <bits/stdc++.h>
using namespace std;
stack<int> st;
queue<int> q;
int sum[10000001],scc[10000001],d[10000001],ans,in[1000001],out[10000001],hc[10000001],vc[10000001],nc[10000001],cnt,tmp,ins[10000001],dfn[10000001],low[1000001],n,m,cv,cu,head[10000001],ver[10000001],nex[10000001],c[10000001];
void add(int u,int v){
	ver[cnt] = v;
	nex[cnt] = head[u];
	head[u] = cnt++;
}
void add_c(int u,int v){
	vc[cnt] = v;
	nex[cnt] = hc[u];
	hc[u] = ++cnt;
}
int tarjan(int u){
	cout << "?";
	dfn[u] = low[u] = ++cnt;
	st.push(u);ins[u] = 1;//加点入栈并记录
	for(int i = head[u];i;i = nex[i]){
		cout << "!";
		int v = ver[i];
		if(!dfn[v]){//在搜索树上
		cout <<"@";
			tarjan(v);//go on
			low[u] = min(low[u],low[v]); 
		}else if(ins[ver[i]])//在栈中，可以更新
			low[u] = min(low[u],dfn[v]);
		cout << "^";
	}
	if(dfn[u] == low[u]){//满足性质
		tmp++;
		do{	
			c[st.top()] = tmp;//c存储点所对应强连通分量编号 
			scc[tmp]+=d[st.top()];//scc存强连通分量total w 
			ins[st.top()] = false;//标记出栈 
			st.pop();
		}while(u != st.top());//弹到自己为止 
	}
}
int main(){
	cin >> n >> m;
	cnt = 1;
	for(int i = 1;i <= n;i++) cin >> d[i];
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		add(cv,cu);
	}
	cnt = 0;
	tarjan(1);
	cnt = 0;
	for(int x = 1;x <= n;x++)
		for(int i = head[x];i;i = nex[i]){
			int v = ver[i];
			if(c[x] == c[v]) continue;
			add_c(c[x],c[v]);//建立缩点后新图 
			out[c[x]]++;
			in[c[v]]++;
		}
	//Topo -> map_c
	for(int i = 1;i <= n;i++)
		if(in[i] == 0){
			q.push(i);
			sum[i] = scc[i];
		}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i = hc[t];i;i = nc[i]){
			int v = vc[i];
			in[v]--;
			sum[v] = max(sum[v],sum[t]+scc[v]);
			if(in[v] == 0) q.push(v);
		}
	}
	for(int i = 1;i <= n;i++)
		ans = max(ans,sum[i]);
	cout << ans;
}
