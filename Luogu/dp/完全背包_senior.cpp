#include <bits/stdc++.h>
using namespace std;
long long v,n,c[1000001],w[1000001],f[100000001];
int main(){
	cin >>v >> n;
	for(int i = 1;i <= n;i++) cin >> c[i] >>w[i];
	for(int i = 1;i <= n;i++)
		for(int j = c[i];j <= v;j++)
			f[j] = max(f[j],f[j-c[i]]+w[i]);
	cout << f[v];
	return 0;
} 
