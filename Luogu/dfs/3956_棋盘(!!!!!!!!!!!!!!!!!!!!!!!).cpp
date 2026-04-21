#include <bits/stdc++.h>
using namespace std;
int m,n,ma[101][1001],test[101][1001],visit[101][1001],c,sx,sy,ans = INT_MAX;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};
void dfs(int x,int y,int money,bool used){
	if(x < 1 || x > m || y < 1 || y > m) return ;
	if(test[x][y] < money) return ;
	if(ma[x][y] == 0 && used == false) return ;
	test[x][y] = money;
	if(money > ans) return ;//×îÓÅ¡ù 
	if(x == m && y == m){
		ans = money;
		return ;
	}
	cout << "x = " << x << " y = " << y << " money = " << money << " used = " << used << endl;
	//cout << "error";
	for(int i = 1;i <= 4;i++){
		int xx = x + dx[i],yy = y + dy[i];
		//cout << ma[xx][yy] << endl;
		if(visit[xx][yy] == 0){
			visit[xx][yy] = 1;
			cout << "xx = " << xx << " yy = " << yy << " ma[x][y] = " << ma[x][y] << " ma[xx][yy] = " << ma[xx][yy] << endl;
			if(ma[xx][yy] != 0){ 
			if(ma[xx][yy] = ma[x][y]){ 
				dfs(xx,yy,money,true);
			}else{ 
				dfs(xx,yy,money+1,true);
			} 
		}else{ 
			if(used == true){ 
				ma[xx][yy] = ma[x][y];
				dfs(xx,yy,money+2,false);
				ma[xx][yy] = 0;
			} 
		} 
		visit[xx][yy] = 0;
		} 
	} 
	if(x != m || y != m) ans = -1; 
}

int main(){//c2yellow,c1red,c0none
	memset(test,0x3f,sizeof(test)); 
	cin >> m >> n;
	for(int i = 1;i <= n;i++){
		cin >> sx >> sy >> c;
		ma[sx][sy] = c+1;
	}
	cout << "the map:" << endl;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++) cout << ma[i][j];
		cout << endl;
	}
	dfs(1,1,0,true);
	cout << ans;
	return 0;
}
