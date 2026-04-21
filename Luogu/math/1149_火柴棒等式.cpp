#include <bits/stdc++.h>
using namespace std;

int n,cnt;

int main(){ 
	cin >> n;
	int a[11111] = {6,2,5,5,4,5,6,3,7,6};
	for(int i = 10;i <= 100;i++){ 
		a[i] = a[i/10] + a[i%10];
	} 
	for(int i = 100;i <= 800;i++){ 
		a[i] = a[i/10] + a[i%10];
	} 
	for(int i = 0;i <= 800;i++)
		for(int j = 0;j <= 800;j++)
			if(a[i] + a[j] + 4 == n && i + j <= 800) cnt++;
	cout << cnt;
	return 0;
} 
