#include <bits/stdc++.h>
using namespace std;
long long n,v,a[10001],f[1000001],ans;
int main(){
	cin >> n >>v;
	for(int i = 1;i <= n;i++) cin >> a[i];
	f[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = a[i];j <= v;j++){
			f[j] += f[j-a[i]];
		}
	}
	cout <<f[v];
	return 0;
}
