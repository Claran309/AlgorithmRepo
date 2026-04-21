#include <bits/stdc++.h>//m*q O(n^2) 100分 10AC 
using namespace std;
int out = 1,botans,t,m[60],p[1001],q[1001],a[1001][1001],bot[1000001];
bool cmp(int x,int y){
	return x > y;
} 
int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){//最多T个铺面 i    t <= 5 基本不存在复杂度问题 
		cin >> m[i];
		for(int j = 1, gd = 1;j <= m[i];gd++,j++){//m个轨道 j     m<=100
			cin >> p[j] >> q[j];
			for(int x = 1;x <= q[j];x++){//q个tap x   q <= 100
				cin >> a[x][gd];
				a[x][gd] *= p[j];
				botans = max(botans,a[x][gd]);
				bot[a[x][gd]]++;//桶排 
			}
		}
		for(int w = 0;w <= 1000000;w++){
			out = max(bot[w],out);
		}
		cout << out << endl;
		out = 0;
		memset(bot,0,sizeof(bot));
	}
	return 0;
}
