#include <bits/stdc++.h>
using namespace std;
struct qwq{
	bool flag;
	int x,y,z,r;
} a[1000];
int ans,n,h,r,t;
int dits(){
	return pow();
}
void dfs(int k){
	a[k].flag = 1;
	if(ans = 1) return 0;
	if(a[k].z+r>=h){
		ans = 1;
		return ;
	}
	for(int i = 1;i <= n;i++)
		if(!a[i].flag && dist(i,k)<=4*r*r) dfs(i);
}
int main(){
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n >> h >> r;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].flag = false; 
		} 
		for(int i = 1;i <= n;i++){
			if(a[i].z <= r) dfs(i);
		}
		if(ans=1) cout << "Yes";
		else cout << "No"; 
	}
	return 0;
}
