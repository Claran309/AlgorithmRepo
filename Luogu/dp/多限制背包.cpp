#include <bits/stdc++.h>
using namespace std;
int v1,v2,n,c1[55],c2[55],w[55],f[500][500];
int main(){
	cin >> v1 >> v2;
	cin >>n;
	for(int i = 1;i <= n;i++) cin >> c1[i] >> c2[i] >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j1 = v1;j1 >= c1[i];j1--)
			for(int j2 = v2;j2 >= c2[i];j2--)
				f[j1][j2] = max(f[j1][j2],f[j1-c1[i]][j2-c2[i]]+w[i]);
	cout << f[v1][v2];
	return 0;
} 
