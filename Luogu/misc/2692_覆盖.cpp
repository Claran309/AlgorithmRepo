#include <bits/stdc++.h>

using namespace std;

int main(){ 
	int n,m,b,g,x,y,s = 0;
	cin >> n >> m >> b >> g;
	bool map[n][m]; 
	for(int i = 0;i < b;i++) cin >> x >> y;
	for(int i = x;i <= y;i++) map[i][m] = true;
	for(int i = 0;i < b;i++) cin >> x >> y;
	for(int i = x;i <= y;i++) map[n][i] = true;
	for(int i = 0;i < n;i++) 
	for(int j = 0;j < m;j++) 
	if(map[i][j] == true) s++;
	cout << s*2;
	return 0;
} 
//ac
