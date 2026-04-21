#include <bits/stdc++.h>
using namespace std;
struct edge{
	int next,w;
};
int start,n,m,cv,cu,cw,d[100001];
bool f[100001];
vector<edge> v[100001];
priority_queue<pair<int,int> > q;
int main(){
	cin >> n >> m >> start;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu >> cw;
		edge in;in.next = cu;in.w = cw;
		v[cv].push_back(in);
	}
	memset(d,0X3f,sizeof(d));
	//初始化 
	for(int j = 0;j <= (int)v[start].size()-1;j++)
		d[v[start][j].next] = v[start][j].w; 
	d[start] = 0;
	q.push(make_pair(0,start));//0表示w，1为i 
	while(q.size()){
		//找最小
		int x = q.top().second;
		q.pop();
		if(f[x]) continue;
		//修改值 
		f[x] = 1;
		for(int j = 0;j <= (int)v[x].size()-1;j++){
			if(d[v[x][j].next] == 1061109567) d[v[x][j].next] = v[x][j].w+d[x];
			if(d[v[x][j].next] >= v[x][j].w+d[x]){
				d[v[x][j].next] = v[x][j].w + d[x];
				q.push(make_pair(-d[v[x][j].next],v[x][j].next));
			}
		}
	}	
	for(int i = 1;i <= n;i++)
		if(d[i] == 1061109567) cout << 2147483647 << " ";
		else cout << d[i] << " ";
	 
	return 0;
}
