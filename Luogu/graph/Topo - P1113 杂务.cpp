#include <bits/stdc++.h>
using namespace std;
int n,cv,cu,r[10001],t[10001],d[10001],ans;
vector<int> v[10001];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> cv >> t[i];
		d[i] = t[i];
		while(true){
			cin >> cu;
			if(cu == 0) break;
			v[cu].push_back(cv);
			r[cv]++;
		}
	}
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(!r[i]) q.push(i);
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			r[v[out][i]]--;
			if(d[out] + t[v[out][i]] > d[v[out][i]] || d[v[out][i]] == t[v[out][i]]) d[v[out][i]] = d[out] + t[v[out][i]];
			if(!r[v[out][i]]) q.push(v[out][i]);
		}
	}
	for(int i = 1;i <= n;i++)
		ans = max(ans,d[i]);
	cout << ans;
	return 0;
}
/*
5
0
4 5 1 0
1 0
5 3 0
3 0
*/
