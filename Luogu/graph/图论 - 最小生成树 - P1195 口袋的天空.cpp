#include <bits/stdc++.h>
using namespace std;
struct edge{
	long long from,to,w;
};
long long father[100001],m,n,cv,k,cu,cw,x,y,ans,edge_s;
edge d[200001];
bool cmp(edge x,edge y);
int find(int x);
void unionn(int r1,int r2);
int main(){
	cin >> n >> m >> k;
	for(int j = 1;j <= m;j++){
		cin >> cv >> cu >> cw;
		d[j].from = cv;d[j].to = cu;d[j].w = cw;
	}
	sort(d+1,d+m+1,cmp);
	for(int i = 1;i <= n;i++) father[i] = i;
	for(int i = 1;i <= m;i++){
		int u = find(d[i].from),v = find(d[i].to);
		if(u == v) continue;
		ans+=d[i].w;unionn(u,v);edge_s++;
		if(edge_s == n-k) break;
	}
	if(edge_s != n-k) cout << "No Answer";
	else cout << ans;
	return 0;
}
int find(int x){
	if(father[x] != x) father[x] = find(father[x]);
	return father[x];
}
void unionn(int r1,int r2){
	father[r2] = r1;
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

28
*/
