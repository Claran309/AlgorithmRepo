#include <bits/stdc++.h>
using namespace std;
int v,n,rc,w[10001],c[10001],f[10001],ans;
int main(){
	cin >> v >> n >> rc;
	for(int i = 1;i <= n;i++) cin >> w[i] >> c[i];
	for(int i = 1;i <= n;i++)
		for(int j = rc;j >= c[i];j--){
			f[j] = max(f[j],f[j-c[i]]+w[i]);
			if(f[j] >= v)
				ans = max(ans,rc-j);
		}
	if(f[rc] < v)
		cout << "Impossible";
	else cout << ans;
	return 0;
}
