#include <bits/stdc++.h>
using namespace std;
stack<int> st;
vector<int> scc[10001];
int cnt,tmp,ins[10000001],dfn[10000001],low[1000001],n,m,cv,cu,head[10000001],ver[10000001],nex[10000001],c[10000001];
void add(int u,int v){
	ver[cnt] = v;
	nex[cnt] = head[u];
	head[u] = ++cnt;
}
int tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	st.push(u);ins[u] = 1;//加点入栈并记录
	for(int i = head[u];i;i = nex[i]){
		int v = ver[i];
		if(!dfn[v]){//在搜索树上
			tarjan(v);//go on
			low[u] = min(low[u],low[v]); 
		}else if(ins[ver[i]])//在栈中，可以更新
			low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u]){//满足性质
		tmp++;
		do{	
			c[st.top()] = tmp;//c存储点所对应强连通分量编号 
			scc[tmp].push_back(st.top());//scc存强连通分量包含那些点 
			ins[st.top()] = false;//标记出栈 
			st.pop();
		}while(u != st.top());//弹到自己为止 
	}
}
int main(){
	cin >> n >> m;
	cnt = 1;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		add(cv,cu);
	}
	cnt = 0;
	tarjan(1);
}
