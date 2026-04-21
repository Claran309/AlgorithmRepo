#include <bits/stdc++.h>
using namespace std;
int f[100001],n,v,c[100001],w[100001],m[100001];
int main(){
	cin >> n >> v;
	for(int i = 1;i <= n;i++) {
		cin >> w[i] >> c[i] >> m[i];
	}
	for(int i = 1;i <= n;i++)
		for(int j = v;j >= 0;j--)
			for(int k = 1;k <= m[i];k++) 
				if(j >= k*c[i]) f[j] = max(f[j],f[j-k*c[i]]+k*w[i]);
				else break;
	cout << f[v];
	return 0;
}
