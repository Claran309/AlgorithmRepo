#include <bits/stdc++.h>
using namespace std;
int a[1001],f[1001],tf,tr;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
	    cin >> a[i];
	    f[i] = f[i-1] + a[i];
	}
	for(int i = 1;i <= m;i++) {
		cin >> tf >> tr;
		cout << f[b] - f[a-1];
	}
	return 0;
}
