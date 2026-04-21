#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,ans = 0,flag = 0;
	cin >> n; int a[n+1];
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> m; int b[m+1];
	for(int j = 1;j <= m;j++) cin >> b[j];
	int check[n+m+1];
	for(int i = 1;i <= n;i++) check[i] = a[i];
	for(int i = n+1,j = 1;i <= n+m,j <= m;i++,j++) check[i] = b[j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			flag = 0;
			for(int o = 1;o <= n+m;o++)
				if(a[i] + b[j] == check[o])
					flag = 1;
			if(flag == 0) {
				flag = 1;
				ans++;
			}
		}
	cout << ans;
	return 0;
}
