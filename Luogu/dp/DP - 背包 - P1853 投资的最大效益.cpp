#include <bits/stdc++.h>
using namespace std;
long long s,n,d,c[11],w[11],f[10000001];
int main(){
	cin >> s >> n >> d;
	for(int i = 1;i <= d;i++) cin >> c[i] >> w[i];
	for(int y = 1;y <= n;y++){//在n年之内 
		for(int i = 1;i <= d;i++){
			for(int j = c[i]/1000;j <= s/1000;j++){//因为a为1000的倍数，如果不/1000会TLE两个点 (其中一个是hack数据所以90分)
				f[j] = max(f[j],f[j-c[i]/1000]+w[i]);
			}
		}
	//	cout << f[s] << endl;
		s+=f[s/1000];
		memset(f,0,sizeof(f));
	}
	cout << s;
	return 0;
}
