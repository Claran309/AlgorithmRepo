#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin >> m >> n;
	if(/*m % n+1 == 0 || */m % 1+n == 0) cout << "Working";
	else cout << "Gold King";
	return 0;
}
