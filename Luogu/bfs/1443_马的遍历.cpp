#include <bits/stdc++.h>
using namespace std;
const int maxn=500;

queue<pair<int,int> >q;

bool vis[maxn][maxn];
int n,m,sx,sy,len[maxn][maxn];
int dis[8][2]={1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1}; 


void bfs(){
	q.push(make_pair(sx,sy));
	vis[sx][sy]=1; 
	while(!q.empty()){	
		int x=q.front().first;
		int y=q.front().second; 
		q.pop(); 	
		for(int i=0;i<8;i++){
			int dx=x+dis[i][0];
			int dy=y+dis[i][1];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&!vis[dx][dy]){
				vis[dx][dy]=1;
				len[dx][dy]=len[x][y]+1;
				q.push(make_pair(dx,dy));			
			}
		}	
	}	
}
int main(){
	cin>>n>>m>>sx>>sy;
	memset(len,-1,sizeof(len));
	len[sx][sy]=0;
	bfs(); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)	
		if(len[i][j] >= 0 && len[i][j] <= 9)
			cout << len[i][j] << "    ";
		else if(len[i][j] == -1 || (len[i][j] > 9 && len[i][j] <= 99))cout << len[i][j] << "   ";
		else cout << len[i][j] << "  ";
		cout<<endl;	
	}
}
