#include <bits/stdc++.h>
using namespace std;
int n,a[305],sum[305],f[305][305],j;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = a[i],sum[i] += sum[i-1];
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= n;i++) f[i][i] = 0;
	for(int len = 2;len <= n;len++)
		for(int i = 1;i <= n;i++){
			j = i+len-1;
			if(j > n) break;
			for(int k = i;k < j;k++)
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
		}
	cout << f[1][n];
	return 0;
} 
