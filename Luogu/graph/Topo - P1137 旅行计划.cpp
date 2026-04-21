#include <bits/stdc++.h>
using namespace std;
int n,m,cv,cu,r[1000001],d[1000001];
vector<int> v[1000001];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		v[cv].push_back(cu);
		r[cu]++;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(!r[i]) 
			q.push(i);
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			r[v[out][i]]--;
			d[v[out][i]] = d[out]+1;
			if(!r[v[out][i]]) q.push(v[out][i]);
		}
	}  
	for(int i = 1;i <= n;i++) cout << d[i]+1 << endl;//都少加了一个城市一 
	return 0;
} 
