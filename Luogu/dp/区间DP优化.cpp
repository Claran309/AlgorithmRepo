#include <bits/stdc++.h>
using namespace std;
int n,a[305],f[305][305],j,s[305][305],sum[305];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[i] = a[i],sum[i] += sum[i-1];
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 1;i <= n;i++) s[i][i] = i,f[i][i] = 0;
	for(int len = 2;len <= n;len++)
		for(int i = 1;i <= n;i++){
			j = i+len-1;
			if(j > n) break;
			for(int k = s[i][j-1];k <= s[i+1][j];k++)
				if(f[i][j] > f[i][k]+f[k+1][j]+sum[j]-sum[i-1]){
					f[i][j] = f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
					s[i][j] = k;
				}
		}	
	cout << f[1][n];
	return 0;
} 
