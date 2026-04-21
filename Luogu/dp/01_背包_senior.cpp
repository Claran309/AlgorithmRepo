#include <bits/stdc++.h>
using namespace std;
int f2[1000001],f[2][1000001],n,v,c[101],w[101];//滚动数组优化 
int main(){
	cin >> n >> v;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= v;j++)
			if(j >= c[i])
				f[i&1][j] = max(f[(i-1)&1][j],f[(i-1)&1][j-c[i]]+w[i]);
			else
				f[i&1][j] = f[(i-1)&1][j];//滚动数组优化 
		
	// 逆序优化为一维数组 
	for(int i = 1;i <= n;i++)
		for(int j = v;j >= c[i];j--)
			f2[j] = max(f2[j],f2[j-c[i]]+w[i]);
	cout << f[n&1][v] << " " << f2[v];
	return 0;
}
/*
4 20
8 9 5 2
5 6 7 3
*/
