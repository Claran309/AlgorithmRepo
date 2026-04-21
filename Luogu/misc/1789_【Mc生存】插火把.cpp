#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
int n,m,k,a11,a21,a1,a2,ans;
int main(){
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> a11 >> a21;
		a1 = a11 - 1;
		a2 = a21 - 1;
		a[a1][a2] == true;
		a[a1][a1-1] = true;
		a[a1][a1-2] = true;
		a[a1][a1+1] = true;
		a[a1][a1+2] = true;
		a[a2-1][a2] = true;
		a[a2-2][a2] = true;
		a[a2+1][a2] = true;
		a[a2+2][a2] = true;
	}
	
	for(int i = 0;i < k;i++){
		cin >> a11 >> a21;
		a1 = a11 - 1;
		a2 = a21 - 1;
		//a[a1][a2] == true;
		for(int i = a1-2;i <= a1+2;i++){
			for(int j = a2-2;j<=a2+2;j++){
				a[i][j] = true;
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(a[i][j] == false) ans++; 
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cout << a[i][j];
		}
		cout << endl;
	}
	//cout << ans;
	return 0;
}
