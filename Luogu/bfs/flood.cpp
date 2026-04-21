#include <bits/stdc++.h>
using namespace std;
int dx[5] = {0,0,0,-1,1},dy[5]={0,1,-1,0,0};
int wcnt=1,d[1001][1001],n,m,sx,sy,ex,ey,wx[1001],wy[1001],time_water[1001][1001];
char p[1001][1001];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			cin >> p[i][j];
			if(p[i][j] == 'S'){
				sx = i;sy = j;
			}else if(p[i][j] = 'D'){
				ex = i;ey = j;
			}else if(p[i][j] = '*'){
				wx[wcnt]=i;
				wy[wcnt]=j;
				wcnt++;
			}
		}
	memset(time_water,0x3f,sizeof(time_water));
	for(int i = 1;i <= wcnt;i++){//存每个地块最短的被淹没时间 bfs1 爆？！？ 
		memset(d,0,sizeof(d));
		queue<pair<int,int> > q;
		q.push(make_pair(wx[i],wy[i]));
		d[wx[i]][wy[i]] = 1;
		time_water[wx[i]][wy[i]] = 0; 
		while(!q.empty()){
			pair<int,int> out = q.front();
			q.pop();
			for(int j = 1;j <= 4;i++){
				int xx = out.first + dx[j],yy = out.second + dy[j];
				if(d[xx][yy]==0){
					d[xx][yy] = 1 + d[out.first][out.second];
					time_water[xx][yy] = min(time_water[xx][yy],d[xx][yy]-1);
					q.push(make_pair(xx,yy));
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++) cout << time_water[i][j] << " ";
		cout << endl;
	}
	
	return 0;
} 
