#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,bottle[1000001],v[1000001],k,ans;
int main(){ 
	cin >> n >> k;
	for(ll i = 1;i <= n;i++){ 
		cin >> v[i];
		bottle[i] = v[i];
		bottle[i] += bottle[i-1];
		v[i] += bottle[i-1];
		if(i > k) v[i] -= bottle[i-k-1];
	} 
	ans = v[1];
	for(ll i = 1;i <= n;i++) 
		if(ans < v[i-1]) ans = v[i-1];
	//for(int i = 1;i <= n;i++) cout << v[i] << " ";
	cout << ans;
	return 0;
} 
