#include <bits/stdc++.h>
using namespace std;
int n,m;
int qpow(int n,int k){
	int ans = 1;
	while(k){
		if(k % 2 == 0){
			k/=2;
			n*=n;
		}else{
			k--;
			ans*=n;
		}
	}
	return ans;
}
int main(){
	cin >> n >> m;
	cout << qpow(n,m);
	return 0;
}
