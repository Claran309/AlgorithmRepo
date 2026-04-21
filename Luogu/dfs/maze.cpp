#include <bits/stdc++.h>
using namespace std;
int n,m,startx,starty;
char ma[201][201];

void dfs(int x,int y,int ans){
	if(ma[x+1] == false && ma[x-1] == false && ma[y+1] == false && ma[y-1] == false || ma[x][y] == false) {
		cout << ans;
	}
	if(ma[x][y] == '*') ans++;
	ma[x][y] == false;
	dfs(x-1,y,ans);
	dfs(x+1,y,ans);
	dfs(x,y-1,ans);
	dfs(x,y+1,ans);
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> ma[i][j];
			if(ma[i][j] == 'S'){
				startx = i;
				starty = j;
			}if(ma[i][j] == '#'){
				ma[i][j] = false;
			}
		}
	}
	dfs(startx,starty,0);
	return 0;
}
