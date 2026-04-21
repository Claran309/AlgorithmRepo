#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h> 
using namespace std;
int n,m,cu,cv,ans,p[1000001];
vector<int> v[1000001];
void dfs(int k);
void bfs(int k);
int main(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> cu >> cv;
		v[cu].push_back(cv);
	}
	for(int i = 1;i <= m;i++)
		sort(v[i].begin(),v[i].end());
	//for(int i = 1;i <= n;i++)
	//	if(!p[i])
			dfs(1);
	cout << endl;
	memset(p,0,sizeof(p));
//	for(int i = 1;i <= n;i++)
	//	if(!p[i])
			bfs(1);
	return 0;
}
void dfs(int k){
	cout << k << " ";
	p[k] = 1;
	for(int i = 0;i <= (int)v[k].size()-1;i++)
		if(!p[v[k][i]])
			dfs(v[k][i]);
}
void bfs(int k){
	cout << k << " ";
	queue<int> que;
	p[k] = 1;
	que.push(k);
	while(!que.empty()){
		int out = que.front();
		que.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++)
			if(!p[v[out][i]]){
				cout << v[out][i] << " ";
				p[v[out][i]] = 1;
				que.push(v[out][i]);
			}
	}
}
