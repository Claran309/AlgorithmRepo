#include <bits/stdc++.h>
using namespace std;
long long f[1001],n,r,l[1001],w[1001],dn[1001];
int main(){
	cin >> n >> r;
	for(int i = 1;i <= n;i++) cin >> l[i] >> w[i] >> dn[i];
	for(int i = 1;i <= n;i++)
		for(int j = r;j >= 0;j--)
			if(j >= dn[i])
				f[j] = max(f[j]+l[i],f[j-dn[i]]+w[i]);
			else f[j] += l[i];
	cout << f[r]*5;
	return 0;
}
