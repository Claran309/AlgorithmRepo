#include <bits/stdc++.h>
using namespace std;
int n,m,head[10001],ver[10001],next[10001],cv,cu,cnt,dfn[10001],low[10001],bridge[10001];
void add(int u,int v){
	ver[cnt] = v;
	next[cnt] = head[u];
	head[u] = cnt++;
}
void tarjan(int u,int in_edge){
	dfn[u] = low[u] = ++cnt;//初始化 
	for(int i = head[u];i != -1;i = next[i]){
		int v = ver[i];
		if(!dfn[v]){//若该边在搜索树上 
			tarjan(v,i);//往下搜 
			low[u] = min(low[u],low[v]);//维护1 
			if(low[v] > dfn[u])//判定可以割边 (边不在环上) 
				bridge[i] = bridge[i^1] = true;
		}else if(i != (in_edge ^ 1)){//不在搜索树上的边且不往回走 
			low[u] = min(low[u],dfn[v]);//维护2 
		}
	}
}
int main(){
	cin >> n >> m;
	memset(head,-1,sizeof(head));//前向星初始化 
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		add(cv,cu);
		add(cu,cv);
	}
	cnt = 0;
	tarjan(1,0);
	return 0;
}
