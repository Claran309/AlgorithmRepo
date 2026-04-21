#include <bits/stdc++.h>
using namespace std;
struct stick{
	int w,l;
} a[5001];
int n,f[5001],ans;
bool cmp(stick x,stick y){
	if(x.l > y.l) return true;
	if(x.l == y.l) if(x.w > y.w) return true;
	return false;
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].l >> a[i].w;
		f[i] = 1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++)
		for(int k = 1;k <= i-1;k++){
			if(a[k].w >= a[i].w) continue; 
			f[i] = max(f[k]+1,f[i]);
			ans = max(ans,f[i]);
		}
	if(ans == 0) ans = 1;
	cout <<ans;
	return 0;
}
