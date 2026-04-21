#include <bits/stdc++.h> 
using namespace std;
char in;
int a,b,m[1001][1001],jx,jy,hx,hy,d[1001][1001],p[1001][1001],dx[4] = {0,0,-1,1},dy[4] = {1,-1,0,0};
void bfs(int x,int y,int ex,int ey);
void change();
int main(){
	cin >> a >> b;
	for(int i = 1;i <= a;i++) 
		for(int j = 1;j <= b;j++){
		cin >> in;
		if(in == 'O') m[i][j] = 0;
		if(in == 'X') m[i][j] = 1;
	} 
	do{
		for(int i = 1;i <= a;i++)
			for(int j = 1;j <= b;j++) d[i][j] = m[i][j];
		cin >> jx >> jy >> hx >> hy;
		if(!jx && !jy && !hx && !hy) return 0;
		d[jx][jy] = 2;
		change();
		
		printf("\n");
		for(int i = 1;i <= a;i++){ 
			for(int j = 1;j <= b;j++) cout << d[i][j] << " ";
			cout <<endl;
		} 
		cout <<endl;
		
		if(d[hx][hy] == 2){
			cout << 0;return 0;
		}
		bfs(hx,hy,jx,jy);
	}while(jx != 0 && jy != 0 && hx != 0 && hy != 0);
	return 0;
}
void change(){
		int i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i++;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			j++;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			j--;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i--;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i++;j++;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i++;j--;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i--;j++;
		} 
		i = jx,j = jy;
		while(1){
			if(m[i][j] == 1 || i > a || j > b || i <= 0 || j <= 0) break;
			d[i][j] = 2;
			i--;j--;
		} 
}
void bfs(int x,int y,int ex,int ey){
	queue<pair<int,int> > que;
	que.push(make_pair(x,y));
	p[x][y] = 1;
	while(!que.empty()){
		pair<int,int> out = que.front();
		que.pop();
		for(int i = 0;i < 4;i++){
			int xx = out.first + dx[i],yy = out.second + dy[i];
			if(!p[xx][yy] && xx <= a && yy <= b && xx > 0 && yy > 0 && d[xx][yy] != 1){
				p[xx][yy] = p[out.first][out.second] + 1;
				if(d[xx][yy] == 2){
					cout << p[xx][yy] - 1 << endl;
					return;
				}
				que.push(make_pair(xx,yy));
			}
		}
	}
	if(p[ex][ey] == 0) cout << "Poor Harry" << endl;
	memset(p,0,sizeof(p));
}
