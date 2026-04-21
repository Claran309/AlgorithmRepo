#include <bits/stdc++.h>
using namespace std;
int ma[1002][1002],n;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++) cin >> ma[i][n-j];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) cout << ma[i][j] << " ";
		cout << endl;
	}
	return 0;
} 
