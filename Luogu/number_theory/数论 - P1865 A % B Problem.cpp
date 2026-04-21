#include <bits/stdc++.h>
using namespace std;
long long l[10000],r[10000],m,q,sum[100000000],cnt,maxx;
bool num[10000001];
long long prime[10000001],n;//prime[0]´æ¸öÊý 
void eu_prime(int n){
	memset(num,true,sizeof(num));	
	prime[0] = 0;
	for(int i = 2;i <= n;i++){
		if(num[i]) prime[++prime[0]] = i;
		int j = 1;
		for(int j = 1;j <= prime[0] && i*prime[j] <= n;j++) { 
			num[i*prime[j]] = false;
			if(i%prime[j] == 0) break;
		} 
	}
}
int main(){
	cin >> q >> m;
	for(int i = 1;i <= q;i++){
		cin >> l[i] >> r[i];
		maxx = max(maxx,r[i]);
	}
	eu_prime(maxx); 
	for(int i = 2;i <= maxx;i++){
		if(num[i] == true) cnt++;
		sum[i] = cnt;
	}
	for(int i = 1;i <= q;i++){
		if(l[i] <= 0 || r[i] > m) cout << "Crossing the line" << endl;
		else cout << sum[r[i]]-sum[l[i]-1] << endl;
	}
	return 0;
}
