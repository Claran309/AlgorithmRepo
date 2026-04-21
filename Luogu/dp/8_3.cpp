#include <bits/stdc++.h>
using namespace std;
char n[100];
int a[100],dp[100];
int main(){ 
	int x,m;
	cin >> x;
	for(int i = 0;i < x;i++){ 
		cin >> n[i];
		if(n[i] == 'I') a[i] = 1;
		else if(n[i] == 'D') a[i] = -1;
	} 
	dp[0] = a[0];
	m = a[0];
	for(int i = 1;i < x;i++){ 
		dp[i] = max(a[i],dp[i-1] + a[i]);
		if(dp[i] > m) m = dp[i];
	}	 
	cout << m;
	
	return 0;
}  
//3
