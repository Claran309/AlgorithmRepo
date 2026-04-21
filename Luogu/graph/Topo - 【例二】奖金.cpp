#include <bits/stdc++.h>
using namespace std;
int n,m,cv,cu,r[10001],value[10001],ans,cnt;
vector<int> v[10001];
int main(){
	cin >> n >> m;
	cnt = n;
	for(int i = 1; i<= m;i++){
		cin >> cv >> cu;
		v[cu].push_back(cv);
		r[cv]++;
	}
	queue<int> q;
	for(int i = 1;i <= n;i++) if(!r[i]) {
		q.push(i); value[i] = 100;
	}
	while(!q.empty()){
		int out = q.front();
		q.pop();
		cnt--;
		for(int i = 0; i<= (int)v[out].size()-1;i++){
			r[v[out][i]]--;
			if(!r[v[out][i]]){
				q.push(v[out][i]);
				value[v[out][i]] = value[out]+1;
			}
		}
	}
	if(cnt){
		cout << "Poor Xed";
		return 0;
	}
	for(int i = 1;i <= n;i++)
		ans += value[i];
	cout << ans;
	return 0;
}
