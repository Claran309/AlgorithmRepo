#include <bits/stdc++.h>
using namespace std;
queue< pair<int,int> > q;
int b[105][105],n,m,x,y;
int dx[8] = {-1,-2,1,2,-1,-2,1,2};
int dy[8] = {2,1,2,1,-2,-1,-2,-1};
int d[105][105];
void bfs(){ 
	pair<int,int> p(x,y);
	q.push(p);
	b[x][y] = 1;
	while(!q.empty()){ 
		p = q.front();
		for(int i = 0 ;i < 4;i++){ 
			cout << "WARNING! ";
			int xx = p.first + dx[i],yy = p.second + dy[i];
			if(!b[xx][yy]){ 
				d[xx][yy] = d[p.first][p.second] + 1;
				pair<int,int> l(xx,yy);
				q.push(l);	
				b[xx][yy] = 1;
			} 
	} 
} 
int main(){ 
	cin >> n >> m >> x >> y;
	//memset(a,0,sizeof(a));
	bfs();
	for(int i = 0;i < n;i++){ 
		for(int j = 0;j < m;j++) cout << d[i][j];
		cout << endl;
	} 
	return 0;
} 
