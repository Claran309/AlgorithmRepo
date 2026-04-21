#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,r,to[1000001],ans,minn;
vector<ll> v[1000001];
priority_queue<ll> q;
int main(){
	cin >> n >>m;
	for(ll i = 1;i <= m;i++){
		cin >> l >> r;
		v[l].push_back(r);
		to[r]++;
	}
	minn = 1e8;
	for(ll i = 1;i <= n;i++)
		if(to[i] == 0) q.push(i);
	for(int i = 1;i <= n;i++){
		ll x = q.top();
		q.pop();
		for(ll i = 0;i <= (ll)v[x].size()-1;i++){
			ll y = v[x][i];
			to[y]--;
			if(to[y] == 0) q.push(y);
		}
		minn = min(minn,x);
		ans += minn;
	}
	cout << ans;
	return 0;
}
