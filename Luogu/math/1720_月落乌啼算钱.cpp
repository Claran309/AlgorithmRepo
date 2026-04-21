#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	double a,b = 1,c = 0;
	for(int i = 0;i < n;i ++){
		a *= 0.5+sqrt(5)/2 ;
		b *= 0.5-sqrt(5)/2;
		cout << "a = " << a << " b = " << b << endl;
	}
	a = a - b;
	c = a / sqrt(5);
	printf("%.2f",c);
	return 0;
} 
