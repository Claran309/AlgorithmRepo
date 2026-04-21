#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,empty = 0,bottom = 0,ans = 0,p = 0,q = 0;
	cin >> m;
	empty = m; 
	bottom = m;
	do{
		ans += m; m = 0;
		m += empty / 2; m += bottom / 4; p = empty / 2; q = bottom / 4;
		empty -= 2*p; bottom -= 4*q;
		empty += m; bottom += m;
	}while(empty >= 2 || bottom >= 4);
	cout << ans + m;
	return 0;
}
