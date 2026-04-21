#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,maxx,minx;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> n;
	minx = 1e8;
	for(int i = 1;i <= n;i++){
		cin >> a >> b >> c;
		long long high = 0,d = 1;
		while(high <= a){
			high += max(b+d*c,(long long)1);
			d++;
		}
		maxx = max(d,maxx);
	}
	cout << maxx << endl;
	return 0;
}
