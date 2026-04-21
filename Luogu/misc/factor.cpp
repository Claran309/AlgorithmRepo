#include <bits/stdc++.h>
using namespace std;
int n,p[10005];
long long ans=1,a[10005];
const long long pi = 1e9+7;
int main(){
	cin >> n;
	for(int i = 2;i <= n;i++){
		if(p[i]) continue;
		for(int j = 2*i;j <= n;j+=i) p[j] = 1;
	}
	for(int i = 2;i <= n;i++){
		int t = i;
		for(int j = 2;j <= sqrt(i);j++){
			if(p[j]) continue;
			while(t%j==0){
				a[j] = (a[j]+1)%pi;
				t/=j;
			}
		}
		if(t != 1) a[t] = (a[t]+1)%pi;
	}
	for(int i = 2;i <= n;i++){
		if(!p[i]) ans = ans*(a[i]+1)%pi;
	}
	cout << ans;
	return 0;
} 
