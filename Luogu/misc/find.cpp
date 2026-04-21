#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	cin >> n;
	if(n%2 == 1){
		cout << n/2*(n+1)/2;
		return 0;
	}
	if((n/2)%2 == 1){
		cout << (n/2+2)*(n/2-2);
		return 0;
	}
	if((n/2)%2 == 0){
		cout << (n/2+1)*(n/2-1);
		return 0;
	}
	return 0;
}

