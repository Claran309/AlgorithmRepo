#include <bits/stdc++.h>
using namespace std;
int m,n,a[10000];
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a+n);
	cout << a[m-1];
	return 0;
}
