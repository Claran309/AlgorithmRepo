#include <bits/stdc++.h>
using namespace std;
struct tree{
	int l,r;
	char t;
} tr[200];
int rt,n,f[3000];
char a,b,c;
void dfs(int i){
	cout << tr[i].t;
	if(tr[i].l!=0)
		dfs(tr[i].l);
	if(tr[i].r!=0)	
		dfs(tr[i].r);
}
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> b >> c;
		if(i == 1) rt = a-'a'+1;
		tr[a-'a'+1].t = a;
		if(b != '*')
			tr[b-'a'+1].t = b;
		if(c != '*')
			tr[c-'a'+1].t = c;
		if(b != '*')
			tr[a-'a'+1].l = b-'a'+1;
		if(c != '*')
			tr[a-'a'+1].r = c-'a'+1; 
	}
	dfs(rt);
	return 0;
}
