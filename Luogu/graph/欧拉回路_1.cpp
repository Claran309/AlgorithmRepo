#include <bits/stdc++.h>
using namespace std;
int n,m,cv,cu,head[10000001],ver[10000001],nex[10000001],cnt,visit[10000001],sta[10000001],top,t,ans[10000001],sum[10000001],ji;
stack<int> st;
void dfs(int u){//µÝ¹é°æ±¾ 
	for(int i = head[u];i != -1;i = head[u]){
//		if(visit[i] == 1) continue;
	//	visit[i] = visit[i^1] = true;
		int v = ver[i];
		head[u] = nex[i];//ÓÅ»¯ 
		dfs(v);
	}
	st.push(u);
}
void add(int x,int y){
	ver[cnt] = y;
	nex[cnt] = head[x];
	head[x] = cnt++;
}
int main(){
	cin >> n >> m;
	memset(head,-1,sizeof(head));
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		sum[cv]++;sum[cu]++;
		add(cv,cu);
	//	add(cu,cv);
	}
	for(int i = 1;i <= n;i++)
		if(sum[i]%2==1) ji++;
	if(ji != 2 && ji != 0){
		cout << "No" << endl;
		return 0;
	}
	dfs(1);//µÝ¹é°æ±¾ 
	while(!st.empty()){//µÝ¹é°æ±¾ 
		cout << st.top() << " ";
		st.pop();
	}
//	euler();
//	for(int i = t;i >= 1;i--) cout << ans[i] << " ";
	return 0;
} 
