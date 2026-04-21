#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
long long n,m,cv,cu,r[500001],in[500001],ans,p[500001],cnt;
vector<int> v[500001];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu;
		v[cu].push_back(cv);
		r[cv]++;
	}
	for(int i = 1;i<=n;i++)
		if((int)v[i].size() == 0) p[++cnt] = i;
	queue<int> q;
	for(int i = 1;i <= n;i++)
		if(!r[i]){
			q.push(i);
			in[i] = 1;
		}
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++){
			//cout << "front -> next" << out << " " << v[out][i] << "   yw = " << in[v[out][i]] << " give " << in[out];
			in[v[out][i]]+=in[out];
			in[v[out][i]]%=mod;
			//cout << " nw = " << in[v[out][i]] << endl;
			r[v[out][i]]--;
			if(!r[v[out][i]]) q.push(v[out][i]);
		}
	}
	for(int i = 1;i <= cnt;i++) ans += in[p[i]];
	cout << ans%mod;
	return 0;
}
