#include <bits/stdc++.h>
using namespace std;
long long f[100000];
int main(){ 
	f[1] = 1;
	f[2] = 2;
	for(int i = 3;i <= 100000;i++){
		f[i] = f[i-1] + f[i-2];
	}
	long long n;
	cin >> n;
	cout << f[n] << endl;
	return 0;
} 
//高精
//此程序60分 
