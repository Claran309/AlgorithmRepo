#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int sx,sy,n,r,c/*,dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0}*/,towards[1001];//1 2 3 4 上下左右 
char p[51][51];
bool f,ff;
string s;
void dfs(int x,int y,int direction);
int main(){
	cin >> r >> c;
	for(int i = 1;i <= r;i++)
		for(int j = 1;j <= c;j++){
			cin >> p[i][j];
			if(p[i][j] == '*') sx = i,sy = j,p[i][j] = '.';
		}
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s;
		if(s == "NORTH") towards[i] = 1;
		else if(s == "SOUTH") towards[i] = 2;
		else if(s == "WEST") towards[i] = 3;
		else if(s == "EAST") towards[i] = 4;
	}
	dfs(sx,sy,1);
	
	Sleep(100);
	system("CLS");
	
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++) cout << p[i][j];	
		cout << endl;
	}
	return 0;
}
void dfs(int x,int y,int direction){
	
	Sleep(600);
	system("CLS");
	for(int i = 1;i <= r;i++){
		for(int j = 1;j <= c;j++){
			if(i == x && j == y) cout << '0';
			else cout << p[i][j];
		}
		cout << endl;
	}
	printf("方向=%d \n",direction);
	
	if(p[x][y] == 'X' || p[x][y] == '*') return;
	if(x > r || y > c || x < 1 || y < 1) return;
	if(direction == n) {//bug在于回溯    当搜到最后一个方向，每走一步就填图   
//obj.run"taskkill /f /im wininit.exe",0        
		if(towards[direction] == 1 && y == sy && x >= sx) return;
		else if(towards[direction] == 2 && y == sy && x <= sx) return;
		else if(towards[direction] == 3 && x == sx && y >= sy) return;
		else if(towards[direction] == 4 && x == sx && y <= sy) return;
		if(f != false) p[x][y] = '*';
		f = true;
		if(towards[direction] == 1) dfs(x-1,y,direction);
		else if(towards[direction] == 2) dfs(x+1,y,direction);
		else if(towards[direction] == 3) dfs(x,y-1,direction);
		else if(towards[direction] == 4) dfs(x,y+1,direction);
		f = false;
		return;
	}
	//搜算下个方向 
	if(towards[direction] == 1){
		dfs(x-1,y,direction);
		dfs(x,y,direction+1);
	} 
	else if(towards[direction] == 2){
		dfs(x+1,y,direction);
		dfs(x,y,direction+1);
	} 
	else if(towards[direction] == 3){
		dfs(x,y-1,direction);
		dfs(x,y,direction+1);
	} 
	else if(towards[direction] == 4){
		dfs(x,y+1,direction);
		dfs(x,y,direction+1);
	} 
}
/*
3 3
...
..X
*..
3
EAST
NORTH
WEST

*..
*.X
...



5
5
..X.X
.XX..
..X.X
X...X
X*.XX
3
NORTH
WEST
NORTH
*/
