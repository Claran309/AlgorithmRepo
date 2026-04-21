/*
12345678a
chr070309
Chr070309
cl309715
Cl309715
CL309715 
qwertyuiop 
*/
#include <bits/stdc++.h>
using namespace std;
struct edge{
	long long from,to,w;
};
long long father[1000001],cnt,m,n,k,cw,x,y,ans,edge_s;
edge d[2000001];
bool cmp(edge x,edge y);
int find(int x);
void unionn(int r1,int r2);
int main(){
	cin >> m >> n;
	cnt = 1;
	for(int i = 1;i <=n;i++)
		for(int j = 1;j <= n;j++){
			cin >> cw;
			if(i!=j){
				d[cnt].from = i;d[cnt].to = j;d[cnt].w = cw;
				if(cw == 0 || cw > m) d[cnt].w = m;
				cnt++;
			}
		}
	sort(d+1,d+cnt,cmp);
	for(int i = 1;i <= n;i++) father[i] = i;
	for(int i = 1;i <= cnt-1;i++){
		int u = find(d[i].from),v = find(d[i].to);
		if(u == v) continue;
		ans+=d[i].w;unionn(u,v);edge_s++;
		if(edge_s==n-1) break;
	}
	cout << ans+m;
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
