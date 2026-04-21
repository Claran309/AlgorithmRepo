#include <bits/stdc++.h>
using namespace std;
int t,k,m,n,c[10000][10000],ans;
int main(){
	cin >> t >> k;
	c[1][1] = c[0][0] = c[1][0] = 1;
	for(int ni = 2;ni <= 2000;ni++){ 
	    c[ni][0] = 1; 
		for(int mi = 1;mi <= 2000;mi++)
			c[ni][mi] += (c[ni-1][mi] + c[ni-1][mi-1])%k;
	} 
	for(int i = 1;i <= t;i++){
		cin >> n >> m;
		ans = 0;
		for(int ni = 1;ni <= n;ni++)
			for(int mi = 1;mi <= min(ni,m);mi++)
				if(c[ni][mi] == 0) ans++;		
		if(k == 1) ans++;
		cout << ans << endl;
	}
	return 0;
}
