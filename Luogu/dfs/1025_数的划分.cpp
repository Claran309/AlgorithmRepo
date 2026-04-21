#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[10];
void dfs(int p,int q){
	if(p != 0 && q == k+1) return ;
	if(p == 0 && q != k+1) return ;
	//cout << 2;
	if(p == 0 && q == k+1) {
		ans++;
		return ;
	}
	for(int i = a[q-1];i <= p/(k+1-q);i++){
		a[q] = i;
		//cout << 2;
		dfs(p-i,q+1);
		//cout << 2;
		//cout << p << " " << q << endl;
	} 
	
}

int main(){
	a[0] = 1;
	cin >> n >> k;
	dfs(n,1);
	cout << ans;
	return 0;
}

