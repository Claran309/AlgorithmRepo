#include <bits/stdc++.h>
using namespace std;
const int mod = 1e8+3;
int c[100001][100001],n;
int main(){
	cin >> n;
	for(int i = 0;i <= n;i++){
		c[i][0] = 1;
		for(int j = 1;j <= i;j++)
		 c[i][j] = (c[i-1][j] + c[i-1][j-1]%mod);
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++) cout << c[i][j] << ' ';
		cout << endl;
	}
	return 0;
} 
