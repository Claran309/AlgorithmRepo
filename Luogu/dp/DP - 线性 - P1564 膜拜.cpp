#include <bits/stdc++.h>
using namespace std;
int n,m,a[2501],f[2501],sum[2501],r,j;
int main(){
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	cin >>n>> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 2) a[i] = -1;
		sum[i] += sum[i-1]+a[i];
	//	f[i] = 1;
	} 
  //  for(int i = 1;i <= n;i++) cout << sum[i] << " ";
 //   cout <<endl;
	for(int i = 1;i <= n;i++){
		for(int k = 1;k <= i;k++){
			if(abs(sum[i]-sum[k-1])==i-k+1||abs(sum[i]-sum[k-1]) <= m){
				f[i] = min(f[k-1]+1,f[i]);
			}
		//	printf("a[k]=%d,´ËÊ±iÎª%d,k=%d\nabs(sum)=",a[k],i,k);
		//	cout <<abs(sum) << endl;
		}
	}
//	for(int i = 1;i <= n;i++) cout << f[i] << " ";
//	cout << endl;
	cout << f[n];
	return 0;
}

