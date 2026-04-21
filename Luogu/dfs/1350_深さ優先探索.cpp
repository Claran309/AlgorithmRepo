#include <bits/stdc++.h>
using namespace std;
int n,m,ma[501][501],visit[501][501],sx,sy,ex,ey;
char in;
int dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0};
void dfs(int x,int y){
	if(ma[x][y] == 2 || x < 1 || y < 1 || x > n || y > n) return ;
	if(ma[x][y] == 3){
		cout << "Yes";
		exit(0);
	}
	for(int i = 1;i <= 4;i++){
		int xx = dx[i] + x,yy = dy[i] + y;
		if(visit[xx][yy] == 0){
			visit[xx][yy] = 1;
			dfs(xx,yy);
			visit[xx][yy] = 0;
		}
	}
}
int main(){
	memset(ma,2,sizeof(ma));
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	for(int j = 1;j <= m;j++){
		cin >> in;
		if(in == 's'){
			ma[i][j] = 0;
			sx = i;
			sy = j;
		}
		else if(in == 'g'){
			ma[i][j] = 3;
			ex = i;
			ey = j; 
		}
		else if(in == '.') ma[i][j] = 1;
		else if(in == '#') ma[i][j] = 2;
	}
	dfs(sx,sy);
	cout << "No";
	return 0;
} 
