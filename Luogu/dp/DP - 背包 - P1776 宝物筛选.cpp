#include <bits/stdc++.h>
using namespace std;
int v[100001],w[100001],f[100001],n,m,nl,x,y,s,t;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		x = 1,y = 1,s = 1,t = 1;
		cin >> y >> x >> s;
		while(s >= t){
			v[++nl] = x*t;
			w[nl] = y*t;
			s-=t;
			t*=2;
		}
		v[++nl] = x*s;
		w[nl] = y*s;
		//把s以二的指数分堆 
	}
	//然后按照0/1背包做
	for(int i = 1;i <= nl;i++)
		for(int j = m;j >= v[i];j--)
			f[j] = max(f[j],f[j-v[i]]+w[i]);
	cout <<f[m];
	return 0;
} 
