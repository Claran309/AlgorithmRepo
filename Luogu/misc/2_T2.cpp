#include <bits/stdc++.h>
using namespace std;
int q,l,r,ans;
int main(){
	cin >> q;
	for(int j = 1;j <= q;j++){
		cin >> l >> r;
 	    if(l%2 == 1 && r%2==1) ans+=(r-l)/2+1;
 	    else if((l%2==1 && r%2==0) || (l%2==0 && r%2==1)) ans+=(r-l+1)/2;
		else ans+=(r-l)/2;
		ans+=((r-l)/4);
		if(r-l >= 2) ans++;
    	cout << ans;
    	ans=0;
	}
	return 0;
} 
