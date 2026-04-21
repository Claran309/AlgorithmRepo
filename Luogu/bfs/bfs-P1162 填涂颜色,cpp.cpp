#include <bits/stdc++.h>
using namespace std;
long long m[31][31],n,sx,sy,p[31][31],dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0};
long long main(){
	cin >> n;
	for(long long i = 1;i <= n;i++)
		for(long long j = 1;j <= n;j++){
			cin >> m[i][j];
			if(m[i][j] == 1){
				sx = i-1,sy = j-1;
				p[i][j] = 1;
			}
		}
	queue<pair<long long,long long> > que;
	que.push(make_pair(sx,sy));
	p[sx][sy] = 1;
	while(!que.empty()){
		pair<long long,long long> out;
		out = que.front();
		que.pop();
		m[out.first][out.second] = 2;
		for(long long i = 1;i <= 4;i++){
			long long xx = out.first + dx[i],yy = out.second + dy[i];
			if(!p[xx][yy]){
				p[xx][yy] = 1;
				que.push(make_pair(xx,yy));
			}
		}
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = 1;j <= n;j++) cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}
