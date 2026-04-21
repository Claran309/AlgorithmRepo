#include <bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int n,s = 0;
	int j = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		s =s+a[i];
	}
	s = s / n;
	int c = 0;
	for(int i = 0;i < n;i++){
		c = a[i] - s;
		if( c == 0){
			continue;
		}
		a[i] = s;
		a[i+1] = a[i+1] + c;
		j++;
	}
	cout << j;
	return 0;
}
