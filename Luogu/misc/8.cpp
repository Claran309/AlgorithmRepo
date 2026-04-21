#include <bits/stdc++.h>
using namespace std;

int main(){ 
	int n;
	cin >> n;
	int s = 2;
	for(int i = 2;i < n;i++){ 
        if(n % i == 0 && i > s){ 
        	s = i;
		} 
	} 
	cout << s;
	return 0;
} 
//1
