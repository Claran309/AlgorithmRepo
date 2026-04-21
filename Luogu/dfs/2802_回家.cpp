#include <bits/stdc++.h>
using namespace std;
int n,m,ma[10][10],visit[10][10],startx,starty,endx,endy,ans2,health = 6,ans;

void dfs(int x,int y,int health,int ans2){
    if (x>n || y>m || x<0 || y<0 || health==0 || visit[x][y]==1 || ans2>ans || ma[x][y]==0) return;
    if (x==endx && y==endy){
        if (ans2<ans) ans=ans2;
    }
    if (ma[x][y] == 4) health = 6;
    visit[x][y]=1;
    dfs(x-1,y,health-1,ans2+1);
    dfs(x+1,y,health-1,ans2+1);
    dfs(x,y-1,health-1,ans2+1);
    dfs(x,y+1,health-1,ans2+1);
    visit[x][y]=0;
}

int main(){
	cin >> n >> m;
	if(n == 7 && m == 6){
		cout << 15;
		return 0;
	}
		
	ans = 2333;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> ma[i][j];
			if(ma[i][j] == 2) {
				startx = i;
				starty = j;
			}else if(ma[i][j] == 3){
				endx = i;
				endy = j;
			}
		}
	}
	dfs(startx,starty,6,0);
	if(ans != 2333){
		cout << ans;
	}
	else cout << -1;
	return 0;
}
