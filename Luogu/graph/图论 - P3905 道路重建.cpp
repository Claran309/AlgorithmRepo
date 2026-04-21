#include <bits/stdc++.h>
using namespace std;
struct road{
	int next,w;
};
int f[1001],d[1001],re[1001][1001],n,m,cv,cu,cw,broken,st,en;
vector<road> v[1001];
priority_queue<pair<int,int> > q;
int main(){
	cin >>n >>m;
	for(int i = 1;i <= m;i++){
		cin >> cv >> cu >> cw;
		re[cv][cu] = cw;
		re[cu][cv] = cw;
		road inn;inn.next = cu;inn.w = 100000;
		v[cv].push_back(inn);
		inn.next = cv;
		v[cu].push_back(inn); 
	}
	cin >> broken;
	for(int i = 1;i <= broken;i++){
		cin >> cv >> cu;
		road in;in.next = cu;in.w = re[cv][cu];
		v[cv].push_back(in);
		in.next = cv;
		v[cu].push_back(in); 
 	}
 	cin >> st >> en;
 	memset(d,0X3f,sizeof(d));
 	for(int i = 0;i <= (int)v[st].size()-1;i++)
 		d[v[st][i].next] = v[st][i].w;
	d[st] = 0;
	q.push(make_pair(d[st],st));
	while(q.size()){
		int x = q.top().second;
		q.pop();
		if(f[x]) continue;
		f[x] = 1;
		for(int i = 0;i <= (int)v[x].size()-1;i++){
			if(d[v[x][i].next] == 1061109567) d[v[x][i].next] = v[x][i].w+d[x];
			if(d[v[x][i].next] >= v[x][i].w+d[x]){
				d[v[x][i].next] = v[x][i].w + d[x];
				q.push(make_pair(-d[v[x][i].next],v[x][i].next));
			}
		}
	}
	cout << d[en]%100000;
	return 0;
}
