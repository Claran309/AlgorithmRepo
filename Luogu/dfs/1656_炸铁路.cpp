#include <bits/stdc++.h>
using namespace std;
pair<int,int> ans[100001];
int n,m,cu,cv,p[100001],cnt,re,c;
bool f;
vector<int> v[100001];
void dfs(int k);
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first == y.first) return x.second < y.second;
	return x.first < y.first;
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cu >> cv;
		v[cu].push_back(cv);
		v[cv].push_back(cu);
	}
	for(int i = 1;i <= n;i++)
		for(int j = 0;j <= (int)v[i].size()-1;j++){
			re = v[i][j];
			v[i][j] = -1;
			dfs(1);
			if(cnt != n){
				ans[c].first = min(i,re);ans[c].second = max(i,re);
				c++;
			}	
			memset(p,0,sizeof(p));	
			cnt = 0;		
			v[i][j] = re;
		}
	sort(ans,ans+c,cmp);
	for(int i = 0;i < c;i++) cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
void dfs(int k){
	p[k] = 1;
	cnt++;
	for(int i = 0;i <= (int)v[k].size()-1;i++)
		if(v[k][i] != -1)
			if(!p[v[k][i]])
				dfs(v[k][i]);
}
