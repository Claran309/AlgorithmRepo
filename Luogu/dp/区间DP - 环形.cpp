#include <bits/stdc++.h>
using namespace std;
int n,a[3005],f[3005][3005],j,sum[305],ans;
int main(){
	ans = 1e9;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		a[n+i] = a[i];
	}
	for(int i = 1;i <= 2*n;i++){
		sum[i] = a[i];
		sum[i] += sum[i-1];
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= 2*n;i++) f[i][i] = 0;
	for(int len = 2;len <= n;len++)
		for(int i = 1;i <= 2*n;i++){
			int j = i+len-1;
			if(j-i+1 > n) break;
			for(int k = i;k < j;k++) 
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + sum[j]-sum[i-1]);
		}
	for(int i = 1;i <= n;i++)
		ans = min(ans,f[i][i+n-1]);
	cout <<ans;
	
	return 0;
} 
