#include <bits/stdc++.h>
using namespace std;
int n,m,k,r,c[201],cw[201],w[201],f[201],t1,ans;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	cin >> n >> m >> k >> r;
	t1 = 1e9;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= m;i++) cin >> cw[i];
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
		for(int j = r;j >= cw[i];j--){
			f[j] = max(f[j],f[j-cw[i]]+w[i]);
			if(f[j] >= k)
				t1 = min(t1,j);
		}
	t1 = r-t1; 
	sort(c+1,c+1+n,cmp);
	for(int i = 1;i <= n;i++)
		if(t1 > c[i]){
			ans++;
			t1-=c[i];
		}else break;
	cout << ans;
	return 0;
}
