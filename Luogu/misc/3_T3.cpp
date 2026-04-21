#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],l,b[1000001],ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		b[a[i]]++;
		if(b[a[i]] > 1){
			l++;
			for(int j = l;j <= i;j++){
				b[j]--;l++;
				if(a[j] == a[i])
					break;
			}
		}
		//if(l == 0) l = -1;
		ans = max(ans,i-l);
	}
	cout << ans;
	return 0;
}
/*
10
7 5 10 2 7 9 1 10 6 1
*/
