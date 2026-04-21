// 完全错排公式：D[n] = (D[n-1]+D[n-2])*(n-1) yulhbur
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
    ll a[100] = {0,0,1,2},n;
    for(int i = 4;i <= 20;i++) a[i] = (i-1)*(a[i-1]+a[i-2]);
	cin >> n;
	cout << a[n];
	return 0;
} 
