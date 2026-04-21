
#include <bits/stdc++.h>
using namespace std;
int n,m,cv,cu,again[1000001],d[1000001],f[1000001],ans[100001];
const int mod = 100003;
vector<int> v[1000001];
priority_queue<pair<int,int> > q;
int main(){
	cin >> n >>m;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		if(again[cv] == cu) continue;
		again[cv] = cu;
		if(cv == cu) continue;
		v[cv].push_back(cu);
		v[cu].push_back(cv);
	}
	memset(d,0X3f,sizeof(d));
//	for(int i = 0;i <= (int)v[1].size()-1;i++)
//		d[v[1][i]] = 1;
	d[1] = 0;
	ans[1] = 1;
	q.push(make_pair(0,1));
	while(q.size()){
		int x = q.top().second;
		q.pop();
		if(f[x]) continue;
		f[x] = 1;
		for(int i = 0;i <= (int)v[x].size()-1;i++){
			if(d[v[x][i]] > 1+d[x]){
				d[v[x][i]] = 1+d[x];
				ans[v[x][i]] = ans[x];
				q.push(make_pair(-d[v[x][i]],v[x][i]));
			} else if(d[v[x][i]] == 1+d[x]){
				ans[v[x][i]] += ans[x];
				ans[v[x][i]] %= mod;
			}
			/*
			if(d[v[x][i]] >= 1+d[x]){
				if(d[v[x][i]] > 1+d[x])
					ans[v[x][i]] = ans[x];
				if(d[v[x][i]] == 1+d[x]){
					ans[v[x][i]] += ans[x];
					ans[v[x][i]] %= mod;
				}
				d[v[x][i]] = 1+d[x];
				q.push(make_pair(-d[v[x][i]],v[x][i]));
			} 
			*/
		}
	}	
	for(int i = 1;i <= n;i++)
		cout << ans[i] << endl;
	return 0;
} 

