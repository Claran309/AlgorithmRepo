#include <bits/stdc++.h>
using namespace std;
int tens,ouo[10000],oo;
char s[100000];
int k = 2,mm[2001][2001],outp[1000000],ans,a,b,p[2001][2001],m[2001][2001],dx[5] = {0,0,0,-1,1},dy[5] = {0,1,-1,0,0};
int main(){
	cin >> a >> b;
	for(int i = 1;i <= a;i++){ 
		cin >> s;
		for(int j = 0;j < a;j++)
			m[i][j+1] = s[j] - 48;
	} 
	int q1,q2;
	for(int i = 1;i <= b;i++){
		cin >> q1 >> q2;
		if(mm[q1][q2] != 0){
			cout << outp[mm[q1][q2]] << endl;
			continue;
		}
		queue<pair<int,int> > que;
		que.push(make_pair(q1,q2));
		p[q1][q2] = 1;
		while(!que.empty()){
			pair<int,int> out = que.front();
			que.pop();
			tens = m[out.first][out.second];
			mm[out.first][out.second] = k;
			ans++;
			for(int i = 1;i <= 4;i++){
				int xx = out.first + dx[i],yy = out.second + dy[i];
				if(!p[xx][yy] && m[xx][yy] != tens/*01½»Ìæ*/ && xx <= a && yy <= a && xx > 0 && yy > 0){
					p[xx][yy] = 1;
					que.push(make_pair(xx,yy));
				}
			}
		}
		outp[k] = ans;
		k++;
		ouo[oo] = ans;
		oo++;
		ans = 0;
		memset(p,0,sizeof(p));
	}
	for(int i = 0;i <= oo;i++) cout << ouo[i] << endl;
	return 0;
}
