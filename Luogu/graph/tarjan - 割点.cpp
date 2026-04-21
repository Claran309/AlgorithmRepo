#include <bits/stdc++.h>
using namespace std;
int rot,n,m,head[10000001],ver[10000001],nex[10000001],cv,cu,cnt,dfn[10000001],low[10000001],cut[10000001],ans;
void add(int u,int v){
	ver[cnt] = v;
	nex[cnt] = head[u];
	head[u] = cnt++;
}
void tarjan(int u){
	dfn[u] = low[u] = ++cnt;//初始化 
	int flag = 0;//用于根节点特殊性质的特判 
	for(int i = head[u];i != -1;i = nex[i]){
		int v = ver[i];
		if(!dfn[v]){//若该边在搜索树上 
			tarjan(v);//往下搜 
			low[u] = min(low[u],low[v]);//维护1 
			if(low[v] >= dfn[u]){//判定可以割点 (该点为环上时间戳最小的点->即连着外边与环的点，必然为割点) 
				flag++; 
				if((u != rot || flag > 1) && (cut[u] != true)){ 
					cut[u] = true;//根节点需要两次该性质所以特判 
					//cout << u << " " << flag <<endl;
					ans++; 
				} 
			}
		}else//走父节点更新或走访问过的点更新 
			low[u] = min(low[u],dfn[v]);//维护2 
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
	for(int i = 1;i <= n;i++)
		if(dfn[i] == 0){
			rot = i;
			tarjan(i);
		}
	cout << ans << endl;
	for(int i = 1;i <= n;i++)
		if(cut[i]) cout << i << " ";
	return 0;
}
