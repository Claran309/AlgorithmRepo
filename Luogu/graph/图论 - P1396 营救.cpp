#include <bits/stdc++.h>//s -> t
using namespace std;
struct road{
	int next,w;
};
int n,m,s,t,cv,cu,cw,p[10001];//p存到目前为止的最大拥挤度 
vector<road> v[10001];
int main(){
	cin >> n >> m >> s >> t;	
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu >> cw;
		road in;in.next = cu;in.w = cw;
		v[cv].push_back(in);
		in.next = cv;
		v[cu].push_back(in);
	}
	memset(p,0X3f,sizeof(p));
	queue<int> q;
	p[s] = 0;
	q.push(s);
	while(!q.empty()){
		int out = q.front();
		q.pop();
		for(int i = 0;i <= (int)v[out].size()-1;i++)
			if(max(p[out],v[out][i].w) < p[v[out][i].next]){
				p[v[out][i].next] = max(p[out],v[out][i].w);
				q.push(v[out][i].next);
			}
	}
	cout << p[t];
	return 0;
}
