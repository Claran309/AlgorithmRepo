#include <bits/stdc++.h>//O(n^2)  
using namespace std;
int f,n,p,h,m,pi[10001],l,r,b[10001][10001];
int main(){
	cin >> n >> p >> h >> m;
	pi[1] = h;
	for(int i = 1;i <= m;i++){ 
		cin >> l >> r;
		if(b[l][r] != 0) continue;
		b[l][r]++;
		if(l < r){ 
			pi[l+1]--;
			pi[r]++;
		}else if(l > r){
			pi[r+1]--;
			pi[l]++;
		}
	}
	for(int i = 1;i <= n;i++){
		pi[i] += pi[i-1];
		cout << pi[i] << endl;
	}
	
	return 0;
}
