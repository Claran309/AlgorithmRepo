#include <bits/stdc++.h>
using namespace std;
int a,b,p;
long long ans = 1;
int main(){
	cin >> a >> b >> p;
	while(b){
		if(b & 1) ans = ans * a % p;
		a *= a;
		b >>= 1;
	}
	cout << ans;
	return 0;
}
