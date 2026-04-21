#include <bits/stdc++.h>
using namespace std;
int mid,n,k,a[200010];
long long l,r;
bool check(int m){
	long long sum = 0;
	for(int i = (n+1)/2;i <= n;i++){ 
		if(a[i] >= m) return true;
		sum += max(0,m-a[i]);
		if(sum > k) return false;
	} 
	return true;
}
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	l = 1; r = 2e9;
	sort(a+1,a+n+1);
	while(l <= r){  
		mid = (l+r)/2;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}  
	cout << r;
	return 0;
}
