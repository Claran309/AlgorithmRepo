#include <bits/stdc++.h>
using namespace std;
struct mission{
	int p,t;
} a[10001];
int n,k,f[10001][10001],c1,c2,ans;//状态：f[i][j]表示从i到j时刻能获得的最小工作时间 
//转换式： f[i][j] = max(f[i][k]+f[k][j],f[k][j]+f[i][k],f[i][j])??????????????????k = a[i].p/a[i].t
int main(){
	memset(f,0x3f,sizeof(f));
	cin >>n >>k;
	for(int i = 1;i <= k;i++){
		cin >>a[i].p >>a[i].t;
		//边界处理
		f[a[i].p][a[i].t+a[i].p] = a[i].t;
		for(int j = 1;j <= a[i].t;j++) f[a[i].p+j][a[i].t] = j,f[a[i].p][a[i].p+j] = j;
	}
	//一一 土它 女台 
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= k;j++){
			for(int l = 1;l <= k;l++){
				if(a[l].p > j || a[l].t < i) continue;
				c1 = a[l].p,c2 = a[l].t;        
				f[i][j] = min(f[i][j],min(f[i][c2]+f[c2][j],f[c1][j]+f[i][c1]));//n^3,n=10000 TLE//情况:唯一任务唯一解 
			}
		}
	}
	ans = 1e9;
	for(int i = 1;i <= n;i++)
			ans = min(ans,f[a[i].p][a[i].t]);
	cout << n-ans; 
	return 0;
}
