#include <bits/stdc++.h>
using namespace std;
int n,m,cu,cv,ans;
vector<int> v[1001];
void dfs(int k);
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cu >> cv;
		v[cu].push_back(cv);
		v[cv].push_back(cu);
	}
	for(int i = 1;i <= n;i++)
		if((int)v[i].size() % 2) ans++;
	if(ans == 0) ans = 2;
	cout << ans/2;
	return 0;	
}
