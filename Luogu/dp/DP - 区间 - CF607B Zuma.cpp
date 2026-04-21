#include <bits/stdc++.h>
using namespace std;
int n,a[600],f[600][600];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= n;i++){ 
	   f[i][i] = 1;
	   if(i == n) break;
	   if(a[i] == a[i+1]) f[i][i+1] = 1;
	   else f[i][i+1] = 2;
	}
	for(int len = 3;len <= n;len++)
		for(int i = 1;i+len-1 <= n;i++){
			int j = i+len-1;
			if(a[i] == a[j]) f[i][j] = f[i+1][j-1];
			for(int k = i;k < j;k++)
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
		}
	cout << f[1][n];
	return 0;
}
