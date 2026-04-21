#include <bits/stdc++.h>
using namespace std;
int n,a[10001],f[1001][10001],ans;
int main(){
	while(cin >> n){
		for(int i = 1;i <= n;i++) 
			cin >> a[i];
		for(int len = 3;len <= n;len++)
			for(int i = 1;i <= n;i++){
				int j = i+len-1;
				if(j > n) break;
				f[i][j] = 1e8;
				for(int k = i+1;k <= j-1;k++)
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]+a[i]*a[j]*a[k]);
			}
			
		cout << f[1][n] << endl;
	}
	return 0;
}
