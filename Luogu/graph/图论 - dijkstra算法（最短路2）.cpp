/*
dijkstra:只能对单元点进行最短路算法 
思路：
ps:设单元点为num 
预处理：d[i] = i;
		d[num] = 0; 
1. 只保留点,每次从d值最小的点(第一次为num点)开始如下循环：
   1. 每次找d最小的点，更新他的子节点的d值（保证d值最小） ---- G:priority_queue + 存相反数实现小根堆 
   2. 删去该点，queue加边
2.END 
*/
#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to,w;
};
bool f[100001];
int m,n,cv,cu,cw,d[100001];
vector<edge> v[100001];
priority_queue<pair<int,int> > q;//first->d; second->num; 
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu >> cw;
		edge in;in.to = cu;in.w = cw;
		v[cv].push_back(in);
		in.to = cv;
		v[cu].push_back(in);
	}//存图
	for(int i = 1;i <= n;i++)
		d[i] = 1e8;//初始d为inf 
	for(int i = 0;i <= (int)v[1].size()-1;i++)
		d[v[1][i].to] = v[1][i].w;//处理父节点的所有邻居的初始值
	d[1] = 0;//父节点已处理 
	q.push(make_pair(0,1));
	while(!q.empty()){//开始算法 
		int x = q.top().second;//找d最小,取出序号 
		q.pop();
		if(f[x] == 1) continue;//保证只走一次 
		f[x] = 1;
		for(int i = 0;i <= (int)v[x].size()-1;i++){//扫描当前节点的邻居 
			if(d[v[x][i].to] == 1e8) d[v[x][i].to] = d[x] + v[x][i].w;//未访问过,处理d数组：当前权重+累计权重 
			if(d[v[x][i].to] >= d[x] + v[x][i].w) {//若目标节点不是最优解 
				d[v[x][i].to] = d[x] + v[x][i].w;//更新 
				q.push(make_pair(-d[v[x][i].to]/*找最小存相反数*/,v[x][i].to));//加入待测队列
			}
		}
	}
	for(int i = 1;i <= n;i++)
		cout << d[i] << " ";
	return 0;
}
