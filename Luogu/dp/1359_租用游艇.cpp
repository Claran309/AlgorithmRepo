#include <bits/stdc++.h>
using namespace std;
int f[201],n,r[201][201];
int main(){
	cin >> n;
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i < n;i++)
		for(int j = i;j <= n;j++)
			cin >> r[i][j];
	f[1] = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			f[i] = min(f[j]+r[j][i],f[i]);
	cout << f[n];
	return 0;
}
