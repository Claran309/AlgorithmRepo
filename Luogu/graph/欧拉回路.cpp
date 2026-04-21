#include <bits/stdc++.h>
using namespace std;
int n,m,cv,cu,head[1000001],ver[1000001],next[1000001],cnt,visit[1000001],sta[1000001],top,t,ans[1000001];
stack<int> st;
void dfs(int u){//递归版本 
	for(int i = head[u];i != -1;i = next[i]){
		if(visit[i] == 1) continue;
		visit[i] = visit[i^1] = true;
		int v = ver[i];
		head[u] = next[i];//优化 
		dfs(v);
	}
	st.push(u);
}
void euler(){//非递归版本（防止栈溢出） 
	sta[++top] = 1;
	while(top > 0){
		int x = sta[top],i = head[x];//找未访问的边 
		while(i != -1 && visit[i]) i = next[i];//模拟递归+标记&维护表头 
		if(i != -1){
			sta[++top] = ver[i];
			head[x] = next[i];
			visit[i] = visit[i^1] = true;
		}else{//模拟回溯 
			top--;
			ans[++t] = x;
		}
	}
}
void add(int x,int y){
	ver[cnt] = y;
	next[cnt] = head[x];
	head[x] = cnt++;
}
int main(){
	cin >> n >> m;
	memset(head,-1,sizeof(head));
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		add(cv,cu);
		add(cu,cv);
	}
//	dfs(1);//递归版本 
//	while(!st.empty()){//递归版本 
//		cout << st.top() << " ";
//		st.pop();
//	}
	euler();
	for(int i = t;i >= 1;i--) cout << ans[i] << " ";
	return 0;
} 
