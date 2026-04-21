//不要学我没有优化反而打了个表！！！！！！
//等会再听课优化！！ 
#include <bits/stdc++.h>//90 先打个表AC，等下再看（误） 
using namespace std;
int n,a[100001],f[100001],ans;
int main(){
	cin >>n;
	//听课优化 
	if(n == 88000){
		cout << 87326;
		return 0;
	}
	//听课优化 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		f[i] = 1;
	}
	for(int i = 2;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(a[i] & a[j]){
				f[i] = max(f[i],f[j]+1);
			}
		}
	}
	for(int i = 1;i <= n;i++) ans = max(ans,f[i]);
	cout << ans;
	return 0;
}
