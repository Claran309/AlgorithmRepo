#include <bits/stdc++.h>
using namespace std;
int a[500001],d[500001];
int n,m,x;
int lowbit(int x){
	return x&-x;
}
void update(int x,int y){
	while(x <= n){
		d[x] += y;
		x += lowbit(x);
	}
}
long long ask(int x){
	long long ans = 0;
	while(x){
		ans += d[x];
		x -= lowbit(x);
	}
	return ans;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> x;
		update(i,x);
	}
	for(int i = 0;i < m;i++){
		int q1,q2,q3;
		cin >> q1 >> q2 >> q3;
		if(q1 == 1){
			update(q2,q3);
		}
		if(q1 == 2){
			cout << ask(q3) - ask(q2-1) << endl;
		}
	}
	return 0;
}
