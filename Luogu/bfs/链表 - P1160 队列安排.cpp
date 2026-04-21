#include <bits/stdc++.h>
using namespace std;
struct road{
	int prev,next,w,d;
} e[100001];
int n,k,pl,p,x,m;
int main(){
	cin >> n;
	e[1].w = 1;
	for(int i = 2;i <= n;i++){
		cin >> k >> pl;
		if(pl == 0){//left
			e[e[k].prev].next = i;
			e[i].prev = e[k].prev;
			e[k].prev = i;
			e[i].next = k;
			e[i].w = i;
		}else{
			e[e[k].next].prev = i;
			e[i].next = e[k].next;
			e[k].next = i;
			e[i].prev = k;
			e[i].w = i;
		}
	}
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> x;
		e[x].d = 1;
	}
	int p = 1,cnt;
	while(1){
		cnt = p;
		p = e[p].prev;
		if(p == 0) break;
	}
	p = cnt;
	while(1){
		if(e[p].d != 1)
			cout << p << " ";
		p = e[p].next;
		if(p == 0) break;
	}
	return 0;
}
