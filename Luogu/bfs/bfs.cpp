#include <bits/stdc++.h>
using namespace std;
int n,m,ex,ey,sx,sy,dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0},xx,yy;
char ma[101][101];
struct point{
	int x,y;
};
queue<point> q;
void bfs(int x,int y){
	point t,neww,f;
	f.x = x; f.y = y;
	q.push(f);
	while(!q.empty()){
		t = q.front();
		q.pop();
		for(int i = 1;i <= 4;i++){
			xx = dx[i] + t.x; yy = dy[i] + t.y;
			if(ma[xx][yy] == '.' || ma[xx][yy] == 'T'){
				ma[xx][yy] = ma[t.x][t.y] + 1;
				neww.x = xx; neww.y = yy;
				q.push(neww);
			}
		}
	}
	if(ma[ex][ey] == 'T') cout << -1;
	else cout << (int)ma[ex][ey];
}
/*
4
4
XSXX
...X
XX.X
XX.T
*/
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> ma[i][j];
			if(ma[i][j] == 'S'){
				sx = i;
				sy = j;
				ma[i][j] = 0;
			}else if(ma[i][j] == 'T'){
				ex = i;
				ey = j;
			}
		}
	}
	bfs(sx,sy);
	//for(int i = 1;i <= n;i++){
	//	for(int j = 1;j <= m;j++) cout << ma[i][j] << " ";
	//	cout << endl;
	//}
	return 0;
}
