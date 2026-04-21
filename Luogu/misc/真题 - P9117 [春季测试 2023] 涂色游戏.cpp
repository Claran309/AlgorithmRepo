#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct ana{
	ll line,pri;
} h[100001],s[100001];
ll t,n,m,q,opt,x,c;
int main(){
	cin >> t;
	for(int tmp = 1;tmp <= t;tmp++){//O(tmn)
		cin >> n >> m >> q;
		for(int ask = 1;ask <= q;ask++){
			cin >> opt >> x >> c;
			if(opt == 1)
				s[x].line = c,s[x].pri = ask;
			else 
				h[x].line = c,h[x].pri = ask;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(s[j].pri < h[i].pri){
					printf("%lld ",h[i].line);
				}else{
					printf("%lld ",s[j].line);
				}
			}
			printf("\n");
		} 
		memset(h,0,sizeof(h));
		memset(s,0,sizeof(s));
	}
	return 0;
}
