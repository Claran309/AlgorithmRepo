#include <bits/stdc++.h>
using namespace std;
int a[13];
int main(){
	for(int i = 1;i <= 12;i++) cin >> a[i];
	int y,mum = 0;
	for(int i = 1;i <= 12;i++){
		y = 300 + y - a[i];
		if(y < 0){
			cout << "-" << i << endl;
			return 0;
		}
		mum += y/100;
		y = y%100;
	}
	cout << mum*100*1.2 + y << endl;
	return 0;
}
