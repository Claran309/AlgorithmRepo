#include <bits/stdc++.h>
using namespace std;
int cnttt = 1,cntt = 1,anss,cnt,xx,yy,n,m,a,b,ans[10001],ma[10001][501][501],xs[10001],ys[10001],dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0},visit[501][501];
struct point{
	int x,y;
};
queue<point> q;
void bfs(int x,int y){
	memset(visit,0,sizeof(visit));
	while(!q.empty()) q.pop();
	point t,neww,f;
	f.x = x; f.y = y;
	q.push(f);
	while(!q.empty()){
		t = q.front();
		q.pop();
		for(int i = 1;i <= 4;i++){
			xx = dx[i] + t.x; yy = dy[i] + t.y;
			if(ma[cnttt][xx][yy] != 1 && ma[cnttt][xx][yy] != -1 && visit[xx][yy] == 0){
				visit[xx][yy] = 1;
				ma[cnttt][xx][yy] = ma[cnttt][t.x][t.y] + 1;
				neww.x = xx; neww.y = yy;
				q.push(neww);
			}
		}
	}
}
int main(){ 
	cin >> n >> m >> a >> b;
	memset(ma,-1,sizeof(ma));
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) for(int t = 1;t <= a;t++) ma[t][i][j] = 0;
	for(int i = 1;i <= a;i++){
		cin >> xs[i] >> ys[i];
		for(int j = 1;j <= a;j++){ 
			ma[j][xs[i]][ys[i]] = 1;
			visit[xs[i]][ys[i]] = 1;
		} 
	}
	memset(xs,0,sizeof(xs));
	memset(ys,0,sizeof(ys));
	for(int i = 1;i <= b;i++){
		cin >> xs[i] >> ys[i];
	}
	for(int i = 1;i <= a;i++)
	for(int p = 1;p <= n;p++)
			for(int w = 1;w <= m;w++)
				if(ma[i][p][w] == 1){ bfs(p,w);cnttt++;} 
	for(int i = 1;i <= b;i++)	{ 
	for(int j = 1;j <= a;j++)
		for(int q = 1;q <= n;q++)
				for(int w = 1;w <= m;w++)
					if(q == xs[i] && w == ys[i]) {
						ans[cntt] = ma[j][q][w];
						cntt++;
					}
			anss = ans[1];
		for(int r = 1;r < cnt;r++){
			if(anss > ans[r]) anss = ans[r];
		} 
		cout << ans;
	} 
	return 0;
}
