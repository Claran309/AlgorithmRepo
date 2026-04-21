#include <bits/stdc++.h> 
using namespace std;
int a1,b1,a2,b2,m[101][101],d[101][101],dx[12] = {2,2,-2,-2,-1,-2,-2,-1,1,2,2,1},dy[12] = {2,2,-2,-2,-2,-1,-1,-2,2,1,1,2};
void bfs(int x,int y);
int main(){
	cin >> a1 >> b1 >> a2 >> b2;
	bfs(a1,b1);
	cout << d[1][1] << endl;
	bfs(a2,b2);
	
	cout << d[1][1];for(int i = 1;i <= 18;i++){
		for(int j = 1;j <= 10;j++) cout << d[i][j] << " ";
		cout << endl;
	}cout << endl;
	return 0;
}
void bfs(int x,int y){
	memset(d,0X3f,sizeof(d));
	queue<pair<int,int> > que;
	que.push(make_pair(x,y));
	d[x][y] = 0;
	while(!que.empty()){
		pair<int,int> out = que.front();
		que.pop();
		for(int i = 0;i < 12;i++){
			int xx = out.first + dx[i],yy = out.second + dy[i];
			if(d[xx][yy] == 1061109567 && xx <= 100 && yy <= 100 && xx > 0 && yy > 0){
				d[xx][yy] = d[out.first][out.second] + 1;
				que.push(make_pair(xx,yy));
			}
		}
	}
}
/*
12 16
18 10

8
9
*/
