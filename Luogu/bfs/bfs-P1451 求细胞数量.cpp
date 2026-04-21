#include <bits/stdc++.h>
using namespace std;
string s;
long long a,b,m[101][101],ans,dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0},p[101][101];
long long main(){
	cin >> a >> b;
	for(long long i = 1;i <= a;i++){ 
		cin >> s;
		for(long long o = 0;o < b;o++)
			m[i][o+1] = s[o] - 48;
	} 
	for(long long i = 1;i <= a;i++)
		for(long long j = 1;j <= b;j++)
			if(m[i][j]){
				queue<pair<long long,long long> > que;
				que.push(make_pair(i,j));
				m[i][j] = 0;
				while(!que.empty()){
					pair<long long,long long> out;
					out = que.front();
					que.pop();
					m[out.first][out.second] = 0;
					for(long long i = 1;i <= 4;i++){
						long long xx = out.first + dx[i],yy = out.second + dy[i];
						if(m[xx][yy])
							que.push(make_pair(xx,yy));
					}
				}
				ans++;
			}
	cout << ans;
	return 0;
}
/*
4 10
0 2 3 4 5 0 0 0 6 7
1 0 3 4 5 6 0 5 0 0
2 0 4 5 6 0 0 6 7 1
0 0 0 0 0 0 0 0 8 9
*/
