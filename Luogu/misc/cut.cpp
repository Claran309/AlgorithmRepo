#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m,minn,mins,a,b,c;
int main(){
	cin >> n >> m;
	minn = LONG_LONG_MAX;
	if(n%3==0 || m%3==0){
		cout << 0;
		return 0;
	}
	if(n%3 == 1 || n%3 == 2)
		minn = min(minn,m);
	if(m%3 == 1 || m%3 == 2)
		minn = min(minn,n);
	for(unsigned long long i = 1;i <= n-1;i++){
		a = i*m;
		b = (n-i)*(m/2);
		c = (n-i)*(m-m/2);
		minn = min(minn,max(a,max(b,c))-min(a,min(b,c)));
	}
	a = 0;b = 0;c = 0;
	for(unsigned long long i = 1;i <= m-1;i++){ 
		a = i*n;
		b = (m-i)*(n/2);
		c = (m-i)*(n-n/2);
		minn = min(minn,max(a,max(b,c))-min(a,min(b,c)));
	}
	cout << minn;
	return 0;
}
