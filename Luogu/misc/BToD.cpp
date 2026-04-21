#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,m,k = 0;\
	cin >> a;
	while(a != 0){
		m = a % 10;
		a /= 10;
		b += m*pow(2,k++);
	}
	cout << 1/10;\
	return 0;
}
