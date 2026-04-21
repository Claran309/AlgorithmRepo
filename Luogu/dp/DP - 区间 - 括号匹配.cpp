#include <bits/stdc++.h>
using namespace std;
int n,f[1001][1001];
char s[10001];
int main(){
	cin >> s+1;
	n = strlen(s+1);
	for(int len = 2;len <= n;len++)
		for(int i = 1;i <= n;i++){
			int j = i+len-1;
			if(j > n) break;
			if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
			    f[i][j] = f[i+1][j-1]+2;
			for(int k = i;k < j;k++)
				f[i][j] = max(f[i][j],f[i][k] + f[k+1][j]);
		}
	cout << f[1][n];
	return 0;
} 
