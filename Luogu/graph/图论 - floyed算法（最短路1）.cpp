#include <bits/stdc++.h>
using namespace std;
struct edge{
	int next;
	int w;
};
int n,m,s,e,cv,u,inw,d[1001][1001];
vector<edge> v[1001]; 
int main(){
	memset(d,0X3f,sizeof(d));
	cin >> n >> m;
	cin >> s >> e;
	for(int i = 1;i <= m;i++){
		cin >> cv >> u >> inw;
		edge in;in.next = u;in.w = inw;
		v[cv].push_back(in);
		in.next = cv;
		v[u].push_back(in);
	}
	for(int i = 1;i <= n;i++){//初始化 
		for(int j = 1;j <= n;j++){
			for(int x = 0;x <= (int)v[i].size();x++){
				if(v[i][x].next == j) d[i][j] = v[i][x].w;
				if(i == j) d[i][j] = 0;
			}
		}
	}
	for(int k = 1;k <= n;k++)//算法核心 
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				d[i][j] = min(d[i][j],(d[i][k] + d[k][j]));//核心语句 
	cout << d[s][e]; 
	return 0;
}
/*
5 6
1 5
1 2 23
1 5 49
2 3 5
2 4 13
4 5 7
1 3 17

42
*/
