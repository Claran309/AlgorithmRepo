#include <bits/stdc++.h>// O(nlogn/n!)       100·Ö 10AC
using namespace std;
int fff,ff,f,m,s,ans,p[101];

void dfsmin(int k,int sum){
	if(f == 1) return;
	if(sum == s && k == m+1) {
		f = 1;
		return;
	}
	if(k > m || sum == s) return;
	for(int i = 0;i <= 9;i++){
		if(i == 0 && fff == 0) {
			fff = 1; continue;
		}
		if(sum + i > s || f == 1 || sum + (m-k+1)*9 < s) return;
		if(sum + i <= s && f != 1) {
			p[k] = i;
			ff = 1;
			dfsmin(k+1,sum+i);
		}
	}
}

void dfsmax(int k,int sum){
	if(f == 1) return;
	if(sum == s) {
		f = 1;
		return;
	}
	if(k > m || sum == s) return;
	for(int i = 9;i >= 0;i--){
		if(f == 1 || m*9 < s) return;
		if(sum + i <= s && f != 1) {
			p[k] = i;
			ff = 1;
			dfsmax(k+1,sum+i);
		}
	}
}

int main(){
	cin >> m >> s;
	dfsmin(1,0);
	if(ff == 1)
		for(int i = 1;i <= m;i++) cout << p[i];
	else cout << -1;
	cout << " ";
	memset(p,0,sizeof(p));
	f = 0; ff = 0;
	dfsmax(1,0);
	if(ff == 1)
		for(int i = 1;i <= m;i++) cout << p[i];
	else cout << -1;
	cout << endl;
	return 0;
} 
