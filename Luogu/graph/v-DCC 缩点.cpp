#include <bits/stdc++.h>
using namespace std;
int c[10000001],new_id[10000001],rot,n,m,head[10000001],ver[10000001],nex[10000001],cv,cu,ccnt,cnt,vc[10000001],hc[10000001],nc[10000001],dfn[10000001],low[10000001],cut[10000001];
vector<int> dcc[1000001];//结果 
stack<int> st;
void add(int u,int v){
	if(u == v) return;
	ver[cnt] = v;
	nex[cnt] = head[u];
	head[u] = cnt++;
} 
void add_c(int u,int v){
	vc[cnt] = v;
	nc[cnt] = hc[u];
	hc[u] = cnt++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;
	st.push(u);//新节点入栈 
	if(u == rot && head[u] == -1){//防止孤点 
		dcc[++ccnt].push_back(u);
		return;
	}
	int flag = 0;
	for(int i = head[u];i != -1;i = nex[i]){
		int v = ver[i];
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]){
				flag++; 
				if(u != rot || flag > 1)
					cut[u] = true;
				ccnt++;
				int z;
				do{
					z = st.top();
					st.pop();//直到y为止(不包含y) 
					dcc[ccnt].push_back(z);//点双联通分量 
				}while(z != v);
				dcc[ccnt].push_back(u);
			}
		}else
			low[u] = min(low[u],dfn[v]);
	}
}
int find(int x){
	if(x != father[x]) father[x] = find(father[x]);
	return father[x];https://zkg.me/api/picshow
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
		if(dfn[i] == 0){
			rot = i;
			tarjan(i);
		}
	/*
	cout << ccnt << endl;
	for(int i = 1;i <= ccnt;i++){
		cout << (int)dcc[i].size() << " ";
		for(int j = 0;j <= (int)dcc[i].size()-1;j++)
			cout << dcc[i][j] << " ";
		cout << endl;
	}
	*/	 
	int num = cnt; 
	for(int i = 1;i <= n;i++)
		if(cut[i]) new_id[i] = ++num;
	for(int i = 1;i <= cnt;i++)
		for(int j = 0;j <= (int)dcc[i].size()-1;j++){
			int v = dcc[i][j];
			if(cut[v]){
				add_c(i,new_id[v]);
				add_c(new_id[v],i);
			}else c[v] = i;
		}
	
	return 0;
}
