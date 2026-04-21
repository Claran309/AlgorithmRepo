#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main(){ 
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) 
	cin >> a[i];
	int m = a[0];
	for(int i = 0;i < n;i++)
	for(int j = i;j < n;j++){ 
		int s = 0;
		for(int k = i;k < j;k++) 
		s+=a[k]; 
		if(s > m) 
		m = s;
	} 
	cout << m;
	return 0;
} 
