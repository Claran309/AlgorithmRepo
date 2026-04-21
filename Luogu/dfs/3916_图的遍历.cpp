#include <bits/stdc++.h>
using namespace std;
int maxx[100001];
int n,m,cu,cv,p[100001],ans;
bool f;
vector<int> v[100001];
void dfs(int k,int used);
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cu >> cv;
		v[cv].push_back(cu);//·´´æ 
	}
	for(int i = n;i >= 1;i--)
			if(!p[i])
				dfs(i,0);
	for(int i = 1;i <= n;i++) cout << maxx[i] << " ";
	return 0;
}
void dfs(int k,int used){
	maxx[k] = max(maxx[used],k);
	p[k] = 1;
	for(int i = 0;i <= (int)v[k].size()-1;i++)
		if(!p[v[k][i]])
			dfs(v[k][i],k);
}
