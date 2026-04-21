#include <bits/stdc++.h>//改在线算法 
using namespace std;
int t,n[11],a[11][100001],ans,cnt,d[11][100001],h;
int gcd(int a,int b);//最大公因数
int f(int l,int r);
int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n[i];
		for(int j = 1;j <= n[i];j++)
			cin >> a[i][j];
		for(int j = 1;j <= n[i];j++)
			d[i][j] = a[i][j] + d[i][j-1];
		for(int x = 1;x <= n[i];x++)
			for(int y = x;y <= n[i];y++){
				h=i; 
				cnt += d[y]-d[x-1];
				cnt += f(x,y);
 				ans = max(ans,cnt);
 				cnt = 0;
			}
		cout << ans;
	}
	return 0;
}
int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
int f(int l,int r){
	if(l == r) return l;
	return gcd(f(l,r-1),gcd(a[h][r],a[h][r-1]));
}
/*
2
6
1 10 5 15 5 2
4
3 3 2 3
*/
