#include <bits/stdc++.h>
using namespace std;
struct book{
	int h,w;
} a[101];
int n,k,f[101][101];

bool cmp(book x,book y){
	if(x.h < y.h) return true;
	return false;
}

int main(){
	memset(f,0x3f,sizeof(f));
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i].h >> a[i].w;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		f[i][1]=0;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= (i-1);j++){
			for(int kk = 2;kk <= min(i,n-k);kk++){
				f[i][kk] = min(f[j][kk-1]+abs(a[i].w-a[j].w),f[i][kk]);	
			}
		}
	}
	int minl = 1e9;
	for(int i = n-k;i <= n;i++) 
		 minl = min(minl,f[i][n-k]);
	cout << minl;
	return 0;
} 
