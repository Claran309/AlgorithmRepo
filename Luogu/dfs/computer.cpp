#include <bits/stdc++.h>
using namespace std;
struct road{
	int w,si;
};
long long dans[1000001],n,cv,cu,ans,f[100001],been[100001],d[100001],rt,cnt,sumi;
vector<road> v[100001];
void dp(int u){
	been[u] = 1;
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		road y = v[u][i];
		if(been[y.w]) continue;
		dp(y.w);
		ans = max(ans,d[u]+d[y.w]+y.si);
		d[u] = max(d[u],d[y.w]+y.si); 
	}
}
int main(){
	cin >>n;
	for(int i = 2;i <= n;i++){ 
		cin >> cv >> cu;
		sumi+=cu;
		road in;in.w = cv;in.si = cu;
		v[i].push_back(in);
		in.w = i;
		v[cv].push_back(in);
	}
	cnt = 1e8;
	for(int i = 1;i <= n;i++)
		if(cnt > (int)v[i].size()) rt = i,cnt = (int)v[i].size();
	dp(rt);
	for(int i = 1;i <= n;i++){
		cout << max(d[i],sumi-d[i]) << endl;          //  <----就是这里！！sumi应该是所在路径的长度（不会求）而不是全部长度 
	}
	return 0;
}
/*
9
1 4
1 2
2 2
2 3
1 5
3 4
6 2
8 2

9
13
11
15
16
12
16
14
16

暴力

#include <bits/stdc++.h>
using namespace std;
struct road{
	int w,si;
};
long long start,bee[100001],dans[1000001],n,cv,cu,ans,f[100001],d[100001],rt,cnt;
vector<road> v[100001];
void dfs(int u,long long sum){
	bee[u] = 1;
	ans = max(ans,sum);
	for(int i = 0;i <= (int)v[u].size()-1;i++){
		road y = v[u][i];
		if(bee[y.w] != 0) continue;
		dfs(y.w,sum+y.si);
	}
}
int main(){
	while(cin >> n){
		ans = 0;
		for(int i = 2;i <= n;i++){
			cin >> cv >> cu;
			road in;in.w = cv;in.si = cu;
			v[i].push_back(in);
			in.w = i;
			v[cv].push_back(in);
		}
		for(int i = 1;i <= n;i++){
			dfs(i,0);
			memset(bee,0,sizeof(bee));
			cout << ans << endl;
			ans = 0;
		}
		for(int i = 1;i <= n;i++) v[i].clear();
	}
	return 0;
} 
*/
