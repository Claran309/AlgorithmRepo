//qwq没看懂题目  不知道在求啥  样例没看懂    按照我对题目的理解样例应该输出15 
#include <bits/stdc++.h>
using namespace std;
int m,wood[1000000],n,l,r,p,ans;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> r >> p >> l;
		r = l+r-1;
		for(int j = l;j <= r;j++)
			if(wood[j] < p) wood[j] = p;
	}
	for(int i = 1;i <= n;i++)
		ans += wood[i];
	cout << ans;
	return 0;
}
